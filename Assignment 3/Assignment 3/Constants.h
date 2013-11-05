#pragma once

#define N_ROWS					1		// Tilemap
#define N_COLS					5		// Tilemap
#define T_WIDTH					1024	// Tile width
#define T_HEIGHT				768		// Tile height

#define V_COLS					1		// Viewport Columns
#define V_ROWS					1		// Viewport Rows

#define OFFSET					100
#define HALF					2

#define HEALTH_COST				2
#define MANA_COST				2

#define VELOCITY				6
#define GRAVITY					2
#define SPEED					2

#define BOSS					"makhana"
//
//
//
public enum ECharacters
{	
	PLAYER,
	FLOPPIT,
	FLUPPIT,
	PERUNA,
	COCOON,
	MAKHANA
};
//
// 
//
public enum EDirection
{	
	LEFT  = -1,
	RIGHT =	 1
};
//
//
//
public enum EAction
{
	NEW_BATTLE,
	WAITING,
	WIN,
	LOSE,
	USE_ABILITY,
	FINISHED_ABILITY,
	HOME,
	GAMEOVER
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
