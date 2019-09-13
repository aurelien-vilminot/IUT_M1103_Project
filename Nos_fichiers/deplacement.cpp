#include <iostream>

#include "deplacement.h"

using namespace std;

void NotreMoveToken (const char Move, CPosition & PosPlayer)
{
    if (Move == KUp && PosPlayer.first != 0)
    {
        PosPlayer.first -= 1;
    }
    else if (Move == KLeft && PosPlayer.second != 0)
    {
        PosPlayer.second -= 1;
    }
    else if (Move == KDown && PosPlayer.first != 8)
    {
        PosPlayer.first += 1;
    }
    else if (Move == KRight && PosPlayer.second != 8)
    {
        PosPlayer.second += 1;
    }
    else if (Move == KUpLeft && PosPlayer.first != 0 && PosPlayer.second != 0)
    {
        PosPlayer.first -= 1;
        PosPlayer.second -= 1;
    }
    else if (Move == KUpRight && PosPlayer.first != 0 && PosPlayer.second != 8)
    {
        PosPlayer.first -= 1;
        PosPlayer.second += 1;
    }
    else if (Move == KDownLeft && PosPlayer.first != 8 && PosPlayer.second != 0)
    {
        PosPlayer.first += 1;
        PosPlayer.second -= 1;
    }
    else if (Move == KDownRight && PosPlayer.first != 8 && PosPlayer.second != 8)
    {
        PosPlayer.first += 1;
        PosPlayer.second += 1;
    }
} //NotreMoveToken()
