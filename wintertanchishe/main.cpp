#include <iostream>
#include "map.h"
#include <Windows.h>
int main()
{
	map * m1 = new map;
	while(1)
	{
		m1->start();
	if (m1->endgame() == true)
	{
		std::cout << "game over !" << std::endl;
		delete m1;
		return 0;
	}
	Sleep(100);
	system("cls");
	}
}