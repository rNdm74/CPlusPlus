#pragma once


namespace DataStructures {

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
	private: System::Windows::Forms::ListBox^  listBox;
	protected: 

	protected: 
	private: System::Windows::Forms::Button^  goButton;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
		this->listBox = (gcnew System::Windows::Forms::ListBox());
		this->goButton = (gcnew System::Windows::Forms::Button());
		this->SuspendLayout();
		// 
		// listBox
		// 
		this->listBox->FormattingEnabled = true;
		this->listBox->Location = System::Drawing::Point(13, 13);
		this->listBox->Name = L"listBox";
		this->listBox->Size = System::Drawing::Size(304, 134);
		this->listBox->TabIndex = 0;
		// 
		// goButton
		// 
		this->goButton->Location = System::Drawing::Point(242, 162);
		this->goButton->Name = L"goButton";
		this->goButton->Size = System::Drawing::Size(75, 23);
		this->goButton->TabIndex = 1;
		this->goButton->Text = L"Go";
		this->goButton->UseVisualStyleBackColor = true;
		this->goButton->Click += gcnew System::EventHandler(this, &Form1::goButton_Click);
		// 
		// Form1
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(329, 194);
		this->Controls->Add(this->goButton);
		this->Controls->Add(this->listBox);
		this->Name = L"Form1";
		this->ShowIcon = false;
		this->Text = L"DataStructures";
		this->ResumeLayout(false);

			}
#pragma endregion
	private: System::Void goButton_Click(System::Object^  sender, System::EventArgs^  e) {					
					
				 }	
		};
}

