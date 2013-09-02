#pragma once

#include "GameMenu.h"
#include "GamePlay.h"
#include "GameOver.h"
#include "resource.h"

namespace Tetris_Assignment {

	//using namespace System;
	using namespace System::Collections::Generic;
	//using namespace System::ComponentModel;
	//using namespace System::Data;
	//using namespace System::Drawing;
//	using namespace System::Linq;
	using namespace System::Text;
	using namespace System::Windows::Forms;
//	using namespace System::IO;
	//using namespace System::Reflection;
	//using namespace System::Runtime.InteropServices;
	//using namespace System::Drawing::Text;

	using namespace System;
	using namespace System::IO;
	using namespace System::Resources;
	using namespace System::Reflection;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Text;
	using namespace System::Runtime::InteropServices;

	

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
		PrivateFontCollection^ pfc;
		System::Drawing::Font^ font;

		Graphics^ dbGraphics;
		Bitmap^ dbBitmap;

		Sound^ sound;		
		Brush^ brush;
		
		ResourceManager^ rm;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Tetris::typeid));
			this->SuspendLayout();
			// 
			// Tetris
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1008, 730);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(6);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1024, 768);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(1024, 766);
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

					// Updates what game state is updated and drawn to the screen
					switch(gameState)
					{
						case MENU:
							// Update menu screen animation	 
							gameMenu->update();
					
							// Renders gamemenu to the screen
							gameMenu->render();
							break;

						case PLAY:
							// Game ends	
							if(gamePlay->isGameOver()) gameState = OVER;

							// Updates all the gameobjects to play the game
							gamePlay->update();
					
							// Renders gameobjects to the screen
							gamePlay->render();
							break;

						case OVER:								
							//gameOver->update(); // NOT USED
					
							// Renders gamemenu to the screen
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
					
					//// Grab the assembly this is being called from
					Assembly^ assembly = Assembly::GetExecutingAssembly();
					AssemblyName^ assemblyName = assembly->GetName();

					//// Grab the images from the assembly
					rm = gcnew ResourceManager(assemblyName->Name+".Tetris", assembly);
					
					// Create sound player
					sound = gcnew Sound(rm);

					// Load game font
					pfc = gcnew PrivateFontCollection();

					// receive resource stream
					System::IO::Stream^ ms = rm->GetStream("PressStart2P");
					
					//
					System::IntPtr data = Marshal::AllocCoTaskMem(ms->Length);
				 
					// create a buffer to read in to
					array<unsigned char>^ fontdata = gcnew array<unsigned char>(ms->Length);

					// read the font data from the resource
					ms->Read(fontdata, 0, (int)ms->Length);

					// copy the bytes to the unsafe memory block
					Marshal::Copy(fontdata, 0, data, (int)ms->Length);

					// pass the font to the font collection
					pfc->AddMemoryFont(data, (int)ms->Length);

					// close the resource stream
					ms->Close();

					// free up the unsafe memory
					Marshal::FreeCoTaskMem(data);
					
					// Create font
					font = gcnew System::Drawing::Font(pfc->Families[0], 16, FontStyle::Regular);
					
					// Create font brush
					brush = gcnew SolidBrush(Color::CornflowerBlue);
										
					// Create game screen takes a bitmap graphics object 
					// the window size the games font, color and sound
					gameMenu = gcnew GameMenu(rm, dbGraphics, ClientRectangle, font, brush, sound);
					gamePlay = gcnew GamePlay(rm, dbGraphics, ClientRectangle, font, brush, sound);
					gameOver = gcnew GameOver(rm, dbGraphics, ClientRectangle, font, brush, sound);

					// Set initial game state
					gameState = MENU;
				 }
	private: System::Void Tetris_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
					// Update gamestate
					switch(gameState)
					{
						case MENU:	
							if(e->KeyCode == Keys::Enter)
								gamePlay = gcnew GamePlay(rm, dbGraphics, ClientRectangle, font, brush, sound);							
							
							// Sends player input for the menu
							gameState = gameMenu->input(e);	
							break;

						case PLAY:							
							// Sends player input for the main game								
							gameState = gamePlay->input(e);
							break;

						case OVER:
							if(e->KeyCode == Keys::Space)
								gamePlay = gcnew GamePlay(rm, dbGraphics, ClientRectangle, font, brush, sound);							
							
							// Sends player input for the gover over menu								
							gameState = gameOver->input(e);
							break;
					}					
				 }
};
}

