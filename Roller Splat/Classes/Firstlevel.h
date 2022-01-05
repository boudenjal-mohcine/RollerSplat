#ifndef __FIRSTLEVEL_H__
#define __FIRSTLEVEL_H__

#include "cocos2d.h"

using namespace cocos2d;

class level1 : public cocos2d::Scene
{
public:

    static cocos2d::Scene* createScene();

    virtual bool init();

    void paint(EventKeyboard::KeyCode KeyCode, Event* event);

    //variable depend du coloration des parties
    bool isColored1 = false;
    bool isColored2 = false;
    bool isColored3 = false;
    bool isColored4 = false;



    // implement the "static create()" method manually
    CREATE_FUNC(level1);

    cocos2d::Sprite* Level1_background;
    cocos2d::Sprite* ball1;
    cocos2d::Sprite* color1;
};

#endif
