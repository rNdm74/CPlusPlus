#pragma once

#include "Grid.h"
#include "L.h"
#include "J.h"
#include "Z.h"
#include "S.h"
#include "T.h"
#include "I.h"
#include "O.h"


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
		J^ j;
		Z^ z;
		S^ s;
		T^ t;
		I^ i;
		O^ o;
		
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
						//l->moveDown();
						//j->moveDown();
						//z->moveDown();
						s->moveDown();
						//d->moveDown();
						if(s->isPlaced())t->moveDown();
						//i->moveDown();
						//o->moveDown();

						count = 0;
					}

					count++;

					// Render game
					grid->draw();
					//l->draw();
					//j->draw();
					//z->draw();
					s->draw();

					array<Point>^ p = s->getSquares();

					Text = p[0] + " " + p[1] +" "+ p[2] + " " + p[3];

					if(s->isPlaced())
					{
						t->draw();
					}
					
					//t->draw();
					//i->draw();
					//o->draw();

					
					// Make buffer visible
					e->Graphics->DrawImage(dbBitmap, 0, 0);
				 }

	private: System::Void Tetris_Load(System::Object^  sender, System::EventArgs^  e) {
					// Create graphics size of the screen
					dbBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);

					// Grab its Graphics
					dbGraphics = Graphics::FromImage(dbBitmap);

					grid = gcnew Grid(Point(30,30), dbGraphics);

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

					j = gcnew J
					(
						gcnew array<Point> 
						{ 
							Point(3,1), 
							Point(3,2), 
							Point(3,3),
							Point(2,3)
						}, 
						Color::Green, 
						grid
					);

					z = gcnew Z
					(
						gcnew array<Point> 
						{ 
							Point(1,1), 
							Point(2,1), 
							Point(2,2),
							Point(3,2)
						}, 
						Color::Green, 
						grid
					);

					s = gcnew S
					(
						gcnew array<Point> 
						{ 
							Point(3,1), 
							Point(2,1), 
							Point(2,2),
							Point(1,2)
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

					i = gcnew I
					(
						gcnew array<Point> 
						{ 
							Point(2,1), 
							Point(2,2), 
							Point(2,3),
							Point(2,4)
						}, 
						Color::Green, 
						grid
					);

					o = gcnew O
					(
						gcnew array<Point> 
						{ 
							Point(2,1), 
							Point(2,2), 
							Point(3,1),
							Point(3,2)
						}, 
						Color::Green, 
						grid
					);

					count = 0;
				 }
	private: System::Void Tetris_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
					if(e->KeyCode == Keys::Left) s->moveLeft();
					if(e->KeyCode == Keys::Right) s->moveRight();
					if(e->KeyCode == Keys::Down)
					{						
						s->moveDown();
						if(s->isPlaced())t->moveDown();
					}

					int direction = 3;
					
					if(e->KeyCode == Keys::Up) s->moveRotate();					
				 }
	private: System::Void clock_Tick(System::Object^  sender, System::EventArgs^  e) {
					
				 }
};
}

