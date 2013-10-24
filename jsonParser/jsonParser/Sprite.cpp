#include "StdAfx.h"
#include "Sprite.h"

Sprite::Sprite(Graphics^ startCanvas, String^ startFileName, String^ startFrameName, int startX, int startY)
{
	 canvas = startCanvas;

	 fileName	 = startFileName;
	 frameName	 = startFrameName;

	 xPos		 = startX;
	 yPos		 = startY;

	 scale		 = 1;

	 spriteSheet = gcnew Bitmap(fileName + ".png");
	 spriteSheet->MakeTransparent(spriteSheet->GetPixel(0,0));
	 format = spriteSheet->PixelFormat;

	 //
	 // Load Rectangle array
	 //
	 
	 StreamReader^ reader = gcnew StreamReader(fileName + ".json");

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
					frames[count] = Rectangle(int::Parse(x), int::Parse(y), int::Parse(w), int::Parse(h));

				 count++;
			 }
		 }					 
	 }

	 reader->Close();
}

void Sprite::draw()
{
	 //
	 // Draw sprites frame to the screen
	 //
	 Bitmap^ spriteBitmap = spriteSheet->Clone(frames[currentFrame], format);
	 //
	 // Flips image on the X axis based on direction
	 //
	 if(false) spriteBitmap->RotateFlip(RotateFlipType::RotateNoneFlipX);	
	 //
	 // Draws bitmap to the screen
	 //
	 canvas->DrawImage(spriteBitmap, xPos - frames[currentFrame].Width, yPos - frames[currentFrame].Height, frames[currentFrame].Width * scale, frames[currentFrame].Height * scale);	
	 canvas->DrawRectangle(gcnew Pen(Color::Black), xPos - frames[currentFrame].Width, yPos - frames[currentFrame].Height, frames[currentFrame].Width * scale, frames[currentFrame].Height * scale);
	 //
	 // Clean up bitmap
	 //
	 delete spriteBitmap;
}

void Sprite::drawPlayer()
{
	 //
	 // Draw sprites frame to the screen
	 //
	 Bitmap^ spriteBitmap = spriteSheet->Clone(frames[currentFrame], format);
	 //
	 // Flips image on the X axis based on direction
	 //
	 if(false) spriteBitmap->RotateFlip(RotateFlipType::RotateNoneFlipX);	
	 //
	 // Draws bitmap to the screen
	 //
	 canvas->DrawImage(spriteBitmap, xPos, yPos - frames[currentFrame].Height, frames[currentFrame].Width * scale, frames[currentFrame].Height * scale);	
	 canvas->DrawRectangle(gcnew Pen(Color::Black), xPos, yPos - frames[currentFrame].Height, frames[currentFrame].Width * scale, frames[currentFrame].Height * scale);
	 //
	 // Clean up bitmap
	 //
	 delete spriteBitmap;
}

void Sprite::updateAllFrames()
{
	 // Resets frame
	 currentFrame %= frames->Length - 1;

	 // this is to slow down the frame animation so that the sprites have a more realistic movement
	 bool changeFrame = frameTime > 1;

	 if(true) 
	 {
		 frameTime = 0; // resets frame time

		 currentFrame++; // move to sprites next frame
	 }

	 frameTime++; // increase frame time

}

void Sprite::update(int startFrame, int endFrame)
{
	 // Resets frame
	 if(currentFrame > endFrame)
	 {
		 currentFrame = startFrame;
	 }

	 // this is to slow down the frame animation so that the sprites have a more realistic movement
	 bool changeFrame = frameTime > 1;

	 if(changeFrame) 
	 {
		 frameTime = 0; // resets frame time

		 currentFrame++; // move to sprites next frame
	 }

	 frameTime++; // increase frame time

}
