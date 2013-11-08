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
	using namespace System::Media;

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
		
#pragma region Windows Form Variables
	
	private: String^ melee_tooltip;
	private: String^ magic_tooltip;
	private: String^ melee_multiplier_tooltip;
	private: String^ magic_multiplier_tooltip;
	private: String^ potion1_tooltip;
	private: String^ potion2_tooltip;

	private: Player^ player;
	private: Enemy^ cocoon;
	private: Enemy^ makhana;
	private: Enemy^ floppit;
	private: Enemy^ fluppit;
	private: Enemy^ peruna;

	private: Image^ loadingBlue;
	private: Image^ background;

	private: Image^ lesserWandImage;
	private: Image^ greaterWandImage;
	private: Image^ whirlwindImage;
	private: Image^ lesserIceImage;
	private: Image^ greaterIceImage;
	private: Image^ electricStormImage;
	private: Image^ clearImage;

	private: bool selected;
	private: bool gameHasLoaded;

	private: int nFrames;
	private: int currentFrame;
	private: int frameWidth;
	private: int frameHeight;
	private: RectangleF srcRectangle;
	private: int time;
	private: int loading;

	private: Point cursorLocation;

	private: Graphics^ formCanvas;
	private: Graphics^ dbGraphics;
	private: Bitmap^ dbBitmap;

	private: Graphics^ loadingCanvas;
	private: Graphics^ loadingGraphics;
	private: Bitmap^ loadingBitmap;

	private: EState selectedAbility;

	private: GameManager^ gManager;
	private: FrameManager^ fManager;

	private: System::Threading::Thread^ myThread;

	private: System::Windows::Forms::Timer^  draw;
	private: System::Windows::Forms::Timer^  load;


	private: System::Windows::Forms::ToolTip^  ability_info;



	private: System::Windows::Forms::Panel^  load_screen;	
	private: System::Windows::Forms::Panel^  start_screen;
	private: System::Windows::Forms::Panel^  inventory_panel;	
	

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
	private: System::Windows::Forms::PictureBox^  magic_buff_potion;


	private: System::Windows::Forms::Label^  status;
	private: System::Windows::Forms::Label^  copyright;
	private: System::Windows::Forms::Label^  magic_buff_number;
	private: System::Windows::Forms::Label^  magic_buff;
	private: System::Windows::Forms::Label^  magic_abilites;
	private: System::Windows::Forms::Label^  melee_abilites;
	private: System::Windows::Forms::Label^  pig_slaughter;
	private: System::Windows::Forms::Label^  apprentice_sword;
	private: System::Windows::Forms::Label^  staff_of_magi;
	private: System::Windows::Forms::Label^  brutal_staff;
	private: System::Windows::Forms::Label^  peruna_death;
	private: System::Windows::Forms::Label^  mana_potion_number;
	private: System::Windows::Forms::Label^  health_potion_number;
	private: System::Windows::Forms::Label^  melee_buff_number;
	private: System::Windows::Forms::Label^  mana;
	private: System::Windows::Forms::Label^  apprentice_staff;
	private: System::Windows::Forms::Label^  health;
	private: System::Windows::Forms::Label^  melee_buff;
	private: System::Windows::Forms::Label^  ultimate_fury;
	private: System::Windows::Forms::Label^  cocoons_bane;
	private: System::Windows::Forms::Label^  destroyer;

    private: System::Windows::Forms::Button^  new_game;
    private: System::Windows::Forms::Button^  help;
	private: System::Windows::Forms::Button^  exit;
    private: System::Windows::Forms::Button^  inventory;
	private: System::Windows::Forms::Button^  menu;
	private: System::Windows::Forms::Button^  resume_game;


	private: System::ComponentModel::IContainer^  components;
#pragma endregion

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
		this->brutal_staff_buff = (gcnew System::Windows::Forms::PictureBox());
		this->apprentice_staff_buff = (gcnew System::Windows::Forms::PictureBox());
		this->destroyer_buff = (gcnew System::Windows::Forms::PictureBox());
		this->staff_of_magi_buff = (gcnew System::Windows::Forms::PictureBox());
		this->apprentice_sword_buff = (gcnew System::Windows::Forms::PictureBox());
		this->ultimate_fury_buff = (gcnew System::Windows::Forms::PictureBox());
		this->pig_slaughter_buff = (gcnew System::Windows::Forms::PictureBox());
		this->cocoons_bane_buff = (gcnew System::Windows::Forms::PictureBox());
		this->peruna_death_buff = (gcnew System::Windows::Forms::PictureBox());
		this->new_game = (gcnew System::Windows::Forms::Button());
		this->load_screen = (gcnew System::Windows::Forms::Panel());
		this->start_screen = (gcnew System::Windows::Forms::Panel());
		this->resume_game = (gcnew System::Windows::Forms::Button());
		this->copyright = (gcnew System::Windows::Forms::Label());
		this->exit = (gcnew System::Windows::Forms::Button());
		this->help = (gcnew System::Windows::Forms::Button());
		this->status = (gcnew System::Windows::Forms::Label());
		this->inventory_panel = (gcnew System::Windows::Forms::Panel());
		this->ultimate_fury = (gcnew System::Windows::Forms::Label());
		this->cocoons_bane = (gcnew System::Windows::Forms::Label());
		this->destroyer = (gcnew System::Windows::Forms::Label());
		this->pig_slaughter = (gcnew System::Windows::Forms::Label());
		this->apprentice_sword = (gcnew System::Windows::Forms::Label());
		this->staff_of_magi = (gcnew System::Windows::Forms::Label());
		this->brutal_staff = (gcnew System::Windows::Forms::Label());
		this->peruna_death = (gcnew System::Windows::Forms::Label());
		this->mana_potion_number = (gcnew System::Windows::Forms::Label());
		this->health_potion_number = (gcnew System::Windows::Forms::Label());
		this->melee_buff_number = (gcnew System::Windows::Forms::Label());
		this->mana = (gcnew System::Windows::Forms::Label());
		this->magic_buff_number = (gcnew System::Windows::Forms::Label());
		this->apprentice_staff = (gcnew System::Windows::Forms::Label());
		this->health = (gcnew System::Windows::Forms::Label());
		this->melee_buff = (gcnew System::Windows::Forms::Label());
		this->magic_buff = (gcnew System::Windows::Forms::Label());
		this->magic_abilites = (gcnew System::Windows::Forms::Label());
		this->melee_abilites = (gcnew System::Windows::Forms::Label());
		this->magic_buff_potion = (gcnew System::Windows::Forms::PictureBox());
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
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->brutal_staff_buff))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->apprentice_staff_buff))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->destroyer_buff))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->staff_of_magi_buff))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->apprentice_sword_buff))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ultimate_fury_buff))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pig_slaughter_buff))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cocoons_bane_buff))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->peruna_death_buff))->BeginInit();
		this->load_screen->SuspendLayout();
		this->start_screen->SuspendLayout();
		this->inventory_panel->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->magic_buff_potion))->BeginInit();
		this->SuspendLayout();
		// 
		// draw
		// 
		this->draw->Interval = 1;
		this->draw->Tick += gcnew System::EventHandler(this, &ApprenticeTrial::draw_Tick);
		// 
		// load
		// 
		this->load->Interval = 50;
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
		this->melee_buff_potion->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::potion_DoubleClick);
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
		this->mana_potion->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::potion_DoubleClick);
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
		this->health_potion->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::potion_DoubleClick);
		// 
		// electric_storm
		// 
		this->electric_storm->AccessibleDescription = L"120";
		this->electric_storm->AccessibleName = L"10";
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
		this->ability_info->SetToolTip(this->electric_storm, L"Electric Storm\r\n\r\n20 Damage\r\n60 Mana Cost\r\n");
		this->electric_storm->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Ability_DoubleClick);
		// 
		// greater_ice
		// 
		this->greater_ice->AccessibleDescription = L"110";
		this->greater_ice->AccessibleName = L"8";
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
		this->ability_info->SetToolTip(this->greater_ice, L"Greater Ice\r\n\r\n15 Damage\r\n50 Mana Cost");
		this->greater_ice->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Ability_DoubleClick);
		// 
		// lesser_ice
		// 
		this->lesser_ice->AccessibleDescription = L"100";
		this->lesser_ice->AccessibleName = L"6";
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
		this->ability_info->SetToolTip(this->lesser_ice, L"Lesser Ice\r\n\r\n10 Damage\r\n40 Mana Cost\r\n");
		this->lesser_ice->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Ability_DoubleClick);
		// 
		// whirlwind
		// 
		this->whirlwind->AccessibleDescription = L"10";
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
		this->ability_info->SetToolTip(this->whirlwind, L"Whirlwind\r\n\r\n30 Damage\r\n10 Mana Cost\r\n");
		this->whirlwind->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Ability_DoubleClick);
		// 
		// greater_wand
		// 
		this->greater_wand->AccessibleDescription = L"7";
		this->greater_wand->AccessibleName = L"15";
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
		this->ability_info->SetToolTip(this->greater_wand, L"Greater Wand\r\n\r\n20 Damage\r\n5 Mana Cost\r\n");
		this->greater_wand->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Ability_DoubleClick);
		// 
		// lesser_wand
		// 
		this->lesser_wand->AccessibleDescription = L"5";
		this->lesser_wand->AccessibleName = L"0";
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
		this->ability_info->SetToolTip(this->lesser_wand, L"Lesser Wand\r\n\r\n10 Damage\r\n0 Mana Cost");
		this->lesser_wand->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Ability_DoubleClick);
		// 
		// use_potion_2
		// 
		this->use_potion_2->AccessibleDescription = L"1";
		this->use_potion_2->AccessibleName = L"1";
		this->use_potion_2->BackColor = System::Drawing::Color::Transparent;
		this->use_potion_2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->use_potion_2->Location = System::Drawing::Point(647, 685);
		this->use_potion_2->Name = L"use_potion_2";
		this->use_potion_2->Size = System::Drawing::Size(32, 32);
		this->use_potion_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->use_potion_2->TabIndex = 79;
		this->use_potion_2->TabStop = false;
		this->use_potion_2->Tag = L"";
		this->ability_info->SetToolTip(this->use_potion_2, L"Use Potion");
		this->use_potion_2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ApprenticeTrial::ability_Click);
		// 
		// use_potion_1
		// 
		this->use_potion_1->AccessibleDescription = L"1";
		this->use_potion_1->AccessibleName = L"1";
		this->use_potion_1->BackColor = System::Drawing::Color::Transparent;
		this->use_potion_1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->use_potion_1->Location = System::Drawing::Point(599, 685);
		this->use_potion_1->Name = L"use_potion_1";
		this->use_potion_1->Size = System::Drawing::Size(32, 32);
		this->use_potion_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->use_potion_1->TabIndex = 78;
		this->use_potion_1->TabStop = false;
		this->use_potion_1->Tag = L"";
		this->ability_info->SetToolTip(this->use_potion_1, L"Use Potion");
		this->use_potion_1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ApprenticeTrial::ability_Click);
		// 
		// use_magic_ability
		// 
		this->use_magic_ability->AccessibleDescription = L"1";
		this->use_magic_ability->AccessibleName = L"1";
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
		this->use_magic_ability->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ApprenticeTrial::ability_Click);
		this->use_magic_ability->MouseHover += gcnew System::EventHandler(this, &ApprenticeTrial::ability_MouseHover);
		// 
		// use_melee_ability
		// 
		this->use_melee_ability->AccessibleDescription = L"10";
		this->use_melee_ability->AccessibleName = L"1";
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
		this->use_melee_ability->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ApprenticeTrial::ability_Click);
		this->use_melee_ability->MouseHover += gcnew System::EventHandler(this, &ApprenticeTrial::ability_MouseHover);
		// 
		// melee_multiplier
		// 
		this->melee_multiplier->AccessibleDescription = L"1";
		this->melee_multiplier->AccessibleName = L"1";
		this->melee_multiplier->BackColor = System::Drawing::Color::Transparent;
		this->melee_multiplier->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"melee_multiplier.Image")));
		this->melee_multiplier->Location = System::Drawing::Point(790, 685);
		this->melee_multiplier->Name = L"melee_multiplier";
		this->melee_multiplier->Size = System::Drawing::Size(74, 32);
		this->melee_multiplier->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->melee_multiplier->TabIndex = 77;
		this->melee_multiplier->TabStop = false;
		this->ability_info->SetToolTip(this->melee_multiplier, L"Melee Multiplier");
		this->melee_multiplier->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ApprenticeTrial::ability_Click);
		this->melee_multiplier->MouseHover += gcnew System::EventHandler(this, &ApprenticeTrial::ability_MouseHover);
		// 
		// magic_multiplier
		// 
		this->magic_multiplier->AccessibleDescription = L"1";
		this->magic_multiplier->AccessibleName = L"1";
		this->magic_multiplier->BackColor = System::Drawing::Color::Transparent;
		this->magic_multiplier->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"magic_multiplier.Image")));
		this->magic_multiplier->Location = System::Drawing::Point(881, 685);
		this->magic_multiplier->Name = L"magic_multiplier";
		this->magic_multiplier->Size = System::Drawing::Size(74, 32);
		this->magic_multiplier->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->magic_multiplier->TabIndex = 75;
		this->magic_multiplier->TabStop = false;
		this->magic_multiplier->Tag = L"";
		this->ability_info->SetToolTip(this->magic_multiplier, L"Magic Multiplier");
		this->magic_multiplier->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ApprenticeTrial::ability_Click);
		this->magic_multiplier->MouseHover += gcnew System::EventHandler(this, &ApprenticeTrial::ability_MouseHover);
		// 
		// brutal_staff_buff
		// 
		this->brutal_staff_buff->AccessibleDescription = L"4";
		this->brutal_staff_buff->AccessibleName = L"4";
		this->brutal_staff_buff->BackColor = System::Drawing::Color::Transparent;
		this->brutal_staff_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"brutal_staff_buff.Image")));
		this->brutal_staff_buff->Location = System::Drawing::Point(244, 135);
		this->brutal_staff_buff->Name = L"brutal_staff_buff";
		this->brutal_staff_buff->Size = System::Drawing::Size(100, 50);
		this->brutal_staff_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->brutal_staff_buff->TabIndex = 96;
		this->brutal_staff_buff->TabStop = false;
		this->ability_info->SetToolTip(this->brutal_staff_buff, L"x4 Melee Damage\r\nx4 Magic Damage ");
		this->brutal_staff_buff->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Buff_DoubleClick);
		// 
		// apprentice_staff_buff
		// 
		this->apprentice_staff_buff->AccessibleDescription = L"2";
		this->apprentice_staff_buff->AccessibleName = L"2";
		this->apprentice_staff_buff->BackColor = System::Drawing::Color::Transparent;
		this->apprentice_staff_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"apprentice_staff_buff.Image")));
		this->apprentice_staff_buff->Location = System::Drawing::Point(32, 135);
		this->apprentice_staff_buff->Name = L"apprentice_staff_buff";
		this->apprentice_staff_buff->Size = System::Drawing::Size(100, 50);
		this->apprentice_staff_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->apprentice_staff_buff->TabIndex = 90;
		this->apprentice_staff_buff->TabStop = false;
		this->ability_info->SetToolTip(this->apprentice_staff_buff, L"x2 Melee Damage\r\nx2 Magic Damage ");
		this->apprentice_staff_buff->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Buff_DoubleClick);
		// 
		// destroyer_buff
		// 
		this->destroyer_buff->AccessibleDescription = L"4";
		this->destroyer_buff->AccessibleName = L"1";
		this->destroyer_buff->BackColor = System::Drawing::Color::Transparent;
		this->destroyer_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"destroyer_buff.Image")));
		this->destroyer_buff->Location = System::Drawing::Point(244, 65);
		this->destroyer_buff->Name = L"destroyer_buff";
		this->destroyer_buff->Size = System::Drawing::Size(100, 50);
		this->destroyer_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->destroyer_buff->TabIndex = 91;
		this->destroyer_buff->TabStop = false;
		this->ability_info->SetToolTip(this->destroyer_buff, L"x4 Melee Damage\r\nx1 Magic Damage ");
		this->destroyer_buff->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Buff_DoubleClick);
		// 
		// staff_of_magi_buff
		// 
		this->staff_of_magi_buff->AccessibleDescription = L"1";
		this->staff_of_magi_buff->AccessibleName = L"10";
		this->staff_of_magi_buff->BackColor = System::Drawing::Color::Transparent;
		this->staff_of_magi_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"staff_of_magi_buff.Image")));
		this->staff_of_magi_buff->Location = System::Drawing::Point(350, 135);
		this->staff_of_magi_buff->Name = L"staff_of_magi_buff";
		this->staff_of_magi_buff->Size = System::Drawing::Size(100, 50);
		this->staff_of_magi_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->staff_of_magi_buff->TabIndex = 92;
		this->staff_of_magi_buff->TabStop = false;
		this->ability_info->SetToolTip(this->staff_of_magi_buff, L"x1 Melee Damage\r\nx10 Magic Damage ");
		this->staff_of_magi_buff->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Buff_DoubleClick);
		// 
		// apprentice_sword_buff
		// 
		this->apprentice_sword_buff->AccessibleDescription = L"2";
		this->apprentice_sword_buff->AccessibleName = L"2";
		this->apprentice_sword_buff->BackColor = System::Drawing::Color::Transparent;
		this->apprentice_sword_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"apprentice_sword_buff.Image")));
		this->apprentice_sword_buff->Location = System::Drawing::Point(32, 65);
		this->apprentice_sword_buff->Name = L"apprentice_sword_buff";
		this->apprentice_sword_buff->Size = System::Drawing::Size(100, 50);
		this->apprentice_sword_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->apprentice_sword_buff->TabIndex = 93;
		this->apprentice_sword_buff->TabStop = false;
		this->ability_info->SetToolTip(this->apprentice_sword_buff, L"x2 Melee Damage\r\nx2 Magic Damage ");
		this->apprentice_sword_buff->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Buff_DoubleClick);
		// 
		// ultimate_fury_buff
		// 
		this->ultimate_fury_buff->AccessibleDescription = L"10";
		this->ultimate_fury_buff->AccessibleName = L"1";
		this->ultimate_fury_buff->BackColor = System::Drawing::Color::Transparent;
		this->ultimate_fury_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ultimate_fury_buff.Image")));
		this->ultimate_fury_buff->Location = System::Drawing::Point(456, 65);
		this->ultimate_fury_buff->Name = L"ultimate_fury_buff";
		this->ultimate_fury_buff->Size = System::Drawing::Size(100, 50);
		this->ultimate_fury_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->ultimate_fury_buff->TabIndex = 94;
		this->ultimate_fury_buff->TabStop = false;
		this->ability_info->SetToolTip(this->ultimate_fury_buff, L"x10 Melee Damage\r\nx1 Magic Damage ");
		this->ultimate_fury_buff->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Buff_DoubleClick);
		// 
		// pig_slaughter_buff
		// 
		this->pig_slaughter_buff->AccessibleDescription = L"3";
		this->pig_slaughter_buff->AccessibleName = L"1";
		this->pig_slaughter_buff->BackColor = System::Drawing::Color::Transparent;
		this->pig_slaughter_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pig_slaughter_buff.Image")));
		this->pig_slaughter_buff->Location = System::Drawing::Point(138, 65);
		this->pig_slaughter_buff->Name = L"pig_slaughter_buff";
		this->pig_slaughter_buff->Size = System::Drawing::Size(100, 50);
		this->pig_slaughter_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->pig_slaughter_buff->TabIndex = 95;
		this->pig_slaughter_buff->TabStop = false;
		this->ability_info->SetToolTip(this->pig_slaughter_buff, L"x3 Melee Damage\r\nx1 Magic Damage ");
		this->pig_slaughter_buff->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Buff_DoubleClick);
		// 
		// cocoons_bane_buff
		// 
		this->cocoons_bane_buff->AccessibleDescription = L"5";
		this->cocoons_bane_buff->AccessibleName = L"1";
		this->cocoons_bane_buff->BackColor = System::Drawing::Color::Transparent;
		this->cocoons_bane_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"cocoons_bane_buff.Image")));
		this->cocoons_bane_buff->Location = System::Drawing::Point(350, 65);
		this->cocoons_bane_buff->Name = L"cocoons_bane_buff";
		this->cocoons_bane_buff->Size = System::Drawing::Size(100, 50);
		this->cocoons_bane_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->cocoons_bane_buff->TabIndex = 97;
		this->cocoons_bane_buff->TabStop = false;
		this->ability_info->SetToolTip(this->cocoons_bane_buff, L"x5 Melee Damage\r\nx1 Magic Damage ");
		this->cocoons_bane_buff->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Buff_DoubleClick);
		// 
		// peruna_death_buff
		// 
		this->peruna_death_buff->AccessibleDescription = L"1";
		this->peruna_death_buff->AccessibleName = L"3";
		this->peruna_death_buff->BackColor = System::Drawing::Color::Transparent;
		this->peruna_death_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"peruna_death_buff.Image")));
		this->peruna_death_buff->Location = System::Drawing::Point(138, 135);
		this->peruna_death_buff->Name = L"peruna_death_buff";
		this->peruna_death_buff->Size = System::Drawing::Size(100, 50);
		this->peruna_death_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->peruna_death_buff->TabIndex = 98;
		this->peruna_death_buff->TabStop = false;
		this->ability_info->SetToolTip(this->peruna_death_buff, L"x1 Melee Damage\r\nx3 Magic Damage ");
		this->peruna_death_buff->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Buff_DoubleClick);
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
		this->load_screen->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->load_screen->Controls->Add(this->start_screen);
		this->load_screen->Location = System::Drawing::Point(869, 203);
		this->load_screen->Name = L"load_screen";
		this->load_screen->Size = System::Drawing::Size(127, 259);
		this->load_screen->TabIndex = 25;
		// 
		// start_screen
		// 
		this->start_screen->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"start_screen.BackgroundImage")));
		this->start_screen->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->start_screen->Controls->Add(this->resume_game);
		this->start_screen->Controls->Add(this->copyright);
		this->start_screen->Controls->Add(this->exit);
		this->start_screen->Controls->Add(this->help);
		this->start_screen->Controls->Add(this->new_game);
		this->start_screen->Location = System::Drawing::Point(25, 25);
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
		// copyright
		// 
		this->copyright->BackColor = System::Drawing::Color::Transparent;
		this->copyright->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->copyright->ForeColor = System::Drawing::SystemColors::Info;
		this->copyright->Location = System::Drawing::Point(12, 661);
		this->copyright->Name = L"copyright";
		this->copyright->Size = System::Drawing::Size(169, 52);
		this->copyright->TabIndex = 33;
		this->copyright->Text = L"Copyright";
		this->copyright->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->copyright->UseCompatibleTextRendering = true;
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
		// status
		// 
		this->status->BackColor = System::Drawing::Color::Transparent;
		this->status->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->status->Location = System::Drawing::Point(488, 7);
		this->status->Name = L"status";
		this->status->Size = System::Drawing::Size(237, 48);
		this->status->TabIndex = 26;
		this->status->Text = L"PLAYERS TURN";
		this->status->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->status->UseCompatibleTextRendering = true;
		// 
		// inventory_panel
		// 
		this->inventory_panel->BackColor = System::Drawing::Color::Transparent;
		this->inventory_panel->Controls->Add(this->ultimate_fury);
		this->inventory_panel->Controls->Add(this->cocoons_bane);
		this->inventory_panel->Controls->Add(this->destroyer);
		this->inventory_panel->Controls->Add(this->pig_slaughter);
		this->inventory_panel->Controls->Add(this->apprentice_sword);
		this->inventory_panel->Controls->Add(this->staff_of_magi);
		this->inventory_panel->Controls->Add(this->brutal_staff);
		this->inventory_panel->Controls->Add(this->peruna_death);
		this->inventory_panel->Controls->Add(this->mana_potion_number);
		this->inventory_panel->Controls->Add(this->health_potion_number);
		this->inventory_panel->Controls->Add(this->melee_buff_number);
		this->inventory_panel->Controls->Add(this->mana);
		this->inventory_panel->Controls->Add(this->magic_buff_number);
		this->inventory_panel->Controls->Add(this->apprentice_staff);
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
		// 
		// ultimate_fury
		// 
		this->ultimate_fury->AutoSize = true;
		this->ultimate_fury->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->ultimate_fury->ForeColor = System::Drawing::SystemColors::Info;
		this->ultimate_fury->Location = System::Drawing::Point(466, 47);
		this->ultimate_fury->Name = L"ultimate_fury";
		this->ultimate_fury->Size = System::Drawing::Size(76, 15);
		this->ultimate_fury->TabIndex = 111;
		this->ultimate_fury->Text = L"Ultimate Fury";
		// 
		// cocoons_bane
		// 
		this->cocoons_bane->AutoSize = true;
		this->cocoons_bane->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->cocoons_bane->ForeColor = System::Drawing::SystemColors::Info;
		this->cocoons_bane->Location = System::Drawing::Point(362, 47);
		this->cocoons_bane->Name = L"cocoons_bane";
		this->cocoons_bane->Size = System::Drawing::Size(81, 15);
		this->cocoons_bane->TabIndex = 110;
		this->cocoons_bane->Text = L"Cocoon\'s Bane";
		// 
		// destroyer
		// 
		this->destroyer->AutoSize = true;
		this->destroyer->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->destroyer->ForeColor = System::Drawing::SystemColors::Info;
		this->destroyer->Location = System::Drawing::Point(251, 47);
		this->destroyer->Name = L"destroyer";
		this->destroyer->Size = System::Drawing::Size(58, 15);
		this->destroyer->TabIndex = 109;
		this->destroyer->Text = L"Destroyer";
		// 
		// pig_slaughter
		// 
		this->pig_slaughter->AutoSize = true;
		this->pig_slaughter->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->pig_slaughter->ForeColor = System::Drawing::SystemColors::Info;
		this->pig_slaughter->Location = System::Drawing::Point(148, 47);
		this->pig_slaughter->Name = L"pig_slaughter";
		this->pig_slaughter->Size = System::Drawing::Size(76, 15);
		this->pig_slaughter->TabIndex = 108;
		this->pig_slaughter->Text = L"Pig Slaughter";
		// 
		// apprentice_sword
		// 
		this->apprentice_sword->AutoSize = true;
		this->apprentice_sword->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->apprentice_sword->ForeColor = System::Drawing::SystemColors::Info;
		this->apprentice_sword->Location = System::Drawing::Point(41, 47);
		this->apprentice_sword->Name = L"apprentice_sword";
		this->apprentice_sword->Size = System::Drawing::Size(100, 15);
		this->apprentice_sword->TabIndex = 107;
		this->apprentice_sword->Text = L"Apprentice Sword";
		// 
		// staff_of_magi
		// 
		this->staff_of_magi->AutoSize = true;
		this->staff_of_magi->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->staff_of_magi->ForeColor = System::Drawing::SystemColors::Info;
		this->staff_of_magi->Location = System::Drawing::Point(362, 118);
		this->staff_of_magi->Name = L"staff_of_magi";
		this->staff_of_magi->Size = System::Drawing::Size(81, 15);
		this->staff_of_magi->TabIndex = 106;
		this->staff_of_magi->Text = L"Staff of Magi";
		// 
		// brutal_staff
		// 
		this->brutal_staff->AutoSize = true;
		this->brutal_staff->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->brutal_staff->ForeColor = System::Drawing::SystemColors::Info;
		this->brutal_staff->Location = System::Drawing::Point(253, 118);
		this->brutal_staff->Name = L"brutal_staff";
		this->brutal_staff->Size = System::Drawing::Size(71, 15);
		this->brutal_staff->TabIndex = 105;
		this->brutal_staff->Text = L"Brutal Staff";
		// 
		// peruna_death
		// 
		this->peruna_death->AutoSize = true;
		this->peruna_death->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->peruna_death->ForeColor = System::Drawing::SystemColors::Info;
		this->peruna_death->Location = System::Drawing::Point(148, 117);
		this->peruna_death->Name = L"peruna_death";
		this->peruna_death->Size = System::Drawing::Size(75, 15);
		this->peruna_death->TabIndex = 104;
		this->peruna_death->Text = L"Peruna Death";
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
		// apprentice_staff
		// 
		this->apprentice_staff->AutoSize = true;
		this->apprentice_staff->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->apprentice_staff->ForeColor = System::Drawing::SystemColors::Info;
		this->apprentice_staff->Location = System::Drawing::Point(41, 117);
		this->apprentice_staff->Name = L"apprentice_staff";
		this->apprentice_staff->Size = System::Drawing::Size(97, 15);
		this->apprentice_staff->TabIndex = 103;
		this->apprentice_staff->Text = L"Apprentice Staff";
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
		this->magic_buff_potion->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::potion_DoubleClick);
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
		this->inventory->Location = System::Drawing::Point(375, 685);
		this->inventory->Name = L"inventory";
		this->inventory->Size = System::Drawing::Size(99, 32);
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
		this->menu->Location = System::Drawing::Point(492, 689);
		this->menu->Name = L"menu";
		this->menu->Size = System::Drawing::Size(98, 28);
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
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->brutal_staff_buff))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->apprentice_staff_buff))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->destroyer_buff))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->staff_of_magi_buff))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->apprentice_sword_buff))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ultimate_fury_buff))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pig_slaughter_buff))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cocoons_bane_buff))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->peruna_death_buff))->EndInit();
		this->load_screen->ResumeLayout(false);
		this->start_screen->ResumeLayout(false);
		this->inventory_panel->ResumeLayout(false);
		this->inventory_panel->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->magic_buff_potion))->EndInit();
		this->ResumeLayout(false);

			}
#pragma endregion


private: System::Void ApprenticeTrial_Load(System::Object^  sender, System::EventArgs^  e) {
				 formCanvas = CreateGraphics();
				 loadingCanvas = load_screen->CreateGraphics();
				 //
				 // Create graphics size of the screen
				 //
				 loadingBitmap = gcnew Bitmap(load_screen->Width, load_screen->Height);
				 dbBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);		 
				 //
				 // Grab its Graphics
				 //
				 loadingGraphics = Graphics::FromImage(loadingBitmap);
				 dbGraphics = Graphics::FromImage(dbBitmap);
				 //
				 //
				 //
				 background = Image::FromFile("loading.png");
				 //
				 //
				 //
				 loadingBlue = Image::FromFile("Blue Glossy.png");
				 nFrames = loadingBlue->Width / loadingBlue->Height;		
				 currentFrame = 0;
				 frameWidth = loadingBlue->Width / nFrames;
				 frameHeight = loadingBlue->Height;
				 
				 
				 lesserWandImage = Image::FromFile("lesserwand.png");
				 greaterWandImage = Image::FromFile("greaterwand.png");
				 whirlwindImage = Image::FromFile("whirlwind.png");
				 lesserIceImage = Image::FromFile("lesserrice.png");
				 greaterIceImage = Image::FromFile("greaterrice.png");
				 electricStormImage = Image::FromFile("electricstorm.png");
				 clearImage = Image::FromFile("clear.png");

				 use_potion_1->Image = clearImage;
				 use_potion_2->Image = clearImage;
				 use_magic_ability->Image = clearImage;
				 magic_multiplier->Image = clearImage;
				 melee_multiplier->Image = clearImage;

				 fManager = gcnew FrameManager();

				 SoundPlayer^ menuMusic = gcnew SoundPlayer("PK_menu.wav");
				 //menuMusic->PlayLooping();
				 
				 Focus();
			 }		

private: System::Void draw_Tick(System::Object^  sender, System::EventArgs^  e) {
				 if(gameHasLoaded)
				 {
					 if(gManager->isPlayerTurn() == false)
					 {
						 String^ playerTurnText = "PLAYER'S TURN";						 
						 						 						 
						 status->Text = playerTurnText; 
					 }						 
					 else
					 {
						 String^ enemyTurnText = gManager->getEnemyInPlayName()->ToUpper() + "'S TURN";
						 
						 status->Text = enemyTurnText; 
					 }

					 if(gManager->isGameOver())
					 {
						 draw->Enabled = false;
						 load_screen->Visible = true;
						 start_screen->Visible = true;
					 }

					 /*int availableMana = gManager->getAvailableMana();
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
						
					 }*/
					 				 

					 gManager->Update();
					 gManager->Draw();
					 
					 //
					 // Make Buffer Visible 
					 //
					 formCanvas->DrawImage(dbBitmap, ClientRectangle);
				 }
			 }
private: System::Void update_Tick(System::Object^  sender, System::EventArgs^  e) {
				 
				 if(gameHasLoaded)
				 {
					 load_screen->Visible = false;
					 load->Enabled = false;
				 }
				 
				 if(currentFrame >= nFrames)
				 {
					currentFrame = 0;					
				 }

				 srcRectangle = Rectangle(currentFrame * frameWidth, 0, frameWidth, frameHeight);
				 currentFrame++;

				 loadingGraphics->DrawImage(background, ClientRectangle);

				 loadingGraphics->DrawImage
				 (
					loadingBlue,
					ClientRectangle.Width / 2 - srcRectangle.Width / 2,
					ClientRectangle.Height - srcRectangle.Height,
					srcRectangle,				
					GraphicsUnit::Pixel
				 );

				 loadingCanvas->DrawImage(loadingBitmap, ClientRectangle);
			 }

private: System::Void ApprenticeTrial::ThreadFunction()
			{				
			    LoadGameMethod();
			}

private: System::Void ApprenticeTrial::LoadGameMethod(){
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
				//
				//
				//
				cocoon = gcnew Enemy
				(
					dbGraphics, 
					"cocoon", 				
					startLocations[COCOON],
					fManager->getCocoonList()
				);
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
				//
				//
				//
				gManager = gcnew GameManager(dbGraphics, player, gcnew array<Enemy^>{floppit, fluppit, peruna, cocoon, makhana});
				//
				//
				//		
				//myThread->Sleep(5000);

				gameHasLoaded = true;

				//SoundPlayer^ menuMusic = gcnew SoundPlayer("gayremix_shield_full.wav");
				//menuMusic->PlayLooping();

				myThread->Abort();
		 }	
private: System::Windows::Forms::Cursor^ ApprenticeTrial::getAbilityCursor(PictureBox^ ability) {
				 // Gets the image from the picturebox 
				 Bitmap^ bmp = safe_cast<Bitmap^>(ability->Image);

				 // Gets the image data from bitmap  
				 IntPtr ptr = bmp->GetHicon();
					 
				 // Returns the new cursor
				 return gcnew System::Windows::Forms::Cursor(ptr);
			 }

private: System::Void ability_Click(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 
				 //Gets object clicked by player
				 PictureBox^ ability = safe_cast<PictureBox^>(sender);

				 int availableMana = gManager->getAvailableMana();					 
				 int abilityCost = (ability->Name == "use_melee_ability") ? int::Parse(ability->AccessibleName) : int::Parse(ability->AccessibleDescription);

				 EState playerAbility = safe_cast<EState>(int::Parse(ability->Tag->ToString()));

				 // If available to click execute the following
				 if(abilityCost < availableMana || playerAbility == HEAL)				 
					 if(ability->Image != clearImage)
					 {					 
						 Execute_Ability(ability);
						 Execute_Click_Hud_Item(ability, e);					 
					 }				
			 }	

private: System::Void Execute_Ability(PictureBox^ ability) {
				 if(ability->Tag != nullptr) 
				 {
					 EState playerAbility = safe_cast<EState>(int::Parse(ability->Tag->ToString()));

					 //
					 int availableMana = gManager->getAvailableMana();
					 
					 int abilityCost = (ability->Name == "use_melee_ability") ? int::Parse(ability->AccessibleName) : int::Parse(ability->AccessibleDescription);

					 // Tracks ability clicked by player
					 if(playerAbility == HEAL)
						 gManager->setPlayerPotion(ability->AccessibleName->ToString());

					 if(abilityCost < availableMana || playerAbility == HEAL)
						 selectedAbility = playerAbility;
				 }				 
			 }

private: System::Void Execute_Click_Hud_Item(PictureBox^ ability, System::Windows::Forms::MouseEventArgs^  e) {				 
				 SoundPlayer^ menuMusic = gcnew SoundPlayer("PK_swing2.wav");

				 switch ( e->Button )
				 {
					case ::MouseButtons::Left:
						if(gManager->isEnemyTurn())
						{
							if(ability->AccessibleName != "health")
							{
								String^ name = ability->Name;

								int damageStats = (name == "use_melee_ability") ? generateMeleeStats() : generateMagicStats();								
								int manaStats = (name == "use_melee_ability") ? int::Parse(ability->AccessibleName) : int::Parse(ability->AccessibleDescription);

								gManager->setPlayerHealthCost(damageStats);
								gManager->setPlayerManaCost(manaStats);
							}
							
							gManager->setPlayerAbility(selectedAbility);
							gManager->StartAttack();							
						}												
					   break;

					case ::MouseButtons::Right:
						ability->AccessibleDescription = "1";
						ability->AccessibleName = "1";
						ability->Tag = "1";
						ability->Image = clearImage;

						
						menuMusic->Play();						
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
			 
			 myThread = gcnew System::Threading::Thread( gcnew System::Threading::ThreadStart( this, &ApprenticeTrial::ThreadFunction ) );
			 myThread->IsBackground = true;
			 myThread->Start();

			 draw->Enabled = true;
			 			 
			 start_screen->Visible = false;

			 //SoundPlayer^ menuMusic = gcnew SoundPlayer("gayremix_shield_half.wav");
			 //menuMusic->PlayLooping();
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

private: System::Void ApprenticeTrial::setToolTips() {

			 ability_info->SetToolTip(melee_multiplier, "x" + melee_multiplier->AccessibleDescription + " Melee Damage\nx" + melee_multiplier->AccessibleName + " Magic Damage");
			 ability_info->SetToolTip(magic_multiplier, "x" + magic_multiplier->AccessibleName + " Melee Damage\nx" + magic_multiplier->AccessibleDescription + " Magic Damage");
			 ability_info->SetToolTip(use_melee_ability, "DAMAGE: " + generateMeleeStats() + "\nMANA: " + use_melee_ability->AccessibleName);
			 ability_info->SetToolTip(use_magic_ability, "DAMAGE: " + generateMagicStats() + "\nMANA: " + use_magic_ability->AccessibleDescription);

		 }
		  // Accessiable Name		: mana damage multiplier
		  // Accessible Description	: melee damage multiplier

private: int ApprenticeTrial::generateMeleeStats() {
			 int meleeDamage = int::Parse(use_melee_ability->AccessibleDescription);
			 int meleeMultiplierPrimary = int::Parse(melee_multiplier->AccessibleDescription);
			 int meleeMultiplierSecondary = int::Parse(magic_multiplier->AccessibleDescription);

			 meleeDamage *= meleeMultiplierPrimary;
			 meleeDamage *= meleeMultiplierSecondary;

			 return meleeDamage;
		 }

private: int ApprenticeTrial::generateMagicStats() {
			 int magicDamage = int::Parse(use_magic_ability->AccessibleName); 
			 int magicMultiplierPrimary = int::Parse(magic_multiplier->AccessibleName);
			 int magicMultiplierSecondary = int::Parse(melee_multiplier->AccessibleName);

			 magicDamage *= magicMultiplierPrimary;
			 magicDamage *= magicMultiplierSecondary;

			 return magicDamage;
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

private: System::Void multiplier_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 PictureBox^ ability = safe_cast<PictureBox^>(sender);
			 ability->Image = clearImage;
		 }

private: System::Void melee_Buff_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 PictureBox^ ability = safe_cast<PictureBox^>(sender);
			 melee_multiplier->AccessibleDescription = ability->AccessibleDescription;
			 melee_multiplier->AccessibleName = ability->AccessibleName;
			 melee_multiplier->Image = ability->Image;
			 melee_multiplier->Tag = ability->Tag;

			 SoundPlayer^ menuMusic = gcnew SoundPlayer("CK_TopSpin1.wav");
			 menuMusic->Play();
			 
		 }

private: System::Void magic_Buff_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 PictureBox^ ability = safe_cast<PictureBox^>(sender);
			 magic_multiplier->AccessibleDescription = ability->AccessibleDescription;
			 magic_multiplier->AccessibleName = ability->AccessibleName;
			 magic_multiplier->Image = ability->Image;
			 magic_multiplier->Tag = ability->Tag;

			 SoundPlayer^ menuMusic = gcnew SoundPlayer("CK_TopSpin1.wav");
			 menuMusic->Play();
		 }

private: System::Void potion_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 PictureBox^ ability = safe_cast<PictureBox^>(sender);

			 if(use_potion_1->Image == clearImage)
			 {
				 use_potion_1->AccessibleDescription = ability->AccessibleDescription;
				 use_potion_1->AccessibleName = ability->AccessibleName;
				 use_potion_1->Image = ability->Image;
				 use_potion_1->Tag = ability->Tag;
			 }
			 else
			 {
				 use_potion_2->AccessibleDescription = ability->AccessibleDescription;
				 use_potion_2->AccessibleName = ability->AccessibleName;
				 use_potion_2->Image = ability->Image;
				 use_potion_2->Tag = ability->Tag;
			 }

			 SoundPlayer^ menuMusic = gcnew SoundPlayer("CK_TopSpin1.wav");
			 menuMusic->Play();
		 }

private: System::Void melee_Ability_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 PictureBox^ ability = safe_cast<PictureBox^>(sender);
			 use_melee_ability->AccessibleDescription = ability->AccessibleDescription;
			 use_melee_ability->AccessibleName = ability->AccessibleName;
			 use_melee_ability->Image = ability->Image;
			 use_melee_ability->Tag = ability->Tag;

			 SoundPlayer^ menuMusic = gcnew SoundPlayer("CK_TopSpin1.wav");
			 menuMusic->Play();
		 }

private: System::Void magic_Ability_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 PictureBox^ ability = safe_cast<PictureBox^>(sender);
			 use_magic_ability->AccessibleDescription = ability->AccessibleDescription;
			 use_magic_ability->AccessibleName = ability->AccessibleName;
			 use_magic_ability->Image = ability->Image;
			 use_magic_ability->Tag = ability->Tag;

			 SoundPlayer^ menuMusic = gcnew SoundPlayer("CK_TopSpin1.wav");
			 menuMusic->Play();
		 }

private: System::Void ability_MouseHover(System::Object^  sender, System::EventArgs^  e) {
			 setToolTips();
		 }
};
}

