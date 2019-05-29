#include <conio.h>
#include "Snake.h"


using namespace std;

void pushKey(int k, Snake s)
{
	setPos(45, 2);
	char ch = k;
	cout << "Pressed key is - " << k << " : char - " << ch;
	setPos(45, 4);
	cout << "Head:   " << s.snk[HEAD].coord.first << ", " << s.snk[HEAD].coord.second << endl;
	setPos(45, 5);
	cout<<"Head+1: " << s.snk[HEAD+1].coord.first << ", " << s.snk[HEAD+1].coord.second;
}

int game()
{

	pair<int, int> p(20, 10);
	Tile t;
	Snake snake(t);
	makeScreen(snake);
	char key=72;				//move up
	int count = 0;
	while (checkCollision(snake)) {
		Sleep(300);
		if (_kbhit()) {
			key = _getch();
			key = _getch();			//kill double sleep (300)
			pushKey(key, snake);
		}
		snake.moving(key);	//game speed
		if (snake.randomBlock.coord == snake.snk[HEAD].coord) {
			snake.snk.push_back(Tile(snake.snk.back().coord.first - 1, snake.snk.back().coord.second - 1));		//add new part to the snake
			snake.newTile();
		}
	}
	return 1;
}