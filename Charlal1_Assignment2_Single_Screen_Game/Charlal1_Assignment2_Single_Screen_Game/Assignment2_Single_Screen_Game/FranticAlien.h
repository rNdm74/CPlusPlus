#pragma once

#include "GameManager.h"
#include "Constants.h"

namespace Assignment2_Single_Screen_Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FranticAlien
	///
	/// NOTE:	 Frantic alien is a single screen game where the player controls
	///			 a alien where collecting flags and coins while evading other aliens. 
	///			 The goal is to collect all the flags and return to the exit tile 
	///			 before loosing all the lives allocated. 
	///
	/// </summary>
	public ref class FranticAlien : public System::Windows::Forms::Form
	{
	public:
		FranticAlien(void)
		{
			InitializeComponent();			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FranticAlien()
		{
			if (components)
			{
				delete components;
			}
		}
#pragma region Form Components

	private: System::Windows::Forms::Timer^  clock;

	private: System::ComponentModel::IContainer^  components;

	private: System::Windows::Forms::PictureBox^  background;
	private: System::Windows::Forms::PictureBox^  coinshud;	
	private: System::Windows::Forms::PictureBox^  lives;
	private: System::Windows::Forms::PictureBox^  levelhud;

	private: System::Windows::Forms::PictureBox^  blueflag;
	private: System::Windows::Forms::PictureBox^  orangeflag;
	private: System::Windows::Forms::PictureBox^  yellowflag;
	private: System::Windows::Forms::PictureBox^  greenflag;

	private: System::Windows::Forms::Label^  highscore;
	private: System::Windows::Forms::Label^  level;
	private: System::Windows::Forms::Label^  score;
	private: System::Windows::Forms::Label^  coins;

	private: System::Windows::Forms::Button^  play_button;
	private: System::Windows::Forms::Button^  how_to_play;
	private: System::Windows::Forms::Button^  quit_button;	

 #pragma endregion


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		GameManager^ gManager;
		SoundManager^ sManager;		
		bool clicked;
		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FranticAlien::typeid));
			this->clock = (gcnew System::Windows::Forms::Timer(this->components));
			this->play_button = (gcnew System::Windows::Forms::Button());
			this->background = (gcnew System::Windows::Forms::PictureBox());
			this->quit_button = (gcnew System::Windows::Forms::Button());
			this->coinshud = (gcnew System::Windows::Forms::PictureBox());
			this->blueflag = (gcnew System::Windows::Forms::PictureBox());
			this->lives = (gcnew System::Windows::Forms::PictureBox());
			this->coins = (gcnew System::Windows::Forms::Label());
			this->score = (gcnew System::Windows::Forms::Label());
			this->highscore = (gcnew System::Windows::Forms::Label());
			this->orangeflag = (gcnew System::Windows::Forms::PictureBox());
			this->yellowflag = (gcnew System::Windows::Forms::PictureBox());
			this->greenflag = (gcnew System::Windows::Forms::PictureBox());
			this->level = (gcnew System::Windows::Forms::Label());
			this->levelhud = (gcnew System::Windows::Forms::PictureBox());
			this->how_to_play = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->background))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->coinshud))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->blueflag))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lives))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->orangeflag))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->yellowflag))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->greenflag))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->levelhud))->BeginInit();
			this->SuspendLayout();
			// 
			// clock
			// 
			this->clock->Interval = 1;
			this->clock->Tick += gcnew System::EventHandler(this, &FranticAlien::clock_Tick);
			// 
			// play_button
			// 
			this->play_button->BackColor = System::Drawing::Color::Transparent;
			this->play_button->FlatAppearance->BorderSize = 0;
			this->play_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->play_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->play_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->play_button->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->play_button->ForeColor = System::Drawing::Color::White;
			this->play_button->Location = System::Drawing::Point(26, 645);
			this->play_button->Name = L"play_button";
			this->play_button->Size = System::Drawing::Size(180, 51);
			this->play_button->TabIndex = 0;
			this->play_button->Text = L"PLAY";
			this->play_button->UseCompatibleTextRendering = true;
			this->play_button->UseVisualStyleBackColor = false;
			this->play_button->MouseLeave += gcnew System::EventHandler(this, &FranticAlien::button_MouseLeave);
			this->play_button->Click += gcnew System::EventHandler(this, &FranticAlien::play_button_Click);
			this->play_button->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FranticAlien::button_MouseDown);
			this->play_button->MouseEnter += gcnew System::EventHandler(this, &FranticAlien::button_MouseEnter);
			// 
			// background
			// 
			this->background->BackColor = System::Drawing::Color::Transparent;
			this->background->Dock = System::Windows::Forms::DockStyle::Fill;
			this->background->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"background.Image")));
			this->background->Location = System::Drawing::Point(0, 0);
			this->background->Name = L"background";
			this->background->Size = System::Drawing::Size(1018, 740);
			this->background->TabIndex = 1;
			this->background->TabStop = false;
			// 
			// quit_button
			// 
			this->quit_button->BackColor = System::Drawing::Color::Transparent;
			this->quit_button->FlatAppearance->BorderSize = 0;
			this->quit_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->quit_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->quit_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->quit_button->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->quit_button->ForeColor = System::Drawing::Color::White;
			this->quit_button->Location = System::Drawing::Point(816, 645);
			this->quit_button->Name = L"quit_button";
			this->quit_button->Size = System::Drawing::Size(180, 51);
			this->quit_button->TabIndex = 11;
			this->quit_button->Text = L"QUIT";
			this->quit_button->UseCompatibleTextRendering = true;
			this->quit_button->UseVisualStyleBackColor = false;
			this->quit_button->MouseLeave += gcnew System::EventHandler(this, &FranticAlien::button_MouseLeave);
			this->quit_button->Click += gcnew System::EventHandler(this, &FranticAlien::quit_button_Click);
			this->quit_button->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FranticAlien::button_MouseDown);
			this->quit_button->MouseEnter += gcnew System::EventHandler(this, &FranticAlien::button_MouseEnter);
			// 
			// coinshud
			// 
			this->coinshud->BackColor = System::Drawing::Color::Transparent;
			this->coinshud->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"coinshud.Image")));
			this->coinshud->Location = System::Drawing::Point(548, 1);
			this->coinshud->Name = L"coinshud";
			this->coinshud->Size = System::Drawing::Size(35, 35);
			this->coinshud->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->coinshud->TabIndex = 12;
			this->coinshud->TabStop = false;
			// 
			// blueflag
			// 
			this->blueflag->BackColor = System::Drawing::Color::Transparent;
			this->blueflag->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"blueflag.Image")));
			this->blueflag->Location = System::Drawing::Point(205, 1);
			this->blueflag->Name = L"blueflag";
			this->blueflag->Size = System::Drawing::Size(35, 35);
			this->blueflag->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->blueflag->TabIndex = 13;
			this->blueflag->TabStop = false;
			// 
			// lives
			// 
			this->lives->BackColor = System::Drawing::Color::Transparent;
			this->lives->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"lives.Image")));
			this->lives->Location = System::Drawing::Point(434, 1);
			this->lives->Name = L"lives";
			this->lives->Size = System::Drawing::Size(35, 35);
			this->lives->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->lives->TabIndex = 14;
			this->lives->TabStop = false;
			// 
			// coins
			// 
			this->coins->AutoSize = true;
			this->coins->BackColor = System::Drawing::Color::Transparent;
			this->coins->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->coins->ForeColor = System::Drawing::Color::Gold;
			this->coins->Location = System::Drawing::Point(580, -7);
			this->coins->Name = L"coins";
			this->coins->Size = System::Drawing::Size(85, 49);
			this->coins->TabIndex = 17;
			this->coins->Text = L"000";
			this->coins->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// score
			// 
			this->score->AutoSize = true;
			this->score->BackColor = System::Drawing::Color::Transparent;
			this->score->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->score->ForeColor = System::Drawing::Color::Pink;
			this->score->Location = System::Drawing::Point(17, -7);
			this->score->Name = L"score";
			this->score->Size = System::Drawing::Size(148, 49);
			this->score->TabIndex = 20;
			this->score->Text = L"000000";
			this->score->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// highscore
			// 
			this->highscore->AutoSize = true;
			this->highscore->BackColor = System::Drawing::Color::Transparent;
			this->highscore->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->highscore->ForeColor = System::Drawing::Color::White;
			this->highscore->Location = System::Drawing::Point(858, -7);
			this->highscore->Name = L"highscore";
			this->highscore->Size = System::Drawing::Size(148, 49);
			this->highscore->TabIndex = 21;
			this->highscore->Text = L"000000";
			// 
			// orangeflag
			// 
			this->orangeflag->BackColor = System::Drawing::Color::Transparent;
			this->orangeflag->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"orangeflag.Image")));
			this->orangeflag->Location = System::Drawing::Point(287, 1);
			this->orangeflag->Name = L"orangeflag";
			this->orangeflag->Size = System::Drawing::Size(35, 35);
			this->orangeflag->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->orangeflag->TabIndex = 22;
			this->orangeflag->TabStop = false;
			// 
			// yellowflag
			// 
			this->yellowflag->BackColor = System::Drawing::Color::Transparent;
			this->yellowflag->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"yellowflag.Image")));
			this->yellowflag->Location = System::Drawing::Point(328, 1);
			this->yellowflag->Name = L"yellowflag";
			this->yellowflag->Size = System::Drawing::Size(35, 35);
			this->yellowflag->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->yellowflag->TabIndex = 23;
			this->yellowflag->TabStop = false;
			// 
			// greenflag
			// 
			this->greenflag->BackColor = System::Drawing::Color::Transparent;
			this->greenflag->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"greenflag.Image")));
			this->greenflag->Location = System::Drawing::Point(246, 1);
			this->greenflag->Name = L"greenflag";
			this->greenflag->Size = System::Drawing::Size(35, 35);
			this->greenflag->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->greenflag->TabIndex = 24;
			this->greenflag->TabStop = false;
			// 
			// level
			// 
			this->level->AutoSize = true;
			this->level->BackColor = System::Drawing::Color::Transparent;
			this->level->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->level->ForeColor = System::Drawing::Color::Peru;
			this->level->Location = System::Drawing::Point(777, -7);
			this->level->Name = L"level";
			this->level->Size = System::Drawing::Size(64, 49);
			this->level->TabIndex = 25;
			this->level->Text = L"00";
			// 
			// levelhud
			// 
			this->levelhud->BackColor = System::Drawing::Color::Transparent;
			this->levelhud->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"levelhud.Image")));
			this->levelhud->Location = System::Drawing::Point(736, 0);
			this->levelhud->Name = L"levelhud";
			this->levelhud->Size = System::Drawing::Size(35, 35);
			this->levelhud->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->levelhud->TabIndex = 27;
			this->levelhud->TabStop = false;
			// 
			// how_to_play
			// 
			this->how_to_play->BackColor = System::Drawing::Color::Transparent;
			this->how_to_play->FlatAppearance->BorderSize = 0;
			this->how_to_play->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->how_to_play->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->how_to_play->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->how_to_play->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->how_to_play->ForeColor = System::Drawing::Color::White;
			this->how_to_play->Location = System::Drawing::Point(164, 645);
			this->how_to_play->Name = L"how_to_play";
			this->how_to_play->Size = System::Drawing::Size(117, 51);
			this->how_to_play->TabIndex = 28;
			this->how_to_play->Text = L"\?";
			this->how_to_play->UseCompatibleTextRendering = true;
			this->how_to_play->UseVisualStyleBackColor = false;
			this->how_to_play->MouseLeave += gcnew System::EventHandler(this, &FranticAlien::button_MouseLeave);
			this->how_to_play->Click += gcnew System::EventHandler(this, &FranticAlien::how_to_play_Click);
			this->how_to_play->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FranticAlien::button_MouseDown);
			this->how_to_play->MouseEnter += gcnew System::EventHandler(this, &FranticAlien::button_MouseEnter);
			// 
			// FranticAlien
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1018, 740);
			this->Controls->Add(this->how_to_play);
			this->Controls->Add(this->levelhud);
			this->Controls->Add(this->level);
			this->Controls->Add(this->coinshud);
			this->Controls->Add(this->greenflag);
			this->Controls->Add(this->yellowflag);
			this->Controls->Add(this->orangeflag);
			this->Controls->Add(this->score);
			this->Controls->Add(this->highscore);
			this->Controls->Add(this->coins);
			this->Controls->Add(this->lives);
			this->Controls->Add(this->blueflag);
			this->Controls->Add(this->quit_button);
			this->Controls->Add(this->play_button);
			this->Controls->Add(this->background);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1024, 769);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(1024, 769);
			this->Name = L"FranticAlien";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Frantic Alien";
			this->Load += gcnew System::EventHandler(this, &FranticAlien::FranticAlien_Load);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FranticAlien::FranticAlien_KeyUp);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FranticAlien::FranticAlien_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->background))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->coinshud))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->blueflag))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lives))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->orangeflag))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->yellowflag))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->greenflag))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->levelhud))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region Form Controls
		/// <summary>
		/// Controls events 
		/// </summary>	
		private: System::Void FranticAlien_Load(System::Object^  sender, System::EventArgs^  e) {
			sManager = gcnew SoundManager();
		}
		// 
		// Game Clock Cycle, checks is the game is over updates game then draws to window
		//
		private: System::Void clock_Tick(System::Object^  sender, System::EventArgs^  e) {						
			gManager->updateGame();
			gManager->drawGame();
			checkGameState();
			updateGameHud();
		}
		// 
		// Key Up and Key Down Handlers
		//
		private: System::Void FranticAlien_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {			
			gManager->keyDown(e->KeyCode);
		}			 
		private: System::Void FranticAlien_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			gManager->keyUp(e->KeyCode);
		}
		// 
		// Mouse Handlers
		//
		private: System::Void button_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			Button^ button = safe_cast<Button^>(sender); 
			button->ForeColor = Color::White;
		}
		private: System::Void button_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			Button^ button = safe_cast<Button^>(sender);
			button->ForeColor = Color::White;
		}
		private: System::Void button_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			Button^ button = safe_cast<Button^>(sender);
			button->ForeColor = Color::DeepSkyBlue;
		}
		// 
		// Button Handlers
		//
		private: System::Void how_to_play_Click(System::Object^  sender, System::EventArgs^  e) {

			background->Image = Image::FromFile((clicked) ? MAINSCREEN : HOW_TO_PLAY);
			
			clicked = !clicked;
		}
		private: System::Void quit_button_Click(System::Object^  sender, System::EventArgs^  e) {
			Application::Exit();
		}
		private: System::Void play_button_Click(System::Object^  sender, System::EventArgs^  e) {
			playNewGame();				 
		}
#pragma endregion

#pragma region Methods
		// 
		// Checks if a level is complete or if the game is over
		//
		private: System::Void checkGameState()
		{
			if(gManager->isLevelWin()) 
				updateGameScore();

			if(gManager->isLevelOver())
				showLevelOverScreen();
		}
		// 
		// Checks if a level is complete or if the game is over
		//
		private: System::Void toggleFormControls()
		{			
			background->Visible = !background->Visible;							// Hides picturebox
			how_to_play->Visible = !how_to_play->Visible;						// Hides button
			play_button->Visible = !play_button->Visible;						// Hides button
			quit_button->Visible = !quit_button->Visible;						// Hides button
		}
		// 
		// 
		//
		private: System::Void playNewGame()
		{
			 delete gManager;													// Cleanup

			 toggleFormControls();

			 gManager = gcnew GameManager(CreateGraphics(), ClientRectangle, sManager);	// Creates a new game

			 clock->Enabled = !clock->Enabled;									// Starts the timer

			 Focus();															// Gives the form focus			 
		}
		//
		// Stops the game shows displays the menu
		//
		private: System::Void showLevelOverScreen()
		{
			 toggleFormControls();

			 gManager->setFlag(GAME_OVER);
			
			 gManager->setLives(FULL_HEARTS);			 

			 clock->Enabled = !clock->Enabled;									// Stops the timer
		}
		//
		// Takes the collected coins that adds them to the players score
		//
		private: System::Void updateGameScore()
		{			 
			 clock->Enabled = !clock->Enabled;									// Stops the timer

			 int currentScore = int::Parse(score->Text);						// Gets current score
			 int coinsCollected = int::Parse(coins->Text);						// Gets collected coins

			 for(coinsCollected; coinsCollected >= 0; coinsCollected--)			// Loops through collected coins
			 {				
				sManager->collectCoin->Play();									// Play collected coins sound here

				currentScore += BONUS_COINS;									// Appends to currentScore

				score->Text = String::Format("{0:000000}", currentScore);		// Changes score label with formatting
				score->Refresh();												// Shows changes										
				coins->Text = String::Format("{0:000}", coinsCollected);		// Changes coin label with formatting
				coins->Refresh();												// Shows changes

				System::Threading::Thread::Sleep(DELAY);						// Sleeps so player can see (effect)
			 }

			 gManager->setScore(currentScore);									// Makes score changes permanent 

			 clock->Enabled = !clock->Enabled;									// Re-enables timer
		}
		// 
		// Updates all hud information when the game is being played
		//
		private: System::Void updateGameHud()
		{
			 // Updates labels: Highscore, Score, Coins with applied formating
			 highscore->Text = String::Format("{0:000000}", gManager->getHighScore());
			 score->Text = String::Format("{0:000000}", gManager->getScore());
			 coins->Text = String::Format("{0:000}", gManager->getCoins());
			 level->Text = String::Format("{0:00}", gManager->getLevel());

			 // Changes heart image to show if player has lost a life
			 if(gManager->getLives() >= 0)
				lives->Image = Image::FromFile("Images/lives" + gManager->getLives() + ".png");

			 // Shows which flag has been collected by player
			 int flag = gManager->getFlag();									// Gets the flag number

			 // Tests which flag and makes it visible in the hud
			 if(flag == ORANGE_FLAG)
				 orangeflag->Visible = true; 
			 if(flag == BLUE_FLAG)
				 blueflag->Visible = true;
			 if(flag == YELLOW_FLAG)
				 yellowflag->Visible = true;
			 if(flag == GREEN_FLAG)
				 greenflag->Visible = true;

			 // Flag reset value ZERO 
			 // Used if level is complete or game is restarted
			 // Hides all flags
			 if(flag == 0)														
			 {
				 orangeflag->Visible = false;
				 blueflag->Visible = false;
				 yellowflag->Visible = false;
				 greenflag->Visible = false;
			 }

			 if(flag == GAME_OVER)														
			 {
				 orangeflag->Visible = true;
				 blueflag->Visible = true;
				 yellowflag->Visible = true;
				 greenflag->Visible = true;
			 }
		}
 #pragma endregion
};
}

