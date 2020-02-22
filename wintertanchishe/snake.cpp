#include "snake.h"

snake_node::snake_node(int x,int y):x_(x),y_(y)
{

}

snake_node::~snake_node()
{

}
//获取X轴返回
int snake_node::get_PosX() const
{
	return x_;
}
//获取Y轴返回
int snake_node::get_PosY() const
{
	return y_;
}
//蛇的构造函数
snake::snake() :lenght(3)
{
	head.change_pox(6, 6);
	nail[0].change_pox(6, 7);
	nail[1].change_pox(6, 8);
}
//析构
snake::~snake()
{

}
std::pair<int, int> snake::get_head_pos() const
{
	std::pair<int, int> temp;
	temp.first = head.get_PosX();
	temp.second = head.get_PosY();
	return temp;
}
std::pair<int, int> snake::get_nail_pos(int x) const
{
	std::pair<int, int> temp;
	temp.first = nail[x].get_PosX();
	temp.second = nail[x].get_PosY();
	return temp;
}
//该函数通过外部调用使蛇能够移动
void snake::move()
{
	snake_move_by_fo();
}
void snake::snake_move_by_fo()
{
	int move_x = 0;
	int move_y = 0;
	int temp_x_p = 0;
	int temp_y_p = 0;
	int temp_x_s = 0;
	int temp_y_s = 0;
	switch (head.get_foward())
	{
	case snake_head::UP:
		move_x = 0;
		move_y = -1;
		break;
	case snake_head::DOWN:
		move_x = 0;
		move_y = 1;
		break;
	case snake_head::LEFT:
		move_x = -1;
		move_y = 0;
		break;
	case snake_head::RIGHT:
		move_x = 1;
		move_y = 0;
		break;
	default:
		break;
	}
	/*等待编辑从后方到前方改变蛇的坐标，最后改变蛇头*/// 2020 2 22 6:54pm
	temp_x_p = head.get_PosX();
	temp_y_p = head.get_PosY();
	head.change_pox(head.get_PosX() + move_x, head.get_PosY() + move_y);

	for (int i = 0; i < lenght -1; i++)
	{
		temp_x_s = nail[i].get_PosX();
		temp_y_s = nail[i].get_PosY();
		nail[i].change_pox(temp_x_p, temp_y_p);
		temp_x_p = temp_x_s;
		temp_y_p = temp_x_s;
	}

}
//蛇头构造函数，将x，y参数传给父类node，fo传给foward变量
snake_head::snake_head(short fo,int x,int y):snake_node(x,y),foward(fo)
{

}
//头的析构
snake_head::~snake_head()
{

}
//蛇头转向函数
void snake_head::turn_foward(short fo)
{
	foward = fo;
}
short snake_head::get_foward()const
{
	return foward;
}

void snake_node::change_pox(int x, int y)
{
	x_ = x;
	y_ = y;
}
