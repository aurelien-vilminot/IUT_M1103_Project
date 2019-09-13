#ifndef DEPLACEMENTS_H
#define DEPLACEMENTS_H

/*!
 * \file deplacement.h
 * \brief Set of useful functions for movement in game
 * \author Aurélien Vilminot
 * \version 1.0
 * \date 08 janvier 2019
 */

#include "../Correc_Prof/type.h"
#include "configuration.h"

/*! \brief NotreMoveToken Modifies player's position coordinates according to the movement chosen
 *  \param[in] Move player's move input
 *  \param[in, out] Pos player's position before and after applying movement
 */
void NotreMoveToken (const char Move, CPosition & Pos);

const char KUp (ParamChar() ["KeyUp"]);//!< up key value

const char KLeft (ParamChar() ["KeyLeft"]);//!< left key value

const char KRight (ParamChar() ["KeyRight"]);//!< right key value

const char KDown (ParamChar() ["KeyDown"]);//!< down key value

const char KUpLeft (ParamChar() ["KeyUpLeft"]);//!< upper left key value

const char KUpRight (ParamChar() ["KeyUpRight"]);//!< upper right key value

const char KDownLeft (ParamChar() ["KeyDownLeft"]);//!< down left key value

const char KDownRight (ParamChar() ["KeyDownRight"]);//!< down right key value


#endif // DEPLACEMENTS_H
