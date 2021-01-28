#ifndef BULLET_H
#define BULLET_H
#include <QPixmap>
#include "config.h"

class Bullet
{
public:
    Bullet();
    //更新子弹的坐标
    void updatePosition();
public:

    //子弹的资源对象
    QPixmap m_Bullet;

    //子弹的位置
    int m_X = 0;
    int m_Y = 0;

    //子弹的移动速度
    int m_speed = 0;

    //子弹是否闲置
    bool isFree;

    //子弹的矩形边宽
    QRect m_bullet_Rect;

};

#endif // BULLET_H
