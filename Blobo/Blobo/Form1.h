#pragma once


namespace Blobo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	#define BLOBO_WIDTH 32
	#define BLOBO_HEIGHT 34
	#define NEXT_FRAME 60
	#define RESET_FRAME 7
	#define X_SPEED 1
	#define Y_SPEED 1

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
		RectangleF srcRectangle;
		Graphics^ dbGraphics;
		Bitmap^ dbBitmap;
		Bitmap^ blobo;

		float xPos;
		float yPos;
		float vel;

		int frame;
		float frameX;
		float frameY;
		int frameTime;
		int frameChange;
		
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
		this->ClientSize = System::Drawing::Size(284, 262);
		this->DoubleBuffered = true;
		this->MaximizeBox = false;
		this->MinimizeBox = false;
		this->Name = L"Form1";
		this->ShowIcon = false;
		this->Text = L"Blobo";
		this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
		this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
		this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyUp);
		this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
		this->ResumeLayout(false);

			}
#pragma endregion
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
					// Refresh screen
					Invalidate();

					// Clear background
					dbGraphics->Clear(BackColor);

					xPos += X_SPEED * vel;

					frame %= RESET_FRAME;
					
					// Update 
					if(frameTime > NEXT_FRAME)
					{
						frame++;
						frameTime = 0;
					}

					frameTime++;

					srcRectangle = RectangleF((float)frame * BLOBO_WIDTH, (float)frameY, BLOBO_WIDTH, BLOBO_HEIGHT);

					// Set Transparent 
					blobo->MakeTransparent(blobo->GetPixel(0,0));

					// Draw
					dbGraphics->DrawImage(blobo, xPos, yPos, srcRectangle, GraphicsUnit::Pixel);

					// Make buffer visible
					e->Graphics->DrawImage(dbBitmap, 0, 0);
				 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
					// Create graphics size of the screen
					dbBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);

					// Grab its Graphics
					dbGraphics = Graphics::FromImage(dbBitmap);

					// Load blobo
					blobo = gcnew Bitmap("BlobboMulti.bmp");					
				 }
		private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
						 if(e->KeyCode == Keys::Left)
						 {
							vel = -1;
						 }

						 if(e->KeyCode == Keys::Right)
						 {
							vel = 1;
						 }
					 }
		private: System::Void Form1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 
						if(e->KeyCode == Keys::Left)
						 {
							vel = 0;
						 }

						if(e->KeyCode == Keys::Right)
						 {
							vel = 0;
						 }
			 }
};
}

