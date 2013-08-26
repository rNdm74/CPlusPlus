#include "StdAfx.h"
#include "GamePlay.h"

GamePlay::GamePlay(Graphics^ dbGraphics, Rectangle clientRectangle, Font^ gameFont, Brush^ fontBrush, Sound^ sound)
		 : Game(dbGraphics, screenBounds, gameFont, fontBrush, sound)
{
	rGen = gcnew Random();
	
	background = Image::FromFile("background5.jpg");

	grid = gcnew GameGrid(Point(302,-30), graphics, sound, GAMEGRID_COLS, GAMEGRID_ROWS);
	preview = gcnew Grid(Point(757,480), graphics, PREVIEW_COLS, PREVIEW_ROWS); 

	tetriminoStats = gcnew array<int>(7);
	tetriminoTypes = gcnew array<ETetriminoType>
	{
		I_TETRIMINO,
		J_TETRIMINO, 
		L_TETRIMINO, 
		O_TETRIMINO, 
		S_TETRIMINO, 
		T_TETRIMINO,
		Z_TETRIMINO
	};

	tetriminoInPlay = generateTetrimino();
	nextTetrimino = generateTetrimino();

	waitTime = 50;
}

void GamePlay::moveLeft()
{
	tetriminoInPlay->moveLeft();
	gSound->play("SFX_PieceMoveLR.wav");
}

void GamePlay::moveRight()
{
	tetriminoInPlay->moveRight();
	gSound->play("SFX_PieceMoveLR.wav");
}

void GamePlay::moveDown()
{
	tetriminoInPlay->moveDown();
	gSound->play("SFX_PieceFall.wav");
}

void GamePlay::moveRotate()
{
	tetriminoInPlay->moveRotate();	
}

EGameState GamePlay::input(KeyEventArgs^  e)
{
	Point p = tetriminoInPlay->getCurPosition()[0];

	if(p.Y > 2)
	{
		if(e->KeyCode == Keys::Left) moveLeft();
		if(e->KeyCode == Keys::Right) moveRight();
						
		if(e->KeyCode == Keys::Up) moveRotate();	
		if(e->KeyCode == Keys::Down) moveDown();
		if(e->KeyCode == Keys::S) gSound->Play = !gSound->Play;
		if(e->KeyCode == Keys::Space)
		{
			setDrop(true);
			gSound->play("SFX_PieceHardDrop.wav");			
		}
	}

	if(e->KeyCode == Keys::Escape) return MENU;

	return PLAY;
}

void GamePlay::update()
{
	grid->update();
	
	if(tetriminoInPlay->isPlaced())
	{
		setDrop(false);
		updateStats(tetriminoInPlay->getTetriminoType());
		//random block gen
		tetriminoInPlay = nextTetrimino;
		nextTetrimino = generateTetrimino();
		//blockInPlay++;
	}

	if(drop) tetriminoInPlay->moveDown();		
		
	if(time > waitTime - (grid->getPlayerLevel()*2))
	{
		tetriminoInPlay->moveDown();
		//if(!drop && tetriminoInPlay->getCurPosition()[3].Y > 2)
			//gcnew PlaySound("SFX_PieceFall.wav");
		
		time = 0;
	}

	time++;

	
}

void GamePlay::render()
{
	graphics->DrawImageUnscaledAndClipped(background, screenBounds);

	grid->draw();

	tetriminoInPlay->draw();

	nextTetrimino->drawPreview();
	
	graphics->DrawString
	( 
		"LEVEL:	"+ grid->getPlayerLevel().ToString() +
		"\n\n"+ 
		"LINES:	"+ grid->getPlayerLines().ToString() +
		"\n\n"+ 
		"SCORE:	"+ grid->getPlayerScore().ToString() + 
		"\n\n\n\n"+
		"\n\n\n"+
		"HELP"+
		"\n\n\n"+
		"LEFT:MOVE"+
		"\n\n"+
		"RIGHT:MOVE"+
		"\n\n"+
		"DOWN:MOVE"+
		"\n\n"+
		"UP:ROTATE"+
		"\n\n"+		
		"SPACE:DROP"+
		"\n\n"+		
		"ESCAPE:MENU"
		"\n\n"+		
		"S:SOUND " + ((gSound->Play) ? "ON" : "OFF"),
		font, 
		brush, 
		50, 
		50
	);

	graphics->DrawString
	(			 
		"STATISTICS"+
		"\n\n\n"+
		"    I:	"+ tetriminoStats[0] +  
		"\n\n"+ 
		"    J:	"+  tetriminoStats[1] + 
		"\n\n"+ 
		"    L:	"+  tetriminoStats[2] +   
		"\n\n"+
		"    O:	" +  tetriminoStats[3] + 
		"\n\n"+
		"    S:	"+  tetriminoStats[4] + 
		"\n\n"+
		"    T:	"+  tetriminoStats[5] + 
		"\n\n"+
		"    Z:	"+  tetriminoStats[6] + 
		"\n\n\n"+
		"TOTAL:	"+ getTotalStats()+
		"\n\n\n\n"+
		"NEXT",
		font, 
		brush, 
		727, 
		50
	);	
}

void GamePlay::updateStats(ETetriminoType type)
	{		
		for(int i = 0; i < tetriminoTypes->Length; i++)
			if(type == tetriminoTypes[i]) tetriminoStats[i]++;		
	}



Tetrimino^ GamePlay::generateTetrimino()
{
	switch(rGen->Next(tetriminoTypes->Length))
	{
		case 0:
			return gcnew I(Color::FromArgb(ALPHA, Color::Red), grid, preview);
		case 1:
			return gcnew J(Color::FromArgb(ALPHA, Color::Yellow), grid, preview);
		case 2:
			return gcnew L(Color::FromArgb(ALPHA, Color::Magenta), grid, preview);
		case 3:
			return gcnew O(Color::FromArgb(ALPHA, Color::Blue), grid, preview);
		case 4:
			return gcnew S(Color::FromArgb(ALPHA, Color::Cyan), grid, preview);
		case 5:
			return gcnew T(Color::FromArgb(ALPHA, Color::Green), grid, preview);
		case 6:
			return gcnew Z(Color::FromArgb(ALPHA, Color::Orange), grid, preview);
		default:
			return nullptr;
	}
}

bool GamePlay::isGameOver()
{
	for(int pos = 0; pos < tetriminoInPlay->getCurPosition()->Length; pos++)
	{ 
		Point p = tetriminoInPlay->getCurPosition()[pos];

		if(tetriminoInPlay->isPlaced() && p.Y < 3)
		{
			gSound->play("SFX_GameOver.wav");
			return true;
		}
	}

	return false;
}

int GamePlay::getTotalStats()
{
	int total = 0; 

	for(int i=0;i<tetriminoStats->Length; i++)
		total += tetriminoStats[i];
	
	return total;
}
