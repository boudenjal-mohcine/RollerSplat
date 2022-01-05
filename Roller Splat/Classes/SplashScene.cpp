#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "SplashScene.h"



USING_NS_CC;

Scene* SplashScene::createScene()
{
    return SplashScene::create();
}



// on "init" you need to initialize your instance
bool SplashScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    this->scheduleOnce(schedule_selector(SplashScene::GoToMainMenu), 2.0);

    auto background = Sprite::create("splash.png");
    background->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(background, -1);

   
    return true;
}

void SplashScene::GoToMainMenu(float dt)
{
    //go to a MainPage
    auto scene = MainMenu::createScene();
    Director::getInstance()->pushScene(TransitionFade::create(2.0, scene));
}

