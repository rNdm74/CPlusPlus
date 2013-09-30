// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
#pragma once

// TODO: reference additional headers your program requires here
//
// Constants
//
#define MAX_DIRECTIONS			5
#define HALF					2
#define WANDER_PROB				25
#define SPEED					5
#define N_COLS					15	// X Tiles
#define N_ROWS					11 	// Y tiles
#define N_TILES					10	// Tiles array size
#define T_SIZE					70	// Tile bitmap size
#define V_COLS					15
#define V_ROWS					11
#define OFFSET					100
#define ALIEN_ONE				2
#define ALIEN_TWO				3
#define ALIEN_THREE				4
#define ALIEN_FOUR				5
#define RED_FLAG				10
#define BLUE_FLAG				11
#define YELLOW_FLAG				12

//
//
//
public enum ESprite
{
	PLAYER = 1,
	ENEMY  = 2,
	FLAG   = 3,
	COIN   = 13
};
//
//
//
public enum EFrame
{
	X = 0,
	Y = 1,
	WIDTH = 2,
	HEIGHT = 3
};
//
//
//
public enum EEnemyType
{
	SNAIL = 0,
	SLIME = 1,
	FLY = 2
};
//
// Bearing
//
public enum EBearing
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3,
	STAND = 4
};
//
// BoundsAction
//
public enum EBoundsAction
{
	BOUNCE,
	WRAP,
	DIE,
	STOP, 
	WALK
};
//
//
//
public enum ETileType
{
	SOLID = 0,
	LADDER = 1,
	WALKABLE = 2,
	EXIT = 3
};
