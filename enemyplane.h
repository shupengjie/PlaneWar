#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include <QPixmap>

class EnemyPlane
{
public:
    EnemyPlane();

    //更新坐标
    void updatePosition();

public:
    //敌机资源文件
    QPixmap m_enemy;

    //位置
    int m_X;
    int m_Y;

    //敌机的矩形边框
    QRect enemy_Rect;

    //敌机的速度
    int m_Speed;

    //是否空闲
    bool isFree;


};

#endif // ENEMYPLANE_H
