#include <iostream>
#include "didacticiel.h"
#include "matrice.h"

using namespace std;

void Didacticiel ()
{
    ClearScreen();
    cout << endl << "----------------------- DIDACTICIEL -----------------------" << endl << endl
         << "Heureux de vous accueillir dans notre divertissante création ! Avant de pouvoir profiter de ce PacMan simplifié, un didacticiel est fortement conseillé afin de connaître les bases."
         << endl << "La simplicité est une notion commune à notre groupe, c’est pourquoi l’explication des commandes et de l’environnement sont simples à comprendre !" << endl << endl
         << "                            C O M M A N D E S" << endl << endl
         << "     Appuyer sur la touche z pour monter" << endl << endl
         << "     Appuyer sur la touche s pour descendre"  << endl << endl
         << "     Appuyer sur la touche q pour aller à gauche" << endl << endl
         << "     Appuyer sur la touche d pour aller à droite" << endl << endl
         << "     Appuyer sur la touche a pour monter et aller à gauche" << endl << endl
         << "     Appuyer sur la touche e pour monter et aller à droite" << endl << endl
         << "     Appuyer sur la touche c  pour descendre et aller à droite" << endl << endl
         << "     Appuyer sur la touche w pour descendre et aller à gauche" << endl << endl << endl
         << "                        E N V I R O N N E M E N T" << endl << endl
         << "Sur votre chemin vous rencontrerez quelques bonus et obstacles :" << endl << endl
         << "   L E S   T R O U S   D E   V E R " << endl << endl
         << "Représentés par ";
    Couleur (KVert);
    cout << KTokenTrouDeVerDecollage;
    Couleur (KReset);
    cout << endl
         << "Ils vous permettent de vous téléporter d’un trou de ver à un autre instantanément !" << endl << endl
         << "Utilisez les judicieusement pour piéger votre adversaire" << endl << endl << endl << endl
         << "   L E S   M U R S " << endl << endl
         << "Représentés par ";
    Couleur("40");
    Couleur (KRouge);
    cout << KTokenMur << KTokenMur;
    Couleur(KReset);
    cout << endl
         << "Ce sont des obstacles infranchissables, il fallait bien vous compliquer la tâche ;)" << endl << endl << endl << endl
         << "   L E S   B O O S T S" << endl << endl
         << "- Les boosts classiques :" << endl
         << "Représentés par ";
    Couleur("43");
    Couleur (KMagenta);
    cout << KTokenBoost
         << '1';
    Couleur (KReset);
    cout << endl
         << "Ce bonus vous permet de sauter le nombre de case indiqué, faite attention à votre point d’arrivé !" << endl << endl
         << "- Les boosts orientés :" << endl
         << "Représentés par ";
    Couleur("43");
    Couleur (KMagenta);
    cout << '2'
         << KTokenBoostImposerUp;
    Couleur (KReset);
    cout << endl
         << "Ce bonus vous permet de sauter le nombre de case indiqué dans la direction indiquée, encore une fois : attention au point d’arrivé !" << endl << endl << endl << endl
         << "   L A   C A S E   D O U B L E   T O U R" << endl << endl
         << "Représenté par la case ";
    Couleur("46");
    Couleur (KRouge);
    cout << KTokenDoubleTour;
    cout << '2';
    Couleur (KReset);
    cout << endl
         << "Cette case vous permet de gagner un tour de jeu supplémentaire, utile pour gagner un peu d’avance sur votre adversaire" << endl << endl << endl
         << "Bonne aventure !" << endl;
} //Didacticiel()
