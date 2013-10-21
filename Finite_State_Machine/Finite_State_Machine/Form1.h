#pragma once

#include "Creature.h"



namespace Finite_State_Machine {

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
	private: System::Windows::Forms::Button^  button1;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Graphics^ canvas;
		Graphics^ dbGraphics;
		Bitmap^ dbBitmap;

		Random^ rGen;

		array<Creature^>^ blueBugs;
		array<Creature^>^ redBugs;

		array<Thing^>^ obstaclesInWorld;
		array<Thing^>^ foodInWorld;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(682, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 31);
			this->button1->TabIndex = 0;
			this->button1->Text = L"START";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 20;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
					// Create canvas from form
					canvas = CreateGraphics();

					// Create graphics size of the screen
					dbBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);
					 
					// Grab its Graphics
					dbGraphics = Graphics::FromImage(dbBitmap);

					rGen = gcnew Random();

					blueBugs = gcnew array<Creature^>(10);
					redBugs = gcnew array<Creature^>(10);

					obstaclesInWorld = gcnew array<Thing^>(20);
					foodInWorld = gcnew array<Thing^>(30);


					for(int creature = 0; creature < redBugs->Length; creature++)
					{
						blueBugs[creature] = gcnew Creature(dbGraphics, rGen, ClientRectangle.Width, ClientRectangle.Height, "littleBug1.png", 16);
						redBugs[creature] = gcnew Creature(dbGraphics, rGen, ClientRectangle.Width, ClientRectangle.Height, "littleBug2.png", 16);
					}

					for(int object = 0; object < foodInWorld->Length; object++)
						foodInWorld[object] = gcnew Thing(dbGraphics, rGen, ClientRectangle.Width, ClientRectangle.Height, "cookie.jpg", 20);

					for(int object = 0; object < obstaclesInWorld->Length; object++)
						obstaclesInWorld[object] = gcnew Thing(dbGraphics, rGen, ClientRectangle.Width, ClientRectangle.Height, "gemstone.jpg", 32);
					
				 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
					dbGraphics->FillRectangle(Brushes::Black, ClientRectangle);

					for(int object = 0; object < foodInWorld->Length; object++)						
						if(foodInWorld[object] != nullptr)
							foodInWorld[object]->Draw();

					for(int object = 0; object < obstaclesInWorld->Length; object++)
						obstaclesInWorld[object]->Draw();

					for(int creature = 0; creature < redBugs->Length; creature++)
					{
						Creature^ blueBug = blueBugs[creature];
						blueBug->UpdateState(foodInWorld, obstaclesInWorld);
						blueBug->PerformAction();
						blueBug->Draw();
						
						Creature^ redBug = redBugs[creature];
						redBug->UpdateState(foodInWorld, obstaclesInWorld);
						redBug->PerformAction();
						redBug->Draw();					
					}

					// Make buffer visible 
					canvas->DrawImage(dbBitmap, ClientRectangle);
				 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
					timer1->Enabled = true;
					button1->Visible = false;
				 }
		};
}

