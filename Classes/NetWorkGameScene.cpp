//
//  NetWorkGameScene.cpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/18.
//
//

#include "NetWorkGameScene.hpp"
#include "ControllerLayer.hpp"
#include "DiDiSocket.hpp"
#include "JsonData.h"
#include "writer.h"
#include "Global.hpp"
NetWorkGameScene::NetWorkGameScene()
{
    map = NULL;
}
Scene* NetWorkGameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    // 'layer' is an autorelease object
    auto layer = new NetWorkGameScene();
    
    ControllerLayer *controllerLayer=ControllerLayer::create();
    scene->addChild(controllerLayer,2);
    
    // add layer as a child to scene
    scene->addChild(layer);
   
    
    
    return scene;
}
void NetWorkGameScene::updateEvent(float dt)
{

    
}

void NetWorkGameScene::onEnter()
{
    BaseGameScene::onEnter();
    CCLOG("isover");
    if(!global->isOnline){
        DiDiSocket::getInstance()->start();
        global->isOnline = true;
    }
    
    
    JsonData * jsonData = JsonData::create("{}");
    jsonData->addValue("cmd", 0);
    jsonData->addValue("name", global->username.c_str());
    jsonData->addValue("pointx", global->player->getPositionX());
    jsonData->addValue("pointy", global->player->getPositionY());
    DiDiSocket::getInstance()->sendMsg( jsonData->getsJsonStr().c_str());
    __NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(NetWorkGameScene::updatePlayer), "1", NULL);
    __NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(NetWorkGameScene::whosOnLine), "2", NULL);
    __NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(NetWorkGameScene::  newPlayerOnLine), "3",NULL);
    __NotificationCenter::getInstance()->addObserver(this,  callfuncO_selector(NetWorkGameScene::  updatePosition), "4",NULL);
    //__NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(), "5", NULL);
    
    schedule(schedule_selector(NetWorkGameScene::updateEvent), 1);
    schedule(schedule_selector(NetWorkGameScene::updatePlayerPosition), 2);
    
}

void NetWorkGameScene::updateInfo(float dt){
    
}
void NetWorkGameScene::whosOnLine(Ref* pData)
{
    JsonData* jsonData = (JsonData*)pData;
    
    
    int iNum = jsonData->getIntData("num");
    Json::Value players = jsonData->getRoot()["players"];
    for (int i = 0; i < iNum; i++)
    {
        log("player%d name = %s", i, players[i]["name"].asCString());
        float x = players[i]["pointx"].asDouble();
        float y = players[i]["pointy"].asDouble();
        addPlayer(players[i]["name"].asCString(),Vec2(x,y));
    }
}
void NetWorkGameScene::updatePlayer(Ref * pData){
    JsonData* jsonData = (JsonData*)pData;
    
    
    string name =  jsonData->getCStrData("name");
    int state = jsonData->getIntData("state");
    int destination = jsonData->getIntData("destination");
    Vector<Node *> players = playersNode->getChildren();
    for (auto node :players) {
        Player * player = (Player*) node;
        if (name == player->name) {
            switch (destination) {
               
                case 1:
                    player->setNowDestination(Role::right);
                    
                    break;
                case 2:
                    player->setNowDestination(Role::left);
                   
                    
                    
                    break;
                case 3:
                    
                    player->setNowDestination(Role::up);
                   
                    break;
                case 4:
                    
                    player->setNowDestination(Role::down);
                   
                    break;
                    
                default:
                   
                    break;
            }
            
            if (state==1&&player->getNowState()!=walk) {
                player->changeState(walk);
            }else if(state == 0 && player->getNowState()!=idle){
                player->changeState(idle);
            }else if(state == -1 && player->getNowState()!=dead){
                player->changeState(dead);
            }
        }
        
    }

}
void NetWorkGameScene::newPlayerOnLine(Ref* pData)
{
    JsonData* jsonData = (JsonData*)pData;
    
    float x = jsonData->getDoubleData("pointx");
    float y = jsonData->getDoubleData("pointy");
    
    
    addPlayer(jsonData->getCStrData("newPlayerName"),Point(x,y));
}
void NetWorkGameScene::updatePlayerPosition(float dt){
    //向服务器更新自己的当前位置
    JsonData * data = JsonData::create("{}");
    data->addValue("cmd", 2);
    data->addValue("pointx", global->player->getPositionX());
    data->addValue("pointy", global->player->getPositionY());
    DiDiSocket::getInstance()->sendMsg(data->getsJsonStr().c_str());
}

void NetWorkGameScene::addPlayer(const char * name , Point p){
    Player * player = new Player();
    player->name = name;
    player->setPosition(p);
    playersNode->addChild(player);
    //players.pushBack(player);
    
}

void NetWorkGameScene::updatePosition(Ref * pData){
    JsonData* jsonData = (JsonData*)pData;
    
    float x = jsonData->getDoubleData("pointx");
    float y = jsonData->getDoubleData("pointy");
    
    string name = jsonData->getCStrData("name");
    Vector<Node *> players = playersNode->getChildren();
    for (auto node :players) {
        Player * player = (Player*) node;
        if (name == player->name) {
            
            player->setPosition(Vec2(x,y));
        }
    }

}
