//
//  DiDiSocket.hpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/13.
//
//


typedef int SOCKET;
#ifndef DiDiSocket_hpp
#define DiDiSocket_hpp

#define MAX_LEN 1024

#include "ODSocket.hpp"
#include "cocos2d.h"
#include <stdio.h>
#include "SingleTon.hpp"
using namespace cocos2d;
class DiDiSocket : public Ref{
public:
    DiDiSocket();
    ~DiDiSocket();
    
    static DiDiSocket * getInstance();
    CREATE_FUNC(DiDiSocket);
    
    virtual bool init();
    
    bool connectSever();
    void start();
    void recvData();
    void sendMsg(const char * msg);
protected:
    static DiDiSocket* m_DiDiSocket;
    
    ODSocket cSocket;
};
#endif /* DiDiSocket_hpp */
