/*!
 * \file main.cpp
 * \brief Game launcher
 * \author Aurélien Vilminot
 * \author Christophe Ruiz
 * \author Anthony Ziane
 * \author Vincent Thouvenel
 * \version 1.0
 * \date 27 décembre 2018
 */


#include <iostream>
#include "Nos_fichiers/jeu.h"

using namespace std;

/**
 * @brief Launches the game's main function.
 * @return Returns 0 if everything is OK, 1 if there is an error.
 */
int main()
{
    try
    {
        return Notreppal();
    }
    catch (...)
    {
        cerr << "ca s'est mal passe quelque part" << endl;
        return 1;
    }
} //main ()
