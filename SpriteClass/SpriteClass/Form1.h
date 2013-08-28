#pragma once

#include "Sprite.h"

namespace SpriteClass {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

#define UPDATE 30

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			dbBitmap = nullptr;
			dbGraphics = nullptr;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
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
		Graphics^ dbGraphics;
		Bitmap^ dbBitmap;

		Bitmap^ spriteSheet;
		Image^ background;

		array<Sprite^>^ blobos;

		Random^ rGen;

		long gameTime;

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
		// Form1
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::Black;
		this->ClientSize = System::Drawing::Size(784, 262);
		this->DoubleBuffered = true;
		this->MaximizeBox = false;
		this->MinimizeBox = false;
		this->Name = L"Form1";
		this->ShowIcon = false;
		this->Text = L"Blobo Family";
		this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
		this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
		this->ResumeLayout(false);

			}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
					// Create graphics size of the screen
					dbBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);

					// Grab its Graphics
					dbGraphics = Graphics::FromImage(dbBitmap);

					background = Image::FromFile("Rainbow-d.jpg");

					spriteSheet = gcnew Bitmap("blobboLeft.bmp");

					rGen = gcnew Random();

					blobos = gcnew array<Sprite^>(1);

					for(int b = 0; b < blobos->Length; b++)
						blobos[b] = gcnew Sprite(dbGraphics, spriteSheet, rGen, ClientRectangle); 
				 }
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 // Refresh screen
					Invalidate();

					// Clear background
					dbGraphics->Clear(BackColor);

					dbGraphics->DrawImage(background, 0, 0, ClientRectangle.Width, ClientRectangle.Height);
										
					// Update 
					if(gameTime > UPDATE)
					{
						for(int b = 0; b < blobos->Length; b++)
						{
							blobos[b]->wander();
							blobos[b]->updateFrame();
						}
							
						gameTime = 0;
					}

					// Increase gametime
					gameTime++;

					for(int b = 0; b < blobos->Length; b++)
					{
						blobos[b]->checkBounds();
						blobos[b]->move();
					}

					for(int b = 0; b < blobos->Length; b++)
						blobos[b]->drawDead();

					// Draw
					for(int b = 0; b < blobos->Length; b++)
						blobos[b]->draw();

					// Make buffer visible
					e->Graphics->DrawImage(dbBitmap, 0, 0);
				 }
		};
}

