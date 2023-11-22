#ifndef ISOUND_H
#define ISOUND_H

class ISound
{
public:
    /**
     * \brief Plays the sound. If the sound is already playing, it will
     * be played again, concurrently.
     * \return the id of the sound instance if successful, or -1 on failure.
     */
    virtual long Play();

    /**
     * \brief Plays the sound. If the sound is already playing, it will be
     * played again, concurrently.
     * \param volume the volume in the range [0,1]
     * \return the id of the sound instance if successful, or -1 on failure.  
     */
    virtual long Play( float volume );

    /**
     * \brief Plays the sound. If the sound is already playing, it will be played again, concurrently.
     * \param volume the volume in the range [0,1]
     * \param pitch the pitch multiplier, 1 == default, greater than 1 == faster,
     * less than 1 == slower, the value has to be between '0.5' and '2.0'
     * \param pan panning in the range -1 (full left) to 1 (full right). 0 is center position.
     * \return the id of the sound instance if successful, or -1 on failure.
     */
    virtual long Play( float volume, float pitch, float pan );

    /**
     * \brief Plays the sound, looping. If the sound is already playing,
     * it will be played again, concurrently.
     * \return the id of the sound instance if successful, or -1 on failure.
     */
    virtual long Loop();

    /**
     * \brief Plays the sound, looping. If the sound is already playing, it will be played
     * again, concurrently. You need to stop the sound via a call to Stop(long)
     * using the returned id.
     * \param volume the volume in the range [0, 1]
     * \return the id of the sound instance if successful, or -1 on failure.  
     */
    virtual long Loop( float volume );

    /**
     * \brief Plays the sound, looping. If the sound is already playing, it will be played again,
     * concurrently. You need to stop the sound via a call to Stop(long)
     * using the returned id.
     * \param volume the volume in the range [0,1]
     * \param pitch the pitch multiplier, 1 == default, greater than 1 == faster, less than 1 == slower,
     * the value has to be between 0.5 and 2.0
     * \param pan panning in the range -1 (full left) to 1 (full right). 0 is center position.
     * \return the id of the sound instance if successful, or -1 on failure.  
     */
    virtual long Loop( float volume, float pitch, float pan );

    /**
     * \brief Stops playing all instances of this sound.
     */
    virtual void Stop();

    /**
     * \brief Pauses all instances of this sound.
     */
    virtual void Pause();

    /**
     * \brief Resumes all paused instances of this sound.
     */
    virtual void Resume();

    /**
     * \brief Stops the sound instance with the given id as returned by Play() or
     * Play(float). If the sound is no longer playing, this has no effect.
     * \param soundId the sound id  
     */
    virtual void Stop( long soundId );

    /**
     * \brief Pauses the sound instance with the given id as returned by play()
     * or Play(float). If the sound is no longer playing, this has no effect.
     * \param soundId the sound id  
     */
    virtual void Pause( long soundId );

    /**
     * \brief Resumes the sound instance with the given id as returned by Play()
     * or Play(float). If the sound is not paused, this has no effect.
     * \param soundId the sound id  
     */
    virtual void Resume( long soundId );

    /**
     * \brief Sets the sound instance with the given id to be looping. If the sound is no longer
     * playing this has no effect.
     * \param soundId the sound id 
     * \param looping whether to loop or not.  
     */
    virtual void SetLooping( long soundId, bool looping );

    /**
     * \brief Changes the pitch multiplier of the sound instance with the given id as returned
     * by play() or play(float).
     * If the sound is no longer playing, this has no effect.
     * \param soundId the sound id 
     * \param pitch the pitch multiplier, 1 == default, greater than 1 == faster,
     * less than 1 == slower, the value has to be between 0.5 and 2.0
     */
    virtual void SetPitch( long soundId, float pitch );

    /**
     * \brief Changes the volume of the sound instance with the given id as returned by
     * Play() or Play(float). If the
     * sound is no longer playing, this has no effect.
     * \param soundId the sound id 
     * \param volume the volume in the range 0 (silent) to 1 (max volume).  
     */
    virtual void SetVolume( long soundId, float volume );

    /**
     * \brief Sets the panning and volume of the sound instance with the given id as returned
     * by Play() or Play(float).
     * If the sound is no longer playing, this has no effect. Note that panning only works
     * for mono sounds, not for stereo sounds!
     * \param soundId the sound id 
     * \param pan panning in the range -1 (full left) to 1 (full right). 0 is center position. 
     * \param volume the volume in the range [0,1].  
     */
    virtual void SetPan( long soundId, float pan, float volume );

private:
    ISound()          = default;
    virtual ~ISound() = default;
};

#endif //ISOUND_H
