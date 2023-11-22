#ifndef IMUSIC_H
#define IMUSIC_H

class IOnCompletionListener;

class IMusic
{
public:
    /**
     * \brief Starts the play back of the music stream. In case the stream was paused
     * this will resume the play back. In case the music stream is finished playing
     * this will restart the play back.
     */
    virtual void Play();

    /**
     * \brief Pauses the play back. If the music stream has not been started yet or has
     * finished playing a call to this method will be ignored.
     */
    virtual void Pause();

    /**
     * \brief Stops a playing or paused Music instance. Next time play() is
     * invoked the Music will start from the beginning.
     */
    virtual void Stop();

    /**
     * \brief  whether this music stream is playing.
     */
    virtual bool IsPlaying();

    /**
     * \brief Sets whether the music stream is looping. This can be called at
     * any time, whether the stream is playing.
     * \param isLooping whether to loop the stream
     */
    virtual void SetLooping( bool isLooping );

    /**
     * \brief
     */
    virtual bool IsLooping();

    /**
     * \brief Sets the volume of this music stream. The volume must be given in the
     * range [0,1] with 0 being silent and 1 being the maximum volume.
     */
    virtual void SetVolume( float volume );

    /**
     * \brief
     */
    virtual float GetVolume();

    /**
     * \brief Sets the panning and volume of this music stream.
     * \param pan panning in the range -1 (full left) to 1 (full right). 0 is center position.
     * \param volume the volume in the range [0,1]. 
     */
    virtual void SetPan( float pan, float volume );

    /**
     * \brief Set the playback position in seconds.
     */
    virtual void SetPosition( float position );

    /**
     * \brief Returns the playback position in seconds.
     */
    virtual float GetPosition();

    /**
     * \brief Needs to be called when the Music is no longer needed.
     */
    virtual void Dispose();

    /**
     * \brief Register a callback to be invoked when the end of a music
     * stream has been reached during playback.
     * \param listener the callback that will be run
     */
    virtual void setOnCompletionListener( IOnCompletionListener listener );

private:
    IMusic() = default;
    virtual ~IMusic() = default;
};

/**
 * \brief Interface definition for a callback to be invoked when playback
 * of a music stream has completed.
 */
class IOnCompletionListener
{
public:
    /**
     * \brief Called when the end of a media source is reached during playback.
     * \param music the Music that reached the end of the file
     */
    virtual void OnCompletion( IMusic music ) = 0;

private:
    IOnCompletionListener() = default;
    virtual ~IOnCompletionListener() = default;
};

#endif //IMUSIC_H
