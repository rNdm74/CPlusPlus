#pragma once
#include <string>

namespace pButtonGrow {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


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
	private: System::Windows::Forms::Button^  growable_Button;
	private: System::Windows::Forms::TextBox^  textBox;

	private: System::Windows::Forms::Button^  change_Button;

	private: System::Windows::Forms::GroupBox^  question_1;
	private: System::Windows::Forms::GroupBox^  question_2;
	private: System::Windows::Forms::GroupBox^  question_4;

	private: System::Windows::Forms::Button^  toggle_Button;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  add_Button;
	private: System::Windows::Forms::ListBox^  listBox;
	private: System::Windows::Forms::GroupBox^  question_5a;
	private: System::Windows::Forms::PictureBox^  pictureBox;
	private: System::Windows::Forms::TextBox^  steps_TextBox;



	private: System::Windows::Forms::Button^  go_Button;

	private: System::Windows::Forms::Label^  label;
	private: System::Windows::Forms::GroupBox^  question_5b;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::GroupBox^  question_6;

	private: System::Windows::Forms::Button^  animate_Button;
	private: System::Windows::Forms::PictureBox^  dragon;
	private: System::Windows::Forms::GroupBox^  question_7;


	private: System::Windows::Forms::Button^  draw_Button;


	private: System::ComponentModel::IContainer^  components;





	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		int count;
		int frame;
		int direction;
		Graphics^ mainCanvas;	
		Random^ rGen;
		Rectangle^ r; 

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->growable_Button = (gcnew System::Windows::Forms::Button());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->change_Button = (gcnew System::Windows::Forms::Button());
			this->question_1 = (gcnew System::Windows::Forms::GroupBox());
			this->question_2 = (gcnew System::Windows::Forms::GroupBox());
			this->question_4 = (gcnew System::Windows::Forms::GroupBox());
			this->toggle_Button = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox = (gcnew System::Windows::Forms::ListBox());
			this->add_Button = (gcnew System::Windows::Forms::Button());
			this->question_5a = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->steps_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->go_Button = (gcnew System::Windows::Forms::Button());
			this->label = (gcnew System::Windows::Forms::Label());
			this->question_5b = (gcnew System::Windows::Forms::GroupBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->question_6 = (gcnew System::Windows::Forms::GroupBox());
			this->animate_Button = (gcnew System::Windows::Forms::Button());
			this->dragon = (gcnew System::Windows::Forms::PictureBox());
			this->question_7 = (gcnew System::Windows::Forms::GroupBox());
			this->draw_Button = (gcnew System::Windows::Forms::Button());
			this->question_1->SuspendLayout();
			this->question_2->SuspendLayout();
			this->question_4->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->question_5a->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox))->BeginInit();
			this->question_5b->SuspendLayout();
			this->question_6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dragon))->BeginInit();
			this->question_7->SuspendLayout();
			this->SuspendLayout();
			// 
			// growable_Button
			// 
			this->growable_Button->Location = System::Drawing::Point(6, 30);
			this->growable_Button->Name = L"growable_Button";
			this->growable_Button->Size = System::Drawing::Size(75, 23);
			this->growable_Button->TabIndex = 0;
			this->growable_Button->Text = L"GROW ME";
			this->growable_Button->UseVisualStyleBackColor = true;
			this->growable_Button->Click += gcnew System::EventHandler(this, &Form1::growable_Button_Click);
			// 
			// textBox
			// 
			this->textBox->Location = System::Drawing::Point(6, 27);
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(319, 20);
			this->textBox->TabIndex = 1;
			this->textBox->Text = L"Hello World";
			// 
			// change_Button
			// 
			this->change_Button->Location = System::Drawing::Point(237, 53);
			this->change_Button->Name = L"change_Button";
			this->change_Button->Size = System::Drawing::Size(88, 20);
			this->change_Button->TabIndex = 2;
			this->change_Button->Text = L"CHANGE ME";
			this->change_Button->UseVisualStyleBackColor = true;
			this->change_Button->Click += gcnew System::EventHandler(this, &Form1::change_Button_Click);
			// 
			// question_1
			// 
			this->question_1->Controls->Add(this->growable_Button);
			this->question_1->Location = System::Drawing::Point(13, 12);
			this->question_1->Name = L"question_1";
			this->question_1->Size = System::Drawing::Size(331, 74);
			this->question_1->TabIndex = 3;
			this->question_1->TabStop = false;
			this->question_1->Text = L"Question 1: Click the button to grow 10 px in size ";
			// 
			// question_2
			// 
			this->question_2->Controls->Add(this->textBox);
			this->question_2->Controls->Add(this->change_Button);
			this->question_2->Location = System::Drawing::Point(13, 93);
			this->question_2->Name = L"question_2";
			this->question_2->Size = System::Drawing::Size(331, 79);
			this->question_2->TabIndex = 4;
			this->question_2->TabStop = false;
			this->question_2->Text = L"Question 2: Type below and click the button to change its text";
			// 
			// question_4
			// 
			this->question_4->Controls->Add(this->toggle_Button);
			this->question_4->Location = System::Drawing::Point(13, 361);
			this->question_4->Name = L"question_4";
			this->question_4->Size = System::Drawing::Size(331, 80);
			this->question_4->TabIndex = 5;
			this->question_4->TabStop = false;
			this->question_4->Text = L"Question 4: Toggle button text on/off";
			// 
			// toggle_Button
			// 
			this->toggle_Button->Location = System::Drawing::Point(123, 31);
			this->toggle_Button->Name = L"toggle_Button";
			this->toggle_Button->Size = System::Drawing::Size(75, 23);
			this->toggle_Button->TabIndex = 0;
			this->toggle_Button->Text = L"ON ME";
			this->toggle_Button->UseVisualStyleBackColor = true;
			this->toggle_Button->Click += gcnew System::EventHandler(this, &Form1::toggle_Button_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->listBox);
			this->groupBox1->Controls->Add(this->add_Button);
			this->groupBox1->Location = System::Drawing::Point(13, 179);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(331, 176);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Question 3: Add rows to a listbox";
			// 
			// listBox
			// 
			this->listBox->FormattingEnabled = true;
			this->listBox->Location = System::Drawing::Point(6, 20);
			this->listBox->Name = L"listBox";
			this->listBox->Size = System::Drawing::Size(319, 121);
			this->listBox->TabIndex = 1;
			// 
			// add_Button
			// 
			this->add_Button->Location = System::Drawing::Point(6, 147);
			this->add_Button->Name = L"add_Button";
			this->add_Button->Size = System::Drawing::Size(75, 23);
			this->add_Button->TabIndex = 0;
			this->add_Button->Text = L"ADD ME";
			this->add_Button->UseVisualStyleBackColor = true;
			this->add_Button->Click += gcnew System::EventHandler(this, &Form1::add_Button_Click);
			// 
			// question_5a
			// 
			this->question_5a->Controls->Add(this->pictureBox);
			this->question_5a->Location = System::Drawing::Point(350, 12);
			this->question_5a->Name = L"question_5a";
			this->question_5a->Size = System::Drawing::Size(401, 74);
			this->question_5a->TabIndex = 7;
			this->question_5a->TabStop = false;
			this->question_5a->Text = L"Question 5: Displays picturebox moving nSteps from user input";
			// 
			// pictureBox
			// 
			this->pictureBox->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox->Location = System::Drawing::Point(19, 23);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(30, 30);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			// 
			// steps_TextBox
			// 
			this->steps_TextBox->Location = System::Drawing::Point(55, 27);
			this->steps_TextBox->Name = L"steps_TextBox";
			this->steps_TextBox->Size = System::Drawing::Size(339, 20);
			this->steps_TextBox->TabIndex = 1;
			this->steps_TextBox->Text = L"0";
			// 
			// go_Button
			// 
			this->go_Button->Location = System::Drawing::Point(319, 53);
			this->go_Button->Name = L"go_Button";
			this->go_Button->Size = System::Drawing::Size(75, 20);
			this->go_Button->TabIndex = 2;
			this->go_Button->Text = L"GO ME";
			this->go_Button->UseVisualStyleBackColor = true;
			this->go_Button->Click += gcnew System::EventHandler(this, &Form1::go_Button_Click);
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Location = System::Drawing::Point(15, 30);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(34, 13);
			this->label->TabIndex = 3;
			this->label->Text = L"Steps";
			// 
			// question_5b
			// 
			this->question_5b->Controls->Add(this->go_Button);
			this->question_5b->Controls->Add(this->label);
			this->question_5b->Controls->Add(this->steps_TextBox);
			this->question_5b->Location = System::Drawing::Point(351, 93);
			this->question_5b->Name = L"question_5b";
			this->question_5b->Size = System::Drawing::Size(400, 79);
			this->question_5b->TabIndex = 8;
			this->question_5b->TabStop = false;
			this->question_5b->Text = L"Question 5: Enter numbers of steps ";
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &Form1::timer_Tick);
			// 
			// question_6
			// 
			this->question_6->Controls->Add(this->animate_Button);
			this->question_6->Controls->Add(this->dragon);
			this->question_6->Location = System::Drawing::Point(351, 179);
			this->question_6->Name = L"question_6";
			this->question_6->Size = System::Drawing::Size(400, 262);
			this->question_6->TabIndex = 9;
			this->question_6->TabStop = false;
			this->question_6->Text = L"Question 6: Load image from file and animate to the screen";
			// 
			// animate_Button
			// 
			this->animate_Button->Location = System::Drawing::Point(282, 233);
			this->animate_Button->Name = L"animate_Button";
			this->animate_Button->Size = System::Drawing::Size(112, 23);
			this->animate_Button->TabIndex = 1;
			this->animate_Button->Text = L"ANIMATE ME";
			this->animate_Button->UseVisualStyleBackColor = true;
			this->animate_Button->Click += gcnew System::EventHandler(this, &Form1::animate_Button_Click);
			// 
			// dragon
			// 
			this->dragon->Location = System::Drawing::Point(134, 48);
			this->dragon->Name = L"dragon";
			this->dragon->Size = System::Drawing::Size(128, 128);
			this->dragon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->dragon->TabIndex = 0;
			this->dragon->TabStop = false;
			// 
			// question_7
			// 
			this->question_7->Controls->Add(this->draw_Button);
			this->question_7->Location = System::Drawing::Point(758, 13);
			this->question_7->Name = L"question_7";
			this->question_7->Size = System::Drawing::Size(280, 73);
			this->question_7->TabIndex = 10;
			this->question_7->TabStop = false;
			this->question_7->Text = L"Question 7: Drawing with a graphics object";
			// 
			// draw_Button
			// 
			this->draw_Button->Location = System::Drawing::Point(100, 29);
			this->draw_Button->Name = L"draw_Button";
			this->draw_Button->Size = System::Drawing::Size(75, 23);
			this->draw_Button->TabIndex = 0;
			this->draw_Button->Text = L"START ME";
			this->draw_Button->UseVisualStyleBackColor = true;
			this->draw_Button->Click += gcnew System::EventHandler(this, &Form1::draw_Button_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1050, 464);
			this->Controls->Add(this->question_7);
			this->Controls->Add(this->question_6);
			this->Controls->Add(this->question_5b);
			this->Controls->Add(this->question_5a);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->question_4);
			this->Controls->Add(this->question_2);
			this->Controls->Add(this->question_1);
			this->DoubleBuffered = true;
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->question_1->ResumeLayout(false);
			this->question_2->ResumeLayout(false);
			this->question_2->PerformLayout();
			this->question_4->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->question_5a->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox))->EndInit();
			this->question_5b->ResumeLayout(false);
			this->question_5b->PerformLayout();
			this->question_6->ResumeLayout(false);
			this->question_6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dragon))->EndInit();
			this->question_7->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void growable_Button_Click(System::Object^  sender, System::EventArgs^  e) {
				 //define size that button will grow
				 int grow_Size = 10;
				 
				 //set lefts to variables
				 int growable_Button_Right = growable_Button->Left + growable_Button->Width;
				 int groupBox_Right = question_1->Width - question_1->Left;

				 //check if button is too big
				 if(growable_Button_Right > groupBox_Right){
					 growable_Button->Text = "TO BIG";
					 grow_Size = 0;
				 }

				 //increase button size
				 growable_Button->Width+=grow_Size;				 
			 }
	private: System::Void change_Button_Click(System::Object^  sender, System::EventArgs^  e) {
				 //if textbox is not empty change button text
				 if (textBox->Text != "") change_Button->Text = textBox->Text;
			 }
	private: bool toggle;
	private: System::Void toggle_Button_Click(System::Object^  sender, System::EventArgs^  e) {
				 //change button text
				 toggle_Button->Text = ((toggle) ? "ON" : "OFF") + " ME";

				 //toggle boolean
				 toggle = !toggle;
			}
private: System::Void add_Button_Click(System::Object^  sender, System::EventArgs^  e) {
			 //add item to list box
			 listBox->Items->Add("This is line " + listBox->Items->Count);
		 }
		 
private: System::Void go_Button_Click(System::Object^  sender, System::EventArgs^  e) {
			 //convert object to int
			 int steps = int::Parse(steps_TextBox->Text);
			 
			 //move pictureBox right nSteps
			 for (int i = 0; i < steps; i++) {
				 //move pictureBox left 10 pixels
				 pictureBox->Left += 10;

				 //sleep 100ms
				 System::Threading::Thread::Sleep(100);

				 //redraw window
				 Application::DoEvents();
			 }
		 }
private: System::Void animate_Button_Click(System::Object^  sender, System::EventArgs^  e) {			 
			 //enabled timer
			 timer->Enabled = true;
		 }
	

private: Form1::Void animate_Dragon(){
			 //set frame and direction
			 if(frame >= 8)direction = -1;
			 if(frame <= 1)direction = 1;
			 frame += direction;

			 //load image
			 Image^ dragon_Image = Image::FromFile( "e:\\dragons\\Dragon" + frame + ".bmp" );

			 //set image
			 dragon->Image = dragon_Image;

			 

			 //used to reset frame
			 //count %= 8;
}
private: Form1::Void draw_Random_Ellipse(){
			 //color variables
			 int red;
			 int green;
			 int blue;

			 //assign random numbers to color variables
			 red = rGen->Next(256);
			 green = rGen->Next(256);
			 blue = rGen->Next(256);

			 //create bounds for drawing ellipse
			 Rectangle^ r = gcnew Rectangle(question_7->Left, question_7->Bottom, question_7->Width, Height - 20);
			 int x = rGen->Next(r->Left, r->Right);
			 int y = rGen->Next(r->Top, r->Bottom);
			 int width = rGen->Next(101);
			 int height = rGen->Next(101);

			 //set color
			 Color color = Color::FromArgb(red, green, blue);
			 
			 //set brush
			 Brush^ brush = gcnew SolidBrush(color);

			 //draw ellipse
			 mainCanvas->FillEllipse(brush, x ,y,width, height);
		 }

private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {
			 animate_Dragon();
			 draw_Random_Ellipse();

			 //redraw form
			 Application::DoEvents();
		 }
private: System::Void draw_Button_Click(System::Object^  sender, System::EventArgs^  e) {
			 //change button text
			 draw_Button->Text = ((toggle) ? "START" : "STOP") + " ME";
			 //enable timer
			 timer->Enabled = !toggle;

			 //change boolean
			 toggle = !toggle;			 
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 count = 0;
			 mainCanvas = CreateGraphics();
			 rGen = gcnew Random();
		 }
};
}

