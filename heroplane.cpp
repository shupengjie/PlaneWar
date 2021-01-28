#include "heroplane.h"
#include "config.h"


HeroPlane::HeroPlane()
{
    //加载飞机的资源
    m_Plane.load(HERO_PATH);

    //初始化坐标
    m_X = GAME_WIDTH * 0.5 - m_Plane.width() * 0.5;
    m_Y = GAME_HIGHT - m_Plane.height() - 20;

    //矩形边框
    m_Rect.setWidth(m_Plane.width());
    m_Rect.setHeight(m_Plane.height());
    m_Rect.moveTo(m_X,m_Y);

    //初始化间隔记录的变量
    m_recorder = 0;

}

void HeroPlane::shoot()
{
    //累加时间间隔记录的变量
    ++m_recorder;

    //
    if(m_recorder < BULLET_INTERVAL)
    {
        return;
    }

    m_recorder = 0;

    //发射子弹
    for(int i = 0; i < BULLET_NUM; ++i)
    {
        if(m_bullets[i].isFree == true)
        {
            m_bullets[i].isFree = false;
            m_bullets[i].m_X = m_X + m_Plane.width() * 0.4;
            m_bullets[i].m_Y = m_Y - 25;
            break;
        }
    }
}

void HeroPlane::setPosition(int x, int y)
{
    this->m_X = x;
    this->m_Y = y;
    m_Rect.moveTo(m_X,m_Y);
}
