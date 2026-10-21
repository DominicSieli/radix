#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <SDL3/SDL.h>
#include <SDL3_mixer/SDL_mixer.h>

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

namespace Radix
{
	class AudioManager
	{
		private:
			float sound_volume = 1.0f;
			MIX_Mixer* mixer = nullptr;
			MIX_Track* music_track = nullptr;
			std::vector<MIX_Track*> sound_tracks;
			std::unordered_map<std::string, MIX_Audio*> audio_cache;

			static float clamp_volume(float volume)
			{
				return std::clamp(volume, 0.0f, 1.0f);
			}

		public:
			AudioManager();// = default;

			~AudioManager();

			//AudioManager(const AudioManager&) = delete;

			//AudioManager& operator=(const AudioManager&) = delete;

			bool init();

			MIX_Audio* load_audio(const std::string&);

			bool play_music(const std::string&, int);

			void stop_music();

			bool play_sound(const std::string&, float);

			void stop_sounds();

			void set_music_volume(float);

			void set_sound_volume(float);

			void shut_down();
	};
}

#endif
