#ifndef _TOWER_H
#define _TOWER_H

#include<vector>
#include "resources.h"
#include "monster.h"
#include "tile.h"
#include "trackingShot.h"
#include "path_Grass_listener.h"

class Tower : public TowerListener, public Object, public ObjectWithCenter
{
	bool mobTable[MAX_MONSTER_COUNT];
	int reloadStatus;
	int target; 
	int builtWave;
	static int s_range;
	static int s_dmg;
	static int s_as; //Attack speed in ms
public:
	Tower(int LeftX, int LeftY, int tileSize, int _builtRound);
	~Tower();
	bool operator== (const Tower* t) const;

	// Returns target index or (number of monsters at current wave + 1)
	// if none is found
	int acquireTarget(int numCurrWaveMobs);
	int acquireTarget(int numCurrWaveMobs, int scanFrom);
	bool armed() const;
	void initTower(int _dmg, int _range, int _attSpeed);	
	void mobLeft(int mobId);
	void mobEntered(int mobId);
	void reloadTick();
	bool builtThisWave(int currWave) const;
	// Takes targets center coordinates
	bool targetInRange(int targetX, int targetY, int targetRad);

	// Returns damage done
	int shoot();

	static void resetTowers(int tileSize);
	static void buffAs();
	static void buffDmg(int _dmg);
	static void buffRange();
	static void fastAs();
	static void slowAs();

};

#endif //_TOWER_H
