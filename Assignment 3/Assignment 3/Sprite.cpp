#include "StdAfx.h"
#include "Sprite.h"

Sprite::Sprite(Graphics^ startCanvas, String^ startFileName, array<Point>^ startSpriteState, int startX, int startY)
{
	 canvas				= startCanvas;
	 fileName			= startFileName;
	 xPos				= startX;
	 yPos				= startY;
	 spriteSheetState	= startSpriteState;

	 currentFrame = 0;
	 alive = true;

	 
	 spriteAction = WAITING;
	 

	 StreamReader^ reader = gcnew StreamReader(fileName + ".map");

	 spriteSheetData = gcnew array<int,3>(spriteSheetState->Length, 81, 4);	

	 for(int dim0 = 0; dim0 < spriteSheetData->GetLength(0); dim0++) // Sprite state
	 {
	 	int end = spriteSheetState[dim0].Y - spriteSheetState[dim0].X;
 
   		for(int dim1 = 0; dim1 < end; dim1++) // N Frames
		{			
			String^ line = reader->ReadLine();

			if(line != nullptr)
			{
				array<String^>^ items = line->Split(',');

				for(int dim2 = 0; dim2 < spriteSheetData->GetLength(2); dim2++) // X, Y, WIDTH, HEIGHT
				{
					spriteSheetData[dim0, dim1, dim2] = (int::Parse(items[dim2]));
				}
			}	

			delete line;	// Clean up
		}
     }

	 delete reader;

	 scale = 1;

	 spriteSheet = gcnew Bitmap(fileName + ".png");
	 spriteSheet->MakeTransparent(spriteSheet->GetPixel(0,0));
	 format = spriteSheet->PixelFormat;

	 list = gcnew ArrayList();

	 for(int i = 0; i < spriteSheetData->GetLength(0); i++)
	 {
		 ArrayList^ framesList = gcnew ArrayList();

		 for(int j = 0; j < spriteSheetData->GetLength(1); j++)
		 {
			 if(spriteSheetData[i,j,0] != 0)
			 {
				 framesList->Add
				 (
					 gcnew array<int>
					 {
						 spriteSheetData[i,j,X],
						 spriteSheetData[i,j,Y],
						 spriteSheetData[i,j,WIDTH],
						 spriteSheetData[i,j,HEIGHT]						 
					 }
				 );
			 }
		 }

		 list->Add(framesList);
	 }
	 
	 delete spriteSheetData;
	 
}

void Sprite::Draw(int newXPos, int newYPos){}

void Sprite::Move()
{
	xPos += (3 * SPEED) * facingDirection;		
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

	 if(alive)
	 {
		 currentFrame++; // move to sprites next frame		 
	 }
	 else
	 {
		 
		 currentFrame = stateFrames->Count - 1;
	 }
	  

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