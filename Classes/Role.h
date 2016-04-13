
//
//  Role.h
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/3.
//
//

#ifndef __RedProject__Role__
#define __RedProject__Role__

#include "cocos2d.h"

using namespace cocos2d;

enum State{idle,walk,dead};
class Role : public Node
{
    
public:
    virtual void onEnter();
    SpriteFrame * frameup;
    SpriteFrame * framedown;
    SpriteFrame * frameleft;
    SpriteFrame * frameright;
  
    enum Destination{up,down,left,right};
    void updateCollision(float dt);
    
    Sprite *sprite;
    Texture2D * texture;
    
    void setViewpointCenter(Point p);
    void changeState(State s);
    void updateMove(float dt);
    
    bool isCanWalk();
    Destination nowDestination;
    void setNowDestination(Destination d);
    Destination getNowDestination();
    CC_SYNTHESIZE(Animation *, leftwalkAni,LeftwalkAni);
    CC_SYNTHESIZE(Animation *, rightwalkAni,RightwalkAni);
    CC_SYNTHESIZE(Animation *, upwalkAni,UpwalkAni);
    CC_SYNTHESIZE(Animation *,downwalkAni,DownwalkAni);
    CC_SYNTHESIZE(State,state,NowState);
    
    Vec2  _velocity;
    float speed;
//    CC_SYNTHESIZE(Destination,destination,NowDestination);
};

#endif /* defined(__RedProject__Role__) */
