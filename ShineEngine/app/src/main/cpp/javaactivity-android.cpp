//
// Created by Administrator on 2017/7/3.
//
#include <jni.h>
#include "SGLView.h"

extern "C"
JNIEXPORT jintArray JNICALL
Java_com_geekfaner_shineengine_ShineActivity_getGLContextAttrs(
        JNIEnv* env,
        jobject /* this */) {
    //Patric : TODO
    //cocos2d::Application::getInstance()->initGLContextAttrs();
    GLContextAttrs _glContextAttrs = SGLView::getGLContextAttrs();
    int tmp[6] = {_glContextAttrs.redBits, _glContextAttrs.greenBits, _glContextAttrs.blueBits,
                  _glContextAttrs.alphaBits, _glContextAttrs.depthBits, _glContextAttrs.stencilBits};


    jintArray glContextAttrsJava = env->NewIntArray(6);
    env->SetIntArrayRegion(glContextAttrsJava, 0, 6, tmp);
    return glContextAttrsJava;
}
