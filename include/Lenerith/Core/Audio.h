#pragma once

#include <vector>

#include <SDL3/SDL_audio.h>
#include <SDL3_mixer/SDL_mixer.h>

#include <Lenerith/export.h>

namespace Lenerith {
class LENERITH_API Audio {
private:
  SDL_AudioDeviceID audioDevice;
  SDL_AudioSpec spec;
  MIX_Mixer *mixer;
  MIX_Track *musicTrack;
  std::vector<MIX_Track *> audioTracks;

public:
  static Audio &instance();
  void playSound(MIX_Audio *sound);
  void playMusic(MIX_Audio *music);
  inline void pauseMusic();
  inline void setMasterVolume(float volume);
  inline void setMusicVolume(float volume);
  void clearTracks();
  MIX_Mixer *getMixer() const;
  const SDL_AudioSpec *getSpec() const;
  Audio();
  ~Audio();
};
}; // namespace Lenerith
