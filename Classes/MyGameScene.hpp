//
//  MyGameScene.hpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/18.
//
//

#ifndef MyGameScene_hpp
#define MyGameScene_hpp

#include <stdio.h>

#include "BaseGameScene.hpp"
#include "ControllerLayer.hpp"
#include "Global.hpp"

class MyGameScene:public BaseGameScene
{
public:
    static cocos2d::Scene* createScene();
    
    MyGameScene();
    void updateEvent(float dt);
    virtual void onEnter();
    
};
#endif /* MyGameScene_hpp */
