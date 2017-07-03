//
// Created by Administrator on 2017/7/3.
//

#ifndef SHINEENGINE_SGLVIEW_H
#define SHINEENGINE_SGLVIEW_H

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

class SGLView {

public:
    /**
     * @js ctor
     */
    SGLView();
    /**
     * @js NA
     * @lua NA
     */
    virtual ~SGLView();

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

};


#endif //SHINEENGINE_SGLVIEW_H
