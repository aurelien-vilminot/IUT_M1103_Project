#include <iostream>
#include <cstdlib>
#include <ctime>

#include "menutours.h"

using namespace std;

void MenuNbTours (unsigned & NbToursMax)
{
    while (NbToursMax == 0)
    {
        ClearScreen();
        cout << endl << " ----------------------- MENU -----------------------" << endl << endl;
        cout << "   1. " << KNbTour1 << " Tours" << endl << endl;
        cout << "   2. " << KNbTour2 << " Tours" << endl << endl;
        cout << "   3. " << KNbTour3 << " Tours" << endl << endl;
        cout << "   4. Surpise !" << endl << endl << endl;

        unsigned Choix;
        cout << "Choix : ";
        cin >> Choix;

        if (cin.fail())
        {
            cout << "Echec";
            cin.clear ();
            string Buf;
            getline (cin, Buf);
        }
        else
        {
            switch (Choix)
            {
            case 1:
                NbToursMax = KNbTour1;
                break;
            case 2:
                NbToursMax = KNbTour2;
                break;
            case 3:
                NbToursMax = KNbTour3;
                break;
            case 4:
                srand(time(NULL));
                NbToursMax = (rand() % 3 + 1) * 10;
                break;
            default:
                break;
            }
        }
    }
} //MenuNbTours()
