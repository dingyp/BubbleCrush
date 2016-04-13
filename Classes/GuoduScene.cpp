//
//  GuoduScene.cpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/18.
//
//

#include "GuoduScene.hpp"

#include "IncludeScene.hpp"
#include "VisibleRect.hpp"
#include "Global.hpp"
Scene* GuoduScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GuoduScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}
bool GuoduScene::init(){
    if (!Layer::init()) {
        return false;
    }
    
    time = 0;
    scheduleUpdate();
    Label * label = Label::create();
    label->setPosition(VisibleRect::center());
    label->setTextColor(Color4B::WHITE);
    label->setString("资源加载中。。。");
    addChild(label);
    
    //    Director::getInstance()->getTextureCache()->addImageAsync("images/item2.png", CC_CALLBACK_1(StartScene::loadingTextureCallBack,this));
    return true;
}

void GuoduScene::runScene(float dt){
    switch (global->scene_index) {
        case SceneManager::startstage:
            Director::getInstance()->replaceScene(TransitionFade::create(0.5, HelloWorld::createScene()));
            break;
        case SceneManager::stage1:
            
            Director::getInstance()->replaceScene(TransitionFade::create(0.5, MyGameScene::createScene()));
            break;
        case SceneManager::netscene:
            Director::getInstance()->replaceScene(TransitionFade::create(0.5, NetWorkGameScene::createScene()));
            break;
        default:
            Director::getInstance()->replaceScene(TransitionFade::create(0.5, MyGameScene::createScene()));
            
            break;
    }
    this->unscheduleAllCallbacks();
}
void GuoduScene::update(float dt){
    time += dt;
    if (time>0.2) {
        scheduleOnce(schedule_selector(GuoduScene::runScene), 0.5);
        unscheduleUpdate();
    }
    
}