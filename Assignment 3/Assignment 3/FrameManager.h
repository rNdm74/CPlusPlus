#pragma once

ref class FrameManager
{
private:
	array<int, 3>^ playerList;
	array<int, 3>^ floppitList;
	array<int, 3>^ fluppitList;
	array<int, 3>^ perunaList;
	array<int, 3>^ cocoonList;
	array<int, 3>^ makhanaList;

	array<Point>^ playerState;
	array<Point>^ floppitState;
	array<Point>^ fluppitState;
	array<Point>^ perunaState;
	array<Point>^ cocoonState;
	array<Point>^ makhanaState;

public:
	FrameManager();

	array<int, 3>^ CreateFrameArrayFromFile(String^ fileName, array<Point>^ spriteSheetState);
	ArrayList^ CreateFrameList(array<int, 3>^ spriteSheetData);

	void GarbageCollect();

	ArrayList^ getPlayerList()	{ return CreateFrameList(playerList); }
	ArrayList^ getFloppitList()	{ return CreateFrameList(floppitList); }
	ArrayList^ getFluppitList()	{ return CreateFrameList(fluppitList); }
	ArrayList^ getPerunaList()	{ return CreateFrameList(perunaList); }
	ArrayList^ getCocoonList()	{ return CreateFrameList(cocoonList); }
	ArrayList^ getMakhanaList()	{ return CreateFrameList(makhanaList); }
};
