//
// Created by Administrator on 2017/7/3.
//

#include "SGLView.h"

//default context attributions are set as follows
GLContextAttrs SGLView::_glContextAttrs = {5, 6, 5, 0, 16, 0};

SGLView::SGLView()
{
}

SGLView::~SGLView()
{

}

void SGLView::setGLContextAttrs(GLContextAttrs& glContextAttrs)
{
    _glContextAttrs = glContextAttrs;
}

GLContextAttrs SGLView::getGLContextAttrs()
{
    return _glContextAttrs;
}
