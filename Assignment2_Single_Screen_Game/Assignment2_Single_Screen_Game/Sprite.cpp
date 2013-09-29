#include "StdAfx.h"
#include "Sprite.h"

Sprite::Sprite(TileMap^ startTileMap, EBoundsAction startAction, 
			   Graphics^ startCanvas, String^ filename, 
			   int nFrames, Random^ startRGen, Point startPos, 
			   Viewport^ startViewPort)
	{
		tileMap = startTileMap;
		action = startAction;
		canvas = startCanvas;
		frames = nFrames;
		rGen = startRGen;
		viewPort = startViewPort;
		boundsRect = tileMap->getMapBounds();
		walking = true;
		alive = true;


		//=================================================
		// Create spritesheets from file names
		//=================================================
		spriteSheet = gcnew Bitmap(filename);
		spriteSheet->MakeTransparent(spriteSheet->GetPixel(0,0));


		//=================================================
		// Init directional point array with values 
		// that will move the sprite in specific directions
		//=================================================
		spriteDirection = gcnew array<Point>(MAX_DIRECTIONS);

		spriteDirection[NORTH] = Point(0,-1);
		spriteDirection[EAST] = Point(1,0);
		spriteDirection[SOUTH] = Point(0,1);
		spriteDirection[WEST] = Point(-1,0);
		spriteDirection[STAND] = Point(0,0);

		
		//=================================================
		// Initialize bearing with a random one
		//=================================================
		bearing = STAND;


		//=================================================
		// Set mag speed for the sprite
		//=================================================
		/*xMag = SPEED;
		yMag = SPEED;*/


		//=================================================
		// Picks a random frame to be drawn this creates a random
		// look of all the sprites used in the game and that all 
		// will not start with the same frame animation
		//=================================================
		currentFrame = rGen->Next(frames-1);// minus 1 to keep in bounds

		//=================================================
		// Gets the frame width and hight the sprites 
		// frame being drawn to the screen
		//=================================================
		frameDelay = 1;
		
		//frameWidth = spriteSheets[bearing]->Width / frames;
		//frameHeight = spriteSheets[bearing]->Height;


		//=================================================
		// Set initial position
		//=================================================
		/*xPos = startPos.X;
		yPos = startPos.Y;*/
		
		bounds = gcnew array<Point>(4);
		boundPoints = gcnew array<Point>(4);
	}



//void Sprite::update()
//	{	
//		// REDUNDANT
//	}
//void Sprite::draw()
//	{
//		//=================================================
//		// Draw sprites frame to the screen
//		// Its position is based on its worldX and worldY
//		//=================================================
//		canvas->DrawImage
//		(
//			spriteSheets[bearing], 
//			xPos, 
//			yPos, 
//			frameRectangle, 
//			GraphicsUnit::Pixel
//		);		
//	}

bool Sprite::collided(Sprite^ sprite)
	{
		bool collided = true;

		int s1XPos = (xPos - viewPort->getViewportWorldX()) + (frameWidth / 3);
		int s1YPos = (yPos - viewPort->getViewportWorldY())  + (frameHeight / 3);

		int s2XPos = (sprite->getXPos() - viewPort->getViewportWorldX())+(sprite->getWidth() / 3);
		int s2YPos = (sprite->getYPos() - viewPort->getViewportWorldY())+(sprite->getHeight() / 3);

		Rectangle s1 = Rectangle(s1XPos, s1YPos, frameWidth / 3, frameHeight / 3);
		Rectangle s2 = Rectangle(s2XPos, s2YPos, sprite->getWidth() / 3 , sprite->getHeight() / 3);

		if(s1.Bottom  < s2.Top)	 collided = false;
		if(s1.Top > s2.Bottom)	 collided = false;
		if(s1.Right < s2.Left)	 collided = false;
		if(s1.Left > s2.Right)	 collided = false;

		return collided;	
	}



void Sprite::draw(int newXPos, int newYPos)
	{
		//=================================================
		// Draw sprites frame to the screen
		//=================================================
		if(true)
		{
			Bitmap^ cloneBitmap;			

			System::Drawing::Imaging::PixelFormat format = spriteSheet->PixelFormat;
			cloneBitmap = spriteSheet->Clone(frameRectangle, format);

			if(bearing == WEST)
			{
				cloneBitmap->RotateFlip(RotateFlipType::RotateNoneFlipX);				
			}

			canvas->DrawImage
			(
				cloneBitmap,
				newXPos,
				newYPos
			);
		}

		canvas->DrawRectangle
		(
			gcnew Pen(Color::Fuchsia), 
			Rectangle
			(
				newXPos, 
				newYPos, 
				frameRectangle.Width, 
				frameRectangle.Height
			)
		);

		canvas->DrawRectangle
		(
			gcnew Pen(Color::Fuchsia), 
			Rectangle
			(
				bounds[0].X, 
				bounds[0].Y, 
				1, 
				1
			)
		);
		canvas->DrawRectangle
		(
			gcnew Pen(Color::Fuchsia), 
			Rectangle
			(
				bounds[1].X, 
				bounds[1].Y, 
				1, 
				1
			)
		);
		canvas->DrawRectangle
		(
			gcnew Pen(Color::Fuchsia), 
			Rectangle
			(
				bounds[2].X, 
				bounds[2].Y, 
				1, 
				1
			)
		);
		canvas->DrawRectangle
		(
			gcnew Pen(Color::Fuchsia), 
			Rectangle
			(
				bounds[3].X, 
				bounds[3].Y, 
				1, 
				1
			)
		);		
	}



void Sprite::erase(Color eraseColor)
	{
		//=================================================
		// Draw coloured rectangle over sprite
		//=================================================
		Brush^ brush = gcnew SolidBrush(eraseColor);
		Rectangle rect = Rectangle(xPos, yPos, frameRectangle.Width, frameRectangle.Height);
		canvas->FillRectangle(brush, rect);
	}


void Sprite::move(int viewportWorldX, int viewportWorldY)
	{
		//=======================================================================
		// If sprite can walk the xPosition and yPosition is incremented
		// the a set magnitude, a direction is then applied to the magnitude 1, -1
		// this will allow the sprite to move up, down, left and right
		//=======================================================================
		if(isBoundsCollision())
			executeBoundsAction();				

		if(walking)
			canSpriteMove(viewportWorldX, viewportWorldY);	
	}


void Sprite::canSpriteMove(int viewportWorldX, int viewportWorldY)
{
	int col = (xPos + frameWidth / 2) / T_SIZE;
	int row = (yPos / T_SIZE) + 1;

	ETileType tileType = tileMap->getTileType(row, col);

	if(tileType == WALKABLE && bearing == EAST)
	{
		yPos = (row * T_SIZE) - (frameHeight - 70);
	}
	
	if(tileType == LADDER && bearing == NORTH)
	{
		xPos = col * T_SIZE;
	}

	col = (xPos + frameWidth / 2) / T_SIZE;
	row = (yPos + frameHeight + 5) / T_SIZE;

	tileType = tileMap->getTileType(row, col);

	
	
	
	if(tileType == LADDER && bearing == SOUTH)
	{
		xPos = col * T_SIZE;
	}
					
	if(checkCanMove(bearing, viewportWorldX, viewportWorldY))
	{
		yPos += yMag * spriteDirection[bearing].Y;
		xPos += xMag * spriteDirection[bearing].X;	
	}

	if(xPos < 0)
	{
		executeBoundsAction();
		xPos = 0;		
	}

	if(xPos > (boundsRect.Right - frameWidth) - 35)
	{
		executeBoundsAction();
		xPos = (boundsRect.Right - frameWidth) - 35;		
	}
}

bool Sprite::checkCanMove(EBearing spriteBearing, int viewportWorldX, int viewportWorldY)
{
	// Copies current position to new variable
	int newSpriteXPos = xPos;
	int newSpriteYPos = yPos;

	// Adds to the new variable this will see where the knight wants to move
	newSpriteXPos += xMag * spriteDirection[spriteBearing].X;
	newSpriteYPos += yMag * spriteDirection[spriteBearing].Y;

	// Brings new positon into the viewport area
	int viewportSpriteX = newSpriteXPos - viewportWorldX;
	int viewportSpriteY = newSpriteYPos - viewportWorldY;

	//**************************************************
	// Sets the detection point for the knight to tell what tile he is on
	

	bounds[0].X = viewportSpriteX; //+ frameWidth / 5;
	bounds[0].Y = (viewportSpriteY + frameHeight) - 1;
	bounds[1].X = viewportSpriteX; // + frameWidth / 5;
	bounds[1].Y = (viewportSpriteY + frameHeight) - 70;
	bounds[2].X = (viewportSpriteX + frameWidth);//; - frameWidth / 5;
	bounds[2].Y = (viewportSpriteY + frameHeight)- 70;
	bounds[3].X = (viewportSpriteX + frameWidth);//; - frameWidth / 5;
	bounds[3].Y = (viewportSpriteY + frameHeight) - 1;
	

	//**************************************************
	/*boundPoints[0].X = (newSpriteXPos + frameWidth / 5) / T_SIZE;
	boundPoints[0].Y = ((newSpriteYPos + frameHeight) - 1) / T_SIZE;
	boundPoints[1].X = (newSpriteXPos + frameWidth / 5) / T_SIZE;
	boundPoints[1].Y = ((newSpriteYPos + frameHeight) - 70) / T_SIZE;
	boundPoints[2].X = ((newSpriteXPos + frameWidth) - frameWidth / 5) / T_SIZE;
	boundPoints[2].Y = ((newSpriteYPos + frameHeight) - 70) / T_SIZE;
	boundPoints[3].X = ((newSpriteXPos + frameWidth) - frameWidth / 5) / T_SIZE;;
	boundPoints[3].Y = ((newSpriteYPos + frameHeight) - 1) / T_SIZE;*/

	boundPoints[0].X = (newSpriteXPos) / T_SIZE;
	boundPoints[0].Y = ((newSpriteYPos + frameHeight) - 1) / T_SIZE;
	boundPoints[1].X = (newSpriteXPos) / T_SIZE;
	boundPoints[1].Y = ((newSpriteYPos + frameHeight) - 70) / T_SIZE;
	boundPoints[2].X = ((newSpriteXPos + frameWidth)) / T_SIZE;
	boundPoints[2].Y = ((newSpriteYPos + frameHeight) - 70) / T_SIZE;
	boundPoints[3].X = ((newSpriteXPos + frameWidth)) / T_SIZE;;
	boundPoints[3].Y = ((newSpriteYPos + frameHeight)-1) / T_SIZE;

	// Current pixel plus half framewidth puts pixel in 
	// center of knight then devides to get tile position 

	if(boundPoints[0].Y < 11 && boundPoints[2].X < 15)
	{
		bool p1 = tileMap->isSolid(boundPoints[0].Y, boundPoints[0].X);
		bool p2 = tileMap->isSolid(boundPoints[1].Y, boundPoints[1].X);
		bool p3 = tileMap->isSolid(boundPoints[2].Y, boundPoints[2].X);
		bool p4 = tileMap->isSolid(boundPoints[3].Y, boundPoints[3].X);

		if(!p1 && !p2 && !p3 && !p4) // If the tile is not flowers apply new move position
		{			
			return true;
		}
	}

	return false;
}

bool Sprite::isBoundsCollision()// should return info
	{
		//=======================================================================
		// checks the top, right, bottom and left side of the sprite
		// if outside of the specified area an action is triggered
		//======================================================================= 
		
		bool hitLeft = xPos < boundsRect.Left;						// Check left

		bool hitRight = xPos + frameWidth > boundsRect.Right - 35;		// Check right

		bool hitTop = yPos < boundsRect.Top;						// Check top

		bool hitBottom = yPos + frameHeight > boundsRect.Bottom;	// Check bottom

		return ( hitLeft || hitRight || hitTop || hitBottom );	
	}

void Sprite::executeBoundsAction()
	{
	    //=======================================================================
	    // Depending on the selected action of a sprite, a function will be
		// called that will force the sprite to do a specific action 
		// e.g. wrap around the screen or bounce off an object
		//=======================================================================
	    switch(action)
	    {
		    case BOUNCE:
			    reverse();	// Reverse sprites direction
			    break;
		    case WRAP:
			    wrap();		// Allows sprite wrap the screen e.g. right side to the left
			    break;
		    case DIE:
			    die();		// Sprite dies
			    break;
		    case STOP:
			    stop();		//Stop the sprite from moving
			    break;
	    }
	}



void Sprite::wrap()
	{
		// Depending on what bearing the sprite is when called 
		// the players position is changed to wrap around the screen
		switch(bearing)
		{
			case NORTH:
				// puts sprite on the south side on the screen
				yPos = tileMap->getMapBounds().Height - frameWidth; 				
			break;

			case EAST:
				// puts sprite on the west side of the screen
				xPos = 0;  
			break;

			case SOUTH:
				// puts sprite on the north side of the screen
				yPos = 0;
			break;

			case WEST:
				// puts sprite on the east side of the screen
				xPos = tileMap->getMapBounds().Width - frameWidth;
			break;
		}
	}

void Sprite::reverse()
	{
		// Reverse direction for bounce, modulo required for wrap around
		// Current bearings + half total directions mod max number directions)
		// This is to reverse the direction of our sprite, 
		// todo this we must add to our current bearing enumeration
		// Then after we have added we must use modulo to wrap around 
		// and the correct oposite direction is chosen
		int newBearing = (bearing + (4 / HALF)) % 4; 

		// If new bearing is in acceptable range
		bool inRange = newBearing < 4 && newBearing >= 0;
		
		if(inRange) bearing = static_cast<EBearing>(newBearing);

		// if illegal direction bearing unchanged 
		// throwing exception is more appropriate	
	}

void Sprite::die()
	{
		// NOT IMPLIMENTED YET
		/*alive = false;
		xMag = 0;
		yMag = 0;*/
	}

void Sprite::stop()
	{
		// NOT IMPLIMENTED YET
		if(bearing == WEST)
			xPos = boundsRect.Left - 1;

		if(bearing == EAST)
			xPos = boundsRect.Right - frameWidth - 35;
	}



void Sprite::updateFrame()
	{
		//=================================================
		// Update sprites frame is not standing
		//=================================================
				
		currentFrame %= frames; // c = c%f;

		//frameRectangle = Rectangle(currentFrame * frameWidth, 0, frameWidth, frameHeight);

		frameWidth = sheetData[bearing, currentFrame, WIDTH];
		frameHeight = sheetData[bearing, currentFrame, HEIGHT];
		
		frameRectangle = Rectangle
		(
			sheetData[bearing, currentFrame, X],			// XPOS
			sheetData[bearing, currentFrame, Y],			// YPOS
			sheetData[bearing, currentFrame, WIDTH],		// WIDTH
			sheetData[bearing, currentFrame, HEIGHT]		// HEIGHT
		);
		
		// this is to slow down the frame animation so that the sprites have a more realistic movement
		bool changeFrame = frameTime > frameDelay;

		if(changeFrame && walking) 
		{
			frameTime = 0; // resets frame time

			currentFrame++; // move to sprites next frame
		}

		frameTime++; // increase frame time		
	}

void Sprite::setSpriteSheet() 
	{		
		// NOT IMPLIMENTED this will handle multiple spritesheets
	}




void Sprite::setBearing(EBearing b)
	{
		switch(b)
		{
			case NORTH:
				if(getTileType(-2) == LADDER)
				{
					bearing = b;	
				}
				break;
			case SOUTH:
				if(getTileType(2) == LADDER)
				{
					bearing = b;	
				}
				break;
			default:
				bearing = b;
				break;
		}		
	}

ETileType Sprite::getTileType(int offset)
	{
		int col = (xPos + (frameWidth / HALF)) / T_SIZE;
		int row = (yPos + (frameHeight + offset)) / T_SIZE;

		return tileMap->getTileType(row, col);
	}