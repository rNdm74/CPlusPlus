#pragma once

#include "Main.h"
#include <time.h>
#include <ctime>

namespace Pong_Revisited {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Pong
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Pong : public System::Windows::Forms::Form
	{
	public:
		Pong(void)
		{
			InitializeComponent();

			dbBitmap = nullptr;
			dbGraphics = nullptr;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Pong()
		{
			if (components)
			{
				delete components;
			}
		}	
	 
	private: System::ComponentModel::IContainer^  components;

	
	private: Graphics^ dbGraphics;
	private: Graphics^ canvas;
	private: Bitmap^ dbBitmap;
	private: Pen^ pen;

	private: Main^ main;
	private: Play^ p;

	private: int frames;
	private: long lastTime;
	private: long totalTime;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Pong
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->DoubleBuffered = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Pong";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pong Revisited";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &Pong::Pong_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Pong::Pong_Paint);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Pong::Pong_KeyPress);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Pong::Pong_KeyUp);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Pong::Pong_MouseMove);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Pong::Pong_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: Pong::Void gameLoop(){
				 //while(true){
				 //}
				
        /*Time.init();

        int frames = 0;
        long lastTime = System.nanoTime();
        long totalTime = 0;

        while (!Display.isCloseRequested()){
            long now = System.nanoTime();
            long passed = now - lastTime;
            lastTime = now;
            totalTime += passed;

            if(totalTime >= 1000000000){
                Display.setTitle("FPS: " + frames);
                //System.out.println(frames);
                totalTime = 0;
                frames = 0;
            }

            Time.update();
            getInput();
            update();
            render();
            frames++;
        }*/
    }

	private: Pong::Void initGame(){
				 main = gcnew Main(this);

				 //
				 p = main->getGame()->getPlayer();

				 // Create a bitmap
                 dbBitmap = gcnew Bitmap(ClientRectangle.Width,
                                        ClientRectangle.Height);

				 // Grab its Graphics
                 dbGraphics = Graphics::FromImage(dbBitmap);
			 }

	private: Pong::Void updateGame(){
				 main->update();
			 }

	private: Pong::Void renderGame(){
				 main->render(dbGraphics);
			 }



	

	private: System::Void Pong_Load(System::Object^  sender, System::EventArgs^  e) {
				 // Creates all game objects
				 initGame();
			 }
	 
	private: System::Void Pong_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 // Clear the screen
				 Invalidate();

				 // Update all game objects
				 updateGame();

				 // Draw game objects to buffer
				 renderGame();
				 
				 // Make buffer visible
				 e->Graphics->DrawImage(dbBitmap, 0, 0);
			 }

	private: System::Void Pong_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 p->input(e, 1);
			 }

	private: System::Void Pong_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 p->input(e , 0);
			 }
	
	private: System::Void Pong_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 int x = e->X;
				 Point p = e->Location;
				 //main->getGame()->getPlayer()->yPos = (float)y;
				 //Text = "x:" + p.X + " y:" + p.Y;
			 }
	private: System::Void Pong_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {				 
			 }
};
}

