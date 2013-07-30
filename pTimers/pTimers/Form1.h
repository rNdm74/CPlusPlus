#pragma once

namespace pTimers {

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
			start_stop->Select();
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
	private: System::Windows::Forms::Button^  buttonLeft;
	private: System::Windows::Forms::Button^  buttonRight;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::Button^  start_stop;

	private: System::Windows::Forms::Button^  exit;



	protected: 

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
			this->buttonLeft = (gcnew System::Windows::Forms::Button());
			this->buttonRight = (gcnew System::Windows::Forms::Button());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->start_stop = (gcnew System::Windows::Forms::Button());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonLeft
			// 
			this->buttonLeft->Location = System::Drawing::Point(12, 12);
			this->buttonLeft->Name = L"buttonLeft";
			this->buttonLeft->Size = System::Drawing::Size(57, 56);
			this->buttonLeft->TabIndex = 0;
			this->buttonLeft->UseVisualStyleBackColor = true;
			this->buttonLeft->Click += gcnew System::EventHandler(this, &Form1::buttonLeft_Click);
			// 
			// buttonRight
			// 
			this->buttonRight->Location = System::Drawing::Point(221, 12);
			this->buttonRight->Name = L"buttonRight";
			this->buttonRight->Size = System::Drawing::Size(59, 56);
			this->buttonRight->TabIndex = 1;
			this->buttonRight->UseVisualStyleBackColor = true;
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &Form1::timer_Tick);
			// 
			// start_stop
			// 
			this->start_stop->Location = System::Drawing::Point(12, 95);
			this->start_stop->Name = L"start_stop";
			this->start_stop->Size = System::Drawing::Size(75, 23);
			this->start_stop->TabIndex = 2;
			this->start_stop->Text = L"Start";
			this->start_stop->UseVisualStyleBackColor = true;
			this->start_stop->Click += gcnew System::EventHandler(this, &Form1::start_stop_Click);
			// 
			// exit
			// 
			this->exit->Location = System::Drawing::Point(205, 95);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(75, 23);
			this->exit->TabIndex = 4;
			this->exit->Text = L"Exit";
			this->exit->UseVisualStyleBackColor = true;
			this->exit->Click += gcnew System::EventHandler(this, &Form1::exit_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(288, 127);
			this->ControlBox = false;
			this->Controls->Add(this->exit);
			this->Controls->Add(this->start_stop);
			this->Controls->Add(this->buttonRight);
			this->Controls->Add(this->buttonLeft);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonLeft_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 }
	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {
				 //move buttonLeft right
				 buttonLeft->Left += 6;

				 //move buttonRight left
				 buttonRight->Left -= 7;
				 
				 //collision check
				 if(collision(buttonLeft) || collision(buttonRight)){
					//change button color
					button_Collision(buttonLeft, buttonRight)->BackColor = Color::Green;
					
					//stop timer
					timer->Stop();
				 }				  				 				 				 
			 }
	private: Button^ Form1::button_Collision(Button^ b1, Button^ b2) {
				 return (collision(b1)) ? b1 : b2;
			 }
	private: bool Form1::collision(Button^ b) {
				 return ((b->Left < 0)||(b->Right > Width));
			 }
	private: Form1::Void reset() {
				 //reset color
				 buttonLeft->BackColor = SystemColors::Control;
				 buttonRight->BackColor = SystemColors::Control;
				 
				 //set start button
				 start_stop->Text = "Start";
				 start_stop->Select();

				 //set positions
				 buttonLeft->Left =	12;				 
				 buttonRight->Left = 221;				 
			 }
	private: System::Void start_stop_Click(System::Object^  sender, System::EventArgs^  e) {				 				 
				 //set start_stop text
				 start_stop->Text = (!timer->Enabled) ? "Reset" : "Start";
				 
				 //enable/disable timer
				 timer->Enabled = !timer->Enabled;

				 //reset form
				 if(timer->Enabled) reset();
			}

private: System::Void exit_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
};
}

