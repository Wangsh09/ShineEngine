//
// Created by Administrator on 2017/7/4.
//

#include "Director.h"

#define kDefaultFPS        60  // 60 frames per second

// singleton stuff
static Director *s_SharedDirector = nullptr;

Director::Director()
: _isStatusLabelUpdated(true)
, _invalid(true)
{
}

Director::~Director(void)
{

    __android_log_print(ANDROID_LOG_INFO,"Director::~Director(void)","deallocing Director");

    //Patrick : TODO
    /*
    CC_SAFE_RELEASE(_FPSLabel);
    CC_SAFE_RELEASE(_drawnVerticesLabel);
    CC_SAFE_RELEASE(_drawnBatchesLabel);

    CC_SAFE_RELEASE(_runningScene);
    CC_SAFE_RELEASE(_notificationNode);
    CC_SAFE_RELEASE(_scheduler);
    CC_SAFE_RELEASE(_actionManager);
    CC_SAFE_DELETE(_defaultFBO);

    CC_SAFE_RELEASE(_beforeSetNextScene);
    CC_SAFE_RELEASE(_afterSetNextScene);
    CC_SAFE_RELEASE(_eventBeforeUpdate);
    CC_SAFE_RELEASE(_eventAfterUpdate);
    CC_SAFE_RELEASE(_eventAfterDraw);
    CC_SAFE_RELEASE(_eventBeforeDraw);
    CC_SAFE_RELEASE(_eventAfterVisit);
    CC_SAFE_RELEASE(_eventProjectionChanged);
    CC_SAFE_RELEASE(_eventResetDirector);

    delete _renderer;
    delete _console;

    CC_SAFE_RELEASE(_eventDispatcher);

    Configuration::destroyInstance();
     */

    s_SharedDirector = nullptr;
}

Director* Director::getInstance()
{
    if (!s_SharedDirector)
    {
        s_SharedDirector = new (std::nothrow) Director;
        if(s_SharedDirector == nullptr)
            __android_log_print(ANDROID_LOG_FATAL,"Director::getInstance()","FATAL: Not enough memory");
        s_SharedDirector->init();
    }

    return s_SharedDirector;
}

bool Director::init(void)
{
    setDefaultValues();

    _winSizeInPoints = Size(0, 0);

    // invalid ?
    _invalid = false;
    //Patrick : TODO
    /*
    // scenes
    _runningScene = nullptr;
    _nextScene = nullptr;

    _notificationNode = nullptr;

    _scenesStack.reserve(15);

    // FPS
    _accumDt = 0.0f;
    _frameRate = 0.0f;
    _FPSLabel = _drawnBatchesLabel = _drawnVerticesLabel = nullptr;
    _totalFrames = 0;
    _lastUpdate = std::chrono::steady_clock::now();

    _secondsPerFrame = 1.0f;
    _frames = 0;

    // paused ?
    _paused = false;

    // purge ?
    _purgeDirectorInNextLoop = false;

    // restart ?
    _restartDirectorInNextLoop = false;


    _openGLView = nullptr;
    _defaultFBO = nullptr;

    _contentScaleFactor = 1.0f;

    _console = new (std::nothrow) Console;

    // scheduler
    _scheduler = new (std::nothrow) Scheduler();
    // action manager
    _actionManager = new (std::nothrow) ActionManager();
    _scheduler->scheduleUpdate(_actionManager, Scheduler::PRIORITY_SYSTEM, false);

    _eventDispatcher = new (std::nothrow) EventDispatcher();

    _beforeSetNextScene = new (std::nothrow) EventCustom(EVENT_BEFORE_SET_NEXT_SCENE);
    _beforeSetNextScene->setUserData(this);
    _afterSetNextScene = new (std::nothrow) EventCustom(EVENT_AFTER_SET_NEXT_SCENE);
    _afterSetNextScene->setUserData(this);
    _eventAfterDraw = new (std::nothrow) EventCustom(EVENT_AFTER_DRAW);
    _eventAfterDraw->setUserData(this);
    _eventBeforeDraw = new (std::nothrow) EventCustom(EVENT_BEFORE_DRAW);
    _eventBeforeDraw->setUserData(this);
    _eventAfterVisit = new (std::nothrow) EventCustom(EVENT_AFTER_VISIT);
    _eventAfterVisit->setUserData(this);
    _eventBeforeUpdate = new (std::nothrow) EventCustom(EVENT_BEFORE_UPDATE);
    _eventBeforeUpdate->setUserData(this);
    _eventAfterUpdate = new (std::nothrow) EventCustom(EVENT_AFTER_UPDATE);
    _eventAfterUpdate->setUserData(this);
    _eventProjectionChanged = new (std::nothrow) EventCustom(EVENT_PROJECTION_CHANGED);
    _eventProjectionChanged->setUserData(this);
    _eventResetDirector = new (std::nothrow) EventCustom(EVENT_RESET);
    //init TextureCache
    initTextureCache();
    initMatrixStack();
    */

    _renderer = new (std::nothrow) Renderer;


    //Patrick : TODO
    /*
     RenderState::initialize();
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    EngineDataManager::init();
#endif
     */
    return true;
}

void Director::setDefaultValues(void)
{
    Configuration *conf = Configuration::getInstance();

    double fps = kDefaultFPS;
    _oldAnimationInterval = _animationInterval = 1.0 / fps;
    _displayStats = false;
    std::string projection = "3d";
    Texture2D::setDefaultAlphaPixelFormat(Texture2D::PixelFormat::RGBA8888);
    Image::setPVRImagesHavePremultipliedAlpha(false);

    //Patrick : TODO
    /*
    // default FPS
    double fps = conf->getValue("cocos2d.x.fps", Value(kDefaultFPS)).asDouble();
    _oldAnimationInterval = _animationInterval = 1.0 / fps;

    // Display FPS
    _displayStats = conf->getValue("cocos2d.x.display_fps", Value(false)).asBool();

    // GL projection
    std::string projection = conf->getValue("cocos2d.x.gl.projection", Value("3d")).asString();
    if (projection == "3d")
        _projection = Projection::_3D;
    else if (projection == "2d")
        _projection = Projection::_2D;
    else if (projection == "custom")
        _projection = Projection::CUSTOM;
    else
        CCASSERT(false, "Invalid projection value");

    // Default pixel format for PNG images with alpha
    std::string pixel_format = conf->getValue("cocos2d.x.texture.pixel_format_for_png", Value("rgba8888")).asString();
    if (pixel_format == "rgba8888")
        Texture2D::setDefaultAlphaPixelFormat(Texture2D::PixelFormat::RGBA8888);
    else if(pixel_format == "rgba4444")
        Texture2D::setDefaultAlphaPixelFormat(Texture2D::PixelFormat::RGBA4444);
    else if(pixel_format == "rgba5551")
        Texture2D::setDefaultAlphaPixelFormat(Texture2D::PixelFormat::RGB5A1);

    // PVR v2 has alpha premultiplied ?
    bool pvr_alpha_premultiplied = conf->getValue("cocos2d.x.texture.pvrv2_has_alpha_premultiplied", Value(false)).asBool();
    Image::setPVRImagesHavePremultipliedAlpha(pvr_alpha_premultiplied);
    */
}

void Director::setOpenGLView(GLView *openGLView)
{
    if(openGLView == nullptr)
        __android_log_print(ANDROID_LOG_WARN,"Director::setOpenGLView","opengl view should not be null");

    if (_openGLView != openGLView)
    {
        // Configuration. Gather GPU info
        Configuration *conf = Configuration::getInstance();

        //Patrick : TODO
        /*
        conf->gatherGPUInfo();
        CCLOG("%s\n",conf->getInfo().c_str());

        if(_openGLView)
            _openGLView->release();
        */
        _openGLView = openGLView;

        //_openGLView->retain();

        // set size
        _winSizeInPoints = _openGLView->getDesignResolutionSize();

        _isStatusLabelUpdated = true;

        if (_openGLView)
        {
            setGLDefaultValues();
        }

        _renderer->initGLView();

        //Patrick : TODO
        /*
        CHECK_GL_ERROR_DEBUG();

        if (_eventDispatcher)
        {
            _eventDispatcher->setEnabled(true);
        }

        _defaultFBO = experimental::FrameBuffer::getOrCreateDefaultFBO(_openGLView);
        _defaultFBO->retain();
         */
    }
}

void Director::setGLDefaultValues()
{
    // This method SHOULD be called only after openGLView_ was initialized
    if(_openGLView == nullptr)
        __android_log_print(ANDROID_LOG_WARN,"Director::setGLDefaultValues","opengl view should not be null");

    //Patrick : TODO
    /*
    setAlphaBlending(true);
    setDepthTest(false);
    setProjection(_projection);
    */
}

void Director::mainLoop()
{
    //Patrick : TODO
    /*
    if (_purgeDirectorInNextLoop)
    {
        _purgeDirectorInNextLoop = false;
        purgeDirector();
    }
    else if (_restartDirectorInNextLoop)
    {
        _restartDirectorInNextLoop = false;
        restartDirector();
    }
    else */if (! _invalid)
    {
        drawScene();

        //Patrick : TODO
        /*
        // release the objects
        PoolManager::getInstance()->getCurrentPool()->clear();
         */
    }
}

// Draw the Scene
void Director::drawScene()
{
    /*
    // calculate "global" dt
    calculateDeltaTime();

    if (_openGLView)
    {
        _openGLView->pollEvents();
    }

    //tick before glClear: issue #533
    if (! _paused)
    {
        _eventDispatcher->dispatchEvent(_eventBeforeUpdate);
        _scheduler->update(_deltaTime);
        _eventDispatcher->dispatchEvent(_eventAfterUpdate);
    }

    _renderer->clear();
    experimental::FrameBuffer::clearAllFBOs();

    _eventDispatcher->dispatchEvent(_eventBeforeDraw);

    // to avoid flickr, nextScene MUST be here: after tick and before draw.
    // FIXME: Which bug is this one. It seems that it can't be reproduced with v0.9
    if (_nextScene)
    {
        setNextScene();
    }

    pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);

    if (_runningScene)
    {
#if (CC_USE_PHYSICS || (CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION) || CC_USE_NAVMESH)
        _runningScene->stepPhysicsAndNavigation(_deltaTime);
#endif
        //clear draw stats
        _renderer->clearDrawStats();

        //render the scene
        _openGLView->renderScene(_runningScene, _renderer);

        _eventDispatcher->dispatchEvent(_eventAfterVisit);
    }

    // draw the notifications node
    if (_notificationNode)
    {
        _notificationNode->visit(_renderer, Mat4::IDENTITY, 0);
    }

    updateFrameRate();

    if (_displayStats)
    {
#if !CC_STRIP_FPS
        showStats();
#endif
    }

    _renderer->render();

    _eventDispatcher->dispatchEvent(_eventAfterDraw);

    popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);

    _totalFrames++;

    // swap buffers
    if (_openGLView)
    {
        _openGLView->swapBuffers();
    }

    if (_displayStats)
    {
#if !CC_STRIP_FPS
        calculateMPF();
#endif
    }
     */
}