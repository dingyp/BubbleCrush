//
//  Global.hpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/15.
//
//

#ifndef Global_hpp
#define Global_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SingleTon.hpp"
#include "Hero.hpp"
#include "SceneManager.hpp"
using namespace cocos2d;

class Global:public Singleton<Global>
{
public:
    Global(void);
    ~Global(void);
    
    float fps;
    
    bool isOnline;
    void createRandPosition(Vec2 * a,int n,TMXTiledMap * map);
    Hero * player;
    experimental::TMXTiledMap *map;
    bool isTransition;
    Point  tileCoordForPosition(Point pos);//用于游戏坐标换算到地图坐标
    Point  positionCoordForTile(Point pos);//用于地图坐标换算到游戏坐标
    bool isCanWalk();
    SceneManager::Scenes_Index scene_index;
    bool sendToServer(string str);
    string username;
    
    Animation * createAni(Texture2D * texture,int row,int col,int frames);
    Animation * createAni(Texture2D * texture,int index);
};
#define global Global::instance()


#endif /* Global_hpp */
