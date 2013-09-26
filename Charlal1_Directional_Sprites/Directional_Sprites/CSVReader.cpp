#include "StdAfx.h"
#include "CSVReader.h"

CSVReader::CSVReader()
	{
		reader = gcnew StreamReader("tilemap.csv");		

		tileMap = gcnew array<int,2>(N_ROWS, N_COLS);

		// while there is something to read		
		for (int row = 0; !reader->EndOfStream; row++)
		{
			// the reader will grab a line from the file
			String ^x = reader->ReadLine();

			// populates the items array with split results from the csv file
			items = x->Split(',');

			// populates tileMaps columns with each value from the items array
			for (int col = 0; col < N_COLS; col++)
			{
				tileMap[row, col] = (int::Parse(items[col])) - 1; // minus 1 to make map zero based
			}
		}		
	}
