#ifndef __SECONDLEVEL_H__
#define __SECONDLEVEL_H__

#include "cocos2d.h"

using namespace cocos2d;

class level2 : public cocos2d::Scene
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

    // implement the "static create()" method manually
    CREATE_FUNC(level2);

    cocos2d::Sprite* Level2_background;
    cocos2d::Sprite* ball2;
    cocos2d::Sprite* color2;


};

#endif
