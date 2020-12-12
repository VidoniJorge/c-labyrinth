#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    Player();

    void callInput();
    void resetToSafePosition();

    int getAxisX();
    int getAxisY();

protected:
private:
    int axisX, axisY, lastAxisX, lastAxisY;
    void saveLastPosition();
};
#endif