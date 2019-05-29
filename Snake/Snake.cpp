#include "Snake.h"
#include <iostream>
#include <utility>
#include <deque>
#include "windows.h"

using namespace std;

//random numbers
default_random_engine randomEngine(time(NULL));
//==============================================
void setPos(SHORT x, SHORT y)   //coordinate of cursor
{
	COORD coord { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//==============================================
pair<int, int> randomCoord()
{
	uniform_int_distribution<int> getNumX(1, 39);
	int X = getNumX(randomEngine);
	uniform_int_distribution<int> getNumY(1, 28);
	int Y = getNumY(randomEngine);
	return pair<int, int> (X, Y);
}
//==============================================
void Snake::newTile()
{
	pair<int, int> temp;
	while (true) {
		 temp=randomCoord();
		for (auto a : snk) {
			if (a.coord == temp) 
				break;
		}
		randomBlock = temp;
		setPos(randomBlock.coord.first, randomBlock.coord.second);
		cout << randomBlock.body;
		return;
	}
	
}
//==============================================
Snake::Snake(Tile hed) {
	snk.resize(3); // snk initial size
	for (int i = 0; i < snk.size(); ++i) 
		snk[i].coord.second +=i;
	newTile();
}
//==============================================
void Snake::moving(int key)
{
	/*	up - 72
		down - 80
		left - 75
		right - 77*/

	switch (key) {
	case 72: case 80: {
		if (snk[HEAD].coord.second < snk[HEAD + 1].coord.second) {							//if I move up, I can't go to down
			pair<int, int> temp{ snk[HEAD].coord.first, snk[HEAD].coord.second - 1 };
			snk.push_front(temp);
			setPos(snk[HEAD].coord.first, snk[HEAD].coord.second);							//HEAD instead front() use for  clarity
			cout << 'Ô';
			setPos(snk[HEAD+1].coord.first, snk[HEAD + 1].coord.second);
			cout << snk[HEAD + 1].body;
			setPos(snk.back().coord.first, snk.back().coord.second);						//last element of the snk				
			cout << ' ';
			snk.pop_back();	
		}
		else if (snk[HEAD].coord.second > snk[HEAD + 1].coord.second) {					//if I move down, I can't go to up
			pair<int, int> temp{ snk[HEAD].coord.first, snk[HEAD].coord.second + 1 };
			snk.push_front(temp);
			setPos(snk[HEAD].coord.first, snk[HEAD].coord.second);							//HEAD instead front() use for  clarity
			cout << 'Ô';
			setPos(snk[HEAD + 1].coord.first, snk[HEAD + 1].coord.second);
			cout << snk[HEAD + 1].body;
			setPos(snk.back().coord.first, snk.back().coord.second);						//last element of the snk				
			cout << ' ';
			snk.pop_back();
		}
		else {
			switch (key) {
			case 72: {																	//if I move horizontaly, I need to move  
				pair<int, int> temp{ snk[HEAD].coord.first, snk[HEAD].coord.second - 1 };
				snk.push_front(temp);
				setPos(snk[HEAD].coord.first, snk[HEAD].coord.second);							//HEAD instead front() use for  clarity
				cout << 'Ô';
				setPos(snk[HEAD + 1].coord.first, snk[HEAD + 1].coord.second);
				cout << snk[HEAD + 1].body;
				setPos(snk.back().coord.first, snk.back().coord.second);						//last element of the snk				
				cout << ' ';
				snk.pop_back();
				break;
			}
			case 80: {																	//if I move horizontaly, I need to move  
				pair<int, int> temp{ snk[HEAD].coord.first, snk[HEAD].coord.second + 1 };
				snk.push_front(temp);
				setPos(snk[HEAD].coord.first, snk[HEAD].coord.second);							//HEAD instead front() use for  clarity
				cout << 'Ô';
				setPos(snk[HEAD + 1].coord.first, snk[HEAD + 1].coord.second);
				cout << snk[HEAD + 1].body;
				setPos(snk.back().coord.first, snk.back().coord.second);						//last element of the snk				
				cout << ' ';
				snk.pop_back();
				break;
			}
			}
		}
		break;
	}
			 //left - 75; right - 77 
	case 75: case 77: {
		if (snk[HEAD].coord.first < snk[HEAD + 1].coord.first) {							 //if I move left, I can't go to right
			pair<int, int> temp{ snk[HEAD].coord.first - 1, snk[HEAD].coord.second };
			snk.push_front(temp);
			setPos(snk[HEAD].coord.first, snk[HEAD].coord.second);
			cout << 'Ô';
			setPos(snk[HEAD+1].coord.first, snk[HEAD+1].coord.second);
			cout << snk[HEAD + 1].body;
			setPos(snk.back().coord.first, snk.back().coord.second);		//last element of the snk
			cout << ' ';
			snk.pop_back();
		}
		else if (snk[HEAD].coord.first > snk[HEAD + 1].coord.first) {					   //if I move right, I can't go to left
			pair<int, int> temp{ snk[HEAD].coord.first + 1, snk[HEAD].coord.second };
			snk.push_front(temp);
			setPos(snk[HEAD].coord.first, snk[HEAD].coord.second);
			cout << 'Ô';
			setPos(snk[HEAD + 1].coord.first, snk[HEAD + 1].coord.second);
			cout << snk[HEAD + 1].body;
			setPos(snk.back().coord.first, snk.back().coord.second);		//last element of the snk
			cout << ' ';
			snk.pop_back();
		}
		else {
			switch (key) {
				case 75: {																	//if I move horizontaly, I need to move  
					pair<int, int> temp { snk[HEAD].coord.first - 1, snk[HEAD].coord.second }; //according to the pressed key
					snk.push_front(temp);
					setPos(snk[HEAD].coord.first, snk[HEAD].coord.second);
					cout << 'Ô';
					setPos(snk[HEAD + 1].coord.first, snk[HEAD + 1].coord.second);
					cout << snk[HEAD + 1].body;
					setPos(snk.back().coord.first, snk.back().coord.second);		//last element of the snk
					cout << ' ';
					snk.pop_back();
					break;
				}
				case 77: {																	//if I move horizontaly, I need to move  
					pair<int, int> temp{ snk[HEAD].coord.first + 1, snk[HEAD].coord.second };
					snk.push_front(temp);
					setPos(snk[HEAD].coord.first, snk[HEAD].coord.second);
					cout << 'Ô';
					setPos(snk[HEAD + 1].coord.first, snk[HEAD + 1].coord.second);
					cout << snk[HEAD + 1].body;
					setPos(snk.back().coord.first, snk.back().coord.second);		//last element of the snk
					cout << ' ';
					snk.pop_back();
					break;
				}
			}
		}
		break;
	}
	}
}
//==============================================
void makeScreen(Snake &snake )
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
	for (int i = 0; i < snake.snk.size(); ++i) {   // print the snk to start
		setPos(snake.snk[i].coord.first, snake.snk[i].coord.second);
		if (i == HEAD)
			cout << 'Ô';
		else
			cout << snake.snk[i].body;
	}
	setPos(snake.randomBlock.coord.first, snake.randomBlock.coord.second);
	cout << snake.randomBlock.body;

}
//==============================================
bool checkCollision(const Snake& s)
{
	if (s.snk[HEAD].coord.first == (MIN_X) || s.snk[HEAD].coord.first == (MAX_X ) ||		//frame 
		s.snk[HEAD].coord.second == (MIN_Y ) || s.snk[HEAD].coord.second == (MAX_Y-1 )) 	//collision
		return false;
	
	for (int i=1; i<s.snk.size(); ++i)					//if i=0, the first iteration loop is true
		if (s.snk[i].coord == s.snk[HEAD].coord)
			return false;
	
	return true;
}
//==============================================