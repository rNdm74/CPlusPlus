#include "StdAfx.h"
#include "Sprite.h"

Sprite::Sprite(Graphics^ startCanvas, String^ startFileName, array<Point>^ startSpriteState, int startX, int startY)
{
	 canvas		 = startCanvas;
	 fileName	 = startFileName;
	 xPos		 = startX;
	 yPos		 = startY;
	 spriteState = startSpriteState;

	 currentFrame = 0;

	 StreamReader^ reader = gcnew StreamReader(fileName + ".txt");

	 spriteSheetData = gcnew array<int,3>(spriteState->Length, 81, 4);	

	 for(int dim0 = 0; dim0 < spriteSheetData->GetLength(0); dim0++) // Sprite state
	 {
	 	int end = spriteState[dim0].Y - spriteState[dim0].X;
 
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
						 spriteSheetData[i,j,0],
						 spriteSheetData[i,j,1],
						 spriteSheetData[i,j,2],
						 spriteSheetData[i,j,3]
					 }
				 );
			 }
		 }

		 list->Add(framesList);
	 }
	 

	 /*ArrayList^ item = safe_cast<ArrayList^>(list[state]);

	 array<int>^ breakline = safe_cast<array<int>^>(item[currentFrame]);*/

	 state = IDLE;

	 //
	 // Load Rectangle array
	 //
	 
	 /*StreamReader^ reader = gcnew StreamReader(fileName + ".json");

	 int count = 0;
	 int nFrames = 0;

	 while(!reader->EndOfStream)
	 {
		 String^ line = reader->ReadLine();

		 array<String^>^ items = line->Split('"');

		 for(int string = 0; string < items->Length; string++)
		 {
			 if(items[string]->Contains(frameName))
			 {
				 nFrames++;
			 }
		 }
	 }

	 reader->Close();

	 frames = gcnew array<Rectangle>(nFrames - 1);

	 reader = gcnew StreamReader(fileName + ".json");	 

	 while(!reader->EndOfStream)
	 {
		 String^ line = reader->ReadLine();

		 array<String^>^ items = line->Split('"');

		 for(int string = 0; string < items->Length; string++)
		 {
			 if(items->Length > 3 && items[string]->Contains("frame") )
			 {
				 String^ x = items[4]->Trim(':',',');
				 String^ y = items[6]->Trim(':',',');
				 String^ w = items[8]->Trim(':',',');
				 String^ h = items[10]->Trim(':',',','}');

				 if(count < nFrames - 1)
				 {					 
					 frames[count] = Rectangle(int::Parse(x), int::Parse(y), int::Parse(w), int::Parse(h));
				 }
					

				 count++;
			 }
		 }					 
	 }

	 
	 reader->Close();*/

	 /*StreamWriter^ writer = gcnew StreamWriter(fileName + ".txt");

	 for(int i = 0; i < frames->Length; i++)
	 {
		 String^ x = frames[i].X.ToString();
		 String^ y = frames[i].Y.ToString();
		 String^ w = frames[i].Width.ToString();
		 String^ h = frames[i].Height.ToString();

		 writer->WriteLine(x + "," + y + "," + w + "," + h);		 
	 }

	 writer->Close();*/

	 
}

void Sprite::draw()
{
	 //
	 // Draw sprites frame to the screen
	 //	 
	 Bitmap^ spriteBitmap = spriteSheet->Clone(spriteFrame, format);
	 //
	 // Flips image on the X axis based on direction
	 //
	 if(right == -1) spriteBitmap->RotateFlip(RotateFlipType::RotateNoneFlipX);	
	 //
	 // Draws bitmap to the screen
	 //

	 xOFFSET = spriteFrame.Width;	 
	 yOFFSET = spriteFrame.Height;

	 if(fileName == "Player") xOFFSET = 0;

	 canvas->DrawImage(spriteBitmap, xPos - xOFFSET, yPos - yOFFSET);	
	 canvas->DrawRectangle(gcnew Pen(Color::Black), getCollisionRectangle());
	 
	 delete spriteBitmap;
}

void Sprite::move(int direction)
{
	right = direction;

	if(direction < 0 || direction > 0)
	{
		state = WALK;
	}
	else
	{
		if(attack == false)		
		{
			direction = 0;
			state = IDLE;
		}		
	}

	xPos += (3 * SPEED) * direction;
}

void Sprite::update()
{
	 //
	 // Gets all frames for the current state
	 //
	 ArrayList^ stateFrames = safe_cast<ArrayList^>(list[state]);

	 //
	 // Sets action flag sprite will return to IDLE state when required
	 //
	 finishedAction = (currentFrame == stateFrames->Count - 1);

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
		 frameData[0],						
		 frameData[1],					
		 frameData[2],				
		 frameData[3]			
	 );

	 currentFrame++; // move to sprites next frame

	 //
	 // Clean up
	 //
	 delete stateFrames;
	 delete frameData;
}

void Sprite::update(int startFrame, int endFrame)
{
	 finishedAction = false;

	 // Resets frame
	 if(currentFrame > endFrame)
	 {
		 currentFrame = startFrame;
		 finishedAction = true;
	 }

	 currentFrame++; // move to sprites next frame
}
