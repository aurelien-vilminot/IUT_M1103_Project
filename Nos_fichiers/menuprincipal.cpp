#include <iostream>

#include "menuprincipal.h"
#include "matrice.h"

using namespace std;

void MenuPrincipal(unsigned & NbManches)
{
    NbManches = 0;
    bool MenuOK = false;
    bool ChoixOK = true;
    unsigned Choix;

    while (!MenuOK)
    {
        ClearScreen();
        cout << endl << "----------------------- ACCUEIL -----------------------" << endl << endl;
        cout << "   1. Mode normal" << endl << endl;
        cout << "   2. Mode "<< KNbManches << " manches" << endl << endl;
        cout << "   3. Didactiel" << endl << endl << endl;

        if (!ChoixOK)
            cerr << "Veuillez faire un choix valide !" << endl << endl;

        cout << "Choix : ";
        cin >> Choix;

        if (cin.fail())
        {
            ChoixOK = false;
            cin.clear ();
            string Buf;
            getline (cin, Buf);
        }
        else
        {
            switch (Choix)
            {
            case 1:
                MenuOK = true;
                NbManches = 1;
                system("echo '\e]0;MODE NORMAL\a'");
                break;
            case 2:
                MenuOK = true;
                NbManches = KNbManches;
                system("echo '\e]0;MODE BATTLE\a'");
                break;
            case 3:
                MenuOK = true;
                NbManches = 0;
                system("echo '\e]0;DIDACTICIEL\a'");
                break;
            default:
                break;
            }
        }
    }
} //MenuPrincipal()
