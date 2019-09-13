#include <iostream>
#include <vector>

#include "matrice.h"
#include "jeu.h"
#include "troudever.h"
#include "deplacement.h"
#include "mur.h"
#include "boost.h"
#include "menutours.h"
#include "doubletour.h"
#include "menuprincipal.h"
#include "didacticiel.h"
#include "modenoncanonique.h"
#include "configuration.h"

using namespace std;

int Notreppal()
{
    if (!VerifFic(KFicConfig))
        cerr << "Erreur concernant le fichier de configuration" << endl << endl;
    else
    {
        unsigned NbColonnes = 9;
        unsigned NbLignes = 9;

        CPosition P1;
        CPosition P2;
        CPosition EmplacementPrecedent;

        CPosition TrouDeVerDecollage;
        CPosition TrouDeVerAtterrissage;

        CPosition DebutMur;
        CPosition FinMur;

        unsigned IndiceBoost;
        CPosition EmplacementBoost;

        unsigned DirectionBoostImposer;
        unsigned IndiceBoostImposer;
        CPosition EmplacementBoostImposer;

        CPosition PosDoubleTour;

        CMat TableJeu;
        char Deplacement;
        bool Victoire;
        bool VictoireP1;

        unsigned TourMinimum = 1;
        unsigned NbManches;
        bool ModeBattle;

        MenuPrincipal(NbManches);

        unsigned NbVic_P1 = 0;
        unsigned NbVic_P2 = 0;

        if (NbManches > 1)
            ModeBattle = true;
        else if (NbManches == 1)
            ModeBattle = false;

        if (NbManches != 0)
        {
            unsigned NbToursMax = 0;

            MenuNbTours(NbToursMax);

            unsigned NbCoups;

            bool Joueur = true;

            unsigned TourFinal;

            for (unsigned i = TourMinimum; i <= NbManches; i+=1)
            {
                set_input_mode();
                NbCoups = 0;

                P1.first = 0;
                P1.second = NbColonnes - 1;

                P2.first = NbLignes - 1;
                P2.second = 0;

                GenereTrouDeVer(P1, P2, TrouDeVerDecollage, TrouDeVerAtterrissage);
                GenereMur(P1, P2, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur);
                GenereBoost (P1, P2, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoost, IndiceBoost);
                GenereBoostImposer(P1, P2, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoost, DirectionBoostImposer, IndiceBoostImposer, EmplacementBoostImposer);
                GenereDoubleTour(P1, P2, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoost, EmplacementBoostImposer, PosDoubleTour);

                InitMat(TableJeu, NbLignes, NbColonnes, P1, P2, VictoireP1, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoost, EmplacementBoostImposer, PosDoubleTour);
                ShowMatrix(TableJeu, IndiceBoost, IndiceBoostImposer, DirectionBoostImposer, ModeBattle, i, NbManches, NbVic_P1, NbVic_P2);

                Victoire = false;
                VictoireP1 = false;

                while (!Victoire)
                {
                    if (Joueur)
                    {
                        EmplacementPrecedent = P1;
                        cout << endl << "Joueur 1 joue: " << endl;
                        while (EmplacementPrecedent == P1)
                        {
                            cin >> Deplacement;
                            NotreMoveToken(Deplacement, P1);
                        }

                        Troudever(P1, TrouDeVerDecollage, TrouDeVerAtterrissage);
                        Mur(P1, Deplacement, DebutMur, FinMur);
                        Boost(P1, Deplacement, EmplacementBoost, IndiceBoost, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoostImposer, IndiceBoostImposer, DirectionBoostImposer);
                        BoostImposer(P1, Deplacement, EmplacementBoost, IndiceBoost, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoostImposer, IndiceBoostImposer, DirectionBoostImposer);
                        DoubleTour(Joueur, P1, PosDoubleTour);
                    }
                    else
                    {
                        EmplacementPrecedent = P2;
                        cout << endl << "Joueur 2 joue: " << endl;
                        while (EmplacementPrecedent == P2)
                        {
                            cin >> Deplacement;
                            NotreMoveToken(Deplacement, P2);
                        }
                        Troudever(P2, TrouDeVerDecollage, TrouDeVerAtterrissage);
                        Mur(P2, Deplacement, DebutMur, FinMur);
                        Boost(P2, Deplacement, EmplacementBoost, IndiceBoost, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoostImposer, IndiceBoostImposer, DirectionBoostImposer);
                        BoostImposer(P2, Deplacement, EmplacementBoost, IndiceBoost, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoostImposer, IndiceBoostImposer, DirectionBoostImposer);
                        DoubleTour(Joueur, P2, PosDoubleTour);
                    }

                    InitMat(TableJeu, NbLignes, NbColonnes, P1, P2, VictoireP1, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoost, EmplacementBoostImposer, PosDoubleTour);
                    ShowMatrix(TableJeu, IndiceBoost, IndiceBoostImposer, DirectionBoostImposer, ModeBattle, i, NbManches, NbVic_P1, NbVic_P2);

                    NbCoups += 1;
                    Couleur(KCyan);
                    cout << "Tours restant: " << NbToursMax - NbCoups << endl;
                    Couleur(KReset);

                    if (!Joueur && P1 == P2)
                    {
                        VictoireP1 = true;
                        InitMat(TableJeu, NbLignes, NbColonnes, P1, P2, VictoireP1, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoost, EmplacementBoostImposer, PosDoubleTour);
                        ShowMatrix(TableJeu, IndiceBoost, IndiceBoostImposer, DirectionBoostImposer, ModeBattle, i, NbManches, NbVic_P1, NbVic_P2);
                        Couleur(KVert);
                        cout << "Joueur 1 GAGNE !" << endl;
                        Couleur(KReset);
                        Victoire = true;
                        NbVic_P1 += 1;
                        if (!ModeBattle)
                            goto End;
                    }
                    else if (Joueur && P1 == P2)
                    {
                        InitMat(TableJeu, NbLignes, NbColonnes, P1, P2, VictoireP1, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoost, EmplacementBoostImposer, PosDoubleTour);
                        ShowMatrix(TableJeu, IndiceBoost, IndiceBoostImposer, DirectionBoostImposer, ModeBattle, i, NbManches, NbVic_P1, NbVic_P2);
                        Couleur(KVert);
                        cout << "Joueur 2 GAGNE !" << endl;
                        Couleur(KReset);
                        Victoire = true;
                        NbVic_P2 += 1;
                        if (!ModeBattle)
                            goto End;
                    }

                    if (NbCoups == NbToursMax && !Victoire)
                    {
                        cout << "PLUS DE COUPS DISPONIBLES" << endl;
                        if (ModeBattle)
                        {
                            Couleur(KRouge);
                            NbManches += 1;
                            cout << "Une MANCHE a été ajoutée !" << endl;
                            Couleur(KReset);
                            break;
                        }
                        else if (!ModeBattle)
                        {
                            Couleur(KMagenta);
                            cout << "C'est un MATCH NUL !" << endl;
                            Couleur(KReset);
                            goto End;
                        }
                    }

                    if (NbVic_P1 + NbVic_P2 == NbManches && NbVic_P1 == NbVic_P2)
                    {
                        TourFinal = i;
                        goto Draw;
                    }

                    if ((NbVic_P1 > NbVic_P2 && NbVic_P2 + NbManches - (NbVic_P1 + NbVic_P2) < NbVic_P1) || (NbVic_P1 > NbVic_P2 && (NbVic_P1 + NbVic_P2) == NbManches))
                    {
                        TourFinal = i;
                        goto P1_Battle_Won;
                    }
                    else if ((NbVic_P2 > NbVic_P1 && NbVic_P1 + NbManches - (NbVic_P1 + NbVic_P2) < NbVic_P2) || (NbVic_P2 > NbVic_P1 && (NbVic_P1 + NbVic_P2) == NbManches))
                    {
                        TourFinal = i;
                        goto P2_Battle_Won;
                    }
                }
            }
    P1_Battle_Won :
            InitMat(TableJeu, NbLignes, NbColonnes, P1, P2, VictoireP1, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoost, EmplacementBoostImposer, PosDoubleTour);
            ShowMatrix(TableJeu, IndiceBoost, IndiceBoostImposer, DirectionBoostImposer, ModeBattle, TourFinal, NbManches, NbVic_P1, NbVic_P2);

            Couleur(KBleu);
            cout << endl << "Joueur 1 a battu Joueur 2 !" << endl;
            Couleur (KReset);
            return 0;

    P2_Battle_Won :
            InitMat(TableJeu, NbLignes, NbColonnes, P1, P2, VictoireP1, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoost, EmplacementBoostImposer, PosDoubleTour);
            ShowMatrix(TableJeu, IndiceBoost, IndiceBoostImposer, DirectionBoostImposer, ModeBattle, TourFinal, NbManches, NbVic_P1, NbVic_P2);

            Couleur(KBleu);
            cout << endl << "Joueur 2 a battu Joueur 1 !" << endl;
            Couleur (KReset);
            return 0;
    Draw:
            InitMat(TableJeu, NbLignes, NbColonnes, P1, P2, VictoireP1, TrouDeVerDecollage, TrouDeVerAtterrissage, DebutMur, FinMur, EmplacementBoost, EmplacementBoostImposer, PosDoubleTour);
            ShowMatrix(TableJeu, IndiceBoost, IndiceBoostImposer, DirectionBoostImposer, ModeBattle, TourFinal, NbManches, NbVic_P1, NbVic_P2);

            Couleur(KMagenta);
            cout << endl << "C'est un MATCH NUL" << endl;
            Couleur (KReset);
            return 0;
        }
        else if (NbManches == 0)
        {
            Didacticiel();
        }
    End:
        return 0;
    }
} //Notreppal()
