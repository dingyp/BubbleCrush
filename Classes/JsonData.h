/*
 Œƒº˛√˚£∫    JsonDataUtil.h
 √Ë°° ˆ£∫	Json ˝æ›
 ¥¥Ω®»À£∫    ±øƒæÕ∑_÷”µœ¡˙ (≤©øÕ£∫http://www.benmutou.com)
 */
#ifndef JsonDataUtil_H
#define JsonDataUtil_H

#include "cocos2d.h"
#include "value.h"
#include "json.h"
USING_NS_CC;

class JsonData : public Ref
{
public:
    JsonData();
    ~JsonData();
    
    static JsonData* create(const char* data);
    bool init(const char* data);
    
    const char* getCStrData(const char* key);
    int getIntData(const char* key);
    float getDoubleData(const char* key);
    bool getBoolData(const char* key);
    bool isHasKey(const char* key);
    /* ÃÌº”◊÷∂ŒµΩJson */
    void addValue(const char* key, int value);
    void addValue(const char* key, const char* value);
    void addValue(const char* key, float value);
    /* ªÒ»°Json∏Ò Ωµƒ◊÷∑˚¥Æ */
    std::string getsJsonStr();
    Json::Value getRoot();
private:
    Json::Value root;
};

#endif