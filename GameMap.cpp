#include "GameMap.h"
#include <iostream>
#include <fstream>

using namespace std;

string tabs = "\t\t\t\t\t";
GameMap::GameMap()
{
    playerCell = NULL;
    finished = false;
    loadMapFromFile();
}

void GameMap::draw()
{
    cout << endl
         << endl;
    for (int y = 0; y < 15; y++)
    {
        cout << tabs << tabs << "\t\t";
        for (int x = 0; x < 10; x++)
        {

            cout << cells[y][x].id;
        }
        cout << endl;
    }
}

bool GameMap::setPlayerCell(int playerX, int playerY)
{
    if (cells[playerY][playerX].isBlocked() == false)
    {
        if (playerCell != NULL)
        {
            playerCell->id = ' ';
        }
        playerCell = &cells[playerY][playerX];
        if (playerCell->id == '$')
        {
            finished = true;
        }
        playerCell->id = 'H';
        return true;
    }

    return false;
}

void GameMap::loadMapFromFile()
{
    string line;
    ifstream MyFile("Map.data");
    if (MyFile.is_open())
    {
        int row = 0;
        while (getline(MyFile, line))
        {
            for (int x = 0; x < line.length(); x++)
            {
                if (line[x] == '0')
                    cells[row][x].id = ' ';
                else
                    cells[row][x].id = line[x];
            }
            row++;
        }
    }
    else
    {
        cout << "FATAL ERROR: MAP FILE COULD NOT BE LOADED!" << endl;
    }
    MyFile.close();
}

bool GameMap::isFinished()
{
    return finished;
}
