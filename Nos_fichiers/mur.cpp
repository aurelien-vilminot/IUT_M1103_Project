#include <iostream>
#include <cstdlib>
#include <ctime>

#include "mur.h"
#include "jeu.h"
#include "deplacement.h"

using namespace std;

void GenereMur (const CPosition & P1, const CPosition & P2, const CPosition & TrouDeVerDecollage, const CPosition & TrouDeVerAtterrissage, CPosition & DebutMur, CPosition & FinMur)
{

    DebutMur.first = rand() % 7 + 1;
    DebutMur.second = rand() % 6 + 1;
    FinMur.first = DebutMur.first;
    FinMur.second = rand() % 8;

    while (FinMur.second < DebutMur.second)
    {
        FinMur.second = rand() % 8;
    }

    while (DebutMur == TrouDeVerDecollage || DebutMur == TrouDeVerAtterrissage || FinMur == TrouDeVerDecollage || FinMur == TrouDeVerAtterrissage ||
           DebutMur == P1 || DebutMur == P2 || FinMur == P1 || FinMur == P2 ||
           ((DebutMur.second <= TrouDeVerDecollage.second) <= FinMur.second && DebutMur.first == TrouDeVerDecollage.first) ||
           ((DebutMur.second <= TrouDeVerAtterrissage.second) <= FinMur.second && DebutMur.first == TrouDeVerAtterrissage.first)) /* Vérifie qu'il n'y a pas de superposition entre les éléments */
    {
        DebutMur.first = rand() % 7 + 1;
        DebutMur.second = rand() % 6 + 1;
        FinMur.first = DebutMur.first;
        FinMur.second = rand() % 8;

        while (FinMur.second < DebutMur.second)
        {
            FinMur.second = rand() % 8;
        }
    }
} //GenereMur()

void Mur (CPosition & PosPlayer, const char & Deplacement, const CPosition & DebutMur, const CPosition & FinMur)
{
    if (PosPlayer.first >= DebutMur.first && PosPlayer.first <= FinMur.first && PosPlayer.second >= DebutMur.second && PosPlayer.second <= FinMur.second)
    {
        if (Deplacement == KUp)
            NotreMoveToken(KDown, PosPlayer);
        else if (Deplacement == KLeft)
            NotreMoveToken(KRight, PosPlayer);
        else if (Deplacement == KDown)
            NotreMoveToken(KUp, PosPlayer);
        else if (Deplacement == KRight)
            NotreMoveToken(KLeft, PosPlayer);
        else if (Deplacement == KUpLeft)
            NotreMoveToken(KDownRight, PosPlayer);
        else if (Deplacement == KUpRight)
            NotreMoveToken(KDownLeft, PosPlayer);
        else if (Deplacement == KDownLeft)
            NotreMoveToken(KUpRight, PosPlayer);
        else if (Deplacement == KDownRight)
            NotreMoveToken(KUpLeft, PosPlayer);
    }
} //Mur()
