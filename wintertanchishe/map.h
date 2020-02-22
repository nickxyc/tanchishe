#pragma once
#ifndef MAP_H_
#define MAP_H_
#include "snake.h"
#include "food.h"
#include "global_config.h"
class map
{public:
	static const DEATH_T DEATH = 0
public:
	map();
	~map();	
	void show();			//在地图上展示物体
	void snake_move();		//获取snake对象中的位置来在地图上绘画
private:
	int x_, y_;
	char map_[MAX_SIZE_Y][MAX_SIZE_X];
	snake e;
	void print_snake_to_map();			//把蛇打印到地图上
	void release_snake_to_map();			//将过去的蛇从地图上删除
	//food f;
	short death_jugement();

};
#endif // !

