#ifndef MODENONCANONIQUE_H
#define MODENONCANONIQUE_H

/*!
 * \file modenoncanonique.h
 * \brief Set of functions for instant moving control in game
 * \author Christophe Ruiz
 * \version 2.4
 * \date 10 janvier 2019
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

/*!
 * \brief reset_input_mode resets input mode
 */
void reset_input_mode (void);
/*!
 * \brief set_input_mode sets input mode
 */
void set_input_mode (void);

#endif // MODENONCANONIQUE_H
