#ifndef IAUDIODEVICE_H
#define IAUDIODEVICE_H

class IAudioDevice
{
public:
    /**
     * \brief Returns whether this AudioDevice is in mono or stereo mode.
     * \returns TRUE for mono, FALSE for stereo.
     */
    virtual bool isMono() = 0;

    /**
     * \brief Writes the array of 16-bit signed PCM samples to the audio
     * device and blocks until they have been processed.
     * \param samples The samples.
     * \param offset The offset into the samples array.
     * \param num_samples The number of samples to write to the device.
     */
    virtual void writeSamples( int samples[ ], int offset, int num_samples ) = 0;

    /**
     * \brief Writes the array of float PCM samples to the audio device and
     * blocks until they have been processed.
     * \param samples The samples.
     * \param offset The offset into the samples array.
     * \param num_samples The number of samples to write to the device.
     */
    virtual void writeSamples( float samples[ ], int offset, int num_samples ) = 0;

    /**
     * \brief The latency in samples.
     */
    virtual int getLatency() = 0;

    /**
     * \brief Sets the volume in the range [0,1].
     */
    virtual void setVolume( float volume ) = 0;

    /**
     * \brief Frees all resources associated with this AudioDevice.
     * Needs to be called when the device is no longer needed.
     */
    virtual void dispose() = 0;

private:
    IAudioDevice()          = default;
    virtual ~IAudioDevice() = default;
};

#endif //IAUDIODEVICE_H
