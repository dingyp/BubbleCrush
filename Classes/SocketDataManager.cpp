//
//  SocketDataManager.cpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/15.
//
//
#include "JsonData.h"
#include "SocketDataManager.hpp"
SocketDataManager* SocketDataManager::m_socketDatManager=NULL;
SocketDataManager::SocketDataManager(){
    
}
SocketDataManager::~SocketDataManager(){
    
}
SocketDataManager* SocketDataManager::getInstance(){
    if (m_socketDatManager==NULL) {
        m_socketDatManager = SocketDataManager::create();
        
        m_socketDatManager->retain();
    }
    
    return m_socketDatManager;
}
bool SocketDataManager::init(){
     Director::getInstance()->getScheduler()->schedule(schedule_selector(SocketDataManager::update),this,0.1,false);
    return true;
}
void SocketDataManager::update(float dt){
    m_mutex.lock();
    
    for (auto value : m_msgList) {
        log("recv : %s",value.asString().c_str());
        JsonData* jsonData = JsonData::create(value.asString().c_str());
        if (jsonData->isHasKey("cmd")) {
             __NotificationCenter::getInstance()->postNotification(StringUtils::toString(jsonData->getIntData("cmd")), jsonData);
        }
       
    }
    
    m_msgList.clear();
    
    m_mutex.unlock();
}

void SocketDataManager::pushMsg(const char * msg){
    m_mutex.lock();
    
    m_msgList.push_back(Value(msg));
    
    m_mutex.unlock();
}