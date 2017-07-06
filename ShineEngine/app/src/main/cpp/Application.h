//
// Created by Administrator on 2017/7/5.
//

#ifndef SHINEENGINE_APPLICATION_H
#define SHINEENGINE_APPLICATION_H

#include "android/log.h"
#include "utility.h"

class Application {
public:
    Application();
    virtual ~Application();

    static Application * sm_pSharedApplication;

    /**
    @brief    Run the message loop.
    */
    int run();

    /**
    @brief    Get current application instance.
    @return Current application instance pointer.
    */
    static Application* getInstance();

    /**
    @brief  This function will be called when the application screen size is changed.
    @param new width
    @param new height
    */
    virtual void applicationScreenSizeChanged(int newWidth, int newHeight);
};


#endif //SHINEENGINE_APPLICATION_H
