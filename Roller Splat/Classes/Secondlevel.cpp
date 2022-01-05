#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "Secondlevel.h"
#include "Thirdlevel.h"
#include "Definitions.h"



USING_NS_CC;

Scene* level2::createScene()
{
    return level2::create();
}



// on "init" you need to initialize your instance
bool level2::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //set background of level2 from Resources
    Level2_background = Sprite::create("lvl2.png");
    Level2_background->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(Level2_background, -1);

    //set yellowbal from Resources
    ball2 = Sprite::create("yellowball.png");
    ball2->setPosition(Point(405, 210));
    this->addChild(ball2, 1);
    
    //Create an event when we press a key
    auto Listener = EventListenerKeyboard::create();
    Listener->onKeyPressed = CC_CALLBACK_2(level2::paint, this);
    ball2->getEventDispatcher()->addEventListenerWithSceneGraphPriority(Listener, ball2);
  
   
    return true;
}



void level2::paint(EventKeyboard::KeyCode KeyCode, Event* event) {

    //Positionnement actuelle du balle
    auto ballVect = ball2->getPosition();

    //les mouvements possibles
    auto actionMoveright = MoveTo::create(0.09f, Point(405, ballVect.y));
    auto actionMoveup1 = MoveTo::create(0.09f, Point(ballVect.x, 362));
    auto actionMoveup2 = MoveTo::create(0.09f, Point(ballVect.x, 515));
    auto actionMoveleft = MoveTo::create(0.09f, Point(185, ballVect.y));
    auto actionMovedown1 = MoveTo::create(0.09f, Point(ballVect.x, 362));
    auto actionMovedown2 = MoveTo::create(0.09f, Point(ballVect.x, 210));

    //Effet music
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("move.mp3");


    //run action en fonction du positionnement et d'action correspendant
    switch (KeyCode) {

    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
    case EventKeyboard::KeyCode::KEY_A:
        if (ballVect == Point(405, 210)) {
            ball2->runAction(actionMoveleft);
             if (!isColored1) {
             for (int j = 405; j >= 183; j = j - 37) {
                auto coloryellow = Sprite::create("yellow.png");
                coloryellow->setPosition(Point(j, ballVect.y+5));
                this->addChild(coloryellow, -1);
                isColored1 = true;
                }
            
             }
             CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");
        }

        if (ballVect == Point(405, 362)) {
            ball2->runAction(actionMoveleft);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");
        }

        if (ballVect == Point(405, 515)) {
            ball2->runAction(actionMoveleft);
            if (!isColored5) {
           for (int j = 400; j >= 185; j = j - 5) {
              auto coloryellow = Sprite::create("yellow.png");
              coloryellow->setPosition(Point(j, ballVect.y));
              this->addChild(coloryellow, -1);
               isColored5 = true;
            }
          }
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");
        }
        break;

    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
    case EventKeyboard::KeyCode::KEY_D:

        if (ballVect == Point(185, 362)) {
            ball2->runAction(actionMoveright);
            if (!isColored3) {
            for (int j = 185; j <= 400; j = j + 1) {
                auto coloryellow = Sprite::create("yellow.png");
                coloryellow->setPosition(Point(j, ballVect.y+2));
                this->addChild(coloryellow, -1);
                isColored3 = true;
                }
              }
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");
        }

        if (ballVect == Point(185, 210)) {
            ball2->runAction(actionMoveright);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");
        }

        if (ballVect == Point(185, 515)) {
            ball2->runAction(actionMoveright);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");
        }
        break;

    case EventKeyboard::KeyCode::KEY_UP_ARROW:
    case EventKeyboard::KeyCode::KEY_W:

        if (ballVect == Point(185, 210)) {
           ball2->runAction(actionMoveup1);
           if (!isColored2) {
            for (int j = 220; j <= 362; j++) {
                auto coloryellow = Sprite::create("yellow.png");
                coloryellow->setPosition(Point(ballVect.x-1, j));
                this->addChild(coloryellow, -1);
            }
            isColored2 = true;
           
           }

            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }

        if (ballVect == Point(405, 362)) {

            ball2->runAction(actionMoveup2);
             if (!isColored4) {
            for (int j = 365; j <= 520; j = j + 10) {
                auto coloryellow = Sprite::create("yellow.png");
               coloryellow->setPosition(Point(ballVect.x-3, j));
               this->addChild(coloryellow, -1);
            }
              isColored4 = true;
          }
             CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }
        break;

    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
    case EventKeyboard::KeyCode::KEY_S:
        
        if (ballVect == Point(405, 515)) {

            ball2->runAction(actionMovedown1);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }

        if (ballVect == Point(185, 362)) {
            ball2->runAction(actionMovedown2);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }

        break;


    }
    //tester si tout les partie est coulerer
    if (isColored1 && isColored2 && isColored3 && isColored4 && isColored5)
    {
        //l'effet du win
        CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("win.mp3");
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("win.mp3");
        
        //ball jump
        auto actionWIN = JumpBy::create(8, Point(0, 0), 80, 20);
        ball2->runAction(actionWIN);

        //go to level3
        auto scene = level3::createScene();
        Director::getInstance()->pushScene(TransitionFade::create(TRANSITION_TIME_SCENE, scene));
    }

}