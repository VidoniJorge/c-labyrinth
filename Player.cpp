#include <iostream>
#include "Player.h"

using namespace std;

Player::Player()
{
    axisX = 1;
    axisY = 1;
}

void Player::saveLastPosition()
{
    lastAxisX = axisX;
    lastAxisY = axisY;
}

void Player::callInput()
{
    char input = getchar();

    saveLastPosition();

    switch (input)
    {
    case 'd':
        axisX++;
        break;
    case 'a':
        axisX--;
        break;
    case 'w':
        axisY--;
        break;
    case 's':
        axisY++;
        break;
    default:
        break;
    }
}

int Player::getAxisX()
{
    return axisX;
}
int Player::getAxisY()
{
    return axisY;
}

void Player::resetToSafePosition()
{
    axisX = lastAxisX;
    axisY = lastAxisY;
}
//g++ hello-world.cpp Player.cpp -o main