#include "StdAfx.h"
#include "Grid.h"

Grid::Grid(Point location, Graphics^ dbGraphics)
	{		
		gridLocation = location;
		graphics = dbGraphics;

		playerScore = 0;

		gridData = gcnew array<Cell^, 2>(N_COLS,N_ROWS);
		
		brush = gcnew SolidBrush(Color::White);

		pfc = gcnew PrivateFontCollection();
		pfc->AddFontFile("PressStart2P.ttf");
		font = gcnew Font(pfc->Families[0], 16, FontStyle::Regular);

		//font = gcnew Font("Consolas", 28);
		fontBrush = gcnew SolidBrush(Color::CornflowerBlue);

		blocks = gcnew array<Point>(4);

		for(int col = 0; col < N_COLS; col++)
		{
			for(int row = 0; row < N_ROWS; row++)
			{
				gridData[col, row] = gcnew Cell(Color::Black);
			}
		}		
	}

void Grid::draw()
	{
		

		for(int col = 0; col < N_COLS; col++)
		{			
			Cell^ southWall = gridData[col, 24];
			southWall->setSolid(true);
			southWall = gridData[col, 25];
			southWall->setSolid(true);

			for(int row = 0; row < N_ROWS; row++)
			{
				Cell^ westWall = gridData[0, row];
				westWall->setSolid(true);
				westWall = gridData[1, row];
				westWall->setSolid(true);	

				Cell^ eastWall = gridData[13, row];
				eastWall->setSolid(true);
				eastWall = gridData[14, row];
				eastWall->setSolid(true);

				Cell^ cell = gridData[col, row];
				
				graphics->FillRectangle
				(
				gcnew SolidBrush((cell->isSolid()) ? cell->getColor() : Color::WhiteSmoke), 
					gridLocation.X + col * CELL_SIZE,
					gridLocation.Y + row * CELL_SIZE,
					CELL_SIZE,
					CELL_SIZE
				);

				//graphics->DrawString
				//(
				//	//col + "," + row, 
				//	"" + cell->isBlock(),
				//	font, 
				//	fontBrush, 
				//	gridLocation.X + col * CELL_SIZE, 
				//	gridLocation.Y + row * CELL_SIZE
				//);
			}
		}

		graphics->DrawString
		(
			//col + "," + row, 
			"LEVEL:	0\n\n" + 
			"LINES:	0\n\n" + 
			"SCORE:	" + playerScore.ToString() + 
			"\n\n\n\n\n" +
			"HELP\n\n"+
			"LEFT:\n\n"+
			"RIGHT:\n\n"+
			"UP:ROTATE\n\n"+
			"DOWN:DROP\n\n\n\n"+
			"NEXT:",
			font, 
			fontBrush, 
			50, 
			50
		);
	}

void Grid::update()
	{
		for(int col = 0; col < N_COLS; col++)
		{
			for(int row = 0; row < N_ROWS; row++)
			{
				if(isRowFull(row))
				{
					deleteRow(row);
					playerScore += 100;
				}					
			}
		}		
	}

void Grid::drawOneSquare(int col, int row,  Color color)
	{
		graphics->FillRectangle
		(
			gcnew SolidBrush(Color::Aquamarine), 
			gridLocation.X + col * CELL_SIZE,
			gridLocation.Y + row * CELL_SIZE,
			CELL_SIZE,
			CELL_SIZE
		);		
	}

bool Grid::isRowFull(int rowNumber)
	{
		bool fullRow = true;
		
		for (int col = 2; col < 13; col++)
			if (!gridData[col, rowNumber]->isBlock())
				fullRow = false;

		return fullRow;						
	}

void Grid::deleteRow(int rowNumber)
	{
		int col;
		int row;

		//to delete row r, work up from that row, moving each row down one
		for (row = rowNumber; row >= 1; row--)
		{
			for (col=2; col < 13; col++)
			{
				gridData[col, row]->setSolid(gridData[col, row - 1]->isSolid());
				gridData[col, row]->setBlock(gridData[col, row - 1]->isBlock());
				gridData[col, row]->setColor(gridData[col, row - 1]->getColor());
			}
		}		
	}