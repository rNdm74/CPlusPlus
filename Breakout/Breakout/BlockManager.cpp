#include "StdAfx.h"
#include "BlockManager.h"

#define BLOCK_WIDTH 60
#define BLOCK_HEIGHT 25
#define PADDLE_WIDTH 120
#define PADDLE_HEIGHT 15
#define BALL_WIDTH 15

BlockManager::BlockManager(Graphics^ g, Size s, int c, int r)
	{
		columns = c;
		rows = r;
		

		blocks = gcnew array<Shape^,2>(columns,rows);
		
		for(int col = 0; col < columns; col++)
			for(int row = 0; row < rows; row++)
				blocks[col, row] = gcnew RectangleShape
				(
					(float)12 + BLOCK_WIDTH * col,			// xPos
					(float)BLOCK_HEIGHT * row,				// yPos				
					(float)BLOCK_WIDTH,						// width
					(float)BLOCK_HEIGHT,					// height
					g,										// graphics
					0,										// xVel
					0,										// yVel
					Color::Green							// color
				);

		paddle = gcnew RectangleShape
				(
					(float)s.Width / 2 - PADDLE_WIDTH / 2, 
					(float)s.Height - 50, 
					(float)PADDLE_WIDTH, 
					(float)PADDLE_HEIGHT, 
					g, 
					0, 
					0, 
					Color::Blue
				);

		ball = gcnew EllipseShape
				(
					(float)s.Width / 2, 
					(float)s.Height / 2, 
					(float)BALL_WIDTH, 
					(float)BALL_WIDTH, 
					g, 
					0, 
					(float)1, 
					Color::Red
				);

		northWall = gcnew RectangleShape
				(
					0, 
					(float)-BALL_WIDTH, 
					(float)s.Width, 
					(float)BALL_WIDTH, 
					g, 
					0, 
					0, 
					Color::WhiteSmoke
				);

		westWall = gcnew RectangleShape
				(
					(float)-BALL_WIDTH, 
					0, 
					(float)BALL_WIDTH, 
					(float)s.Height, 
					g, 
					0, 
					0, 
					Color::WhiteSmoke
				);

		eastWall = gcnew RectangleShape
				(
					(float)s.Width, 
					0, 
					(float)BALL_WIDTH, 
					(float)s.Height, 
					g, 
					0, 
					0, 
					Color::WhiteSmoke
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
		if(gameRunning)
		{
			paddle->move();
			ball->move();

			if(ball->collision(paddle))		
				ball->verticalBounce(paddle->getCenterX());

			if(ball->collision(westWall))		
				ball->horizontalBounce();

			if(ball->collision(eastWall))		
				ball->horizontalBounce();

			if(ball->collision(northWall))		
				ball->verticalBounce();		

			checkCollision(ball);
		}
	}

void BlockManager::render()
	{
		for(int x = 0; x < columns; x++)
			for(int y = 0; y < rows; y++)
				if(blocks[x, y]->isVisible())blocks[x, y]->draw();

		paddle->draw();
		ball->draw();
	}

bool BlockManager::checkCollision(Shape ^ball)
	{
		for(int col = 0; col < columns; col++)
		{
			for(int row = 0; row < rows; row++)
			{
				Shape^ block = blocks[col, row];

				if(block->isVisible())
				{
					if(block->collision(ball))
					{
						ball->verticalBounce(block->getCenterX());
						block->setVisible(false);
						brokenBrickCount++;						
						return true;
					}
				}
			}
		}

		return false;
	}

bool BlockManager::checkGameOver()
	{
		return (ball->getYPos() > paddle->getYPos() + 50);
	}
