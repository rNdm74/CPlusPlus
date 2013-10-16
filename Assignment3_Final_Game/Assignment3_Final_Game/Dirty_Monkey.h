#pragma once

#include "Constants.h"
#include "GameManager.h"

namespace Assignment3_Final_Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Dirty_Monkey
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Dirty_Monkey : public System::Windows::Forms::Form
	{
	public:
		Dirty_Monkey(void)
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
		~Dirty_Monkey()
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
		this->clock->Interval = 1;
		this->clock->Tick += gcnew System::EventHandler(this, &Dirty_Monkey::clock_Tick);
		// 
		// Dirty_Monkey
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::Black;
		this->ClientSize = System::Drawing::Size(1008, 730);
		this->Name = L"Dirty_Monkey";
		this->Text = L"Dirty Monkey";
		this->Load += gcnew System::EventHandler(this, &Dirty_Monkey::Dirty_Monkey_Load);
		this->ResumeLayout(false);

			}
#pragma endregion
	private: System::Void clock_Tick(System::Object^  sender, System::EventArgs^  e) {
				Text = gManager->getXPos().ToString();
				gManager->updateGame();
				gManager->drawGame();
			}
	private: System::Void Dirty_Monkey_Load(System::Object^  sender, System::EventArgs^  e) {
				gManager = gcnew GameManager(CreateGraphics(), ClientRectangle);
				clock->Enabled = true;
			}
		};
}

