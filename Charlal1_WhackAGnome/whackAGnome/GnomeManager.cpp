#include "StdAfx.h"
#include "GnomeManager.h"

GnomeManager::GnomeManager(Graphics^ g, int gnomeCount)
	{
		const int PADDING = 100;

		// Init gnomes array
		gnomes = gcnew array<Gnome^>(gnomeCount);

		// Init random
		rGen = gcnew Random();

		// Get screen bounds
		int width = g->VisibleClipBounds.Width;
		int height = g->VisibleClipBounds.Height;

		//bounds
		Rectangle r = Rectangle(PADDING, PADDING, width - PADDING*2, height - PADDING*2); 
				
		// Create gnomes
		for(int i = 0; i < gnomes->Length; i++){
			gnomes[i] = gcnew Gnome(g, Point(rGen->Next(r.Width), rGen->Next(r.Height)));
		}
	}

void GnomeManager::drawAllGnomes()
	{
		// Draw all gnomes
		for(int i = 0; i < gnomes->Length; i++){
			if(gnomes[i]->getHit()) gnomes[i]->draw();
		}		
	}

void GnomeManager::drawOneGnome(int index)
	{	
		// Draw one gnome
		if(!gnomes[index]->getHit()) gnomes[index]->draw();		
	}

void GnomeManager::eraseAllGnomes()
	{
		// Erase all gnomes from screen
		for(int i = 0; i < gnomes->Length; i++){
			gnomes[i]->setVisible(false);
		}
	}

void GnomeManager::eraseOneGnome(int index)
	{
		// Erase a gnome from screen
		gnomes[index]->setVisible(false);
	}

void GnomeManager::visibleGnome(int index)
	{
		// Set gnome visible flag
		for(int i = 0; i < gnomes->Length; i++){
			gnomes[i]->setVisible((gnomes[i] == gnomes[index]));
		}
	}

void GnomeManager::hitGnome(Point p)
	{
		// Check if gnome is hit
		for(int i = 0; i < gnomes->Length; i++){
			if(gnomes[i]->getVisible()){
				gnomes[i]->isHit(p);
			}																			
		}		
	}

int GnomeManager::getHitHamsters()
	{
		int count = 0;

		// Count hit gnomes
		for(int i = 0; i < gnomes->Length; i++){
			if(gnomes[i]->getHit()) count++;
		}

		return count;		
	}

bool GnomeManager::isGnomeHamster(int index)
	{
		// Return if gnome is hamster
		return gnomes[index]->getHit();		
	}

 