#include <iostream>
#include <cstdlib>
#include <ctime>

#include "deplacement.h"
#include "mur.h"
#include "troudever.h"
#include "boost.h"

using namespace std;


void GenereBoost (const CPosition & P1, const CPosition & P2, const CPosition & TrouDeVerDecollage, const CPosition & TrouDeVerAtterrissage, const CPosition & DebutMur, const CPosition & FinMur,
                  CPosition & EmplacementBoost, unsigned & IndiceBoost)
{
    srand(time(NULL));

    IndiceBoost = rand() % 3 + 1;

    switch (IndiceBoost)
    {
    case 1:
        EmplacementBoost.first = rand() % 7+ 1;
        EmplacementBoost.second = rand() % 7 + 1;
        break;
    case 2:
        EmplacementBoost.first = rand() % 5 + 2;
        EmplacementBoost.second = rand() % 5 + 2;
        break;
    case 3:
        EmplacementBoost.first = rand() % 3 + 3;
        EmplacementBoost.second = rand() % 3 + 3;
        break;
    default: break;
    }

    while (EmplacementBoost == TrouDeVerDecollage || EmplacementBoost == TrouDeVerAtterrissage || EmplacementBoost == DebutMur || EmplacementBoost == FinMur || EmplacementBoost == P1 || EmplacementBoost == P2 ||
           (EmplacementBoost.first == DebutMur.first && (DebutMur.second <= EmplacementBoost.second) <= FinMur.second))
    {
        switch (IndiceBoost)
        {
        case 1:
            EmplacementBoost.first = rand() % 7+ 1;
            EmplacementBoost.second = rand() % 7 + 1;
            break;
        case 2:
            EmplacementBoost.first = rand() % 5 + 2;
            EmplacementBoost.second = rand() % 5 + 2;
            break;
        case 3:
            EmplacementBoost.first = rand() % 3 + 3;
            EmplacementBoost.second = rand() % 3 + 3;
            break;
        default: break;
        }
    }
} //GenereBoost()

void GenereBoostImposer (const CPosition & P1, const CPosition & P2, const CPosition & TrouDeVerDecollage, const CPosition & TrouDeVerAtterrissage, const CPosition & DebutMur, const CPosition & FinMur,
                         const CPosition & EmplacementBoost, unsigned & DirectionBoostImposer, unsigned & IndiceBoostImposer, CPosition & EmplacementBoostImposer)
{
    srand(time(NULL));

    DirectionBoostImposer = rand() % 4 + 1;

    IndiceBoostImposer = rand() % 3 + 1;

    switch (IndiceBoostImposer)
    {
    case 1:
        EmplacementBoostImposer.first = rand() % 7+ 1;
        EmplacementBoostImposer.second = rand() % 7 + 1;
        break;
    case 2:
        EmplacementBoostImposer.first = rand() % 5 + 2;
        EmplacementBoostImposer.second = rand() % 5 + 2;
        break;
    case 3:
        EmplacementBoostImposer.first = rand() % 3 + 3;
        EmplacementBoostImposer.second = rand() % 3 + 3;
        break;
    default: break;
    }

    while (EmplacementBoostImposer == TrouDeVerDecollage || EmplacementBoostImposer == TrouDeVerAtterrissage || EmplacementBoostImposer == DebutMur || EmplacementBoostImposer == FinMur ||
           EmplacementBoostImposer == P1 || EmplacementBoostImposer == P2 || EmplacementBoostImposer == EmplacementBoost ||
           (EmplacementBoostImposer.first == DebutMur.first && (DebutMur.second <= EmplacementBoostImposer.second) <= FinMur.second))
    {
        switch (IndiceBoostImposer)
        {
        case 1:
            EmplacementBoostImposer.first = rand() % 7+ 1;
            EmplacementBoostImposer.second = rand() % 7 + 1;
            break;
        case 2:
            EmplacementBoostImposer.first = rand() % 5 + 2;
            EmplacementBoostImposer.second = rand() % 5 + 2;
            break;
        case 3:
            EmplacementBoostImposer.first = rand() % 3 + 3;
            EmplacementBoostImposer.second = rand() % 3 + 3;
            break;
        default: break;
        }
    }
} //GenereBoostImposer()

void Boost(CPosition & PosPlayer, const char & Deplacement, const CPosition & EmplacementBoost, const unsigned & IndiceBoost, const CPosition & TrouDeVerDecollage,
           const CPosition & TrouDeVerAtterrissage, const CPosition & DebutMur, const CPosition & FinMur, const CPosition & EmplacementBoostImposer, const unsigned & IndiceBoostImposer,
           const unsigned & DirectionBoostImposer)
{
    if (PosPlayer == EmplacementBoost)
    {
        if (Deplacement == KUp)
        {
            for (unsigned i = 1; i <= IndiceBoost; ++i)
            {
                NotreMoveToken(KUp, PosPlayer);
                Troudever(PosPlayer, TrouDeVerDecollage, TrouDeVerAtterrissage);
                Mur(PosPlayer, Deplacement, DebutMur, FinMur);
                BoostImposer(PosPlayer, Deplacement, EmplacementBoost, IndiceBoost, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoostImposer, IndiceBoostImposer, DirectionBoostImposer);
                if (PosPlayer == EmplacementBoost)
                    NotreMoveToken(KDown, PosPlayer);
            }
        }
        else if (Deplacement == KLeft)
        {
            for (unsigned i = 1; i <= IndiceBoost; ++i)
            {
                NotreMoveToken(KLeft, PosPlayer);
                Troudever(PosPlayer, TrouDeVerDecollage, TrouDeVerAtterrissage);
                Mur(PosPlayer, Deplacement, DebutMur, FinMur);
                BoostImposer(PosPlayer, Deplacement, EmplacementBoost, IndiceBoost, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoostImposer, IndiceBoostImposer, DirectionBoostImposer);
                if (PosPlayer == EmplacementBoost)
                    NotreMoveToken(KDown, PosPlayer);
            }
        }
        else if (Deplacement == KDown)
        {
            for (unsigned i = 1; i <= IndiceBoost; ++i)
            {
                NotreMoveToken(KDown, PosPlayer);
                Troudever(PosPlayer, TrouDeVerDecollage, TrouDeVerAtterrissage);
                Mur(PosPlayer, Deplacement, DebutMur, FinMur);
                BoostImposer(PosPlayer, Deplacement, EmplacementBoost, IndiceBoost, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoostImposer, IndiceBoostImposer, DirectionBoostImposer);
                if (PosPlayer == EmplacementBoost)
                    NotreMoveToken(KUp, PosPlayer);
            }
        }
        else if (Deplacement == KRight)
        {
            for (unsigned i = 1; i <= IndiceBoost; ++i)
            {
                NotreMoveToken(KRight, PosPlayer);
                Troudever(PosPlayer, TrouDeVerDecollage, TrouDeVerAtterrissage);
                Mur(PosPlayer, Deplacement, DebutMur, FinMur);
                BoostImposer(PosPlayer, Deplacement, EmplacementBoost, IndiceBoost, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoostImposer, IndiceBoostImposer, DirectionBoostImposer);
                if (PosPlayer == EmplacementBoost)
                    NotreMoveToken(KLeft, PosPlayer);
            }
        }
        else if (Deplacement == KUpLeft)
        {
            for (unsigned i = 1; i <= IndiceBoost; ++i)
            {
                NotreMoveToken(KUpLeft, PosPlayer);
                Troudever(PosPlayer, TrouDeVerDecollage, TrouDeVerAtterrissage);
                Mur(PosPlayer, Deplacement, DebutMur, FinMur);
                BoostImposer(PosPlayer, Deplacement, EmplacementBoost, IndiceBoost, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoostImposer, IndiceBoostImposer, DirectionBoostImposer);
                if (PosPlayer == EmplacementBoost)
                    NotreMoveToken(KDownRight, PosPlayer);
            }
        }
        else if (Deplacement == KUpRight)
        {
            for (unsigned i = 1; i <= IndiceBoost; ++i)
            {
                NotreMoveToken(KUpRight, PosPlayer);
                Troudever(PosPlayer, TrouDeVerDecollage, TrouDeVerAtterrissage);
                Mur(PosPlayer, Deplacement, DebutMur, FinMur);
                BoostImposer(PosPlayer, Deplacement, EmplacementBoost, IndiceBoost, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoostImposer, IndiceBoostImposer, DirectionBoostImposer);
                if (PosPlayer == EmplacementBoost)
                    NotreMoveToken(KDownLeft, PosPlayer);
            }
        }
        else if (Deplacement == KDownLeft)
        {
            for (unsigned i = 1; i <= IndiceBoost; ++i)
            {
                NotreMoveToken(KDownLeft, PosPlayer);
                Troudever(PosPlayer, TrouDeVerDecollage, TrouDeVerAtterrissage);
                Mur(PosPlayer, Deplacement, DebutMur, FinMur);
                BoostImposer(PosPlayer, Deplacement, EmplacementBoost, IndiceBoost, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoostImposer, IndiceBoostImposer, DirectionBoostImposer);
                if (PosPlayer == EmplacementBoost)
                    NotreMoveToken(KUpRight, PosPlayer);
            }
        }
        else if (Deplacement == KDownRight)
        {
            for (unsigned i = 1; i <= IndiceBoost; ++i)
            {
                NotreMoveToken(KDownRight, PosPlayer);
                Troudever(PosPlayer, TrouDeVerDecollage, TrouDeVerAtterrissage);
                Mur(PosPlayer, Deplacement, DebutMur, FinMur);
                BoostImposer(PosPlayer, Deplacement, EmplacementBoost, IndiceBoost, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoostImposer, IndiceBoostImposer, DirectionBoostImposer);
                if (PosPlayer == EmplacementBoost)
                    NotreMoveToken(KUpLeft, PosPlayer);
            }
        }
    }
} //Boost()

void BoostImposer(CPosition & PosPlayer, const char & Deplacement, const CPosition & EmplacementBoost, const unsigned & IndiceBoost, const CPosition & TrouDeVerDecollage,
                  const CPosition & TrouDeVerAtterrissage, const CPosition & DebutMur, const CPosition & FinMur, const CPosition & EmplacementBoostImposer, const unsigned & IndiceBoostImposer,
                  const unsigned & DirectionBoostImposer)
{
    if (PosPlayer == EmplacementBoostImposer)
    {
        switch (DirectionBoostImposer)
        {
        case 1:
            for (unsigned i = 1; i <= IndiceBoostImposer; ++i)
            {
                NotreMoveToken(KUp, PosPlayer);
                Troudever(PosPlayer, TrouDeVerDecollage, TrouDeVerAtterrissage);
                Mur(PosPlayer, Deplacement, DebutMur, FinMur);
                Boost(PosPlayer, Deplacement, EmplacementBoost, IndiceBoost, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoostImposer, IndiceBoostImposer, DirectionBoostImposer);
                if (PosPlayer == EmplacementBoost)
                    NotreMoveToken(KDown, PosPlayer);
            }
            break;
        case 2:
            for (unsigned i = 1; i <= IndiceBoostImposer; ++i)
            {
                NotreMoveToken(KDown, PosPlayer);
                Troudever(PosPlayer, TrouDeVerDecollage, TrouDeVerAtterrissage);
                Mur(PosPlayer, Deplacement, DebutMur, FinMur);
                Boost(PosPlayer, Deplacement, EmplacementBoost, IndiceBoost, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoostImposer, IndiceBoostImposer, DirectionBoostImposer);
                if (PosPlayer == EmplacementBoost)
                    NotreMoveToken(KUp, PosPlayer);
            }
            break;
        case 3:
            for (unsigned i = 1; i <= IndiceBoostImposer; ++i)
            {
                NotreMoveToken(KRight, PosPlayer);
                Troudever(PosPlayer, TrouDeVerDecollage, TrouDeVerAtterrissage);
                Mur(PosPlayer, Deplacement, DebutMur, FinMur);
                Boost(PosPlayer, Deplacement, EmplacementBoost, IndiceBoost, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoostImposer, IndiceBoostImposer, DirectionBoostImposer);
                if (PosPlayer == EmplacementBoost)
                    NotreMoveToken(KLeft, PosPlayer);
            }
            break;
        case 4:
            for (unsigned i = 1; i <= IndiceBoostImposer; ++i)
            {
                NotreMoveToken(KLeft, PosPlayer);
                Troudever(PosPlayer, TrouDeVerDecollage, TrouDeVerAtterrissage);
                Mur(PosPlayer, Deplacement, DebutMur, FinMur);
                Boost(PosPlayer, Deplacement, EmplacementBoost, IndiceBoost, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoostImposer, IndiceBoostImposer, DirectionBoostImposer);
                if (PosPlayer == EmplacementBoost)
                    NotreMoveToken(KRight, PosPlayer);
            }
            break;
        default:
            break;
        }
    }
} //BoostImposer()
