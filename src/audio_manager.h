#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <SDL3/SDL.h>
#include <SDL3_mixer/SDL_mixer.h>

#include <vector>
#include <string>
#include <unordered_map>

namespace Radix
{
	class AudioManager
	{
		private:
			float sound_volume = 1.00f;
			MIX_Mixer* mixer = nullptr;
			MIX_Track* music_track = nullptr;
			std::vector<MIX_Track*> sound_tracks;
			std::unordered_map<std::string, MIX_Audio*> audio_cache;

		public:
			AudioManager();

			~AudioManager();

			bool init();

			MIX_Audio* load_audio(const std::string&);

			bool play_music(const std::string&, const int&);

			void stop_music();

			bool play_sound(const std::string&, const float&);

			void stop_sounds();

			void set_music_volume(const float&);

			void set_sound_volume(const float&);

			void shut_down();
	};
}

#endif
