#include "SDL3_mixer/SDL_mixer.h"
#include <Lenerith/Core/Audio.h>
#include <Lenerith/Core/Config.h>
#include <algorithm>

Lenerith::Audio::Audio() {
  MIX_Init();
  audioDevice = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, nullptr);
  mixer = MIX_CreateMixerDevice(audioDevice, nullptr);
  MIX_SetMixerGain(mixer, config.masterVolume);
  musicTrack = MIX_CreateTrack(mixer);
}

Lenerith::Audio &Lenerith::Audio::instance() {
  static Audio instance;
  return instance;
}

Lenerith::Audio::~Audio() {
  MIX_DestroyTrack(musicTrack);
  MIX_DestroyMixer(mixer);
  MIX_Quit();
}

void Lenerith::Audio::playSound(MIX_Audio *sound) {
  MIX_Track *track = MIX_CreateTrack(mixer);
  audioTracks.emplace_back(track);
  MIX_SetTrackGain(track, config.soundVolume);
  MIX_SetTrackAudio(track, sound);
  MIX_PlayTrack(track, 0);
}

void Lenerith::Audio::clearTracks() {
  audioTracks.erase(std::remove_if(audioTracks.begin(), audioTracks.end(),
                                   [](MIX_Track *track) {
                                     if (!MIX_TrackPlaying(track)) {
                                       MIX_DestroyTrack(track);
                                       return true;
                                     }
                                     return false;
                                   }),
                    audioTracks.end());
}

void Lenerith::Audio::playMusic(MIX_Audio *music) {
  MIX_SetTrackAudio(musicTrack, music);
  MIX_PlayTrack(musicTrack, 0);
  MIX_SetTrackLoops(musicTrack, -1);
}

inline void Lenerith::Audio::pauseMusic() {
  MIX_PauseTrack(musicTrack);
}

inline void Lenerith::Audio::setMasterVolume(float volume) {
  MIX_SetMixerGain(mixer, volume);
}

inline void Lenerith::Audio::setMusicVolume(float volume) {
  MIX_SetTrackGain(musicTrack, volume);
}

MIX_Mixer *Lenerith::Audio::getMixer() const {
  return mixer;
}

const SDL_AudioSpec *Lenerith::Audio::getSpec() const {
  return &spec;
}
