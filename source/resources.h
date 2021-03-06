#ifndef _RESOURCES_H
#define _RESOURCES_H

#include <string>

enum Mode
{
	TitleMode,
	PlayMode,
	PausedMode,
	EndedMode
};

enum Image {
	BuyDamageImage,
	BuyRangeImage,
	BuySpeedImage,
	CrossWallImage,
	ExitImage,
	FastSpeedImage,
	GrassImage,
	IceImage,
	LdWallImage,
	LuWallImage,
	MonsterImage,
	MudImage,
	NormalSpeedImage,
	PauseImage,
	SendImage,
	PlayImage,
	RdWallImage,
	RedTowerImage,
	RlWallImage,
	RldWallImage,
	RluWallImage,
	RuWallImage,
	ShowRangeImage,
	SellImage,
	RedShotImage,
	YellowShotImage,
	TealShotImage,
	SpawnImage,
	TealTowerImage,
	UdWallImage,
	UdlWallImage,
	UdrWallImage,
	WaterImage,
	YellowTowerImage,
	ShowPathIamge
};

const int MAX_MONSTER_COUNT			= 300;
const int BASE_MONSTER_COUNT		= 7;

const int AS_BUFF					= 8;
const int BASE_CREDITS				= 200;
const int GAME_SPEED				= 16;
const int GRID_ROWS					= 11;
const int MONSTER_BASE_HP			= 5;
const int BASE_SPAWN_INTERVAL		= 8; // Must be multiple of 2
const int MAX_WAVE					= 7;
const int MAX_CREDITS				= 99999;
const int MAX_DAMAGE_LEVEL			= 3;
const int MAX_SPEED_LEVEL			= 3;
const int MAX_RANGE_LEVEL			= 3;
const int TOUCH_INTERVAL			= 100;
const int TOWER_BASE_SPEED			= 50;
const int TOWER_BASE_DMG			= 5;
const int TIER1_TOWER_PRICE			= 50;
const int TICKS_PER_SECOND			= 1000 / GAME_SPEED;

#endif //_RESOURCES_H

// Grass		0xff10be36
// Dark green	0xFF046b0a
// Water		0xffff9900
// button bg    0xff09ab12
// tower grey	0xFF4E4949
