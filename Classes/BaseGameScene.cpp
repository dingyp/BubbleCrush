//
//  BaseGameScene.cpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/18.
//
//

#include "BaseGameScene.hpp"
void BaseGameScene::onEnter()
{
    Layer::onEnter();
   
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    if(NULL==map){
        map=experimental::TMXTiledMap::create("map/map1.tmx");
    }
    //map->setScale(2);
    addChild(map);
    playersNode = Node::create();
    addChild(playersNode);

    TMXObjectGroup *objects = map->getObjectGroup("player");
    CCASSERT(NULL != objects, "'Objects' object group not found");
    auto spawnPoint = objects->getObject("playerinit");
    CCASSERT(!spawnPoint.empty(), "SpawnPoint object not found");
    int x = spawnPoint["x"].asInt();
    int y = spawnPoint["y"].asInt();
    Hero * player = new Hero();
    global->player=player;
    global->map=map;
    player->setPosition(Vec2(x,y));
    addChild(player,2);
    //player->sprite->runAction(RepeatForever::create(Animate::create(global->createAni(player->texture, 3))));
    TMXObjectGroup *object2=map->getObjectGroup("Event");
    auto transitionpoint=object2->getObject("transitionEvent");
    int x1=transitionpoint["x"].asInt();
    int y1=transitionpoint["y"].asInt();
    transitionPosition=Vec2(x1,y1);
    CCLOG("transition: %d,%d",x1,y1);
   // this->runAction(CCFollow::create(player,CCRectMake(0,0,map->getContentSize().width,map->getContentSize().height)));
    
    
   //
}