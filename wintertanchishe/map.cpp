#include "map.h"
//初始化生成地图
#include <iostream>
map::map():x_(MAX_SIZE_X),y_(MAX_SIZE_Y)
{
	for (int i = 0; i < y_; i++)
	{
		for (int j = 0; j < x_; j++)
		{
			map_[i][j] = ' ';
		}
	}
	for (int i = 0; i < x_; i++)
	{
		map_[0][i] = '#';
		map_[y_ - 1][i] = '#';
	}
	for (int i = 0; i < y_; i++)
	{
		map_[i][0] = '#';
		map_[i][x_ - 1] = '#';
	}
}
//将地图打印出来
void map::show()
{
	print_snake_to_map();

	/*展示全部*/
	for (int i = 0; i < x_; i++)
	{
		for (int j = 0; j < y_; j++)
		{
			std::cout << map_[i][j] <<' ';
		}
		std::cout << std::endl;
	}
}
void map::snake_move()
{
	
}
void map::print_snake_to_map()
{
	std::pair<int, int> snake_head_pos = e.get_head_pos();
	map_[snake_head_pos.second][snake_head_pos.first] = '@';		//修改地图为蛇头
}
//析构函数
map::~map()
{

}
