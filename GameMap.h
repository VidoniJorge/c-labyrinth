#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "MapCell.h"

class GameMap
{
public:
    MapCell cells[15][10];
    MapCell *playerCell;

    GameMap();

    void draw();
    bool setPlayerCell(int playerX, int playerY);
    bool isFinished();

protected:
private:
    void loadMapFromFile();
    bool finished;
};

#endif