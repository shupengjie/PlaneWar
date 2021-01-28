#ifndef CONFIG_H
#define CONFIG_H



//游戏配置
#define GAME_WIDTH 512
#define GAME_HIGHT 768
#define GAME_TITLE "飞机大战v1.0"
#define GAME_RES_PATH "./plane.rcc"  //二进制资源文件
#define GAEM_ICON ":/ResourceFile/app.ico" //图标路径

//地图配置
#define MAP_PATH  ":/ResourceFile/img_bg_level_1.jpg"  //地图背景图片路径
#define MAP_SCROLL_SPEED 2 //地图滚动速度
#define GAME_RATE 10  //游戏帧率

//飞机配置
#define HERO_PATH ":/ResourceFile/hero2.png"

//子弹的配置
#define BULLET_PATH ":/ResourceFile/bullet_11.png"
#define BULLET_SPEED 5

#define BULLET_NUM 30  //弹夹数量
#define BULLET_INTERVAL 20 //子弹的发射间隔


//敌机配置
#define ENEMY_PATH ":/ResourceFile/img-plane_1.png"
#define ENEMY_SPEED 5
#define ENEMY_NUM 20
#define ENEMY_INTERVAL 60  //敌机出现的时间间隔

//爆炸配置
#define BOMB_PATH ":/ResourceFile/bomb-%1.png"
#define BOMB_NUM 20  //爆炸数量
#define BOMB_MAX 7   //爆炸图片最大索引
#define BOMB_INTERVAL 20 //爆炸切图时间间隔

//音乐
#define SOUND_BACKGROUND ":/ResourceFile/bg.wav"
#define SOUND_BOMB ":/ResourceFile/bomb.wav"


#endif // CONFIG_H
