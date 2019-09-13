#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H
/*!
 * \file menuprincipal.h
 * \brief Set of useful functions for game mode choice
 * \author Anthony Ziane
 * \author Vincent Thouvenel
 * \version 2.2
 * \date 08 janvier 2019
 */

#include "configuration.h"


/*!
 * \brief MenuPrincipal calls main menu and assigns maximum rounds number
 * \param[out] NbManches max round number
 */
void MenuPrincipal(unsigned & NbManches);

const unsigned KNbManches = ParamUnsigned() ["Nombre de manches en mode battle"];//!< rounds number

#endif // MENUPRINCIPAL_H
