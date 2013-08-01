#include "StdAfx.h"
#include "Main.h"

Main::Main(Form^ f)
{
	game = gcnew Game(f);
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
