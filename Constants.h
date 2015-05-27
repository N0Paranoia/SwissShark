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
const int TOTAL_TILE_SPRITES = 15;

const int TILE_CLEAR = 00;
const int TILE_SKY = 01;
const int TILE_WALL = 02;
const int TILE_WOOD = 03;
const int TILE_DOOR = 04;
const int TILE_LAVA = 05;
const int TILE_GRASS = 06;
const int TILE_WATER = 07;
const int TILE_PLATFORM = 10;
const int TILE_LADDER = 11;
const int TILE_LADDER_TOP = 12;
const int TILE_SLOPE_RIGHT = 13;
const int TILE_SLOPE_LEFT = 14;

const int TOTAL_DOORS = 2;

const int GRAVITY = 4;


#endif // CONSTANTS_H_INCLUDED
