#include "map.h"
//初始化生成地图
#include <iostream>
/*初始化地图类，设置地图大小以及，地图边框和空白区域*/
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
	release_snake_to_map();
	e.move();
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
	/*根据蛇的尾巴长度循环蛇数组得到各节尾巴的位置并将打印在map上*/
	for (int i = 0; i < e.get_snake_size()-1; i++)									
	{
		std::pair<int, int> snake_body_pos = e.get_nail_pos(i);
		map_[snake_body_pos.second][snake_body_pos.first] = '*';
	}
}
void map::release_snake_to_map()
{
	std::pair<int, int> snake_head_pos = e.get_head_pos();
	map_[snake_head_pos.second][snake_head_pos.first] = ' ';		//修改原来蛇头位置为空白
	/*根据蛇的尾巴长度循环蛇数组得到各节尾巴的位置并将打印空白在map上*/
	for (int i = 0; i < e.get_snake_size() - 1; i++)
	{
		std::pair<int, int> snake_body_pos = e.get_nail_pos(i);
		map_[snake_body_pos.second][snake_body_pos.first] = ' ';
	}
}
//对蛇头下一位置的判断，判断蛇的死亡
short map::death_jugement()
{
	short next_x;
	short next_y;
	switch (e.get_head_foward())
	{
	case snake_head::UP:
		next_x = 0;
		next_y = -1;
		break;
	case snake_head::DOWN:
		next_x = 0;
		next_y = 1;
		break;
	case snake_head::LEFT:
		next_x = -1;
		next_y = 0;
		break;
	case snake_head::RIGHT:
		next_x = 1;
		next_y = 0;
		break;
	default:
		break;
	}
}
//析构函数
map::~map()
{

}
