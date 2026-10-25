#include "utilities.h"
#include "audio_manager.h"

namespace Radix
{
	AudioManager::AudioManager()
	{}

	AudioManager::~AudioManager()
	{
		destroy();
	}

	bool AudioManager::initialize()
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
			destroy();

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

		if(audio_map.contains(id))
		{
			return audio_map.at(id);
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

		if(audio_map.contains(id))
		{
			audio = audio_map.at(id);
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

		current_music_id = id;

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

		if(audio_map.contains(id))
		{
			audio = audio_map.at(id);
		}

		if(!audio)
		{
			return false;
		}

		MIX_Track* new_track = nullptr;

		for(MIX_Track* track : tracks)
		{
			if(!MIX_TrackPlaying(track))
			{
				new_track = track;
				break;
			}
		}

		if(!new_track)
		{
			new_track = MIX_CreateTrack(mixer);

			if(!new_track)
			{
				SDL_Log("Creating sound track failed: %s", SDL_GetError());

				return false;
			}

			tracks.push_back(new_track);
		}

		if(!MIX_SetTrackAudio(new_track, audio) || !MIX_SetTrackGain(new_track, clamp_float(volume, 0.00f, 1.00f) * sound_volume))
		{
			SDL_Log("Configuring sound effect failed: %s", SDL_GetError());

			return false;
		}

		if(!MIX_PlayTrack(new_track, 0))
		{
			SDL_Log("Playing sound effect failed: %s", SDL_GetError());

			return false;
		}

		return true;
	}

	void AudioManager::stop_sounds()
	{
		for(MIX_Track* track : tracks)
		{
			MIX_StopTrack(track, 0);
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

		for(MIX_Track* track : tracks)
		{
			MIX_SetTrackGain(track, sound_volume);
		}
	}

	bool AudioManager::delete_audio(const unsigned int& id)
	{
		MIX_Audio* audio = audio_map[id];

		if(!audio)
		{
			SDL_Log("No audio data to delete");

			return false;
		}

		if(current_music_id == id)
		{
			stop_music();
		}

		MIX_DestroyAudio(audio);
		audio_map.erase(id);

		return true;
	}

	void AudioManager::destroy()
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

		for(MIX_Track* track : tracks)
		{
			MIX_DestroyTrack(track);
		}

		tracks.clear();

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
