#include "StdAfx.h"
#include "Main.h"

Main::Main()
{
	game = gcnew Game();
}

void Main::update()
{
	game->update();
}

void Main::render(Graphics^ g)
{
	game->render(g);
}
