#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class Character
	{
	private:
		float xPos;
		float yPos;
		float width;
		float height;
		float speed;
		float velocity;

	protected:

	public:
		Character(); //Constructor
		Character(float x, float y); //Constructer
		Character(float x, float y, float width, float height); //Constructer
		~Character(); //Destructor

		void move();
		void render();
		void update();

		void setX(float x) {xPos = x;}
		void setY(float y) {yPos = y;}
		void setWidth(float w) {width = w;}
		void setHeight(float h) {height = h;}
		void setSpeed(float s) {speed = s;}


		float getX() {return xPos;}
		float getY() {return yPos;}
		float getWidth() {return width;}
		float getHeight() {return height;}
		float getSpeed() {return speed;}

	};
