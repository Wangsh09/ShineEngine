//
// Created by Administrator on 2017/7/5.
//

#ifndef SHINEENGINE_GLVIEW_H
#define SHINEENGINE_GLVIEW_H


#include "Geometry.h"

/** @struct GLContextAttrs
 *
 * There are six opengl Context Attrs.
 */
struct GLContextAttrs
{
    int redBits;
    int greenBits;
    int blueBits;
    int alphaBits;
    int depthBits;
    int stencilBits;
};

class GLView {

public:
    /**
     * @js ctor
     */
    GLView();
    /**
     * @js NA
     * @lua NA
     */
    virtual ~GLView();

    /** Static method and member so that we can modify it on all platforms before create OpenGL context.
     *
     * @param glContextAttrs The OpenGL context attrs.
     */
    static void setGLContextAttrs(GLContextAttrs& glContextAttrs);

    /** Return the OpenGL context attrs.
     *
     * @return Return the OpenGL context attrs.
     */
    static GLContextAttrs getGLContextAttrs();

    /** The OpenGL context attrs. */
    static GLContextAttrs _glContextAttrs;

    /**
     * Set the frame size of EGL view.
     *
     * @param width The width of the fram size.
     * @param height The height of the fram size.
     */
    virtual void setFrameSize(float width, float height);

    // real screen size
    Size _screenSize;

    // resolution size, it is the size appropriate for the app resources.
    Size _designResolutionSize;

    /** Get design resolution size.
     *  Default resolution size is the same as 'getFrameSize'.
     *
     * @return The design resolution size.
     */
    virtual const Size&  getDesignResolutionSize() const;
};



#endif //SHINEENGINE_GLVIEW_H
