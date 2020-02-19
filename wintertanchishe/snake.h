#pragma once
#ifndef SNAKE_H_
#define SNAKE_H_

class snake
{
private:
	
public:

};

class snake_head
{
private:
	const short LEFT = -1;
	const short RIGHT = 1;
	const short TOP = 2;
	const short DOWN = -2;
	int x_, y_;
	int foward;
public:
	snake_head(int pox_x = 6, int pos_y = 6);
	~snake_head();
	int get_PosX()const;
	int get_PosY()const;
	int get_forward()const;
	int move();
	void turn(int turn_foward);
};
#endif // SNAKE_H_
