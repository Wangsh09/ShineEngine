//
// Created by Administrator on 2017/7/12.
//

#ifndef SHINEENGINE_OGLES2DRAW_H
#define SHINEENGINE_OGLES2DRAW_H

#include "android/log.h"
#include <GLES2/gl2.h>
#include <string>
#include "utility.h"

class OGLES2Draw {

public:

    OGLES2Draw();
    virtual ~OGLES2Draw();

    static OGLES2Draw * sm_pSharedOGLES2Draw;

    /**
    @brief    Run the message loop.
    */
    int run();

    /**
    @brief    Get current OGLES2Draw instance.
    @return Current OGLES2Draw instance pointer.
    */
    static OGLES2Draw* getInstance();

private:
    void draw();
};


#endif //SHINEENGINE_OGLES2DRAW_H
