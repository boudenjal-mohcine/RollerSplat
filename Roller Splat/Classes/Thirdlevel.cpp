#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "Thirdlevel.h"

USING_NS_CC;

Scene* level3::createScene()
{
    return level3::create();
}



// on "init" you need to initialize your instance
bool level3::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //set level3 background
    Level3_background = Sprite::create("lvl3.jpeg");
    Level3_background->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(Level3_background, -1);
    
    //set blue ball of level3
    ball3 = Sprite::create("blueball.png");
    ball3->setPosition(Point(260,340));
    this->addChild(ball3, 0);

    //le capteur du touche et qui fait appelle au fonction paint
    //Create an event when we press a key
    auto Listener = EventListenerKeyboard::create();
    Listener->onKeyPressed = CC_CALLBACK_2(level3::paint, this);
    ball3->getEventDispatcher()->addEventListenerWithSceneGraphPriority(Listener, ball3);



   
    return true;
}


void level3::paint(EventKeyboard::KeyCode KeyCode, Event* event) {

    //Positionnement du balle et les mouvements possibles
    auto ballVect = ball3->getPosition();
    auto actionMoveright = MoveTo::create(0.09f, Point(410, ballVect.y));
    auto actionMoveup1 = MoveTo::create(0.09f, Point(ballVect.x, 437));
    auto actionMoveup2 = MoveTo::create(0.09f, Point(ballVect.x, 539));
    auto actionMoveup3 = MoveTo::create(0.09f, Point(ballVect.x, 340));
    auto actionMoveleft = MoveTo::create(0.09f, Point(150, ballVect.y));
    auto actionMoveleft2 = MoveTo::create(0.09f, Point(260, ballVect.y));
    auto actionMovedown = MoveTo::create(0.09f, Point(ballVect.x, 155));
    auto actionMovedown2 = MoveTo::create(0.09f, Point(ballVect.x, 210));


    //Effet music
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("move.mp3");

    //°En fonction du position , RunAction correspendant
    switch (KeyCode) {


    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
    case EventKeyboard::KeyCode::KEY_D:
        if (ballVect == Point(260, 340)) {
            ball3->runAction(actionMoveright);
            if (!isColored1) {
                for (int i = 260; i < 415; i = i + 5) {
                    color3 = Sprite::create("blue.jpg");
                    color3->setPosition(Point(i, ballVect.y));
                    this->addChild(color3, -1);
                }
            isColored1 = true;
            }
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }

        if (ballVect == Point(150, 437)) {
            ball3->runAction(actionMoveright);
            if (!isColored5) {
                for (int i = 150; i < 420; i = i + 20) {
                    color3 = Sprite::create("blue.jpg");
                    color3->setPosition(Point(i, ballVect.y));
                    this->addChild(color3, -1);
                }
                isColored5 = true;
            }
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }

        if (ballVect == Point(150, 155)) {
            ball3->runAction(actionMoveright);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }

        break;

    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
    case EventKeyboard::KeyCode::KEY_S:

        if (ballVect == Point(410, 340)) {
            ball3->runAction(actionMovedown);
            if (!isColored2) {
                for (int i = 340; i >= 155; i = i - 5) {
                    color3 = Sprite::create("blue.jpg");
                    color3->setPosition(Point(ballVect.x, i));
                    this->addChild(color3, -1);
                }
            isColored2 = true;
            }
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }

        if (ballVect == Point(410, 539)) {
            ball3->runAction(actionMoveup1);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }

        if (ballVect == Point(150, 437)) {
            ball3->runAction(actionMovedown);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }

        break;
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
    case EventKeyboard::KeyCode::KEY_A:

        if (ballVect == Point(410, 155)) {
            ball3->runAction(actionMoveleft);
            if (!isColored3) {
                for (int i = 410; i > 150; i = i - 5) {
                    color3 = Sprite::create("blue.jpg");
                    color3->setPosition(Point(i, ballVect.y));
                    this->addChild(color3, -1);
                }
                isColored3 = true;
            }
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }

        if (ballVect == Point(410, 539)) {
            ball3->runAction(actionMoveleft);
            if (!isColored7) {
                for (int i = 410; i > 150; i = i - 10) {
                    color3 = Sprite::create("blue.jpg");
                    color3->setPosition(Point(i, ballVect.y));
                    this->addChild(color3, -1);
                }
                isColored7 = true;
            }
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }

        if (ballVect == Point(410, 437)) {
            ball3->runAction(actionMoveleft);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }

        if (ballVect == Point(410, 340)) {
            ball3->runAction(actionMoveleft2);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }

        break;

    case EventKeyboard::KeyCode::KEY_UP_ARROW:
    case EventKeyboard::KeyCode::KEY_W:

        if (ballVect == Point(150, 155)) {
            ball3->runAction(actionMoveup1);
            if (!isColored6) {
                for (int i = 155; i < 440; i = i + 5) {
                    color3 = Sprite::create("blue.jpg");
                    color3->setPosition(Point(ballVect.x, i));
                    this->addChild(color3, -1);
                }
             isColored6 = true;
            }
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }

        if (ballVect == Point(410, 437)) {
            ball3->runAction(actionMoveup2);
            if (!isColored4) {
                for (int i = 437; i <= 547; i = i + 20) {
                    color3 = Sprite::create("blue.jpg");
                    color3->setPosition(Point(ballVect.x, i));
                    this->addChild(color3, -1);

                }
                isColored4 = true;
            }
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }

        if (ballVect == Point(410, 155)) {
            ball3->runAction(actionMoveup3);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("move.mp3");

        }
        break;
    }

    //verifier si tout les partie sont colorer

    if (isColored1 && isColored2 && isColored3 && isColored4 && isColored5 && isColored6 && isColored7)
    {
      
        //ball jump
        auto actionWIN = JumpBy::create(8, Point(0, 0), 80, 20);
        ball3->runAction(actionWIN);

        //Retourner a la page menu
        auto scene = MainMenu::createScene();
        Director::getInstance()->pushScene(TransitionFade::create(8.0, scene));

    }
}