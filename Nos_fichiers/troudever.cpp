#include <iostream>
#include <cstdlib>
#include <ctime>

#include "troudever.h"

using namespace std;

void GenereTrouDeVer (const CPosition & P1, const CPosition & P2, CPosition & TrouDeVerDecollage, CPosition & TrouDeVerAtterrissage)
{
    srand (time(NULL));

    TrouDeVerDecollage.first = rand() % 8 + 0;
    TrouDeVerDecollage.second = rand() % 8 + 0;
    TrouDeVerAtterrissage.first = rand() % 8 + 0;
    TrouDeVerAtterrissage.second = rand() % 8 + 0;

    while (TrouDeVerDecollage == TrouDeVerAtterrissage || TrouDeVerDecollage == P1 || TrouDeVerAtterrissage == P1 || TrouDeVerDecollage == P2 || TrouDeVerAtterrissage == P2)
    {
        TrouDeVerDecollage.first = rand() % 8 + 0;
        TrouDeVerDecollage.second = rand() % 8 + 0;
        TrouDeVerAtterrissage.first = rand() % 8 + 0;
        TrouDeVerAtterrissage.second = rand() % 8 + 0;
    }
} //GenereTrouDeVer()

void Troudever (CPosition & PosPlayer, const CPosition & TrouDeVerDecollage, const CPosition & TrouDeVerAtterrissage)
{
    if (PosPlayer == TrouDeVerDecollage)
    {
        PosPlayer = TrouDeVerAtterrissage;
    }
    else if (PosPlayer == TrouDeVerAtterrissage)
    {
        PosPlayer = TrouDeVerDecollage;
    }
} //Troudever()
