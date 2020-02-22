#pragma once
#ifndef SNAKE_H_
#define SNAKE_H_
#include "global_config.h"	//导入基本设置
#include <map>
//蛇节点
class snake_node
{
public:
	snake_node(int x = 0,int y = 0);		 //初始化蛇的节点
	~snake_node();								//销毁
	int get_PosX()const;						//获得X轴坐标
	int get_PosY()const;						//获得Y轴坐标
	void change_pox(int x, int y);			//传入参数改变蛇节点位置
private:
	int x_;											//X轴坐标
	int y_;											//Y轴坐标
};
//蛇头
class snake_head:public snake_node
{
public:
	snake_head(short fo = UP, int x = 0, int y = 0);
	~snake_head();
	void turn_foward(short fo  = UP);
	short get_foward()const;
private:
	int foward;
public:
	static const short LEFT = -1;
	static const short RIGHT = 1;
	static const short UP = -2;
	static const short DOWN = 2;
};
//蛇类包括蛇头和身子，合并类
class snake
{
public:
	snake();
	~snake();
	int get_snake_size()const { return lenght; }			//返回蛇的长度;
	std::pair<int, int> get_head_pos()const;		//返回蛇头的位置
	std::pair<int, int> get_nail_pos(int x)const;		//返回第几段蛇尾位置
	void move();													//蛇移动的相关方法
	short get_head_foward()const;						//返回蛇头的方向
private:
	snake_head head;			//头
	snake_node nail[SNAKE_SIZE];//尾巴
	int lenght;						//蛇的长度
	void snake_move_by_fo();		//通过判断蛇的方向来进行蛇的转换
};




#endif // SNAKE_H_
