#pragma once


enum BackColors{ //no enum name needed
    HIDE, 
	SHOW
};

namespace SimonSays {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	

#define PATTERN_LENGTH 20
#define PATTERN_START_LENGTH 4
#define MIN_RGEN 1
#define MAX_RGEN 5

	/// <summary>
	/// Summary for Game
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Game : public System::Windows::Forms::Form
	{
	public:
		Game(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Game()
		{
			if (components)
			{
				delete components;
			}
		}

	private: array<PictureBox^>^ pBoxs;
	private: array<Color>^ colors;
	private: array<Color>^ darkcolors;
	private: array<int>^ pattern;
	private: array<int>^ answers;

	private: Random^ rGen;

	private: int count;
	private: int patternCount;

	private: bool running;

	private: System::Windows::Forms::Button^  start_Button;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;

	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::ListBox^  listBox3;
	

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
		this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
		this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
		this->start_Button = (gcnew System::Windows::Forms::Button());
		this->listBox1 = (gcnew System::Windows::Forms::ListBox());
		this->listBox2 = (gcnew System::Windows::Forms::ListBox());
		this->listBox3 = (gcnew System::Windows::Forms::ListBox());
		this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
		this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
		this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
		this->groupBox1->SuspendLayout();
		this->groupBox2->SuspendLayout();
		this->groupBox3->SuspendLayout();
		this->SuspendLayout();
		// 
		// pictureBox1
		// 
		this->pictureBox1->BackColor = System::Drawing::Color::White;
		this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->pictureBox1->Location = System::Drawing::Point(0, 0);
		this->pictureBox1->Name = L"pictureBox1";
		this->pictureBox1->Size = System::Drawing::Size(300, 200);
		this->pictureBox1->TabIndex = 0;
		this->pictureBox1->TabStop = false;
		this->pictureBox1->Tag = L"1";
		this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Game::pictureBox_MouseDown);
		this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Game::pictureBox_MouseUp);
		// 
		// pictureBox2
		// 
		this->pictureBox2->BackColor = System::Drawing::Color::White;
		this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->pictureBox2->Location = System::Drawing::Point(299, 0);
		this->pictureBox2->Name = L"pictureBox2";
		this->pictureBox2->Size = System::Drawing::Size(300, 200);
		this->pictureBox2->TabIndex = 1;
		this->pictureBox2->TabStop = false;
		this->pictureBox2->Tag = L"2";
		this->pictureBox2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Game::pictureBox_MouseDown);
		this->pictureBox2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Game::pictureBox_MouseUp);
		// 
		// pictureBox3
		// 
		this->pictureBox3->BackColor = System::Drawing::Color::White;
		this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->pictureBox3->Location = System::Drawing::Point(0, 199);
		this->pictureBox3->Name = L"pictureBox3";
		this->pictureBox3->Size = System::Drawing::Size(300, 200);
		this->pictureBox3->TabIndex = 2;
		this->pictureBox3->TabStop = false;
		this->pictureBox3->Tag = L"3";
		this->pictureBox3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Game::pictureBox_MouseDown);
		this->pictureBox3->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Game::pictureBox_MouseUp);
		// 
		// pictureBox4
		// 
		this->pictureBox4->BackColor = System::Drawing::Color::White;
		this->pictureBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->pictureBox4->Location = System::Drawing::Point(299, 199);
		this->pictureBox4->Name = L"pictureBox4";
		this->pictureBox4->Size = System::Drawing::Size(300, 200);
		this->pictureBox4->TabIndex = 3;
		this->pictureBox4->TabStop = false;
		this->pictureBox4->Tag = L"4";
		this->pictureBox4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Game::pictureBox_MouseDown);
		this->pictureBox4->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Game::pictureBox_MouseUp);
		// 
		// start_Button
		// 
		this->start_Button->BackColor = System::Drawing::Color::Transparent;
		this->start_Button->FlatAppearance->BorderColor = System::Drawing::Color::White;
		this->start_Button->FlatAppearance->BorderSize = 0;
		this->start_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->start_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->start_Button->Location = System::Drawing::Point(0, 400);
		this->start_Button->Name = L"start_Button";
		this->start_Button->Size = System::Drawing::Size(599, 43);
		this->start_Button->TabIndex = 4;
		this->start_Button->Text = L"PLAY";
		this->start_Button->UseVisualStyleBackColor = false;
		this->start_Button->Click += gcnew System::EventHandler(this, &Game::start_Button_Click);
		// 
		// listBox1
		// 
		this->listBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
		this->listBox1->FormattingEnabled = true;
		this->listBox1->Location = System::Drawing::Point(6, 19);
		this->listBox1->Name = L"listBox1";
		this->listBox1->Size = System::Drawing::Size(188, 91);
		this->listBox1->TabIndex = 5;
		// 
		// listBox2
		// 
		this->listBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
		this->listBox2->FormattingEnabled = true;
		this->listBox2->Location = System::Drawing::Point(6, 19);
		this->listBox2->Name = L"listBox2";
		this->listBox2->Size = System::Drawing::Size(188, 91);
		this->listBox2->TabIndex = 6;
		// 
		// listBox3
		// 
		this->listBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
		this->listBox3->FormattingEnabled = true;
		this->listBox3->Location = System::Drawing::Point(6, 19);
		this->listBox3->Name = L"listBox3";
		this->listBox3->Size = System::Drawing::Size(188, 91);
		this->listBox3->TabIndex = 7;
		// 
		// groupBox1
		// 
		this->groupBox1->Controls->Add(this->listBox1);
		this->groupBox1->Location = System::Drawing::Point(621, 12);
		this->groupBox1->Name = L"groupBox1";
		this->groupBox1->Size = System::Drawing::Size(200, 126);
		this->groupBox1->TabIndex = 8;
		this->groupBox1->TabStop = false;
		this->groupBox1->Text = L"Pattern";
		// 
		// groupBox2
		// 
		this->groupBox2->Controls->Add(this->listBox2);
		this->groupBox2->Location = System::Drawing::Point(621, 144);
		this->groupBox2->Name = L"groupBox2";
		this->groupBox2->Size = System::Drawing::Size(200, 126);
		this->groupBox2->TabIndex = 9;
		this->groupBox2->TabStop = false;
		this->groupBox2->Text = L"Answers";
		// 
		// groupBox3
		// 
		this->groupBox3->Controls->Add(this->listBox3);
		this->groupBox3->Location = System::Drawing::Point(621, 276);
		this->groupBox3->Name = L"groupBox3";
		this->groupBox3->Size = System::Drawing::Size(200, 126);
		this->groupBox3->TabIndex = 10;
		this->groupBox3->TabStop = false;
		this->groupBox3->Text = L"Check";
		// 
		// Game
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::White;
		this->ClientSize = System::Drawing::Size(599, 443);
		this->Controls->Add(this->groupBox3);
		this->Controls->Add(this->groupBox2);
		this->Controls->Add(this->groupBox1);
		this->Controls->Add(this->start_Button);
		this->Controls->Add(this->pictureBox4);
		this->Controls->Add(this->pictureBox3);
		this->Controls->Add(this->pictureBox2);
		this->Controls->Add(this->pictureBox1);
		this->DoubleBuffered = true;
		this->Name = L"Game";
		this->ShowIcon = false;
		this->Text = L"Simon Says";
		this->Load += gcnew System::EventHandler(this, &Game::Game_Load);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
		this->groupBox1->ResumeLayout(false);
		this->groupBox2->ResumeLayout(false);
		this->groupBox3->ResumeLayout(false);
		this->ResumeLayout(false);

			}
#pragma endregion

	private: System::Void pictureBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 // event handler
				 answers[count] = pickedItem(sender, BackColors::SHOW);

				 // add to listbox for debug
				 listBox2->Items->Add(answers[count]);

				 // if not finished
				 if(!isSequenceFinished()) count++;

				 // if finished
				 if(isSequenceFinished()) reset(); 
			 }

	private: System::Void pictureBox_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 // event handler
				 pickedItem(sender, BackColors::HIDE);
			 }
		
	private: int Game::pickedItem(System::Object^  s, BackColors bc){
				 // cast object as picturebox
				 PictureBox^ pBox = safe_cast<PictureBox^>(s);
				 
				 // convert tag to int
				 int item = int::Parse(pBox->Tag->ToString());

				 // if game running change color
				 if(!running) pBox->BackColor = getColor(bc, item);

				 return item;
			 }

	private: Color Game::getColor(BackColors bc, int item) {
				 // switch on enum
				 switch(bc)
				 {
					case BackColors::SHOW:
						return colors[--item];
					case BackColors::HIDE:
						return Color::White;
				 }
			 }

	private: System::Void Game_Load(System::Object^  sender, System::EventArgs^  e) {
				 // assign pictureboxs to array
				 pBoxs = gcnew array<PictureBox^> 
				 {
					pictureBox1, 
					pictureBox2, 
					pictureBox3, 
					pictureBox4 
				 };

				 // create color array
				 colors = gcnew array<Color> 
				 { 
					Color::Red, 
					Color::Blue, 
					Color::Lime, 
					Color::Yellow 
				 };
				 
				 // create arrays for sequences
				 pattern = gcnew array<int>(PATTERN_LENGTH);
				 answers = gcnew array<int>(PATTERN_LENGTH);

				 // create random instance
				 rGen = gcnew Random();
				 
				 // initialize pattern count
				 patternCount = PATTERN_START_LENGTH;

				 gameInit();
			 }
	
	private: System::Void start_Button_Click(System::Object^  sender, System::EventArgs^  e) {
				 // clear boxes
				 gameClearBoxes();

				 // set game running
				 gameToggleRunning();

				 // reset count
				 gameResetCount();

				 // set button text
				 gameHandleButton();

				 // run main game
				 executeGameSequence();		

				 // set game to not running
				 gameToggleRunning();
			 }

	private: Game::Void gameClearBoxes() {
				 listBox1->Items->Clear();
				 listBox2->Items->Clear();
				 listBox3->Items->Clear();
			 }

	private: Game::Void gameHandleButton() {
				 // enable / disable button
				 start_Button->Enabled = !start_Button->Enabled;
				 start_Button->Text = "MATCH THE SEQUENCE OF COLOURS";
			 }

	private: Game::Void gameInit() {
				 generateSequence();
				 //runSequence();				 
			 }

	private: Game::Void generateSequence() {
				 // loop through pattern array
				 for(int i = 0; i < pattern->Length; i++)
				 {	
					pattern[i] = rGen->Next(MIN_RGEN,MAX_RGEN);
				 }
			 }

	private: Game::Void executeGameSequence() {
				 for(int i = 0; i < patternCount; i++)
				 {
				    // add to list box for debug
				    listBox1->Items->Add(pattern[i]);

				    // run flash sequence
				    runSequence(pattern[i] - 1);					
				 }
			  }


	private: Game::Void runSequence(int currInt) {
					// show color
					pBoxs[currInt]->BackColor = colors[currInt];
					Application::DoEvents();
					System::Threading::Thread::Sleep(500);
					
					// hide color
					pBoxs[currInt]->BackColor = Color::White;
					Application::DoEvents();
					System::Threading::Thread::Sleep(500);
			 }

	private: Game::Void gameToggleRunning() {
				 // toggle bool
				 running = !running;
			 }

	private: Game::Void gameResetCount() {
				 // reset
				 count = 0;
			 }

	private: bool Game:: isSequenceFinished() {
				 // is count greater than or equal to the pattern
				 return count >= patternCount; 					 
			 }

	private: Game::Void reset() {
				 // reset count
				 gameResetCount();

				 // go into button handler
				 start_Button->Enabled = !start_Button->Enabled;
				 start_Button->Text = checkAnswers() ? "NEXT" : "TRY AGAIN";
			 }

	private: bool Game::checkAnswers() {
				 // loop through pattern array
				 for(int i = 0; i < patternCount; i++)
				 {
					// display in listbox for debug
					listBox3->Items->Add(answers[i] + " | " + pattern[i]);

					// if wrong
					if(answers[i] != pattern[i])
						return false;
				 }

				 // if correct increase pattern length
				 patternCount++;
				 return true;					
			 }
};
}

