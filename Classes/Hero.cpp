//
//  Hero.cpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/26.
//
//

#include "Hero.hpp"
#include "Global.hpp"
Hero::Hero(){
    speed=5;
    schedule(schedule_selector(Player::updateViewPoint), global->fps);

}
