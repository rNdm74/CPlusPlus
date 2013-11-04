#include "StdAfx.h"
#include "FileReader.h"

FileReader::FileReader()
	{		
	}

array<int,3>^ FileReader::getSpriteSheetData(int startObjectNumber)
{
	//
	// Gets the 3 Dimension array that holds 
	// frame data for the sprite used the the game
	//
	return getMap("player.map", 7, 11, 4);
}


array<int,2>^ FileReader::getMap(String^ filename)
{
	/// <summary>
	/// Takes the input of a CSV file and reads it line by line
	///	with each line it is then split using a delimiter.
	///
	/// All of the lines from the CSV file are processed and populate
	///	a 2-Dimensional array.
	///
	/// Once the file is read the populated array is then returned.
	/// </summary>

	StreamReader^ reader = gcnew StreamReader(filename);

	array<int,2>^ map2D = gcnew array<int,2>(N_ROWS, N_COLS);

	// while there is something to read		
	for (int row = 0; !reader->EndOfStream; row++)
	{
		// the reader will grab a line from the file
		String^ line = reader->ReadLine();

		if(line != "") // if there is something to read
		{
			// populates the items array with split results from the csv file
			array<String^>^ items = line->Split(',');

			// populates tileMaps columns with each value from the items array
			for (int col = 0; col < N_COLS; col++)
			{
				map2D[row, col] = (int::Parse(items[col])); // minus 1 to make map zero based
			}
		}

		delete line;	// Clean up
	}

	reader->Close();
	
	reader = nullptr;
	delete reader;	// Clean up

	return map2D;
}


array<int,3>^ FileReader::getMap(String^ filename, int dim0, int dim1, int dim2)
{
	/// <summary>
	/// Takes the input of a CSV file and reads it line by line
	///	with each line it is then split using a delimiter.
	///
	/// All of the lines from the CSV file are processed and populate
	///	a 2-Dimensional array.
	///
	/// Once the file is read the populated array is then returned.
	/// </summary>

	StreamReader^ reader = gcnew StreamReader(filename);		

	array<int,3>^ map3D = gcnew array<int,3>(dim0, dim1, dim2);	
	
	for(int dim0 = 0; dim0 < map3D->GetLength(0); dim0++) // Sprite state
	{
		for(int dim1 = 0; dim1 < map3D->GetLength(1); dim1++) // N Frames
		{			
			String^ line = reader->ReadLine();

			if(line != "")
			{
				array<String^>^ items = line->Split(',');

				for(int dim2 = 0; dim2 < map3D->GetLength(2); dim2++) // X, Y, WIDTH, HEIGHT
				{
					map3D[dim0, dim1, dim2] = (int::Parse(items[dim2]));
				}
			}	

			delete line;	// Clean up
		}
	}	

	reader->Close();
	
	reader = nullptr;
	delete reader;  // Clean up

	return map3D;
}
