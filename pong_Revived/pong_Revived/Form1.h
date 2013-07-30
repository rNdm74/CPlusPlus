#pragma once

#include "Character.h"

namespace pong_Revived {
	
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
	private: Graphics^ dbGraphics;
	private: Bitmap^ dbBitmap;
	private: Pen^ pen;
	

	private: float x;
	private: float y;
	private: float width;
	private: float height;

	private: float speed;
    private: float velocity;

	private: Character^ player;

	private: System::Windows::Forms::Timer^  timer1;
	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


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
		this->timer1->Interval = 10;
		this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
		// 
		// Form1
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(784, 562);
		this->DoubleBuffered = true;
		this->Name = L"Form1";
		this->Text = L"Form1";
		this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
		this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
		this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyUp);
		this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
		this->ResumeLayout(false);

			}
#pragma endregion
		

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 
				 // Create a bitmap
                 dbBitmap = gcnew Bitmap(ClientRectangle.Width,
                                        ClientRectangle.Height);

				 // Grab its Graphics
                 dbGraphics = Graphics::FromImage(dbBitmap);

				 pen = gcnew Pen(Color::Black);	

				 

				 x = 0;
				 y = 10;
				 width = 25;
				 height = 80;

				 player = gcnew Character(0, 10, 25, 80);
				 player->setSpeed(0);

				 speed = 0;
				 velocity = 1;

				 timer1->Enabled = true;
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {	
				 player->move();
				 Invalidate();
			 }

				 
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 //if(e->KeyCode == Keys::Up) speed = -2;
				 //if(e->KeyCode == Keys::Down) speed = 2;
			 }
	private: System::Void Form1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 //if(e->KeyCode == Keys::Up) speed = -2;
				 //if(e->KeyCode == Keys::Down) speed = 2;
			 }
				 
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			dbGraphics->Clear(Color::Black);

			Drawing::Rectangle Head  = Drawing::Rectangle(x, y, width, height);
			dbGraphics->FillRectangle(Brushes::Yellow, Head);
            dbGraphics->DrawRectangle(pen, Head);
			
            // Make the buffer visible
            e->Graphics->DrawImageUnscaled(dbBitmap, 0, 0);	
			}
		
};
}

