#ifndef __THIRDLEVEL_H__
#define __THIRDLEVEL_H__

#include "cocos2d.h"

using namespace cocos2d;

class level3 : public cocos2d::Scene
{
public:

    static cocos2d::Scene* createScene();

    virtual bool init();

    void paint(EventKeyboard::KeyCode KeyCode, Event* event);


    bool isColored1 = false;
    bool isColored2 = false;
    bool isColored3 = false;
    bool isColored4 = false;
    bool isColored5 = false;
    bool isColored6 = false;
    bool isColored7 = false;


    // implement the "static create()" method manually
    CREATE_FUNC(level3);

    cocos2d::Sprite* Level3_background;
    cocos2d::Sprite* ball3;
    cocos2d::Sprite* color3;

};

#endif
