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
	private: Point cursorLocation;
	private: Graphics^ formCanvas;
	private: Graphics^ dbGraphics;
	private: Bitmap^ dbBitmap;
	private: EState selectedAbility;
	private: GameManager^ gManager;
	private: FrameManager^ fManager;
	private: System::Windows::Forms::Timer^  draw;
	private: System::Windows::Forms::Timer^  load;











	private: System::Windows::Forms::ToolTip^  ability_info;
	private: System::Windows::Forms::Button^  new_game;













	private: System::Windows::Forms::Panel^  load_screen;




	private: System::Windows::Forms::Label^  loading_events;
	private: System::Windows::Forms::ProgressBar^  loading_bar;



	private: System::Windows::Forms::Label^  status;
	private: System::Windows::Forms::Panel^  start_screen;
	private: System::Windows::Forms::Button^  exit;




	private: System::Windows::Forms::Button^  help;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Panel^  inventory_panel;

	private: System::Windows::Forms::Button^  inventory;

	private: System::Windows::Forms::PictureBox^  melee_buff_potion;

	private: System::Windows::Forms::PictureBox^  mana_potion;

	private: System::Windows::Forms::PictureBox^  health_potion;


	private: System::Windows::Forms::PictureBox^  electric_storm;
	private: System::Windows::Forms::PictureBox^  greater_ice;
	private: System::Windows::Forms::PictureBox^  lesser_ice;
	private: System::Windows::Forms::PictureBox^  whirlwind;
	private: System::Windows::Forms::PictureBox^  greater_wand;
	private: System::Windows::Forms::PictureBox^  lesser_wand;
private: System::Windows::Forms::PictureBox^  peruna_death_buff;

private: System::Windows::Forms::PictureBox^  cocoons_bane_buff;
private: System::Windows::Forms::PictureBox^  brutal_staff_buff;


private: System::Windows::Forms::PictureBox^  pig_slaughter_buff;
private: System::Windows::Forms::PictureBox^  ultimate_fury_buff;



private: System::Windows::Forms::PictureBox^  apprentice_sword_buff;
private: System::Windows::Forms::PictureBox^  staff_of_magi_buff;


private: System::Windows::Forms::PictureBox^  destroyer_buff;
private: System::Windows::Forms::PictureBox^  apprentice_staff_buff;


private: System::Windows::Forms::PictureBox^  use_potion_2;

private: System::Windows::Forms::PictureBox^  use_potion_1;
private: System::Windows::Forms::PictureBox^  melee_multiplier;


private: System::Windows::Forms::PictureBox^  use_magic_ability;

private: System::Windows::Forms::PictureBox^  use_melee_ability;
private: System::Windows::Forms::PictureBox^  magic_multiplier;
private: System::Windows::Forms::Button^  menu;



private: System::Windows::Forms::PictureBox^  magic_buff_potion;



private: System::Windows::Forms::Label^  magic_buff_number;
private: System::Windows::Forms::Label^  magic_buff;
private: System::Windows::Forms::Label^  magic_abilites;




private: System::Windows::Forms::Label^  melee_abilites;

private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::Label^  mana_potion_number;

private: System::Windows::Forms::Label^  health_potion_number;
private: System::Windows::Forms::Label^  melee_buff_number;
private: System::Windows::Forms::Label^  mana;



private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Label^  health;

private: System::Windows::Forms::Label^  melee_buff;

private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::Button^  resume_game;
















































































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
			this->ability_info = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->melee_buff_potion = (gcnew System::Windows::Forms::PictureBox());
			this->mana_potion = (gcnew System::Windows::Forms::PictureBox());
			this->health_potion = (gcnew System::Windows::Forms::PictureBox());
			this->electric_storm = (gcnew System::Windows::Forms::PictureBox());
			this->greater_ice = (gcnew System::Windows::Forms::PictureBox());
			this->lesser_ice = (gcnew System::Windows::Forms::PictureBox());
			this->whirlwind = (gcnew System::Windows::Forms::PictureBox());
			this->greater_wand = (gcnew System::Windows::Forms::PictureBox());
			this->lesser_wand = (gcnew System::Windows::Forms::PictureBox());
			this->use_potion_2 = (gcnew System::Windows::Forms::PictureBox());
			this->use_potion_1 = (gcnew System::Windows::Forms::PictureBox());
			this->use_magic_ability = (gcnew System::Windows::Forms::PictureBox());
			this->use_melee_ability = (gcnew System::Windows::Forms::PictureBox());
			this->melee_multiplier = (gcnew System::Windows::Forms::PictureBox());
			this->magic_multiplier = (gcnew System::Windows::Forms::PictureBox());
			this->new_game = (gcnew System::Windows::Forms::Button());
			this->load_screen = (gcnew System::Windows::Forms::Panel());
			this->start_screen = (gcnew System::Windows::Forms::Panel());
			this->resume_game = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->help = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->loading_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->loading_events = (gcnew System::Windows::Forms::Label());
			this->status = (gcnew System::Windows::Forms::Label());
			this->inventory_panel = (gcnew System::Windows::Forms::Panel());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->mana_potion_number = (gcnew System::Windows::Forms::Label());
			this->health_potion_number = (gcnew System::Windows::Forms::Label());
			this->melee_buff_number = (gcnew System::Windows::Forms::Label());
			this->mana = (gcnew System::Windows::Forms::Label());
			this->magic_buff_number = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->health = (gcnew System::Windows::Forms::Label());
			this->melee_buff = (gcnew System::Windows::Forms::Label());
			this->magic_buff = (gcnew System::Windows::Forms::Label());
			this->magic_abilites = (gcnew System::Windows::Forms::Label());
			this->melee_abilites = (gcnew System::Windows::Forms::Label());
			this->brutal_staff_buff = (gcnew System::Windows::Forms::PictureBox());
			this->apprentice_staff_buff = (gcnew System::Windows::Forms::PictureBox());
			this->destroyer_buff = (gcnew System::Windows::Forms::PictureBox());
			this->staff_of_magi_buff = (gcnew System::Windows::Forms::PictureBox());
			this->magic_buff_potion = (gcnew System::Windows::Forms::PictureBox());
			this->apprentice_sword_buff = (gcnew System::Windows::Forms::PictureBox());
			this->ultimate_fury_buff = (gcnew System::Windows::Forms::PictureBox());
			this->pig_slaughter_buff = (gcnew System::Windows::Forms::PictureBox());
			this->cocoons_bane_buff = (gcnew System::Windows::Forms::PictureBox());
			this->peruna_death_buff = (gcnew System::Windows::Forms::PictureBox());
			this->inventory = (gcnew System::Windows::Forms::Button());
			this->menu = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->melee_buff_potion))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mana_potion))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->health_potion))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->electric_storm))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->greater_ice))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lesser_ice))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->whirlwind))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->greater_wand))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lesser_wand))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->use_potion_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->use_potion_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->use_magic_ability))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->use_melee_ability))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->melee_multiplier))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->magic_multiplier))->BeginInit();
			this->load_screen->SuspendLayout();
			this->start_screen->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->inventory_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->brutal_staff_buff))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->apprentice_staff_buff))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->destroyer_buff))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->staff_of_magi_buff))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->magic_buff_potion))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->apprentice_sword_buff))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ultimate_fury_buff))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pig_slaughter_buff))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cocoons_bane_buff))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->peruna_death_buff))->BeginInit();
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
			// ability_info
			// 
			this->ability_info->AutomaticDelay = 0;
			this->ability_info->AutoPopDelay = 5000;
			this->ability_info->InitialDelay = 0;
			this->ability_info->ReshowDelay = 0;
			this->ability_info->UseAnimation = false;
			this->ability_info->UseFading = false;
			// 
			// melee_buff_potion
			// 
			this->melee_buff_potion->AccessibleDescription = L"50";
			this->melee_buff_potion->AccessibleName = L"mana";
			this->melee_buff_potion->BackColor = System::Drawing::Color::Transparent;
			this->melee_buff_potion->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->melee_buff_potion->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"melee_buff_potion.Image")));
			this->melee_buff_potion->Location = System::Drawing::Point(209, 206);
			this->melee_buff_potion->Name = L"melee_buff_potion";
			this->melee_buff_potion->Size = System::Drawing::Size(40, 40);
			this->melee_buff_potion->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->melee_buff_potion->TabIndex = 89;
			this->melee_buff_potion->TabStop = false;
			this->melee_buff_potion->Tag = L"11";
			this->ability_info->SetToolTip(this->melee_buff_potion, L"Mana Potion\r\n\r\n50 Restore Mana");
			this->melee_buff_potion->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Item_Click);
			// 
			// mana_potion
			// 
			this->mana_potion->AccessibleDescription = L"50";
			this->mana_potion->AccessibleName = L"mana";
			this->mana_potion->BackColor = System::Drawing::Color::Transparent;
			this->mana_potion->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->mana_potion->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mana_potion.Image")));
			this->mana_potion->Location = System::Drawing::Point(121, 206);
			this->mana_potion->Name = L"mana_potion";
			this->mana_potion->Size = System::Drawing::Size(40, 40);
			this->mana_potion->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->mana_potion->TabIndex = 88;
			this->mana_potion->TabStop = false;
			this->mana_potion->Tag = L"11";
			this->ability_info->SetToolTip(this->mana_potion, L"Mana Potion\r\n\r\n50 Restore Mana");
			this->mana_potion->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Item_Click);
			// 
			// health_potion
			// 
			this->health_potion->AccessibleDescription = L"50";
			this->health_potion->AccessibleName = L"health";
			this->health_potion->BackColor = System::Drawing::Color::Transparent;
			this->health_potion->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->health_potion->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"health_potion.Image")));
			this->health_potion->Location = System::Drawing::Point(32, 206);
			this->health_potion->Name = L"health_potion";
			this->health_potion->Size = System::Drawing::Size(40, 40);
			this->health_potion->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->health_potion->TabIndex = 86;
			this->health_potion->TabStop = false;
			this->health_potion->Tag = L"11";
			this->ability_info->SetToolTip(this->health_potion, L"Health Potion\r\n\r\n50 Restore Health");
			this->health_potion->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Item_Click);
			// 
			// electric_storm
			// 
			this->electric_storm->AccessibleDescription = L"60";
			this->electric_storm->AccessibleName = L"60";
			this->electric_storm->BackColor = System::Drawing::Color::Transparent;
			this->electric_storm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->electric_storm->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"electric_storm.Image")));
			this->electric_storm->Location = System::Drawing::Point(297, 267);
			this->electric_storm->Name = L"electric_storm";
			this->electric_storm->Size = System::Drawing::Size(40, 40);
			this->electric_storm->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->electric_storm->TabIndex = 85;
			this->electric_storm->TabStop = false;
			this->electric_storm->Tag = L"8";
			this->ability_info->SetToolTip(this->electric_storm, L"Electric Storm\r\n\r\n60 Damage\r\n60 Mana Cost\r\n");
			this->electric_storm->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Item_Click);
			// 
			// greater_ice
			// 
			this->greater_ice->AccessibleDescription = L"50";
			this->greater_ice->AccessibleName = L"50";
			this->greater_ice->BackColor = System::Drawing::Color::Transparent;
			this->greater_ice->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->greater_ice->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"greater_ice.Image")));
			this->greater_ice->Location = System::Drawing::Point(251, 267);
			this->greater_ice->Name = L"greater_ice";
			this->greater_ice->Size = System::Drawing::Size(40, 40);
			this->greater_ice->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->greater_ice->TabIndex = 84;
			this->greater_ice->TabStop = false;
			this->greater_ice->Tag = L"4";
			this->ability_info->SetToolTip(this->greater_ice, L"Greater Ice\r\n\r\n50 Damage\r\n50 Mana Cost");
			this->greater_ice->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Item_Click);
			// 
			// lesser_ice
			// 
			this->lesser_ice->AccessibleDescription = L"40";
			this->lesser_ice->AccessibleName = L"40";
			this->lesser_ice->BackColor = System::Drawing::Color::Transparent;
			this->lesser_ice->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->lesser_ice->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"lesser_ice.Image")));
			this->lesser_ice->Location = System::Drawing::Point(205, 267);
			this->lesser_ice->Name = L"lesser_ice";
			this->lesser_ice->Size = System::Drawing::Size(40, 40);
			this->lesser_ice->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->lesser_ice->TabIndex = 83;
			this->lesser_ice->TabStop = false;
			this->lesser_ice->Tag = L"3";
			this->ability_info->SetToolTip(this->lesser_ice, L"Lesser Ice\r\n\r\n40 Damage\r\n40 Mana Cost\r\n");
			this->lesser_ice->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Item_Click);
			// 
			// whirlwind
			// 
			this->whirlwind->AccessibleDescription = L"30";
			this->whirlwind->AccessibleName = L"30";
			this->whirlwind->BackColor = System::Drawing::Color::Transparent;
			this->whirlwind->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->whirlwind->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"whirlwind.Image")));
			this->whirlwind->Location = System::Drawing::Point(124, 267);
			this->whirlwind->Name = L"whirlwind";
			this->whirlwind->Size = System::Drawing::Size(40, 40);
			this->whirlwind->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->whirlwind->TabIndex = 82;
			this->whirlwind->TabStop = false;
			this->whirlwind->Tag = L"10";
			this->ability_info->SetToolTip(this->whirlwind, L"Whirlwind\r\n\r\n30 Damage\r\n30 Mana Cost\r\n");
			this->whirlwind->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Item_Click);
			// 
			// greater_wand
			// 
			this->greater_wand->AccessibleDescription = L"20";
			this->greater_wand->AccessibleName = L"20";
			this->greater_wand->BackColor = System::Drawing::Color::Transparent;
			this->greater_wand->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->greater_wand->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"greater_wand.Image")));
			this->greater_wand->Location = System::Drawing::Point(78, 267);
			this->greater_wand->Name = L"greater_wand";
			this->greater_wand->Size = System::Drawing::Size(40, 40);
			this->greater_wand->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->greater_wand->TabIndex = 81;
			this->greater_wand->TabStop = false;
			this->greater_wand->Tag = L"9";
			this->ability_info->SetToolTip(this->greater_wand, L"Greater Wand\r\n\r\n20 Damage\r\n20 Mana Cost\r\n");
			this->greater_wand->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Item_Click);
			// 
			// lesser_wand
			// 
			this->lesser_wand->AccessibleDescription = L"10";
			this->lesser_wand->AccessibleName = L"10";
			this->lesser_wand->BackColor = System::Drawing::Color::Transparent;
			this->lesser_wand->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->lesser_wand->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"lesser_wand.Image")));
			this->lesser_wand->Location = System::Drawing::Point(32, 267);
			this->lesser_wand->Name = L"lesser_wand";
			this->lesser_wand->Size = System::Drawing::Size(40, 40);
			this->lesser_wand->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->lesser_wand->TabIndex = 80;
			this->lesser_wand->TabStop = false;
			this->lesser_wand->Tag = L"6";
			this->ability_info->SetToolTip(this->lesser_wand, L"Lesser Wand\r\n\r\n10 Damage\r\n10 Mana Cost");
			this->lesser_wand->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Item_Click);
			// 
			// use_potion_2
			// 
			this->use_potion_2->AccessibleDescription = L"10";
			this->use_potion_2->AccessibleName = L"10";
			this->use_potion_2->BackColor = System::Drawing::Color::Transparent;
			this->use_potion_2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->use_potion_2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"use_potion_2.Image")));
			this->use_potion_2->Location = System::Drawing::Point(647, 685);
			this->use_potion_2->Name = L"use_potion_2";
			this->use_potion_2->Size = System::Drawing::Size(32, 32);
			this->use_potion_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->use_potion_2->TabIndex = 79;
			this->use_potion_2->TabStop = false;
			this->use_potion_2->Tag = L"6";
			this->ability_info->SetToolTip(this->use_potion_2, L"Use Potion");
			this->use_potion_2->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
			// 
			// use_potion_1
			// 
			this->use_potion_1->AccessibleDescription = L"10";
			this->use_potion_1->AccessibleName = L"10";
			this->use_potion_1->BackColor = System::Drawing::Color::Transparent;
			this->use_potion_1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->use_potion_1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"use_potion_1.Image")));
			this->use_potion_1->Location = System::Drawing::Point(599, 685);
			this->use_potion_1->Name = L"use_potion_1";
			this->use_potion_1->Size = System::Drawing::Size(32, 32);
			this->use_potion_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->use_potion_1->TabIndex = 78;
			this->use_potion_1->TabStop = false;
			this->use_potion_1->Tag = L"6";
			this->ability_info->SetToolTip(this->use_potion_1, L"Use Potion");
			this->use_potion_1->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
			// 
			// use_magic_ability
			// 
			this->use_magic_ability->AccessibleDescription = L"10";
			this->use_magic_ability->AccessibleName = L"10";
			this->use_magic_ability->BackColor = System::Drawing::Color::Transparent;
			this->use_magic_ability->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->use_magic_ability->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"use_magic_ability.Image")));
			this->use_magic_ability->Location = System::Drawing::Point(743, 685);
			this->use_magic_ability->Name = L"use_magic_ability";
			this->use_magic_ability->Size = System::Drawing::Size(32, 32);
			this->use_magic_ability->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->use_magic_ability->TabIndex = 76;
			this->use_magic_ability->TabStop = false;
			this->use_magic_ability->Tag = L"6";
			this->ability_info->SetToolTip(this->use_magic_ability, L"Use Magic Ability");
			this->use_magic_ability->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
			// 
			// use_melee_ability
			// 
			this->use_melee_ability->AccessibleDescription = L"10";
			this->use_melee_ability->AccessibleName = L"10";
			this->use_melee_ability->BackColor = System::Drawing::Color::Transparent;
			this->use_melee_ability->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->use_melee_ability->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"use_melee_ability.Image")));
			this->use_melee_ability->Location = System::Drawing::Point(695, 685);
			this->use_melee_ability->Name = L"use_melee_ability";
			this->use_melee_ability->Size = System::Drawing::Size(32, 32);
			this->use_melee_ability->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->use_melee_ability->TabIndex = 74;
			this->use_melee_ability->TabStop = false;
			this->use_melee_ability->Tag = L"6";
			this->ability_info->SetToolTip(this->use_melee_ability, L"Use Melee Ability");
			this->use_melee_ability->Click += gcnew System::EventHandler(this, &ApprenticeTrial::ability_Click);
			// 
			// melee_multiplier
			// 
			this->melee_multiplier->BackColor = System::Drawing::Color::Transparent;
			this->melee_multiplier->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"melee_multiplier.Image")));
			this->melee_multiplier->Location = System::Drawing::Point(790, 685);
			this->melee_multiplier->Name = L"melee_multiplier";
			this->melee_multiplier->Size = System::Drawing::Size(74, 32);
			this->melee_multiplier->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->melee_multiplier->TabIndex = 77;
			this->melee_multiplier->TabStop = false;
			this->ability_info->SetToolTip(this->melee_multiplier, L"Melee Multiplier");
			this->melee_multiplier->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::melee_multiplier_DoubleClick);
			// 
			// magic_multiplier
			// 
			this->magic_multiplier->BackColor = System::Drawing::Color::Transparent;
			this->magic_multiplier->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"magic_multiplier.Image")));
			this->magic_multiplier->Location = System::Drawing::Point(881, 685);
			this->magic_multiplier->Name = L"magic_multiplier";
			this->magic_multiplier->Size = System::Drawing::Size(74, 32);
			this->magic_multiplier->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->magic_multiplier->TabIndex = 75;
			this->magic_multiplier->TabStop = false;
			this->ability_info->SetToolTip(this->magic_multiplier, L"Magic Multiplier");
			// 
			// new_game
			// 
			this->new_game->BackColor = System::Drawing::Color::Transparent;
			this->new_game->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"new_game.BackgroundImage")));
			this->new_game->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->new_game->FlatAppearance->BorderSize = 0;
			this->new_game->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->new_game->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->new_game->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->new_game->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->new_game->Location = System::Drawing::Point(391, 308);
			this->new_game->Name = L"new_game";
			this->new_game->Size = System::Drawing::Size(235, 60);
			this->new_game->TabIndex = 23;
			this->new_game->UseVisualStyleBackColor = false;
			this->new_game->Click += gcnew System::EventHandler(this, &ApprenticeTrial::play_Click);
			// 
			// load_screen
			// 
			this->load_screen->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"load_screen.BackgroundImage")));
			this->load_screen->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->load_screen->Controls->Add(this->start_screen);
			this->load_screen->Controls->Add(this->pictureBox1);
			this->load_screen->Controls->Add(this->loading_bar);
			this->load_screen->Controls->Add(this->loading_events);
			this->load_screen->Dock = System::Windows::Forms::DockStyle::Fill;
			this->load_screen->Location = System::Drawing::Point(0, 0);
			this->load_screen->Name = L"load_screen";
			this->load_screen->Size = System::Drawing::Size(1008, 729);
			this->load_screen->TabIndex = 25;
			// 
			// start_screen
			// 
			this->start_screen->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"start_screen.BackgroundImage")));
			this->start_screen->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->start_screen->Controls->Add(this->resume_game);
			this->start_screen->Controls->Add(this->label2);
			this->start_screen->Controls->Add(this->exit);
			this->start_screen->Controls->Add(this->help);
			this->start_screen->Controls->Add(this->new_game);
			this->start_screen->Location = System::Drawing::Point(24, 27);
			this->start_screen->Name = L"start_screen";
			this->start_screen->Size = System::Drawing::Size(1008, 729);
			this->start_screen->TabIndex = 30;
			// 
			// resume_game
			// 
			this->resume_game->BackColor = System::Drawing::Color::Transparent;
			this->resume_game->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"resume_game.BackgroundImage")));
			this->resume_game->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->resume_game->FlatAppearance->BorderSize = 0;
			this->resume_game->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->resume_game->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->resume_game->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->resume_game->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->resume_game->Location = System::Drawing::Point(391, 388);
			this->resume_game->Name = L"resume_game";
			this->resume_game->Size = System::Drawing::Size(235, 60);
			this->resume_game->TabIndex = 34;
			this->resume_game->UseVisualStyleBackColor = false;
			this->resume_game->Click += gcnew System::EventHandler(this, &ApprenticeTrial::resume_Click);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::Info;
			this->label2->Location = System::Drawing::Point(12, 661);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(169, 52);
			this->label2->TabIndex = 33;
			this->label2->Text = L"Copyright";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->UseCompatibleTextRendering = true;
			// 
			// exit
			// 
			this->exit->BackColor = System::Drawing::Color::Transparent;
			this->exit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"exit.BackgroundImage")));
			this->exit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->exit->FlatAppearance->BorderSize = 0;
			this->exit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->exit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->exit->Location = System::Drawing::Point(391, 551);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(235, 60);
			this->exit->TabIndex = 32;
			this->exit->UseVisualStyleBackColor = false;
			this->exit->Click += gcnew System::EventHandler(this, &ApprenticeTrial::quit_Click);
			// 
			// help
			// 
			this->help->BackColor = System::Drawing::Color::Transparent;
			this->help->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"help.BackgroundImage")));
			this->help->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->help->FlatAppearance->BorderSize = 0;
			this->help->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->help->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->help->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->help->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->help->Location = System::Drawing::Point(391, 470);
			this->help->Name = L"help";
			this->help->Size = System::Drawing::Size(235, 60);
			this->help->TabIndex = 31;
			this->help->UseVisualStyleBackColor = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(197, 178);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(620, 422);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 31;
			this->pictureBox1->TabStop = false;
			// 
			// loading_bar
			// 
			this->loading_bar->Location = System::Drawing::Point(0, 689);
			this->loading_bar->Maximum = 140;
			this->loading_bar->Name = L"loading_bar";
			this->loading_bar->Size = System::Drawing::Size(1008, 10);
			this->loading_bar->Step = 1;
			this->loading_bar->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->loading_bar->TabIndex = 25;
			// 
			// loading_events
			// 
			this->loading_events->BackColor = System::Drawing::Color::Transparent;
			this->loading_events->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->loading_events->ForeColor = System::Drawing::SystemColors::Info;
			this->loading_events->Location = System::Drawing::Point(229, 625);
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
			this->status->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->status->Location = System::Drawing::Point(490, 9);
			this->status->Name = L"status";
			this->status->Size = System::Drawing::Size(237, 45);
			this->status->TabIndex = 26;
			this->status->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->status->UseCompatibleTextRendering = true;
			// 
			// inventory_panel
			// 
			this->inventory_panel->BackColor = System::Drawing::Color::Transparent;
			this->inventory_panel->Controls->Add(this->label20);
			this->inventory_panel->Controls->Add(this->label19);
			this->inventory_panel->Controls->Add(this->label18);
			this->inventory_panel->Controls->Add(this->label17);
			this->inventory_panel->Controls->Add(this->label16);
			this->inventory_panel->Controls->Add(this->label15);
			this->inventory_panel->Controls->Add(this->label14);
			this->inventory_panel->Controls->Add(this->label13);
			this->inventory_panel->Controls->Add(this->mana_potion_number);
			this->inventory_panel->Controls->Add(this->health_potion_number);
			this->inventory_panel->Controls->Add(this->melee_buff_number);
			this->inventory_panel->Controls->Add(this->mana);
			this->inventory_panel->Controls->Add(this->magic_buff_number);
			this->inventory_panel->Controls->Add(this->label12);
			this->inventory_panel->Controls->Add(this->health);
			this->inventory_panel->Controls->Add(this->melee_buff);
			this->inventory_panel->Controls->Add(this->magic_buff);
			this->inventory_panel->Controls->Add(this->magic_abilites);
			this->inventory_panel->Controls->Add(this->electric_storm);
			this->inventory_panel->Controls->Add(this->melee_abilites);
			this->inventory_panel->Controls->Add(this->lesser_ice);
			this->inventory_panel->Controls->Add(this->greater_ice);
			this->inventory_panel->Controls->Add(this->lesser_wand);
			this->inventory_panel->Controls->Add(this->greater_wand);
			this->inventory_panel->Controls->Add(this->whirlwind);
			this->inventory_panel->Controls->Add(this->brutal_staff_buff);
			this->inventory_panel->Controls->Add(this->apprentice_staff_buff);
			this->inventory_panel->Controls->Add(this->melee_buff_potion);
			this->inventory_panel->Controls->Add(this->destroyer_buff);
			this->inventory_panel->Controls->Add(this->mana_potion);
			this->inventory_panel->Controls->Add(this->staff_of_magi_buff);
			this->inventory_panel->Controls->Add(this->magic_buff_potion);
			this->inventory_panel->Controls->Add(this->apprentice_sword_buff);
			this->inventory_panel->Controls->Add(this->health_potion);
			this->inventory_panel->Controls->Add(this->ultimate_fury_buff);
			this->inventory_panel->Controls->Add(this->pig_slaughter_buff);
			this->inventory_panel->Controls->Add(this->cocoons_bane_buff);
			this->inventory_panel->Controls->Add(this->peruna_death_buff);
			this->inventory_panel->Location = System::Drawing::Point(229, 170);
			this->inventory_panel->Name = L"inventory_panel";
			this->inventory_panel->Size = System::Drawing::Size(568, 337);
			this->inventory_panel->TabIndex = 27;
			this->inventory_panel->Visible = false;
			this->inventory_panel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &ApprenticeTrial::ApprenticeTrial_MouseMove);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label20->ForeColor = System::Drawing::SystemColors::Info;
			this->label20->Location = System::Drawing::Point(466, 47);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(76, 15);
			this->label20->TabIndex = 111;
			this->label20->Text = L"Ultimate Fury";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label19->ForeColor = System::Drawing::SystemColors::Info;
			this->label19->Location = System::Drawing::Point(362, 47);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(81, 15);
			this->label19->TabIndex = 110;
			this->label19->Text = L"Cocoon\'s Bane";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label18->ForeColor = System::Drawing::SystemColors::Info;
			this->label18->Location = System::Drawing::Point(251, 47);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(58, 15);
			this->label18->TabIndex = 109;
			this->label18->Text = L"Destroyer";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::SystemColors::Info;
			this->label17->Location = System::Drawing::Point(148, 47);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(76, 15);
			this->label17->TabIndex = 108;
			this->label17->Text = L"Pig Slaughter";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::SystemColors::Info;
			this->label16->Location = System::Drawing::Point(41, 47);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(100, 15);
			this->label16->TabIndex = 107;
			this->label16->Text = L"Apprentice Sword";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::SystemColors::Info;
			this->label15->Location = System::Drawing::Point(362, 118);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(81, 15);
			this->label15->TabIndex = 106;
			this->label15->Text = L"Staff of Magi";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::SystemColors::Info;
			this->label14->Location = System::Drawing::Point(253, 118);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(71, 15);
			this->label14->TabIndex = 105;
			this->label14->Text = L"Brutal Staff";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::SystemColors::Info;
			this->label13->Location = System::Drawing::Point(148, 117);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(75, 15);
			this->label13->TabIndex = 104;
			this->label13->Text = L"Peruna Death";
			// 
			// mana_potion_number
			// 
			this->mana_potion_number->AutoSize = true;
			this->mana_potion_number->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->mana_potion_number->ForeColor = System::Drawing::SystemColors::Info;
			this->mana_potion_number->Location = System::Drawing::Point(167, 220);
			this->mana_potion_number->Name = L"mana_potion_number";
			this->mana_potion_number->Size = System::Drawing::Size(24, 15);
			this->mana_potion_number->TabIndex = 103;
			this->mana_potion_number->Text = L"x 0";
			// 
			// health_potion_number
			// 
			this->health_potion_number->AutoSize = true;
			this->health_potion_number->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->health_potion_number->ForeColor = System::Drawing::SystemColors::Info;
			this->health_potion_number->Location = System::Drawing::Point(78, 220);
			this->health_potion_number->Name = L"health_potion_number";
			this->health_potion_number->Size = System::Drawing::Size(24, 15);
			this->health_potion_number->TabIndex = 103;
			this->health_potion_number->Text = L"x 0";
			// 
			// melee_buff_number
			// 
			this->melee_buff_number->AutoSize = true;
			this->melee_buff_number->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->melee_buff_number->ForeColor = System::Drawing::SystemColors::Info;
			this->melee_buff_number->Location = System::Drawing::Point(251, 220);
			this->melee_buff_number->Name = L"melee_buff_number";
			this->melee_buff_number->Size = System::Drawing::Size(24, 15);
			this->melee_buff_number->TabIndex = 103;
			this->melee_buff_number->Text = L"x 0";
			// 
			// mana
			// 
			this->mana->AutoSize = true;
			this->mana->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->mana->ForeColor = System::Drawing::SystemColors::Info;
			this->mana->Location = System::Drawing::Point(131, 188);
			this->mana->Name = L"mana";
			this->mana->Size = System::Drawing::Size(35, 15);
			this->mana->TabIndex = 103;
			this->mana->Text = L"Mana";
			// 
			// magic_buff_number
			// 
			this->magic_buff_number->AutoSize = true;
			this->magic_buff_number->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->magic_buff_number->ForeColor = System::Drawing::SystemColors::Info;
			this->magic_buff_number->Location = System::Drawing::Point(343, 220);
			this->magic_buff_number->Name = L"magic_buff_number";
			this->magic_buff_number->Size = System::Drawing::Size(24, 15);
			this->magic_buff_number->TabIndex = 103;
			this->magic_buff_number->Text = L"x 0";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::SystemColors::Info;
			this->label12->Location = System::Drawing::Point(41, 117);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(97, 15);
			this->label12->TabIndex = 103;
			this->label12->Text = L"Apprentice Staff";
			// 
			// health
			// 
			this->health->AutoSize = true;
			this->health->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->health->ForeColor = System::Drawing::SystemColors::Info;
			this->health->Location = System::Drawing::Point(42, 188);
			this->health->Name = L"health";
			this->health->Size = System::Drawing::Size(40, 15);
			this->health->TabIndex = 103;
			this->health->Text = L"Health";
			// 
			// melee_buff
			// 
			this->melee_buff->AutoSize = true;
			this->melee_buff->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->melee_buff->ForeColor = System::Drawing::SystemColors::Info;
			this->melee_buff->Location = System::Drawing::Point(215, 188);
			this->melee_buff->Name = L"melee_buff";
			this->melee_buff->Size = System::Drawing::Size(66, 15);
			this->melee_buff->TabIndex = 103;
			this->melee_buff->Text = L"Melee Buff";
			// 
			// magic_buff
			// 
			this->magic_buff->AutoSize = true;
			this->magic_buff->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->magic_buff->ForeColor = System::Drawing::SystemColors::Info;
			this->magic_buff->Location = System::Drawing::Point(307, 188);
			this->magic_buff->Name = L"magic_buff";
			this->magic_buff->Size = System::Drawing::Size(67, 15);
			this->magic_buff->TabIndex = 103;
			this->magic_buff->Text = L"Magic Buff";
			// 
			// magic_abilites
			// 
			this->magic_abilites->AutoSize = true;
			this->magic_abilites->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->magic_abilites->ForeColor = System::Drawing::SystemColors::Info;
			this->magic_abilites->Location = System::Drawing::Point(215, 249);
			this->magic_abilites->Name = L"magic_abilites";
			this->magic_abilites->Size = System::Drawing::Size(86, 15);
			this->magic_abilites->TabIndex = 102;
			this->magic_abilites->Text = L"Magic Abilities";
			// 
			// melee_abilites
			// 
			this->melee_abilites->AutoSize = true;
			this->melee_abilites->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->melee_abilites->ForeColor = System::Drawing::SystemColors::Info;
			this->melee_abilites->Location = System::Drawing::Point(43, 249);
			this->melee_abilites->Name = L"melee_abilites";
			this->melee_abilites->Size = System::Drawing::Size(85, 15);
			this->melee_abilites->TabIndex = 101;
			this->melee_abilites->Text = L"Melee Abilities";
			// 
			// brutal_staff_buff
			// 
			this->brutal_staff_buff->BackColor = System::Drawing::Color::Transparent;
			this->brutal_staff_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"brutal_staff_buff.Image")));
			this->brutal_staff_buff->Location = System::Drawing::Point(244, 135);
			this->brutal_staff_buff->Name = L"brutal_staff_buff";
			this->brutal_staff_buff->Size = System::Drawing::Size(100, 50);
			this->brutal_staff_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->brutal_staff_buff->TabIndex = 96;
			this->brutal_staff_buff->TabStop = false;
			this->brutal_staff_buff->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Item_Click);
			// 
			// apprentice_staff_buff
			// 
			this->apprentice_staff_buff->BackColor = System::Drawing::Color::Transparent;
			this->apprentice_staff_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"apprentice_staff_buff.Image")));
			this->apprentice_staff_buff->Location = System::Drawing::Point(32, 135);
			this->apprentice_staff_buff->Name = L"apprentice_staff_buff";
			this->apprentice_staff_buff->Size = System::Drawing::Size(100, 50);
			this->apprentice_staff_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->apprentice_staff_buff->TabIndex = 90;
			this->apprentice_staff_buff->TabStop = false;
			this->apprentice_staff_buff->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Item_Click);
			// 
			// destroyer_buff
			// 
			this->destroyer_buff->BackColor = System::Drawing::Color::Transparent;
			this->destroyer_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"destroyer_buff.Image")));
			this->destroyer_buff->Location = System::Drawing::Point(244, 65);
			this->destroyer_buff->Name = L"destroyer_buff";
			this->destroyer_buff->Size = System::Drawing::Size(100, 50);
			this->destroyer_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->destroyer_buff->TabIndex = 91;
			this->destroyer_buff->TabStop = false;
			this->destroyer_buff->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Item_Click);
			// 
			// staff_of_magi_buff
			// 
			this->staff_of_magi_buff->BackColor = System::Drawing::Color::Transparent;
			this->staff_of_magi_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"staff_of_magi_buff.Image")));
			this->staff_of_magi_buff->Location = System::Drawing::Point(350, 135);
			this->staff_of_magi_buff->Name = L"staff_of_magi_buff";
			this->staff_of_magi_buff->Size = System::Drawing::Size(100, 50);
			this->staff_of_magi_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->staff_of_magi_buff->TabIndex = 92;
			this->staff_of_magi_buff->TabStop = false;
			this->staff_of_magi_buff->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Item_Click);
			// 
			// magic_buff_potion
			// 
			this->magic_buff_potion->AccessibleDescription = L"50";
			this->magic_buff_potion->AccessibleName = L"health";
			this->magic_buff_potion->BackColor = System::Drawing::Color::Transparent;
			this->magic_buff_potion->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->magic_buff_potion->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"magic_buff_potion.Image")));
			this->magic_buff_potion->Location = System::Drawing::Point(297, 206);
			this->magic_buff_potion->Name = L"magic_buff_potion";
			this->magic_buff_potion->Size = System::Drawing::Size(40, 40);
			this->magic_buff_potion->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->magic_buff_potion->TabIndex = 87;
			this->magic_buff_potion->TabStop = false;
			this->magic_buff_potion->Tag = L"11";
			this->magic_buff_potion->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Item_Click);
			// 
			// apprentice_sword_buff
			// 
			this->apprentice_sword_buff->BackColor = System::Drawing::Color::Transparent;
			this->apprentice_sword_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"apprentice_sword_buff.Image")));
			this->apprentice_sword_buff->Location = System::Drawing::Point(32, 65);
			this->apprentice_sword_buff->Name = L"apprentice_sword_buff";
			this->apprentice_sword_buff->Size = System::Drawing::Size(100, 50);
			this->apprentice_sword_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->apprentice_sword_buff->TabIndex = 93;
			this->apprentice_sword_buff->TabStop = false;
			this->apprentice_sword_buff->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ApprenticeTrial::melee_buff_MouseDown);
			this->apprentice_sword_buff->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &ApprenticeTrial::melee_buff_MouseUp);
			// 
			// ultimate_fury_buff
			// 
			this->ultimate_fury_buff->BackColor = System::Drawing::Color::Transparent;
			this->ultimate_fury_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ultimate_fury_buff.Image")));
			this->ultimate_fury_buff->Location = System::Drawing::Point(456, 65);
			this->ultimate_fury_buff->Name = L"ultimate_fury_buff";
			this->ultimate_fury_buff->Size = System::Drawing::Size(100, 50);
			this->ultimate_fury_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->ultimate_fury_buff->TabIndex = 94;
			this->ultimate_fury_buff->TabStop = false;
			this->ultimate_fury_buff->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Item_Click);
			// 
			// pig_slaughter_buff
			// 
			this->pig_slaughter_buff->BackColor = System::Drawing::Color::Transparent;
			this->pig_slaughter_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pig_slaughter_buff.Image")));
			this->pig_slaughter_buff->Location = System::Drawing::Point(138, 65);
			this->pig_slaughter_buff->Name = L"pig_slaughter_buff";
			this->pig_slaughter_buff->Size = System::Drawing::Size(100, 50);
			this->pig_slaughter_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pig_slaughter_buff->TabIndex = 95;
			this->pig_slaughter_buff->TabStop = false;
			this->pig_slaughter_buff->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Item_Click);
			// 
			// cocoons_bane_buff
			// 
			this->cocoons_bane_buff->BackColor = System::Drawing::Color::Transparent;
			this->cocoons_bane_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"cocoons_bane_buff.Image")));
			this->cocoons_bane_buff->Location = System::Drawing::Point(350, 65);
			this->cocoons_bane_buff->Name = L"cocoons_bane_buff";
			this->cocoons_bane_buff->Size = System::Drawing::Size(100, 50);
			this->cocoons_bane_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->cocoons_bane_buff->TabIndex = 97;
			this->cocoons_bane_buff->TabStop = false;
			this->cocoons_bane_buff->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Item_Click);
			// 
			// peruna_death_buff
			// 
			this->peruna_death_buff->BackColor = System::Drawing::Color::Transparent;
			this->peruna_death_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"peruna_death_buff.Image")));
			this->peruna_death_buff->Location = System::Drawing::Point(138, 135);
			this->peruna_death_buff->Name = L"peruna_death_buff";
			this->peruna_death_buff->Size = System::Drawing::Size(100, 50);
			this->peruna_death_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->peruna_death_buff->TabIndex = 98;
			this->peruna_death_buff->TabStop = false;
			this->peruna_death_buff->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Item_Click);
			// 
			// inventory
			// 
			this->inventory->BackColor = System::Drawing::Color::Transparent;
			this->inventory->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"inventory.BackgroundImage")));
			this->inventory->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->inventory->FlatAppearance->BorderSize = 0;
			this->inventory->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->inventory->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->inventory->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->inventory->Location = System::Drawing::Point(378, 687);
			this->inventory->Name = L"inventory";
			this->inventory->Size = System::Drawing::Size(99, 28);
			this->inventory->TabIndex = 99;
			this->inventory->UseVisualStyleBackColor = false;
			this->inventory->Click += gcnew System::EventHandler(this, &ApprenticeTrial::inventory_Click);
			// 
			// menu
			// 
			this->menu->BackColor = System::Drawing::Color::Transparent;
			this->menu->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"menu.BackgroundImage")));
			this->menu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->menu->FlatAppearance->BorderSize = 0;
			this->menu->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->menu->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->menu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->menu->Location = System::Drawing::Point(483, 687);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(99, 28);
			this->menu->TabIndex = 100;
			this->menu->UseVisualStyleBackColor = false;
			this->menu->Click += gcnew System::EventHandler(this, &ApprenticeTrial::menu_Click);
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
			this->Controls->Add(this->inventory);
			this->Controls->Add(this->use_potion_2);
			this->Controls->Add(this->use_potion_1);
			this->Controls->Add(this->melee_multiplier);
			this->Controls->Add(this->use_magic_ability);
			this->Controls->Add(this->use_melee_ability);
			this->Controls->Add(this->magic_multiplier);
			this->Controls->Add(this->status);
			this->Controls->Add(this->inventory_panel);
			this->Controls->Add(this->menu);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1024, 768);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(1024, 766);
			this->Name = L"ApprenticeTrial";
			this->Text = L"The Apprentice\'s Trial";
			this->Load += gcnew System::EventHandler(this, &ApprenticeTrial::ApprenticeTrial_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ApprenticeTrial::ApprenticeTrial_MouseClick);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &ApprenticeTrial::ApprenticeTrial_MouseMove);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->melee_buff_potion))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mana_potion))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->health_potion))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->electric_storm))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->greater_ice))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lesser_ice))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->whirlwind))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->greater_wand))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lesser_wand))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->use_potion_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->use_potion_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->use_magic_ability))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->use_melee_ability))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->melee_multiplier))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->magic_multiplier))->EndInit();
			this->load_screen->ResumeLayout(false);
			this->load_screen->PerformLayout();
			this->start_screen->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->inventory_panel->ResumeLayout(false);
			this->inventory_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->brutal_staff_buff))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->apprentice_staff_buff))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->destroyer_buff))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->staff_of_magi_buff))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->magic_buff_potion))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->apprentice_sword_buff))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ultimate_fury_buff))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pig_slaughter_buff))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cocoons_bane_buff))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->peruna_death_buff))->EndInit();
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
						status->Text = "PLAYER'S TURN";
					 else
						status->Text = gManager->getEnemyInPlayName()->ToUpper() + "'S TURN";

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

				Focus();
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
private: System::Void health_mana_MouseHover(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 PictureBox^ hud = safe_cast<PictureBox^>(sender);
			 
			 String^ value;

			 if(hud->AccessibleName == "player_health")
				 value = gManager->getPlayerHealth();
			 if(hud->AccessibleName == "player_mana")
				 value = gManager->getPlayerMana();
			 if(hud->AccessibleName == "enemy_health")
				 value = gManager->getEnemyHealth();
			 
			 ability_info->SetToolTip(hud, value);
		 }

private: System::Void inventory_Click(System::Object^  sender, System::EventArgs^  e) {
			 inventory_panel->Visible = !inventory_panel->Visible;
			 gManager->showInventory(inventory_panel->Visible);			 
		 }
private: System::Void menu_Click(System::Object^  sender, System::EventArgs^  e) {
			 draw->Enabled = false;
			 load_screen->Visible = true;
			 start_screen->Visible = true;
		 }
private: System::Void resume_Click(System::Object^  sender, System::EventArgs^  e) {
			 draw->Enabled = true;
			 load_screen->Visible = false;
			 start_screen->Visible = false;

		 }
private: System::Void inventory_Item_Click(System::Object^  sender, System::EventArgs^  e) {
			 PictureBox^ ability = safe_cast<PictureBox^>(sender);
			 Cursor = getAbilityCursor(ability);			 
		 }
private: System::Void melee_buff_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 PictureBox^ ability = safe_cast<PictureBox^>(sender);
			 //Text = Cursor->HotSpot.ToString();
			 //Text = e->Location.ToString();
			 Cursor = getAbilityCursor(ability);
			 Focus();
		 }
private: System::Void melee_buff_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 PictureBox^ ability = safe_cast<PictureBox^>(sender);

			 //Text = melee_multiplier->Location.ToString() + " " + this->Cursor->Position.ToString();

			 //Point cursorPosition = Point(Cursor->Position.X - ability->Image->Width, Cursor->Position.Y - ability->Image->Width);

			 //Text = melee_multiplier->Bounds.ToString() + " " + e->Location.ToString() + " " + cursorPosition.ToString();

			 //Text = cursorLocation.ToString();
			 //this->Location
			 Point l = Point((((Cursor->Position.X - Location.X) - ability->Image->Width /2) + 20), ((Cursor->Position.Y - Location.Y)- (ability->Image->Height/2)) - 20);
			 Text = l.ToString();

			 if(melee_multiplier->Bounds.Contains(l))
			 {
				 melee_multiplier->Image = ability->Image;								 
			 }			 

			 Cursor = Cursors::Arrow;
		 }
private: System::Void ApprenticeTrial_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 //cursorLocation = e->Location;
			 //Text = cursorLocation.ToString();
		 }
private: System::Void melee_multiplier_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 melee_multiplier->Image = clearImage;

		 }
};
}

