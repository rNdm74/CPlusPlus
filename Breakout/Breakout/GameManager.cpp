#include "StdAfx.h"
#include "GameManager.h"

#define BLOCK_WIDTH 62.4
#define BLOCK_HEIGHT 25
#define PADDLE_WIDTH 120
#define PADDLE_HEIGHT 15
#define BALL_WIDTH 15

GameManager::GameManager(Graphics^ g, Size s, int c, int r)
	{
		columns = c;
		rows = r;

		lifes = 3;

		blocks = gcnew array<Shape^,2>(columns,rows);

		array<Color>^ colors = gcnew array<Color> 
		{ 
			Color::Red, 
			Color::Blue, 
			Color::Green, 
			Color::Yellow 
		};
		

		// Create blocks
		for(int col = 0; col < columns; col++)
			for(int row = 0; row < rows; row++)
				blocks[col, row] = gcnew RectangleShape
				(
					(float)BLOCK_WIDTH * col,				// xPos
					(float)BLOCK_HEIGHT * row,				// yPos				
					(float)BLOCK_WIDTH,						// width
					(float)BLOCK_HEIGHT,					// height
					g,										// graphics
					0,										// xVel
					0,										// yVel
					colors[row]								// color
				);

		// Create paddle
		paddle = gcnew RectangleShape
				(
					(float)s.Width / 2 - PADDLE_WIDTH / 2, 
					(float)s.Height - PADDLE_HEIGHT, 
					(float)PADDLE_WIDTH, 
					(float)PADDLE_HEIGHT, 
					g, 
					0, 
					0, 
					Color::CornflowerBlue
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
					Color::Orange
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

void GameManager::keyDown(KeyEventArgs^  e)
	{
		paddle->keyDown(e);
	}

void GameManager::keyUp(KeyEventArgs^  e)
	{
		paddle->keyUp(e);
	}

void GameManager::update()
	{
		if(gameRunning)
		{
			paddle->move();
			ball->move();

			if(ball->collision(paddle))		
				ball->verticalBounce(paddle->getCenterX());

			if(ball->collision(westWall) || ball->collision(eastWall))		
				ball->horizontalBounce();

			if(ball->collision(northWall))		
				ball->verticalBounce();		

			checkCollision(ball);
		}
	}

void GameManager::render()
	{
		for(int col = 0; col < columns; col++)
			for(int row = 0; row < rows; row++)
				blocks[col, row]->draw();

		paddle->draw();
		ball->draw();
	}

bool GameManager::checkCollision(Shape ^ball)
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

void GameManager::resetGame(SizeF s)
	{
		ball->setYPos(s.Height / 2); 
		ball->setXPos(s.Width / 2);
		ball->setXVel(0);

		brokenBrickCount = 0;

		lifes--;
	}

bool GameManager::checkGameOver()
	{
		return (lifes <= 0);
	}

bool GameManager::checkBallOutOfBounds()
	{
		return (ball->getYPos() > paddle->getYPos() + PADDLE_HEIGHT);
	}
