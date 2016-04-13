//
//  ControllerLayer.hpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/18.
//
//

#ifndef ControllerLayer_hpp
#define ControllerLayer_hpp

#include <stdio.h>

#include "cocos2d.h"
#include "JoyStick.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "HelloWorldScene.h"

using namespace cocos2d::ui;
using namespace cocostudio;
//cocos2d::Sprite * player;
class ControllerLayer :public cocos2d::Layer
{
public:
	   virtual bool init();
	   CREATE_FUNC(ControllerLayer);
	   //important!!!
    
    
	   void moveright(Ref * ref,Widget::TouchEventType type);
	   void moveleft(Ref * ref,Widget::TouchEventType type);
    void moveup(Ref * ref,Widget::TouchEventType type);
    void movedown(Ref * ref,Widget::TouchEventType type);
    
	   virtual void onExit();
	   virtual void onEnter();
	   void jump(Ref * ref,Widget::TouchEventType type);
	   void attack(Ref * ref,Widget::TouchEventType type);
	   void menucallback(Ref * ref,Widget::TouchEventType type);
	   void updateInfo(float dt);
    // LoadingBar *bloodprogress;
};

#endif /* ControllerLayer_hpp */
