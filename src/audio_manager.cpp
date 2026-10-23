#include "utilities.h"
#include "audio_manager.h"

namespace Radix
{
	AudioManager::AudioManager()
	{}

	AudioManager::~AudioManager()
	{
		shut_down();
	}

	bool AudioManager::init()
	{
		if(mixer)
		{
			return true;
		}

		if(!MIX_Init())
		{
			SDL_Log("MIX_Init failed: %s", SDL_GetError());

			return false;
		}

		mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, nullptr);

		if(!mixer)
		{
			SDL_Log("Creating audio mixer failed: %s", SDL_GetError());
			MIX_Quit();

			return false;
		}

		music_track = MIX_CreateTrack(mixer);

		if(!music_track)
		{
			SDL_Log("Creating music track failed: %s", SDL_GetError());
			shut_down();

			return false;
		}

		return true;
	}

	MIX_Audio* AudioManager::load_audio(const std::string& path, const unsigned int& id)
	{
		if(!mixer)
		{
			SDL_Log("AudioManager has not been initialized.");

			return nullptr;
		}

		if(auto it = audio_map.find(id); it != audio_map.end())
		{
			return it->second;
		}

		MIX_Audio* audio = MIX_LoadAudio(mixer, path.c_str(), true);

		if(!audio)
		{
			SDL_Log("Loading audio '%s' failed: %s", path.c_str(), SDL_GetError());

			return nullptr;
		}

		audio_map.try_emplace(id, audio);

		return audio;
	}

	bool AudioManager::play_music(const unsigned int& id)
	{
		if(!music_track)
		{
			return false;
		}

		MIX_Audio* audio = nullptr;

		if(auto it = audio_map.find(id); it != audio_map.end())
		{
			audio = it->second;
		}

		if(!audio)
		{
			return false;
		}

		if(!MIX_SetTrackAudio(music_track, audio))
		{
			SDL_Log("Setting music audio failed: %s", SDL_GetError());

			return false;
		}

		SDL_PropertiesID options = SDL_CreateProperties();

		if(!options)
		{
			SDL_Log("Creating playback properties failed: %s", SDL_GetError());

			return false;
		}

		const bool configured = SDL_SetNumberProperty(options, MIX_PROP_PLAY_LOOPS_NUMBER, -1);

		const bool played = configured && MIX_PlayTrack(music_track, options);

		SDL_DestroyProperties(options);

		if(!played)
		{
			SDL_Log("Playing music failed: %s", SDL_GetError());
		}

		return played;
	}

	void AudioManager::stop_music()
	{
		if(music_track)
		{
			MIX_StopTrack(music_track, 0);
		}
	}

	bool AudioManager::play_sound(const unsigned int& id, const float& volume = 1.00f)
	{
		if(!mixer || volume < 0.00f)
		{
			return false;
		}

		MIX_Audio* audio = nullptr;

		if(auto it = audio_map.find(id); it != audio_map.end())
		{
			audio = it->second;
		}

		if(!audio)
		{
			return false;
		}

		MIX_Track* track = nullptr;

		for(MIX_Track* candidate : sounds)
		{
			if(!MIX_TrackPlaying(candidate))
			{
				track = candidate;
				break;
			}
		}

		if(!track)
		{
			track = MIX_CreateTrack(mixer);

			if(!track)
			{
				SDL_Log("Creating sound track failed: %s", SDL_GetError());

				return false;
			}

			sounds.push_back(track);
		}

		if(!MIX_SetTrackAudio(track, audio) || !MIX_SetTrackGain(track, clamp_float(volume, 0.00f, 1.00f) * sound_volume))
		{
			SDL_Log("Configuring sound effect failed: %s", SDL_GetError());

			return false;
		}

		if(!MIX_PlayTrack(track, 0))
		{
			SDL_Log("Playing sound effect failed: %s", SDL_GetError());

			return false;
		}

		return true;
	}

	void AudioManager::stop_sounds()
	{
		for(MIX_Track* sound : sounds)
		{
			MIX_StopTrack(sound, 0);
		}
	}

	float AudioManager::get_music_volume()
	{
		return music_volume;
	}

	float AudioManager::get_sound_volume()
	{
		return sound_volume;
	}

	void AudioManager::set_music_volume(const float& volume)
	{
		music_volume = clamp_float(volume, 0.00f, 1.00f);

		if(music_track)
		{
			MIX_SetTrackGain(music_track, music_volume);
		}
	}

	void AudioManager::set_sound_volume(const float& volume)
	{
		sound_volume = clamp_float(volume, 0.00f, 1.00f);

		for(MIX_Track* sound : sounds)
		{
			MIX_SetTrackGain(sound, sound_volume);
		}
	}

	void AudioManager::shut_down()
	{
		if(!mixer)
		{
			return;
		}

		if(music_track)
		{
			MIX_DestroyTrack(music_track);
			music_track = nullptr;
		}

		for(MIX_Track* sound : sounds)
		{
			MIX_DestroyTrack(sound);
		}

		sounds.clear();

		for(auto& [id, audio] : audio_map)
		{
			MIX_DestroyAudio(audio);
		}

		audio_map.clear();

		MIX_DestroyMixer(mixer);
		mixer = nullptr;

		MIX_Quit();
	}
}
