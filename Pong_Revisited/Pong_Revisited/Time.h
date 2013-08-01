#pragma once

#include <time.h>
#include <ctime>

ref class Time
{
private:
	static const float DAMPING = 18000000;
	static long currentTime;
	static long lastTime;

public:
	static long getTime() { return time(0); }
	static float getDelta() { return (currentTime - lastTime) / DAMPING; }
	static void update();
	static void init();
};
