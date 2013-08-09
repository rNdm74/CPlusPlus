#pragma once

#include "GameBoard.h"

namespace Tetris {

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

		GameBoard^ board;
	private: System::Windows::Forms::Timer^  clock;

	private: System::ComponentModel::IContainer^  components;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
		this->components = (gcnew System::ComponentModel::Container());
		this->clock = (gcnew System::Windows::Forms::Timer(this->components));
		this->SuspendLayout();
		// 
		// clock
		// 
		this->clock->Interval = 1;
		this->clock->Tick += gcnew System::EventHandler(this, &Game::clock_Tick);
		// 
		// Game
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::Black;
		this->ClientSize = System::Drawing::Size(464, 602);
		this->DoubleBuffered = true;
		this->Name = L"Game";
		this->ShowIcon = false;
		this->Text = L"Tetris";
		this->Load += gcnew System::EventHandler(this, &Game::Game_Load);
		this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Game::Game_Paint);
		this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Game::Game_KeyUp);
		this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Game::Game_KeyDown);
		this->ResumeLayout(false);

			}
#pragma endregion
	private: int count;
	private: System::Void Game_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
					// Refresh screen
					Invalidate();

					// Clear background
					dbGraphics->Clear(BackColor);

					// Update Code
					board->update();

					// Render Code
					board->render();
					
					// Make buffer visible
					e->Graphics->DrawImage(dbBitmap, 0, 0);
				 }
	private: System::Void Game_Load(System::Object^  sender, System::EventArgs^  e) {
					// Create graphics size of the screen
					dbBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);

					// Grab its Graphics
					dbGraphics = Graphics::FromImage(dbBitmap);

					board = gcnew GameBoard(ClientRectangle, dbGraphics);

					clock->Enabled = true;
				 }
	private: System::Void clock_Tick(System::Object^  sender, System::EventArgs^  e) {
					//board->update();
					
					//Refresh();
				 }
	private: System::Void Game_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 board->getBoard()->getHead()->setLocation().X += 20;
				 }
	private: System::Void Game_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 }
};
}

