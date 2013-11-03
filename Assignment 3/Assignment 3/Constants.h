#pragma once

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
#define PLAYER_X_MAG			5
#define PLAYER_Y_MAG			2
#define ALIEN_X_MAG				7
#define ALIEN_Y_MAG				8
#define NEW_ALIEN_X_MAG			11
#define NEW_ALIEN_Y_MAG			12
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
#define PERCENTAGE				3
#define GAME_OVER				5
#define FULL_HEARTS				3
//
//
//
#define EXIT_COL				4
#define EXIT_ROW				9
#define EXIT_TILE				9
#define LADDER_TILE				5
#define DEFAULT_TILE			0

#define N_ROWS					1		// Tilemap
#define N_COLS					5		// Tilemap
#define T_WIDTH					1024	// Tile width
#define T_HEIGHT				768		// Tile height

#define V_COLS					1		// Viewport Columns
#define V_ROWS					1		// Viewport Rows
#define OFFSET 100

#define MAX_DIRECTIONS 7
#define HALF 2
#define WANDER_PROB 25

#define SPEED 2

//
// 
//
public enum EDirection
{	
	LEFT						=	   -1,
	RIGHT						=		1
};
//
//
//
public enum EAction
{
	WAITING						=		0,
	WIN							=		1,
	LOSE						=		2,
	USE_ABILITY					=		3,
	FINISHED_ABILITY			=		4
};
//
//
//
public enum EAbility
{
	START_ABILITY,
	WALK_FORWARD,
	ATTACK,
	WALK_BACKWARD,
	FINISHED,
	HEALTH_POTION
};
//
//
//

//
//
//
enum EState
{
	IDLE,
	HURT,
	BOSS_HURT,
	LESSER_ICE,
	GREATER_ICE,
	WALK,
	LESSER_WAND,
	DODGE,
	ELECTRIC_STORM,
	GREATER_WAND,
	WHIRLWIND,
	HEAL
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
