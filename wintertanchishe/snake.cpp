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
snake::snake()
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
//蛇头构造函数，将x，y参数传给父类node，fo传给foward变量
snake_head::snake_head(int fo,int x,int y):snake_node(x,y),foward(fo)
{

}
//头的析构
snake_head::~snake_head()
{

}
//蛇头转向函数
void snake_head::turn_foward(int fo)
{
	
}
void snake_node::change_pox(int x, int y)
{
	x_ = x;
	y_ = y;
}
