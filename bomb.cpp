#include "bomb.h"

Bomb::Bomb()
{
 for(int i = 1; i <= BOMB_MAX; ++i)
 {
     QString str = QString(BOMB_PATH).arg(i);
     m_pixArr.push_back(QPixmap(str));
 }

 //初始化坐标
 m_X = 0;
 m_Y = 0;

 //初始化空闲状态
 isFree = true;

 //当前播放图片的下标
 m_index = 0;

 //爆炸事件间隔
 m_recoder = 0;

}

void Bomb::updateInfo()
{
    if(isFree == true)
    {
        return;
    }

    m_recoder++;
    if(m_recoder < BOMB_INTERVAL)
    {
        return;
    }
    m_recoder = 0;
    m_index++;

    if(m_index > BOMB_MAX - 1)
    {
        m_index = 0;
        isFree = true;
    }

}
