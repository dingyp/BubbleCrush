//
//  JoyStick.cpp
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/21.
//
//

#include "JoyStick.h"
#include "JsonData.h"
bool Joystick::init()
{
    bool ret = false;
    
    nowstate = 0 ;
    nowdestination = 2;
    do {
        CC_BREAK_IF( !Sprite::init() );
        m_pJoystickBg = Sprite::create("transparentLight.png");//背景
        m_pJoystick = Sprite::create("transparentLight2.png");//摇杆
        this->addChild(m_pJoystickBg, 0);
        this->addChild(m_pJoystick, 1);
        this->hideJoystick();
        //this->showJoystick();
        m_pJoystickR= m_pJoystickBg->getContentSize().width/2;
        m_pJoystickr= m_pJoystick->getContentSize().width/2;
        //新的API注册这么写
        auto listener = EventListenerTouchAllAtOnce::create();
        listener->onTouchesBegan = CC_CALLBACK_2(Joystick::onTouchesBegan, this);
        listener->onTouchesMoved = CC_CALLBACK_2(Joystick::onTouchesMoved, this);
        listener->onTouchesEnded = CC_CALLBACK_2(Joystick::onTouchesEnded, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
        ret = true;
    } while(0);
    return ret;
}
void Joystick::showJoystick()
{
    //显示摇杆
    m_pJoystick->setVisible(true);
    m_pJoystickBg->setVisible(true);
}
void Joystick::hideJoystick()
{
    //隐藏摇杆
    //m_pJoystick->setPosition(m_pJoystickBg->getPosition());
    m_pJoystick->setVisible(false);
    //m_pJoystickBg->setVisible(false);
    m_pJoystickBg->setVisible(true);
}
void Joystick::onTouchesBegan(const vector<Touch*>& touches, Event *unused_event)
{
    //按下事件处理
    std::vector<Touch*>::const_iterator touchIter = touches.begin();
    Touch* touch = (Touch*)(*touchIter);
    if(m_pJoystickBg->getBoundingBox().containsPoint(touch->getLocation()))
    {
        this->showJoystick();
        updateJoystick(touch);
        global->player->changeState(walk);
        changetowhat(1, nowdestination);
        return;
    }
}
void Joystick::onTouchesMoved(const vector<Touch*>& touches, Event *unused_event)
{
    //移动时处理
    std::vector<Touch*>::const_iterator touchIter = touches.begin();
    Touch* touch = (Touch*)(*touchIter);
    if(m_pJoystick->isVisible())
    {
        updateJoystick(touch);
        return;
    }
}
void Joystick::onTouchesEnded(const vector<Touch*>& touches, Event *unused_event)
{
    //离开是处理
    //m_pJoystick->runAction(MoveTo::create(0.08f,start));
    //m_pJoystick->setPosition(start);
    //global->hero->onStop();
    global->player->changeState(idle);
    changetowhat(0,nowdestination);
    this->hideJoystick();
}
void Joystick::setJoystick(Vec2 point)
{
    //将这个摇杆的放在某个坐标上
    start =point;
    m_pJoystickBg->setPosition(start);
    m_pJoystick->setPosition(m_pJoystickBg->getPosition());
}
void Joystick::updateJoystick(Touch* touch)
{
    //更新摇杆状态
    //我用向量来判断
    Vec2 hit = touch->getLocation();
    float distance = start.getDistance(hit);
    Vec2 direction = (hit - start).getNormalized();
    //为了防止摇杆移出摇杆背景
    if(distance < m_pJoystickr/2)
    {
        m_pJoystick->setPosition(start + (direction * distance));
    }else if(distance >m_pJoystickr) {
        m_pJoystick->setPosition(start + (direction * m_pJoystickr));
    }else {
        m_pJoystick->setPosition(start + (direction * m_pJoystickr/2));
    }
    if(direction.x<=0.7&&direction.x>=-0.7){
        if(direction.y>=0.7){
             global->player->setNowDestination(Role::up);
            changetowhat(1,3);
            
        }else if(direction.y<=-0.7){
             global->player->setNowDestination(Role::down);
            changetowhat(1,4);
        }
        
    }
    
    if(direction.y>-0.7&&direction.y<0.45){
        if(direction.x<-0.7){
            global->player->setNowDestination(Role::left);
            changetowhat(1,2);
        }
        else if(direction.x>0.7){
         
            global->player->setNowDestination(Role::right);
            
            changetowhat(1,1);
            
        }
    }
    
    //CCLOG("%f,%f",direction.x,direction.y);
  //  global->player->setNowDestination(Role::down);
  //  global->player->changeState(walk);
    //global->hero->onMove(direction,distance);
}
void Joystick::changetowhat(int state,int destination){
    if (nowstate!=state||destination!=nowdestination) {
        nowstate = state;
        nowdestination = destination;
        JsonData * data;
        data = JsonData::create("{}");
        data->addValue("cmd", 1);
        data->addValue("state", state);
    data->addValue("destination", destination);
        global->sendToServer(data->getsJsonStr());
    }
    
}