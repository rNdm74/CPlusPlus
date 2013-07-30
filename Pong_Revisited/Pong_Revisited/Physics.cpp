#include "StdAfx.h"
#include "Physics.h"

bool Physics::checkCollision(GameObject^ o1, GameObject^ o2)
{
    Rectangle rectangle1 = Rectangle((int)o1->getX(), (int)o1->getY(), (int)o1->getWidth(), (int)o1->getHeight());
	Rectangle rectangle2 = Rectangle((int)o2->getX(), (int)o2->getY(), (int)o2->getWidth(), (int)o2->getHeight());
      
	return ( rectangle1.IntersectsWith( rectangle2 ) );
}
