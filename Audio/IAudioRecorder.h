#ifndef IAUDIORECORDER_H
#define IAUDIORECORDER_H
#include "../Core/IDisposable.h"

class IAudioRecorder : public IDisposable
{
public:
    /**
     * \brief Reads in numSamples samples into the array samples starting at offset.
     * If the recorder is in stereo you have to multiply numSamples by 2.
     * \param samples the array to write the samples to.
     * \param offset the offset into the array.
     * \param num_samples The number of samples to be read.
     */
    void Read( short samples[], int offset, int num_samples );

private:
    IAudioRecorder();
    virtual ~IAudioRecorder();
};

#endif //IAUDIORECORDER_H
