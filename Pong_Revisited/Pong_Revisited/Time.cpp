#include "StdAfx.h"
#include "Time.h"


void Time::update()
{
	lastTime = currentTime;
    currentTime = getTime();
}

void Time::init()
{
	lastTime = getTime();
    currentTime = getTime();
}

