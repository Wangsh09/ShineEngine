//
// Created by Administrator on 2017/7/3.
//

#ifndef SHINEENGINE_SGLVIEW_H
#define SHINEENGINE_SGLVIEW_H

#include <string>

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
    static std::string setGLContextAttrs();

};


#endif //SHINEENGINE_SGLVIEW_H
