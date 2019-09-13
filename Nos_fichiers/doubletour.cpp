#include <iostream>
#include <cstdlib>
#include <ctime>

#include "doubletour.h"

using namespace std;

void GenereDoubleTour (const CPosition & P1, const CPosition & P2, const CPosition & TrouDeVerDecollage, const CPosition & TrouDeVerAtterrissage, const CPosition & DebutMur, const CPosition & FinMur,
                       const CPosition & EmplacementBoost, const CPosition & EmplacementBoostImposer, CPosition & PosDoubleTour)
{
    srand(time(NULL));

    PosDoubleTour.first = rand() % 8 + 0;
    PosDoubleTour.second = rand() % 8 + 0;

    while (PosDoubleTour == P1 || PosDoubleTour == P2 || PosDoubleTour == TrouDeVerDecollage || PosDoubleTour == TrouDeVerAtterrissage || PosDoubleTour == DebutMur || PosDoubleTour == FinMur ||
           PosDoubleTour == EmplacementBoost || PosDoubleTour == EmplacementBoostImposer || (PosDoubleTour.first == DebutMur.first && (DebutMur.second <= PosDoubleTour.second) <= FinMur.second))
    {
        PosDoubleTour.first = rand() % 8 + 0;
        PosDoubleTour.second = rand() % 8 + 0;
    }
} //GenereDoubleTour()

void DoubleTour(bool & Joueur, const CPosition & PosPlayer, const CPosition & PosDoubleTour)
{
    if (PosPlayer == PosDoubleTour)
    {
        Joueur = Joueur;
    }
    else
    {
        Joueur = !Joueur;
    }
} //DoubleTour()
