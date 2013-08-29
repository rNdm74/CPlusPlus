#include "StdAfx.h"
#include "Sprite.h"

Sprite::Sprite(Graphics^ startCanvas, Bitmap^ startSpriteSheet, Random^ startRGen, Rectangle startBounds)
	{
		canvas = startCanvas;
		spriteSheet = startSpriteSheet;
		rGen = startRGen;
		boundsRect = startBounds;

		leftFrame = gcnew Bitmap("blobboLeft.bmp");
		rightFrame = gcnew Bitmap("blobboRight.bmp");

		xPos = rGen->Next(boundsRect.Width-32);
		yPos = boundsRect.Height - spriteSheet->Height;

		xVel = 0.1;
		yVel = 0;

		init();
	}

Sprite::Sprite(Graphics^ startCanvas, Bitmap^ startSpriteSheet, Random^ startRGen, int startXPos, int startYPos, int startXVel, int startYVel)
	{
		canvas = startCanvas;
		spriteSheet = startSpriteSheet;
		rGen = startRGen;
		xPos = startXPos;
		yPos = startYPos;
		xVel = startXVel;
		yVel = startYVel;

		init();
	}

void Sprite::init()
	{
		nFrames = spriteSheet->Width / spriteSheet->Height;
		
		currentFrame = rGen->Next(nFrames-1);

		frameWidth = spriteSheet->Width / nFrames;
		frameHeight = spriteSheet->Height;

		spriteSheet->MakeTransparent(spriteSheet->GetPixel(0,0));

		lifeExpectancy = rGen->Next(MIN_LIFE_EXPECTANCY, MAX_LIFE_EXPECTANCY);

		scale = 256;
		tombStoneTime = 0;

		do
		{
			growRate = (rGen->NextDouble() * rGen->Next(2));
		}
		while(growRate == 0);
	}

void Sprite::draw()
	{
		if(!dead)
		{
			spriteSheet->SetResolution(scale, scale);
			
			//canvas->DrawString(spriteSheet->VerticalResolution

			canvas->DrawImage
			(
				spriteSheet, 
				(float)xPos, 
				(float)yPos, 
				srcRectangle, 
				GraphicsUnit::Pixel
			);
		}
	}

void Sprite::drawDead()
	{	
		if(tombStoneTime < 100)
		{
			if(dead)
			{
				canvas->DrawImage
				(
					spriteSheet, 
					(float)xPos, 
					(float)yPos, 
					srcRectangle, 
					GraphicsUnit::Pixel
				);				
			}
		}		
	}

void Sprite::erase(Color eraseColor)
	{
		canvas->FillRectangle(gcnew SolidBrush(eraseColor),(float)xPos, (float)yPos, srcRectangle.Width, srcRectangle.Height);
	}

void Sprite::move()
	{
		if(!adult && !dead)
		{			
			scale-=growRate;

			float growScale = frameHeight / scale;

			//yPos -= growScale;
		}

		if(scale < 100)
		{
			adult = true;
			scale = 100;
		}

		if(!dead)
		{
			float pastPos = xPos;

			xPos += SPEED * xVel;
			yPos += SPEED * yVel;

			setSpriteSheet(((xPos < pastPos) ? leftFrame : rightFrame), 4);
		}		
	}

void Sprite::checkBounds()
	{
		if(xPos + frameWidth > boundsRect.Width) xVel *= DIRECTION;
		if(xPos < 0) xVel *= DIRECTION;
	}

void Sprite::updateFrame()
	{
		if(dead) tombStoneTime++;

		currentFrame %= nFrames;

		srcRectangle = Rectangle(currentFrame * frameWidth, 0, frameWidth-1, frameHeight);

		currentFrame++;

		age++;		
	}

void Sprite::setSpriteSheet(Bitmap^ newSpriteSheet, int newNframes)
	{
		spriteSheet = newSpriteSheet;

		nFrames = newNframes;

		frameWidth = spriteSheet->Width / nFrames;
		frameHeight = spriteSheet->Height;

		spriteSheet->MakeTransparent(spriteSheet->GetPixel(0,0));		
	}

void Sprite::wander()
	{
		if(rGen->Next(WANDER_PROB) == 0)
		{
			xVel *= DIRECTION;			
		}

		if(age > lifeExpectancy && !dead && adult)
		{
			yPos+=10;
			setSpriteSheet(gcnew Bitmap("tombstone.bmp"), 1);
			dead = true;			
		}

		
	}