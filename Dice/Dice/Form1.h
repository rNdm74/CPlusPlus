#pragma once

enum Player
	{
		ONE,
		TWO,
	};

namespace Dice {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

#define WIN_CONDITION 100

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
	private: System::Windows::Forms::Button^  playerOneRoll;
	private: System::Windows::Forms::Button^  playerTwoRoll;
	private: System::Windows::Forms::PictureBox^  p1Dice1;
	private: System::Windows::Forms::PictureBox^  p1Dice2;
	private: System::Windows::Forms::PictureBox^  p1Dice3;
	private: System::Windows::Forms::PictureBox^  p1Dice4;
	private: System::Windows::Forms::PictureBox^  p1Dice5;
	private: System::Windows::Forms::PictureBox^  p1Dice6;
	private: System::Windows::Forms::PictureBox^  p2Dice1;
	private: System::Windows::Forms::PictureBox^  p2Dice2;
	private: System::Windows::Forms::PictureBox^  p2Dice3;
	private: System::Windows::Forms::PictureBox^  p2Dice4;
	private: System::Windows::Forms::PictureBox^  p2Dice5;
	private: System::Windows::Forms::PictureBox^  p2Dice6;
	protected: 

	protected: 
	private: System::Windows::Forms::Label^  playerOneScore;
	private: System::Windows::Forms::Label^  playerTwoScore;
	private: System::Windows::Forms::GroupBox^  gBoxPlayerOne;
	private: System::Windows::Forms::GroupBox^  gBoxPlayerTwo;


	private: System::Windows::Forms::GroupBox^  totals;
	private: System::Windows::Forms::Label^  runningTotalPlayer2Value;
	private: System::Windows::Forms::Label^  runningTotalPlayer1Value;
	private: System::Windows::Forms::Label^  runningTotalPlayer2;
	private: System::Windows::Forms::Label^  runningTotalPlayer1;
	private: System::Windows::Forms::Label^  title;

	private: array<Image^>^ dice;
	private: array<PictureBox^>^ playerOneDice;
	private: array<PictureBox^>^ playerTwoDice;

	private: Random^ rGen;
	
	private: int p1RunningScore;
	private: int p2RunningScore;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
		this->playerOneRoll = (gcnew System::Windows::Forms::Button());
		this->playerTwoRoll = (gcnew System::Windows::Forms::Button());
		this->p1Dice1 = (gcnew System::Windows::Forms::PictureBox());
		this->p1Dice2 = (gcnew System::Windows::Forms::PictureBox());
		this->p1Dice3 = (gcnew System::Windows::Forms::PictureBox());
		this->p1Dice4 = (gcnew System::Windows::Forms::PictureBox());
		this->p1Dice5 = (gcnew System::Windows::Forms::PictureBox());
		this->p2Dice1 = (gcnew System::Windows::Forms::PictureBox());
		this->p2Dice2 = (gcnew System::Windows::Forms::PictureBox());
		this->p2Dice3 = (gcnew System::Windows::Forms::PictureBox());
		this->p2Dice4 = (gcnew System::Windows::Forms::PictureBox());
		this->p2Dice5 = (gcnew System::Windows::Forms::PictureBox());
		this->playerOneScore = (gcnew System::Windows::Forms::Label());
		this->playerTwoScore = (gcnew System::Windows::Forms::Label());
		this->gBoxPlayerOne = (gcnew System::Windows::Forms::GroupBox());
		this->p1Dice6 = (gcnew System::Windows::Forms::PictureBox());
		this->gBoxPlayerTwo = (gcnew System::Windows::Forms::GroupBox());
		this->p2Dice6 = (gcnew System::Windows::Forms::PictureBox());
		this->totals = (gcnew System::Windows::Forms::GroupBox());
		this->runningTotalPlayer2Value = (gcnew System::Windows::Forms::Label());
		this->runningTotalPlayer1Value = (gcnew System::Windows::Forms::Label());
		this->runningTotalPlayer2 = (gcnew System::Windows::Forms::Label());
		this->runningTotalPlayer1 = (gcnew System::Windows::Forms::Label());
		this->title = (gcnew System::Windows::Forms::Label());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p1Dice1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p1Dice2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p1Dice3))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p1Dice4))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p1Dice5))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p2Dice1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p2Dice2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p2Dice3))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p2Dice4))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p2Dice5))->BeginInit();
		this->gBoxPlayerOne->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p1Dice6))->BeginInit();
		this->gBoxPlayerTwo->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p2Dice6))->BeginInit();
		this->totals->SuspendLayout();
		this->SuspendLayout();
		// 
		// playerOneRoll
		// 
		this->playerOneRoll->Location = System::Drawing::Point(17, 38);
		this->playerOneRoll->Name = L"playerOneRoll";
		this->playerOneRoll->Size = System::Drawing::Size(57, 100);
		this->playerOneRoll->TabIndex = 0;
		this->playerOneRoll->Text = L"ROLL";
		this->playerOneRoll->UseVisualStyleBackColor = true;
		this->playerOneRoll->Click += gcnew System::EventHandler(this, &Form1::playerOneRoll_Click);
		// 
		// playerTwoRoll
		// 
		this->playerTwoRoll->Location = System::Drawing::Point(17, 38);
		this->playerTwoRoll->Name = L"playerTwoRoll";
		this->playerTwoRoll->Size = System::Drawing::Size(57, 100);
		this->playerTwoRoll->TabIndex = 1;
		this->playerTwoRoll->Text = L"ROLL";
		this->playerTwoRoll->UseVisualStyleBackColor = true;
		this->playerTwoRoll->Click += gcnew System::EventHandler(this, &Form1::playerTwoRoll_Click);
		// 
		// p1Dice1
		// 
		this->p1Dice1->Location = System::Drawing::Point(80, 38);
		this->p1Dice1->Name = L"p1Dice1";
		this->p1Dice1->Size = System::Drawing::Size(100, 100);
		this->p1Dice1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->p1Dice1->TabIndex = 2;
		this->p1Dice1->TabStop = false;
		// 
		// p1Dice2
		// 
		this->p1Dice2->Location = System::Drawing::Point(186, 38);
		this->p1Dice2->Name = L"p1Dice2";
		this->p1Dice2->Size = System::Drawing::Size(100, 100);
		this->p1Dice2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->p1Dice2->TabIndex = 3;
		this->p1Dice2->TabStop = false;
		// 
		// p1Dice3
		// 
		this->p1Dice3->Location = System::Drawing::Point(292, 38);
		this->p1Dice3->Name = L"p1Dice3";
		this->p1Dice3->Size = System::Drawing::Size(100, 100);
		this->p1Dice3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->p1Dice3->TabIndex = 4;
		this->p1Dice3->TabStop = false;
		// 
		// p1Dice4
		// 
		this->p1Dice4->Location = System::Drawing::Point(398, 38);
		this->p1Dice4->Name = L"p1Dice4";
		this->p1Dice4->Size = System::Drawing::Size(100, 100);
		this->p1Dice4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->p1Dice4->TabIndex = 5;
		this->p1Dice4->TabStop = false;
		// 
		// p1Dice5
		// 
		this->p1Dice5->Location = System::Drawing::Point(504, 38);
		this->p1Dice5->Name = L"p1Dice5";
		this->p1Dice5->Size = System::Drawing::Size(100, 100);
		this->p1Dice5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->p1Dice5->TabIndex = 6;
		this->p1Dice5->TabStop = false;
		// 
		// p2Dice1
		// 
		this->p2Dice1->Location = System::Drawing::Point(80, 38);
		this->p2Dice1->Name = L"p2Dice1";
		this->p2Dice1->Size = System::Drawing::Size(100, 100);
		this->p2Dice1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->p2Dice1->TabIndex = 7;
		this->p2Dice1->TabStop = false;
		// 
		// p2Dice2
		// 
		this->p2Dice2->Location = System::Drawing::Point(186, 38);
		this->p2Dice2->Name = L"p2Dice2";
		this->p2Dice2->Size = System::Drawing::Size(100, 100);
		this->p2Dice2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->p2Dice2->TabIndex = 8;
		this->p2Dice2->TabStop = false;
		// 
		// p2Dice3
		// 
		this->p2Dice3->Location = System::Drawing::Point(292, 38);
		this->p2Dice3->Name = L"p2Dice3";
		this->p2Dice3->Size = System::Drawing::Size(100, 100);
		this->p2Dice3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->p2Dice3->TabIndex = 9;
		this->p2Dice3->TabStop = false;
		// 
		// p2Dice4
		// 
		this->p2Dice4->Location = System::Drawing::Point(398, 38);
		this->p2Dice4->Name = L"p2Dice4";
		this->p2Dice4->Size = System::Drawing::Size(100, 100);
		this->p2Dice4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->p2Dice4->TabIndex = 10;
		this->p2Dice4->TabStop = false;
		// 
		// p2Dice5
		// 
		this->p2Dice5->Location = System::Drawing::Point(504, 38);
		this->p2Dice5->Name = L"p2Dice5";
		this->p2Dice5->Size = System::Drawing::Size(100, 100);
		this->p2Dice5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->p2Dice5->TabIndex = 11;
		this->p2Dice5->TabStop = false;
		// 
		// playerOneScore
		// 
		this->playerOneScore->AutoSize = true;
		this->playerOneScore->BackColor = System::Drawing::Color::Transparent;
		this->playerOneScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->playerOneScore->Location = System::Drawing::Point(712, 64);
		this->playerOneScore->Name = L"playerOneScore";
		this->playerOneScore->Size = System::Drawing::Size(35, 37);
		this->playerOneScore->TabIndex = 12;
		this->playerOneScore->Text = L"0";
		// 
		// playerTwoScore
		// 
		this->playerTwoScore->AutoSize = true;
		this->playerTwoScore->BackColor = System::Drawing::Color::Transparent;
		this->playerTwoScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->playerTwoScore->Location = System::Drawing::Point(712, 64);
		this->playerTwoScore->Name = L"playerTwoScore";
		this->playerTwoScore->Size = System::Drawing::Size(35, 37);
		this->playerTwoScore->TabIndex = 13;
		this->playerTwoScore->Text = L"0";
		// 
		// gBoxPlayerOne
		// 
		this->gBoxPlayerOne->Controls->Add(this->p1Dice6);
		this->gBoxPlayerOne->Controls->Add(this->playerOneRoll);
		this->gBoxPlayerOne->Controls->Add(this->p1Dice1);
		this->gBoxPlayerOne->Controls->Add(this->playerOneScore);
		this->gBoxPlayerOne->Controls->Add(this->p1Dice2);
		this->gBoxPlayerOne->Controls->Add(this->p1Dice3);
		this->gBoxPlayerOne->Controls->Add(this->p1Dice4);
		this->gBoxPlayerOne->Controls->Add(this->p1Dice5);
		this->gBoxPlayerOne->Location = System::Drawing::Point(12, 63);
		this->gBoxPlayerOne->Name = L"gBoxPlayerOne";
		this->gBoxPlayerOne->Size = System::Drawing::Size(760, 168);
		this->gBoxPlayerOne->TabIndex = 14;
		this->gBoxPlayerOne->TabStop = false;
		this->gBoxPlayerOne->Text = L"PLAYER 1";
		// 
		// p1Dice6
		// 
		this->p1Dice6->Location = System::Drawing::Point(610, 38);
		this->p1Dice6->Name = L"p1Dice6";
		this->p1Dice6->Size = System::Drawing::Size(100, 100);
		this->p1Dice6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->p1Dice6->TabIndex = 13;
		this->p1Dice6->TabStop = false;
		// 
		// gBoxPlayerTwo
		// 
		this->gBoxPlayerTwo->Controls->Add(this->p2Dice6);
		this->gBoxPlayerTwo->Controls->Add(this->playerTwoRoll);
		this->gBoxPlayerTwo->Controls->Add(this->p2Dice1);
		this->gBoxPlayerTwo->Controls->Add(this->playerTwoScore);
		this->gBoxPlayerTwo->Controls->Add(this->p2Dice2);
		this->gBoxPlayerTwo->Controls->Add(this->p2Dice5);
		this->gBoxPlayerTwo->Controls->Add(this->p2Dice3);
		this->gBoxPlayerTwo->Controls->Add(this->p2Dice4);
		this->gBoxPlayerTwo->Location = System::Drawing::Point(12, 237);
		this->gBoxPlayerTwo->Name = L"gBoxPlayerTwo";
		this->gBoxPlayerTwo->Size = System::Drawing::Size(760, 168);
		this->gBoxPlayerTwo->TabIndex = 15;
		this->gBoxPlayerTwo->TabStop = false;
		this->gBoxPlayerTwo->Text = L"PLAYER 2";
		// 
		// p2Dice6
		// 
		this->p2Dice6->Location = System::Drawing::Point(610, 38);
		this->p2Dice6->Name = L"p2Dice6";
		this->p2Dice6->Size = System::Drawing::Size(100, 100);
		this->p2Dice6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->p2Dice6->TabIndex = 14;
		this->p2Dice6->TabStop = false;
		// 
		// totals
		// 
		this->totals->Controls->Add(this->runningTotalPlayer2Value);
		this->totals->Controls->Add(this->runningTotalPlayer1Value);
		this->totals->Controls->Add(this->runningTotalPlayer2);
		this->totals->Controls->Add(this->runningTotalPlayer1);
		this->totals->Location = System::Drawing::Point(12, 411);
		this->totals->Name = L"totals";
		this->totals->Size = System::Drawing::Size(760, 138);
		this->totals->TabIndex = 16;
		this->totals->TabStop = false;
		this->totals->Text = L"TOTALS";
		// 
		// runningTotalPlayer2Value
		// 
		this->runningTotalPlayer2Value->AutoSize = true;
		this->runningTotalPlayer2Value->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		this->runningTotalPlayer2Value->Location = System::Drawing::Point(508, 81);
		this->runningTotalPlayer2Value->Name = L"runningTotalPlayer2Value";
		this->runningTotalPlayer2Value->Size = System::Drawing::Size(29, 31);
		this->runningTotalPlayer2Value->TabIndex = 14;
		this->runningTotalPlayer2Value->Text = L"0";
		// 
		// runningTotalPlayer1Value
		// 
		this->runningTotalPlayer1Value->AutoSize = true;
		this->runningTotalPlayer1Value->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		this->runningTotalPlayer1Value->Location = System::Drawing::Point(508, 31);
		this->runningTotalPlayer1Value->Name = L"runningTotalPlayer1Value";
		this->runningTotalPlayer1Value->Size = System::Drawing::Size(29, 31);
		this->runningTotalPlayer1Value->TabIndex = 13;
		this->runningTotalPlayer1Value->Text = L"0";
		// 
		// runningTotalPlayer2
		// 
		this->runningTotalPlayer2->AutoSize = true;
		this->runningTotalPlayer2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		this->runningTotalPlayer2->Location = System::Drawing::Point(205, 81);
		this->runningTotalPlayer2->Name = L"runningTotalPlayer2";
		this->runningTotalPlayer2->Size = System::Drawing::Size(297, 31);
		this->runningTotalPlayer2->TabIndex = 1;
		this->runningTotalPlayer2->Text = L"Running Total Player 2:";
		// 
		// runningTotalPlayer1
		// 
		this->runningTotalPlayer1->AutoSize = true;
		this->runningTotalPlayer1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		this->runningTotalPlayer1->Location = System::Drawing::Point(205, 31);
		this->runningTotalPlayer1->Name = L"runningTotalPlayer1";
		this->runningTotalPlayer1->Size = System::Drawing::Size(297, 31);
		this->runningTotalPlayer1->TabIndex = 0;
		this->runningTotalPlayer1->Text = L"Running Total Player 1:";
		// 
		// title
		// 
		this->title->AutoSize = true;
		this->title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->title->Location = System::Drawing::Point(177, 18);
		this->title->Name = L"title";
		this->title->Size = System::Drawing::Size(434, 29);
		this->title->TabIndex = 17;
		this->title->Text = L"First player to make a score of 100 wins";
		// 
		// Form1
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::White;
		this->ClientSize = System::Drawing::Size(784, 562);
		this->Controls->Add(this->title);
		this->Controls->Add(this->totals);
		this->Controls->Add(this->gBoxPlayerTwo);
		this->Controls->Add(this->gBoxPlayerOne);
		this->DoubleBuffered = true;
		this->MaximumSize = System::Drawing::Size(800, 600);
		this->MinimumSize = System::Drawing::Size(800, 600);
		this->Name = L"Form1";
		this->ShowIcon = false;
		this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
		this->Text = L"Dice";
		this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p1Dice1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p1Dice2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p1Dice3))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p1Dice4))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p1Dice5))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p2Dice1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p2Dice2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p2Dice3))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p2Dice4))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p2Dice5))->EndInit();
		this->gBoxPlayerOne->ResumeLayout(false);
		this->gBoxPlayerOne->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p1Dice6))->EndInit();
		this->gBoxPlayerTwo->ResumeLayout(false);
		this->gBoxPlayerTwo->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->p2Dice6))->EndInit();
		this->totals->ResumeLayout(false);
		this->totals->PerformLayout();
		this->ResumeLayout(false);
		this->PerformLayout();

			}
#pragma endregion

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 playerOneDice = gcnew array<PictureBox^>
			 {
				 p1Dice1,
				 p1Dice2,
				 p1Dice3,
				 p1Dice4,
				 p1Dice5,
				 p1Dice6
			 };

			 playerTwoDice = gcnew array<PictureBox^>
			 {
				 p2Dice1,
				 p2Dice2,
				 p2Dice3,
				 p2Dice4,
				 p2Dice5,
				 p2Dice6
			 };

			 dice = gcnew array<Image^>(6);

			 for(int i = 0; i < dice->Length; i++)
			 {
				dice[i] = Image::FromFile((i+1) + ".png");

				playerOneDice[i]->Image = dice[i];
				playerTwoDice[i]->Image = dice[i];
			 }
			 
			 rGen = gcnew Random();
		 }

private: System::Void playerOneRoll_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(roll(Player::ONE, playerOneDice, playerOneScore, runningTotalPlayer1Value) >= WIN_CONDITION) 
				 MessageBox::Show("Player One Wins");
		 }

private: System::Void playerTwoRoll_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(roll(Player::TWO, playerTwoDice, playerTwoScore, runningTotalPlayer2Value) >= WIN_CONDITION)
				 MessageBox::Show("Player Two Wins");
		 }

private: int Form1::roll(Player player, array<PictureBox^>^ pBoxs, Label^ pScore, Label^ rScoreValue) {
			 int score = getScore(pBoxs);
		
			 pScore->Text = score.ToString();

			 rScoreValue->Text = getRunningScore(player, score).ToString();	

			 return int::Parse(rScoreValue->Text);
		 }

private: int Form1::getRunningScore(Player p, int score) {
			 switch(p)
			 {
				 case Player::ONE:
					 p1RunningScore += score;
					 return p1RunningScore;

				 default:
					 p2RunningScore += score;
					 return p2RunningScore; 
			 }
		 }

private: int Form1::getScore(array<PictureBox^>^ pBoxs) {
			 int score = 0;

			 for(int i = 0; i < pBoxs->Length; i++)
			 {
				int pick = rGen->Next(dice->Length);

				pBoxs[i]->Image = dice[pick];

				score += pick;
			 }

			 return score;
		 }
};
}

