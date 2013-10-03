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
	private: System::Windows::Forms::PictureBox^  player;
	private: System::Windows::Forms::PictureBox^  alien1;
	private: System::Windows::Forms::PictureBox^  alien2;
	private: System::Windows::Forms::PictureBox^  logo;
	
	private: System::Windows::Forms::Button^  play_button;

    private: System::Windows::Forms::Label^  gameover_label;	
	private: System::Windows::Forms::Label^  high_score_label;
	private: System::Windows::Forms::Label^  highscore;
	private: System::Windows::Forms::Label^  score_label;
	private: System::Windows::Forms::Label^  score;

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
			this->high_score_label = (gcnew System::Windows::Forms::Label());
			this->score_label = (gcnew System::Windows::Forms::Label());
			this->gameover_label = (gcnew System::Windows::Forms::Label());
			this->score = (gcnew System::Windows::Forms::Label());
			this->highscore = (gcnew System::Windows::Forms::Label());
			this->restart_button = (gcnew System::Windows::Forms::Button());
			this->quit_button = (gcnew System::Windows::Forms::Button());
			this->player = (gcnew System::Windows::Forms::PictureBox());
			this->alien1 = (gcnew System::Windows::Forms::PictureBox());
			this->alien2 = (gcnew System::Windows::Forms::PictureBox());
			this->logo = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->background))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->player))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->alien1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->alien2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logo))->BeginInit();
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
			this->play_button->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 24, System::Drawing::FontStyle::Bold));
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
			this->background->Size = System::Drawing::Size(1008, 730);
			this->background->TabIndex = 1;
			this->background->TabStop = false;
			// 
			// high_score_label
			// 
			this->high_score_label->AutoSize = true;
			this->high_score_label->BackColor = System::Drawing::Color::Transparent;
			this->high_score_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 24, System::Drawing::FontStyle::Bold));
			this->high_score_label->ForeColor = System::Drawing::Color::White;
			this->high_score_label->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->high_score_label->Location = System::Drawing::Point(363, 316);
			this->high_score_label->Name = L"high_score_label";
			this->high_score_label->Size = System::Drawing::Size(245, 45);
			this->high_score_label->TabIndex = 4;
			this->high_score_label->Text = L"HIGH SCORE:";
			this->high_score_label->Visible = false;
			// 
			// score_label
			// 
			this->score_label->AutoSize = true;
			this->score_label->BackColor = System::Drawing::Color::Transparent;
			this->score_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 24, System::Drawing::FontStyle::Bold));
			this->score_label->ForeColor = System::Drawing::Color::White;
			this->score_label->Location = System::Drawing::Point(334, 380);
			this->score_label->Name = L"score_label";
			this->score_label->Size = System::Drawing::Size(274, 45);
			this->score_label->TabIndex = 5;
			this->score_label->Text = L"PLAYER SCORE:";
			this->score_label->Visible = false;
			// 
			// gameover_label
			// 
			this->gameover_label->AutoSize = true;
			this->gameover_label->BackColor = System::Drawing::Color::Transparent;
			this->gameover_label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 24, System::Drawing::FontStyle::Bold));
			this->gameover_label->ForeColor = System::Drawing::Color::White;
			this->gameover_label->Location = System::Drawing::Point(407, 238);
			this->gameover_label->Name = L"gameover_label";
			this->gameover_label->Size = System::Drawing::Size(201, 45);
			this->gameover_label->TabIndex = 3;
			this->gameover_label->Text = L"GAMEOVER";
			this->gameover_label->Visible = false;
			// 
			// score
			// 
			this->score->AutoSize = true;
			this->score->BackColor = System::Drawing::Color::Transparent;
			this->score->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 24, System::Drawing::FontStyle::Bold));
			this->score->ForeColor = System::Drawing::Color::White;
			this->score->Location = System::Drawing::Point(614, 380);
			this->score->Name = L"score";
			this->score->Size = System::Drawing::Size(40, 45);
			this->score->TabIndex = 8;
			this->score->Text = L"0";
			this->score->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->score->Visible = false;
			// 
			// highscore
			// 
			this->highscore->AutoSize = true;
			this->highscore->BackColor = System::Drawing::Color::Transparent;
			this->highscore->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 24, System::Drawing::FontStyle::Bold));
			this->highscore->ForeColor = System::Drawing::Color::White;
			this->highscore->Location = System::Drawing::Point(614, 316);
			this->highscore->Name = L"highscore";
			this->highscore->Size = System::Drawing::Size(40, 45);
			this->highscore->TabIndex = 9;
			this->highscore->Text = L"0";
			this->highscore->Visible = false;
			// 
			// restart_button
			// 
			this->restart_button->BackColor = System::Drawing::Color::Transparent;
			this->restart_button->FlatAppearance->BorderSize = 0;
			this->restart_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->restart_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->restart_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->restart_button->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 24, System::Drawing::FontStyle::Bold));
			this->restart_button->ForeColor = System::Drawing::Color::White;
			this->restart_button->Location = System::Drawing::Point(26, 645);
			this->restart_button->Name = L"restart_button";
			this->restart_button->Size = System::Drawing::Size(180, 51);
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
			this->quit_button->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 24, System::Drawing::FontStyle::Bold));
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
			// player
			// 
			this->player->BackColor = System::Drawing::Color::Transparent;
			this->player->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"player.Image")));
			this->player->Location = System::Drawing::Point(140, 478);
			this->player->Name = L"player";
			this->player->Size = System::Drawing::Size(66, 92);
			this->player->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->player->TabIndex = 12;
			this->player->TabStop = false;
			// 
			// alien1
			// 
			this->alien1->BackColor = System::Drawing::Color::Transparent;
			this->alien1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"alien1.Image")));
			this->alien1->Location = System::Drawing::Point(751, 478);
			this->alien1->Name = L"alien1";
			this->alien1->Size = System::Drawing::Size(66, 92);
			this->alien1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->alien1->TabIndex = 13;
			this->alien1->TabStop = false;
			// 
			// alien2
			// 
			this->alien2->BackColor = System::Drawing::Color::Transparent;
			this->alien2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"alien2.Image")));
			this->alien2->Location = System::Drawing::Point(832, 478);
			this->alien2->Name = L"alien2";
			this->alien2->Size = System::Drawing::Size(66, 92);
			this->alien2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->alien2->TabIndex = 14;
			this->alien2->TabStop = false;
			// 
			// logo
			// 
			this->logo->BackColor = System::Drawing::Color::Transparent;
			this->logo->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"logo.Image")));
			this->logo->Location = System::Drawing::Point(217, 286);
			this->logo->Name = L"logo";
			this->logo->Size = System::Drawing::Size(587, 109);
			this->logo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->logo->TabIndex = 15;
			this->logo->TabStop = false;
			// 
			// FranticAlien
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1008, 730);
			this->Controls->Add(this->gameover_label);
			this->Controls->Add(this->score);
			this->Controls->Add(this->score_label);
			this->Controls->Add(this->highscore);
			this->Controls->Add(this->high_score_label);
			this->Controls->Add(this->logo);
			this->Controls->Add(this->alien2);
			this->Controls->Add(this->alien1);
			this->Controls->Add(this->player);
			this->Controls->Add(this->quit_button);
			this->Controls->Add(this->restart_button);
			this->Controls->Add(this->play_button);
			this->Controls->Add(this->background);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FranticAlien";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Frantic Alien";
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FranticAlien::FranticAlien_KeyUp);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FranticAlien::FranticAlien_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->background))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->player))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->alien1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->alien2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logo))->EndInit();
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
			// FranticAlien
			//
			isGameOver(gManager->isGameOver());
			gManager->updateGame();
			gManager->drawGame();
		}
		// 
		// FranticAlien
		//
		private: System::Void FranticAlien_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {			
			gManager->keyDown(e->KeyCode);
		}			 
		private: System::Void FranticAlien_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			gManager->keyUp(e->KeyCode);
		}
		// 
		// FranticAlien
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
		// FranticAlien
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
		// FranticAlien
		//
		private: System::Void isGameOver(bool gameover)
		{
			if(gameover)
			{
				clock->Enabled = !clock->Enabled;

				background->Visible = gameover;
				player->Visible = gameover;
				alien1->Visible = gameover;
				alien2->Visible = gameover;

				gameover_label->Visible = gameover;
				restart_button->Visible = gameover;
				quit_button->Visible = gameover;						
				
				highscore->Text = gManager->getHighScore();
				high_score_label->Visible = gameover;
				highscore->Visible = gameover;
				
				score->Text = gManager->getScore();
				score_label->Visible = gameover;
				score->Visible = gameover;
			}
		}
		// 
		// FranticAlien
		//
		private: System::Void createGame()
		{
			 background->Visible = false;
			 logo->Visible = false;
			 player->Visible = false;
			 alien1->Visible = false;
			 alien2->Visible = false;

			 high_score_label->Visible = false;
			 highscore->Visible = false;
			
			 score_label->Visible = false;
			 score->Visible = false;
			 
			 play_button->Visible = false;
			 gameover_label->Visible = false;
			 restart_button->Visible = false;
			 quit_button->Visible = false;	

			 gManager = gcnew GameManager(CreateGraphics(), ClientRectangle);

			 clock->Enabled = !clock->Enabled;

			 Focus();
		}
#pragma endregion
};
}

