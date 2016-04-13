//
//  UIManager.hpp
//  benpaobabaozi
//
//  Created by 丁逸鹏 on 15/8/20.
//
//

#ifndef UIManager_cpp
#define UIManager_cpp

#include <stdio.h>
#include "SingleTon.hpp"
#include "cocos2d.h"
#include "cocostudio/Cocostudio.h"
#include "cocos-ext.h"

using namespace cocos2d::ui;
using namespace cocos2d;
class UIManager : public Singleton<UIManager>{
public:
    UIManager();
    ~UIManager();
    Button * createButton(string,Size size = Size(60,40));
    Button * createNoBackGroundButton(string,Size size = Size(60,40));

    
};

#endif /* UIManager_cpp */
