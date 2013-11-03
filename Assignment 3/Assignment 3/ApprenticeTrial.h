#pragma once

#include "Constants.h"
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
	private: bool selected;
	private: EState selectedAbility;
	private: GameManager^ gManager;

	private: System::Windows::Forms::Timer^  clock;
	private: System::Windows::Forms::Timer^  secondary_clock;
	private: System::Windows::Forms::PictureBox^  lesser_wand;
	private: System::Windows::Forms::PictureBox^  greater_wand;
	private: System::Windows::Forms::PictureBox^  whirlwind;
	private: System::Windows::Forms::PictureBox^  lesser_ice;
	private: System::Windows::Forms::PictureBox^  greater_ice;
	private: System::Windows::Forms::PictureBox^  electric_storm;
	private: System::Windows::Forms::PictureBox^  heal;
	private: System::Windows::Forms::ToolTip^  ability_info;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::PictureBox^  pictureBox8;

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
		this->lesser_wand = (gcnew System::Windows::Forms::PictureBox());
		this->greater_wand = (gcnew System::Windows::Forms::PictureBox());
		this->whirlwind = (gcnew System::Windows::Forms::PictureBox());
		this->lesser_ice = (gcnew System::Windows::Forms::PictureBox());
		this->greater_ice = (gcnew System::Windows::Forms::PictureBox());
		this->electric_storm = (gcnew System::Windows::Forms::PictureBox());
		this->heal = (gcnew System::Windows::Forms::PictureBox());
		this->ability_info = (gcnew System::Windows::Forms::ToolTip(this->components));
		this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lesser_wand))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->greater_wand))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->whirlwind))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lesser_ice))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->greater_ice))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->electric_storm))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->heal))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->BeginInit();
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
		// lesser_wand
		// 
		this->lesser_wand->BackColor = System::Drawing::Color::Transparent;
		this->lesser_wand->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->lesser_wand->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"lesser_wand.Image")));
		this->lesser_wand->Location = System::Drawing::Point(709, 677);
		this->lesser_wand->Name = L"lesser_wand";
		this->lesser_wand->Size = System::Drawing::Size(40, 40);
		this->lesser_wand->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->lesser_wand->TabIndex = 7;
		this->lesser_wand->TabStop = false;
		this->lesser_wand->Tag = L"6";
		this->ability_info->SetToolTip(this->lesser_wand, L"Lesser Wand\r\n\r\n10 Damage\r\n10 Mana Cost");
		this->lesser_wand->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
		// 
		// greater_wand
		// 
		this->greater_wand->BackColor = System::Drawing::Color::Transparent;
		this->greater_wand->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->greater_wand->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"greater_wand.Image")));
		this->greater_wand->Location = System::Drawing::Point(756, 677);
		this->greater_wand->Name = L"greater_wand";
		this->greater_wand->Size = System::Drawing::Size(40, 40);
		this->greater_wand->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->greater_wand->TabIndex = 8;
		this->greater_wand->TabStop = false;
		this->greater_wand->Tag = L"9";
		this->ability_info->SetToolTip(this->greater_wand, L"Greater Wand\r\n\r\n20 Damage\r\n20 Mana Cost\r\n");
		this->greater_wand->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
		// 
		// whirlwind
		// 
		this->whirlwind->BackColor = System::Drawing::Color::Transparent;
		this->whirlwind->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->whirlwind->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"whirlwind.Image")));
		this->whirlwind->Location = System::Drawing::Point(804, 677);
		this->whirlwind->Name = L"whirlwind";
		this->whirlwind->Size = System::Drawing::Size(40, 40);
		this->whirlwind->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->whirlwind->TabIndex = 9;
		this->whirlwind->TabStop = false;
		this->whirlwind->Tag = L"10";
		this->ability_info->SetToolTip(this->whirlwind, L"Whirlwind\r\n\r\n30 Damage\r\n30 Mana Cost\r\n");
		this->whirlwind->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
		// 
		// lesser_ice
		// 
		this->lesser_ice->BackColor = System::Drawing::Color::Transparent;
		this->lesser_ice->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->lesser_ice->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"lesser_ice.Image")));
		this->lesser_ice->Location = System::Drawing::Point(851, 677);
		this->lesser_ice->Name = L"lesser_ice";
		this->lesser_ice->Size = System::Drawing::Size(40, 40);
		this->lesser_ice->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->lesser_ice->TabIndex = 10;
		this->lesser_ice->TabStop = false;
		this->lesser_ice->Tag = L"3";
		this->ability_info->SetToolTip(this->lesser_ice, L"Lesser Ice\r\n\r\n40 Damage\r\n40 Mana Cost\r\n");
		this->lesser_ice->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
		// 
		// greater_ice
		// 
		this->greater_ice->BackColor = System::Drawing::Color::Transparent;
		this->greater_ice->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->greater_ice->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"greater_ice.Image")));
		this->greater_ice->Location = System::Drawing::Point(899, 677);
		this->greater_ice->Name = L"greater_ice";
		this->greater_ice->Size = System::Drawing::Size(40, 40);
		this->greater_ice->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->greater_ice->TabIndex = 11;
		this->greater_ice->TabStop = false;
		this->greater_ice->Tag = L"4";
		this->ability_info->SetToolTip(this->greater_ice, L"Greater Ice\r\n\r\n50 Damage\r\n50 Mana Cost");
		this->greater_ice->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
		// 
		// electric_storm
		// 
		this->electric_storm->BackColor = System::Drawing::Color::Transparent;
		this->electric_storm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->electric_storm->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"electric_storm.Image")));
		this->electric_storm->Location = System::Drawing::Point(946, 677);
		this->electric_storm->Name = L"electric_storm";
		this->electric_storm->Size = System::Drawing::Size(40, 40);
		this->electric_storm->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->electric_storm->TabIndex = 12;
		this->electric_storm->TabStop = false;
		this->electric_storm->Tag = L"8";
		this->ability_info->SetToolTip(this->electric_storm, L"Electric Storm\r\n\r\n60 Damage\r\n60 Mana Cost\r\n");
		this->electric_storm->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
		// 
		// heal
		// 
		this->heal->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(206)), static_cast<System::Int32>(static_cast<System::Byte>(141)), 
			static_cast<System::Int32>(static_cast<System::Byte>(0)));
		this->heal->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
		this->heal->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"heal.Image")));
		this->heal->Location = System::Drawing::Point(233, 677);
		this->heal->Name = L"heal";
		this->heal->Size = System::Drawing::Size(40, 40);
		this->heal->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->heal->TabIndex = 13;
		this->heal->TabStop = false;
		this->heal->Tag = L"11";
		this->ability_info->SetToolTip(this->heal, L"Health Potion\r\n\r\n50 Restore Health");
		this->heal->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
		// 
		// pictureBox1
		// 
		this->pictureBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(206)), static_cast<System::Int32>(static_cast<System::Byte>(141)), 
			static_cast<System::Int32>(static_cast<System::Byte>(0)));
		this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
		this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
		this->pictureBox1->Location = System::Drawing::Point(187, 677);
		this->pictureBox1->Name = L"pictureBox1";
		this->pictureBox1->Size = System::Drawing::Size(40, 40);
		this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->pictureBox1->TabIndex = 14;
		this->pictureBox1->TabStop = false;
		this->pictureBox1->Tag = L"11";
		this->ability_info->SetToolTip(this->pictureBox1, L"Health Potion\r\n\r\n50 Restore Health");
		this->pictureBox1->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
		// 
		// pictureBox2
		// 
		this->pictureBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(206)), static_cast<System::Int32>(static_cast<System::Byte>(141)), 
			static_cast<System::Int32>(static_cast<System::Byte>(0)));
		this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
		this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
		this->pictureBox2->Location = System::Drawing::Point(141, 677);
		this->pictureBox2->Name = L"pictureBox2";
		this->pictureBox2->Size = System::Drawing::Size(40, 40);
		this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->pictureBox2->TabIndex = 15;
		this->pictureBox2->TabStop = false;
		this->pictureBox2->Tag = L"11";
		this->ability_info->SetToolTip(this->pictureBox2, L"Health Potion\r\n\r\n50 Restore Health");
		this->pictureBox2->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
		// 
		// pictureBox3
		// 
		this->pictureBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(206)), static_cast<System::Int32>(static_cast<System::Byte>(141)), 
			static_cast<System::Int32>(static_cast<System::Byte>(0)));
		this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
		this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox3.Image")));
		this->pictureBox3->Location = System::Drawing::Point(95, 677);
		this->pictureBox3->Name = L"pictureBox3";
		this->pictureBox3->Size = System::Drawing::Size(40, 40);
		this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->pictureBox3->TabIndex = 16;
		this->pictureBox3->TabStop = false;
		this->pictureBox3->Tag = L"11";
		this->ability_info->SetToolTip(this->pictureBox3, L"Health Potion\r\n\r\n50 Restore Health");
		this->pictureBox3->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
		// 
		// pictureBox4
		// 
		this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
		this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox4.Image")));
		this->pictureBox4->Location = System::Drawing::Point(559, 13);
		this->pictureBox4->Name = L"pictureBox4";
		this->pictureBox4->Size = System::Drawing::Size(30, 38);
		this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
		this->pictureBox4->TabIndex = 17;
		this->pictureBox4->TabStop = false;
		// 
		// pictureBox5
		// 
		this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
		this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox5.Image")));
		this->pictureBox5->Location = System::Drawing::Point(595, 13);
		this->pictureBox5->Name = L"pictureBox5";
		this->pictureBox5->Size = System::Drawing::Size(30, 38);
		this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
		this->pictureBox5->TabIndex = 18;
		this->pictureBox5->TabStop = false;
		// 
		// pictureBox6
		// 
		this->pictureBox6->BackColor = System::Drawing::Color::Transparent;
		this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox6.Image")));
		this->pictureBox6->Location = System::Drawing::Point(631, 12);
		this->pictureBox6->Name = L"pictureBox6";
		this->pictureBox6->Size = System::Drawing::Size(30, 38);
		this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
		this->pictureBox6->TabIndex = 19;
		this->pictureBox6->TabStop = false;
		// 
		// pictureBox7
		// 
		this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
		this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox7.Image")));
		this->pictureBox7->Location = System::Drawing::Point(667, 13);
		this->pictureBox7->Name = L"pictureBox7";
		this->pictureBox7->Size = System::Drawing::Size(30, 38);
		this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
		this->pictureBox7->TabIndex = 20;
		this->pictureBox7->TabStop = false;
		// 
		// pictureBox8
		// 
		this->pictureBox8->BackColor = System::Drawing::Color::Transparent;
		this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox8.Image")));
		this->pictureBox8->Location = System::Drawing::Point(703, 13);
		this->pictureBox8->Name = L"pictureBox8";
		this->pictureBox8->Size = System::Drawing::Size(30, 38);
		this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
		this->pictureBox8->TabIndex = 21;
		this->pictureBox8->TabStop = false;
		// 
		// ApprenticeTrial
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::Black;
		this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
		this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
		this->ClientSize = System::Drawing::Size(1008, 729);
		this->Controls->Add(this->pictureBox8);
		this->Controls->Add(this->pictureBox7);
		this->Controls->Add(this->pictureBox6);
		this->Controls->Add(this->pictureBox5);
		this->Controls->Add(this->pictureBox4);
		this->Controls->Add(this->pictureBox3);
		this->Controls->Add(this->pictureBox2);
		this->Controls->Add(this->pictureBox1);
		this->Controls->Add(this->heal);
		this->Controls->Add(this->electric_storm);
		this->Controls->Add(this->greater_ice);
		this->Controls->Add(this->lesser_ice);
		this->Controls->Add(this->whirlwind);
		this->Controls->Add(this->greater_wand);
		this->Controls->Add(this->lesser_wand);
		this->MaximizeBox = false;
		this->MaximumSize = System::Drawing::Size(1024, 768);
		this->MinimizeBox = false;
		this->MinimumSize = System::Drawing::Size(1024, 766);
		this->Name = L"ApprenticeTrial";
		this->Text = L"The Apprentice\'s Trial";
		this->Load += gcnew System::EventHandler(this, &ApprenticeTrial::ApprenticeTrial_Load);
		this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ApprenticeTrial::ApprenticeTrial_MouseClick);
		this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &ApprenticeTrial::ApprenticeTrial_KeyDown);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lesser_wand))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->greater_wand))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->whirlwind))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lesser_ice))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->greater_ice))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->electric_storm))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->heal))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->EndInit();
		this->ResumeLayout(false);
		this->PerformLayout();

			}
#pragma endregion

	private: System::Void ApprenticeTrial_Load(System::Object^  sender, System::EventArgs^  e) {
				 gManager = gcnew GameManager(CreateGraphics(), ClientRectangle);
				 clock->Enabled = true;				 
				 Focus();
			 }
	private: System::Void ApprenticeTrial_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 gManager->MouseDown(e->Location);
			 }	
	private: System::Void clock_Tick(System::Object^  sender, System::EventArgs^  e) {
				 gManager->Draw();
			 }
	private: System::Void secondary_clock_Tick(System::Object^  sender, System::EventArgs^  e) {
				 gManager->Update();
			 }
	private: System::Void ApprenticeTrial_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 gManager->KeyDown(e->KeyCode);
			 }	
	private: System::Void button_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
				 Button^ button = safe_cast<Button^>(sender);				 
			 }
	private: System::Void button_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
				 Button^ button = safe_cast<Button^>(sender);				 
			 }

	private: System::Windows::Forms::Cursor^ ApprenticeTrial::getAbilityCursor(PictureBox^ ability) {
				 // Gets the image from the picturebox 
				 Bitmap^ bmp = safe_cast<Bitmap^>(ability->Image);

				 // Gets the image data from bitmap  
				 IntPtr ptr = bmp->GetHicon();
					 
				 // Returns the new cursor
				 return gcnew System::Windows::Forms::Cursor(ptr);
			 }

	private: System::Void ability_Click(System::Object^  sender, System::EventArgs^  e) {
				 //Gets object clicked by player
				 PictureBox^ ability = safe_cast<PictureBox^>(sender);

				 EState playerAbility = safe_cast<EState>(int::Parse(ability->Tag->ToString()));

				 if(gManager->canUseAbility(playerAbility) || playerAbility == HEAL)
				 {
					 // Tracks ability clicked by player
					 selectedAbility = playerAbility;

					 Text = ability->Tag->ToString();
						 
					 // Changes Cursor to clicked ability
					 Cursor = getAbilityCursor(ability);
				 }
				 else
				 {
					 Text = "NOT ENOUGH MANA";
				 }						
				 //Removes potion from hud
				 //if(selectedAbility == HEAL) ability->Image = Image::FromFile("clear.png");
			 }			 
	private: System::Void ApprenticeTrial_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 Point location = e->Location;
				 
				 switch ( e->Button )
				 {
					case ::MouseButtons::Left:
						if(gManager->clickedOnEnemy(location) && selectedAbility != HEAL)
						{
							if(gManager->canUseAbility(selectedAbility))
							{
								gManager->setPlayerAbility(selectedAbility);
								gManager->StartAttack();
								Cursor = Cursors::Arrow;
							}														
						}	
						else if(gManager->clickedOnPlayer(location) && selectedAbility == HEAL)
						{
							gManager->setPlayerAbility(selectedAbility);
							gManager->StartAttack();
							Cursor = Cursors::Arrow;

						}
					   break;

					case ::MouseButtons::Right:
						Cursor = Cursors::Arrow;
					   break;

					case ::MouseButtons::Middle:
					   break;

					case ::MouseButtons::XButton1:
					   break;

					case ::MouseButtons::XButton2:
					   break;

					case ::MouseButtons::None:
					default:
					   break;
				 }
			 }
};
}

