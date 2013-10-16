#pragma once


namespace Trig {

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
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Graphics^ canvas;

		Graphics^ dbGraphics;

		Bitmap^ dbBitmap;

		int startX;
		int startY;

		int trajX;
		int trajY;

		int xVel;
		int yVel;

		int xPos;
		int yPos;

		int rotationDistanceX;
		int rotationDistanceY;

		int direction;

		int gravity;

		int angle;

		int lineStartX;
		int lineStartY;



	private: System::Windows::Forms::NumericUpDown^  spinLength;
	private: System::Windows::Forms::NumericUpDown^  spinAngle;


	private: System::Windows::Forms::Label^  Length;
	private: System::Windows::Forms::Label^  label1;

		int diameter;
		


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
		this->components = (gcnew System::ComponentModel::Container());
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
		this->spinLength = (gcnew System::Windows::Forms::NumericUpDown());
		this->spinAngle = (gcnew System::Windows::Forms::NumericUpDown());
		this->Length = (gcnew System::Windows::Forms::Label());
		this->label1 = (gcnew System::Windows::Forms::Label());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->spinLength))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->spinAngle))->BeginInit();
		this->SuspendLayout();
		// 
		// button1
		// 
		this->button1->Location = System::Drawing::Point(12, 12);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(75, 23);
		this->button1->TabIndex = 0;
		this->button1->Text = L"Draw";
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
		// 
		// timer1
		// 
		this->timer1->Enabled = true;
		this->timer1->Interval = 1;
		this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
		// 
		// spinLength
		// 
		this->spinLength->Location = System::Drawing::Point(502, 14);
		this->spinLength->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
		this->spinLength->Name = L"spinLength";
		this->spinLength->Size = System::Drawing::Size(67, 20);
		this->spinLength->TabIndex = 2;
		this->spinLength->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {200, 0, 0, 0});
		// 
		// spinAngle
		// 
		this->spinAngle->Location = System::Drawing::Point(638, 14);
		this->spinAngle->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {360, 0, 0, 0});
		this->spinAngle->Name = L"spinAngle";
		this->spinAngle->Size = System::Drawing::Size(67, 20);
		this->spinAngle->TabIndex = 3;
		this->spinAngle->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {45, 0, 0, 0});
		// 
		// Length
		// 
		this->Length->AutoSize = true;
		this->Length->ForeColor = System::Drawing::Color::White;
		this->Length->Location = System::Drawing::Point(456, 16);
		this->Length->Name = L"Length";
		this->Length->Size = System::Drawing::Size(40, 13);
		this->Length->TabIndex = 4;
		this->Length->Text = L"Length";
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->ForeColor = System::Drawing::Color::White;
		this->label1->Location = System::Drawing::Point(598, 17);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(34, 13);
		this->label1->TabIndex = 5;
		this->label1->Text = L"Angle";
		// 
		// Form1
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::Black;
		this->ClientSize = System::Drawing::Size(746, 380);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->Length);
		this->Controls->Add(this->spinAngle);
		this->Controls->Add(this->spinLength);
		this->Controls->Add(this->button1);
		this->Name = L"Form1";
		this->Text = L"Form1";
		this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->spinLength))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->spinAngle))->EndInit();
		this->ResumeLayout(false);
		this->PerformLayout();

			}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				//
				// Clear screen
				//
				dbGraphics->Clear(BackColor);
				//
				// Ellipse falling
				//
				trajX += xVel;
				trajY += yVel;
				yVel += gravity;
				
				if((trajY + diameter) > ClientRectangle.Height)
				{
					trajX = startX;
					trajY = startY;
				}

				dbGraphics->DrawEllipse(gcnew Pen(Color::Red), trajX, trajY, diameter, diameter);
				//
				//	Draw Line that rotates
				//
				int lineLength = (int)spinLength->Value;
				int lineAngle = (int)spinAngle->Value;
								
				double lineRadiansAngle = lineAngle * 0.01745; // convert degrees to radians PI / 180

				int xDelta = Math::Cos(lineRadiansAngle) * lineLength;
				int yDelta = Math::Sin(lineRadiansAngle) * lineLength;

				int endX = lineStartX + xDelta;
				int endY = lineStartY + yDelta;

				dbGraphics->DrawLine(gcnew Pen(Color::White, 3), lineStartX, lineStartY, endX, endY);
				//
				// Draw ellipse that orbits another rectangle
				//
				if(xPos + 20 > ClientRectangle.Right)	direction *= -1;
				if(xPos		 < ClientRectangle.Left)	direction *= -1;
				
				xPos += direction;
				
				angle++;

				double radiansAngle = angle * 0.01745; // convert degrees to radians PI / 180
				
				int newX = xPos + ((rotationDistanceX * Math::Cos(radiansAngle)) - (rotationDistanceY * Math::Sin(radiansAngle)));
				int newY = yPos + ((rotationDistanceY * Math::Sin(radiansAngle)) + (rotationDistanceX * Math::Cos(radiansAngle)));

				dbGraphics->FillEllipse(Brushes::Yellow, newX, newY, 2, 2);

				// Object Ellipse
				dbGraphics->FillEllipse(Brushes::Green, xPos, yPos, 20, 20);

				//=================================================
				// Make buffer visible 
				//=================================================
				canvas->DrawImage(dbBitmap, ClientRectangle);
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				//=================================================
				// Create canvas from form
				//================================================= 
				canvas = CreateGraphics();

				//=================================================
				// Create graphics size of the screen
				//=================================================
				dbBitmap = gcnew Bitmap(ClientRectangle.Width, ClientRectangle.Height);
				 
				//=================================================
				// Grab its Graphics
				//=================================================
				dbGraphics = Graphics::FromImage(dbBitmap);

				startX = 50;
				startY = 50;

				lineStartX = 500;
				lineStartY = 100;

				rotationDistanceX = 50;
				rotationDistanceY = 50;

				xPos = 200;
				yPos = 200;

				direction = 1;

				diameter = 50;
			 }
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				trajX = startX;
				trajY = startY;

				xVel = 5;
				yVel = 3;
				gravity = 1;

				timer1->Enabled = true;
			 }

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

				dbGraphics->Clear(BackColor);
				canvas->DrawImage(dbBitmap, ClientRectangle);
			 }
};
}

