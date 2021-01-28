#include "mainscene.h"
#include "config.h"
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
#include <ctime>
MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    initScene();
}

MainScene::~MainScene()
{

}

void MainScene::initScene()
{
    //初始化窗口大小
    setFixedSize(GAME_WIDTH,GAME_HIGHT);
    //窗口标题
    setWindowTitle(GAME_TITLE);
    //设置窗口标题
    setWindowIcon(QIcon(GAEM_ICON));
    //播放背景音乐
    QSound::play(SOUND_BACKGROUND);
    //设置时间间隔
    m_Timer.setInterval(GAME_RATE);

    playGame();

    //设置敌机出场间隔
    m_enemy_recoder = 0;

    //随机种子
    srand((unsigned int)time(NULL));

}

void MainScene::playGame()
{
    //启动定时器
    m_Timer.start();

    //监听定时器的信号
    connect(&m_Timer,&QTimer::timeout,[=]()
    {
        //发射敌机
        enemyToScene();
        //更新游戏中所有元素的坐标
        updatePosition();
        //绘制游戏中的元素
        update();//会调用paintEvent函数
        //碰撞检测
        collisionDetechion();
    });
}

void MainScene::updatePosition()
{
    //更新地图坐标
    m_map.mapPosition();


    //发射子弹
    m_hero.shoot();

    //计算子弹的坐标
    for(int i = 0; i < BULLET_NUM; ++i)
    {
        //如果子弹非空闲，计算其位置
        if(m_hero.m_bullets[i].isFree == false)
        {
            m_hero.m_bullets[i].updatePosition();
        }
    }

    //计算敌机的位置
    for(int i = 0; i < ENEMY_NUM; ++i)
    {
        if(m_enemys[i].isFree == false)
        {
            m_enemys[i].updatePosition();
        }
    }

    for(int i = 0; i < BOMB_NUM; ++i)
    {
        if(m_bombs[i].isFree == false)
        {
            m_bombs[i].updateInfo();
        }
    }
}

void MainScene::paintEvent(QPaintEvent *event)
{
    //利用画家画图片
    QPainter painter(this);

    //绘制地图
    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);

    //绘制飞机
    painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.m_Plane);

    //绘制子弹
    for(int i = 0; i < BULLET_NUM; ++i)
    {
        //如果子弹非空闲，计算其位置
        if(m_hero.m_bullets[i].isFree == false)
        {
            painter.drawPixmap(m_hero.m_bullets[i].m_X,m_hero.m_bullets[i].m_Y,m_hero.m_bullets[i].m_Bullet);
        }
    }

    //绘制敌机
    for(int i = 0; i < ENEMY_NUM; ++i)
    {
        if(m_enemys[i].isFree == false)
        {
            painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);
        }
    }

    for(int i = 0; i < BOMB_NUM; ++i)
    {
        if(m_bombs[i].isFree == false)
        {
            painter.drawPixmap(m_bombs[i].m_X,m_bombs[i].m_Y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }

}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x() - m_hero.m_Rect.width() * 0.5;
    int y = event->y() - m_hero.m_Rect.height() * 0.5;

    //边际检测，不让飞机飞出边框
    if(x <= 0)
    {
        x = 0;
    }
    if(x >= GAME_WIDTH - m_hero.m_Rect.width())
    {
        x = GAME_WIDTH - m_hero.m_Rect.width();
    }
    if(y <= 0)
    {
        y = 0;
    }
    if(y >= GAME_HIGHT - m_hero.m_Rect.height())
    {
        y = GAME_HIGHT - m_hero.m_Rect.height();
    }

    m_hero.setPosition(x,y);
}

void MainScene::enemyToScene()
{
    ++ m_enemy_recoder;

    if(m_enemy_recoder < ENEMY_INTERVAL)
    {
        return;
    }

    for(int i = 0; i < ENEMY_NUM; ++i)
    {
        if(m_enemys[i].isFree == true)
        {
            //发射敌机
            m_enemys[i].isFree = false;

            //设置敌机的位置
            m_enemys[i].m_X = rand() % (GAME_WIDTH - m_enemys[i].enemy_Rect.width());
            m_enemys[i].m_Y = 0;
            m_enemy_recoder = 0;
            return;
        }
    }
}

void MainScene::collisionDetechion()
{
    for(int i = 0; i < ENEMY_NUM; ++i)
    {
        if(m_enemys[i].isFree == true)
        {
            continue;
        }

        for(int j = 0; j < BULLET_NUM; ++j)
        {
            if(m_hero.m_bullets[j].isFree == true)
            {
                continue;
            }

            if(m_enemys[i].enemy_Rect.intersects(m_hero.m_bullets[j].m_bullet_Rect) == true)
            {
                m_enemys[i].isFree = true;
                m_hero.m_bullets[j].isFree = true;

                QSound::play(SOUND_BOMB);

                //调用爆炸的特效
                for(int k = 0; k < BOMB_NUM; ++k)
                {
                    if(m_bombs[k].isFree == true)
                    {
                        //爆炸状态设置为非空闲
                        m_bombs[k].isFree = false;

                        m_bombs[k].m_X = m_enemys[i].m_X + m_enemys[i].m_enemy.width() * 0.5;
                        m_bombs[k].m_Y = m_enemys[i].m_Y + m_enemys[i].m_enemy.height() * 0.5;
                        break;
                    }
                }
            }
        }
    }
}
