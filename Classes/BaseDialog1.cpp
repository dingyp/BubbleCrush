//
//  BaseDialog1.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/5/4.
//
//

#include "BaseDialog1.h"
#include "VisibleRect.hpp"
#include "UIManager.hpp"
#include <iostream>

bool BaseDialog1::init(){
    if(!Layer::init()){
        return false;
    }
    dialogSize=Size(150,150);
    
    isSetClose = false;
    auto listener = EventListenerTouchOneByOne::create();
    auto callback = [](Touch * ,Event *)
    
    {
        //CCLOG("ss");
        return true;
        
    };
    listener->onTouchBegan = callback;
    
    listener->setSwallowTouches(true);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
    return true;
}
void BaseDialog1::onEnter(){
    Layer::onEnter();
    background = Scale9Sprite::create("images/dialog2.png");//,Rect(0,0,55,65),Rect(30, 30, 1,1))
    
    background->setPreferredSize(dialogSize);
    background->retain();
    closeButton = Button::create("images/close.png");
    addChild(closeButton,1);
    closeButton->setTag(-1);
    this->setAnchorPoint(Vec2(0.5,0.5));
    
    closeButton->setPosition(Vec2(dialogSize.width/2,dialogSize.height/2));
    closeButton->addTouchEventListener(CC_CALLBACK_2(BaseDialog1::closeCallBack, this));
    if (!isSetClose) {
        closeButton->setVisible(false);
    }
    
    this->addChild(background);
   // background->setVisible(false);
    
    //this->runAction(FadeIn::create(0.5));
    
    
    
}
void BaseDialog1::closeCallBack(Ref * ref,Widget::TouchEventType type)
{
    switch (type) {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
            break;
        case cocos2d::ui::Widget::TouchEventType::MOVED:
            break;
        case cocos2d::ui::Widget::TouchEventType::ENDED:
            close();
            break;
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
            break;
    }
    
}
void BaseDialog1::close(){
    this->removeFromParent();
}
void BaseDialog1::setCloseButton(){
    log("1");
    isSetClose=true;
    //  closeButton->addTouchEventListener(CC_CALLBACK_2([](Ref * ref,Widget::TouchEventType type){}, this));
}
void BaseDialog1::setTitile(string str){
    Button * titleButton =Button::create("images/dialog2.png","images/dialog2.png");
    addChild(titleButton,1);
    titleButton->setTitleColor(Color3B::BLACK);
    
    
    titleButton->setTitleText(str);
    
    //  button->set
    titleButton->setScale9Enabled(true);
    titleButton->setCapInsets(Rect(15,15,80,80));
    titleButton->setContentSize(Size(80,40));
    titleButton->setPosition(Vec2(0,dialogSize.height/2));
    addChild(titleButton,2);
    
}
void BaseDialog1::setBottomButton(string s,const cocos2d::ui::Button::ccWidgetTouchCallback& callback,Size size){
    Button * button = UIManager::instance()->createButton(s,size);
    button->setPosition(Vec2(0,-dialogSize.height/4));
    addChild(button,2);
    button->addTouchEventListener(callback);
    
    
}