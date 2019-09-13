#ifndef MENUNBTOURS_H
#define MENUNBTOURS_H
/*!
 * \file menutours.h
 * \brief Set of useful functions for boost bonus in the game
 * \author Christophe Ruiz
 * \author Aurélien Vilminot
 * \version 1.5
 * \date 31 décembre 2018
 */

#include "configuration.h"

/*!
 * \brief MenuNbTours displays max move selection menu
 * \param[out] NbToursMax maximum move
 */
void MenuNbTours (unsigned & NbToursMax);

/*!
 * \brief ClearScreen clears the screen
 */
void ClearScreen();

const unsigned KNbTour1 = ParamUnsigned() ["Choix nombre de tours 1"];//!< laps number for first choice

const unsigned KNbTour2 = ParamUnsigned() ["Choix nombre de tours 2"];//!< laps number for second choice

const unsigned KNbTour3 = ParamUnsigned() ["Choix nombre de tours 3"];//!< laps number for third choice

#endif // MENUNBTOURS_H
