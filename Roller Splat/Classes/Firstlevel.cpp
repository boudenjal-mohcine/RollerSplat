#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "Firstlevel.h"
#include "Secondlevel.h"
#include "Definitions.h"

USING_NS_CC;

Scene* level1::createScene()
{
    return level1::create();
}



// on "init" you need to initialize your instance
bool level1::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }
    //stopper la music du menu
    CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();

    //Create The level1 ( Ball and Background )
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //set background level
    Level1_background = Sprite::create("lvl1.jpg");
    Level1_background->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(Level1_background, -1);

    //set ball in the level
    ball1 = Sprite::create("redball.png");
    ball1->setPosition(BALL_POSITION_LEVEL1);
    this->addChild(ball1, 0);
    ball1->setName("ball"); 
    
    //Create an event when we press a key
    auto Listener = EventListenerKeyboard::create();
    Listener->onKeyPressed = CC_CALLBACK_2(level1::paint, this);
    ball1->getEventDispatcher()->addEventListenerWithSceneGraphPriority(Listener, ball1);

    return true;
}


//fonction qui traite le mouvement en chaque position , coulerer et partie au niveau suivant si on gangne :
void level1::paint(EventKeyboard::KeyCode KeyCode, Event* event) {


    auto ballVect = ball1->getPosition();
   //Les mouvements possible , il depend de x ou y .
    auto actionMoveright = MoveTo::create(0.09f, Point(410, ballVect.y));
    auto actionMoveup = MoveTo::create(0.09f, Point(ballVect.x, 524));
    auto actionMoveleft = MoveTo::create(0.09f, Point(190, ballVect.y));
    auto actionMovedown = MoveTo::create(0.09f, Point(ballVect.x, 194));

    //faire appelle a chaque mouvement le son d'effet
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("move.mp3");


    switch (KeyCode) {
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
    case EventKeyboard::KeyCode::KEY_A:
        if (ballVect == Point(410, 194)) {
        //repositionnement du ball et faire des tests si la partie est deja coulerer ou non
            ball1->runAction(actionMoveleft);
            if (!isColored1) {
                //si non on les coulerer
                for (int j = 410; j >= 190; j = j - 20) {
                    auto colorred = Sprite::create("red.png");
                    colorred->setPosition(Point(j, ballVect.y));
                    this->addChild(colorred, -1);
                    isColored1 = true;
                }
            }
            //allumer l'effet
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");
        }
        if (ballVect == Point(410, 524)) {
            ball1->runAction(actionMoveleft);
            if (!isColored3) {
                for (int j = 410; j >= 190; j = j - 20) {
                    auto colorred = Sprite::create("red.png");
                    colorred->setPosition(Point(j, ballVect.y));
                    this->addChild(colorred, -1);
                    isColored3 = true;
                }
            }
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }
        break;

    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
    case EventKeyboard::KeyCode::KEY_D:
        if (ballVect == BALL_POSITION_LEVEL1) {
            ball1->runAction(actionMoveright);
            if (!isColored1) {
                for (int j = 190; j <= 410; j = j + 20) {
                    auto colorred = Sprite::create("red.png");
                    colorred->setPosition(Point(j, ballVect.y));
                    this->addChild(colorred, -1);
                    isColored1 = true;
                }
            }
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }
        if (ballVect == Point(190, 524)) {
            ball1->runAction(actionMoveright);
            if (!isColored3) {
                for (int j = 190; j <= 410; j = j + 20) {
                    auto colorred = Sprite::create("red.png");
                    colorred->setPosition(Point(j, ballVect.y));
                    this->addChild(colorred, -1);
                    isColored3 = true;
                }
            }
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }
        break;

    case EventKeyboard::KeyCode::KEY_UP_ARROW:
    case EventKeyboard::KeyCode::KEY_W:
        if (ballVect == BALL_POSITION_LEVEL1) {
            ball1->runAction(actionMoveup);
            if (!isColored2) {
                for (int j = 194; j <= 524; j = j + 30) {
                   auto colorred = Sprite::create("red.png");
                   colorred->setPosition(Point(ballVect.x, j));
                   this->addChild(colorred, -1);
                }
                isColored2 = true;
            }
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }

        if (ballVect == Point(410, 194)) {
            ball1->runAction(actionMoveup);
            if (!isColored4) {
                for (int j = 194; j <= 524; j = j + 30) {
                    auto colorred = Sprite::create("red.png");
                    colorred->setPosition(Point(ballVect.x, j));
                    this->addChild(colorred, -1);
                }
                isColored4 = true;
            }
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }
        break;

    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
    case EventKeyboard::KeyCode::KEY_S:
        if (ballVect == Point(190, 524)) {
            ball1->runAction(actionMovedown);
            if (!isColored2) {
                for (int j = 524; j >= 194; j = j - 30) {
                    auto colorred = Sprite::create("red.png");
                    colorred->setPosition(Point(ballVect.x, j));
                    this->addChild(colorred, -1);
                }
                isColored2 = true;
            }
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }

        if (ballVect == Point(410, 524)) {
            ball1->runAction(actionMovedown);
            if (!isColored4) {
                for (int j = 524; j >= 194; j = j - 30) {
                    auto colorred = Sprite::create("red.png");
                    colorred->setPosition(Point(ballVect.x, j));
                    this->addChild(colorred, -1);
                }
                isColored4 = true;
            }
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }
        break;


    }

    //tester si tout les partie est coulerer
    if (isColored1 && isColored2 && isColored3 && isColored4)
    {
        //l'effet du win
        CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("win.mp3");
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("win.mp3");
      
        //la balle jump
        auto actionWIN = JumpBy::create(8, Point(0, 0), 80, 20);
        ball1->runAction(actionWIN);

        //allez au niveau prochain
        auto scene = level2::createScene();
        Director::getInstance()->pushScene(TransitionFade::create(TRANSITION_TIME_SCENE, scene));

      
    }
}