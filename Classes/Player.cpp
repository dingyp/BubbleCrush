//
//  Player.cpp
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/9.
//
//

#include "Player.h"
#include "Global.hpp"
bool Player::init()
{
    if(!Node::init())
    {
        return false;
    }
          return true;
}
Player::Player()
{
    Sprite * spritexture=Sprite::create("lingmeng/meng.png");
   // spritexture->retain();
    texture=spritexture->getTexture();
    CCLOG("init Player");

    //  addChild(spritexture);
        
}
void Player::updateViewPoint(float dt){
    this->setViewpointCenter(this->getPosition());
}

void Player::bomb()
{
    //Bomber * bomber=new Bomber();
//    this->getParent()->addChild(bomber);
//    bomber->setPosition(this->getPosition());
}