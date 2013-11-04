#pragma once

#include "Constants.h"
#include "GameManager.h"
#include "FrameManager.h"

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

	private: Player^ player;
	private: Enemy^ cocoon;
	private: Enemy^ makhana;
	private: Enemy^ floppit;
	private: Enemy^ fluppit;
	private: Enemy^ peruna;

	private: bool selected;
	private: bool gameHasLoaded;
	private: int time;
	private: int loading;
	private: Graphics^ formCanvas;
	private: Graphics^ dbGraphics;
	private: Bitmap^ dbBitmap;
	private: EState selectedAbility;
	private: GameManager^ gManager;
	private: FrameManager^ fManager;
	private: System::Windows::Forms::Timer^  draw;
	private: System::Windows::Forms::Timer^  update;


	private: System::Windows::Forms::PictureBox^  lesser_wand;
	private: System::Windows::Forms::PictureBox^  greater_wand;
	private: System::Windows::Forms::PictureBox^  whirlwind;
	private: System::Windows::Forms::PictureBox^  lesser_ice;
	private: System::Windows::Forms::PictureBox^  greater_ice;
	private: System::Windows::Forms::PictureBox^  electric_storm;
	private: System::Windows::Forms::PictureBox^  health_potion1;

	private: System::Windows::Forms::ToolTip^  ability_info;
	private: System::Windows::Forms::PictureBox^  health_potion2;
	private: System::Windows::Forms::PictureBox^  mana_potion1;
	private: System::Windows::Forms::PictureBox^  mana_potion2;








	private: System::Windows::Forms::PictureBox^  mana_potion3;
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label3;



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
			this->draw = (gcnew System::Windows::Forms::Timer(this->components));
			this->update = (gcnew System::Windows::Forms::Timer(this->components));
			this->lesser_wand = (gcnew System::Windows::Forms::PictureBox());
			this->greater_wand = (gcnew System::Windows::Forms::PictureBox());
			this->whirlwind = (gcnew System::Windows::Forms::PictureBox());
			this->lesser_ice = (gcnew System::Windows::Forms::PictureBox());
			this->greater_ice = (gcnew System::Windows::Forms::PictureBox());
			this->electric_storm = (gcnew System::Windows::Forms::PictureBox());
			this->health_potion1 = (gcnew System::Windows::Forms::PictureBox());
			this->ability_info = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->health_potion2 = (gcnew System::Windows::Forms::PictureBox());
			this->mana_potion1 = (gcnew System::Windows::Forms::PictureBox());
			this->mana_potion2 = (gcnew System::Windows::Forms::PictureBox());
			this->mana_potion3 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lesser_wand))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->greater_wand))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->whirlwind))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lesser_ice))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->greater_ice))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->electric_storm))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->health_potion1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->health_potion2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mana_potion1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mana_potion2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mana_potion3))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// draw
			// 
			this->draw->Interval = 1;
			this->draw->Tick += gcnew System::EventHandler(this, &ApprenticeTrial::draw_Tick);
			// 
			// update
			// 
			this->update->Interval = 1000;
			this->update->Tick += gcnew System::EventHandler(this, &ApprenticeTrial::update_Tick);
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
			// health_potion1
			// 
			this->health_potion1->AccessibleDescription = L"health";
			this->health_potion1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(206)), static_cast<System::Int32>(static_cast<System::Byte>(141)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->health_potion1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->health_potion1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"health_potion1.Image")));
			this->health_potion1->Location = System::Drawing::Point(233, 677);
			this->health_potion1->Name = L"health_potion1";
			this->health_potion1->Size = System::Drawing::Size(40, 40);
			this->health_potion1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->health_potion1->TabIndex = 13;
			this->health_potion1->TabStop = false;
			this->health_potion1->Tag = L"11";
			this->ability_info->SetToolTip(this->health_potion1, L"Health Potion\r\n\r\n50 Restore Health");
			this->health_potion1->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
			// 
			// health_potion2
			// 
			this->health_potion2->AccessibleDescription = L"health";
			this->health_potion2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(206)), static_cast<System::Int32>(static_cast<System::Byte>(141)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->health_potion2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->health_potion2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"health_potion2.Image")));
			this->health_potion2->Location = System::Drawing::Point(187, 677);
			this->health_potion2->Name = L"health_potion2";
			this->health_potion2->Size = System::Drawing::Size(40, 40);
			this->health_potion2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->health_potion2->TabIndex = 14;
			this->health_potion2->TabStop = false;
			this->health_potion2->Tag = L"11";
			this->ability_info->SetToolTip(this->health_potion2, L"Health Potion\r\n\r\n50 Restore Health");
			this->health_potion2->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
			// 
			// mana_potion1
			// 
			this->mana_potion1->AccessibleDescription = L"mana";
			this->mana_potion1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(206)), static_cast<System::Int32>(static_cast<System::Byte>(141)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->mana_potion1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->mana_potion1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mana_potion1.Image")));
			this->mana_potion1->Location = System::Drawing::Point(141, 677);
			this->mana_potion1->Name = L"mana_potion1";
			this->mana_potion1->Size = System::Drawing::Size(40, 40);
			this->mana_potion1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->mana_potion1->TabIndex = 15;
			this->mana_potion1->TabStop = false;
			this->mana_potion1->Tag = L"11";
			this->ability_info->SetToolTip(this->mana_potion1, L"Health Potion\r\n\r\n50 Restore Health");
			this->mana_potion1->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
			// 
			// mana_potion2
			// 
			this->mana_potion2->AccessibleDescription = L"mana";
			this->mana_potion2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(206)), static_cast<System::Int32>(static_cast<System::Byte>(141)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->mana_potion2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->mana_potion2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mana_potion2.Image")));
			this->mana_potion2->Location = System::Drawing::Point(95, 677);
			this->mana_potion2->Name = L"mana_potion2";
			this->mana_potion2->Size = System::Drawing::Size(40, 40);
			this->mana_potion2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->mana_potion2->TabIndex = 16;
			this->mana_potion2->TabStop = false;
			this->mana_potion2->Tag = L"11";
			this->ability_info->SetToolTip(this->mana_potion2, L"Health Potion\r\n\r\n50 Restore Health");
			this->mana_potion2->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
			// 
			// mana_potion3
			// 
			this->mana_potion3->AccessibleDescription = L"mana";
			this->mana_potion3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(206)), static_cast<System::Int32>(static_cast<System::Byte>(141)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->mana_potion3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->mana_potion3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mana_potion3.Image")));
			this->mana_potion3->Location = System::Drawing::Point(49, 677);
			this->mana_potion3->Name = L"mana_potion3";
			this->mana_potion3->Size = System::Drawing::Size(40, 40);
			this->mana_potion3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->mana_potion3->TabIndex = 22;
			this->mana_potion3->TabStop = false;
			this->mana_potion3->Tag = L"11";
			this->ability_info->SetToolTip(this->mana_potion3, L"Health Potion\r\n\r\n50 Restore Health");
			this->mana_potion3->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(681, 611);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(235, 60);
			this->button1->TabIndex = 23;
			this->button1->Text = L"PLAY";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ApprenticeTrial::button1_Click);
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->progressBar1);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->richTextBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1008, 729);
			this->panel1->TabIndex = 25;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Tahoma", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0), true));
			this->label2->ForeColor = System::Drawing::SystemColors::Info;
			this->label2->Location = System::Drawing::Point(79, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(563, 72);
			this->label2->TabIndex = 28;
			this->label2->Text = L"The Apprentice\'s Trial";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->UseCompatibleTextRendering = true;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0), true));
			this->label1->ForeColor = System::Drawing::SystemColors::Info;
			this->label1->Location = System::Drawing::Point(187, 565);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(488, 72);
			this->label1->TabIndex = 26;
			this->label1->Text = L"Loading";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->UseCompatibleTextRendering = true;
			this->label1->Visible = false;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(0, 640);
			this->progressBar1->Maximum = 140;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(1008, 60);
			this->progressBar1->Step = 1;
			this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar1->TabIndex = 25;
			this->progressBar1->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Black;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(49, 504);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(138, 185);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 29;
			this->pictureBox1->TabStop = false;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::Black;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->richTextBox1->DetectUrls = false;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0), true));
			this->richTextBox1->ForeColor = System::Drawing::SystemColors::Info;
			this->richTextBox1->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->richTextBox1->Location = System::Drawing::Point(95, 160);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(50);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->richTextBox1->ShortcutsEnabled = false;
			this->richTextBox1->ShowSelectionMargin = true;
			this->richTextBox1->Size = System::Drawing::Size(821, 345);
			this->richTextBox1->TabIndex = 27;
			this->richTextBox1->Text = resources->GetString(L"richTextBox1.Text");
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0), true));
			this->label3->Location = System::Drawing::Point(563, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(164, 45);
			this->label3->TabIndex = 26;
			this->label3->Text = L"Floppit";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label3->UseCompatibleTextRendering = true;
			// 
			// ApprenticeTrial
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1008, 729);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->mana_potion3);
			this->Controls->Add(this->mana_potion2);
			this->Controls->Add(this->mana_potion1);
			this->Controls->Add(this->health_potion2);
			this->Controls->Add(this->health_potion1);
			this->Controls->Add(this->electric_storm);
			this->Controls->Add(this->greater_ice);
			this->Controls->Add(this->lesser_ice);
			this->Controls->Add(this->whirlwind);
			this->Controls->Add(this->greater_wand);
			this->Controls->Add(this->lesser_wand);
			this->Controls->Add(this->label3);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->health_potion1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->health_potion2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mana_potion1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mana_potion2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mana_potion3))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void ApprenticeTrial_Load(System::Object^  sender, System::EventArgs^  e) {
				 formCanvas = CreateGraphics();
				 //
				 // Create graphics size of the screen
				 //
				 dbBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);		 
				 //
				 // Grab its Graphics
				 //
				 dbGraphics = Graphics::FromImage(dbBitmap);

				 fManager = gcnew FrameManager();
				 Focus();

				 richTextBox1->SelectionStart = richTextBox1->Text->Length;
				 richTextBox1->ScrollToCaret();
			 }
	private: System::Void ApprenticeTrial_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 gManager->MouseDown(e->Location);
			 }	
	private: System::Void draw_Tick(System::Object^  sender, System::EventArgs^  e) {
				 if(gameHasLoaded)
				 {
					 

					 label3->Text = gManager->getEnemyInPlayName();

					 if(gManager->isGameOver())
					 {
						 draw->Enabled = false;
						 label1->Visible = false;
						 progressBar1->Visible = false;
						 panel1->Visible = true;
						 button1->Visible = true;
					 }

					 gManager->Update();
					 gManager->Draw();
					 //
					 // Make Buffer Visible 
					 //
					 formCanvas->DrawImage(dbBitmap, ClientRectangle);
				 }
				 else
				 {
					 progressBar1->Value = loading;
					 loading++;
				 }
			 }
	private: System::Void update_Tick(System::Object^  sender, System::EventArgs^  e) {
				 int startY = ClientRectangle.Height - 200;

				 array<Point>^ startLocations = gcnew array<Point>
				 { 
					 Point(250,			        startY),
					 Point((T_WIDTH)	 - 100, startY),
					 Point((T_WIDTH * 2) - 100, startY),
					 Point((T_WIDTH * 3) - 100, startY),
					 Point((T_WIDTH * 4) - 100, startY),
					 Point((T_WIDTH * 5) - 100, startY),
				 };

				 

				 //
				// Create Player
				//
				player = gcnew Player
				(
					dbGraphics, 
					"player", 				
					startLocations[PLAYER],
					fManager->getPlayerList()
				);

				draw->Enabled = false;

				label1->Text = "Creating Player";
				label1->Refresh();
				time += 20;
				progressBar1->Value = time;
							
				/// <summary>
				/// Required method for Designer support - do not modify
				/// the contents of this method with the code editor.
				/// </summary>
				cocoon = gcnew Enemy
				(
					dbGraphics, 
					"cocoon", 				
					startLocations[COCOON],
					fManager->getCocoonList()
				);

				label1->Text = "Creating Cocoon";
				label1->Refresh();
				time += 20;
				progressBar1->Value = time;
				//
				//
				//			
				makhana = gcnew Enemy
				(
					dbGraphics, 
					"makhana", 				
					startLocations[MAKHANA],
					fManager->getMakhanaList()
				);

				label1->Text = "Creating Makhana";
				label1->Refresh();
				time += 20;
				progressBar1->Value = time;
				//
				//
				//
				floppit = gcnew Enemy
				(
					dbGraphics, 
					"floppit", 				 
					startLocations[FLOPPIT],
					fManager->getFloppitList()
				);

				label1->Text = "Creating Floppit";
				label1->Refresh();
				time += 20;
				progressBar1->Value = time;
				//
				//
				//
				fluppit = gcnew Enemy
				(
					dbGraphics, 
					"fluppit", 				
					startLocations[FLUPPIT],
					fManager->getFluppitList()
				);

				label1->Text = "Creating Fluppit";
				label1->Refresh();
				time += 20;
				progressBar1->Value = time;
				//
				//
				//			
				peruna = gcnew Enemy
				(
					dbGraphics, 
					"peruna",
					startLocations[PERUNA],
					fManager->getPerunaList()
				);

				label1->Text = "Creating Peruna";
				label1->Refresh();
				time += 20;
				progressBar1->Value = time;

				gManager = gcnew GameManager(dbGraphics, ClientRectangle, player, gcnew array<Enemy^>{floppit, fluppit, peruna, cocoon, makhana});

				label1->Text = "Starting game";
				label1->Refresh();
				time = 0;
				loading = 0;
				progressBar1->Value = 0;
				

				Threading::Thread::Sleep(1000);
				gameHasLoaded = true;
				panel1->Visible = false;
				draw->Enabled = true;
				update->Enabled = false;
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

				 if(playerAbility == HEAL)
				 {
					 gManager->setPlayerPotion(ability->AccessibleDescription->ToString());					 
				 }

				 if(gManager->canUseAbility(playerAbility) || playerAbility == HEAL)
				 {
					 // Tracks ability clicked by player
					 selectedAbility = playerAbility;

					 //Text = ability->Tag->ToString();
						 
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
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 player = nullptr;
			 cocoon = nullptr;
			 makhana = nullptr;
			 floppit = nullptr;
			 fluppit = nullptr;
			 peruna = nullptr;
			 gManager = nullptr;
			 delete gManager;
			 GC::GetTotalMemory(true);
			 GC::Collect(0);
			 gameHasLoaded = false;
			 update->Enabled = true;
			 draw->Enabled = true;
			 label1->Visible = true;
			 progressBar1->Visible = true;
			 button1->Visible = false;
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 draw->Enabled = false;

			 gManager = nullptr;
			 delete gManager;
			 GC::GetTotalMemory(true);
			 GC::Collect(0);

			 gManager = gcnew GameManager(dbGraphics, ClientRectangle, player, gcnew array<Enemy^>{floppit, fluppit, peruna, cocoon, makhana});	
			 panel1->Visible = false;
			 draw->Enabled = true;
		 }

};
}

