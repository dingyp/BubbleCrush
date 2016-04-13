//
//  GuoduScene.hpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/18.
//
//

#ifndef GuoduScene_hpp
#define GuoduScene_hpp

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class GuoduScene: public Layer{
public:
    virtual bool init();
    CREATE_FUNC(GuoduScene);
    static Scene * createScene();
    void loadingTextureCallBack(Texture2D * texture);
    void runScene(float dt);
    void update(float dt );
    float time;
};


#endif /* GuoduScene_hpp */
