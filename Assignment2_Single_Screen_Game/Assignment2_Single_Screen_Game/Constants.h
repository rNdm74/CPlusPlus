#pragma once
//
// Constants
//
#define PLAYER_X_MAG			8
#define PLAYER_Y_MAG			10
#define ALIEN_X_MAG				6
#define ALIEN_Y_MAG				6
#define FLAG_X_MAG				0
#define FLAG_Y_MAG				0
//
//
//
#define FRAME_DELAY				1
#define FLAG_FRAME_DELAY		3
//
//
//
#define N_LIVES					3
#define N_FLAG					3
#define N_ALIENS				4
//
//
//
#define MAX_DIRECTIONS			5
#define HALF					2
#define WANDER_PROB				20
#define SPEED					5
//
//
//
#define N_COLS					15	// X Tiles
#define N_ROWS					11 	// Y tiles
#define N_TILES					10	// Tiles array size
#define T_SIZE					70	// Tile bitmap size
#define V_COLS					15
#define V_ROWS					11
//
//
//
#define OFFSET					100
//
//
//
#define PLAYER					1
#define ALIEN_ONE				2
#define ALIEN_TWO				3
#define ALIEN_THREE				4
#define ALIEN_FOUR				5
#define BLUE_FLAG				10
#define ORANGE_FLAG				11
#define YELLOW_FLAG				12
#define GREEN_FLAG				13
//
//
//
public enum EFrame
{
	X,
	Y,
	WIDTH,
	HEIGHT
};
//
// Bearing
//
public enum EBearing
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
	STAND
};
//
// BoundsAction
//
public enum EAction
{
	BOUNCE,
	WRAP,
	DIE,
	STOP, 
	WALK,
	COLLECT_COIN
};
//
//
//
public enum ETileType
{
	SOLID,
	LADDER,
	WALKABLE,
	EXIT,
	LADDER_COIN,
	COIN
};

