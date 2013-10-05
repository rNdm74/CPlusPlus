#pragma once

#include "GameManager.h"


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
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
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
	private: System::Windows::Forms::Timer^  clock;

	private: System::ComponentModel::IContainer^  components;

	private: System::Windows::Forms::PictureBox^  background;
	private: System::Windows::Forms::PictureBox^  coinshud;	
	private: System::Windows::Forms::PictureBox^  lives;

	private: System::Windows::Forms::PictureBox^  blueflag;
	private: System::Windows::Forms::PictureBox^  orangeflag;
	private: System::Windows::Forms::PictureBox^  yellowflag;
	private: System::Windows::Forms::PictureBox^  greenflag;

    private: System::Windows::Forms::Label^  gameover_label;
	private: System::Windows::Forms::Label^  highscorelabel;
	private: System::Windows::Forms::Label^  highscore;
	private: System::Windows::Forms::Label^  scorelabel;
	private: System::Windows::Forms::Label^  score;
	private: System::Windows::Forms::Label^  coins;

	private: System::Windows::Forms::Button^  play_button;
	private: System::Windows::Forms::Button^  restart_button;
	private: System::Windows::Forms::Button^  quit_button;	


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		GameManager^ gManager;


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
			this->gameover_label = (gcnew System::Windows::Forms::Label());
			this->restart_button = (gcnew System::Windows::Forms::Button());
			this->quit_button = (gcnew System::Windows::Forms::Button());
			this->coinshud = (gcnew System::Windows::Forms::PictureBox());
			this->blueflag = (gcnew System::Windows::Forms::PictureBox());
			this->lives = (gcnew System::Windows::Forms::PictureBox());
			this->highscorelabel = (gcnew System::Windows::Forms::Label());
			this->scorelabel = (gcnew System::Windows::Forms::Label());
			this->coins = (gcnew System::Windows::Forms::Label());
			this->score = (gcnew System::Windows::Forms::Label());
			this->highscore = (gcnew System::Windows::Forms::Label());
			this->orangeflag = (gcnew System::Windows::Forms::PictureBox());
			this->yellowflag = (gcnew System::Windows::Forms::PictureBox());
			this->greenflag = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->background))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->coinshud))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->blueflag))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lives))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->orangeflag))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->yellowflag))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->greenflag))->BeginInit();
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
			// gameover_label
			// 
			this->gameover_label->AutoSize = true;
			this->gameover_label->BackColor = System::Drawing::Color::Transparent;
			this->gameover_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gameover_label->ForeColor = System::Drawing::Color::OrangeRed;
			this->gameover_label->Location = System::Drawing::Point(399, 246);
			this->gameover_label->Name = L"gameover_label";
			this->gameover_label->Size = System::Drawing::Size(229, 52);
			this->gameover_label->TabIndex = 3;
			this->gameover_label->Text = L"GAMEOVER";
			this->gameover_label->Visible = false;
			// 
			// restart_button
			// 
			this->restart_button->BackColor = System::Drawing::Color::Transparent;
			this->restart_button->FlatAppearance->BorderSize = 0;
			this->restart_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->restart_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->restart_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->restart_button->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->restart_button->ForeColor = System::Drawing::Color::White;
			this->restart_button->Location = System::Drawing::Point(26, 645);
			this->restart_button->Name = L"restart_button";
			this->restart_button->Size = System::Drawing::Size(199, 51);
			this->restart_button->TabIndex = 10;
			this->restart_button->Text = L"RESTART";
			this->restart_button->UseVisualStyleBackColor = false;
			this->restart_button->Visible = false;
			this->restart_button->MouseLeave += gcnew System::EventHandler(this, &FranticAlien::button_MouseLeave);
			this->restart_button->Click += gcnew System::EventHandler(this, &FranticAlien::restart_button_Click);
			this->restart_button->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FranticAlien::button_MouseDown);
			this->restart_button->MouseEnter += gcnew System::EventHandler(this, &FranticAlien::button_MouseEnter);
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
			this->blueflag->Location = System::Drawing::Point(299, 1);
			this->blueflag->Name = L"blueflag";
			this->blueflag->Size = System::Drawing::Size(35, 35);
			this->blueflag->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->blueflag->TabIndex = 13;
			this->blueflag->TabStop = false;
			this->blueflag->Visible = false;
			// 
			// lives
			// 
			this->lives->BackColor = System::Drawing::Color::Transparent;
			this->lives->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"lives.Image")));
			this->lives->Location = System::Drawing::Point(463, 1);
			this->lives->Name = L"lives";
			this->lives->Size = System::Drawing::Size(35, 35);
			this->lives->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->lives->TabIndex = 14;
			this->lives->TabStop = false;
			// 
			// highscorelabel
			// 
			this->highscorelabel->AutoSize = true;
			this->highscorelabel->BackColor = System::Drawing::Color::Transparent;
			this->highscorelabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->highscorelabel->ForeColor = System::Drawing::Color::Firebrick;
			this->highscorelabel->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->highscorelabel->Location = System::Drawing::Point(695, -7);
			this->highscorelabel->Name = L"highscorelabel";
			this->highscorelabel->Size = System::Drawing::Size(189, 49);
			this->highscorelabel->TabIndex = 15;
			this->highscorelabel->Text = L"HSCORE -";
			// 
			// scorelabel
			// 
			this->scorelabel->AutoSize = true;
			this->scorelabel->BackColor = System::Drawing::Color::Transparent;
			this->scorelabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->scorelabel->ForeColor = System::Drawing::Color::Pink;
			this->scorelabel->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->scorelabel->Location = System::Drawing::Point(0, -7);
			this->scorelabel->Name = L"scorelabel";
			this->scorelabel->Size = System::Drawing::Size(162, 49);
			this->scorelabel->TabIndex = 16;
			this->scorelabel->Text = L"SCORE -";
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
			this->score->Location = System::Drawing::Point(145, -7);
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
			this->highscore->ForeColor = System::Drawing::Color::Firebrick;
			this->highscore->Location = System::Drawing::Point(867, -7);
			this->highscore->Name = L"highscore";
			this->highscore->Size = System::Drawing::Size(148, 49);
			this->highscore->TabIndex = 21;
			this->highscore->Text = L"000000";
			// 
			// orangeflag
			// 
			this->orangeflag->BackColor = System::Drawing::Color::Transparent;
			this->orangeflag->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"orangeflag.Image")));
			this->orangeflag->Location = System::Drawing::Point(381, 1);
			this->orangeflag->Name = L"orangeflag";
			this->orangeflag->Size = System::Drawing::Size(35, 35);
			this->orangeflag->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->orangeflag->TabIndex = 22;
			this->orangeflag->TabStop = false;
			this->orangeflag->Visible = false;
			// 
			// yellowflag
			// 
			this->yellowflag->BackColor = System::Drawing::Color::Transparent;
			this->yellowflag->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"yellowflag.Image")));
			this->yellowflag->Location = System::Drawing::Point(422, 1);
			this->yellowflag->Name = L"yellowflag";
			this->yellowflag->Size = System::Drawing::Size(35, 35);
			this->yellowflag->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->yellowflag->TabIndex = 23;
			this->yellowflag->TabStop = false;
			this->yellowflag->Visible = false;
			// 
			// greenflag
			// 
			this->greenflag->BackColor = System::Drawing::Color::Transparent;
			this->greenflag->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"greenflag.Image")));
			this->greenflag->Location = System::Drawing::Point(340, 1);
			this->greenflag->Name = L"greenflag";
			this->greenflag->Size = System::Drawing::Size(35, 35);
			this->greenflag->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->greenflag->TabIndex = 24;
			this->greenflag->TabStop = false;
			this->greenflag->Visible = false;
			// 
			// FranticAlien
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1018, 740);
			this->Controls->Add(this->coinshud);
			this->Controls->Add(this->greenflag);
			this->Controls->Add(this->yellowflag);
			this->Controls->Add(this->orangeflag);
			this->Controls->Add(this->score);
			this->Controls->Add(this->highscore);
			this->Controls->Add(this->coins);
			this->Controls->Add(this->scorelabel);
			this->Controls->Add(this->highscorelabel);
			this->Controls->Add(this->lives);
			this->Controls->Add(this->blueflag);
			this->Controls->Add(this->gameover_label);
			this->Controls->Add(this->quit_button);
			this->Controls->Add(this->restart_button);
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
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FranticAlien::FranticAlien_KeyUp);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FranticAlien::FranticAlien_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->background))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->coinshud))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->blueflag))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lives))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->orangeflag))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->yellowflag))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->greenflag))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region Form Controls
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>			 
		private: System::Void clock_Tick(System::Object^  sender, System::EventArgs^  e) {
			// 
			// Game Clock Cycle, checks is the game is over updates game then draws to window
			//
			
			gManager->updateGame();
			gManager->drawGame();

			checkGameState();
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
		private: System::Void quit_button_Click(System::Object^  sender, System::EventArgs^  e) {
			Application::Exit();
		}
		private: System::Void restart_button_Click(System::Object^  sender, System::EventArgs^  e) {
			createGame();
		}
		private: System::Void play_button_Click(System::Object^  sender, System::EventArgs^  e) {
			createGame();				 
		}
		// 
		// Game Over
		//
		private: System::Void checkGameState()
		{
			if(gManager->isGameOver())
			{
				clock->Enabled = !clock->Enabled;
				background->Visible = true;
				gameover_label->Visible = true;
				restart_button->Visible = true;
				quit_button->Visible = true;
			}
			else
			{
				updateHud();
			}
			
			if(gManager->isLevelOver())
			{
				clock->Enabled = !clock->Enabled;

				int scoreCount = int::Parse(score->Text);
				int coinCount = int::Parse(coins->Text);

				for(coinCount; coinCount >= 0; coinCount--)
				{
					scoreCount += 150;

					score->Text = String::Format("{0:000000}", scoreCount);
					score->Refresh();
					coins->Text = String::Format("{0:000}", coinCount);
					coins->Refresh();

					System::Threading::Thread::Sleep(20);
				}

				gManager->setScore(scoreCount);
				
				clock->Enabled = !clock->Enabled;
			}
		}
		// 
		// Create New Game
		//
		private: System::Void createGame()
		{
			 delete gManager;

			 background->Visible = false;			 
			 play_button->Visible = false;
			 gameover_label->Visible = false;
			 restart_button->Visible = false;
			 quit_button->Visible = false;	

			 gManager = gcnew GameManager(CreateGraphics(), ClientRectangle);

			 clock->Enabled = !clock->Enabled;

			 Focus();
		}
		// 
		// Create New Game
		//
		private: System::Void updateHud()
		{
			 highscore->Text = String::Format("{0:000000}", gManager->getHighScore());
			 score->Text = String::Format("{0:000000}", gManager->getScore());
			 coins->Text = String::Format("{0:000}", gManager->getCoins());

			 lives->Image = Image::FromFile("Images/lives" + gManager->getLives() + ".png");

			 int flag = gManager->getFlag();

			 if(flag == ORANGE_FLAG)
				 orangeflag->Visible = true;
 
			 if(flag == BLUE_FLAG)
				 blueflag->Visible = true;

			 if(flag == YELLOW_FLAG)
				 yellowflag->Visible = true;

			 if(flag == GREEN_FLAG)
				 greenflag->Visible = true;

			 if(flag == 0)
			 {
				 orangeflag->Visible = false;
				 blueflag->Visible = false;
				 yellowflag->Visible = false;
				 greenflag->Visible = false;
			 }
		}
#pragma endregion
};
}

