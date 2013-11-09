#pragma once

using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

ref class Item
{
private:
	PictureBox^ item;

	Image^ itemImage;
	
	Graphics^ dbGraphics;

	Point location;

	bool collected;

public:
	Item(Graphics^ startCanvas, PictureBox^ startItem);
	void Draw();
};
