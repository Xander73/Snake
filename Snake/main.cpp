#include "Snake.h"
#include <iostream>

using namespace std;

int main()
{	
	pair<int, int> p(20, 10);
	Tile t;
	Snake snake(t);
	makeScreen(snake);
	while (true) {
		snake.move(72);
		Sleep(550);
	}
	
	getchar();
	return 0;
}