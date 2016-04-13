#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Global.hpp"
#include "DiDiSocket.hpp"
#include "SceneManager.hpp"
#include "UserNameSettingDialog.hpp"
#include "VisibleRect.hpp"
USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);
    
//    DiDiSocket::getInstance()->start();
    
 //   Global::instance()->num = 10;
    
   // DiDiSocket::instance()->connectSever("127.0.0.1", 10000);
    
    Button * button = (Button * )rootNode->getChildByName("Button_Start");
    
    button->addTouchEventListener([=](Ref * ref,Widget::TouchEventType type){
        switch (type) {
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                SceneManager::instance()->changeScene(SceneManager::stage1);
                break;
                
            default:
                break;
        }
    });
    
    
    Button * button_pvp = (Button *)rootNode->getChildByName("Button_pvp");
    button_pvp->addTouchEventListener([=](Ref * ref,Widget::TouchEventType type){
        switch (type) {
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                SceneManager::instance()->changeScene(SceneManager::netscene);
                break;
                
            default:
                break;
        }
    });

    log("hello");
    Button * button_setting = (Button * )rootNode->getChildByName("Button_setting");
    button_setting->addTouchEventListener([=](Ref * ref,Widget::TouchEventType type){
        switch (type) {
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                UserNameSettingDialog * dialog ;
                dialog = UserNameSettingDialog::create();
                dialog->setPosition(VisibleRect::center());
                addChild(dialog,1);
                break;
                
            default:
                break;
        }
    });
    


    return true;
}
