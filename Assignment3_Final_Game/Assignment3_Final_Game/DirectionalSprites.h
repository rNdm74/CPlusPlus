#pragma once

#include "Sprite.h"
#include "SpriteList.h"
#include "TileMap.h"

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
		Graphics^ canvas;

		Graphics^ dbGraphics;		
		Bitmap^ dbBitmap;

		Image^ background;

		TileMap^ tileMap;

		SpriteList^ spriteList;

		Sprite^ knight;

		array<Sprite^>^ chickens;
		
		bool collision;

		Random^ rGen;
	
		long gameTime;

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
		this->SuspendLayout();
		// 
		// clock
		// 
		this->clock->Enabled = true;
		this->clock->Interval = 1;
		this->clock->Tick += gcnew System::EventHandler(this, &DirectionalSprites::clock_Tick);
		// 
		// DirectionalSprites
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::DarkOliveGreen;
		this->ClientSize = System::Drawing::Size(624, 442);
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

			}
#pragma endregion
	

		private: System::Void DirectionalSprites_Load(System::Object^  sender, System::EventArgs^  e) {
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
					tileMap = gcnew TileMap(dbGraphics);
					tileMap->generateTileMap();
					//background = Image::FromFile("ground.png");

					//=================================================
					// Create SpriteList
					//=================================================
					spriteList = gcnew SpriteList();

					//=================================================
					// Create knight
					//=================================================
					knight = gcnew Sprite
					(
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
						Point(ClientRectangle.Width / 2, ClientRectangle.Height / 2),
						ClientRectangle
					);
					
					knight->setWalking(false);
				
					//=================================================
					// Create chickens
					//=================================================
					chickens = gcnew array<Sprite^>(20);

					for(int c = 0; c < chickens->Length; c++)
					{
						chickens[c] = gcnew Sprite
						(
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
							Point(rGen->Next(ClientRectangle.Width), rGen->Next(ClientRectangle.Height)),
							ClientRectangle
						);
					}

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
							tileMap->moveMapDown();
						 }

						 if(e->KeyCode==Keys::Down)
						 {
							knight->setBearing(SOUTH);
							tileMap->moveMapUp();
						 }

						 if(e->KeyCode==Keys::Right)
						 {
							knight->setBearing(EAST);
							tileMap->moveMapLeft();
						 }

						 if(e->KeyCode==Keys::Left)
						 {
							 knight->setBearing(WEST);
							 tileMap->moveMapRight();
						 }

						 if(e->KeyCode==Keys::W);
							 
						 if(e->KeyCode==Keys::S);
							 	
						 if(e->KeyCode==Keys::D);
							 
						 if(e->KeyCode==Keys::A);
						 
					 }

		private: System::Void DirectionalSprites_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
						//=================================================
						// Handle key up event
						//=================================================
						knight->setWalking(false);
						tileMap->mapStop();
					 }		
		private: System::Void clock_Tick(System::Object^  sender, System::EventArgs^  e) {
						//=================================================
						// Draw background 
						//=================================================
						tileMap->updateTilePosition();
						tileMap->drawTileMap(); 
						
						//=================================================
						// Update sprites frame animation
						//=================================================
						spriteList->update();
						
						for(int c = 0; c < chickens->Length; c++)
							chickens[c]->wander();

						//=================================================
						// Draw sprites to the canvas 
						//=================================================
						spriteList->draw();

						//=================================================
						// Make buffer visible 
						//=================================================
						canvas->DrawImage(dbBitmap, ClientRectangle);
					 }
};
}

