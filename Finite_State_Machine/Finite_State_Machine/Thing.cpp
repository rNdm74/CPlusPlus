#include "StdAfx.h"
#include "Thing.h"

Thing::Thing()
	{
	}

Thing::Thing(Graphics^ startCanvas, Random^ startRandom, int startWorldWidth, int startWorldHeight, String^ imageFileName, int startRadius)
	{
		canvas = startCanvas;
		rGen = startRandom;

		worldWidth = startWorldWidth;
		worldHeight = startWorldHeight;

		thingImage = gcnew Bitmap(imageFileName);
		thingImage->MakeTransparent(thingImage->GetPixel(0,0));

		location.X = rGen->Next(worldWidth);
		location.Y = rGen->Next(worldHeight);

		radius = startRadius;

		speed = 2;
	}

void Thing::Move()
	{
		double radiansAngle = angle * 0.01745; // convert degrees to radians PI / 180

		if(location.X < 0 || location.X + radius > worldWidth || location.Y < 0 || location.Y + radius > worldHeight)
		{
			location.X -= Math::Cos(radiansAngle) * speed;
			location.Y -= Math::Sin(radiansAngle) * speed;

			ChangeRandomDirection();
		}
		else
		{
			location.X += Math::Cos(radiansAngle) * speed;
			location.Y += Math::Sin(radiansAngle) * speed;
		}		
	}

bool Thing::collided(Thing^ thing)
	{
		bool collided = true;

		int s1XPos = location.X;
		int s1YPos = location.Y;

		int s2XPos = thing->getLocation().X;
		int s2YPos = thing->getLocation().Y;

		Rectangle s1 = Rectangle(s1XPos, s1YPos, radius, radius);
		Rectangle s2 = Rectangle(s2XPos, s2YPos, thing->getRadius(), thing->getRadius());

		if(s1.Bottom  < s2.Top)	 collided = false;
		if(s1.Top > s2.Bottom)	 collided = false;
		if(s1.Right < s2.Left)	 collided = false;
		if(s1.Left > s2.Right)	 collided = false;

		return collided;	
	}

void Thing::ChangeRandomDirection()
	{
		int newAngle = rGen->Next(361);

		angle = newAngle;
	}

void Thing::Draw()
	{
		canvas->DrawImage(thingImage, location.X, location.Y, radius, radius);		
	}

void Thing::PointMeAt(int newX, int newY)
	{

	}

double Thing::ComputeDistance(Thing^ otherGuy)
	{
		Point myCenter = getCenter();
		Point otherGuyCenter = otherGuy->getCenter();

		double delta = Math::Sqrt(Math::Pow(myCenter.X - otherGuyCenter.X, 2.0) + Math::Pow(myCenter.Y - otherGuyCenter.Y, 2.0));

		return delta;
	}