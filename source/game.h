#ifndef _GAME_H
#define _GAME_H

#include <string>
#include <list>
#include <string>
#include <utility>
#include <map>

#include "tileGrid.h"
#include "trackingShot.h"
#include "pathingVertex.h"
#include "input.h"
#include "pathGrid.h"
#include "io.h"
#include "wall.h"

typedef std::pair<int, Tower*> TowerElement;
typedef std::pair<int, Wall*> WallElement;
typedef std::map<int, Tower*>::const_iterator TowerMapConstIter;
typedef std::map<int, Wall*>::const_iterator WallMapConstIter;

class Game 
{
public:
	Game(int _tileSize);

	~Game();

	Mode update();

	void render();

	void reloadUI();

	Mode manangePausedMode();

	Mode manageTitleMode();

	Mode manageGameEnded();

	void cleanUp();

	void reset();
private:
	typedef std::pair<int, int> Point;

	Io			*io;
	TileGrid	*tileGrid;
	PathGrid	*pathGrid;
	std::string *mobPath;
	
	std::vector<Monster*>		monsters;
	std::map<int, Tower*>		towers;
	std::map<int, Wall*>		walls;
	std::vector<Point>			mobGridPos;
	std::list<TrackingShot*>	shots;

	SpeedMode speedMode;
	SpeedMode rememberSpeedMode;

	bool spawnNextWave;
	bool updatePath;
	bool validPathExists;
	bool newTowerBuilt;

	int gridColumns;
	int gridRows;
	int towerAsCounter;
	int towerDmgCounter;
	int towerRangeCounter;
	int spawnX;
	int spawnY;
	int exitX;
	int exitY;
	int spawnNextMobId;
	int mobHp;
	int mobMoveSpeed;
	int shotMoveSpeed;
	int currWave;
	int credits;
	int numOfCurrWaveMons;
	int mobsAlive;
	int spawnTimer;
	int shotDiam;
	int lives;
	int monsterRadius;

	unsigned int wallCap;
	unsigned int tileSize;
	unsigned int horizontalOffset;
	unsigned int horizontalBorder;

	// Will construct a string of instructions to get from exit to spawnpoint
	// given that pathGrid contains one found by findShortestPath()
	void backtrack(pvPtr iter, std::string &path) const;

	void buildTower(int _x, int _y);

	// Will build wall on (x,y)
	void buildWall(int x, int y);

	// Updates the speed of moveable objects
	void changeGameSpeed();

	void decreaseLives();
	
	// Generate keys for grid positions
	int getKey(int x, int y) const;

	// Returns the Image of tile x,y
	Image getTileType(int x, int y) const;

	// Returns a grid coordiante, takes a screen value
	int getGridCoordX(int xVal) const;
	int getGridCoordY(int yVal) const;

	// Depending on current speedMode will build or remove a wall
	void gridTouch();

	//Returns game mode, play or paused
	Mode handleInput();

	void invokeDeleteTowerBtn();
	void invokeDmgBtn();
	void invokeBuySpeedBtn();
	void invokeBuyRangeBtn();

	// Retunvalue indicates which neighbouring tiles contain towers.
	// Neighbouring walls can be updated.
	unsigned int findNeighbours(int x, int y, bool updateNeighbours);

	// Returns true if a shortest path was found and g_mobPath was Updated
	bool findShortestPath();

	// Check if game over and if so, manage that
	bool gameEnded();

	// Set up the map terrain using rng
	void generateMap();

	Image getWallType(unsigned int neighbours) const;
	TowerElement makeTowerElement(int x, int y, Tower *t);
	WallElement makeWallElement(int x, int y, Wall *w);

	// Will check for collisions and handle consequences
	void manageCollisions();

	// Handles the consequences of a monster dyeing
	void monsterDied(Monster *mon);
	void moveMobs();
	void moveShots();

	void wallTouch(int x, int y);

	// Manages the events that accur when a new wave begins
	void onNewWave();

	void removePathGrassListeners(int pathTravX, int pathTravY);
	void removeWall(int x, int y);
	void renderMonsters() const;
	void renderShots() const;
	void renderWalls() const;
	void renderTowers() const;
	void setMonsterSpeed();
	void setShotSpeed();
	void setPathGrassListeners(int pathTravX, int pathTravY);

	// Towers will shoot if they can
	void shoot();

	// Will spawn a monster if allowed
	void spawnMonster();
	
	// Returns true if tower attack speed can be upgraded further
	bool towerAsUncapped() const;

	// Returns true if tower attack range can be upgraded further
	bool towerRangeUncapped() const;

	void towerTouch(int x, int y);

	// If a monster has moved into a new grid element, will Update new and previous
	// grid elements
	void updateMobGrid();

	// Updated wave number
	void updateStats();

	// Updates thewall in tile x,y when an adjoining wall is built
	void updateWall(int x, int y);

	// Retuns true if (x, y) is not the spawn or exit point
	bool validIceMud(int x, int y) const;

	// Will check if wave is over and if so, if a new wave should be initiated
	void waveOverCheck();

};
#endif /* !_GAME_H */
