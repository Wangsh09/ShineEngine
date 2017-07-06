//
// Created by Administrator on 2017/7/3.
//
#include <jni.h>
#include "GLView.h"
#include "Director.h"
#include "GLViewImpl.h"
#include "Application.h"

extern "C"
{
JNIEXPORT jintArray JNICALL
Java_com_geekfaner_shineengine_ShineActivity_getGLContextAttrs(
        JNIEnv *env,
        jobject /* this */) {
    //Patrick : TODO
    //cocos2d::Application::getInstance()->initGLContextAttrs();
    GLContextAttrs _glContextAttrs = GLView::getGLContextAttrs();
    int tmp[6] = {_glContextAttrs.redBits, _glContextAttrs.greenBits, _glContextAttrs.blueBits,
                  _glContextAttrs.alphaBits, _glContextAttrs.depthBits,
                  _glContextAttrs.stencilBits};


    jintArray glContextAttrsJava = env->NewIntArray(6);
    env->SetIntArrayRegion(glContextAttrsJava, 0, 6, tmp);
    return glContextAttrsJava;
}

JNIEXPORT void JNICALL
Java_com_geekfaner_shineengine_SRenderer_nativeInit(JNIEnv *env, jobject thiz, jint w, jint h) {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview) {
        glview = GLViewImpl::create("Android app");
        glview->setFrameSize(w, h);
        director->setOpenGLView(glview);

        //Patrick : TODO
        //Application::getInstance()->run();
    } else {
        //Patrick : TODO
        /*
        cocos2d::GL::invalidateStateCache();
        cocos2d::GLProgramCache::getInstance()->reloadDefaultGLPrograms();
        cocos2d::DrawPrimitives::init();
        cocos2d::VolatileTextureMgr::reloadAllTextures();

        cocos2d::EventCustom recreatedEvent(EVENT_RENDERER_RECREATED);
        director->getEventDispatcher()->dispatchEvent(&recreatedEvent);
        director->setGLDefaultValues();
         */
    }
    //Patrick : TODO
    /*cocos2d::network::_preloadJavaDownloaderClass();*/
}

JNIEXPORT void JNICALL
Java_com_geekfaner_shineengine_SRenderer_nativeOnSurfaceChanged(JNIEnv *env, jobject thiz, jint w,
                                                                jint h) {
    //Patrick : TODO
    //Application::getInstance()->applicationScreenSizeChanged(w, h);
}

JNIEXPORT void JNICALL Java_com_geekfaner_shineengine_SRenderer_nativeRender(JNIEnv *env) {
    Director::getInstance()->mainLoop();
}
}
