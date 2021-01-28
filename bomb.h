#ifndef BOMB_H
#define BOMB_H

#include "config.h"
#include <QPixmap>
#include <QVector>
class Bomb
{
public:
    Bomb();

    void updateInfo();

public:

    QVector<QPixmap> m_pixArr;

    //爆炸位置
    int m_X;
    int m_Y;

    //爆炸状态
    bool isFree;

    //爆炸切图的时间间隔
    int m_recoder;

    //爆炸时加载的图片下标
    int m_index;
};

#endif // BOMB_H
