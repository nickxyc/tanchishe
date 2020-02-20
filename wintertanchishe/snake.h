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
	void change_pox(int x, int y);
private:
	int x_;											//X轴坐标
	int y_;											//Y轴坐标
};
//蛇头
class snake_head:public snake_node
{
public:
	snake_head(int fo = -1, int x = 0, int y = 0);
	~snake_head();
	void turn_foward(int fo  = -1);
private:
	int foward;
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
private:
	snake_head head;			//头
	snake_node nail[SNAKE_SIZE];//尾巴
	int lenght;						//蛇的长度
	
};




#endif // SNAKE_H_
