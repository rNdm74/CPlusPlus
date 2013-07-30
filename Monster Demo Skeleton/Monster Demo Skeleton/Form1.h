#pragma once

#include "Creature.h";

namespace MonsterDemoSkeleton {

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
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  btnMonster;
	private: System::Windows::Forms::Button^  btnWitch;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	private: Creature^ witch;
	private: Creature^ monster;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
		this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
		this->btnMonster = (gcnew System::Windows::Forms::Button());
		this->btnWitch = (gcnew System::Windows::Forms::Button());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
		this->SuspendLayout();
		// 
		// pictureBox1
		// 
		this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
		this->pictureBox1->Location = System::Drawing::Point(96, 53);
		this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
		this->pictureBox1->Name = L"pictureBox1";
		this->pictureBox1->Size = System::Drawing::Size(96, 96);
		this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
		this->pictureBox1->TabIndex = 0;
		this->pictureBox1->TabStop = false;
		// 
		// pictureBox2
		// 
		this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
		this->pictureBox2->Location = System::Drawing::Point(274, 53);
		this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
		this->pictureBox2->Name = L"pictureBox2";
		this->pictureBox2->Size = System::Drawing::Size(96, 96);
		this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
		this->pictureBox2->TabIndex = 1;
		this->pictureBox2->TabStop = false;
		// 
		// btnMonster
		// 
		this->btnMonster->Location = System::Drawing::Point(120, 184);
		this->btnMonster->Margin = System::Windows::Forms::Padding(2);
		this->btnMonster->Name = L"btnMonster";
		this->btnMonster->Size = System::Drawing::Size(72, 19);
		this->btnMonster->TabIndex = 2;
		this->btnMonster->Text = L"Monster";
		this->btnMonster->UseVisualStyleBackColor = true;
		this->btnMonster->Click += gcnew System::EventHandler(this, &Form1::btnMonster_Click);
		// 
		// btnWitch
		// 
		this->btnWitch->Location = System::Drawing::Point(274, 184);
		this->btnWitch->Margin = System::Windows::Forms::Padding(2);
		this->btnWitch->Name = L"btnWitch";
		this->btnWitch->Size = System::Drawing::Size(72, 19);
		this->btnWitch->TabIndex = 3;
		this->btnWitch->Text = L"Witch";
		this->btnWitch->UseVisualStyleBackColor = true;
		this->btnWitch->Click += gcnew System::EventHandler(this, &Form1::btnWitch_Click);
		// 
		// Form1
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::Black;
		this->ClientSize = System::Drawing::Size(449, 276);
		this->Controls->Add(this->btnWitch);
		this->Controls->Add(this->btnMonster);
		this->Controls->Add(this->pictureBox2);
		this->Controls->Add(this->pictureBox1);
		this->Margin = System::Windows::Forms::Padding(2);
		this->Name = L"Form1";
		this->Text = L"Form1";
		this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
		this->ResumeLayout(false);
		this->PerformLayout();

			}
#pragma endregion
	private: System::Void btnMonster_Click(System::Object^  sender, System::EventArgs^  e) {
				 monster->Speak();
			 }
private: System::Void btnWitch_Click(System::Object^  sender, System::EventArgs^  e) {
				witch->Speak();
			 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				witch = gcnew Creature(ECreatureType::WITCH);
				monster = gcnew Creature(ECreatureType::MONSTER);
			 }
};
}

