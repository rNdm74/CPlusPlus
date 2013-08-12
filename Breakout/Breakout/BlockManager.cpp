#include "StdAfx.h"
#include "BlockManager.h"

#define BLOCK_WIDTH 60
#define BLOCK_HEIGHT 25
#define PADDLE_WIDTH 120
#define PADDLE_HEIGHT 15
#define BALL_WIDTH 15

BlockManager::BlockManager(Graphics^ g, Size s)
	{
		columns = (s.Width / BLOCK_WIDTH);
		rows = 4;

		blocks = gcnew array<Shape^,2>(columns,rows);
		
		for(int x = 0; x < columns; x++)
			for(int y = 0; y < rows; y++)
				blocks[x, y] = gcnew RectangleShape
				(
					12 + BLOCK_WIDTH * x,			// xPos
					BLOCK_HEIGHT * y,				// yPos				
					BLOCK_WIDTH,					// width
					BLOCK_HEIGHT,					// height
					g,								// graphics
					0,								// xVel
					0,								// yVel
					Color::Green					// color
				);

		paddle = gcnew RectangleShape
				(
					s.Width / 2 - PADDLE_WIDTH / 2, 
					s.Height - 50, 
					PADDLE_WIDTH, 
					PADDLE_HEIGHT, 
					g, 
					0, 
					0, 
					Color::Blue
				);

		ball = gcnew EllipseShape
				(
					s.Width / 2, 
					s.Height / 2, 
					BALL_WIDTH, 
					BALL_WIDTH, 
					g, 
					0, 
					1, 
					Color::Red
				);
	}

void BlockManager::keyDown(KeyEventArgs^  e)
	{
		paddle->keyDown(e);
	}

void BlockManager::keyUp(KeyEventArgs^  e)
	{
		paddle->keyUp(e);
	}

void BlockManager::update()
	{
		for(int x = 0; x < columns; x++)
		{
			for(int y = 0; y < rows; y++)
			{
				blocks[x, y]->collision(ball);
				
				ball->collision(blocks[x, y]);
			}
		}	

		ball->collision(paddle);

		paddle->move();
		ball->move();
		
	}

void BlockManager::render()
	{
		for(int x = 0; x < columns; x++)
			for(int y = 0; y < rows; y++)
				if(blocks[x, y]->isVisible())blocks[x, y]->draw();

		paddle->draw();
		ball->draw();
	}
