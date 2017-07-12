//
// Created by Administrator on 2017/7/12.
//

#include "OGLES2Draw.h"

// sharedApplication pointer
OGLES2Draw * OGLES2Draw::sm_pSharedOGLES2Draw = nullptr;

//////////////////////////////////////////////////////////////////////////
// static member function
//////////////////////////////////////////////////////////////////////////
OGLES2Draw* OGLES2Draw::getInstance()
{
    if(sm_pSharedOGLES2Draw == nullptr)
    {
        sm_pSharedOGLES2Draw = new (std::nothrow) OGLES2Draw;
        if(sm_pSharedOGLES2Draw == nullptr)
            __android_log_print(ANDROID_LOG_WARN,"OGLES2Draw::getInstance()","sm_pSharedOGLES2Draw is null");
    }
    return sm_pSharedOGLES2Draw;
}

OGLES2Draw::OGLES2Draw()
{
    if(sm_pSharedOGLES2Draw == nullptr)
        __android_log_print(ANDROID_LOG_WARN,"Application::Application()","sm_pSharedApplication is null");
    sm_pSharedOGLES2Draw = this;
}

OGLES2Draw::~OGLES2Draw()
{
    if(sm_pSharedOGLES2Draw == nullptr)
        __android_log_print(ANDROID_LOG_WARN,"Application::~Application()","sm_pSharedApplication is null");
    sm_pSharedOGLES2Draw = nullptr;
}

int OGLES2Draw::run()
{

    draw();
    return 0;
}

void OGLES2Draw::draw()
{
    const GLchar* vertexShaderSource = "attribute vec3 position;\n"
            "void main()\n"
            "{"
            "gl_Position = vec4(position, 1.0);\n"
            "}";

    const GLchar* fragmentShaderSource = "void main()\n"
            "{"
            "gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
            "}";

    GLfloat vertices[] = {
            -1.0f, -1.0f, 0.0f, // BottomLeft
            1.0f, -1.0f, 0.0f, // BottomRight
            0.0f,  1.0f, 0.0f,  // TopLeft
    };

    glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, 0, 400, 600);

    GLint vs = glCreateShader(GL_VERTEX_SHADER);
    GLint ps = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vs, 1, &vertexShaderSource, nullptr);
    glShaderSource(ps, 1, &fragmentShaderSource, nullptr);
    glCompileShader(vs);
    glCompileShader(ps);

    GLint program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, ps);
    glLinkProgram(program);
    glUseProgram(program);

    GLint position = glGetAttribLocation(program,  "position");
    if(-1 != position)
    {
        glEnableVertexAttribArray(position);
        glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    }

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(position);



    /*
    glViewport(0, 0, 300, 300);
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    GLenum error = glGetError();
     */

}
