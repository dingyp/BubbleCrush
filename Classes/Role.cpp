//
//  Role.cpp
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/3.
//
//

#include "Role.h"
#include "Global.hpp"
void Role::onEnter(){
    Node::onEnter();
    
    if(!texture){
       
        Sprite * spritexture=Sprite::create("lingmeng/meng.png");
        texture=spritexture->getTexture();
      
    //  addChild(spritexture);
        speed=0.2;
        CCLOG("tex");
    }
    speed=2;
    texture->retain();
    
    float width=texture->getContentSize().width;
    float height = texture->getContentSize().height;
    framedown=SpriteFrame::createWithTexture(texture,
                                             Rect(0, 0, width/3, height/4));
    frameup=SpriteFrame::createWithTexture(texture,Rect(0, height/4*3, width/3, height/4) );
    frameleft=SpriteFrame::createWithTexture(texture, Rect(0, height/4*2, width/3, height/4));
    frameright=SpriteFrame::createWithTexture(texture, Rect(0, height/4, width/3, height/4));
    sprite=Sprite::createWithSpriteFrame(framedown);
    this->setDownwalkAni(global->createAni(texture, 0));
    this->setUpwalkAni(global->createAni(texture, 3));
    this->setLeftwalkAni(global->createAni(texture, 1));
    this->setRightwalkAni(global->createAni(texture, 2));
    sprite->retain();
    addChild(sprite);
    schedule(schedule_selector(Role::updateCollision), 0.02);
    schedule(schedule_selector(Role::updateMove),global->fps);
    _velocity = Vec2(0,0);
   
}
void Role::setViewpointCenter(Point p)
{
    Size size = Director::getInstance()->getWinSize();
    float x = MAX(p.x, size.width / 2);
    float y = MAX(p.y, size.height / 2);
    
    x = MIN(x, (global->map->getMapSize().width*global->map->getTileSize().width) - size.width / 2);
    y = MIN(y, (global->map->getMapSize().height*global->map->getTileSize().height) - size.height / 2);
    Point actualPosition = Point(x, y);
    Point centerOfView = Point(size.width / 2, size.height / 2);
    Point viewPoint =centerOfView - actualPosition;
    
    
    this->getParent()->setPosition(viewPoint);
    
}
void Role::changeState(State s)
{
    this->setNowState(s);
   // this->stopAllActions();
    this->sprite->stopAllActions();
    switch (this->getNowState()) {
        case walk:
            if (isCanWalk()) {
                switch (this->getNowDestination()) {
                    case up:
                        _velocity = Vec2(0, speed);
                        //this->runAction(RepeatForever::create(MoveBy::create(0.1, Vec2(0,speed))));
                        this->sprite->runAction(RepeatForever::create(Animate::create(this->getUpwalkAni())));
                        break;
                    case down:
                        _velocity = Vec2(0,-speed);
                       // this->runAction(RepeatForever::create(MoveBy::create(0.1, Vec2(0,-speed))));
                        this->sprite->runAction(RepeatForever::create(Animate::create(this->getDownwalkAni())));
                        break;
                    case Role::left:
                        _velocity = Vec2(-speed,0);
                        //this->runAction(RepeatForever::create(MoveBy::create(0.1, Vec2(-speed,0))));
                        this->sprite->runAction(RepeatForever::create(Animate::create(this->getLeftwalkAni())));
                        break;
                    case Role::right:
                        _velocity = Vec2(speed,0);
                       // this->runAction(RepeatForever::create(MoveBy::create(0.1, Vec2(speed,0))));
                        this->sprite->runAction(RepeatForever::create(Animate::create(this->getRightwalkAni())));
                        break;
                    default:
                        break;
                }

            }
            
            break;
        case idle:
            _velocity = Vec2(0,0);
            break;
        case dead:
            
            break;
        default:
            break;
    }
    
}
void Role::updateCollision(float dt)
{
    if(!isCanWalk())
    {
        this->changeState(idle);
        
    }
}

void Role::setNowDestination(Destination d){
    if(d!=nowDestination){
        nowDestination=d;
        this->changeState(walk);
    }
}
Role::Destination Role::getNowDestination(){
    return nowDestination;
}
void Role::updateMove(float dt){
    this->setPosition(this->getPosition()+_velocity);
}
bool Role::isCanWalk()
{
    Point playerpoint=this->getPosition();
    experimental:: TMXLayer *collisionLayer=global->map->getLayer("collision");
    Point tilepointplayer=global->tileCoordForPosition(playerpoint);
    int x=playerpoint.x;
    int y=playerpoint.y;
    
    int x1=this->sprite->getContentSize().width/2*0.9;
    int y1=this->sprite->getContentSize().height/2*0.9;
    // CCLOG("%d,%d,%d,%d",x,y,x1,y1);
    Point p1,p2,p3;
    switch (this->getNowDestination()) {
        case Role::up:
            p1=ccp(x-x1,y+y1);
            p2=ccp(x,y+y1);
            p3=ccp(x+x1,y+y1);
            
            break;
        case Role::down:
            p1=ccp(x-x1,y-y1);
            p2=ccp(x,y-y1);
            p3=ccp(x+x1,y-y1);
            break;
        case Role::left:
            p1=ccp(x-x1,y+y1);
            p2=ccp(x-x1,y);
            p3=ccp(x-x1,y-y1);
            break;
        case Role::right:
            p1=ccp(x+x1,y-y1);
            p2=ccp(x+x1,y);
            p3=ccp(x+x1,y+y1);
            break;
        default:
            break;
    }
    Point r1=global->tileCoordForPosition(p1);
    Point r2=global->tileCoordForPosition(p2);
    Point r3=global->tileCoordForPosition(p3);
    int id1=collisionLayer->getTileGIDAt(r1);
    int id2=collisionLayer->getTileGIDAt(r2);
    int id3=collisionLayer->getTileGIDAt(r3);
    //CCLOG("%d,%d,%d",id1,id2,id3);
    Vec2 modp,modp1;
    
    
    
    
    
    if((id1&&id3)||id2)
    {
        //        if (id1) {
        //            modp1 = r1;
        //        }else if(id2){
        //            modp1 = r2;
        //        }else if(id3){
        //            modp1 = r3;
        //        }
        //        modp=positionCoordForTile(modp1);
        //        switch (player->getNowDestination()) {
        //            case Role::right:
        //
        //                player->setPositionX(modp.x-32);
        //                break;
        //            case Role::left:
        //                player->setPositionX(modp.x+32);
        //                break;
        //            case Role::up:
        //                player->setPositionY(modp.y-32);
        //                break;
        //            case Role::down:
        //                player->setPositionY(modp.y+32);
        //                break;
        //            default:
        //                break;
        //        }
        return false;
    }
    return true;
}