#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class Gnome
	{
	private:
		bool visible;
		bool hamster;
		bool hit;

		Point location;
		Image^ image;
		Graphics^ canvas;
		
	public:
		//constructor
		Gnome(Graphics^ g, Point p);

		//functions
		void draw();
		void erase();
		void changeImage();
		void isHit(Point p);
		void isAHamster();

		//sets
		void setVisible(bool v){ visible = v; }
		void setHit(bool h){ hit = h; }
		void setHamster(bool h){ hamster = h; }
		void setLocation(Point l){ location = l; }
		void setImage(Image^ i){ image = i; }
		
		//gets
		bool getVisible(){ return visible; }
		bool getHit(){ return hit; }
		bool getHamster(){ return hamster; }
		Point getLocation(){ return location; }
		Image^ getImage(){ return image; }
	};
