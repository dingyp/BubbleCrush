//
//  DiDiSocket.cpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/13.
//
//

#include "DiDiSocket.hpp"
#include "SocketDataManager.hpp"
DiDiSocket* DiDiSocket::m_DiDiSocket=NULL;
DiDiSocket::DiDiSocket(){
    
}
DiDiSocket::~DiDiSocket(){
    
}
bool DiDiSocket::init(){
    return true;
}

DiDiSocket *DiDiSocket::getInstance(){
    if (m_DiDiSocket == NULL) {
        m_DiDiSocket = DiDiSocket::create();
        m_DiDiSocket->retain();
    }
    return m_DiDiSocket;
}

bool DiDiSocket::connectSever(){
    
    cSocket.Init();
    cSocket.Create(AF_INET, SOCK_STREAM,0);
    
   // const char * ip ="127.0.0.1";
    const char * ip ="192.168.2.1";

    int port = 11000;
    
    bool result = cSocket.Connect(ip,port);
    
    int retrytimes = 0;
    while (result == false&&retrytimes<7) {
        log("retry connecting...");
        result = cSocket.Connect(ip, port);
        retrytimes++;
        
        usleep(500);
    }
    
    if (result) {
        log("connect to server!");
    }else{
        log("cannot connect to server");
    }
    
    return result;
}
void DiDiSocket::start(){
    if (connectSever()==true) {
        std::thread recvthread = std::thread(&DiDiSocket::recvData,this);
        recvthread.detach();
    }
}

void DiDiSocket::recvData(){
    while (true) {
        char recvBuf[MAX_LEN] = "";
       // log("received");

        int iresult = cSocket.Recv(recvBuf, MAX_LEN,0);
        
        if (iresult<=0) {
            break;
        }
        SocketDataManager::getInstance()->pushMsg(recvBuf);
        
        usleep(20);
        
    }
}
void DiDiSocket::sendMsg(const char * msg){
   // int length = strlen(msg);
    string str = msg;
    log("send to server:%s",msg);
    string str2 = str;
  //  sprintf(str,"%s\n",msg);
    
    cSocket.Send(str2.c_str(),strlen(str2.c_str()));
}
