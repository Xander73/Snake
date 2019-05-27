#include <conio.h>
#include "Snake.h"


using namespace std;

void pushKey(int k, Snake s)
{
	setPos(45, 2);
	cout << "Pressed key is - " << k;
	setPos(45, 4);
	cout << "Head:   " << s.snk[HEAD].coord.first << ", " << s.snk[HEAD].coord.second << endl;
	setPos(45, 5);
	cout<<"Head+1: " << s.snk[HEAD+1].coord.first << ", " << s.snk[HEAD+1].coord.second;
}

int game()
{
	pair<int, int> p(20, 10);
	Tile t;
	Snake snk(t);
	makeScreen(snk);
	char key=72;				//move up
	int count = 0;
	while (checkCollision(snk)) {						
		if (_kbhit()) {
			key = _getch();
			pushKey(key, snk);
		}
		snk.moving(key);
		Sleep(550);				//game speed
	}
	return 1;
}