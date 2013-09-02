#pragma once

#include "Sprite.h"

namespace Directional_Sprites {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	#define UPDATE 30

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

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		Graphics^ dbGraphics;
		Bitmap^ dbBitmap;
		Sprite^ knight;
		array<Sprite^>^ chickens;

		Random^ rGen;
		long gameTime;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
		this->SuspendLayout();
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
		this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &DirectionalSprites::DirectionalSprites_Paint);
		this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &DirectionalSprites::DirectionalSprites_KeyUp);
		this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &DirectionalSprites::DirectionalSprites_KeyDown);
		this->ResumeLayout(false);

			}
#pragma endregion
	private: System::Void DirectionalSprites_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
					// Refresh screen
					Invalidate();

					// Clear background
					dbGraphics->Clear(BackColor);

					
					for(int c = 0; c < chickens->Length; c++)
						chickens[c]->move();

					knight->move();	

					// Update 
					if(gameTime > UPDATE)
					{	
						for(int c = 0; c < chickens->Length; c++)
						{
							chickens[c]->updateFrame();
							chickens[c]->wander();
						}

						knight->updateFrame();

						gameTime = 0;
					}

					// Increase gametime
					gameTime++;
					
					// Draw
					for(int c = 0; c < chickens->Length; c++)
						chickens[c]->draw();
					knight->draw();
											

					// Make buffer visible
					e->Graphics->DrawImage(dbBitmap, 0, 0);
				 }
	private: System::Void DirectionalSprites_Load(System::Object^  sender, System::EventArgs^  e) {
					// Create graphics size of the screen
					dbBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);

					// Grab its Graphics
					dbGraphics = Graphics::FromImage(dbBitmap);
					
					rGen = gcnew Random();

					knight = gcnew Sprite
					(
						dbGraphics,
						gcnew array<String^>
						{
							"Knight Walk North 8.bmp",
							"Knight Walk South 8.bmp",
							"Knight Walk East 8.bmp",
							"Knight Walk West 8.bmp"
						},
						rGen,
						ClientRectangle
					);
					

					//


					chickens = gcnew array<Sprite^>(50);

					for(int c = 0; c < chickens->Length; c++)
					{
						chickens[c] = gcnew Sprite
						(
							dbGraphics,
							gcnew array<String^>
							{
								"Little Chicken Walk North 8.bmp",
								"Little Chicken Walk South 8.bmp",
								"Little Chicken Walk East 8.bmp",
								"Little Chicken Walk West 8.bmp"
							},
							rGen,
							ClientRectangle,
							knight
						);
					}
				 }

		private: System::Void DirectionalSprites_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
						 if(e->KeyCode==Keys::Up)
							 knight->setBearing(NORTH);

						 if(e->KeyCode==Keys::Down)
							 knight->setBearing(SOUTH);	

						 if(e->KeyCode==Keys::Right)
							 knight->setBearing(EAST);

						 if(e->KeyCode==Keys::Left)
							 knight->setBearing(WEST);
						 
					 }
private: System::Void DirectionalSprites_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 }
};
}

