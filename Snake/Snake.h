#pragma once

#ifndef SNAKE_H
#define SNAKE_H

#include <utility>
#include <deque>
#include <iostream>
#include <random>
#include <ctime>
#include "windows.h"

using namespace std;

//constants
const int MIN_X = 0;
const int MAX_X = 40;

const int MIN_Y = 0;
const int MAX_Y = 29;

const int HEAD = 0;


//==============================================
void setPos(SHORT, SHORT);
//==============================================
pair<int, int> randomCoord();
//==============================================
class Tile
{
public:
	char body;
	pair<int, int> coord;
	Tile(pair<int, int> c = { 20,10 }, char ch = 'O') :coord(c), body(ch) {}
	Tile(int a, int b, char ch = 'O') :coord(a,b), body(ch) {}
};
//==============================================
class Snake
{
public:
	deque<Tile> snk;
	Snake(Tile);
	Tile randomBlock;
	void moving(int);
	void newTile();
};
//==============================================
void makeScreen(Snake&);
//==============================================
bool checkCollision(const Snake&);
//==============================================

#endif
