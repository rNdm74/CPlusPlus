#include "StdAfx.h"
#include "FrameManager.h"

FrameManager::FrameManager()
{
		playerList = CreateFrameArrayFromFile
		(
			"player",
			gcnew array<Point>
			{
				Point(0,14),		// Idle
				Point(15,29),		// Hurt
				Point(30,110),		// Boss Hurt
				Point(111,185),		// Lesser Ice
				Point(186,242),		// Greater Ice
				Point(243,260),		// Walk
				Point(261,290),		// Basic Attack
				Point(291,327),		// Dodge
				Point(328,383),		// Electric Storm
				Point(384,425),		// Heavy Attack
				Point(426,472),		// Whirlwind Attack
				Point(473,499)		// Heal		 
			 }
		);

		cocoonList = CreateFrameArrayFromFile
		(
			"cocoon",
			gcnew array<Point>
			{
				Point(0,22),		// Idle
				Point(23,71),		// Hurt
				Point(72,104),		// Desecrate
				Point(105,158),		// Tentishock
				Point(159,215),		// Oil Spill
				Point(216,249)		// Killed
			} 
		);

		perunaList = CreateFrameArrayFromFile
		(
			"peruna",
			gcnew array<Point>
			{
				Point(0,12),		// Idle
				Point(13,22),		// Hurt
				Point(23,47),		// Desecrate
				Point(48,72),		// Tentishock
				Point(73,91),		// Oil Spill
				Point(92,105)		// Killed
			}
		);

		fluppitList = CreateFrameArrayFromFile
		(
			"fluppit",
			gcnew array<Point>
			{
				Point(0,7),			// Idle
				Point(7,46),		// Hurt
				Point(46,75),		// Desecrate
				Point(75,97),		// Tentishock
				Point(97,107),		// Oil Spill
				Point(108,125)		// Killed
			}
		);
		
		floppitList = CreateFrameArrayFromFile
		(
			"floppit",
			gcnew array<Point>
			{
				Point(0,7),			// Idle
				Point(7,46),		// Hurt
				Point(46,75),		// Desecrate
				Point(75,97),		// Tentishock
				Point(97,107),		// Oil Spill
				Point(108,125)		// Killed
			}
		);

		makhanaList = CreateFrameArrayFromFile
		(
			"makhana",
			gcnew array<Point>
			{
				Point(0,22),		// Idle
				Point(23,60),		// Hurt
				Point(61,134),		// Desecrate
				Point(135,188),		// Tentishock
				Point(189,259),		// Oil Spill
				Point(260,303)		// Killed
			}
		);
}

array<int, 3>^ FrameManager::CreateFrameArrayFromFile(String^ fileName, array<Point>^ spriteSheetState)
{
		 StreamReader^ reader = gcnew StreamReader(fileName + ".map");

		 array<int, 3>^ spriteSheetData = gcnew array<int,3>(spriteSheetState->Length, 81, 4);	

		 for(int dim0 = 0; dim0 < spriteSheetData->GetLength(0); dim0++) // Sprite state
		 {
			int end = spriteSheetState[dim0].Y - spriteSheetState[dim0].X;
	 
			for(int dim1 = 0; dim1 < end; dim1++) // N Frames
			{			
				String^ line = reader->ReadLine();

				if(line != nullptr)
				{
					array<String^>^ items = line->Split(',');

					for(int dim2 = 0; dim2 < spriteSheetData->GetLength(2); dim2++) // X, Y, WIDTH, HEIGHT
					{
						spriteSheetData[dim0, dim1, dim2] = (int::Parse(items[dim2]));
					}
				}	

				delete line;	// Clean up
			}
		 }

		 return spriteSheetData;
}

ArrayList^ FrameManager::CreateFrameList(array<int, 3>^ spriteSheetData)
{
		ArrayList^ list = gcnew ArrayList();

		 for(int i = 0; i < spriteSheetData->GetLength(0); i++)
		 {
			 ArrayList^ framesList = gcnew ArrayList();

			 for(int j = 0; j < spriteSheetData->GetLength(1); j++)
			 {
				 if(spriteSheetData[i,j,0] != 0)
				 {
					 framesList->Add
					 (
						 gcnew array<int>
						 {
							 spriteSheetData[i,j,X],
							 spriteSheetData[i,j,Y],
							 spriteSheetData[i,j,WIDTH],
							 spriteSheetData[i,j,HEIGHT]						 
						 }
					 );
				 }
			 }

			 list->Add(framesList);

			 framesList = nullptr;
			 delete framesList;
		 }

		 return list;
}

void FrameManager::GarbageCollect()
{
	playerList = nullptr;
	floppitList = nullptr;
	fluppitList = nullptr;
	perunaList = nullptr;
	cocoonList = nullptr;
	makhanaList = nullptr;

	playerState = nullptr;
	floppitState = nullptr;
	fluppitState = nullptr;
	perunaState = nullptr;
	cocoonState = nullptr;
	makhanaState = nullptr;

	delete playerList;
	delete floppitList;
	delete fluppitList;
	delete perunaList;
	delete cocoonList;
	delete makhanaList;

	delete playerState;
	delete floppitState;
	delete fluppitState;
	delete perunaState;
	delete cocoonState;
	delete makhanaState;

	GC::GetTotalMemory(true);
	GC::Collect(0);
}