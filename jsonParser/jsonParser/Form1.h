#pragma once

#include "spriteFrame.h"

namespace jsonParser {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;

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
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		array<Rectangle>^ frameRectangles1;
		array<Rectangle>^ frameRectangles2;

		Graphics^ canvas;

		Graphics^ dbGraphics;
		Bitmap^ dbBitmap;

		Bitmap^ spriteSheet1;
		Bitmap^ spriteSheet2;

		PixelFormat format;

		int currentFrame;
		int frameTime;


	private: System::Windows::Forms::Timer^  timer1;

		


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
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 729);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: array<Rectangle>^ Form1::loadSpriteSheetFrames(String^ file) {

				 //
				 // Load Rectangle array
				 //
				 String^ filename = file + ".json";

				 String^ frameName = filename->Substring(0, filename->IndexOf('.'));

				 StreamReader^ reader = gcnew StreamReader(filename);

				 int count = 0;
				 int nFrames = 0;

				 while(!reader->EndOfStream)
				 {
					 String^ line = reader->ReadLine();

					 array<String^>^ items = line->Split('"');

					 for(int string = 0; string < items->Length; string++)
					 {
						 if(items[string]->Contains("Enemy"))
						 {
							 nFrames++;
						 }
					 }
				 }

				 reader->Close();

				 array<Rectangle>^ frames = gcnew array<Rectangle>(nFrames);

				 reader = gcnew StreamReader(filename);

				 while(!reader->EndOfStream)
				 {
					 String^ line = reader->ReadLine();

					 array<String^>^ items = line->Split('"');

					 for(int string = 0; string < items->Length; string++)
					 {
						 if(items->Length > 3 && items[string]->Contains("frame") )
						 {
							 String^ x = items[4]->Trim(':',',');
							 String^ y = items[6]->Trim(':',',');
							 String^ w = items[8]->Trim(':',',');
							 String^ h = items[10]->Trim(':',',','}');

							 frames[count] = Rectangle(int::Parse(x), int::Parse(y), int::Parse(w), int::Parse(h));

							 count++;
						 }
					 }					 
				 }

				 reader->Close();

				 return frames;
			 }


	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

				 canvas = CreateGraphics();

				 dbBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);
				
				 dbGraphics = Graphics::FromImage(dbBitmap);

				 String^ file1 = "Cocoon";
				 String^ file2 = "Cocoon";
				 
				 spriteSheet1 = gcnew Bitmap(file1 + ".png");
				 spriteSheet1->MakeTransparent(spriteSheet1->GetPixel(0,0));
				 format = spriteSheet1->PixelFormat;

				 spriteSheet2 = gcnew Bitmap(file2 + ".png");
				 spriteSheet2->MakeTransparent(spriteSheet2->GetPixel(0,0));

				 frameRectangles1 = loadSpriteSheetFrames(file1);
				 frameRectangles2 = loadSpriteSheetFrames(file2);

				 currentFrame = 8;
				 

			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

				 /*if(currentFrame > 30)
				 {
					 currentFrame = 8;
				 }*/
				 //; // c = c%f;
				 currentFrame %= frameRectangles1->Length - 1;

				 //frameRectangle = Rectangle(currentFrame * frameWidth, 0, frameWidth, frameHeight);

				// this is to slow down the frame animation so that the sprites have a more realistic movement
				 bool changeFrame = frameTime > 1;

				 if(changeFrame) 
				 {
					 frameTime = 0; // resets frame time

					 currentFrame++; // move to sprites next frame
				 }

				 frameTime++; // increase frame time

				 dbGraphics->FillRectangle(Brushes::WhiteSmoke, ClientRectangle);

				 //
				 // Draw sprites frame to the screen
				 //
				 Bitmap^ spriteBitmap = spriteSheet1->Clone(frameRectangles1[currentFrame], format);
				 //
				 // Flips image on the X axis based on direction
				 //
				 if(false) spriteBitmap->RotateFlip(RotateFlipType::RotateNoneFlipX);	
				 //
				 // Draws bitmap to the screen
				 //
				 dbGraphics->DrawImage(spriteBitmap, 300, 300);	
				 //
				 // Clean up bitmap
				 //
				 delete spriteBitmap;

				 ////
				 //// Draw sprites frame to the screen
				 ////
				 //spriteBitmap = spriteSheet2->Clone(frameRectangles2[currentFrame], format);
				 ////
				 //// Flips image on the X axis based on direction
				 ////
				 //if(true) spriteBitmap->RotateFlip(RotateFlipType::RotateNoneFlipX);	
				 ////
				 //// Draws bitmap to the screen
				 ////
				 //dbGraphics->DrawImage(spriteBitmap, 500, 100);	
				 ////
				 //// Clean up bitmap
				 ////
				 //delete spriteBitmap;

				 /*dbGraphics->DrawImage
				 (
					 spriteSheet1, 
					 100, 
					 100, 
					 frameRectangles1[currentFrame], 
					 GraphicsUnit::Pixel
				 );

				 dbGraphics->DrawImage
				 (
					 spriteSheet2, 
					 500, 
					 100, 
					 frameRectangles2[currentFrame], 
					 GraphicsUnit::Pixel
				 );*/

				 canvas->DrawImage(dbBitmap, ClientRectangle);
			 }
};
}

