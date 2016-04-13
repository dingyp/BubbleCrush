//
//  UIManager.cpp
//  benpaobabaozi
//
//  Created by 丁逸鹏 on 15/8/20.
//
//

#include "UIManager.hpp"
DECLARE_SINGLETON_MEMBER(UIManager);

UIManager::UIManager(){
    
}
UIManager::~UIManager(){
    
}
Button* UIManager::createButton(string s, Size size){
    Button * button = Button::create("images/dialog2.png");
    button->setTitleColor(Color3B::BLACK);
    button->setTitleText(s);
 //   button->setTitleFontSize(15);
    button->setTitleFontSize(button->getTitleFontSize());
    //  button->set
    button->setScale9Enabled(true);
    button->setCapInsets(Rect(15,15,80,80));
    button->setContentSize(size);
    return button;
    
}
Button* UIManager::createNoBackGroundButton(string s, Size size){
    Button * button = Button::create();
    button->setTitleColor(Color3B::BLACK);
    button->setTitleText(s);
    button->setTitleFontSize(button->getTitleFontSize()+2);
    //  button->set
    button->setScale9Enabled(true);
    button->setCapInsets(Rect(15,15,200,200));
    button->setContentSize(size);
    return button;
    
}