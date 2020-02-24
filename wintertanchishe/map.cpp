#include "map.h"
//初始化生成地图
#include <iostream>
#include <conio.h>
/*初始化地图类，设置地图大小以及，地图边框和空白区域*/
map::map():x_(MAX_SIZE_X),y_(MAX_SIZE_Y)
{
	e = new snake;
	f = new food;
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
//游戏开始
void map::start()
{
	show();
	snake_control();
	snake_move();
	draw_food();
}
//将地图打印出来
void map::show()const
{
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
	eat_judgement();
	death_jugement();
	release_snake_to_map();
	e->move();
	print_snake_to_map();
}
void map::draw_food()
{
	map_[f->get_PosY()][f->get_PosX()] = '&';
}
void map::print_snake_to_map()
{
	std::pair<int, int> snake_head_pos = e->get_head_pos();
	map_[snake_head_pos.second][snake_head_pos.first] = '@';		//修改地图为蛇头
	/*根据蛇的尾巴长度循环蛇数组得到各节尾巴的位置并将打印在map上*/
	for (int i = 0; i < e->get_snake_size()-1; i++)									
	{
		std::pair<int, int> snake_body_pos = e->get_nail_pos(i);
		map_[snake_body_pos.second][snake_body_pos.first] = '*';
	}
}
void map::release_snake_to_map()
{
	std::pair<int, int> snake_head_pos = e->get_head_pos();
	map_[snake_head_pos.second][snake_head_pos.first] = ' ';		//修改原来蛇头位置为空白
	/*根据蛇的尾巴长度循环蛇数组得到各节尾巴的位置并将打印空白在map上*/
	for (int i = 0; i < e->get_snake_size() - 1; i++)
	{
		std::pair<int, int> snake_body_pos = e->get_nail_pos(i);
		map_[snake_body_pos.second][snake_body_pos.first] = ' ';
	}
}
/*对蛇头下一位置的判断，判断蛇的死亡
蛇头不能碰地图边缘以及撞击自己的尾巴
*/
void map::death_jugement()
{
	short next_x = 0;
	short next_y = 0;
	switch (e->get_head_foward())
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
	if ((map_[e->get_head_pos().first + next_x][e->get_head_pos().second + next_y] == '#') || (map_[e->get_head_pos().first + next_x][e->get_head_pos().second + next_y] == '*'))
	{
		turn_end_game();
	}
}
/*实现吃到食物的判断*/
void map::eat_judgement()
{/*
	short next_x = 0;
	short next_y = 0;
	switch (e->get_head_foward())
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
	*/
	if ((e->get_head_pos().first == f->get_PosX()) && (e->get_head_pos().second == f->get_PosY()))
	{
		e->increase_snake_lenght();
		f->create_food();
	}
}
bool map::endgame()
{
	return ENDGAME;
}
void map::turn_end_game()
{
	ENDGAME = true;
}
//对蛇的方向进行控制
void map::snake_control()
{
	if (_kbhit())
	{
		char ch = _getch();
		std::cout << ch << std::endl;

		switch (ch)
		{
		case 56:
			if (e->get_head_foward() != snake_head::DOWN)
			{
				e->change_head_foward("UP");
			}
			break;
		case 53:
			if (e->get_head_foward() != snake_head::UP)
			{
				e->change_head_foward("DOWN");
			}
			break;
		case 52:
			if (e->get_head_foward() != snake_head::RIGHT)
			{
				e->change_head_foward("LEFT");
			}
			break;
		case 54:
			if (e->get_head_foward() != snake_head::LEFT)
			{
				e->change_head_foward("RIGHT");
			}
			break;
		default:
			break;
		}
	}
}
//析构函数
map::~map()
{
	delete e;
	e = nullptr;
}
