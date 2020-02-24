#include "food.h"

food::food() :x_(0), y_(0)
{
	create_food();
}
food::~food()
{

}

void food::create_food()
{
	x_ = 0;
	y_ = 0;
	int temp_x;
	int temp_y;
	std::srand(time(0));
	temp_x = rand() % (MAX_SIZE_X)-2 + 1;
	temp_y = rand() % (MAX_SIZE_Y-2) + 1;
	x_ = temp_x;
	y_ = temp_y;

}

int food::get_PosX() const
{
	return x_;
}

int food::get_PosY() const
{
	return y_;
}
