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

	private: Image^ lesserWandImage;
	private: Image^ greaterWandImage;
	private: Image^ whirlwindImage;
	private: Image^ lesserIceImage;
	private: Image^ greaterIceImage;
	private: Image^ electricStormImage;
	private: Image^ clearImage;


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
	private: System::Windows::Forms::Timer^  load;



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
	private: System::Windows::Forms::Button^  play;
	private: System::Windows::Forms::Panel^  load_screen;




	private: System::Windows::Forms::Label^  loading_events;
	private: System::Windows::Forms::ProgressBar^  loading_bar;
	private: System::Windows::Forms::RichTextBox^  story;
	private: System::Windows::Forms::Label^  title;
	private: System::Windows::Forms::PictureBox^  apprentice;
	private: System::Windows::Forms::Label^  status;
	private: System::Windows::Forms::Panel^  start_screen;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  quit;

	private: System::Windows::Forms::Button^  help;
	private: System::Windows::Forms::Label^  label2;











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
		this->load = (gcnew System::Windows::Forms::Timer(this->components));
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
		this->play = (gcnew System::Windows::Forms::Button());
		this->load_screen = (gcnew System::Windows::Forms::Panel());
		this->start_screen = (gcnew System::Windows::Forms::Panel());
		this->quit = (gcnew System::Windows::Forms::Button());
		this->help = (gcnew System::Windows::Forms::Button());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->apprentice = (gcnew System::Windows::Forms::PictureBox());
		this->title = (gcnew System::Windows::Forms::Label());
		this->loading_bar = (gcnew System::Windows::Forms::ProgressBar());
		this->story = (gcnew System::Windows::Forms::RichTextBox());
		this->loading_events = (gcnew System::Windows::Forms::Label());
		this->status = (gcnew System::Windows::Forms::Label());
		this->label2 = (gcnew System::Windows::Forms::Label());
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
		this->load_screen->SuspendLayout();
		this->start_screen->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->apprentice))->BeginInit();
		this->SuspendLayout();
		// 
		// draw
		// 
		this->draw->Interval = 1;
		this->draw->Tick += gcnew System::EventHandler(this, &ApprenticeTrial::draw_Tick);
		// 
		// load
		// 
		this->load->Interval = 1000;
		this->load->Tick += gcnew System::EventHandler(this, &ApprenticeTrial::update_Tick);
		// 
		// lesser_wand
		// 
		this->lesser_wand->AccessibleDescription = L"10";
		this->lesser_wand->AccessibleName = L"10";
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
		this->greater_wand->AccessibleDescription = L"20";
		this->greater_wand->AccessibleName = L"20";
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
		this->whirlwind->AccessibleDescription = L"30";
		this->whirlwind->AccessibleName = L"30";
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
		this->lesser_ice->AccessibleDescription = L"40";
		this->lesser_ice->AccessibleName = L"40";
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
		this->greater_ice->AccessibleDescription = L"50";
		this->greater_ice->AccessibleName = L"50";
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
		this->electric_storm->AccessibleDescription = L"60";
		this->electric_storm->AccessibleName = L"60";
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
		this->health_potion1->AccessibleDescription = L"50";
		this->health_potion1->AccessibleName = L"health";
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
		this->health_potion2->AccessibleDescription = L"50";
		this->health_potion2->AccessibleName = L"health";
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
		this->mana_potion1->AccessibleDescription = L"50";
		this->mana_potion1->AccessibleName = L"mana";
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
		this->ability_info->SetToolTip(this->mana_potion1, L"Mana Potion\r\n\r\n50 Restore Mana");
		this->mana_potion1->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
		// 
		// mana_potion2
		// 
		this->mana_potion2->AccessibleDescription = L"50";
		this->mana_potion2->AccessibleName = L"mana";
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
		this->ability_info->SetToolTip(this->mana_potion2, L"Mana Potion\r\n\r\n50 Restore Mana");
		this->mana_potion2->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
		// 
		// mana_potion3
		// 
		this->mana_potion3->AccessibleDescription = L"50";
		this->mana_potion3->AccessibleName = L"mana";
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
		this->ability_info->SetToolTip(this->mana_potion3, L"Mana Potion\r\n\r\n50 Restore Mana");
		this->mana_potion3->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
		// 
		// play
		// 
		this->play->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
		this->play->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->play->Location = System::Drawing::Point(391, 308);
		this->play->Name = L"play";
		this->play->Size = System::Drawing::Size(235, 60);
		this->play->TabIndex = 23;
		this->play->Text = L"PLAY";
		this->play->UseVisualStyleBackColor = true;
		this->play->Click += gcnew System::EventHandler(this, &ApprenticeTrial::play_Click);
		// 
		// load_screen
		// 
		this->load_screen->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"load_screen.BackgroundImage")));
		this->load_screen->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->load_screen->Controls->Add(this->start_screen);
		this->load_screen->Controls->Add(this->title);
		this->load_screen->Controls->Add(this->loading_bar);
		this->load_screen->Controls->Add(this->story);
		this->load_screen->Controls->Add(this->loading_events);
		this->load_screen->Dock = System::Windows::Forms::DockStyle::Fill;
		this->load_screen->Location = System::Drawing::Point(0, 0);
		this->load_screen->Name = L"load_screen";
		this->load_screen->Size = System::Drawing::Size(1008, 729);
		this->load_screen->TabIndex = 25;
		// 
		// start_screen
		// 
		this->start_screen->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->start_screen->Controls->Add(this->label2);
		this->start_screen->Controls->Add(this->quit);
		this->start_screen->Controls->Add(this->help);
		this->start_screen->Controls->Add(this->label1);
		this->start_screen->Controls->Add(this->play);
		this->start_screen->Controls->Add(this->apprentice);
		this->start_screen->Dock = System::Windows::Forms::DockStyle::Fill;
		this->start_screen->Location = System::Drawing::Point(0, 0);
		this->start_screen->Name = L"start_screen";
		this->start_screen->Size = System::Drawing::Size(1008, 729);
		this->start_screen->TabIndex = 30;
		// 
		// quit
		// 
		this->quit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
		this->quit->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->quit->Location = System::Drawing::Point(391, 507);
		this->quit->Name = L"quit";
		this->quit->Size = System::Drawing::Size(235, 60);
		this->quit->TabIndex = 32;
		this->quit->Text = L"QUIT";
		this->quit->UseVisualStyleBackColor = true;
		this->quit->Click += gcnew System::EventHandler(this, &ApprenticeTrial::quit_Click);
		// 
		// help
		// 
		this->help->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
		this->help->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->help->Location = System::Drawing::Point(391, 408);
		this->help->Name = L"help";
		this->help->Size = System::Drawing::Size(235, 60);
		this->help->TabIndex = 31;
		this->help->Text = L"HELP";
		this->help->UseVisualStyleBackColor = true;
		// 
		// label1
		// 
		this->label1->BackColor = System::Drawing::Color::Transparent;
		this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0), true));
		this->label1->ForeColor = System::Drawing::SystemColors::Info;
		this->label1->Location = System::Drawing::Point(214, 54);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(563, 72);
		this->label1->TabIndex = 30;
		this->label1->Text = L"The Apprentice\'s Trial";
		this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->label1->UseCompatibleTextRendering = true;
		// 
		// apprentice
		// 
		this->apprentice->BackColor = System::Drawing::Color::Transparent;
		this->apprentice->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"apprentice.Image")));
		this->apprentice->Location = System::Drawing::Point(837, 507);
		this->apprentice->Name = L"apprentice";
		this->apprentice->Size = System::Drawing::Size(138, 185);
		this->apprentice->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
		this->apprentice->TabIndex = 29;
		this->apprentice->TabStop = false;
		// 
		// title
		// 
		this->title->BackColor = System::Drawing::Color::Transparent;
		this->title->Font = (gcnew System::Drawing::Font(L"Tahoma", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0), true));
		this->title->ForeColor = System::Drawing::SystemColors::Info;
		this->title->Location = System::Drawing::Point(214, 54);
		this->title->Name = L"title";
		this->title->Size = System::Drawing::Size(563, 72);
		this->title->TabIndex = 28;
		this->title->Text = L"The Apprentice\'s Trial";
		this->title->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->title->UseCompatibleTextRendering = true;
		// 
		// loading_bar
		// 
		this->loading_bar->Location = System::Drawing::Point(0, 661);
		this->loading_bar->Maximum = 140;
		this->loading_bar->Name = L"loading_bar";
		this->loading_bar->Size = System::Drawing::Size(1008, 10);
		this->loading_bar->Step = 1;
		this->loading_bar->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
		this->loading_bar->TabIndex = 25;
		// 
		// story
		// 
		this->story->BackColor = System::Drawing::Color::Black;
		this->story->BorderStyle = System::Windows::Forms::BorderStyle::None;
		this->story->Cursor = System::Windows::Forms::Cursors::Arrow;
		this->story->DetectUrls = false;
		this->story->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0), true));
		this->story->ForeColor = System::Drawing::SystemColors::Info;
		this->story->ImeMode = System::Windows::Forms::ImeMode::Off;
		this->story->Location = System::Drawing::Point(197, 186);
		this->story->Margin = System::Windows::Forms::Padding(50);
		this->story->Name = L"story";
		this->story->ReadOnly = true;
		this->story->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
		this->story->ShortcutsEnabled = false;
		this->story->ShowSelectionMargin = true;
		this->story->Size = System::Drawing::Size(620, 405);
		this->story->TabIndex = 27;
		this->story->Text = resources->GetString(L"story.Text");
		// 
		// loading_events
		// 
		this->loading_events->BackColor = System::Drawing::Color::Transparent;
		this->loading_events->Font = (gcnew System::Drawing::Font(L"Tahoma", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0), true));
		this->loading_events->ForeColor = System::Drawing::SystemColors::Info;
		this->loading_events->Location = System::Drawing::Point(610, 597);
		this->loading_events->Name = L"loading_events";
		this->loading_events->Size = System::Drawing::Size(386, 60);
		this->loading_events->TabIndex = 26;
		this->loading_events->Text = L"Loading";
		this->loading_events->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->loading_events->UseCompatibleTextRendering = true;
		// 
		// status
		// 
		this->status->BackColor = System::Drawing::Color::Transparent;
		this->status->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0), true));
		this->status->Location = System::Drawing::Point(563, 9);
		this->status->Name = L"status";
		this->status->Size = System::Drawing::Size(164, 45);
		this->status->TabIndex = 26;
		this->status->Text = L"Floppit";
		this->status->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->status->UseCompatibleTextRendering = true;
		// 
		// label2
		// 
		this->label2->BackColor = System::Drawing::Color::Transparent;
		this->label2->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0), true));
		this->label2->ForeColor = System::Drawing::SystemColors::Info;
		this->label2->Location = System::Drawing::Point(12, 661);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(169, 52);
		this->label2->TabIndex = 33;
		this->label2->Text = L"Copyright";
		this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->label2->UseCompatibleTextRendering = true;
		// 
		// ApprenticeTrial
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::Black;
		this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
		this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
		this->ClientSize = System::Drawing::Size(1008, 729);
		this->Controls->Add(this->load_screen);
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
		this->Controls->Add(this->status);
		this->MaximizeBox = false;
		this->MaximumSize = System::Drawing::Size(1024, 768);
		this->MinimizeBox = false;
		this->MinimumSize = System::Drawing::Size(1024, 766);
		this->Name = L"ApprenticeTrial";
		this->Text = L"The Apprentice\'s Trial";
		this->Load += gcnew System::EventHandler(this, &ApprenticeTrial::ApprenticeTrial_Load);
		this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ApprenticeTrial::ApprenticeTrial_MouseClick);
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
		this->load_screen->ResumeLayout(false);
		this->start_screen->ResumeLayout(false);
		this->start_screen->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->apprentice))->EndInit();
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

				 lesserWandImage = Image::FromFile("lesserwand.png");
				 greaterWandImage = Image::FromFile("greaterwand.png");
				 whirlwindImage = Image::FromFile("whirlwind.png");
				 lesserIceImage = Image::FromFile("lesserrice.png");
				 greaterIceImage = Image::FromFile("greaterrice.png");
				 electricStormImage = Image::FromFile("electricstorm.png");
				 clearImage = Image::FromFile("clear.png");

				 fManager = gcnew FrameManager();
				 
				 Focus();
			 }
		
	private: System::Void draw_Tick(System::Object^  sender, System::EventArgs^  e) {
				 if(gameHasLoaded)
				 {
					 if(gManager->isPlayerTurn())
						status->Text = "player turn";
					 else
						status->Text = gManager->getEnemyInPlayName() + " turn";

					 if(gManager->isGameOver())
					 {
						 draw->Enabled = false;
						 load_screen->Visible = true;
						 start_screen->Visible = true;
					 }

					 int availableMana = gManager->getAvailableMana();
					 int lesserWandCost = int::Parse(lesser_wand->AccessibleDescription);
					 int greaterWandCost = int::Parse(greater_wand->AccessibleDescription);
					 int whirlwindCost = int::Parse(whirlwind->AccessibleDescription);
					 int lesserIceCost = int::Parse(lesser_ice->AccessibleDescription);
					 int greaterIceCost = int::Parse(greater_ice->AccessibleDescription);
					 int electricStormCost = int::Parse(electric_storm->AccessibleDescription);
					 
					 if(lesserWandCost < availableMana || greaterWandCost < availableMana ||
						whirlwindCost < availableMana  || lesserIceCost < availableMana   ||
						greaterIceCost < availableMana || electricStormCost < availableMana)
					 {
						lesser_wand->Image = (lesserWandCost < availableMana) ?  lesserWandImage: clearImage;					 
						greater_wand->Image = (greaterWandCost < availableMana) ? greaterWandImage : clearImage;					 
						whirlwind->Image = (whirlwindCost < availableMana) ? whirlwindImage : clearImage;					 
						lesser_ice->Image = (lesserIceCost < availableMana) ? lesserIceImage : clearImage;					 
						greater_ice->Image = (greaterIceCost < availableMana) ? greaterIceImage : clearImage;					 
						electric_storm->Image = (electricStormCost < availableMana) ? electricStormImage : clearImage;
						
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
					 loading_bar->Value = loading;
					 loading++;
				 }
			 }
	private: System::Void update_Tick(System::Object^  sender, System::EventArgs^  e) {
				 

				 int startY = ClientRectangle.Height - 200;

				 array<Point>^ startLocations = gcnew array<Point>
				 { 
					 Point(250,startY),
					 Point((T_WIDTH) - 100, startY),
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

				loading_events->Text = "Creating Player";
				loading_events->Refresh();
				time += 20;
				loading_bar->Value = time;
							
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

				loading_events->Text = "Creating Cocoon";
				loading_events->Refresh();
				time += 20;
				loading_bar->Value = time;
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

				loading_events->Text = "Creating Makhana";
				loading_events->Refresh();
				time += 20;
				loading_bar->Value = time;
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

				loading_events->Text = "Creating Floppit";
				loading_events->Refresh();
				time += 20;
				loading_bar->Value = time;
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

				loading_events->Text = "Creating Fluppit";
				loading_events->Refresh();
				time += 20;
				loading_bar->Value = time;
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

				loading_events->Text = "Creating Peruna";
				loading_events->Refresh();
				time += 20;
				loading_bar->Value = time;

				gManager = gcnew GameManager(dbGraphics, player, gcnew array<Enemy^>{floppit, fluppit, peruna, cocoon, makhana});

				loading_events->Text = "Starting game";
				loading_events->Refresh();
				time = 0;
				loading = 0;
				loading_bar->Value = loading_bar->Maximum;
				loading_bar->Refresh();
				
				gameHasLoaded = true;
				load_screen->Visible = false;

				draw->Enabled = true;
				load->Enabled = false;
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
					 gManager->setPlayerPotion(ability->AccessibleName->ToString());					 
				 }

				 int availableMana = gManager->getAvailableMana();
				 int abilityCost = int::Parse(ability->AccessibleDescription);

				 if(abilityCost < availableMana || playerAbility == HEAL)
				 {
					 // Tracks ability clicked by player
					 selectedAbility = playerAbility;

					 status->Text = "ATTACK!!";
						 
					 // Changes Cursor to clicked ability
					 Cursor = getAbilityCursor(ability);
				 }
				 else
				 {
					 
				 }

				 						
				 //Removes potion from hud
				 if(selectedAbility == HEAL) ability->Image = clearImage;
			 }			 
	private: System::Void ApprenticeTrial_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 Point location = e->Location;
				 
				 switch ( e->Button )
				 {
					case ::MouseButtons::Left:
						if(gManager->clickedOnEnemy(location) && selectedAbility != HEAL)
						{
							gManager->setPlayerAbility(selectedAbility);
							gManager->StartAttack();
							Cursor = Cursors::Arrow;														
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
private: System::Void play_Click(System::Object^  sender, System::EventArgs^  e) {
			 //
			 // Clean up
			 //
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

			 load->Enabled = true;
			 draw->Enabled = true;

			 
			 //loading_events->Visible = true;
			 //loading_bar->Visible = true;

			 
			 start_screen->Visible = false;
		 }
	private: System::Void quit_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
		 }
};
}

