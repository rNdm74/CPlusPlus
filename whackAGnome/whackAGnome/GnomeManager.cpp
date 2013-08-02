#include "StdAfx.h"
#include "GnomeManager.h"

GnomeManager::GnomeManager(Graphics^ g, int gnomeCount)
	{
		gnomes = gcnew array<Gnome^>(gnomeCount);

		rGen = gcnew Random();
		
		for(int i = 0; i < gnomes->Length; i++){
			gnomes[i] = gcnew Gnome(g, Point(rGen->Next(609), rGen->Next(424)));
		}
	}

void GnomeManager::drawAllGnomes()
	{
		for(int i = 0; i < gnomes->Length; i++){
			gnomes[i]->draw();
		}		
	}

void GnomeManager::drawOneGnome(int index)
	{
		gnomes[index]->draw();		
	}

void GnomeManager::eraseAllGnomes()
	{
		gnomes->Clear(gnomes, 0 , gnomes->Length);
				
	}

void GnomeManager::eraseOneGnome(int index)
	{
		gnomes->Clear(gnomes, index, 1);
	}

bool GnomeManager::hitGnome(int index, Point p)
	{
		return true;
	}

 