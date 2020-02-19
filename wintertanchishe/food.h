#pragma once
#ifndef FOOD_H_
#define FOOD_H_
#include <random>
class food
{
	int _x, _y;
	food();
	void generate();
	void destory();
	~food();
};
#endif