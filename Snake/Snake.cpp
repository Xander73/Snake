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
	snake.resize(3); // snake initial size
	for (int i = 0; i < snake.size(); ++i) 
		snake[i].coord.second +=i;
}
//==============================================
void Snake::moving(int key)
{
	/*	up - 72
		down - 80
		left - 75
		right - 77*/

	switch (key) {
		case 72: {
			if (snake[HEAD].coord.second < snake[HEAD + 1].coord.second) {							//if I move up, i can't go to down
				pair<int, int> temp{ snake[HEAD].coord.first, snake[HEAD].coord.second - 1 };
				snake.push_front(temp);
				setPos(snake[snake.size() - 1].coord.first, snake[snake.size() - 1].coord.second); //last element of the snake
				cout << ' ';
				snake.pop_back();
			} else if (snake[HEAD].coord.second > snake[HEAD + 1].coord.second) {					//if I move down, i can't go to up
				pair<int, int> temp{ snake[HEAD].coord.first, snake[HEAD].coord.second + 1 };
				snake.push_front(temp);
				setPos(snake[snake.size() - 1].coord.first, snake[snake.size() - 1].coord.second); //last element of the snake
				cout << ' ';
				snake.pop_back();
			} else if (key==72) {																	//if I move horizontaly, I need to move  
				pair<int, int> temp{ snake[HEAD].coord.first, snake[HEAD].coord.second - 1 };		//according to the pressed key
				snake.push_front(temp);
				setPos(snake[snake.size() - 1].coord.first, snake[snake.size() - 1].coord.second); //last element of the snake
				cout << ' ';																					
				snake.pop_back();
			} else if (key == 80) {																	//if I move horizontaly, I need to move  
				pair<int, int> temp{ snake[HEAD].coord.first, snake[HEAD].coord.second + 1 };		//according to the pressed key
				snake.push_front(temp);
				setPos(snake[snake.size() - 1].coord.first, snake[snake.size() - 1].coord.second); //last element of the snake
				cout << ' ';
				snake.pop_back();
			}
			break;
		}
		case 80: {			
			if (snake[HEAD].coord.second < snake[HEAD + 1].coord.second) {
				pair<int, int> temp{ snake[HEAD].coord.first, snake[HEAD].coord.second - 1 };
				snake.push_front(temp);
				setPos(snake[snake.size() - 1].coord.first, snake[snake.size() - 1].coord.second); //last element of the snake
				cout << ' ';
				snake.pop_back();
			}
			else if(snake[HEAD].coord.second < snake[HEAD + 1].coord.second) {
				pair<int, int> temp{ snake[HEAD].coord.first, snake[HEAD].coord.second + 1 };
				snake.push_front(temp);
				setPos(snake[snake.size() - 1].coord.first, snake[snake.size() - 1].coord.second); //last element of the snake
				cout << ' ';
				snake.pop_back();
			}
			break;
		}
		case 75: {
			pair<int, int> temp{ --snake[HEAD].coord.first, snake[HEAD].coord.second };
			snake.push_front(temp);
			snake.pop_back();
			break;
		}
		case 77: {
			pair<int, int> temp{ snake[HEAD].coord.first, --snake[HEAD].coord.second };
			snake.push_front(temp);
			snake.pop_back();
			break;
		}
	}
		setPos(snake[HEAD].coord.first, snake[HEAD].coord.second);
		cout << 'Ô';		//snake cobras head print
		setPos(snake[HEAD+1].coord.first, snake[HEAD+1].coord.second);
		cout << snake[HEAD+1].body;	
		
}
//==============================================
void makeScreen(Snake snake )
{
	for (int y = MIN_Y; y < MAX_Y; ++y) {        //make a frame of the game place
		for (int x = MIN_X; x < MAX_X; ++x) {
			switch (y) {
				case MIN_Y: case (MAX_Y - 1): {		//first and last row
					setPos(x, y);
					cout << '*';
					if (x == (MAX_X-1)) {
						setPos(MAX_X, y);		// tehnical
						cout << '*';			//moment
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
	for (int i = 0; i < snake.snake.size(); ++i) {   // print the snake to start
		setPos(snake.snake[i].coord.first, snake.snake[i].coord.second);
		if (i == HEAD)
			cout << 'Ô';
		else
			cout << snake.snake[i].body;
	}
}
//==============================================
bool checkCollision(Snake s)
{
	if (s.snake[HEAD].coord.first == (MIN_X+1) || s.snake[HEAD].coord.first == (MAX_X-1 ) ||		//frame 
		s.snake[HEAD].coord.second == (MIN_Y+1 ) || s.snake[HEAD].coord.second == (MAX_Y-1 )) 	//collision
		return false;
	
	for (int i=1; i<s.snake.size(); ++i) 
		if (s.snake[i].coord == s.snake[HEAD].coord)
			return false;
	
	return true;
}
//==============================================