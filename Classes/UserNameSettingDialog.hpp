//
//  UserNameSettingDialog.hpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/24.
//
//

#ifndef UserNameSettingDialog_hpp
#define UserNameSettingDialog_hpp

#include <stdio.h>
#include "UIManager.hpp"
#include "BaseDialog1.h"
class UserNameSettingDialog : public BaseDialog1,public EditBoxDelegate{
public:

    
    virtual bool init();
    CREATE_FUNC(UserNameSettingDialog);
    EditBox * editbox;
    
    //输入伪托
    // This method is called when an edit box gains focus after keyboard is shown.
    void editBoxEditingDidBegin(EditBox* editBox);
    
    // This method is called when an edit box loses focus after keyboard is hidden.
    void editBoxEditingDidEnd(EditBox* editBox);
    
    // This method is called when the edit box text was changed.
    void editBoxTextChanged(EditBox* editBox, const std::string& text);
    
    // This method is called when the return button was pressed or the outside area of keyboard was touched.
    void editBoxReturn(EditBox* editBox);
    
};
#endif /* UserNameSettingDialog_hpp */
