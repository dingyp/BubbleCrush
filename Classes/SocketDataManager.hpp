//
//  SocketDataManager.hpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/15.
//
//

#ifndef SocketDataManager_hpp
#define SocketDataManager_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SingleTon.hpp"
using namespace::cocos2d;

class SocketDataManager: public Ref{
public:
    
    SocketDataManager();
    ~SocketDataManager();
    static SocketDataManager* getInstance();
    CREATE_FUNC(SocketDataManager);
    
    virtual bool init();
    void pushMsg(const char * msg);
    void update(float);
protected:
    static SocketDataManager * m_socketDatManager;
    std::mutex m_mutex;
    ValueVector m_msgList;//存放数据
};

#endif /* SocketDataManager_hpp */
