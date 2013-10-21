#include "StdAfx.h"
#include "Thing.h"

Thing::Thing()
	{
	}

Thing::Thing(Graphics^ startCanvas, Random^ startRandom, int startWorldWidth, int startWorldHeight, String^ imageFileName)
	{
		canvas = startCanvas;
		rGen = startRandom;
		worldWidth = startWorldWidth;
		worldHeight = startWorldHeight;
		thingImage = gcnew Bitmap(imageFileName);

		location.X = rGen->Next(worldWidth);
		location.Y = rGen->Next(worldHeight);

		speed = 2;

		radius = thingImage->Width / 2;
	}

void Thing::Move()
	{
		if(rGen->Next(100) > 90) ChangeRandomDirection();

		if(location.X < 0 || location.X + width > worldWidth || location.Y < 0 || location.Y + height > worldHeight)
			ChangeRandomDirection();

		double radiansAngle = angle * 0.01745; // convert degrees to radians PI / 180
		
		location.X += Math::Cos(radiansAngle) * speed;
		location.Y += Math::Sin(radiansAngle) * speed;
	}

void Thing::ChangeRandomDirection()
	{
		int newAngle = rGen->Next(361);

		while(newAngle == angle)
			newAngle = rGen->Next(361);

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
		return 0;
	}
