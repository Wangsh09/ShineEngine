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
            "attribute float alpha;\n"
            "uniform mediump float x;\n"
            "varying mediump float vx;\n"
            "void main()\n"
            "{"
            "gl_Position = vec4(position, alpha);\n"
            "vx = x;\n"
            "}";

    const GLchar* fragmentShaderSource = "precision mediump float;\n"
            "uniform float x;\n"
            "varying float vx;\n"
            "void main()\n"
            "{"
            "gl_FragColor = vec4(vx, x, 0.0, 1.0);\n"
            "}";

    GLfloat vertices[] = {
            -1.0f, -1.0f, 0.0f, // BottomLeft
            1.0f, -1.0f, 0.0f, // BottomRight
            0.0f,  1.0f, 0.0f,  // TopLeft
            1.0f,  1.0f, 0.0f,  // TopRight
    };

    GLfloat color[] = {
            1.0f, 1.0f, 1.0f, 1.0f,
    };

    GLubyte index[] = {
            0, 1, 2, 1, 2, 3,
    };

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, 0, 400, 600);

    GLint vs = glCreateShader(GL_VERTEX_SHADER);
    GLint ps = glCreateShader(GL_FRAGMENT_SHADER);
    GLint program = glCreateProgram();

    glBindAttribLocation(program, 0, "position");
    glBindAttribLocation(program, 1, "position");
    glBindAttribLocation(program, 2, "alpha");
    glShaderSource(vs, 1, &vertexShaderSource, nullptr);
    glShaderSource(ps, 1, &fragmentShaderSource, nullptr);
    glCompileShader(vs);
    glCompileShader(ps);

    glAttachShader(program, vs);
    glAttachShader(program, ps);
    glLinkProgram(program);
    glUseProgram(program);

    GLuint vbo, ibo;
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 3 * 4 * sizeof(GL_FLOAT), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(GLubyte), index, GL_STATIC_DRAW);
    GLint position = glGetAttribLocation(program,  "position");
    if(-1 != position)
    {
        glEnableVertexAttribArray(position);
        glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    }

    if(1 == position)
    {
        __android_log_print(ANDROID_LOG_ERROR,"OGLES2Draw::draw()","1 == position");
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 0, color);

    GLint x = glGetUniformLocation(program, "x");
    glUniform1f(x, 1.0f);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, nullptr);
    glDisableVertexAttribArray(position);
    glUseProgram(0);
    glDeleteProgram(program);
    glDeleteShader(vs);
    glDeleteShader(ps);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ibo);

    GLenum error = glGetError();
    switch (error)
    {
        case 0x0500:
            __android_log_print(ANDROID_LOG_ERROR,"OGLES2Draw::draw()","GL_INVALID_ENUM");
            break;
        case 0x0501:
            __android_log_print(ANDROID_LOG_ERROR,"OGLES2Draw::draw()","GL_INVALID_VALUE");
            break;
        case 0x0502:
            __android_log_print(ANDROID_LOG_ERROR,"OGLES2Draw::draw()","GL_INVALID_OPERATION");
            break;
        case 0x0505:
            __android_log_print(ANDROID_LOG_ERROR,"OGLES2Draw::draw()","GL_OUT_OF_MEMORY");
            break;
        case 0:
            __android_log_print(ANDROID_LOG_ERROR,"OGLES2Draw::draw()","GL_NO_ERROR");
            break;
        default:
            __android_log_print(ANDROID_LOG_ERROR,"OGLES2Draw::draw()","GL_ERROR");
    }



    /*
    glViewport(0, 0, 300, 300);
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    GLenum error = glGetError();
     */

}
