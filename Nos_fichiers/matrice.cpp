#include <iostream>

#include "matrice.h"

using namespace std;

void Couleur (const string & coul)
{
    cout << "\033[" << coul <<"m";
} //Couleur()

void InitMat (CMat & Mat,
              const unsigned NbLine,
              const unsigned NbColumn,
              const CPosition & PosPlayer1,
              const CPosition & PosPlayer2,
              const bool & VictoireP1,
              const CPosition & TrouDeVerDecollage,
              const CPosition & TrouDeVerAtterrissage,
              const CPosition & DebutMur,
              const CPosition & FinMur,
              const CPosition & EmplacementBoost,
              const CPosition & EmplacementBoostImposer,
              const CPosition & PosDoubleTour)
{
    Mat.resize(NbLine);

    for (unsigned cpt = 0; cpt <= Mat.size() - 1 ; ++cpt)
    {
        Mat[cpt].resize(NbColumn);
    }

    for (unsigned i = 0; i <= Mat.size() -1; ++i)
    {
        for (unsigned j = 0; j <= Mat[i].size() -1; ++j)
        {
            Mat[i][j] = KEmpty;
        }
    }

    Mat[PosPlayer1.first][PosPlayer1.second] = KTokenPlayer1;
    Mat[PosPlayer2.first][PosPlayer2.second] = KTokenPlayer2;

    if (PosPlayer1 == PosPlayer2 && VictoireP1 == true)
    {
        Mat[PosPlayer2.first][PosPlayer2.second] = KTokenPlayer1;
    }

    Mat[TrouDeVerDecollage.first][TrouDeVerDecollage.second] = KTokenTrouDeVerDecollage;
    Mat[TrouDeVerAtterrissage.first][TrouDeVerAtterrissage.second] = KTokenTrouDeVerAtterrissage;

    if (PosPlayer1 == TrouDeVerDecollage)
    {
        Mat[TrouDeVerDecollage.first][TrouDeVerDecollage.second] = KTokenPlayer1;
    }

    if (PosPlayer1 == TrouDeVerAtterrissage)
    {
        Mat[TrouDeVerAtterrissage.first][TrouDeVerAtterrissage.second] = KTokenPlayer1;
    }

    if (PosPlayer2 == TrouDeVerDecollage)
    {
        Mat[TrouDeVerDecollage.first][TrouDeVerDecollage.second] = KTokenPlayer2;
    }

    if (PosPlayer2 == TrouDeVerAtterrissage)
    {
        Mat[TrouDeVerAtterrissage.first][TrouDeVerAtterrissage.second] = KTokenPlayer2;
    }

    Mat[DebutMur.first][DebutMur.second] = KTokenMur;
    Mat[FinMur.first][FinMur.second] = KTokenMur;

    Mat[EmplacementBoost.first][EmplacementBoost.second] = KTokenBoost;

    Mat[EmplacementBoostImposer.first][EmplacementBoostImposer.second] = KTokenBoostImposer;

    Mat[PosDoubleTour.first][PosDoubleTour.second] = KTokenDoubleTour;

    if (PosPlayer1 == PosDoubleTour)
    {
        Mat[PosDoubleTour.first][PosDoubleTour.second] = KTokenPlayer1;
    }

    if (PosPlayer2 == PosDoubleTour)
    {
        Mat[PosDoubleTour.first][PosDoubleTour.second] = KTokenPlayer2;
    }

    for (unsigned IndiceLigne = 0; IndiceLigne <= Mat.size(); ++IndiceLigne)
    {
        for (unsigned IndiceColonne = 0; IndiceColonne <= Mat.size(); ++IndiceColonne)
        {
            if (IndiceLigne == DebutMur.first && IndiceColonne > DebutMur.second && IndiceColonne < FinMur.second )
            {
                Mat[IndiceLigne][IndiceColonne] = KTokenMur;
            }
        }
    }
} //InitMat()

void ShowMatrix (const CMat & Mat,
                 const unsigned & IndiceBoost,
                 const unsigned & IndiceBoostImposer,
                 const unsigned DirectionBoostImposer,
                 const bool & Mode,
                 const unsigned & TourActuel,
                 const unsigned & NbManches,
                 const unsigned & NbVic_P1,
                 const unsigned & NbVic_P2)
{
    ClearScreen ();
    Couleur(KReset);

    if (Mode)
        cout << endl <<
                "-  M O D E   B A T T L E  -" << endl <<
                "-    M A N C H E   " << TourActuel << "/" << NbManches << "    -" << endl << endl;
    else
        cout << endl <<
                "-M O D E   C L A S S I Q U E-" << endl << endl;

    for (unsigned i = 0; i <= Mat.size() -1; ++i)
    {
        for (unsigned Cpt = 0; Cpt <= Mat[i].size() -1; ++Cpt)
        {
            cout << "---";
        }
        cout << endl;
        for (unsigned j = 0; j <= Mat[i].size(); ++j)
        {
            if (Mat[i][j] == KEmpty)
            {
                cout << "  |";
            }
            else if(Mat[i][j] == KTokenPlayer1)
            {
                cout << " " ;
                Couleur (KBleu);
                cout << KTokenPlayer1;
                Couleur (KReset);
                cout << "|";
            }
            else if(Mat[i][j] == KTokenPlayer2)
            {
                cout << " ";
                Couleur (KRouge);
                cout << KTokenPlayer2;
                Couleur (KReset);
                cout << "|";
            }
            else if(Mat[i][j] == KTokenTrouDeVerDecollage)
            {
                cout << " ";
                Couleur (KVert);
                cout << KTokenTrouDeVerDecollage;
                Couleur (KReset);
                cout << "|";
            }
            else if(Mat[i][j] == KTokenTrouDeVerAtterrissage)
            {
                cout << " ";
                Couleur (KVert);
                cout << KTokenTrouDeVerAtterrissage;
                Couleur (KReset);
                cout << "|";
            }
            else if(Mat[i][j] == KTokenMur)
            {
                Couleur("40");
                Couleur (KRouge);
                cout << KTokenMur;
                cout << KTokenMur;
                Couleur (KReset);
                cout << "|";
            }
            else if(Mat[i][j] == KTokenBoost)
            {
                Couleur("43");
                Couleur (KMagenta);
                cout << KTokenBoost;
                cout << IndiceBoost;
                Couleur (KReset);
                cout << "|";
            }
            else if(Mat[i][j] == KTokenBoostImposer)
            {
                switch (DirectionBoostImposer)
                {
                case 1:
                    Couleur("43");
                    Couleur (KMagenta);
                    cout << IndiceBoostImposer;
                    cout << KTokenBoostImposerUp;
                    Couleur (KReset);
                    cout << "|";
                    break;
                case 2:
                    Couleur("43");
                    Couleur (KMagenta);
                    cout << IndiceBoostImposer;
                    cout << KTokenBoostImposerDown;
                    Couleur (KReset);
                    cout << "|";
                    break;
                case 3:
                    Couleur("43");
                    Couleur (KMagenta);
                    cout << IndiceBoostImposer;
                    cout << KTokenBoostImposerRight;
                    Couleur (KReset);
                    cout << "|";
                    break;
                case 4:
                    Couleur("43");
                    Couleur (KMagenta);
                    cout << KTokenBoostImposerLeft;
                    cout << IndiceBoostImposer;
                    Couleur (KReset);
                    cout << "|";
                    break;
                default:
                    break;
                }
            }
            else if(Mat[i][j] == KTokenDoubleTour)
            {
                Couleur("46");
                Couleur (KRouge);
                cout << KTokenDoubleTour;
                cout << '2';
                Couleur (KReset);
                cout << "|";
            }
        }
        cout << endl;
    }
    for (unsigned Cpt = 0; Cpt <= Mat[Mat.size() -1].size() -1; ++Cpt)
    {
        cout << "---";
    }
    cout << endl;

    if (Mode)
        cout << "VICTOIRES" << endl << " - " << NbVic_P1 << ":" << NbVic_P2 << " -" << endl << endl ;
} //ShowMatrix()
