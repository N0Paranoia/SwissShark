#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

const int FPS = 60;
const int TICK_PER_FRAME = 1000 / FPS;

const int WINDOW_WIDTH = 1056;
const int WINDOW_HEIGHT = 576;

const int TILE_SIZE = 48;

const int LEVEL_WIDTH = 44;
const int LEVEL_HEIGHT = 12;

//Set Tile Types
const int TOTAL_TILES = LEVEL_WIDTH*LEVEL_HEIGHT;
const int TOTAL_TILE_SPRITES = 16;

const int TILE_CLEAR = 0;
const int TILE_LEFT_TOP = 1;
const int TILE_MIDDLE_TOP = 2;
const int TILE_RIGHT_TOP = 3;
const int TILE_INNER_RIGHT_BOTTOM = 4;
const int TILE_INNER_LEFT_BOTTOM = 5;
const int TILE_LEFT_MIDDLE = 6;
const int TILE_MIDDLE_MIDDLE = 7;
const int TILE_RIGHT_MIDDLE = 8;
const int TILE_INNER_RIGHT_TOP = 9;
const int TILE_INNER_LEFT_TOP = 10;
const int TILE_LEFT_BOTTOM = 11;
const int TILE_MIDDLE_BOTTOM = 12;
const int TILE_RIGHT_BOTTOM = 13;

const int TOTAL_DOORS = 2;

const int GRAVITY = 4;

//A circle stucture
struct Circle
{
	int x, y;
	int r;
};

#endif // CONSTANTS_H_INCLUDED
