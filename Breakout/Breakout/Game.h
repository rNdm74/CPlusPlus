#pragma once

#include "GameManager.h"

#define NCOLS 10
#define NROWS 4

namespace Breakout {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Game
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Game : public System::Windows::Forms::Form
	{
	public:
		Game(void)
		{
			InitializeComponent();
			dbBitmap = nullptr;
			dbGraphics = nullptr;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Game()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Graphics^ dbGraphics;
		Bitmap^ dbBitmap;

		GameManager^ gManager;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(624, 442);
			this->DoubleBuffered = true;
			this->Name = L"Game";
			this->ShowIcon = false;
			this->Text = L"Breakout";
			this->Load += gcnew System::EventHandler(this, &Game::Game_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Game::Game_Paint);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Game::Game_KeyUp);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Game::Game_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: Game::Void updateLabels() {
				if(gManager->getGameRunning())
					Text = "Score: " + (gManager->getBrokenBrickCount() * 10) + "  Lifes: " + gManager->getLifes();

				if(gManager->getBrokenBrickCount() >= (NCOLS * NROWS))
				{
					gManager->setGameRunning(false);
					Text = "You Win !";
				}

				if(gManager->checkGameOver())
				{
					gManager->setGameRunning(false);
					Text = "You Lose !";
				}

				if(gManager->checkBallOutOfBounds())
				{
					gManager->resetGame(SizeF(ClientSize));					
				}
			 }
	private: System::Void Game_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
					// Refresh screen
					Invalidate();

					// Clear background
					dbGraphics->Clear(BackColor);

					// Update labels
					updateLabels();

					// Update game	
					gManager->update();

					// Render game
					gManager->render();
					
					// Make buffer visible
					e->Graphics->DrawImage(dbBitmap, 0, 0);
				 }
	private: System::Void Game_Load(System::Object^  sender, System::EventArgs^  e) {
					// Create graphics size of the screen
					dbBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);

					// Grab its Graphics
					dbGraphics = Graphics::FromImage(dbBitmap);

					// Create game
					gManager = gcnew GameManager(dbGraphics, ClientSize, NCOLS, NROWS);

					// Set gamestate 
					gManager->setGameRunning(true);
				 }
	private: System::Void Game_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
					gManager->keyDown(e);	
				 }
	private: System::Void Game_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
					gManager->keyUp(e);
				 }	
		};
}

