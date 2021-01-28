#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include "map.h"
#include "heroplane.h"
#include "bullet.h"
#include "enemyplane.h"
#include "bomb.h"
#include <QSound>

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = 0);
    ~MainScene();

    //初始化场景
    void initScene();

    //启动游戏
    void playGame();

    //更新位置
    void updatePosition();

    //绘制
    void paintEvent(QPaintEvent *event);

    //监控鼠标事件
    void mouseMoveEvent(QMouseEvent *event);

    //敌机出场
    void enemyToScene();

    //碰撞检测
    void collisionDetechion();

    //

public:

    //敌机数组
    EnemyPlane m_enemys[ENEMY_NUM];

    //爆炸数组
    Bomb m_bombs[BOMB_NUM];

    //敌机出场间隔
    int m_enemy_recoder;

    //创建地图对象
    Map m_map;
    //定时器对象
    QTimer m_Timer;
    //创建飞机的对象
    HeroPlane m_hero;
};

#endif // MAINSCENE_H
