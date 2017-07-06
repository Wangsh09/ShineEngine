//
// Created by Administrator on 2017/7/5.
//

#include "GLView.h"

//default context attributions are set as follows
GLContextAttrs GLView::_glContextAttrs = {5, 6, 5, 0, 16, 0};

GLView::GLView()
        : _designResolutionSize(0,0)
        , _screenSize(0,0)
{
}

GLView::~GLView()
{

}

void GLView::setGLContextAttrs(GLContextAttrs& glContextAttrs)
{
    _glContextAttrs = glContextAttrs;
}

GLContextAttrs GLView::getGLContextAttrs()
{
    return _glContextAttrs;
}

void GLView::setFrameSize(float width, float height)
{
    _screenSize = Size(width, height);

    Size zero = Size(0, 0);
    // only update the designResolution if it wasn't previously set
    if (_designResolutionSize.equals(zero))
        _designResolutionSize = _screenSize;
}

const Size& GLView::getDesignResolutionSize() const
{
    return _designResolutionSize;
}
