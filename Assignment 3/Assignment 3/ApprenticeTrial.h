#pragma once

#include "GameManager.h"

namespace Assignment3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for The Apprentice's Trial
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ApprenticeTrial : public System::Windows::Forms::Form
	{
	public:
		ApprenticeTrial(void)
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
		~ApprenticeTrial()
		{
			if (components)
			{
				delete components;
			}
		}
	private: GameManager^ gManager;
	private: System::Windows::Forms::Timer^  clock;
	private: System::Windows::Forms::Timer^  secondary_clock;







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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ApprenticeTrial::typeid));
			this->clock = (gcnew System::Windows::Forms::Timer(this->components));
			this->secondary_clock = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// clock
			// 
			this->clock->Interval = 1;
			this->clock->Tick += gcnew System::EventHandler(this, &ApprenticeTrial::clock_Tick);
			// 
			// secondary_clock
			// 
			this->secondary_clock->Enabled = true;
			this->secondary_clock->Interval = 1;
			this->secondary_clock->Tick += gcnew System::EventHandler(this, &ApprenticeTrial::secondary_clock_Tick);
			// 
			// ApprenticeTrial
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1008, 729);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1024, 768);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(1024, 768);
			this->Name = L"ApprenticeTrial";
			this->Text = L"The Apprentice\'s Trial";
			this->Load += gcnew System::EventHandler(this, &ApprenticeTrial::ApprenticeTrial_Load);
			this->MouseEnter += gcnew System::EventHandler(this, &ApprenticeTrial::ApprenticeTrial_MouseEnter);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ApprenticeTrial::ApprenticeTrial_MouseDown);
			this->MouseLeave += gcnew System::EventHandler(this, &ApprenticeTrial::ApprenticeTrial_MouseLeave);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &ApprenticeTrial::ApprenticeTrial_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ApprenticeTrial_Load(System::Object^  sender, System::EventArgs^  e) {
				 gManager = gcnew GameManager(CreateGraphics(), ClientRectangle);
				 clock->Enabled = true;
			 }
	private: System::Void ApprenticeTrial_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 gManager->mouseDown(e->Location);
			 }
	private: System::Void ApprenticeTrial_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void ApprenticeTrial_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void clock_Tick(System::Object^  sender, System::EventArgs^  e) {
				 gManager->draw();
			 }
	private: System::Void secondary_clock_Tick(System::Object^  sender, System::EventArgs^  e) {
				 gManager->update();
			 }
	
	
	private: System::Void ApprenticeTrial_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 gManager->keyDown(e->KeyCode);
			 }	
};
}

