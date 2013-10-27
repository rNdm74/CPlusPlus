#pragma once

#include "Sprite.h"

//enum EPlayerAction{
//			IDLE,
//			HURT,
//			BOSS_HURT,
//			BLOCK,
//			LESSER_ICE,
//			GREATER_ICE,
//			WALK,
//			BASIC_ATTACK,
//			DODGE,
//			ELECTRIC_STORM,
//			HEAVY_ATTACK,
//			WHIRLWIND_ATTACK,
//			SHOCKED,
//			HEAL
//		};
//
//enum EMakhanaAction{
//			/*IDLE,
//			HURT,*/
//			DESECRATE,
//			TENTISHOCK,
//			OIL_SPILL,
//			KILLED
//		};
				 

namespace jsonParser {

	using namespace System;
	using namespace System::IO;
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
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>		

		Graphics^ canvas;

		Graphics^ dbGraphics;
		Bitmap^ dbBitmap;

		Bitmap^ bg;
		
		Sprite^ player;
		Sprite^ cocoon;
		Sprite^ makhana;
		Sprite^ floppit;
		Sprite^ fluppit;
		Sprite^ peruna;

		EPlayerAction playerAction;

		Point movePoint;
		bool initiateAction;
		int direction;

		array<Point>^ playerState;
		array<Point>^ makhanaState;
		array<Point>^ cocoonState;
		array<Point>^ floppitState;
		array<Point>^ fluppitState;
		array<Point>^ perunaState;

	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private: System::Windows::Forms::Button^  button1;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;


	private: System::Windows::Forms::Timer^  timer2;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(937, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(59, 59);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->CausesValidation = false;
			this->button1->Enabled = false;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(873, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(58, 59);
			this->button1->TabIndex = 17;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(630, 682);
			this->label4->MinimumSize = System::Drawing::Size(74, 23);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(101, 23);
			this->label4->TabIndex = 28;
			this->label4->Tag = L"3";
			this->label4->Text = L"Lesser Ice";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label4->MouseLeave += gcnew System::EventHandler(this, &Form1::label_MouseLeave);
			this->label4->Click += gcnew System::EventHandler(this, &Form1::label_Click);
			this->label4->MouseEnter += gcnew System::EventHandler(this, &Form1::label_MouseEnter);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(737, 682);
			this->label5->MinimumSize = System::Drawing::Size(74, 23);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(113, 23);
			this->label5->TabIndex = 29;
			this->label5->Tag = L"4";
			this->label5->Text = L"Greater Ice";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label5->MouseLeave += gcnew System::EventHandler(this, &Form1::label_MouseLeave);
			this->label5->Click += gcnew System::EventHandler(this, &Form1::label_Click);
			this->label5->MouseEnter += gcnew System::EventHandler(this, &Form1::label_MouseEnter);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(856, 682);
			this->label6->MinimumSize = System::Drawing::Size(74, 23);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(140, 23);
			this->label6->TabIndex = 30;
			this->label6->Tag = L"8";
			this->label6->Text = L"Electric Storm";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label6->MouseLeave += gcnew System::EventHandler(this, &Form1::label_MouseLeave);
			this->label6->Click += gcnew System::EventHandler(this, &Form1::label_Click);
			this->label6->MouseEnter += gcnew System::EventHandler(this, &Form1::label_MouseEnter);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(237, 682);
			this->label7->MinimumSize = System::Drawing::Size(74, 23);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(96, 23);
			this->label7->TabIndex = 31;
			this->label7->Tag = L"10";
			this->label7->Text = L"Whirlwind";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label7->MouseLeave += gcnew System::EventHandler(this, &Form1::label_MouseLeave);
			this->label7->Click += gcnew System::EventHandler(this, &Form1::label_Click);
			this->label7->MouseEnter += gcnew System::EventHandler(this, &Form1::label_MouseEnter);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(98, 682);
			this->label8->MinimumSize = System::Drawing::Size(74, 23);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(133, 23);
			this->label8->TabIndex = 32;
			this->label8->Tag = L"9";
			this->label8->Text = L"Heavy Attack";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label8->MouseLeave += gcnew System::EventHandler(this, &Form1::label_MouseLeave);
			this->label8->Click += gcnew System::EventHandler(this, &Form1::label_Click);
			this->label8->MouseEnter += gcnew System::EventHandler(this, &Form1::label_MouseEnter);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1;
			this->timer2->Tick += gcnew System::EventHandler(this, &Form1::timer2_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(339, 682);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 23);
			this->label2->TabIndex = 33;
			this->label2->Tag = L"1";
			this->label2->Text = L"Hurt";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->MouseLeave += gcnew System::EventHandler(this, &Form1::label_MouseLeave);
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label_Click);
			this->label2->MouseEnter += gcnew System::EventHandler(this, &Form1::label_MouseEnter);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(502, 682);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(66, 23);
			this->label9->TabIndex = 35;
			this->label9->Tag = L"7";
			this->label9->Text = L"Dodge";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label9->MouseLeave += gcnew System::EventHandler(this, &Form1::label_MouseLeave);
			this->label9->Click += gcnew System::EventHandler(this, &Form1::label_Click);
			this->label9->MouseEnter += gcnew System::EventHandler(this, &Form1::label_MouseEnter);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(574, 682);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(50, 23);
			this->label11->TabIndex = 37;
			this->label11->Tag = L"11";
			this->label11->Text = L"Heal";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label11->MouseLeave += gcnew System::EventHandler(this, &Form1::label_MouseLeave);
			this->label11->Click += gcnew System::EventHandler(this, &Form1::label_Click);
			this->label11->MouseEnter += gcnew System::EventHandler(this, &Form1::label_MouseEnter);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Transparent;
			this->label12->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(398, 682);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(98, 23);
			this->label12->TabIndex = 38;
			this->label12->Tag = L"2";
			this->label12->Text = L"Boss Hurt";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label12->MouseLeave += gcnew System::EventHandler(this, &Form1::label_MouseLeave);
			this->label12->Click += gcnew System::EventHandler(this, &Form1::label_Click);
			this->label12->MouseEnter += gcnew System::EventHandler(this, &Form1::label_MouseEnter);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(18, 682);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 23);
			this->label1->TabIndex = 25;
			this->label1->Tag = L"6";
			this->label1->Text = L"Attack";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->MouseLeave += gcnew System::EventHandler(this, &Form1::label_MouseLeave);
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label_Click);
			this->label1->MouseEnter += gcnew System::EventHandler(this, &Form1::label_MouseEnter);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 23);
			this->label3->TabIndex = 39;
			this->label3->Tag = L"1";
			this->label3->Text = L"Hurt";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label3->MouseLeave += gcnew System::EventHandler(this, &Form1::label_MouseLeave);
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			this->label3->MouseEnter += gcnew System::EventHandler(this, &Form1::label_MouseEnter);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(65, 12);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(101, 23);
			this->label10->TabIndex = 40;
			this->label10->Tag = L"2";
			this->label10->Text = L"Desecrate";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label10->MouseLeave += gcnew System::EventHandler(this, &Form1::label_MouseLeave);
			this->label10->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			this->label10->MouseEnter += gcnew System::EventHandler(this, &Form1::label_MouseEnter);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Transparent;
			this->label13->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(169, 12);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(109, 23);
			this->label13->TabIndex = 41;
			this->label13->Tag = L"3";
			this->label13->Text = L"Tentishock";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label13->MouseLeave += gcnew System::EventHandler(this, &Form1::label_MouseLeave);
			this->label13->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			this->label13->MouseEnter += gcnew System::EventHandler(this, &Form1::label_MouseEnter);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::Transparent;
			this->label14->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(367, 12);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(60, 23);
			this->label14->TabIndex = 42;
			this->label14->Tag = L"5";
			this->label14->Text = L"Killed";
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label14->MouseLeave += gcnew System::EventHandler(this, &Form1::label_MouseLeave);
			this->label14->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			this->label14->MouseEnter += gcnew System::EventHandler(this, &Form1::label_MouseEnter);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::Color::Transparent;
			this->label15->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(284, 12);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(77, 23);
			this->label15->TabIndex = 43;
			this->label15->Tag = L"4";
			this->label15->Text = L"Oil Spill";
			this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label15->MouseLeave += gcnew System::EventHandler(this, &Form1::label_MouseLeave);
			this->label15->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			this->label15->MouseEnter += gcnew System::EventHandler(this, &Form1::label_MouseEnter);
			// 
			// Form1
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1008, 729);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ClientSizeChanged += gcnew System::EventHandler(this, &Form1::Form1_ClientSizeChanged);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion		
	
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 //walking 0,13
			 //hurt 13,29
			 //boss hurt 29,110
			 //block 110, 146
			 //lesser ice 146, 202
			 //greater ice 202, 236
			 //walk 236, 255
			 //basic attack 255, 285
			 //dodge 285, 324
			 //electric storm 324, 373
			 //heavy attack 373, 415
			 //whirlwind attack 415, 451
			 //shocked 451, 460
			 //heal 460, 497


			 //makhanaAction = 0;

			 

			 //Makahana
			 //IDLE 0,22
			 //HURT 22,60
			 //DESECRATE 60,134
			 //TENTISHOCK 134,188
			 //OIL_SPILL 188,259
			 //KILLED 259,301

			 //Floppit,Fluppit
			 //IDLE 0,7
			 //HURT 7,46
			 //ATTACK 46,75
			 //ATTACK2 75,97
			 //DEAD 97,107
			 //NEARDEATH 108,125

			 //Peruna
			 //IDLE 0,12
			 //HURT 12,22
			 //ATTACK 22,47
			 //ATTACK2 47,72
			 //DEAD 72,91
			 //ANGRY 92,103

			 //Cocoon
			 //IDLE 0,22
			 //HURT 22,71
			 //ATTACK 72,104
			 //ATTACK2 104,158
			 //BEAM 158,215
			 //DEAD 215,247				 

			 playerState = gcnew array<Point>
			 {
				 Point(0,14),		// Idle
				 Point(15,29),		// Hurt
				 Point(30,110),		// Boss Hurt
				 //Point(111,130),	// Block
				 Point(111,185),	// Lesser Ice
				 Point(186,242),	// Greater Ice
				 Point(243,260),	// Walk
				 Point(261,290),	// Basic Attack
				 Point(291,327),	// Dodge
				 Point(328,383),	// Electric Storm
				 Point(384,425),	// Heavy Attack
				 Point(426,472),	// Whirlwind Attack
				 //Point(456,480),	// Shocked
				 Point(473,499)		// Heal		 
			 };

			 //Makahana
			 //IDLE 0,22
			 //HURT 22,60
			 //DESECRATE 60,134
			 //TENTISHOCK 134,188
			 //OIL_SPILL 188,259
			 //KILLED 259,301

			 makhanaState = gcnew array<Point>
			 {
				 Point(0,22),		// Idle
				 Point(23,60),		// Hurt
				 Point(61,134),		// Desecrate
				 Point(135,188),	// Tentishock
				 Point(189,259),	// Oil Spill
				 Point(260,303)		// Killed
			 };

			 //Cocoon
			 //IDLE 0,22
			 //HURT 22,71
			 //ATTACK 72,104
			 //ATTACK2 104,158
			 //BEAM 158,215
			 //DEAD 215,247
			 cocoonState = gcnew array<Point>
			 {
				 Point(0,22),		// Idle
				 Point(23,71),		// Hurt
				 Point(72,104),		// Desecrate
				 Point(105,158),	// Tentishock
				 Point(159,215),	// Oil Spill
				 Point(216,249)		// Killed
			 };

			 //Peruna
			 //IDLE 0,12
			 //HURT 12,22
			 //ATTACK 22,47
			 //ATTACK2 47,72
			 //DEAD 72,91
			 //ANGRY 92,103
			 perunaState = gcnew array<Point>
			 {
				 Point(0,12),		// Idle
				 Point(13,22),		// Hurt
				 Point(23,47),		// Desecrate
				 Point(48,72),	// Tentishock
				 Point(73,91),	// Oil Spill
				 Point(92,105)		// Killed
			 };

			 //Floppit,Fluppit
			 //IDLE 0,7
			 //HURT 7,46
			 //ATTACK 46,75
			 //ATTACK2 75,97
			 //DEAD 97,107
			 //NEARDEATH 108,125
			 floppitState = gcnew array<Point>
			 {
				 Point(0,7),		// Idle
				 Point(7,46),		// Hurt
				 Point(46,75),		// Desecrate
				 Point(75,97),	// Tentishock
				 Point(97,107),	// Oil Spill
				 Point(108,125)		// Killed
			 };

			 	

			 
			 canvas = CreateGraphics();

			 dbBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);
			
			 dbGraphics = Graphics::FromImage(dbBitmap);

			 bg = gcnew Bitmap("bg.png");

			 player = gcnew Sprite(dbGraphics, "Player", playerState, 250, ClientRectangle.Height - 100);

			 
			 cocoon = gcnew Sprite(dbGraphics, "Cocoon", cocoonState, 850, ClientRectangle.Height - 100);
			 makhana = gcnew Sprite(dbGraphics, "Makhana", makhanaState, 850, ClientRectangle.Height - 100);
			 floppit = gcnew Sprite(dbGraphics, "Floppit", floppitState, 850, ClientRectangle.Height - 100);
			 fluppit = gcnew Sprite(dbGraphics, "Fluppit", floppitState, 850, ClientRectangle.Height - 100);
			 peruna = gcnew Sprite(dbGraphics, "Peruna", perunaState, 850, ClientRectangle.Height - 100);

			 //timer2->Enabled = true;
			 timer1->Enabled = true;
			 
			 Focus();

			 direction = 0;
			 initiateAction = false;

		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {	

			 dbGraphics->DrawImageUnscaledAndClipped(bg, ClientRectangle);

			 cocoon->update();
			 //cocoon->draw();

			 makhana->update();
			 //makhana->draw();

			 floppit->update();
			 ///floppit->draw();

			 
			 fluppit->draw();

			 peruna->update();
			 //peruna->draw();

			 /*if(!player->getCollisionRectangle().Contains(movePoint))
				player->move(direction);*/

			 player->update();
			 player->draw();

			 Rectangle r = Rectangle(movePoint.X, movePoint.Y, 2,2);

			 dbGraphics->DrawRectangle(gcnew Pen(Color::Black), r);

			 Text = ClientRectangle.X.ToString() + "," + ClientRectangle.Y.ToString() + "," + ClientRectangle.Width.ToString() + "," +ClientRectangle.Height.ToString();
			 
			 canvas->DrawImage(dbBitmap, ClientRectangle);
		 }

private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {

			 fluppit->update();
			 
			 if(!player->getCollisionRectangle().Contains(movePoint))
			 {
				 player->move(direction);					 
			 }
			 else
			 {
				 if(!player->isAttacking())
				 {
					player->setState(IDLE);
					direction = 0;
				 }					 
			 }

			 if(player->isAttacking() && player->isFinishedAction())
			 {
				 player->setState(IDLE);
			 }

			 if(makhana->isAttacking() && makhana->isFinishedAction())
			 {
				 makhana->setState(IDLE);
			 }

			 if(peruna->isAttacking() && peruna->isFinishedAction())
			 {
				 peruna->setState(IDLE);
			 }

			 if(fluppit->isAttacking() && fluppit->isFinishedAction())
			 {
				 fluppit->setState(IDLE);
			 }

			 if(floppit->isAttacking() && floppit->isFinishedAction())
			 {
				 floppit->setState(IDLE);
			 }

			 if(cocoon->isAttacking() && cocoon->isFinishedAction())
			 {
				 cocoon->setState(IDLE);
			 }
		 }

private: System::Void Form1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 movePoint = e->Location;			 
			 direction = (movePoint.X > player->getXPos()) ? 1 : -1;
			 player->setAttacking(false);
			 
		 }

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 timer1->Enabled = !timer1->Enabled;
		 }

private: System::Void label_Click(System::Object^  sender, System::EventArgs^  e) {
			 Label^ label = safe_cast<Label^>(sender);
			 label->ForeColor = Color::Black;
			 player->setAttacking(true);
			 player->setState(safe_cast<EPlayerAction>(int::Parse(label->Tag->ToString())));

			 //makhana->setAttacking(true);
			 //makhana->setState(LESSER_ICE);
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 Label^ label = safe_cast<Label^>(sender);
			 label->ForeColor = Color::Black;

			 makhana->setAttacking(true);
			 makhana->setState(safe_cast<EPlayerAction>(int::Parse(label->Tag->ToString())));

			 peruna->setAttacking(true);
			 peruna->setState(safe_cast<EPlayerAction>(int::Parse(label->Tag->ToString())));

			 cocoon->setAttacking(true);
			 cocoon->setState(safe_cast<EPlayerAction>(int::Parse(label->Tag->ToString())));

			 floppit->setAttacking(true);
			 floppit->setState(safe_cast<EPlayerAction>(int::Parse(label->Tag->ToString())));

			 fluppit->setAttacking(true);
			 fluppit->setState(safe_cast<EPlayerAction>(int::Parse(label->Tag->ToString())));
		 }

private: System::Void label_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 Label^ label = safe_cast<Label^>(sender);
			 label->ForeColor = Color::AliceBlue;
		 }

private: System::Void label_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			 Label^ label = safe_cast<Label^>(sender);
			 label->ForeColor = Color::Black;
		 }
private: System::Void Form1_ClientSizeChanged(System::Object^  sender, System::EventArgs^  e) {
			 //dbGraphics->SetClip(ClientRectangle);

			 //dbBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);
		 }
};
}

