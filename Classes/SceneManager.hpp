//
//  SceneManager.hpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/18.
//
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <stdio.h>
#include "SingleTon.hpp"

class SceneManager : public Singleton<SceneManager>{
public:
    SceneManager();
    enum Scenes_Index{startstage,stage1,netscene};
    void changeScene(Scenes_Index index);
};

#endif /* SceneManager_hpp */
