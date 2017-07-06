//
// Created by Administrator on 2017/7/4.
//

#include "GLViewImpl.h"

void initExtensions() {
    //Patrick : TODO
    /*
    glGenVertexArraysOESEXT = (PFNGLGENVERTEXARRAYSOESPROC)eglGetProcAddress("glGenVertexArraysOES");
    glBindVertexArrayOESEXT = (PFNGLBINDVERTEXARRAYOESPROC)eglGetProcAddress("glBindVertexArrayOES");
    glDeleteVertexArraysOESEXT = (PFNGLDELETEVERTEXARRAYSOESPROC)eglGetProcAddress("glDeleteVertexArraysOES");
     */
}

GLViewImpl* GLViewImpl::create(const std::string& viewName)
{
    auto ret = new GLViewImpl;
    if(ret && ret->initWithFullScreen(viewName)) {
        //ret->autorelease();
        return ret;
    }
    delete ret;
    ret = nullptr;
    return nullptr;
}

bool GLViewImpl::initWithFullScreen(const std::string& viewName)
{
    return true;
}

GLViewImpl::GLViewImpl()
{
    initExtensions();
}

GLViewImpl::~GLViewImpl()
{

}