//
//  UserNameSettingDialog.cpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/24.
//
//

#include "UserNameSettingDialog.hpp"
#include "Global.hpp"
bool UserNameSettingDialog::init(){
    if (!BaseDialog1::init()) {
        return false;
    }
    dialogSize = Size(350,200);
    
    this->setCloseButton();
    this->setTitile("信息配置");
    
    Label * label = Label::create();
    label->setString("快输入你的名字吧～");
    label->setColor(Color3B::BLACK);
    label->setPosition(Vec2(0,60));
 //   label->setAliasTexParameters();
    addChild(label,2);
    editbox = EditBox::create(Size(128,24), Scale9Sprite::create());

    editbox->setPosition(Vec2(0,20));
    editbox->setText(global->username.c_str());

    editbox->setDelegate(this);//开启委托
    editbox->setMaxLength(10);
    editbox->setFontColor(Color3B::BLACK);//设置文字颜色
    Button * button = UIManager::instance()-> createButton("确定");
    button->setPosition(Vec2(0,-60));
    addChild(button,2);
 //   editbox->setInputMode()
    addChild(editbox,1);
    button->addTouchEventListener([=](Ref * ref,Widget::TouchEventType type){
        switch (type) {
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                
                log("%s",editbox->getText());
                global->username = editbox->getText();
                UserDefault::getInstance()->setStringForKey("username", editbox->getText());
                close();
                break;
                
            default:
                break;
        }
    });
    return true;
}
//输入伪托
// This method is called when an edit box gains focus after keyboard is shown.
void UserNameSettingDialog:: editBoxEditingDidBegin(EditBox* editBox){
    
}

// This method is called when an edit box loses focus after keyboard is hidden.
void UserNameSettingDialog:: editBoxEditingDidEnd(EditBox* editBox){
    
}

// This method is called when the edit box text was changed.
void UserNameSettingDialog:: editBoxTextChanged(EditBox* editBox, const std::string& text){
    
}

// This method is called when the return button was pressed or the outside area of keyboard was touched.
void UserNameSettingDialog:: editBoxReturn(EditBox* editBox){
    
}