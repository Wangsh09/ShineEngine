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
            "attribute float depth;\n"
            "attribute vec2 texcoord;\n"
            "varying vec2 uv;\n"
            "void main()\n"
            "{"
            "uv = texcoord;\n"
            "gl_Position = vec4(position, depth);\n"
            "}";

    const GLchar* fragmentShaderSource = "precision mediump float;\n"
            "uniform float x;\n"
            "uniform sampler2D tex;\n"
            "varying vec2 uv;\n"
            "void main()\n"
            "{"
            "gl_FragColor = texture2D(tex, uv, 0.0);\n"
            "}";

    GLfloat vertices[] = {
            -0.5f, -0.5f, 0.0f, // BottomLeft
            0.5f, -0.5f, 0.0f, // BottomRight
            -0.5f,  0.5f, 0.0f,  // TopLeft
            0.5f,  0.5f, 0.0f,  // TopRight
    };

    GLfloat depth[] = {
            1.0f, 1.0f, 1.0f, 1.0f,
    };

    GLfloat uv[] =
            {
                    0.0f, 0.0f,
                    0.0f, 1.0f,
                    1.0f, 0.0f,
                    1.0f, 1.0f,
            };



    GLubyte index[] = {
            0, 1, 2, 2, 1, 3,
    };

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, 0, 64, 64);

    GLint vs = glCreateShader(GL_VERTEX_SHADER);
    GLint ps = glCreateShader(GL_FRAGMENT_SHADER);
    GLint program = glCreateProgram();

    glBindAttribLocation(program, 0, "position");
    glBindAttribLocation(program, 1, "position");
    glBindAttribLocation(program, 2, "depth");
    glShaderSource(vs, 1, &vertexShaderSource, nullptr);
    glShaderSource(ps, 1, &fragmentShaderSource, nullptr);
    glCompileShader(vs);
    glCompileShader(ps);

    Check_CompileShader(ps);

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
    //glVertexAttrib1f(2, 1.0f);
    glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 0, depth);

    GLint x = glGetUniformLocation(program, "x");
    glUniform1f(x, 1.0f);

    int width = 128;
    int height = 128;

    GLubyte* pixels1;
    pixels1 = GenCheckImage(width, height, 1);

    GLubyte* pixels2;
    pixels2 = GenCheckImage(width / 2, height / 2, 2);

    GLubyte* pixels3;
    pixels3 = GenCheckImage(width / 4, height / 4, 3);

    GLubyte* pixels4;
    pixels4 = GenCheckImage(width / 8, height / 8, 4);

    GLubyte* pixels5;
    pixels5 = GenCheckImage(width / 16, height / 16, 5);

    GLubyte* pixels6;
    pixels6 = GenCheckImage(width / 32, height / 32, 6);

    GLubyte* pixels7;
    pixels7 = GenCheckImage(width / 64, height / 64, 7);

    GLubyte* pixels8;
    pixels8 = GenCheckImage(width / 128, height / 128, 8);


    GLuint texture;
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels1);
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexImage2D(GL_TEXTURE_2D, 1, GL_RGB, width / 2, height / 2, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels2);
    glTexImage2D(GL_TEXTURE_2D, 2, GL_RGB, width / 4, height / 4, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels3);
    glTexImage2D(GL_TEXTURE_2D, 3, GL_RGB, width / 8, height / 8, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels4);
    glTexImage2D(GL_TEXTURE_2D, 4, GL_RGB, width / 16, height / 16, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels5);
    glTexImage2D(GL_TEXTURE_2D, 5, GL_RGB, width / 32, height / 32, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels6);
    glTexImage2D(GL_TEXTURE_2D, 6, GL_RGB, width / 64, height / 64, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels7);
    glTexImage2D(GL_TEXTURE_2D, 7, GL_RGB, width / 128, height / 128, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels8);
    GLint textureLocation = glGetUniformLocation(program, "tex");
    glActiveTexture (GL_TEXTURE0);
    glBindTexture (GL_TEXTURE_2D, texture);
    glUniform1i(textureLocation, 0);

    GLint uvLocation = glGetAttribLocation(program, "texcoord");
    glEnableVertexAttribArray(uvLocation);
    glVertexAttribPointer(uvLocation, 2, GL_FLOAT,  GL_FALSE, 0, uv);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, nullptr);
    glDisableVertexAttribArray(position);
    glDisableVertexAttribArray(uvLocation);
    glUseProgram(0);
    glDeleteProgram(program);
    glDeleteShader(vs);
    glDeleteShader(ps);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ibo);

    /*
    glViewport(0, 0, 300, 300);
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    GLenum error = glGetError();
     */

}

void OGLES2Draw::Check_Error()
{
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
}

void OGLES2Draw::Check_CompileShader(GLint shader)
{
    GLint nGetLogLength = 0;
    GLchar *sGetLog = NULL;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &nGetLogLength);
    sGetLog = (GLchar *)malloc(sizeof(GLchar) * nGetLogLength);
    glGetShaderInfoLog(shader, nGetLogLength, NULL, sGetLog);
    __android_log_print(ANDROID_LOG_ERROR,"OGLES2Draw::draw()","%s", sGetLog);
}
//  Generate an RGB8 checkerboard image
GLubyte* OGLES2Draw::GenCheckImage(int width, int height, int colorOffset)
{
    int x, y;
    int checkSize = 8;
    GLubyte *pixels = (GLubyte *)malloc(width * height * 3);

    if (pixels == NULL)
        return NULL;

    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            GLubyte rColor = 0;
            GLubyte gColor = 0;
            GLubyte bColor = 0;

            if((x / checkSize) % 2 == 0)
            {
                if(colorOffset == 1)
                {
                    rColor = 255;
                    gColor = 0;
                    bColor = 0;
                }
                else if(colorOffset == 2)
                {
                    rColor = 0;
                    gColor = 255;
                    bColor = 0;
                }
                else if(colorOffset == 3)
                {
                    rColor = 0;
                    gColor = 0;
                    bColor = 255;
                }
                else if(colorOffset == 4)
                {
                    rColor = 255;
                    gColor = 255;
                    bColor = 0;
                }
                else if(colorOffset == 5)
                {
                    rColor = 255;
                    gColor = 0;
                    bColor = 255;
                }
                else if(colorOffset == 6)
                {
                    rColor = 0;
                    gColor = 255;
                    bColor = 255;
                }
                else if(colorOffset == 7)
                {
                    rColor = 255;
                    gColor = 255;
                    bColor = 255;
                }
                else if(colorOffset == 8)
                {
                    rColor = 0;
                    gColor = 0;
                    bColor = 0;
                }
            }
            else
            {
                rColor = 0;
                gColor = 0;
                bColor = 255;
            }


            /*
            if ((x / checkSize) % 2 == 0)
            {
                rColor = 255 * ((y / checkSize) % 2);
                bColor = 255 * (1 - ((y / checkSize) % 2));
            }
            else
            {
                bColor = 255 * ((y / checkSize) % 2);
                rColor = 255 * (1 - ((y / checkSize) % 2));
            }
             */

            pixels[(y * width + x) * 3] = rColor;
            pixels[(y * width + x) * 3 + 1] = gColor;
            pixels[(y * width + x) * 3 + 2] = bColor;
        }
    }
    return pixels;
}
