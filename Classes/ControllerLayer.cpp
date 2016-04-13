//
//  ControllerLayer.cpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/18.
//
//


#include "ControllerLayer.hpp"
#include "VisibleRect.hpp"
#include "DiDiSocket.hpp"
#include "JsonData.h"
USING_NS_CC;



bool ControllerLayer::init()
{
    CCLOG("Layer init");
    if ( !Layer::init() )
    {
        return false;
    }
    auto ui=CSLoader::createNode("ControllerLayer2.csb");
    addChild(ui);
    auto m_pjoystick = Joystick::create();
    m_pjoystick->setJoystick(Vec2(80,80));
    //    m_pjoystick->setScale(0.6);
    this->addChild(m_pjoystick,2);
    //    Button * button_Left = static_cast<Button *>(ui->getChildByName("Button_left"));
    //
    //    button_Left->addTouchEventListener(CC_CALLBACK_2(ControllerLayer::moveleft, this));
    //
    //    Button * button_Right = static_cast<Button *>(ui->getChildByName("Button_right"));
    //
    //    button_Right->addTouchEventListener(CC_CALLBACK_2(ControllerLayer::moveright, this));
    //
    //    Button * button_Up = static_cast<Button *>(ui->getChildByName("Button_up"));
    //
    //    button_Up->addTouchEventListener(CC_CALLBACK_2(ControllerLayer::moveup, this));
    //
    //    Button * button_Down = static_cast<Button *>(ui->getChildByName("Button_down"));
    //
    //    button_Down->addTouchEventListener(CC_CALLBACK_2(ControllerLayer::movedown, this));
    
    Button * button_A = static_cast<Button *>(ui->getChildByName("Button_ok"));
    
    button_A->addTouchEventListener(CC_CALLBACK_2(ControllerLayer::attack, this));
    
    Button * button_Pause = Button::create("flatLight/flatLight23.png");
    
    button_Pause->setPosition(VisibleRect::rightTop()-Vec2(62,62));
    
    button_Pause->addTouchEventListener(CC_CALLBACK_2(ControllerLayer::menucallback, this));
    
    button_Pause->setScale(0.5);
    
    
    addChild(button_Pause);
    return true;
}
void ControllerLayer::moveright(Ref *ref,Widget::TouchEventType type)
{
    
    
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            global->player->setNowDestination(Role::right);
            global->player->changeState(walk);
            JsonData * data;
            data = JsonData::create("{}");
            data->addValue("cmd", 1);
            data->addValue("state", 1);
            global->sendToServer(data->getsJsonStr());
            break;
            //	case (int)(cocos2d::ui::Widget::TouchEventType::MOVED):
            
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            global->player->changeState(idle);
            JsonData * data2;
            data2 = JsonData::create("{}");
            data2->addValue("cmd", 1);
            data2->addValue("state",0);
            global->sendToServer(data->getsJsonStr());

            
            break;
        default:
            break;
    }
    
    
}
void ControllerLayer::moveleft(Ref *ref,Widget::TouchEventType type)
{
    auto actionmove=RepeatForever::create(MoveBy::create(0.1,Vec2(-5,0)));
    actionmove->setTag(2);
    
    
    //auto game=GameScene::createScene();
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            global->player->setNowDestination(Role::left);
            global->player->changeState(walk);
            break;
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            global->player->changeState(idle);
            break;
        default:
            break;
    }
}

void ControllerLayer::movedown(Ref *ref, Widget::TouchEventType type)
{
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            global->player->setNowDestination(Role::down);
            global->player->changeState(walk);
            break;
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
             
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            global->player->changeState(idle);
            break;
        default:
            break;
    }
    
}

void ControllerLayer::moveup(Ref * ref, Widget::TouchEventType type)
{
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            global->player->setNowDestination(Role::up);
            global->player->changeState(walk);
            break;
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            global->player->changeState(idle);
            break;
        default:
            break;
    }
    
}
void ControllerLayer::onEnter()
{
    Layer::onEnter();
    schedule(schedule_selector(ControllerLayer::updateInfo));
}

void ControllerLayer::jump(Ref *ref,Widget::TouchEventType type)
{
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            
            break;
            //	case (int)(cocos2d::ui::Widget::TouchEventType::MOVED):
            
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            
            //global->player->changestate(Hero::idel);
            
            break;
        default:
            break;
    }
    //if(global->player->herostate!=Hero::jump){
    
}
void ControllerLayer::menucallback(Ref * ref,Widget::TouchEventType type)
{
    
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            //global->player->changestate(Hero::leftwalk);
            break;
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            Director::sharedDirector()->replaceScene(TransitionFade::create(1.5f,HelloWorld::createScene()));
//            DiDiSocket::getInstance()->e
//            global->isOnline = false;
            break;
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            //global->player->changestate(Hero::idel);
            break;
        default:
            break;
    }
}
void ControllerLayer::updateInfo(float dt)
{
    
    
    
}
void ControllerLayer::onExit()
{
    Layer::onExit();
    unschedule(schedule_selector(ControllerLayer::updateInfo));
    //	 Director::getInstance()->getEventDispatcher()->rem
}
void ControllerLayer::attack(Ref * ref,Widget::TouchEventType type)
{
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            //global->player->bomb();
            //Director::getInstance()->replaceScene(TransitionCrossFade::create(1, GameScene1::createScene()));
            break;
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            if(global->isOnline){
                DiDiSocket::getInstance()->sendMsg("dddd");
            }
            
            break;
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            
            break;
        default:
            break;
    }
    
}