#ifndef IAPPLICATION_H
#define IAPPLICATION_H

#include "ILifeCycleListener.h"
#include "IPreferences.h"
#include "../Utils/IClipboard.h"
#include "../Utils/IRunnable.h"

class IApplication
{
public:
    enum ApplicationType
    {
        None,
        Android,
        IOS,
        Desktop,
        Linux,
        WebGL,
    };

    const int LOG_NONE  = 0;
    const int LOG_ERROR = 1;
    const int LOG_INFO  = 2;
    const int LOG_DEBUG = 3;

    [[nodiscard]] virtual int             GetLogLevel() = 0;
    [[nodiscard]] virtual int             GetVersion() = 0;
    [[nodiscard]] virtual ApplicationType GetAppType() = 0;
    [[nodiscard]] virtual IClipboard      GetClipBoard() = 0;
    [[nodiscard]] virtual IPreferences    GetPreferences( char* name ) = 0;

    virtual void Log( const char* tag, const char* message ) = 0;
    virtual void Error( const char* tag, const char* message ) = 0;
    virtual void Debug( const char* tag, const char* message ) = 0;

    virtual void Exit() = 0;

    virtual void AddLifecycleListener( ILifeCycleListener listener ) = 0;
    virtual void RemoveLifecycleListener( ILifeCycleListener listener ) = 0;
    virtual void PostRunnable( IRunnable runnable ) = 0;

private:
    IApplication();
    virtual ~IApplication();

    int             log_level = LOG_NONE;
    ApplicationType app_type  = ApplicationType::Desktop;
    IClipboard      clipboard;
};

#endif //IAPPLICATION_H
