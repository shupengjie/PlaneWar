#include "bullet.h"

Bullet::Bullet()
{
    //加载资源文件
    m_Bullet.load(BULLET_PATH);

    //子弹坐标初始化
    m_X = GAME_WIDTH * 0.5 - m_Bullet.width() * 0.5;
    m_Y = GAME_HIGHT - m_Bullet.height();

    //子弹的状态
    isFree = true;

    //子弹的初速度
    m_speed = BULLET_SPEED;

    //矩形边框的位置
    m_bullet_Rect.setWidth(m_Bullet.width());
    m_bullet_Rect.setHeight(m_Bullet.height());
    m_bullet_Rect.moveTo(m_X,m_Y);
}

void Bullet::updatePosition()
{
    if(isFree == true)
    {
        return;
    }
    m_Y -= m_speed;
    m_bullet_Rect.moveTo(m_X,m_Y);

    if(m_Y < -m_Bullet.height())
    {
        isFree = true;
    }
}
