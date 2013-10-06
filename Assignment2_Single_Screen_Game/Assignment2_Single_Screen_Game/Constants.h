#pragma once
//
// Constants
//
#define NORTH_X				    35
#define	NORTH_Y			       -75	
#define SOUTH_X					35
#define	SOUTH_Y					2
#define EAST_X					75
#define	EAST_Y				   -35
#define WEST_X				   -2
#define	WEST_Y				   -35
#define CENTER_X				35
#define	CENTER_Y			   -35
//
//
//
#define PLAYER_X_MAG			10
#define PLAYER_Y_MAG			11
#define ALIEN_X_MAG				8
#define ALIEN_Y_MAG				8
#define FLAG_X_MAG				0
#define FLAG_Y_MAG				0
//
//
//
#define FRAME_DELAY				1
#define FLAG_FRAME_DELAY		3
#define HURT_DELAY				100
#define DELAY					30
//
//
//
#define N_LIVES					3
#define N_FLAGS					4
#define N_ALIENS				4
#define N_DIRECTIONS			4
#define N_LEVELS				15
#define START_LEVEL				1
//
//
//
#define MAX_DIRECTIONS			6
#define HALF					2
#define WANDER_PROB				30
#define SPEED					5
//
//
//
#define N_COLS					15	// X Tiles
#define N_ROWS					11 	// Y tiles
#define N_TILES					10	// Tiles array size
#define T_SIZE					70	// Tile bitmap size
#define V_COLS					15	// Viewport columns
#define V_ROWS					11  // Viewport rows
//
//
//
#define BONUS_COINS				150
#define COIN_PICKUP				50
#define FLAG_PICKUP				500
//
//
//
#define OFFSET					100
#define PERCENTAGE				3
//
//
//
#define EXIT_COL				4
#define EXIT_ROW				9
#define EXIT_TILE				9
#define LADDER_TILE				5
#define DEFAULT_TILE			0
//
//
//
#define DATAFILE				"data.dat"
#define BACKGROUND				"Images/playscreen.png"
#define THE_END					"THE END"
//
//
//
public enum ESprite
{
	PLAYER		= 1,
	ALIEN_ONE	= 2,
	ALIEN_TWO	= 3,
	ALIEN_THREE	= 4,
	ALIEN_FOUR	= 5,
	BLUE_FLAG	= 10,
	ORANGE_FLAG	= 11,
	YELLOW_FLAG	= 12,
	GREEN_FLAG	= 13
};
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
// 
//
public enum EState
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
	STAND,
	HURT
};
//
// 
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

