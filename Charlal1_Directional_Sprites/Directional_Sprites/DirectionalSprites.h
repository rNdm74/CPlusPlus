#pragma once

#include "Chicken.h"
#include "Player.h"
#include "Sprite.h"
#include "SpriteList.h"
#include "TileMap.h"
#include "Viewport.h"
#include "CsvReader.h"

namespace Directional_Sprites {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	#define UPDATE 1
	#define KNIGHT_FRAMES 8
	#define CHICKEN_FRAMES 8


	/// <summary>
	/// Summary for Directional_Sprites
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class DirectionalSprites : public System::Windows::Forms::Form
	{
	public:
		DirectionalSprites(void)
		{
			InitializeComponent();
			dbBitmap = nullptr;
			dbGraphics = nullptr;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DirectionalSprites()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Viewport^ viewport;

		Graphics^ canvas;

		Graphics^ dbGraphics;

		Bitmap^ dbBitmap;

		Image^ background;

		TileMap^ tileMap;

		SpriteList^ spriteList;

		Player^ knight;

		array<Chicken^>^ chickens;
		
		bool collision;

		Random^ rGen;

		CsvReader^ reader;
	
		long gameTime;
	private: System::Windows::Forms::Label^  label1;







		private: System::Windows::Forms::Timer^  clock;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->clock = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// clock
			// 
			this->clock->Enabled = true;
			this->clock->Interval = 1;
			this->clock->Tick += gcnew System::EventHandler(this, &DirectionalSprites::clock_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(681, 56);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// DirectionalSprites
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1008, 729);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"DirectionalSprites";
			this->ShowIcon = false;
			this->Text = L"Directional Sprites";
			this->Load += gcnew System::EventHandler(this, &DirectionalSprites::DirectionalSprites_Load);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &DirectionalSprites::DirectionalSprites_KeyUp);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &DirectionalSprites::DirectionalSprites_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

		private: System::Void DirectionalSprites_Load(System::Object^  sender, System::EventArgs^  e) {
				    //=================================================
					// Create the csv file reader
					//=================================================
					reader = gcnew CsvReader();

					//=================================================
					// Create canvas from form
					//================================================= 
					canvas = CreateGraphics();

					//=================================================
					// Create graphics size of the screen
					//=================================================
					dbBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);
					 
					//=================================================
					// Grab its Graphics
					//=================================================
					dbGraphics = Graphics::FromImage(dbBitmap);
					
					//=================================================
					// Create random
					//=================================================
					rGen = gcnew Random();

					//=================================================
					// Create background
					//=================================================
					tileMap = gcnew TileMap(dbGraphics, reader->getTileMap());

					//=================================================
					// Create viewport
					//=================================================
					viewport = gcnew Viewport(0, 0, V_COLS, V_ROWS, tileMap, dbGraphics);

					//=================================================
					// Create spritelist
					//=================================================
					spriteList = gcnew SpriteList(viewport);

					Rectangle mapRect = tileMap->getMapBounds();

					//=================================================
					// Create knight
					//=================================================
					knight = gcnew Player
					(
						tileMap,
						WRAP,
						dbGraphics,
						gcnew array<String^>
						{
							"Knight Walk North 8.bmp",
							"Knight Walk East 8.bmp",							
							"Knight Walk South 8.bmp",
							"Knight Walk West 8.bmp"
						},
						KNIGHT_FRAMES,
						rGen,
						Point(mapRect.Width / 2 - 50, mapRect.Height / 2 - 50),
						viewport
					);
					
					knight->setWalking(false);
				
					//=================================================
					// Create chickens
					//=================================================
					chickens = gcnew array<Chicken^>(10);				

					for(int c = 0; c < chickens->Length; c++)
					{
						chickens[c] = gcnew Chicken
						(
							tileMap,
							BOUNCE,
							dbGraphics,
							gcnew array<String^>
							{
								"Little Chicken Walk North 8.bmp",								
								"Little Chicken Walk East 8.bmp",
								"Little Chicken Walk South 8.bmp",
								"Little Chicken Walk West 8.bmp"
							},
							CHICKEN_FRAMES,
							rGen,
							Point(rGen->Next(260, 800), rGen->Next(260, 300)),
							viewport
						);
					}

					// Adds all game characters to the spritelist
					for(int c = 0; c < chickens->Length; c++)
						spriteList->add(chickens[c]);

					spriteList->add(knight);
				 }

		private: System::Void DirectionalSprites_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
						 //=================================================
						 // Handle key down event
						 //=================================================
						 if(e->KeyCode==Keys::Up ||e->KeyCode==Keys::Down || e->KeyCode==Keys::Left || e->KeyCode==Keys::Right)
							 knight->setWalking(true);


						 if(e->KeyCode==Keys::Up)
						 {
							knight->setBearing(NORTH);
						 }

						 if(e->KeyCode==Keys::Down)
						 {
							knight->setBearing(SOUTH);
						 }

						 if(e->KeyCode==Keys::Right)
						 {
							knight->setBearing(EAST);
						 }

						 if(e->KeyCode==Keys::Left)
						 {
							 knight->setBearing(WEST);
						 }

						 
					 }

		private: System::Void DirectionalSprites_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
						//=================================================
						// Handle key up event
						//=================================================
						knight->setWalking(false);
					 }		
		private: System::Void clock_Tick(System::Object^  sender, System::EventArgs^  e) {
						label1->Text = knight->getXPos() + "," + knight->getYPos();
						
						//=================================================
						// Move knight
						//=================================================
						//knight->move(viewport->getViewportWorldX(), viewport->getViewportWorldY());

						//=================================================
						// Set viewports position on player
						//=================================================
						// Gets knights center
						int knightX = knight->getXPos() + (knight->getWidth() / 2);
						int knightY = knight->getYPos() + (knight->getHeight() / 2);

						viewport->moveRelativeToPlayer(knightX, knightY);						
																		
						//=================================================
						// Updates sprites animation
						//=================================================
						spriteList->update();

						
						//=================================================
						// NPC AI
						//=================================================
						for(int c = 0; c < chickens->Length; c++)
							chickens[c]->wander();

						//=================================================
						// Draw viewport to canvas 
						//=================================================
						
						viewport->viewportDraw(knightX, knightY);

						//=================================================
						// Draw sprites to canvas
						//=================================================
						spriteList->renderSprites(viewport->getViewportWorldX(), viewport->getViewportWorldY());
												
						//=================================================
						// Make buffer visible 
						//=================================================
						canvas->DrawImage(dbBitmap, ClientRectangle);
					 }
};
}

