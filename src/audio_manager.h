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
			MIX_Mixer* mixer;
			MIX_Track* music_track;
			float music_volume = 1.00f;
			float sound_volume = 1.00f;
			unsigned int current_music_id;
			std::vector<MIX_Track*> tracks;
			std::unordered_map<unsigned int, MIX_Audio*> audio_map;

		public:
			AudioManager();

			~AudioManager();

			bool initialize();

			MIX_Audio* load_audio(const std::string&, const unsigned int&);

			bool play_music(const unsigned int&);

			void stop_music();

			bool play_sound(const unsigned int&, const float&);

			void stop_sounds();

			float get_music_volume();

			float get_sound_volume();

			void set_music_volume(const float&);

			void set_sound_volume(const float&);

			bool delete_audio(const unsigned int&);

			void destroy();
	};
}

#endif
