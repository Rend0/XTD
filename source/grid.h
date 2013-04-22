#ifndef _GRID_H
#define _GRID_H

#include "tile.h"
#include "tower.h"
#include "rendering.h"
#include "grass.h"
#include "Iw2D.h"
//==============================================================================
class Grid 
{
	Tile* tiles[GRID_COLUMNS][GRID_ROWS];
public:
	Grid();
	~Grid();
	void buildGrass(int x, int y);
	void buildSpawn(int x, int y);
	Tower* buildTowerMan(int x, int y);
	void addTower(Tower* t, int x, int y);
	void buildWater(int x, int y);
	void buildExit(int x, int y);
	Tile* get(int x, int y);
	const Tile & get(int x, int y) const;
	void releaseTile(int x, int y);
	void render() const;
	void notifyTileExit(int x, int y, int mobId);
	void notifyTileEnter(int x, int y, int mobId);
	bool isGrass(int x, int y) const;
	Tile* at(int x, int y) const;
	bool validPoint(int x, int y) const;
	void setAllGrass();
	void buildAllGrass();
	void removeListener(int x, int y);
	void setListener(int x, int y, Tower* t);
	void removePathGrassListeners(int pathTravX, int pathTravY);
	void setPathGrassListeners(int pathTravX, int pathTravY);
	bool isTower(int x, int y);
};
//==============================================================================
inline void Grid::setAllGrass()
{
	for(int x=0; x < GRID_COLUMNS; x++)
		for(int y=0; y < GRID_ROWS; y++) 
		{
			tiles[x][y]->setColor(GRASS);
		}
}
//==============================================================================
inline void Grid::buildAllGrass()
{
	for(int x=0; x < GRID_COLUMNS; x++)
		for(int y=0; y < GRID_ROWS; y++) 
		{
			buildGrass(x,y);
		}
}
//==============================================================================
inline void Grid::addTower(Tower* t, int x, int y)
{
	releaseTile(x, y);
	tiles[x][y] = t;
}
//==============================================================================
inline bool Grid::validPoint(int x, int y) const
{
	return (x >= 0 && x < GRID_COLUMNS && y >= 0 && y < GRID_ROWS);
}
//==============================================================================
inline Tile* Grid::at(int x, int y) const
{
	return tiles[x][y];
}
//==============================================================================
inline void Grid::releaseTile(int x, int y)
{
	delete tiles[x][y];
}
//==============================================================================
inline Tower* Grid::buildTowerMan(int x, int y)
{
	releaseTile(x, y);
	Tower *t = new Tower(x, y);
	tiles[x][y] = t;
	return t;
}
//==============================================================================
inline void Grid::buildGrass(int x, int y)
{
	tiles[x][y] = new Grass();
}
//==============================================================================
inline void Grid::buildWater(int x, int y)
{
	at(x, y)->setColor(WATER);
}
//==============================================================================
inline void Grid::buildSpawn(int x, int y)
{
	releaseTile(x, y);
	tiles[x][y] = new Spawn();
}
//==============================================================================
inline void Grid::buildExit(int x, int y)
{
	releaseTile(x, y);
	tiles[x][y] = new Exit();
}
//==============================================================================
#endif //_GRID_H
