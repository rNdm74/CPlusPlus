#pragma once

#include "Main.h"
#include <time.h>
#include <ctime>
#include <Windows.h>

namespace Pong_Revisited {

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
	private: System::Windows::Forms::Timer^  update;
	protected: 
	private: System::ComponentModel::IContainer^  components;

	private: Graphics^ dbGraphics;
	private: Graphics^ canvas;
	private: Bitmap^ dbBitmap;
	private: Pen^ pen;

	private: Main^ main;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->update = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// update
			// 
			this->update->Interval = 10;
			this->update->Tick += gcnew System::EventHandler(this, &Form1::update_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->DoubleBuffered = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->Text = L"Pong Revisited";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyUp);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->ResumeLayout(false);
gameLoop();
		}
#pragma endregion
	private: Form1::Void gameLoop(){
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

	private: Form1::Void initGame(){
				 main = gcnew Main();

				 // Create a bitmap
                dbBitmap = gcnew Bitmap(ClientRectangle.Width,
                                        ClientRectangle.Height);

				// Grab its Graphics
                dbGraphics = Graphics::FromImage(dbBitmap);
			 }

	private: Form1::Void updateGame(){
				 main->update();
			 }

	private: Form1::Void renderGame(){
				 main->render(dbGraphics);
			 }



	private: int frames;
	private: double lastTime;
	private: long totalTime;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 initGame();

				 frames = 0;
				 
				 lastTime = time(NULL);


				 totalTime = 0;	

				 //Time t;

				 
				
				 //this->Text = " " + clock_gettime();
				 
			 }
	 
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 //this->Text = " " + lastTime;
				 double msec = time(NULL);
				 
				 //long now = time;
				 
				 double passed = msec - lastTime;

				 Text = "FPS: " + passed;
				 //lastTime = now;
				 
				 if(totalTime >= 1000000000){
					 
					 totalTime = 0;
					 frames = 0;
				 }
				 
				 Invalidate();

				 updateGame();

				 renderGame();
				 
				 // Make the buffer visible
				 e->Graphics->DrawImage(dbBitmap, 0, 0);

				 frames++;
			 }

    private: System::Void update_Tick(System::Object^  sender, System::EventArgs^  e) {
				 
			 }

	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if(e->KeyCode == Keys::Up) main->getGame()->getPlayer()->setMag(-1);
				 if(e->KeyCode == Keys::Down) main->getGame()->getPlayer()->setMag(1);	 
			 }
	private: System::Void Form1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if(e->KeyCode == Keys::Up) main->getGame()->getPlayer()->setMag(0);
				 if(e->KeyCode == Keys::Down) main->getGame()->getPlayer()->setMag(0);
			 }
	
	};
}

