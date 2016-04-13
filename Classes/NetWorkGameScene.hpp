//
//  NetWorkGameScene.hpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/18.
//
//

#ifndef NetWorkGameScene_hpp
#define NetWorkGameScene_hpp

#include <stdio.h>
#include "BaseGameScene.hpp"

class NetWorkGameScene : public BaseGameScene{
public:
    static cocos2d::Scene* createScene();
    
    NetWorkGameScene();
    void updateEvent(float dt);
    virtual void onEnter();
    
    void updateInfo(float dt);
    
    void addPlayer(const char * name,Point p = Point(100,100));
    void updatePlayerPosition(float dt);
private:
    void updatePlayer(Ref* pData);
    void whosOnLine(Ref* pData);
    void updatePosition(Ref* pData);
    void newPlayerOnLine(Ref* pData);
};
#endif /* NetWorkGameScene_hpp */
