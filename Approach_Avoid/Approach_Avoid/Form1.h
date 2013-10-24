#pragma once

#include "SpriteList.h"
#include "Ship.h"


namespace Approach_Avoid {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::Timer^  timer1;
	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Graphics^ canvas;

		Graphics^ dbGraphics;

		Bitmap^ dbBitmap;

		Image^ background;

		Random^ rGen;

		SpriteList^ spriteList;






		Sprite^ blobbo;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				
				canvas = CreateGraphics();
				
				dbBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);
				 
				dbGraphics = Graphics::FromImage(dbBitmap);

				rGen = gcnew Random();

				spriteList = gcnew SpriteList();

				background = Image::FromFile("images/groupBoxBackground.jpg");

				blobbo = gcnew Sprite
						(
							BOUNCE, 
							dbGraphics, 
							gcnew array<String^>{ "images/blobbo.bmp" }, 
							8, 
							rGen, 
							Point(rGen->Next(800),rGen->Next(600))
						);

				for(int ship = 0; ship < 20; ship++)
				{
					spriteList->add
					(
						gcnew Ship
						(
							BOUNCE, 
							dbGraphics, 
							gcnew array<String^>{ "images/yellowShip.bmp" }, 
							40, 
							rGen, 
							Point(rGen->Next(800),rGen->Next(600)),
							1
						)
					);

					spriteList->add
					(
						gcnew Ship
						(
							BOUNCE, 
							dbGraphics, 
							gcnew array<String^>{ "images/redShip.bmp" }, 
							40, 
							rGen, 
							Point(rGen->Next(800),rGen->Next(600)),
							-1
						)
					);
				}

				spriteList->add(blobbo);
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				//Draw background
				dbGraphics->DrawImageUnscaledAndClipped(background, ClientRectangle);

				spriteList->approach_avoid(blobbo);

				spriteList->update();
				spriteList->draw();
								
				canvas->DrawImage(dbBitmap, ClientRectangle);
			 }
	private: System::Void Form1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				blobbo->setXPos(e->X);
				blobbo->setYPos(e->Y);	
			 }
	};
}

