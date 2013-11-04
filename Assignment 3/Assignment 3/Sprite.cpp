#include "StdAfx.h"
#include "Sprite.h"

Sprite::Sprite(Graphics^ startCanvas, String^ startFileName, Point startLocation, ArrayList^ startFrameList)
{
	 canvas	= startCanvas;
	 fileName = startFileName;
	 xPos = startLocation.X;
	 yPos = startLocation.Y;
	 list = startFrameList;

	 spriteSheet = gcnew Bitmap(fileName + ".png");
	 spriteSheet->MakeTransparent(spriteSheet->GetPixel(0,0));

	 currentFrame = 0;
	 alive = true;

	 boss = startFileName == BOSS;

	 spriteAction = WAITING; 
}

void Sprite::Draw(int newXPos, int newYPos){}

void Sprite::Move()
{
	xPos += VELOCITY * facingDirection;	
}

void Sprite::Update()
{	 
	 //
	 // Gets all frames for the current state
	 //
	 ArrayList^ stateFrames = safe_cast<ArrayList^>(list[spriteState]);

	 //
	 // Sets action flag sprite will return to IDLE state when required
	 //
	 finishedAnimation = (currentFrame == stateFrames->Count - 1);

	 //
	 // Resets frame to zero when all frames have been updated
	 //
	 currentFrame %= stateFrames->Count - 1;

	 //
	 // Gets frame data for the current frame from the stateFrames list
	 //
	 array<int>^ frameData = safe_cast<array<int>^>(stateFrames[currentFrame]);
	 
	 //
	 // Creates sprite frame rectangle
	 //
	 
	 spriteFrame = Rectangle
	 (		 
		 frameData[X],						
		 frameData[Y],					
		 frameData[WIDTH],				
		 frameData[HEIGHT]			
	 );

	 currentFrame++; // move to sprites next frame	  

	 //
	 // Clean up
	 //
	 delete stateFrames;
	 delete frameData;
}


// FSM Methods
void Sprite::UpdateState(Sprite^ otherSprite){}
void Sprite::PerformAction(Sprite^ otherSprite){}
void Sprite::UpdateAbility(){}
void Sprite::PerformAbility(Sprite^ otherSprite){}
void Sprite::ExecuteAbility(){}

Rectangle Sprite::getCollisionRectangle(int vx, int vy)
{
	return Rectangle((xPos - xOFFSET) - vx, (yPos - yOFFSET)-vy, spriteFrame.Width, spriteFrame.Height);
}
