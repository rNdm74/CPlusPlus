#include "StdAfx.h"
#include "CSVReader.h"

CSVReader::CSVReader(Random^ startRGen)
	{
		rGen = startRGen;
	}

array<int,3>^ CSVReader::getSpriteSheetData(int startObjectNumber)
{
	switch(startObjectNumber)
	{
		case PLAYER:
			return getPlayerMap();;
		case ALIEN_ONE:
			return getPlayerMap();
		case ALIEN_TWO:
			return getAlienMap();
		case ALIEN_THREE:
			return getPlayerMap();
		case ALIEN_FOUR:
			return getAlienMap();
		case RED_FLAG:
			return getItemMap();
		case BLUE_FLAG:
			return getItemMap();
		case YELLOW_FLAG:
			return getItemMap();
	}
}


array<int,2>^ CSVReader::getMap(String^ filename)
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

	array<int,2>^ map;

	reader = gcnew StreamReader(filename);		

	map = gcnew array<int,2>(N_ROWS, N_COLS);

	// while there is something to read		
	for (int row = 0; !reader->EndOfStream; row++)
	{
		// the reader will grab a line from the file
		String^ line = reader->ReadLine();

		if(line != "") // if there is something to read
		{
			// populates the items array with split results from the csv file
			items = line->Split(',');

			// populates tileMaps columns with each value from the items array
			for (int col = 0; col < N_COLS; col++)
			{
				map[row, col] = (int::Parse(items[col])); // minus 1 to make map zero based
			}
		}
	}

	reader->Close();

	return map;
}


array<int,3>^ CSVReader::getMap(String^ filename, int dim0, int dim1, int dim2)
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

	array<int,3>^ map;

	reader = gcnew StreamReader(filename);		

	map = gcnew array<int,3>(dim0, dim1, dim2);	
	
	for(int dim0 = 0; dim0 < map->GetLength(0); dim0++)
	{
		for(int dim1 = 0; dim1 < map->GetLength(1); dim1++)
		{			
			String^ line = reader->ReadLine();

			if(line != "")
			{
				items = line->Split(',');

				for(int dim2 = 0; dim2 < map->GetLength(2); dim2++)
				{
					map[dim0, dim1, dim2] = (int::Parse(items[dim2]));
				}
			}			
		}
	}	

	reader->Close();

	return map;
}
