#include "Snake.h"
#include <iostream>
#include <utility>
#include <deque>
#include "windows.h"

using namespace std;

void setPos(SHORT x, SHORT y)   //coordinate of cursor
{
	COORD coord { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//==============================================
void makeNewTail(pair<int, int> p)
{
	Tile(p, 'O');
}
//==============================================
Snake::Snake(Tile hed) {
	snake.resize(3); 
	cout << snake.size() << endl;// snake initial size
	for (int i = 0; i < snake.size(); ++i) {
		snake[i].coord.second +=i;
	}
}
//==============================================
void Snake::move(int key)
{
	/*	up - 72
		down - 80
		left - 75
		right - 77
	*/
	int head = 0;		//head of snake
	switch (key) {
		case 72: {
			pair<int, int> temp{ snake[head].coord.first, snake[head].coord.second-1 };
			snake.push_front(temp);			
			setPos(snake[snake.size() - 1].coord.first, snake[snake.size()-1].coord.second); //last element of the snake
			cout << ' ';
			snake.pop_back();
			break;
		}
		case 80: {
			head = snake.size() - 1;
			pair<int, int> temp{ snake[head].coord.first, ++snake[head].coord.second };
			snake.push_back(temp);
			snake.pop_front();
			break;
		}
		case 75: {
			pair<int, int> temp{ --snake[head].coord.first, snake[head].coord.second };
			snake.push_front(temp);
			snake.pop_back();
			break;
		}
		case 77: {
			pair<int, int> temp{ snake[head].coord.first, --snake[head].coord.second };
			snake.push_front(temp);
			snake.pop_back();
			break;
		}
	}
		setPos(snake[head].coord.first, snake[head].coord.second);
		cout << snake[head].body;	
		
}
//==============================================
void makeScreen(Snake snake )
{
	for (int y = 0; y < MAX_Y; ++y) {        //make a frame of the game place
		for (int x = 0; x < MAX_X; ++x) {
			switch (y) {
				case 0: case (MAX_Y - 1): {		//first and last row
					setPos(x, y);
					cout << '*';
					if (x == (MAX_X-1)) {
						setPos(MAX_X, y);		// tehnical
						cout << '*';			//moment
						cout << '\n';
					}
					break;
				}
				default: {
					setPos(x, y);
					cout << '*';
					setPos(MAX_X, y);
					cout << '*';
					x = MAX_X;
					break;
				}
			}				
		}
	}
	for (auto a : snake.snake) {   // print the snake to start
		setPos(a.coord.first, a.coord.second);
		cout << a.body;
	}
}
//==============================================