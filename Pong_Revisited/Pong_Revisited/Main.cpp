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
	g->Clear(Color::Black);
	game->render(g);

}
