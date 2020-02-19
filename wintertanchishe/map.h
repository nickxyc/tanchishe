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
	void show()const;
private:
	int x_, y_;
	char map_[MAX_SIZE_Y][MAX_SIZE_X];
	//snake e;
	//food f;
};
#endif // !

