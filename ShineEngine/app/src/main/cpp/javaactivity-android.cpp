//
// Created by Administrator on 2017/7/3.
//
#include <jni.h>
#include "SGLView.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_geekfaner_shineengine_ShineActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = SGLView::setGLContextAttrs();
    return env->NewStringUTF(hello.c_str());
}
