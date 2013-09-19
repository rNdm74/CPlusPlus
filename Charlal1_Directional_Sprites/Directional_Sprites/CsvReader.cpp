#include "StdAfx.h"
#include "csvReader.h"

CsvReader::CsvReader()
	{
		reader = gcnew StreamReader("tilemap.csv");

		tileMap = gcnew array<int,2>(N_ROWS, N_COLS);

		// while there is something to read		
		for (int row = 0; reader->Peek() != -1; row++)
		{
			// the reader will grab a line from the file
			String ^x = reader->ReadLine();

			items = x->Split(',');

			for (int col = 0; col < N_COLS; col++)
			{
				tileMap[row, col] = (int::Parse(items[col])) - 1; // minus 1 to make map zero based
			}
		}		
	}
