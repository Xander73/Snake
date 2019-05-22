#pragma once

#ifndef SNAKE_H
#define SNAKE_H

#include <utility>
#include <deque>
#include "windows.h"

using namespace std;

const int MAX_X = 40;
const int MAX_Y = 29;

//==============================================
void setPos(SHORT, SHORT);
//==============================================
class Tile
{
public:
	char body;
	pair<int, int> coord;
	Tile(pair<int, int> c = { 20,10 }, char ch = 'O') :coord(c), body(ch) {}
};
//==============================================
Tile makeNewTile(pair<int,int>);
//==============================================
class Snake
{
public:
	deque<Tile> snake;
	Snake(Tile);
	void move(int);
};

//==============================================
void makeScreen(Snake);
//==============================================
void speedOfTheGame(int);
//==============================================


#endif
