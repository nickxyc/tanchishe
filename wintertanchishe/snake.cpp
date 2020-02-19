#include "snake.h"

snake_head::snake_head(int PosX, int PosY) :x_(PosX), y_(PosY),foward(TOP)
{

}
snake_head::~snake_head()
{

}

int snake_head::get_PosX()const
{
	return X_;
}

int snake_head::get_PosY()const
{
	return y_;
}
int snake_head::get_forward()const
{
	return foward;
}
int snake_head::move()
{
	if (foward == TOP)
	{
		y_--;
	}
	else if(foward == DOWN)
	{
		y_ ++;
	}
	else if (foward == LEFT)
	{
		x_--;
	}
	else if(foward == RIGHT)
	{
		x_++;
	}
}
void snake_head::turn(int turn_foward)
{
	foward = turn_foward;
}
