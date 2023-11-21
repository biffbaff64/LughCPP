#ifndef IAUDIO_H
#define IAUDIO_H

#include <cstdio>

#include "../Audio/IAudioDevice.h"
#include "../Audio/IAudioRecorder.h"
#include "../Audio/ISound.h"
#include "../Audio/IMusic.h"

class IAudio
{
public:
    IAudioDevice NewAudioDevice(int samplingRate, bool is_mono);

    IAudioRecorder newAudioRecorder(int samplingRate, bool is_mono);

    ISound newSound(FILE* file_handle);

    IMusic newMusic(FILE* file);

private:
    IAudio() = default;
    ~IAudio() = default;
};

#endif //IAUDIO_H
