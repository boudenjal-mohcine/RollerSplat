#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "Firstlevel.h"
#include "Definitions.h"




USING_NS_CC;
//Cree la scene Menu
Scene* MainMenu::createScene()
{
    return MainMenu::create();
}



// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    //Cree un echelle pour positionner les choses
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //Set backgroiund of MainMenu
    auto background = Sprite::create("background.png");
    background->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(background, -1);

    //Ajouter une music 
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("musicmenu.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("musicmenu.mp3");

   //Ajouter une botton de commenacer le jeu
   auto playItem =
        MenuItemImage::create("Play_Button.png",
                              "Play_Button.png",
                              CC_CALLBACK_1(MainMenu::GoToLevel1, this));

    auto menu = Menu::create(playItem,NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height);
    this->addChild(menu);

    return true;
}


//Fonction pour partir au niveau 1
void MainMenu::GoToLevel1(Ref* pSender)
{
    //go to a level1
    auto scene = level1::createScene();
    Director::getInstance()->pushScene(TransitionFade::create(TRANSITION_TIME_SCENE, scene));
}

