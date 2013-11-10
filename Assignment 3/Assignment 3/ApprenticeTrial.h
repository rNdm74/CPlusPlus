#pragma once

#include "Item.h"
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

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		
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

	private: array<Item^>^ items;
 	private: Item^ pickupItem;

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
	private: bool newAvailable;
	private: bool generatedWeapon;
	private: bool gameStarted;

	private: int nFrames;
	private: int currentFrame;
	private: int frameWidth;
	private: int frameHeight;
	private: RectangleF srcRectangle;
	private: int time;
	private: int loading;
	private: int spawned;	

	private: Random^ rGen;

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
	private: System::Windows::Forms::Timer^  game_clock;
	private: System::Windows::Forms::Timer^  game_loading;

	private: System::Windows::Forms::ToolTip^  ability_info;

	private: System::Windows::Forms::Panel^  load_screen;	
	private: System::Windows::Forms::Panel^  start_screen;
	private: System::Windows::Forms::Panel^  inventory_panel;	

	private: System::Windows::Forms::PictureBox^  poison_potion;
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
	private: System::Windows::Forms::PictureBox^  powerup_potion;

	private: System::Windows::Forms::Label^  status;

	private: System::Windows::Forms::Label^  powerup_buff_number;
	private: System::Windows::Forms::Label^  powerup_buff;
	private: System::Windows::Forms::Label^  magic_abilites;
	private: System::Windows::Forms::Label^  melee_abilites;
	private: System::Windows::Forms::Label^  pig_slaughter;
	private: System::Windows::Forms::Label^  apprentice_sword;
	private: System::Windows::Forms::Label^  staff_of_magi;
	private: System::Windows::Forms::Label^  brutal_staff;
	private: System::Windows::Forms::Label^  peruna_death;
	private: System::Windows::Forms::Label^  mana_potion_number;
	private: System::Windows::Forms::Label^  health_potion_number;
	private: System::Windows::Forms::Label^  poison_buff_number;
	private: System::Windows::Forms::Label^  mana;
	private: System::Windows::Forms::Label^  apprentice_staff;
	private: System::Windows::Forms::Label^  health;
    private: System::Windows::Forms::Label^  poison_buff;
	private: System::Windows::Forms::Label^  ultimate_fury;
	private: System::Windows::Forms::Label^  cocoons_bane;
	private: System::Windows::Forms::Label^  destroyer;
	private: System::Windows::Forms::Label^  electric_storm_label;
	private: System::Windows::Forms::Label^  greater_ice_label;
	private: System::Windows::Forms::Label^  lesser_ice_label;
	private: System::Windows::Forms::Label^  whirlwind_label;
	private: System::Windows::Forms::Label^  greater_wand_label;
	private: System::Windows::Forms::Label^  lesser_wand_label;
	private: System::Windows::Forms::Label^  multiplier_label;
	private: System::Windows::Forms::Label^  potion_label;

    private: System::Windows::Forms::Button^  new_game;
    private: System::Windows::Forms::Button^  help;
	private: System::Windows::Forms::Button^  exit;
    private: System::Windows::Forms::Button^  inventory;
	private: System::Windows::Forms::Button^  menu;
	private: System::Windows::Forms::Button^  resume_game;	
private: System::Windows::Forms::PictureBox^  apprentice_image;


	private: System::Windows::Forms::Label^  inventory_label;
	private: System::Windows::Forms::Label^  electric_storm_new;
	private: System::Windows::Forms::Label^  greater_ice_new;
	private: System::Windows::Forms::Label^  lesser_ice_new;
	private: System::Windows::Forms::Label^  whirlwind_new;
	private: System::Windows::Forms::Label^  brutal_staff_new;
	private: System::Windows::Forms::Label^  ultimate_fury_new;
	private: System::Windows::Forms::Label^  cocoons_bane_new;
	private: System::Windows::Forms::Label^  peruna_death_new;
	private: System::Windows::Forms::Label^  destroyer_new;
	private: System::Windows::Forms::Label^  pig_slaughter_new;
	private: System::Windows::Forms::Label^  greater_wand_new;
	private: System::Windows::Forms::Label^  staff_of_magi_new;
	private: System::Windows::Forms::Label^  apprentice_sword_new;
	private: System::Windows::Forms::Label^  apprentice_staff_new;
	private: System::Windows::Forms::Label^  lesser_wand_new;

private: System::Windows::Forms::Button^  back;
private: System::Windows::Forms::Button^  help_back;

private: System::Windows::Forms::Button^  help_hud;

private: System::Windows::Forms::Button^  help_inventory;
private: System::Windows::Forms::Button^  help_howtoplay;



	private: System::ComponentModel::IContainer^  components;
#pragma endregion	

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ApprenticeTrial::typeid));
			this->game_clock = (gcnew System::Windows::Forms::Timer(this->components));
			this->game_loading = (gcnew System::Windows::Forms::Timer(this->components));
			this->ability_info = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->poison_potion = (gcnew System::Windows::Forms::PictureBox());
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
			this->powerup_potion = (gcnew System::Windows::Forms::PictureBox());
			this->new_game = (gcnew System::Windows::Forms::Button());
			this->load_screen = (gcnew System::Windows::Forms::Panel());
			this->start_screen = (gcnew System::Windows::Forms::Panel());
			this->apprentice_image = (gcnew System::Windows::Forms::PictureBox());
			this->resume_game = (gcnew System::Windows::Forms::Button());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->help = (gcnew System::Windows::Forms::Button());
			this->help_howtoplay = (gcnew System::Windows::Forms::Button());
			this->help_back = (gcnew System::Windows::Forms::Button());
			this->help_hud = (gcnew System::Windows::Forms::Button());
			this->help_inventory = (gcnew System::Windows::Forms::Button());
			this->back = (gcnew System::Windows::Forms::Button());
			this->status = (gcnew System::Windows::Forms::Label());
			this->inventory_panel = (gcnew System::Windows::Forms::Panel());
			this->electric_storm_new = (gcnew System::Windows::Forms::Label());
			this->greater_ice_new = (gcnew System::Windows::Forms::Label());
			this->lesser_ice_new = (gcnew System::Windows::Forms::Label());
			this->whirlwind_new = (gcnew System::Windows::Forms::Label());
			this->electric_storm_label = (gcnew System::Windows::Forms::Label());
			this->greater_ice_label = (gcnew System::Windows::Forms::Label());
			this->lesser_ice_label = (gcnew System::Windows::Forms::Label());
			this->whirlwind_label = (gcnew System::Windows::Forms::Label());
			this->greater_wand_label = (gcnew System::Windows::Forms::Label());
			this->brutal_staff_new = (gcnew System::Windows::Forms::Label());
			this->staff_of_magi_new = (gcnew System::Windows::Forms::Label());
			this->ultimate_fury_new = (gcnew System::Windows::Forms::Label());
			this->cocoons_bane_new = (gcnew System::Windows::Forms::Label());
			this->peruna_death_new = (gcnew System::Windows::Forms::Label());
			this->destroyer_new = (gcnew System::Windows::Forms::Label());
			this->pig_slaughter_new = (gcnew System::Windows::Forms::Label());
			this->apprentice_sword_new = (gcnew System::Windows::Forms::Label());
			this->apprentice_staff_new = (gcnew System::Windows::Forms::Label());
			this->lesser_wand_new = (gcnew System::Windows::Forms::Label());
			this->greater_wand_new = (gcnew System::Windows::Forms::Label());
			this->lesser_wand_label = (gcnew System::Windows::Forms::Label());
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
			this->poison_buff_number = (gcnew System::Windows::Forms::Label());
			this->mana = (gcnew System::Windows::Forms::Label());
			this->powerup_buff_number = (gcnew System::Windows::Forms::Label());
			this->apprentice_staff = (gcnew System::Windows::Forms::Label());
			this->health = (gcnew System::Windows::Forms::Label());
			this->poison_buff = (gcnew System::Windows::Forms::Label());
			this->powerup_buff = (gcnew System::Windows::Forms::Label());
			this->magic_abilites = (gcnew System::Windows::Forms::Label());
			this->multiplier_label = (gcnew System::Windows::Forms::Label());
			this->potion_label = (gcnew System::Windows::Forms::Label());
			this->melee_abilites = (gcnew System::Windows::Forms::Label());
			this->inventory = (gcnew System::Windows::Forms::Button());
			this->menu = (gcnew System::Windows::Forms::Button());
			this->inventory_label = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->poison_potion))->BeginInit();
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->powerup_potion))->BeginInit();
			this->load_screen->SuspendLayout();
			this->start_screen->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->apprentice_image))->BeginInit();
			this->inventory_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// game_clock
			// 
			this->game_clock->Interval = 1;
			this->game_clock->Tick += gcnew System::EventHandler(this, &ApprenticeTrial::game_Clock_Tick);
			// 
			// game_loading
			// 
			this->game_loading->Interval = 50;
			this->game_loading->Tick += gcnew System::EventHandler(this, &ApprenticeTrial::game_Loading_Tick);
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
			// poison_potion
			// 
			this->poison_potion->AccessibleDescription = L"50";
			this->poison_potion->AccessibleName = L"poison";
			this->poison_potion->BackColor = System::Drawing::Color::Transparent;
			this->poison_potion->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->poison_potion->Cursor = System::Windows::Forms::Cursors::Hand;
			this->poison_potion->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"poison_potion.Image")));
			this->poison_potion->Location = System::Drawing::Point(190, 193);
			this->poison_potion->Name = L"poison_potion";
			this->poison_potion->Size = System::Drawing::Size(40, 40);
			this->poison_potion->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->poison_potion->TabIndex = 89;
			this->poison_potion->TabStop = false;
			this->poison_potion->Tag = L"11";
			this->ability_info->SetToolTip(this->poison_potion, L"Reduce Enemies Health\r\nfor a period of time");
			this->poison_potion->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::potion_DoubleClick);
			this->poison_potion->Click += gcnew System::EventHandler(this, &ApprenticeTrial::potion_DoubleClick);
			// 
			// mana_potion
			// 
			this->mana_potion->AccessibleDescription = L"50";
			this->mana_potion->AccessibleName = L"mana";
			this->mana_potion->BackColor = System::Drawing::Color::Transparent;
			this->mana_potion->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->mana_potion->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mana_potion->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mana_potion.Image")));
			this->mana_potion->Location = System::Drawing::Point(102, 193);
			this->mana_potion->Name = L"mana_potion";
			this->mana_potion->Size = System::Drawing::Size(40, 40);
			this->mana_potion->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->mana_potion->TabIndex = 88;
			this->mana_potion->TabStop = false;
			this->mana_potion->Tag = L"11";
			this->ability_info->SetToolTip(this->mana_potion, L"Restore 50 Mana points");
			this->mana_potion->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::potion_DoubleClick);
			this->mana_potion->Click += gcnew System::EventHandler(this, &ApprenticeTrial::potion_DoubleClick);
			// 
			// health_potion
			// 
			this->health_potion->AccessibleDescription = L"50";
			this->health_potion->AccessibleName = L"health";
			this->health_potion->BackColor = System::Drawing::Color::Transparent;
			this->health_potion->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->health_potion->Cursor = System::Windows::Forms::Cursors::Hand;
			this->health_potion->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"health_potion.Image")));
			this->health_potion->Location = System::Drawing::Point(13, 193);
			this->health_potion->Name = L"health_potion";
			this->health_potion->Size = System::Drawing::Size(40, 40);
			this->health_potion->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->health_potion->TabIndex = 86;
			this->health_potion->TabStop = false;
			this->health_potion->Tag = L"11";
			this->ability_info->SetToolTip(this->health_potion, L"Restore 50 Health points");
			this->health_potion->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::potion_DoubleClick);
			this->health_potion->Click += gcnew System::EventHandler(this, &ApprenticeTrial::potion_DoubleClick);
			// 
			// electric_storm
			// 
			this->electric_storm->AccessibleDescription = L"110";
			this->electric_storm->AccessibleName = L"10";
			this->electric_storm->BackColor = System::Drawing::Color::Transparent;
			this->electric_storm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->electric_storm->Cursor = System::Windows::Forms::Cursors::Hand;
			this->electric_storm->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"electric_storm.Image")));
			this->electric_storm->Location = System::Drawing::Point(450, 272);
			this->electric_storm->Name = L"electric_storm";
			this->electric_storm->Size = System::Drawing::Size(40, 40);
			this->electric_storm->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->electric_storm->TabIndex = 85;
			this->electric_storm->TabStop = false;
			this->electric_storm->Tag = L"8";
			this->ability_info->SetToolTip(this->electric_storm, L"Damage\t\t10\r\nMana Cost\t120\r\n");
			this->electric_storm->Visible = false;
			this->electric_storm->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Ability_DoubleClick);
			this->electric_storm->Click += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Ability_DoubleClick);
			// 
			// greater_ice
			// 
			this->greater_ice->AccessibleDescription = L"105";
			this->greater_ice->AccessibleName = L"8";
			this->greater_ice->BackColor = System::Drawing::Color::Transparent;
			this->greater_ice->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->greater_ice->Cursor = System::Windows::Forms::Cursors::Hand;
			this->greater_ice->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"greater_ice.Image")));
			this->greater_ice->Location = System::Drawing::Point(365, 272);
			this->greater_ice->Name = L"greater_ice";
			this->greater_ice->Size = System::Drawing::Size(40, 40);
			this->greater_ice->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->greater_ice->TabIndex = 84;
			this->greater_ice->TabStop = false;
			this->greater_ice->Tag = L"4";
			this->ability_info->SetToolTip(this->greater_ice, L"Damage\t\t8\r\nMana Cost\t120");
			this->greater_ice->Visible = false;
			this->greater_ice->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Ability_DoubleClick);
			this->greater_ice->Click += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Ability_DoubleClick);
			// 
			// lesser_ice
			// 
			this->lesser_ice->AccessibleDescription = L"100";
			this->lesser_ice->AccessibleName = L"6";
			this->lesser_ice->BackColor = System::Drawing::Color::Transparent;
			this->lesser_ice->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->lesser_ice->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lesser_ice->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"lesser_ice.Image")));
			this->lesser_ice->Location = System::Drawing::Point(278, 272);
			this->lesser_ice->Name = L"lesser_ice";
			this->lesser_ice->Size = System::Drawing::Size(40, 40);
			this->lesser_ice->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->lesser_ice->TabIndex = 83;
			this->lesser_ice->TabStop = false;
			this->lesser_ice->Tag = L"3";
			this->ability_info->SetToolTip(this->lesser_ice, L"Damage\t\t6\r\nMana Cost\t100\r\n");
			this->lesser_ice->Visible = false;
			this->lesser_ice->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Ability_DoubleClick);
			this->lesser_ice->Click += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Ability_DoubleClick);
			// 
			// whirlwind
			// 
			this->whirlwind->AccessibleDescription = L"10";
			this->whirlwind->AccessibleName = L"30";
			this->whirlwind->BackColor = System::Drawing::Color::Transparent;
			this->whirlwind->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->whirlwind->Cursor = System::Windows::Forms::Cursors::Hand;
			this->whirlwind->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"whirlwind.Image")));
			this->whirlwind->Location = System::Drawing::Point(190, 272);
			this->whirlwind->Name = L"whirlwind";
			this->whirlwind->Size = System::Drawing::Size(40, 40);
			this->whirlwind->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->whirlwind->TabIndex = 82;
			this->whirlwind->TabStop = false;
			this->whirlwind->Tag = L"10";
			this->ability_info->SetToolTip(this->whirlwind, L"Damage\t\t10\r\nMana Cost\t30\r\n");
			this->whirlwind->Visible = false;
			this->whirlwind->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Ability_DoubleClick);
			this->whirlwind->Click += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Ability_DoubleClick);
			// 
			// greater_wand
			// 
			this->greater_wand->AccessibleDescription = L"7";
			this->greater_wand->AccessibleName = L"15";
			this->greater_wand->BackColor = System::Drawing::Color::Transparent;
			this->greater_wand->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->greater_wand->Cursor = System::Windows::Forms::Cursors::Hand;
			this->greater_wand->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"greater_wand.Image")));
			this->greater_wand->Location = System::Drawing::Point(102, 272);
			this->greater_wand->Name = L"greater_wand";
			this->greater_wand->Size = System::Drawing::Size(40, 40);
			this->greater_wand->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->greater_wand->TabIndex = 81;
			this->greater_wand->TabStop = false;
			this->greater_wand->Tag = L"9";
			this->ability_info->SetToolTip(this->greater_wand, L"Damage\t\t7\r\nMana Cost\t15\r\n");
			this->greater_wand->Visible = false;
			this->greater_wand->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Ability_DoubleClick);
			this->greater_wand->Click += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Ability_DoubleClick);
			// 
			// lesser_wand
			// 
			this->lesser_wand->AccessibleDescription = L"5";
			this->lesser_wand->AccessibleName = L"0";
			this->lesser_wand->BackColor = System::Drawing::Color::Transparent;
			this->lesser_wand->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->lesser_wand->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lesser_wand->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"lesser_wand.Image")));
			this->lesser_wand->Location = System::Drawing::Point(13, 272);
			this->lesser_wand->Name = L"lesser_wand";
			this->lesser_wand->Size = System::Drawing::Size(40, 40);
			this->lesser_wand->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->lesser_wand->TabIndex = 80;
			this->lesser_wand->TabStop = false;
			this->lesser_wand->Tag = L"6";
			this->ability_info->SetToolTip(this->lesser_wand, L"Damage\t\t5\r\nMana Cost\t0");
			this->lesser_wand->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Ability_DoubleClick);
			this->lesser_wand->Click += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Ability_DoubleClick);
			// 
			// use_potion_2
			// 
			this->use_potion_2->AccessibleDescription = L"0";
			this->use_potion_2->AccessibleName = L"0";
			this->use_potion_2->BackColor = System::Drawing::Color::Transparent;
			this->use_potion_2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->use_potion_2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->use_potion_2->Enabled = false;
			this->use_potion_2->Location = System::Drawing::Point(647, 685);
			this->use_potion_2->Name = L"use_potion_2";
			this->use_potion_2->Size = System::Drawing::Size(32, 32);
			this->use_potion_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->use_potion_2->TabIndex = 79;
			this->use_potion_2->TabStop = false;
			this->use_potion_2->Tag = L"0";
			this->ability_info->SetToolTip(this->use_potion_2, L"Use Potion");
			this->use_potion_2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ApprenticeTrial::ability_Click);
			// 
			// use_potion_1
			// 
			this->use_potion_1->AccessibleDescription = L"0";
			this->use_potion_1->AccessibleName = L"0";
			this->use_potion_1->BackColor = System::Drawing::Color::Transparent;
			this->use_potion_1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->use_potion_1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->use_potion_1->Enabled = false;
			this->use_potion_1->Location = System::Drawing::Point(599, 685);
			this->use_potion_1->Name = L"use_potion_1";
			this->use_potion_1->Size = System::Drawing::Size(32, 32);
			this->use_potion_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->use_potion_1->TabIndex = 78;
			this->use_potion_1->TabStop = false;
			this->use_potion_1->Tag = L"0";
			this->ability_info->SetToolTip(this->use_potion_1, L"Use Potion");
			this->use_potion_1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ApprenticeTrial::ability_Click);
			// 
			// use_magic_ability
			// 
			this->use_magic_ability->AccessibleDescription = L"0";
			this->use_magic_ability->AccessibleName = L"0";
			this->use_magic_ability->BackColor = System::Drawing::Color::Transparent;
			this->use_magic_ability->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->use_magic_ability->Cursor = System::Windows::Forms::Cursors::Hand;
			this->use_magic_ability->Enabled = false;
			this->use_magic_ability->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"use_magic_ability.Image")));
			this->use_magic_ability->Location = System::Drawing::Point(743, 685);
			this->use_magic_ability->Name = L"use_magic_ability";
			this->use_magic_ability->Size = System::Drawing::Size(32, 32);
			this->use_magic_ability->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->use_magic_ability->TabIndex = 76;
			this->use_magic_ability->TabStop = false;
			this->use_magic_ability->Tag = L"0";
			this->ability_info->SetToolTip(this->use_magic_ability, L"Use Magic Ability");
			this->use_magic_ability->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ApprenticeTrial::ability_Click);
			this->use_magic_ability->MouseHover += gcnew System::EventHandler(this, &ApprenticeTrial::ability_MouseHover);
			// 
			// use_melee_ability
			// 
			this->use_melee_ability->AccessibleDescription = L"0";
			this->use_melee_ability->AccessibleName = L"0";
			this->use_melee_ability->BackColor = System::Drawing::Color::Transparent;
			this->use_melee_ability->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->use_melee_ability->Cursor = System::Windows::Forms::Cursors::Hand;
			this->use_melee_ability->Enabled = false;
			this->use_melee_ability->Location = System::Drawing::Point(695, 685);
			this->use_melee_ability->Name = L"use_melee_ability";
			this->use_melee_ability->Size = System::Drawing::Size(32, 32);
			this->use_melee_ability->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->use_melee_ability->TabIndex = 74;
			this->use_melee_ability->TabStop = false;
			this->use_melee_ability->Tag = L"0";
			this->ability_info->SetToolTip(this->use_melee_ability, L"Use Melee Ability");
			this->use_melee_ability->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ApprenticeTrial::ability_Click);
			this->use_melee_ability->MouseHover += gcnew System::EventHandler(this, &ApprenticeTrial::ability_MouseHover);
			// 
			// melee_multiplier
			// 
			this->melee_multiplier->AccessibleDescription = L"1";
			this->melee_multiplier->AccessibleName = L"1";
			this->melee_multiplier->BackColor = System::Drawing::Color::Transparent;
			this->melee_multiplier->Cursor = System::Windows::Forms::Cursors::Default;
			this->melee_multiplier->Enabled = false;
			this->melee_multiplier->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"melee_multiplier.Image")));
			this->melee_multiplier->Location = System::Drawing::Point(790, 685);
			this->melee_multiplier->Name = L"melee_multiplier";
			this->melee_multiplier->Size = System::Drawing::Size(74, 32);
			this->melee_multiplier->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->melee_multiplier->TabIndex = 77;
			this->melee_multiplier->TabStop = false;
			this->melee_multiplier->Tag = L"0";
			this->ability_info->SetToolTip(this->melee_multiplier, L"Melee Multiplier");
			this->melee_multiplier->MouseHover += gcnew System::EventHandler(this, &ApprenticeTrial::ability_MouseHover);
			// 
			// magic_multiplier
			// 
			this->magic_multiplier->AccessibleDescription = L"1";
			this->magic_multiplier->AccessibleName = L"1";
			this->magic_multiplier->BackColor = System::Drawing::Color::Transparent;
			this->magic_multiplier->Cursor = System::Windows::Forms::Cursors::Default;
			this->magic_multiplier->Enabled = false;
			this->magic_multiplier->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"magic_multiplier.Image")));
			this->magic_multiplier->Location = System::Drawing::Point(881, 685);
			this->magic_multiplier->Name = L"magic_multiplier";
			this->magic_multiplier->Size = System::Drawing::Size(74, 32);
			this->magic_multiplier->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->magic_multiplier->TabIndex = 75;
			this->magic_multiplier->TabStop = false;
			this->magic_multiplier->Tag = L"0";
			this->ability_info->SetToolTip(this->magic_multiplier, L"Magic Multiplier");
			this->magic_multiplier->MouseHover += gcnew System::EventHandler(this, &ApprenticeTrial::ability_MouseHover);
			// 
			// brutal_staff_buff
			// 
			this->brutal_staff_buff->AccessibleDescription = L"4";
			this->brutal_staff_buff->AccessibleName = L"5";
			this->brutal_staff_buff->BackColor = System::Drawing::Color::Transparent;
			this->brutal_staff_buff->Cursor = System::Windows::Forms::Cursors::Hand;
			this->brutal_staff_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"brutal_staff_buff.Image")));
			this->brutal_staff_buff->Location = System::Drawing::Point(225, 107);
			this->brutal_staff_buff->Name = L"brutal_staff_buff";
			this->brutal_staff_buff->Size = System::Drawing::Size(100, 50);
			this->brutal_staff_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->brutal_staff_buff->TabIndex = 96;
			this->brutal_staff_buff->TabStop = false;
			this->ability_info->SetToolTip(this->brutal_staff_buff, L"Melee\tx4\r\nMagic\tx4");
			this->brutal_staff_buff->Visible = false;
			this->brutal_staff_buff->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Buff_DoubleClick);
			this->brutal_staff_buff->Click += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Buff_DoubleClick);
			// 
			// apprentice_staff_buff
			// 
			this->apprentice_staff_buff->AccessibleDescription = L"1";
			this->apprentice_staff_buff->AccessibleName = L"2";
			this->apprentice_staff_buff->BackColor = System::Drawing::Color::Transparent;
			this->apprentice_staff_buff->Cursor = System::Windows::Forms::Cursors::Hand;
			this->apprentice_staff_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"apprentice_staff_buff.Image")));
			this->apprentice_staff_buff->Location = System::Drawing::Point(13, 107);
			this->apprentice_staff_buff->Name = L"apprentice_staff_buff";
			this->apprentice_staff_buff->Size = System::Drawing::Size(100, 50);
			this->apprentice_staff_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->apprentice_staff_buff->TabIndex = 90;
			this->apprentice_staff_buff->TabStop = false;
			this->ability_info->SetToolTip(this->apprentice_staff_buff, L"Melee\tx2\r\nMagic\tx2");
			this->apprentice_staff_buff->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Buff_DoubleClick);
			this->apprentice_staff_buff->Click += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Buff_DoubleClick);
			// 
			// destroyer_buff
			// 
			this->destroyer_buff->AccessibleDescription = L"4";
			this->destroyer_buff->AccessibleName = L"2";
			this->destroyer_buff->BackColor = System::Drawing::Color::Transparent;
			this->destroyer_buff->Cursor = System::Windows::Forms::Cursors::Hand;
			this->destroyer_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"destroyer_buff.Image")));
			this->destroyer_buff->Location = System::Drawing::Point(225, 36);
			this->destroyer_buff->Name = L"destroyer_buff";
			this->destroyer_buff->Size = System::Drawing::Size(100, 50);
			this->destroyer_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->destroyer_buff->TabIndex = 91;
			this->destroyer_buff->TabStop = false;
			this->ability_info->SetToolTip(this->destroyer_buff, L"Melee\tx4\r\nMagic\tx1");
			this->destroyer_buff->Visible = false;
			this->destroyer_buff->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Buff_DoubleClick);
			this->destroyer_buff->Click += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Buff_DoubleClick);
			// 
			// staff_of_magi_buff
			// 
			this->staff_of_magi_buff->AccessibleDescription = L"1";
			this->staff_of_magi_buff->AccessibleName = L"7";
			this->staff_of_magi_buff->BackColor = System::Drawing::Color::Transparent;
			this->staff_of_magi_buff->Cursor = System::Windows::Forms::Cursors::Hand;
			this->staff_of_magi_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"staff_of_magi_buff.Image")));
			this->staff_of_magi_buff->Location = System::Drawing::Point(331, 107);
			this->staff_of_magi_buff->Name = L"staff_of_magi_buff";
			this->staff_of_magi_buff->Size = System::Drawing::Size(100, 50);
			this->staff_of_magi_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->staff_of_magi_buff->TabIndex = 92;
			this->staff_of_magi_buff->TabStop = false;
			this->ability_info->SetToolTip(this->staff_of_magi_buff, L"Melee\tx1\r\nMagic\tx10");
			this->staff_of_magi_buff->Visible = false;
			this->staff_of_magi_buff->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Buff_DoubleClick);
			this->staff_of_magi_buff->Click += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Buff_DoubleClick);
			// 
			// apprentice_sword_buff
			// 
			this->apprentice_sword_buff->AccessibleDescription = L"2";
			this->apprentice_sword_buff->AccessibleName = L"1";
			this->apprentice_sword_buff->BackColor = System::Drawing::Color::Transparent;
			this->apprentice_sword_buff->Cursor = System::Windows::Forms::Cursors::Hand;
			this->apprentice_sword_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"apprentice_sword_buff.Image")));
			this->apprentice_sword_buff->Location = System::Drawing::Point(13, 36);
			this->apprentice_sword_buff->Name = L"apprentice_sword_buff";
			this->apprentice_sword_buff->Size = System::Drawing::Size(100, 50);
			this->apprentice_sword_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->apprentice_sword_buff->TabIndex = 93;
			this->apprentice_sword_buff->TabStop = false;
			this->ability_info->SetToolTip(this->apprentice_sword_buff, L"Melee\tx2\r\nMagic\tx2");
			this->apprentice_sword_buff->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Buff_DoubleClick);
			this->apprentice_sword_buff->Click += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Buff_DoubleClick);
			// 
			// ultimate_fury_buff
			// 
			this->ultimate_fury_buff->AccessibleDescription = L"7";
			this->ultimate_fury_buff->AccessibleName = L"1";
			this->ultimate_fury_buff->BackColor = System::Drawing::Color::Transparent;
			this->ultimate_fury_buff->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ultimate_fury_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ultimate_fury_buff.Image")));
			this->ultimate_fury_buff->Location = System::Drawing::Point(437, 36);
			this->ultimate_fury_buff->Name = L"ultimate_fury_buff";
			this->ultimate_fury_buff->Size = System::Drawing::Size(100, 50);
			this->ultimate_fury_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->ultimate_fury_buff->TabIndex = 94;
			this->ultimate_fury_buff->TabStop = false;
			this->ability_info->SetToolTip(this->ultimate_fury_buff, L"Melee\tx10\r\nMagic\tx1");
			this->ultimate_fury_buff->Visible = false;
			this->ultimate_fury_buff->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Buff_DoubleClick);
			this->ultimate_fury_buff->Click += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Buff_DoubleClick);
			// 
			// pig_slaughter_buff
			// 
			this->pig_slaughter_buff->AccessibleDescription = L"3";
			this->pig_slaughter_buff->AccessibleName = L"1";
			this->pig_slaughter_buff->BackColor = System::Drawing::Color::Transparent;
			this->pig_slaughter_buff->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pig_slaughter_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pig_slaughter_buff.Image")));
			this->pig_slaughter_buff->Location = System::Drawing::Point(119, 36);
			this->pig_slaughter_buff->Name = L"pig_slaughter_buff";
			this->pig_slaughter_buff->Size = System::Drawing::Size(100, 50);
			this->pig_slaughter_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pig_slaughter_buff->TabIndex = 95;
			this->pig_slaughter_buff->TabStop = false;
			this->ability_info->SetToolTip(this->pig_slaughter_buff, L"Melee\tx3\r\nMagic\tx1");
			this->pig_slaughter_buff->Visible = false;
			this->pig_slaughter_buff->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Buff_DoubleClick);
			this->pig_slaughter_buff->Click += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Buff_DoubleClick);
			// 
			// cocoons_bane_buff
			// 
			this->cocoons_bane_buff->AccessibleDescription = L"5";
			this->cocoons_bane_buff->AccessibleName = L"3";
			this->cocoons_bane_buff->BackColor = System::Drawing::Color::Transparent;
			this->cocoons_bane_buff->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cocoons_bane_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"cocoons_bane_buff.Image")));
			this->cocoons_bane_buff->Location = System::Drawing::Point(331, 36);
			this->cocoons_bane_buff->Name = L"cocoons_bane_buff";
			this->cocoons_bane_buff->Size = System::Drawing::Size(100, 50);
			this->cocoons_bane_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->cocoons_bane_buff->TabIndex = 97;
			this->cocoons_bane_buff->TabStop = false;
			this->ability_info->SetToolTip(this->cocoons_bane_buff, L"Melee\tx5\r\nMagic\tx1");
			this->cocoons_bane_buff->Visible = false;
			this->cocoons_bane_buff->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Buff_DoubleClick);
			this->cocoons_bane_buff->Click += gcnew System::EventHandler(this, &ApprenticeTrial::melee_Buff_DoubleClick);
			// 
			// peruna_death_buff
			// 
			this->peruna_death_buff->AccessibleDescription = L"1";
			this->peruna_death_buff->AccessibleName = L"4";
			this->peruna_death_buff->BackColor = System::Drawing::Color::Transparent;
			this->peruna_death_buff->Cursor = System::Windows::Forms::Cursors::Hand;
			this->peruna_death_buff->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"peruna_death_buff.Image")));
			this->peruna_death_buff->Location = System::Drawing::Point(119, 107);
			this->peruna_death_buff->Name = L"peruna_death_buff";
			this->peruna_death_buff->Size = System::Drawing::Size(100, 50);
			this->peruna_death_buff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->peruna_death_buff->TabIndex = 98;
			this->peruna_death_buff->TabStop = false;
			this->ability_info->SetToolTip(this->peruna_death_buff, L"Melee\tx1\r\nMagic\tx3");
			this->peruna_death_buff->Visible = false;
			this->peruna_death_buff->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Buff_DoubleClick);
			this->peruna_death_buff->Click += gcnew System::EventHandler(this, &ApprenticeTrial::magic_Buff_DoubleClick);
			// 
			// powerup_potion
			// 
			this->powerup_potion->AccessibleDescription = L"50";
			this->powerup_potion->AccessibleName = L"power";
			this->powerup_potion->BackColor = System::Drawing::Color::Transparent;
			this->powerup_potion->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->powerup_potion->Cursor = System::Windows::Forms::Cursors::Hand;
			this->powerup_potion->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"powerup_potion.Image")));
			this->powerup_potion->Location = System::Drawing::Point(278, 193);
			this->powerup_potion->Name = L"powerup_potion";
			this->powerup_potion->Size = System::Drawing::Size(40, 40);
			this->powerup_potion->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->powerup_potion->TabIndex = 87;
			this->powerup_potion->TabStop = false;
			this->powerup_potion->Tag = L"11";
			this->ability_info->SetToolTip(this->powerup_potion, L"Increase Health & Mana \r\nfor a period of time");
			this->powerup_potion->DoubleClick += gcnew System::EventHandler(this, &ApprenticeTrial::potion_DoubleClick);
			this->powerup_potion->Click += gcnew System::EventHandler(this, &ApprenticeTrial::potion_DoubleClick);
			// 
			// new_game
			// 
			this->new_game->BackColor = System::Drawing::Color::Transparent;
			this->new_game->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"new_game.BackgroundImage")));
			this->new_game->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->new_game->Cursor = System::Windows::Forms::Cursors::Hand;
			this->new_game->FlatAppearance->BorderSize = 0;
			this->new_game->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->new_game->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->new_game->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->new_game->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->new_game->Location = System::Drawing::Point(426, 324);
			this->new_game->Name = L"new_game";
			this->new_game->Size = System::Drawing::Size(168, 41);
			this->new_game->TabIndex = 1;
			this->new_game->UseVisualStyleBackColor = false;
			this->new_game->Click += gcnew System::EventHandler(this, &ApprenticeTrial::play_Click);
			// 
			// load_screen
			// 
			this->load_screen->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"load_screen.BackgroundImage")));
			this->load_screen->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->load_screen->Controls->Add(this->start_screen);
			this->load_screen->Controls->Add(this->help_howtoplay);
			this->load_screen->Controls->Add(this->help_back);
			this->load_screen->Controls->Add(this->help_hud);
			this->load_screen->Controls->Add(this->help_inventory);
			this->load_screen->Controls->Add(this->back);
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
			this->start_screen->Controls->Add(this->apprentice_image);
			this->start_screen->Controls->Add(this->resume_game);
			this->start_screen->Controls->Add(this->exit);
			this->start_screen->Controls->Add(this->help);
			this->start_screen->Controls->Add(this->new_game);
			this->start_screen->Dock = System::Windows::Forms::DockStyle::Fill;
			this->start_screen->Location = System::Drawing::Point(0, 0);
			this->start_screen->Name = L"start_screen";
			this->start_screen->Size = System::Drawing::Size(1008, 729);
			this->start_screen->TabIndex = 30;
			// 
			// apprentice_image
			// 
			this->apprentice_image->BackColor = System::Drawing::Color::Transparent;
			this->apprentice_image->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"apprentice_image.Image")));
			this->apprentice_image->Location = System::Drawing::Point(216, 404);
			this->apprentice_image->Name = L"apprentice_image";
			this->apprentice_image->Size = System::Drawing::Size(138, 185);
			this->apprentice_image->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->apprentice_image->TabIndex = 35;
			this->apprentice_image->TabStop = false;
			// 
			// resume_game
			// 
			this->resume_game->BackColor = System::Drawing::Color::Transparent;
			this->resume_game->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"resume_game.BackgroundImage")));
			this->resume_game->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->resume_game->Cursor = System::Windows::Forms::Cursors::Hand;
			this->resume_game->FlatAppearance->BorderSize = 0;
			this->resume_game->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->resume_game->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->resume_game->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->resume_game->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->resume_game->Location = System::Drawing::Point(426, 277);
			this->resume_game->Name = L"resume_game";
			this->resume_game->Size = System::Drawing::Size(168, 41);
			this->resume_game->TabIndex = 34;
			this->resume_game->UseVisualStyleBackColor = false;
			this->resume_game->Visible = false;
			this->resume_game->Click += gcnew System::EventHandler(this, &ApprenticeTrial::resume_Click);
			// 
			// exit
			// 
			this->exit->BackColor = System::Drawing::Color::Transparent;
			this->exit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"exit.BackgroundImage")));
			this->exit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->exit->FlatAppearance->BorderSize = 0;
			this->exit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->exit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->exit->Location = System::Drawing::Point(426, 418);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(168, 41);
			this->exit->TabIndex = 3;
			this->exit->UseVisualStyleBackColor = false;
			this->exit->Click += gcnew System::EventHandler(this, &ApprenticeTrial::quit_Click);
			// 
			// help
			// 
			this->help->BackColor = System::Drawing::Color::Transparent;
			this->help->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"help.BackgroundImage")));
			this->help->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->help->Cursor = System::Windows::Forms::Cursors::Hand;
			this->help->FlatAppearance->BorderSize = 0;
			this->help->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->help->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->help->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->help->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->help->Location = System::Drawing::Point(426, 371);
			this->help->Name = L"help";
			this->help->Size = System::Drawing::Size(168, 41);
			this->help->TabIndex = 2;
			this->help->UseVisualStyleBackColor = false;
			this->help->Click += gcnew System::EventHandler(this, &ApprenticeTrial::help_Click);
			// 
			// help_howtoplay
			// 
			this->help_howtoplay->BackColor = System::Drawing::Color::Transparent;
			this->help_howtoplay->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"help_howtoplay.BackgroundImage")));
			this->help_howtoplay->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->help_howtoplay->Cursor = System::Windows::Forms::Cursors::Hand;
			this->help_howtoplay->FlatAppearance->BorderSize = 0;
			this->help_howtoplay->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->help_howtoplay->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->help_howtoplay->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->help_howtoplay->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->help_howtoplay->Location = System::Drawing::Point(426, 277);
			this->help_howtoplay->Name = L"help_howtoplay";
			this->help_howtoplay->Size = System::Drawing::Size(168, 41);
			this->help_howtoplay->TabIndex = 34;
			this->help_howtoplay->UseVisualStyleBackColor = false;
			this->help_howtoplay->Click += gcnew System::EventHandler(this, &ApprenticeTrial::help_howtoplay_Click);
			// 
			// help_back
			// 
			this->help_back->BackColor = System::Drawing::Color::Transparent;
			this->help_back->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"help_back.BackgroundImage")));
			this->help_back->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->help_back->Cursor = System::Windows::Forms::Cursors::Hand;
			this->help_back->FlatAppearance->BorderSize = 0;
			this->help_back->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->help_back->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->help_back->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->help_back->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->help_back->Location = System::Drawing::Point(12, 12);
			this->help_back->Name = L"help_back";
			this->help_back->Size = System::Drawing::Size(168, 41);
			this->help_back->TabIndex = 33;
			this->help_back->UseVisualStyleBackColor = false;
			this->help_back->Visible = false;
			this->help_back->Click += gcnew System::EventHandler(this, &ApprenticeTrial::help_back_Click);
			// 
			// help_hud
			// 
			this->help_hud->BackColor = System::Drawing::Color::Transparent;
			this->help_hud->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"help_hud.BackgroundImage")));
			this->help_hud->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->help_hud->Cursor = System::Windows::Forms::Cursors::Hand;
			this->help_hud->FlatAppearance->BorderSize = 0;
			this->help_hud->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->help_hud->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->help_hud->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->help_hud->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->help_hud->Location = System::Drawing::Point(426, 371);
			this->help_hud->Name = L"help_hud";
			this->help_hud->Size = System::Drawing::Size(168, 41);
			this->help_hud->TabIndex = 32;
			this->help_hud->UseVisualStyleBackColor = false;
			this->help_hud->Click += gcnew System::EventHandler(this, &ApprenticeTrial::help_hud_Click);
			// 
			// help_inventory
			// 
			this->help_inventory->BackColor = System::Drawing::Color::Transparent;
			this->help_inventory->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"help_inventory.BackgroundImage")));
			this->help_inventory->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->help_inventory->Cursor = System::Windows::Forms::Cursors::Hand;
			this->help_inventory->FlatAppearance->BorderSize = 0;
			this->help_inventory->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->help_inventory->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->help_inventory->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->help_inventory->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->help_inventory->Location = System::Drawing::Point(426, 324);
			this->help_inventory->Name = L"help_inventory";
			this->help_inventory->Size = System::Drawing::Size(168, 41);
			this->help_inventory->TabIndex = 31;
			this->help_inventory->UseVisualStyleBackColor = false;
			this->help_inventory->Click += gcnew System::EventHandler(this, &ApprenticeTrial::help_inventory_Click);
			// 
			// back
			// 
			this->back->BackColor = System::Drawing::Color::Transparent;
			this->back->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"back.BackgroundImage")));
			this->back->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->back->Cursor = System::Windows::Forms::Cursors::Hand;
			this->back->FlatAppearance->BorderSize = 0;
			this->back->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->back->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->back->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->back->Font = (gcnew System::Drawing::Font(L"Tahoma", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->back->Location = System::Drawing::Point(426, 418);
			this->back->Name = L"back";
			this->back->Size = System::Drawing::Size(168, 41);
			this->back->TabIndex = 3;
			this->back->UseVisualStyleBackColor = false;
			this->back->Click += gcnew System::EventHandler(this, &ApprenticeTrial::back_Click);
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
			this->status->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->status->UseCompatibleTextRendering = true;
			// 
			// inventory_panel
			// 
			this->inventory_panel->BackColor = System::Drawing::Color::Transparent;
			this->inventory_panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->inventory_panel->Controls->Add(this->electric_storm_new);
			this->inventory_panel->Controls->Add(this->greater_ice_new);
			this->inventory_panel->Controls->Add(this->lesser_ice_new);
			this->inventory_panel->Controls->Add(this->whirlwind_new);
			this->inventory_panel->Controls->Add(this->electric_storm_label);
			this->inventory_panel->Controls->Add(this->greater_ice_label);
			this->inventory_panel->Controls->Add(this->lesser_ice_label);
			this->inventory_panel->Controls->Add(this->whirlwind_label);
			this->inventory_panel->Controls->Add(this->greater_wand_label);
			this->inventory_panel->Controls->Add(this->brutal_staff_new);
			this->inventory_panel->Controls->Add(this->staff_of_magi_new);
			this->inventory_panel->Controls->Add(this->ultimate_fury_new);
			this->inventory_panel->Controls->Add(this->cocoons_bane_new);
			this->inventory_panel->Controls->Add(this->peruna_death_new);
			this->inventory_panel->Controls->Add(this->destroyer_new);
			this->inventory_panel->Controls->Add(this->pig_slaughter_new);
			this->inventory_panel->Controls->Add(this->apprentice_sword_new);
			this->inventory_panel->Controls->Add(this->apprentice_staff_new);
			this->inventory_panel->Controls->Add(this->lesser_wand_new);
			this->inventory_panel->Controls->Add(this->greater_wand_new);
			this->inventory_panel->Controls->Add(this->lesser_wand_label);
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
			this->inventory_panel->Controls->Add(this->poison_buff_number);
			this->inventory_panel->Controls->Add(this->mana);
			this->inventory_panel->Controls->Add(this->powerup_buff_number);
			this->inventory_panel->Controls->Add(this->apprentice_staff);
			this->inventory_panel->Controls->Add(this->health);
			this->inventory_panel->Controls->Add(this->poison_buff);
			this->inventory_panel->Controls->Add(this->powerup_buff);
			this->inventory_panel->Controls->Add(this->magic_abilites);
			this->inventory_panel->Controls->Add(this->electric_storm);
			this->inventory_panel->Controls->Add(this->multiplier_label);
			this->inventory_panel->Controls->Add(this->potion_label);
			this->inventory_panel->Controls->Add(this->melee_abilites);
			this->inventory_panel->Controls->Add(this->lesser_ice);
			this->inventory_panel->Controls->Add(this->greater_ice);
			this->inventory_panel->Controls->Add(this->lesser_wand);
			this->inventory_panel->Controls->Add(this->greater_wand);
			this->inventory_panel->Controls->Add(this->whirlwind);
			this->inventory_panel->Controls->Add(this->brutal_staff_buff);
			this->inventory_panel->Controls->Add(this->apprentice_staff_buff);
			this->inventory_panel->Controls->Add(this->poison_potion);
			this->inventory_panel->Controls->Add(this->destroyer_buff);
			this->inventory_panel->Controls->Add(this->mana_potion);
			this->inventory_panel->Controls->Add(this->staff_of_magi_buff);
			this->inventory_panel->Controls->Add(this->powerup_potion);
			this->inventory_panel->Controls->Add(this->apprentice_sword_buff);
			this->inventory_panel->Controls->Add(this->health_potion);
			this->inventory_panel->Controls->Add(this->ultimate_fury_buff);
			this->inventory_panel->Controls->Add(this->pig_slaughter_buff);
			this->inventory_panel->Controls->Add(this->cocoons_bane_buff);
			this->inventory_panel->Controls->Add(this->peruna_death_buff);
			this->inventory_panel->Location = System::Drawing::Point(235, 179);
			this->inventory_panel->Name = L"inventory_panel";
			this->inventory_panel->Size = System::Drawing::Size(555, 324);
			this->inventory_panel->TabIndex = 27;
			this->inventory_panel->Visible = false;
			// 
			// electric_storm_new
			// 
			this->electric_storm_new->AutoSize = true;
			this->electric_storm_new->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->electric_storm_new->ForeColor = System::Drawing::Color::Gold;
			this->electric_storm_new->Location = System::Drawing::Point(496, 294);
			this->electric_storm_new->Name = L"electric_storm_new";
			this->electric_storm_new->Size = System::Drawing::Size(8, 23);
			this->electric_storm_new->TabIndex = 116;
			this->electric_storm_new->Text = L"!";
			this->electric_storm_new->UseCompatibleTextRendering = true;
			this->electric_storm_new->Visible = false;
			// 
			// greater_ice_new
			// 
			this->greater_ice_new->AutoSize = true;
			this->greater_ice_new->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->greater_ice_new->ForeColor = System::Drawing::Color::Gold;
			this->greater_ice_new->Location = System::Drawing::Point(410, 294);
			this->greater_ice_new->Name = L"greater_ice_new";
			this->greater_ice_new->Size = System::Drawing::Size(8, 23);
			this->greater_ice_new->TabIndex = 115;
			this->greater_ice_new->Text = L"!";
			this->greater_ice_new->UseCompatibleTextRendering = true;
			this->greater_ice_new->Visible = false;
			// 
			// lesser_ice_new
			// 
			this->lesser_ice_new->AutoSize = true;
			this->lesser_ice_new->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lesser_ice_new->ForeColor = System::Drawing::Color::Gold;
			this->lesser_ice_new->Location = System::Drawing::Point(323, 294);
			this->lesser_ice_new->Name = L"lesser_ice_new";
			this->lesser_ice_new->Size = System::Drawing::Size(8, 23);
			this->lesser_ice_new->TabIndex = 114;
			this->lesser_ice_new->Text = L"!";
			this->lesser_ice_new->UseCompatibleTextRendering = true;
			this->lesser_ice_new->Visible = false;
			// 
			// whirlwind_new
			// 
			this->whirlwind_new->AutoSize = true;
			this->whirlwind_new->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->whirlwind_new->ForeColor = System::Drawing::Color::Gold;
			this->whirlwind_new->Location = System::Drawing::Point(233, 294);
			this->whirlwind_new->Name = L"whirlwind_new";
			this->whirlwind_new->Size = System::Drawing::Size(8, 23);
			this->whirlwind_new->TabIndex = 113;
			this->whirlwind_new->Text = L"!";
			this->whirlwind_new->UseCompatibleTextRendering = true;
			this->whirlwind_new->Visible = false;
			// 
			// electric_storm_label
			// 
			this->electric_storm_label->AutoSize = true;
			this->electric_storm_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->electric_storm_label->ForeColor = System::Drawing::SystemColors::Info;
			this->electric_storm_label->Location = System::Drawing::Point(459, 254);
			this->electric_storm_label->Name = L"electric_storm_label";
			this->electric_storm_label->Size = System::Drawing::Size(82, 15);
			this->electric_storm_label->TabIndex = 112;
			this->electric_storm_label->Text = L"Electric Storm";
			// 
			// greater_ice_label
			// 
			this->greater_ice_label->AutoSize = true;
			this->greater_ice_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->greater_ice_label->ForeColor = System::Drawing::SystemColors::Info;
			this->greater_ice_label->Location = System::Drawing::Point(374, 254);
			this->greater_ice_label->Name = L"greater_ice_label";
			this->greater_ice_label->Size = System::Drawing::Size(68, 15);
			this->greater_ice_label->TabIndex = 112;
			this->greater_ice_label->Text = L"Greater Ice";
			// 
			// lesser_ice_label
			// 
			this->lesser_ice_label->AutoSize = true;
			this->lesser_ice_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lesser_ice_label->ForeColor = System::Drawing::SystemColors::Info;
			this->lesser_ice_label->Location = System::Drawing::Point(288, 254);
			this->lesser_ice_label->Name = L"lesser_ice_label";
			this->lesser_ice_label->Size = System::Drawing::Size(61, 15);
			this->lesser_ice_label->TabIndex = 112;
			this->lesser_ice_label->Text = L"Lesser Ice";
			// 
			// whirlwind_label
			// 
			this->whirlwind_label->AutoSize = true;
			this->whirlwind_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->whirlwind_label->ForeColor = System::Drawing::SystemColors::Info;
			this->whirlwind_label->Location = System::Drawing::Point(196, 254);
			this->whirlwind_label->Name = L"whirlwind_label";
			this->whirlwind_label->Size = System::Drawing::Size(61, 15);
			this->whirlwind_label->TabIndex = 112;
			this->whirlwind_label->Text = L"Whirlwind";
			// 
			// greater_wand_label
			// 
			this->greater_wand_label->AutoSize = true;
			this->greater_wand_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->greater_wand_label->ForeColor = System::Drawing::SystemColors::Info;
			this->greater_wand_label->Location = System::Drawing::Point(107, 254);
			this->greater_wand_label->Name = L"greater_wand_label";
			this->greater_wand_label->Size = System::Drawing::Size(80, 15);
			this->greater_wand_label->TabIndex = 112;
			this->greater_wand_label->Text = L"Greater Wand";
			// 
			// brutal_staff_new
			// 
			this->brutal_staff_new->AutoSize = true;
			this->brutal_staff_new->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->brutal_staff_new->ForeColor = System::Drawing::Color::Gold;
			this->brutal_staff_new->Location = System::Drawing::Point(313, 138);
			this->brutal_staff_new->Name = L"brutal_staff_new";
			this->brutal_staff_new->Size = System::Drawing::Size(8, 23);
			this->brutal_staff_new->TabIndex = 112;
			this->brutal_staff_new->Text = L"!";
			this->brutal_staff_new->UseCompatibleTextRendering = true;
			this->brutal_staff_new->Visible = false;
			// 
			// staff_of_magi_new
			// 
			this->staff_of_magi_new->AutoSize = true;
			this->staff_of_magi_new->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->staff_of_magi_new->ForeColor = System::Drawing::Color::Gold;
			this->staff_of_magi_new->Location = System::Drawing::Point(419, 138);
			this->staff_of_magi_new->Name = L"staff_of_magi_new";
			this->staff_of_magi_new->Size = System::Drawing::Size(8, 23);
			this->staff_of_magi_new->TabIndex = 112;
			this->staff_of_magi_new->Text = L"!";
			this->staff_of_magi_new->UseCompatibleTextRendering = true;
			this->staff_of_magi_new->Visible = false;
			// 
			// ultimate_fury_new
			// 
			this->ultimate_fury_new->AutoSize = true;
			this->ultimate_fury_new->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ultimate_fury_new->ForeColor = System::Drawing::Color::Gold;
			this->ultimate_fury_new->Location = System::Drawing::Point(525, 67);
			this->ultimate_fury_new->Name = L"ultimate_fury_new";
			this->ultimate_fury_new->Size = System::Drawing::Size(8, 23);
			this->ultimate_fury_new->TabIndex = 112;
			this->ultimate_fury_new->Text = L"!";
			this->ultimate_fury_new->UseCompatibleTextRendering = true;
			this->ultimate_fury_new->Visible = false;
			// 
			// cocoons_bane_new
			// 
			this->cocoons_bane_new->AutoSize = true;
			this->cocoons_bane_new->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->cocoons_bane_new->ForeColor = System::Drawing::Color::Gold;
			this->cocoons_bane_new->Location = System::Drawing::Point(419, 67);
			this->cocoons_bane_new->Name = L"cocoons_bane_new";
			this->cocoons_bane_new->Size = System::Drawing::Size(8, 23);
			this->cocoons_bane_new->TabIndex = 112;
			this->cocoons_bane_new->Text = L"!";
			this->cocoons_bane_new->UseCompatibleTextRendering = true;
			this->cocoons_bane_new->Visible = false;
			// 
			// peruna_death_new
			// 
			this->peruna_death_new->AutoSize = true;
			this->peruna_death_new->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->peruna_death_new->ForeColor = System::Drawing::Color::Gold;
			this->peruna_death_new->Location = System::Drawing::Point(207, 138);
			this->peruna_death_new->Name = L"peruna_death_new";
			this->peruna_death_new->Size = System::Drawing::Size(8, 23);
			this->peruna_death_new->TabIndex = 112;
			this->peruna_death_new->Text = L"!";
			this->peruna_death_new->UseCompatibleTextRendering = true;
			this->peruna_death_new->Visible = false;
			// 
			// destroyer_new
			// 
			this->destroyer_new->AutoSize = true;
			this->destroyer_new->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->destroyer_new->ForeColor = System::Drawing::Color::Gold;
			this->destroyer_new->Location = System::Drawing::Point(313, 67);
			this->destroyer_new->Name = L"destroyer_new";
			this->destroyer_new->Size = System::Drawing::Size(8, 23);
			this->destroyer_new->TabIndex = 112;
			this->destroyer_new->Text = L"!";
			this->destroyer_new->UseCompatibleTextRendering = true;
			this->destroyer_new->Visible = false;
			// 
			// pig_slaughter_new
			// 
			this->pig_slaughter_new->AutoSize = true;
			this->pig_slaughter_new->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->pig_slaughter_new->ForeColor = System::Drawing::Color::Gold;
			this->pig_slaughter_new->Location = System::Drawing::Point(207, 67);
			this->pig_slaughter_new->Name = L"pig_slaughter_new";
			this->pig_slaughter_new->Size = System::Drawing::Size(8, 23);
			this->pig_slaughter_new->TabIndex = 112;
			this->pig_slaughter_new->Text = L"!";
			this->pig_slaughter_new->UseCompatibleTextRendering = true;
			this->pig_slaughter_new->Visible = false;
			// 
			// apprentice_sword_new
			// 
			this->apprentice_sword_new->AutoSize = true;
			this->apprentice_sword_new->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->apprentice_sword_new->ForeColor = System::Drawing::Color::Gold;
			this->apprentice_sword_new->Location = System::Drawing::Point(105, 67);
			this->apprentice_sword_new->Name = L"apprentice_sword_new";
			this->apprentice_sword_new->Size = System::Drawing::Size(8, 23);
			this->apprentice_sword_new->TabIndex = 112;
			this->apprentice_sword_new->Text = L"!";
			this->apprentice_sword_new->UseCompatibleTextRendering = true;
			// 
			// apprentice_staff_new
			// 
			this->apprentice_staff_new->AutoSize = true;
			this->apprentice_staff_new->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->apprentice_staff_new->ForeColor = System::Drawing::Color::Gold;
			this->apprentice_staff_new->Location = System::Drawing::Point(102, 138);
			this->apprentice_staff_new->Name = L"apprentice_staff_new";
			this->apprentice_staff_new->Size = System::Drawing::Size(8, 23);
			this->apprentice_staff_new->TabIndex = 112;
			this->apprentice_staff_new->Text = L"!";
			this->apprentice_staff_new->UseCompatibleTextRendering = true;
			// 
			// lesser_wand_new
			// 
			this->lesser_wand_new->AutoSize = true;
			this->lesser_wand_new->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lesser_wand_new->ForeColor = System::Drawing::Color::Gold;
			this->lesser_wand_new->Location = System::Drawing::Point(54, 294);
			this->lesser_wand_new->Name = L"lesser_wand_new";
			this->lesser_wand_new->Size = System::Drawing::Size(8, 23);
			this->lesser_wand_new->TabIndex = 112;
			this->lesser_wand_new->Text = L"!";
			this->lesser_wand_new->UseCompatibleTextRendering = true;
			// 
			// greater_wand_new
			// 
			this->greater_wand_new->AutoSize = true;
			this->greater_wand_new->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->greater_wand_new->ForeColor = System::Drawing::Color::Gold;
			this->greater_wand_new->Location = System::Drawing::Point(145, 294);
			this->greater_wand_new->Name = L"greater_wand_new";
			this->greater_wand_new->Size = System::Drawing::Size(8, 23);
			this->greater_wand_new->TabIndex = 112;
			this->greater_wand_new->Text = L"!";
			this->greater_wand_new->UseCompatibleTextRendering = true;
			this->greater_wand_new->Visible = false;
			// 
			// lesser_wand_label
			// 
			this->lesser_wand_label->AutoSize = true;
			this->lesser_wand_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lesser_wand_label->ForeColor = System::Drawing::SystemColors::Info;
			this->lesser_wand_label->Location = System::Drawing::Point(22, 254);
			this->lesser_wand_label->Name = L"lesser_wand_label";
			this->lesser_wand_label->Size = System::Drawing::Size(73, 15);
			this->lesser_wand_label->TabIndex = 112;
			this->lesser_wand_label->Text = L"Lesser Wand";
			// 
			// ultimate_fury
			// 
			this->ultimate_fury->AutoSize = true;
			this->ultimate_fury->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ultimate_fury->ForeColor = System::Drawing::SystemColors::Info;
			this->ultimate_fury->Location = System::Drawing::Point(447, 18);
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
			this->cocoons_bane->Location = System::Drawing::Point(343, 18);
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
			this->destroyer->Location = System::Drawing::Point(232, 18);
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
			this->pig_slaughter->Location = System::Drawing::Point(129, 18);
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
			this->apprentice_sword->Location = System::Drawing::Point(22, 18);
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
			this->staff_of_magi->Location = System::Drawing::Point(343, 90);
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
			this->brutal_staff->Location = System::Drawing::Point(234, 90);
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
			this->peruna_death->Location = System::Drawing::Point(129, 89);
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
			this->mana_potion_number->Location = System::Drawing::Point(148, 207);
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
			this->health_potion_number->Location = System::Drawing::Point(59, 207);
			this->health_potion_number->Name = L"health_potion_number";
			this->health_potion_number->Size = System::Drawing::Size(24, 15);
			this->health_potion_number->TabIndex = 103;
			this->health_potion_number->Text = L"x 0";
			// 
			// poison_buff_number
			// 
			this->poison_buff_number->AutoSize = true;
			this->poison_buff_number->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->poison_buff_number->ForeColor = System::Drawing::SystemColors::Info;
			this->poison_buff_number->Location = System::Drawing::Point(232, 207);
			this->poison_buff_number->Name = L"poison_buff_number";
			this->poison_buff_number->Size = System::Drawing::Size(24, 15);
			this->poison_buff_number->TabIndex = 103;
			this->poison_buff_number->Text = L"x 0";
			// 
			// mana
			// 
			this->mana->AutoSize = true;
			this->mana->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->mana->ForeColor = System::Drawing::SystemColors::Info;
			this->mana->Location = System::Drawing::Point(112, 175);
			this->mana->Name = L"mana";
			this->mana->Size = System::Drawing::Size(35, 15);
			this->mana->TabIndex = 103;
			this->mana->Text = L"Mana";
			// 
			// powerup_buff_number
			// 
			this->powerup_buff_number->AutoSize = true;
			this->powerup_buff_number->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->powerup_buff_number->ForeColor = System::Drawing::SystemColors::Info;
			this->powerup_buff_number->Location = System::Drawing::Point(324, 207);
			this->powerup_buff_number->Name = L"powerup_buff_number";
			this->powerup_buff_number->Size = System::Drawing::Size(24, 15);
			this->powerup_buff_number->TabIndex = 103;
			this->powerup_buff_number->Text = L"x 0";
			// 
			// apprentice_staff
			// 
			this->apprentice_staff->AutoSize = true;
			this->apprentice_staff->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->apprentice_staff->ForeColor = System::Drawing::SystemColors::Info;
			this->apprentice_staff->Location = System::Drawing::Point(22, 89);
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
			this->health->Location = System::Drawing::Point(22, 175);
			this->health->Name = L"health";
			this->health->Size = System::Drawing::Size(40, 15);
			this->health->TabIndex = 103;
			this->health->Text = L"Health";
			// 
			// poison_buff
			// 
			this->poison_buff->AutoSize = true;
			this->poison_buff->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->poison_buff->ForeColor = System::Drawing::SystemColors::Info;
			this->poison_buff->Location = System::Drawing::Point(196, 175);
			this->poison_buff->Name = L"poison_buff";
			this->poison_buff->Size = System::Drawing::Size(40, 15);
			this->poison_buff->TabIndex = 103;
			this->poison_buff->Text = L"Poison";
			// 
			// powerup_buff
			// 
			this->powerup_buff->AutoSize = true;
			this->powerup_buff->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->powerup_buff->ForeColor = System::Drawing::SystemColors::Info;
			this->powerup_buff->Location = System::Drawing::Point(288, 175);
			this->powerup_buff->Name = L"powerup_buff";
			this->powerup_buff->Size = System::Drawing::Size(55, 15);
			this->powerup_buff->TabIndex = 103;
			this->powerup_buff->Text = L"Power Up";
			// 
			// magic_abilites
			// 
			this->magic_abilites->AutoSize = true;
			this->magic_abilites->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->magic_abilites->ForeColor = System::Drawing::SystemColors::Info;
			this->magic_abilites->Location = System::Drawing::Point(275, 236);
			this->magic_abilites->Name = L"magic_abilites";
			this->magic_abilites->Size = System::Drawing::Size(86, 15);
			this->magic_abilites->TabIndex = 102;
			this->magic_abilites->Text = L"Magic Abilities";
			// 
			// multiplier_label
			// 
			this->multiplier_label->AutoSize = true;
			this->multiplier_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->multiplier_label->ForeColor = System::Drawing::SystemColors::Info;
			this->multiplier_label->Location = System::Drawing::Point(10, 3);
			this->multiplier_label->Name = L"multiplier_label";
			this->multiplier_label->Size = System::Drawing::Size(108, 15);
			this->multiplier_label->TabIndex = 101;
			this->multiplier_label->Text = L"Weapon Multipliers";
			// 
			// potion_label
			// 
			this->potion_label->AutoSize = true;
			this->potion_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->potion_label->ForeColor = System::Drawing::SystemColors::Info;
			this->potion_label->Location = System::Drawing::Point(10, 160);
			this->potion_label->Name = L"potion_label";
			this->potion_label->Size = System::Drawing::Size(44, 15);
			this->potion_label->TabIndex = 101;
			this->potion_label->Text = L"Potions";
			// 
			// melee_abilites
			// 
			this->melee_abilites->AutoSize = true;
			this->melee_abilites->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->melee_abilites->ForeColor = System::Drawing::SystemColors::Info;
			this->melee_abilites->Location = System::Drawing::Point(10, 236);
			this->melee_abilites->Name = L"melee_abilites";
			this->melee_abilites->Size = System::Drawing::Size(85, 15);
			this->melee_abilites->TabIndex = 101;
			this->melee_abilites->Text = L"Melee Abilities";
			// 
			// inventory
			// 
			this->inventory->BackColor = System::Drawing::Color::Transparent;
			this->inventory->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"inventory.BackgroundImage")));
			this->inventory->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->inventory->Cursor = System::Windows::Forms::Cursors::Hand;
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
			this->menu->Cursor = System::Windows::Forms::Cursors::Hand;
			this->menu->FlatAppearance->BorderSize = 0;
			this->menu->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->menu->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->menu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->menu->Location = System::Drawing::Point(485, 687);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(98, 28);
			this->menu->TabIndex = 100;
			this->menu->UseVisualStyleBackColor = false;
			this->menu->Click += gcnew System::EventHandler(this, &ApprenticeTrial::menu_Click);
			// 
			// inventory_label
			// 
			this->inventory_label->BackColor = System::Drawing::Color::Transparent;
			this->inventory_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->inventory_label->Location = System::Drawing::Point(488, 7);
			this->inventory_label->Name = L"inventory_label";
			this->inventory_label->Size = System::Drawing::Size(237, 48);
			this->inventory_label->TabIndex = 101;
			this->inventory_label->Text = L"Open your inventory";
			this->inventory_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->inventory_label->UseCompatibleTextRendering = true;
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
			this->Controls->Add(this->inventory_panel);
			this->Controls->Add(this->menu);
			this->Controls->Add(this->inventory_label);
			this->Controls->Add(this->status);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1024, 768);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(1024, 766);
			this->Name = L"ApprenticeTrial";
			this->Text = L"The Apprentice\'s Trial";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->poison_potion))->EndInit();
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->powerup_potion))->EndInit();
			this->load_screen->ResumeLayout(false);
			this->start_screen->ResumeLayout(false);
			this->start_screen->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->apprentice_image))->EndInit();
			this->inventory_panel->ResumeLayout(false);
			this->inventory_panel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

#pragma region Main Game Functions

private: System::Void ApprenticeTrial::loadGame(){
				 rGen = gcnew Random();

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

				 items = gcnew array<Item^>{				 
					 gcnew Item(dbGraphics, apprentice_sword_buff),
					 gcnew Item(dbGraphics, apprentice_staff_buff),
					 gcnew Item(dbGraphics, pig_slaughter_buff),
					 gcnew Item(dbGraphics, destroyer_buff),
					 gcnew Item(dbGraphics, cocoons_bane_buff),
					 gcnew Item(dbGraphics, ultimate_fury_buff),					 
					 gcnew Item(dbGraphics, peruna_death_buff),
					 gcnew Item(dbGraphics, brutal_staff_buff),
					 gcnew Item(dbGraphics, staff_of_magi_buff),
					 gcnew Item(dbGraphics, health_potion),
					 gcnew Item(dbGraphics, mana_potion),
					 gcnew Item(dbGraphics, poison_potion),
					 gcnew Item(dbGraphics, powerup_potion)
				 };

				 gameHasLoaded = false;

				 game_loading->Enabled = true;
				 
				 myThread = gcnew System::Threading::Thread( gcnew System::Threading::ThreadStart( this, &ApprenticeTrial::ThreadFunction ) );
				 myThread->IsBackground = true;
				 myThread->Start();

				 game_clock->Enabled = true;

				 pig_slaughter_buff->Visible = false;
				 destroyer_buff->Visible = false;
				 cocoons_bane_buff->Visible = false;
				 ultimate_fury_buff->Visible = false;
				 peruna_death_buff->Visible = false;
				 brutal_staff_buff->Visible = false;
				 staff_of_magi_buff->Visible = false;
				 greater_wand->Visible = false;
				 whirlwind->Visible = false;
				 lesser_ice->Visible = false;
				 greater_ice->Visible = false;
				 electric_storm->Visible = false;

				 use_melee_ability->Image = clearImage;
				 use_melee_ability->Enabled = false;
				 use_magic_ability->Image = clearImage;
				 use_magic_ability->Enabled = false;
				 melee_multiplier->Image = clearImage;
				 melee_multiplier->Enabled = false;
				 magic_multiplier->Image = clearImage;
				 magic_multiplier->Enabled = false;
				 use_potion_1->Enabled = false;
				 use_potion_2->Enabled = false;				 
				 				 			 
				 back->Visible = false;
				 help_howtoplay->Visible = false;
				 help_inventory->Visible = false;
				 help_hud->Visible = false;
				 help_back->Visible = false;
				 start_screen->Visible = false;
				 
				 Focus();
		 }

private: System::Void game_Clock_Tick(System::Object^  sender, System::EventArgs^  e) {

				 if(gameHasLoaded)
				 {
					 if(gManager->isPlayerTurn() && gameStarted)
					 {
						 //Cursor = Cursors::WaitCursor;

						 String^ charUpper = gManager->getEnemyInPlayName()->Substring(0,1)->ToUpper();
						 String^ enemyTurnText = gManager->getEnemyInPlayName()->Substring(1) + "'s turn";

						 status->Text = charUpper + enemyTurnText; 
					 }						 
					 else
					 {

						 //Cursor = Cursors::Default;

						 String^ playerTurnText = "Player's turn";						 
						 						 						 
						 status->Text = playerTurnText;
					 }

					 if(gManager->isGameOver())
					 {
						 game_clock->Enabled = false;
						 resume_game->Visible = false;
						 load_screen->Visible = true;
						 start_screen->Visible = true;
					 }	 

					 if(gManager->isEnemyDead() == false && player->isGeneratedWeapon() == false)
					 {
						 gameStarted = false;

						 player->setGeneratedWeapon(true);

						 Item^ newItem = generateItemWeapon(2, 9);

						 if(newItem != nullptr)
						 {
							 newItem->showInventoryItem();

							 gManager->addPotion(newItem);	
						 }						 					
					 }

					 if(gManager->isEnemyHit() && gManager->isEnemyDead() == true)
					 {
						 gManager->addPotion(generateItemPotion(9, 13));						
					 }
					 

					 gManager->Update();				 

					 gManager->Draw();

					 //
					 // Make Buffer Visible 
					 //
					 formCanvas->DrawImage(dbBitmap, ClientRectangle);
				 }
			 }

private: System::Void game_Loading_Tick(System::Object^  sender, System::EventArgs^  e) {
				 
				 if(gameHasLoaded)
				 {
					 load_screen->Visible = false;
					 game_loading->Enabled = false;
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
					ClientRectangle.Height - (srcRectangle.Height + 50),
					srcRectangle,				
					GraphicsUnit::Pixel
				 );

				 loadingCanvas->DrawImage(loadingBitmap, ClientRectangle);
			 }

#pragma endregion

#pragma region Game Loading Functions
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
					//myThread->Sleep(1000);

					gameHasLoaded = true;

					myThread->Abort();
			 }	
#pragma endregion

#pragma region Item Generation Functions

private: Item^ ApprenticeTrial::generateItem(int min, int max) {
				switch(rGen->Next(min, max))
				{
					case 0:  return gcnew Item(dbGraphics, apprentice_sword_buff);
					case 1:  return gcnew Item(dbGraphics, apprentice_staff_buff);
					case 2:  return gcnew Item(dbGraphics, pig_slaughter_buff);
					case 3:  return gcnew Item(dbGraphics, destroyer_buff);
					case 4:  return gcnew Item(dbGraphics, cocoons_bane_buff);
					case 5:  return gcnew Item(dbGraphics, ultimate_fury_buff);					
					case 6:  return gcnew Item(dbGraphics, peruna_death_buff);
					case 7:  return gcnew Item(dbGraphics, brutal_staff_buff);
					case 8:  return gcnew Item(dbGraphics, staff_of_magi_buff);
					case 9:  return gcnew Item(dbGraphics, health_potion);
					case 10: return gcnew Item(dbGraphics, mana_potion);
					case 11: return gcnew Item(dbGraphics, poison_potion);
					case 12: return gcnew Item(dbGraphics, powerup_potion);
				}				
			 }

private: Item^ ApprenticeTrial::generateItemWeapon(int min, int max) {
			    // Randomly generates a abilitybuff
				// when the enemy dies and limit on 
				// how many weapons are spawned
				Item^ item;

				if(spawned > 1 && gManager->getEnemyHealth() <= 0) 	// spawn limit, if enemy dies
				{
					spawned = 0;
				
					item = generateItem(min, max);					// add generated item for return
				}

				spawned++;	

				return item;
			 }
private: Item^ ApprenticeTrial::generateItemPotion(int min, int max) {
				// Returns a randomly generated potion
				// with a probablity and limit on 
				// if the potion is spawned
				Item^ item;

				if(spawned > 3 && rGen->Next(10) == 0)	// spawn limit, generation probablity
				{
					spawned = 0; 
				
					item = generateItem(min, max);		// add generated item for return
				}

				spawned++;	

				return item;
			 }

#pragma endregion

#pragma region Player Executes ability

private: System::Void ability_Click(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 
				 // Flag that the game has started
				 gameStarted = true;
				 
				 //Gets object clicked by player
				 PictureBox^ ability = safe_cast<PictureBox^>(sender);

				 if(ability->Tag != nullptr)
				 {
					 int availableMana = gManager->getAvailableMana();	
					 int abilityCost = (ability->Name == "use_melee_ability") ? int::Parse(ability->AccessibleName) : int::Parse(ability->AccessibleDescription);
					 EState playerAbility = safe_cast<EState>(int::Parse(ability->Tag->ToString()));

					 // If available to click execute the following
					 if(abilityCost < availableMana || playerAbility == HEAL)	
					 {
						 if(ability->Image != clearImage && player->isAttacking() == false)
						 {					 
							 Execute_Ability(ability);
							 Execute_Click_Hud_Item(ability, e);					 
						 }
					 }
				 }					 
			 }	

private: System::Void Execute_Ability(PictureBox^ ability) {
				 	
				 EState playerAbility = safe_cast<EState>(int::Parse(ability->Tag->ToString()));

				 //
				 int availableMana = gManager->getAvailableMana();
				 
				 int abilityCost = (ability->Name == "use_melee_ability") ? int::Parse(ability->AccessibleName) : int::Parse(ability->AccessibleDescription);

				 // Tracks ability clicked by player
				 if(gManager->isEnemyTurn() && playerAbility == HEAL)
				 {
					 gManager->setPlayerPotion(ability->AccessibleName->ToString());
					 ability->Image = clearImage;
					 ability->Enabled = false;				 					 
				 }

				 if(abilityCost < availableMana || playerAbility == HEAL)
						selectedAbility = playerAbility;
			 }

private: System::Void Execute_Click_Hud_Item(PictureBox^ ability, System::Windows::Forms::MouseEventArgs^  e) {

				 switch ( e->Button )
				 {
					case ::MouseButtons::Left:
						if(gManager->isEnemyTurn())
							playerAttack(ability);								
					   break;
					case ::MouseButtons::Right:
						addPotionBackToInventory(ability);
						resetSlot(ability);
					   break;
					default:
					   break;
				 }
			 }

private: System::Void ApprenticeTrial::resetSlot(PictureBox^ ability){
				// Reset slot to default
				ability->AccessibleDescription = "0";
				ability->AccessibleName = "0";
				ability->Tag = "0";
				ability->Image = clearImage;
				ability->Enabled = false;
			}

private: System::Void ApprenticeTrial::addPotionBackToInventory(PictureBox^ ability){
				// Adds the potion back to inventory
				if(ability->AccessibleName == "health")
					gManager->setHealthPotions(addPotion(gManager->getHealthPotions()));
				if(ability->AccessibleName == "mana")
					gManager->setManaPotions(addPotion(gManager->getManaPotions()));
				if(ability->AccessibleName == "poison")
					gManager->setPoisonPotions(addPotion(gManager->getPoisonPotions()));
				if(ability->AccessibleName == "powerup")
					gManager->setPowerupPotions(addPotion(gManager->getPowerupPotions()));
		     }

private: int ApprenticeTrial::addPotion(int potion) {

			 potion++;
				 
			 return potion;
		 }

private: int ApprenticeTrial::removePotion(int potion) {

			 potion--;
				 
			 if(potion < 0) potion = 0;

			 return potion;
		 }

private: System::Void ApprenticeTrial::playerAttack(PictureBox^ ability){
				if(ability->AccessibleName != "health" &&
				   ability->AccessibleName != "mana" &&
				   ability->AccessibleName != "poison" &&
				   ability->AccessibleName != "powerup")
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

#pragma endregion

#pragma region Menu Button Events

private: System::Void resume_Click(System::Object^  sender, System::EventArgs^  e) {
			 game_clock->Enabled = true;
			 load_screen->Visible = false;
			 start_screen->Visible = false;
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

			 //
			 // Start game
			 //
			 loadGame();			 			 
		 }

private: System::Void help_Click(System::Object^  sender, System::EventArgs^  e) {
			 //load_screen->Visible = false;
			 help_back->Visible = false;
			 help_howtoplay->Visible = true;
			 help_inventory->Visible = true;
			 help_hud->Visible = true;
			 back->Visible = true;
			 start_screen->Visible = false;
			 //help_screen->Visible = true;
		 }

private: System::Void back_Click(System::Object^  sender, System::EventArgs^  e) {
			 //load_screen->Visible = false;
			 //help_screen->Visible = false;
			 start_screen->Visible = true;			 
		 }

private: System::Void quit_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
		 }

private: System::Void help_inventory_Click(System::Object^  sender, System::EventArgs^  e) {
			 load_screen->BackgroundImage = Image::FromFile("help_inventory.png");
			 
			 help_back->Visible = true;
			 help_howtoplay->Visible = false;
			 help_inventory->Visible = false;
			 help_hud->Visible = false;
			 back->Visible = false;
			 load_screen->Refresh();
		 }
private: System::Void help_hud_Click(System::Object^  sender, System::EventArgs^  e) {
			 load_screen->BackgroundImage = Image::FromFile("help_hud.png");
			 
			 help_back->Visible = true;
			 help_howtoplay->Visible = false;
			 help_inventory->Visible = false;
			 help_hud->Visible = false;
			 back->Visible = false;
			 load_screen->Refresh();
		 }
private: System::Void help_back_Click(System::Object^  sender, System::EventArgs^  e) {
			 load_screen->BackgroundImage = Image::FromFile("help.png");
			 
			 help_back->Visible = false;
			 help_howtoplay->Visible = true;
			 help_inventory->Visible = true;
			 help_hud->Visible = true;
			 back->Visible = true;
			 load_screen->Refresh();
		 }
private: System::Void help_howtoplay_Click(System::Object^  sender, System::EventArgs^  e) {
			 load_screen->BackgroundImage = Image::FromFile("help_howtoplay.png");
			 
			 help_back->Visible = true;
			 help_howtoplay->Visible = false;
			 help_inventory->Visible = false;
			 help_hud->Visible = false;
			 back->Visible = false;
			 load_screen->Refresh();
		 }

#pragma endregion

#pragma region Hud Tooltip Generation

private: System::Void ApprenticeTrial::setToolTips() {

			 ability_info->SetToolTip(melee_multiplier, "Melee\tx" + melee_multiplier->AccessibleDescription + "\nMagic\tx" + melee_multiplier->AccessibleName);
			 ability_info->SetToolTip(magic_multiplier, "Melee\tx" + magic_multiplier->AccessibleDescription + "\nMagic\tx" + magic_multiplier->AccessibleName);
			 
			 int availableMana = gManager->getAvailableMana();				 
			 int meleeAbilityCost = int::Parse(use_melee_ability->AccessibleName);
			 int magicAbilityCost = int::Parse(use_magic_ability->AccessibleDescription);

			 if(meleeAbilityCost > availableMana)
			 {
				ability_info->SetToolTip(use_melee_ability, "NOT ENOUGH MANA");
			 }
			 else
			 {
				ability_info->SetToolTip(use_melee_ability, "Damage\t" + generateMeleeStats() + "\nMana\t" + use_melee_ability->AccessibleName);
			 }

			 if(magicAbilityCost > availableMana)
			 {
				 ability_info->SetToolTip(use_magic_ability, "NOT ENOUGH MANA");
			 }
			 else
			 {
				ability_info->SetToolTip(use_magic_ability, "Damage\t" + generateMagicStats() + "\nMana\t" + use_magic_ability->AccessibleDescription);
			 }
		 }

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

private: System::Void ability_MouseHover(System::Object^  sender, System::EventArgs^  e) {
			 setToolTips();
		 }

#pragma endregion

#pragma region Inventory Events

private: System::Void melee_Buff_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 PictureBox^ ability = safe_cast<PictureBox^>(sender);
			 melee_multiplier->AccessibleDescription = ability->AccessibleDescription;
			 melee_multiplier->AccessibleName = ability->AccessibleName;
			 melee_multiplier->Image = ability->Image;
			 melee_multiplier->Tag = ability->Tag;
			 melee_multiplier->Enabled = true;

			 if(ability->Name == "apprentice_sword_buff")
			 {
				 apprentice_sword_new->AccessibleName = "selected";
				 apprentice_sword_new->Visible = false;
			 }
			 
			 if(ability->Name == "pig_slaughter_buff")
			 {
				 pig_slaughter_new->AccessibleName = "selected";
				 pig_slaughter_new->Visible = false;
			 }
				

			 if(ability->Name == "destroyer_buff")
			 {
				 destroyer_new->AccessibleName = "selected";
				 destroyer_new->Visible = false;
			 }
				

			 if(ability->Name == "cocoons_bane_buff")
			 {
				 cocoons_bane_new->AccessibleName = "selected";
				 cocoons_bane_new->Visible = false;
			 }
				

			 if(ability->Name == "ultimate_fury_buff")
			 {
				 ultimate_fury_new->AccessibleName = "selected";
				 ultimate_fury_new->Visible = false;
			 }
				

			 newAvailable = false;			 
		 }

private: System::Void magic_Buff_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 PictureBox^ ability = safe_cast<PictureBox^>(sender);
			 magic_multiplier->AccessibleDescription = ability->AccessibleDescription;
			 magic_multiplier->AccessibleName = ability->AccessibleName;
			 magic_multiplier->Image = ability->Image;
			 magic_multiplier->Tag = ability->Tag;
			 magic_multiplier->Enabled = true;

			 if(ability->Name == "apprentice_staff_buff")
			 {
				 apprentice_staff_new->AccessibleName = "selected";
				 apprentice_staff_new->Visible = false;
			 }

			 if(ability->Name == "peruna_death_buff")
			 {
				 peruna_death_new->AccessibleName = "selected";
				 peruna_death_new->Visible = false;
			 }
				

			 if(ability->Name == "brutal_staff_buff")
			 {
				 brutal_staff_new->AccessibleName = "selected";
				 brutal_staff_new->Visible = false;
			 }
				

			 if(ability->Name == "staff_of_magi_buff")
			 {
				 staff_of_magi_new->AccessibleName = "selected";
				 staff_of_magi_new->Visible = false;
			 }
				
		 }

private: System::Void potion_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 PictureBox^ ability = safe_cast<PictureBox^>(sender);	

			 int healthPotions = gManager->getHealthPotions();
			 int manaPotions = gManager->getManaPotions();
			 int poisonPotions = gManager->getPoisonPotions();
			 int powerupPotions = gManager->getPowerupPotions();

			 if(healthPotions > 0 || manaPotions > 0 || poisonPotions > 0 || powerupPotions > 0)
			 {
				 if(use_potion_1->Image == clearImage)
				 {
					 use_potion_1->AccessibleDescription = ability->AccessibleDescription;
					 use_potion_1->AccessibleName = ability->AccessibleName;
					 use_potion_1->Image = ability->Image;
					 use_potion_1->Tag = ability->Tag;
					 use_potion_1->Enabled = true;
				 }
				 else
				 {
					 use_potion_2->AccessibleDescription = ability->AccessibleDescription;
					 use_potion_2->AccessibleName = ability->AccessibleName;
					 use_potion_2->Image = ability->Image;
					 use_potion_2->Tag = ability->Tag;
					 use_potion_2->Enabled = true;
				 }
			 }	

			 if(ability->Name == "health_potion")
				 gManager->setHealthPotions(removePotion(gManager->getHealthPotions()));
			 if(ability->Name == "mana_potion")
				 gManager->setManaPotions(removePotion(gManager->getManaPotions()));
			 if(ability->Name == "poison_potion")
				 gManager->setPoisonPotions(removePotion(gManager->getPoisonPotions()));
			 if(ability->Name == "powerup_potion")
				 gManager->setPowerupPotions(removePotion(gManager->getPowerupPotions()));

			 healthPotions = gManager->getHealthPotions();
			 manaPotions = gManager->getManaPotions();
			 poisonPotions = gManager->getPoisonPotions();
			 powerupPotions = gManager->getPowerupPotions();

			 health_potion_number->Text = "x " + healthPotions.ToString();
			 mana_potion_number->Text = "x " + manaPotions.ToString();
			 poison_buff_number->Text = "x " + poisonPotions.ToString();
			 powerup_buff_number->Text = "x " + powerupPotions.ToString();

			 		 
		 }

private: System::Void melee_Ability_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 PictureBox^ ability = safe_cast<PictureBox^>(sender);
			 use_melee_ability->AccessibleDescription = ability->AccessibleDescription;
			 use_melee_ability->AccessibleName = ability->AccessibleName;
			 use_melee_ability->Image = ability->Image;
			 use_melee_ability->Tag = ability->Tag;
			 use_melee_ability->Enabled = true;

			 if(ability->Name == "lesser_wand")
			 {
				 lesser_wand_new->AccessibleName = "selected";
				 lesser_wand_new->Visible = false;
			 }
				 

			 if(ability->Name == "greater_wand")
			 {
				 greater_wand_new->AccessibleName = "selected";
				 greater_wand_new->Visible = false;
			 }
				 
			 if(ability->Name == "whirlwind")
			 {
				 whirlwind_new->AccessibleName = "selected";
				 whirlwind_new->Visible = false;
			 }
				 

		 }

private: System::Void magic_Ability_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 PictureBox^ ability = safe_cast<PictureBox^>(sender);
			 use_magic_ability->AccessibleDescription = ability->AccessibleDescription;
			 use_magic_ability->AccessibleName = ability->AccessibleName;
			 use_magic_ability->Image = ability->Image;
			 use_magic_ability->Tag = ability->Tag;
			 use_magic_ability->Enabled = true;

			 if(ability->Name == "lesser_ice")
			 {
				 lesser_ice_new->AccessibleName = "selected";
				 lesser_ice_new->Visible = false;
			 }
				 

			 if(ability->Name == "greater_ice")
			 {
				 lesser_ice_new->AccessibleName = "selected";
				 greater_ice_new->Visible = false;
			 }
				 

			 if(ability->Name == "electric_storm")
			 {
				 lesser_ice_new->AccessibleName = "selected";
				 electric_storm_new->Visible = false;
			 }
				 
		 }

#pragma endregion

#pragma region Hud Buttons

private: System::Void inventory_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 if(apprentice_sword_new->AccessibleName == nullptr && apprentice_sword_buff->Visible)
				apprentice_sword_new->Visible = true; 

			 if(apprentice_staff_new->AccessibleName == nullptr && apprentice_staff_buff->Visible)
				apprentice_staff_new->Visible = true; 

			 if(pig_slaughter_new->AccessibleName == nullptr && pig_slaughter_buff->Visible)
				pig_slaughter_new->Visible = true; 

			 if(destroyer_new->AccessibleName == nullptr && destroyer_buff->Visible)
				destroyer_new->Visible = true;

			 if(cocoons_bane_new->AccessibleName == nullptr && cocoons_bane_buff->Visible)
				cocoons_bane_new->Visible = true;

			 if(ultimate_fury_new->AccessibleName == nullptr && ultimate_fury_buff->Visible)
				ultimate_fury_new->Visible = true;
			 
			 if(peruna_death_new->AccessibleName == nullptr && peruna_death_buff->Visible)
				peruna_death_new->Visible = true;

			 if(brutal_staff_new->AccessibleName == nullptr && brutal_staff_buff->Visible)
				brutal_staff_new->Visible = true;

			 if(staff_of_magi_new->AccessibleName == nullptr && staff_of_magi_buff->Visible)
				staff_of_magi_new->Visible = true;
			 
			 

			 if(player->getBattleScreen() == 0)
			 {
				 if(lesser_wand_new->AccessibleName == nullptr) 
					 lesser_wand_new->Visible = true;
				 lesser_wand->Visible = true;						 
			 }

			 if(player->getBattleScreen() == 1)
			 {
				 inventory_label->Text = "New abilities available";
				 
				 
				 if(greater_wand_new->AccessibleName == nullptr) 
					 greater_wand_new->Visible = true;
				 greater_wand->Visible = true;				 
				 
				 if(lesser_ice_new->AccessibleName == nullptr)
					 lesser_ice_new->Visible = true;
				 lesser_ice->Visible = true;				 
			 }

			 if(player->getBattleScreen() == 2)
			 {
				 inventory_label->Text = "New abilities available";
				 
				 if(whirlwind_new->AccessibleName == nullptr)
					 whirlwind_new->Visible = true;				 
				 whirlwind->Visible = true;
				 
				 if(greater_wand_new->AccessibleName == nullptr)
					 greater_ice_new->Visible = true;
				 greater_ice->Visible = true;
			 }

			 if(player->getBattleScreen() == 3)
			 {
				 inventory_label->Text = "New abilities available";

				 if(greater_wand_new->AccessibleName == nullptr)
					 electric_storm_new->Visible = true;

				 electric_storm->Visible = true;
			 }
			 
			 health_potion_number->Text = "x " + gManager->getHealthPotions().ToString();
			 mana_potion_number->Text = "x " + gManager->getManaPotions().ToString();
			 poison_buff_number->Text = "x " + gManager->getPoisonPotions().ToString();
			 powerup_buff_number->Text = "x " + gManager->getPowerupPotions().ToString();
			 
			 if(inventory_label->Text == "Inventory Open")
				inventory_label->Visible = !inventory_label->Visible;

			 inventory_label->Text = "Inventory Open";
			 
			 inventory_panel->Visible = !inventory_panel->Visible;
			 gManager->showInventory(inventory_panel->Visible);			 
		 }

private: System::Void menu_Click(System::Object^  sender, System::EventArgs^  e) {
			 game_clock->Enabled = false;
			 resume_game->Visible = true;
			 load_screen->Visible = true;
			 start_screen->Visible = true;
		 }

			 
		 
#pragma endregion

#pragma region Redundant

private: System::Windows::Forms::Cursor^ ApprenticeTrial::getAbilityCursor(PictureBox^ ability) {
				 // Gets the image from the picturebox 
				 Bitmap^ bmp = safe_cast<Bitmap^>(ability->Image);

				 // Gets the image data from bitmap  
				 IntPtr ptr = bmp->GetHicon();
					 
				 // Returns the new cursor
				 return gcnew System::Windows::Forms::Cursor(ptr);
			 }

private: System::Void inventory_Item_Click(System::Object^  sender, System::EventArgs^  e) {
			 PictureBox^ ability = safe_cast<PictureBox^>(sender);
			 Cursor = getAbilityCursor(ability);
		 }

private: System::Void multiplier_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 PictureBox^ ability = safe_cast<PictureBox^>(sender);
			 ability->Image = clearImage;
		 }


#pragma endregion

};
}

