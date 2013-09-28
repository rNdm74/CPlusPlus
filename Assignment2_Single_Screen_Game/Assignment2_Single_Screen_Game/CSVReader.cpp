#include "StdAfx.h"
#include "CSVReader.h"

CSVReader::CSVReader()
	{
		tileMap = populateMap("tilemap.csv");
		objectMap = populateMap("objectmap.csv");		
	}

array<int,2>^ CSVReader::populateMap(String^ filename)
{
	array<int,2>^ map;

	reader = gcnew StreamReader(filename);		

	map = gcnew array<int,2>(N_ROWS, N_COLS);

	// while there is something to read		
	for (int row = 0; !reader->EndOfStream; row++)
	{
		// the reader will grab a line from the file
		String^ line = reader->ReadLine();

		if(line != "")
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
