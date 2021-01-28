#include "enemyplane.h"
#include "config.h"

EnemyPlane::EnemyPlane()
{
    //敌机资源加载
    m_enemy.load(ENEMY_PATH);

    //敌机位置
    int m_X = 0;
    int m_Y = 0;

    //敌机状态
    isFree = true;

    //敌机速度
    m_Speed = ENEMY_SPEED;

    //敌机的矩形边框
    enemy_Rect.setWidth(m_enemy.width());
    enemy_Rect.setHeight(m_enemy.height());
    enemy_Rect.moveTo(m_X,m_Y);

}

void EnemyPlane::updatePosition()
{
    if(isFree == true)
    {
        return;
    }
    m_Y += ENEMY_SPEED;
    enemy_Rect.moveTo(m_X,m_Y);
    if(m_Y >= GAME_HIGHT)
    {
        isFree = true;
    }
}
