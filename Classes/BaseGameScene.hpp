//
//  BaseGameScene.hpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/18.
//
//

#ifndef BaseGameScene_hpp
#define BaseGameScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Player.h"
#include "Global.hpp"
using namespace cocos2d;
class BaseGameScene : public Layer{
public:
    virtual void onEnter();
    //  ControllerLayer * controllerLayer;
    static Scene * createScene();
    experimental::TMXTiledMap * map;
     Vec2 transitionPosition;
    Node * playersNode;
    Vector<Player*>  players;
};
#endif /* BaseGameScene_hpp */
