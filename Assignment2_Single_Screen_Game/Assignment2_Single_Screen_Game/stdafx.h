// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
#pragma once

// TODO: reference additional headers your program requires here
//
// Constants
//
#define PLAYER_X_MAG			8
#define PLAYER_Y_MAG			10
#define ALIEN_X_MAG				6
#define ALIEN_Y_MAG				6
#define FLAG_X_MAG				0
#define FLAG_Y_MAG				0
#define FRAME_DELAY				1
#define FLAG_FRAME_DELAY		4

#define N_FLAG					3
#define N_ALIENS				4

#define MAX_DIRECTIONS			5
#define HALF					2
#define WANDER_PROB				20
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
	FLAG   = 3
	//COIN   = 13
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
	EXIT = 3,
	LADDER_COIN = 4,
	COIN = 5
};
