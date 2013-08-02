#include "StdAfx.h"
#include "GnomeManager.h"

GnomeManager::GnomeManager(Graphics^ g, int gnomeCount)
	{
		gnomes = gcnew array<Gnome^>(gnomeCount);

		rGen = gcnew Random();

		int width = g->VisibleClipBounds.Width;
		int height = g->VisibleClipBounds.Height;
		
		for(int i = 0; i < gnomes->Length; i++){
			gnomes[i] = gcnew Gnome(g, Point(rGen->Next(width), rGen->Next(height)));
		}
	}

void GnomeManager::drawAllGnomes()
	{
		for(int i = 0; i < gnomes->Length; i++){
			if(gnomes[i]->getHit()) gnomes[i]->draw();
		}		
	}

void GnomeManager::drawOneGnome(int index)
	{	
		if(!gnomes[index]->getHit()) gnomes[index]->draw();		
	}

void GnomeManager::eraseAllGnomes()
	{
		for(int i = 0; i < gnomes->Length; i++){
			gnomes[i]->setVisible(false);
		}
	}

void GnomeManager::eraseOneGnome(int index)
	{
		gnomes[index]->setVisible(false);
	}

void GnomeManager::hitGnome(int index, Point p)
	{		
		gnomes[index]->isHit(p);
	}

int GnomeManager::getHamsters()
	{
		int count = 0;

		for(int i = 0; i < gnomes->Length; i++){
			if(gnomes[i]->getHit()) count++;
		}

		return count;		
	}

 