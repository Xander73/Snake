#include <conio.h>
#include "Snake.h"


using namespace std;

int game()
{
	pair<int, int> p(20, 10);
	Tile t;
	Snake snake(t);
	makeScreen(snake);

	while (checkCollision(snake)) {
		char key=72;				//move up
		if (_kbhit())
		key = _getch();
		snake.moving(key);
		Sleep(550);				//game speed
	}
	return 1;
}