#pragma once

#include "GameMenu.h"
#include "GamePlay.h"
#include "GameOver.h"

namespace Tetris_Assignment {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Text;

	

	/// <summary>
	/// Summary for Tetris
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Tetris : public System::Windows::Forms::Form
	{
	public:
		Tetris(void)
		{
			InitializeComponent();
			dbBitmap = nullptr;
			dbGraphics = nullptr;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Tetris()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Graphics^ dbGraphics;
		Bitmap^ dbBitmap;

		PrivateFontCollection^ pfc;
		System::Drawing::Font^ font;
		Brush^ brush;

		GameMenu^ gameMenu;
		GamePlay^ gamePlay;
		GameOver^ gameOver;

		EGameState gameState;

	private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Tetris
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1008, 729);
			this->DoubleBuffered = true;
			this->MaximumSize = System::Drawing::Size(1024, 768);
			this->MinimumSize = System::Drawing::Size(1024, 736);
			this->Name = L"Tetris";
			this->ShowIcon = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Tetris";
			this->Load += gcnew System::EventHandler(this, &Tetris::Tetris_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Tetris::Tetris_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Tetris::Tetris_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Tetris_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
					// Refresh screen
					Invalidate();

					// Clear background
					dbGraphics->Clear(BackColor);

					// Update gamestate
					switch(gameState)
					{
						case MENU:
							// Update gamemenu	 
							gameMenu->update();
					
							// Render gamemenu
							gameMenu->render();
							break;

						case PLAY:
							// Game ends	
							if(gamePlay->isGameOver()) gameState = OVER;

							// Update gameplay
							gamePlay->update();
					
							// Render gameplay
							gamePlay->render();
							break;

						case OVER:
							// Update gameover	
							gameOver->update();
					
							// Render gameover
							gameOver->render();
							break;
					}
										
					// Make buffer visible
					e->Graphics->DrawImage(dbBitmap, 0, 0);										
				 }

	private: System::Void Tetris_Load(System::Object^  sender, System::EventArgs^  e) {
					// Create graphics size of the screen
					dbBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);

					// Grab its Graphics
					dbGraphics = Graphics::FromImage(dbBitmap);

					// Load game font
					pfc = gcnew PrivateFontCollection();
					pfc->AddFontFile("PressStart2P.ttf");

					// Create font
					font = gcnew System::Drawing::Font(pfc->Families[0], 16, FontStyle::Regular);
					
					// Create font brush
					brush = gcnew SolidBrush(Color::CornflowerBlue);

					// Create Game
					gameMenu = gcnew GameMenu(dbGraphics, ClientRectangle, font, brush);
					gamePlay = gcnew GamePlay(dbGraphics, ClientRectangle, font, brush);
					gameOver = gcnew GameOver(dbGraphics, ClientRectangle, font, brush);

					// Set initial game state
					gameState = MENU;
				 }
	private: System::Void Tetris_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
					// Update gamestate
					switch(gameState)
					{
						case MENU:														
							gamePlay = gcnew GamePlay(dbGraphics, ClientRectangle, font, brush);							
							
							// Update gamemenu
							gameState = gameMenu->input(e);	
							break;

						case PLAY:							
							// Update gameplay								
							gameState = gamePlay->input(e);
							break;

						case OVER:
							// Update gameover								
							gameState = gameOver->input(e);
							break;
					}					
				 }
};
}

