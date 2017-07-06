//
// Created by Administrator on 2017/7/4.
//

#ifndef SHINEENGINE_DIRECTOR_H
#define SHINEENGINE_DIRECTOR_H

#include <string>
#include "android/log.h"
#include "Configuration.h"
#include "Texture2D.h"
#include "Image.h"
#include "Renderer.h"
#include "GLView.h"
#include "utility.h"
#include "Geometry.h"

class Director {

public:
    Director();
    ~Director();

    bool init();
    /**
     * Returns a shared instance of the director.
     */
    static Director* getInstance();

    /** Sets the default values based on the Configuration info. */
    void setDefaultValues();

    float _animationInterval;
    float _oldAnimationInterval;
    bool _displayStats;


    /* Renderer for the Director */
    Renderer *_renderer;

    /**
     * Get the GLView.
     */
    GLView* getOpenGLView() { return _openGLView; }


    /* The _openGLView, where everything is rendered, GLView is a abstract class,shine provide GLViewImpl
     which inherit from it as default renderer context,you can have your own by inherit from it*/
    GLView *_openGLView;

    /* window size in points */
    Size _winSizeInPoints;
    bool _isStatusLabelUpdated;

    /* whether or not the director is in a valid state */
    bool _invalid;


    // OpenGL Helper

    /** Sets the OpenGL default values.
     * It will enable alpha blending, disable depth test.
     */
    void setGLDefaultValues();

    /**
     * Sets the GLView.
     */
    void setOpenGLView(GLView *openGLView);

    void mainLoop();

    /** Draw the scene.
     * This method is called every frame. Don't call it manually.
     */
    void drawScene();

};


#endif //SHINEENGINE_DIRECTOR_H
