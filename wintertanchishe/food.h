#pragma once
#ifndef FOOD_H_
#define FOOD_H_
#include<cstdlib>
#include <ctime>
#include "global_config.h"
class food
{
public:
	food();
	~food();
	void create_food();
	int get_PosX()const;
	int get_PosY()const;
private:
	int x_, y_;
};

#endif