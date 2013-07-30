#pragma once


namespace pLinkedList {

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(135, 98);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 273);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 //Method 1
				 int* myIntPointer1; //declare pointer
				 int x;	// declare int 16 bits of memory
				 myIntPointer1 = &x; //assign x memory location in myIntPointer

				 //Method 2
				 int* myIntPointer2;
				 myIntPointer2 = new int; //only way to access int is by referencing to pointer

				 //Example 1 :: reading via a pointer
				 //declare pointer and int variables
				 int* myIntPointer3;
				 int i, j;

				 //give j a value
				 j = 15;

				 //set myIntPointer to point to j
				 myIntPointer3 = &j;

				 // set i= the value at the location pointed to by myIntPointer
				 i = *myIntPointer3;

				 //Example 2 :: writing via a pointer
				 //declare pointer and int variables
				 int* myIntPointer4;
				 int x;

				 //give x a value
				 x = 15;

				 //set myIntPointer to point to j
				 myIntPointer4 = &x;

				 // assign value to x memory location
				 *myIntPointer4 = 25;

				 //Example 3
				 //declare pointer and int variables
				 int* myIntPointer5;
				 int k;

				 myIntPointer5 = new int; //assigned value via pointer

				 *myIntPointer5 = 25; //assigned int to pointer

				 k = *myIntPointer5;	//assigned to k via pointer

				 //Example 4
				 int *aPtr, *bPtr, *cPtr;

				 aPtr = new int;

				 *aPtr = 45; // assigns 45

				 bPtr = aPtr;  //bPtr now 45

				 cPtr = new int;

				 *cPtr = *aPtr; //b

				 //Unmanaged
				 //myClass* unmanagedPtr;
				 //unmanagedPtr = new myClass(.....);

				 //Managed
				 //myClass^ managedPtr;
				 //managedPtr = gcnew myClass(.....);

				 //unmanagedPtr->classMethod(.....);
				 //managedPtr->classMethod(.....);
			 }
	};
}

