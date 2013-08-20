#pragma once

#include "Grid.h"
#include "L.h"
#include "T.h"


namespace Tetris_Assignment {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
		Graphics^ dbGraphics;
		Bitmap^ dbBitmap;

		Grid^ grid;

		L^ l;
		T^ t;

		int count;
	private: System::Windows::Forms::Timer^  clock;
	private: System::ComponentModel::IContainer^  components;



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
		this->clock->Tick += gcnew System::EventHandler(this, &Tetris::clock_Tick);
		// 
		// Tetris
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::Black;
		this->ClientSize = System::Drawing::Size(1008, 730);
		this->DoubleBuffered = true;
		this->MaximumSize = System::Drawing::Size(1024, 768);
		this->MinimumSize = System::Drawing::Size(1024, 736);
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
					
					// Update game	
					if(count > 150)
					{
						l->moveDown();
						t->moveDown();
						count = 0;
					}

					count++;

					// Render game
					grid->draw();
					//l->draw();
					t->draw();
					
					// Make buffer visible
					e->Graphics->DrawImage(dbBitmap, 0, 0);
				 }

	private: System::Void Tetris_Load(System::Object^  sender, System::EventArgs^  e) {
					// Create graphics size of the screen
					dbBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);

					// Grab its Graphics
					dbGraphics = Graphics::FromImage(dbBitmap);

					grid = gcnew Grid(Point(10,10), dbGraphics);

					l = gcnew L
					(
						gcnew array<Point> 
						{ 
							Point(1,1), 
							Point(1,2), 
							Point(1,3),
							Point(2,3)
						}, 
						Color::Green, 
						grid
					);

					t = gcnew T
					(
						gcnew array<Point> 
						{ 
							Point(2,1), 
							Point(1,2), 
							Point(2,2),
							Point(3,2)
						}, 
						Color::Green, 
						grid
					);

					count = 0;
				 }
	private: System::Void Tetris_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
					if(e->KeyCode == Keys::Left) t->moveLeft();
					if(e->KeyCode == Keys::Right) t->moveRight();
					if(e->KeyCode == Keys::Down) t->moveDown();

					int direction = 3;

					
					if(e->KeyCode == Keys::Up) t->rotate();
					
				 }
	private: System::Void clock_Tick(System::Object^  sender, System::EventArgs^  e) {
					
				 }
};
}

