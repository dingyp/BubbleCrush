//
//  MyGameScene.cpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/18.
//
//

#include "MyGameScene.hpp"

MyGameScene::MyGameScene()
{
    map= experimental::TMXTiledMap::create("map/map1.tmx");
    
    global->isOnline = false;
}
Scene* MyGameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    // 'layer' is an autorelease object
    auto layer = new MyGameScene();
    
    ControllerLayer *controllerLayer=ControllerLayer::create();
    scene->addChild(controllerLayer,2);
    
    // add layer as a child to scene
    scene->addChild(layer);
    // return the scene
    //schedule(schedule_selector(MyGameScene::updateEvent), 0.1);
    
    return scene;
}
void MyGameScene::updateEvent(float dt)
{
   // int x=global->player->getPosition().x;
    
//    if(fabs(transitionPosition.x-global->player->getPosition().x)<15&&
//       fabs(transitionPosition.y-global->player->getPosition().y)<15){
//        CCLOG("x:%f,%f",transitionPosition.x,global->player->getPosition().x);
//        CCLOG("Child Scene");
//        Director::getInstance()->replaceScene(TransitionFade::create(1, GameScene::createScene()));
//        unschedule(schedule_selector(MyGameScene::updateEvent));
//    }
    
}
void MyGameScene::onEnter()
{
    BaseGameScene::onEnter();
    CCLOG("isover");
    Vec2 * positions=new Vec2[10];
 //   global->createRandPosition(positions, 10, map);
    
//    for(int i=0;i<10;i++)
//    {
//        Item * item=new Item();
//        //  CCLOG("坐标：%f,%f",global->tileCoordForPosition( positions[i]).x,global->tileCoordForPosition( positions[i]).y);
//        item->setPosition( global->positionCoordForTile( positions[i]));
//        addChild(item);
//    }
    
    
    
    schedule(schedule_selector(MyGameScene::updateEvent), 1);
    
}


