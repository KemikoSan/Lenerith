#pragma once

#include <vector>

#include <SDL3/SDL_audio.h>
#include <SDL3_mixer/SDL_mixer.h>

#include <Lenerith/DLL.h>

namespace Lenerith {
class LENERITH_API Audio {
private:
  SDL_AudioDeviceID audioDevice;
  SDL_AudioSpec spec;
  MIX_Mixer *mixer = nullptr;
  MIX_Track *musicTrack = nullptr;
  SDL_IOStream *musicStream = nullptr;
  std::vector<MIX_Track *> audioTracks;

public:
  static Audio &instance();
  MIX_Audio *loadMusic(const char *path);
  void playSound(MIX_Audio *sound);
  void playMusic(MIX_Audio *music);
  void pauseMusic();
  void setMasterVolume(float volume);
  void setMusicVolume(float volume);
  void clearTracks();
  MIX_Mixer *getMixer() const;
  const SDL_AudioSpec *getSpec() const;
  Audio();
  ~Audio();
};
}; // namespace Lenerith
