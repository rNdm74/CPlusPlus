#pragma once

#include "GnomeManager.h"

namespace whackAGnome {

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

	private: System::Windows::Forms::Button^  start_Button;
	private: System::Windows::Forms::Label^  hamsters_Label;
	private: System::Windows::Forms::Label^  hamsters_Value;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Timer^  tick;
	
	private:
		Random^ rGen;
		
		GnomeManager^ gnomeManager;

		int gnomeCount;
		int selectGnome;
		int showGnome;

		Graphics^ mainCanvas;
		Graphics^ dbGraphics;
	    Graphics^ canvas;

		Bitmap^ dbBitmap;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
		this->components = (gcnew System::ComponentModel::Container());
		this->start_Button = (gcnew System::Windows::Forms::Button());
		this->hamsters_Label = (gcnew System::Windows::Forms::Label());
		this->hamsters_Value = (gcnew System::Windows::Forms::Label());
		this->tick = (gcnew System::Windows::Forms::Timer(this->components));
		this->SuspendLayout();
		// 
		// start_Button
		// 
		this->start_Button->Location = System::Drawing::Point(13, 13);
		this->start_Button->Name = L"start_Button";
		this->start_Button->Size = System::Drawing::Size(75, 23);
		this->start_Button->TabIndex = 0;
		this->start_Button->Text = L"START";
		this->start_Button->UseVisualStyleBackColor = true;
		this->start_Button->Click += gcnew System::EventHandler(this, &Game::start_Button_Click);
		// 
		// hamsters_Label
		// 
		this->hamsters_Label->AutoSize = true;
		this->hamsters_Label->Location = System::Drawing::Point(108, 18);
		this->hamsters_Label->Name = L"hamsters_Label";
		this->hamsters_Label->Size = System::Drawing::Size(54, 13);
		this->hamsters_Label->TabIndex = 1;
		this->hamsters_Label->Text = L"Hamsters:";
		// 
		// hamsters_Value
		// 
		this->hamsters_Value->AutoSize = true;
		this->hamsters_Value->Location = System::Drawing::Point(168, 18);
		this->hamsters_Value->Name = L"hamsters_Value";
		this->hamsters_Value->Size = System::Drawing::Size(13, 13);
		this->hamsters_Value->TabIndex = 2;
		this->hamsters_Value->Text = L"0";
		// 
		// tick
		// 
		this->tick->Tick += gcnew System::EventHandler(this, &Game::tick_Tick);
		// 
		// Game
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::White;
		this->ClientSize = System::Drawing::Size(593, 386);
		this->Controls->Add(this->hamsters_Value);
		this->Controls->Add(this->hamsters_Label);
		this->Controls->Add(this->start_Button);
		this->DoubleBuffered = true;
		this->Name = L"Game";
		this->ShowIcon = false;
		this->Text = L"Whack a Gnome";
		this->Load += gcnew System::EventHandler(this, &Game::Game_Load);
		this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Game::Game_Paint);
		this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Game::Game_MouseDown);
		this->ResumeLayout(false);
		this->PerformLayout();

			}
#pragma endregion

	private: System::Void Game_Load(System::Object^  sender, System::EventArgs^  e) {
				 // Create graphics size of the screen
				 dbBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);

				 // Set amount of gnomes
				 gnomeCount = 10;

				 rGen = gcnew Random();

				 // Grab its Graphics
                 dbGraphics = Graphics::FromImage(dbBitmap); 

				 // Create gnomes
				 gnomeManager = gcnew GnomeManager(dbGraphics, gnomeCount);					
				 }

	private: System::Void Game_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 }

	private: System::Void start_Button_Click(System::Object^  sender, System::EventArgs^  e) {
					// Clear background
					dbGraphics->Clear(Color::White);

					// Create new set of gnomes
					gnomeManager = gcnew GnomeManager(dbGraphics, gnomeCount);

					// Redraw
					Invalidate();
				 }

	private: System::Void Game_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {					 
					 // Draw game objects to buffer
					 gnomeManager->drawAllGnomes();
					 
					 // Make buffer visible
					 e->Graphics->DrawImage(dbBitmap, 0, 0);
				 }
private: System::Void tick_Tick(System::Object^  sender, System::EventArgs^  e) {
				
			 }
};
}

