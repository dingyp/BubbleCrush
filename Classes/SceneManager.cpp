//
//  SceneManager.cpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/18.
//
//

#include "SceneManager.hpp"
#include "Global.hpp"
#include "GuoduScene.hpp"
DECLARE_SINGLETON_MEMBER(SceneManager)
SceneManager::SceneManager(){
    
}
void SceneManager::changeScene(SceneManager::Scenes_Index index){
    global->scene_index = index;
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, GuoduScene::createScene()));
}