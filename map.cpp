#include "map.h"
#include "config.h"
Map::Map()
{
    //初始化加载地图对象
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);

    //设置坐标
    m_map1_posY = -GAME_HIGHT;
    m_map2_posY = 0;

    //滚动速度
    m_scroll_speed = MAP_SCROLL_SPEED;


}

void Map::mapPosition()
{
    //处理第一张图片的滚动
    m_map1_posY += m_scroll_speed;
    if(m_map1_posY >= 0)
    {
        m_map1_posY = -GAME_HIGHT;
    }
    //处理第一张图片的滚动
    m_map2_posY += m_scroll_speed;
    if(m_map2_posY >= GAME_HIGHT)
    {
        m_map2_posY = 0;
    }
}
