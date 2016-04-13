//
//  Global.cpp
//  bubblecrush
//
//  Created by 丁逸鹏 on 15/10/15.
//
//

#include "Global.hpp"
#include "DiDiSocket.hpp"
DECLARE_SINGLETON_MEMBER(Global);
Global::Global(void)
{
    fps = 0.01;
    username = UserDefault::getInstance()->getStringForKey("username", "didi");
}
Global::~Global(void)
{
    
}
bool Global::sendToServer(string str){
    if (global->isOnline) {
        DiDiSocket::getInstance()->sendMsg(str.c_str());
        return true;
    }
    return false;
}
Animation *Global::createAni(Texture2D * texture, int row, int col , int frames)
{
    Animation * animation = Animation::create();
    float width=texture->getContentSize().width;
    float height = texture->getContentSize().height;
    
    for(int i=0;i<frames;i++)
    {
        animation->addSpriteFrameWithTexture(texture, Rect(i*width/col, 0, width/col, height));
    }
    animation->setDelayPerUnit(0.1);
    
    
    return animation;
}
void Global::createRandPosition(Vec2 * a,int n,TMXTiledMap *map)
{
    //  int tmp=rand()%(max-min)+min;
    int rows=map->getTileSize().height;
    int cols=map->getTileSize().width;
    for(int i=0;i<n;i++)
    {
        
        
        while (true)
        {
            bool isRepeat=false;
            int x=rand()%rows;
            int y=rand()%cols;
            a[i]=Vec2(x,y);
            for(int j=0;j<i;j++)
            {
                if(a[i].x==a[j].x&&a[i].y==a[j].y)
                {
                    isRepeat=true;
                }
            }
            if(!isRepeat)
            {
                break;
            }
        }
    }
}

Animation * Global::createAni(Texture2D * texture,int index)
{
    Animation * animation = Animation::create();
    float width=texture->getContentSize().width;
    float height = texture->getContentSize().height;
    
    for(int i=0;i<3;i++)
    {
        animation->addSpriteFrameWithTexture(texture, Rect(i*width/3, height*index/4, width/3, height/4));
    }
    animation->setDelayPerUnit(0.1);
    animation->retain();
    return animation;
}
Point Global::tileCoordForPosition(Point p)
{
    Size mapTileNum=map->getMapSize();
    Size tileSize=map->getTileSize();
    int x=p.x/tileSize.width;
    int y=(map->getContentSize().height-p.y)/tileSize.height;
    return Point(x,y);
}
Point Global::positionCoordForTile(Point pos)
{
//    int posxstart=map->getPositionX()-map->getContentSize().width/2/2;
//    int posystart=map->getPositionY()-map->getContentSize().height/2/2;
    
//    float posx=(pos.x+0.5)*map->getTileSize().width;
//    float posy=(pos.y+0.5)*map->getTileSize().height;
    float posx= (pos.x+0.5)*map->getTileSize().width;
    float posy=map->getContentSize().height- (pos.y+0.5)*map->getTileSize().height;
    return Point(posx,posy);
}
bool Global::isCanWalk()
{
    Point playerpoint=player->getPosition();
   experimental:: TMXLayer *collisionLayer=map->getLayer("collision");
    Point tilepointplayer=tileCoordForPosition(playerpoint);
    int x=playerpoint.x;
    int y=playerpoint.y;
    
    int x1=player->sprite->getContentSize().width/2;
    int y1=player->sprite->getContentSize().height/2;
    // CCLOG("%d,%d,%d,%d",x,y,x1,y1);
    Point p1,p2,p3;
    switch (player->getNowDestination()) {
        case Role::up:
            p1=ccp(x-x1,y+y1);
            p2=ccp(x,y+y1);
            p3=ccp(x+x1,y+y1);
            
            break;
        case Role::down:
            p1=ccp(x-x1,y-y1);
            p2=ccp(x,y-y1);
            p3=ccp(x+x1,y-y1);
            break;
        case Role::left:
            p1=ccp(x-x1,y+y1);
            p2=ccp(x-x1,y);
            p3=ccp(x-x1,y-y1);
            break;
        case Role::right:
            p1=ccp(x+x1,y-y1);
            p2=ccp(x+x1,y);
            p3=ccp(x+x1,y+y1);
            break;
        default:
            break;
    }
    Point r1=tileCoordForPosition(p1);
    Point r2=tileCoordForPosition(p2);
    Point r3=tileCoordForPosition(p3);
    int id1=collisionLayer->getTileGIDAt(r1);
    int id2=collisionLayer->getTileGIDAt(r2);
    int id3=collisionLayer->getTileGIDAt(r3);
    //CCLOG("%d,%d,%d",id1,id2,id3);
    Vec2 modp,modp1;
    
    
    
    
    
    if((id1&&id3)||id2)
    {
//        if (id1) {
//            modp1 = r1;
//        }else if(id2){
//            modp1 = r2;
//        }else if(id3){
//            modp1 = r3;
//        }
//        modp=positionCoordForTile(modp1);
//        switch (player->getNowDestination()) {
//            case Role::right:
//                
//                player->setPositionX(modp.x-32);
//                break;
//            case Role::left:
//                player->setPositionX(modp.x+32);
//                break;
//            case Role::up:
//                player->setPositionY(modp.y-32);
//                break;
//            case Role::down:
//                player->setPositionY(modp.y+32);
//                break;
//            default:
//                break;
//        }
        return false;
    }
    return true;
}