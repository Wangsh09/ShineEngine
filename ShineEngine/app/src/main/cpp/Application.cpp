//
// Created by Administrator on 2017/7/5.
//

#include "Application.h"

// sharedApplication pointer
Application * Application::sm_pSharedApplication = nullptr;

//////////////////////////////////////////////////////////////////////////
// static member function
//////////////////////////////////////////////////////////////////////////
Application* Application::getInstance()
{
    if(sm_pSharedApplication == nullptr)
        __android_log_print(ANDROID_LOG_WARN,"Application::getInstance()","sm_pSharedApplication is null");
    return sm_pSharedApplication;
}

Application::Application()
{
    if(sm_pSharedApplication == nullptr)
        __android_log_print(ANDROID_LOG_WARN,"Application::Application()","sm_pSharedApplication is null");
    sm_pSharedApplication = this;
}

Application::~Application()
{
    if(sm_pSharedApplication == nullptr)
        __android_log_print(ANDROID_LOG_WARN,"Application::~Application()","sm_pSharedApplication is null");
    sm_pSharedApplication = nullptr;
}

int Application::run()
{
    //Patrick : TODO
    /*
    // Initialize instance and shine
    if (! applicationDidFinishLaunching())
    {
        return 0;
    }
     */

    return -1;
}

void Application::applicationScreenSizeChanged(int newWidth, int newHeight) {

}