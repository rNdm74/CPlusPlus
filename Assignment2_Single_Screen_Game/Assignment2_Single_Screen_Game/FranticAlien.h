#pragma once

#include "GameManager.h"


namespace Assignment2_Single_Screen_Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FranticAlien
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class FranticAlien : public System::Windows::Forms::Form
	{
	public:
		FranticAlien(void)
		{
			InitializeComponent();			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FranticAlien()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  clock;
	protected: 

	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		GameManager^ gManager;


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
			this->clock->Interval = 1;
			this->clock->Tick += gcnew System::EventHandler(this, &FranticAlien::clock_Tick);
			// 
			// FranticAlien
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1008, 730);
			this->Name = L"FranticAlien";
			this->Text = L"Frantic Alien";
			this->Load += gcnew System::EventHandler(this, &FranticAlien::FranticAlien_Load);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FranticAlien::FranticAlien_KeyUp);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FranticAlien::FranticAlien_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void clock_Tick(System::Object^  sender, System::EventArgs^  e) {
					gManager->updateGame();
					gManager->drawGame();
				 }
	private: System::Void FranticAlien_Load(System::Object^  sender, System::EventArgs^  e) {
					gManager = gcnew GameManager(CreateGraphics(), ClientRectangle);					
				 }
	private: System::Void FranticAlien_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 gManager->keyDown(e);
			 }

	private: System::Void FranticAlien_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 gManager->keyUp(e);
			 }
	};
}

