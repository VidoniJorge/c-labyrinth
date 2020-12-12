#include <iostream>
#include <fstream>

#include "Player.h"
#include "GameMap.h"

using namespace std;

string tab = "\t\t\t\t\t";

bool isPlayerDead(int hp)
{
    if (hp <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void drawFile(string name)
{
    ifstream myfile(name);
    if (myfile.is_open())
    {
        string line;
        while (getline(myfile, line))
        {
            cout << tab << "\t\t\t" << line << endl;
        }
    }
    else
    {
        cout << "Fatal Error: File " << name << "can not open";
    }
}

void clearDisplay()
{
    system("clear");
}

void printMessage()
{
    cout << tab << "\t\t\tRecuerda el objetivo es llegar al tesorro reprecentado con la el simbolo de $ " << endl;
    for (int i = 0; i < 3; i++)
        cout << endl;
    cout << tab << tab << "Utiliza las teclas:" << endl;
    cout << tab << tab << "a ir a la izquierda" << endl;
    cout << tab << tab << "d ir a la derecha" << endl;
    cout << tab << tab << "w para subir" << endl;
    cout << tab << tab << "s para bajar" << endl;
}

int main()
{
    clearDisplay();
    drawFile("Intro.data");

    string aux;
    cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tPrecione cualquier tecla";
    getchar();
    clearDisplay();
    Player hero;
    GameMap map;

    while (map.isFinished() == false)
    {
        printMessage();
        if (map.setPlayerCell(hero.getAxisX(), hero.getAxisY()) == false)
        {
            hero.resetToSafePosition();
        }
        map.draw();
        hero.callInput();
        clearDisplay();
    }
    drawFile("Cofre.data");

    return 0;
}

//g++ hello-world.cpp Player.cpp MapCell.cpp GameMap.cpp -o main

/*void DrawMap(int HeroPos[2], char GameMap[5][5])
{
    // pinto columnas
    for (int x = 0; x < 5; x++)
    {
        // pinto filas
        for (int y = 0; y < 5; y++)
        {
            if (HeroPos[0] == x && HeroPos[1] == y)
            {
                cout << 'H';
            }
            else
            {
                cout << GameMap[y][x];
            }
        }
        cout << endl;
    }
}

bool validateMaxPosition(int MaxPos, int Pos)
{
    return MaxPos == Pos;
}

bool validateMinPosition(int MinPos, int Pos)
{
    return MinPos == Pos;
}

void createMap()
{
    ofstream MyFile("GameData.txt");
    if (MyFile.is_open())
    {
        MyFile << "--------------" << endl;
        MyFile << "LVL: 1" << endl;
        MyFile << "MAPA" << endl;
        MyFile << "ooooo" << endl;
        MyFile << "ooooo" << endl;
        MyFile << "ooooo" << endl;
        MyFile << "ooooo" << endl;
        MyFile << "ooooo" << endl;
        MyFile << "PJ Position" << endl;
        MyFile << "1,1" << endl;
        MyFile << "--------------" << endl;
    }
    MyFile.close();
}

vector<string> split(string s, string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}
*/
