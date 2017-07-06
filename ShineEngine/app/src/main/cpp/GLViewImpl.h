//
// Created by Administrator on 2017/7/4.
//

#ifndef SHINEENGINE_GLVIEWIMPL_H
#define SHINEENGINE_GLVIEWIMPL_H

#include <string>
#include "GLView.h"
#include "utility.h"

class GLViewImpl : public GLView{

public:

    // static function
    static GLViewImpl* create(const std::string &viewname);
    GLViewImpl();
    virtual ~GLViewImpl();
    bool initWithFullScreen(const std::string& viewName);
};


#endif //SHINEENGINE_GLVIEWIMPL_H
