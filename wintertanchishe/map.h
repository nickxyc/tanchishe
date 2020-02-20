#pragma once
#ifndef MAP_H_
#define MAP_H_
#include "snake.h"
#include "food.h"
#include "global_config.h"
#include <vector>
#include <algorithm>
class map
{
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
	//food f;
};
#endif // !

