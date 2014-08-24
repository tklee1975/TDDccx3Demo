#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}


void setupResolutionPolicy(float designW, float designH)
{
	GLView *view = Director::getInstance()->getOpenGLView();
	Size screenSize = view->getFrameSize();
    
	float designRatio = designW / designH;
	float screenRatio = screenSize.height / screenSize.width;
	
	ResolutionPolicy resolutionPolicy = screenRatio < designRatio ?
	ResolutionPolicy::FIXED_HEIGHT : ResolutionPolicy::FIXED_WIDTH;
	
    view->setDesignResolutionSize(designW, designH, resolutionPolicy);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }
	
	setupResolutionPolicy(568, 320);	// 1136 x 640 / 2
										// 800 x 400 is a common android resolution

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
