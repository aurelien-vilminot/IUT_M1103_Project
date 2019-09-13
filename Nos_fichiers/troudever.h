#ifndef TROUDEVER_H
#define TROUDEVER_H
/*!
 * \file troudever.h
 * \brief Set of useful functions for the wormhole bonus in game
 * \author Aurélien Vilminot
 * \version 1.1
 * \date 27 décembre 2018
 */

#include "../Correc_Prof/type.h"

/*!
 * \brief GenereTrouDeVer generates wormhole bonus
 * \param[in] P1 player one position
 * \param[in] P2 player two position
 * \param[out] TrouDeVerDecollage wormhole start position
 * \param[out] TrouDeVerAtterrissage wormhole end position
 */
void GenereTrouDeVer (const CPosition & P1, const CPosition & P2, CPosition & TrouDeVerDecollage, CPosition & TrouDeVerAtterrissage);

/*!
 * \brief Troudever makes the wormhole bonus functionnal
 * \param[in, out] PosPlayer player position at end of the wormhole
 * \param[in] TrouDeVerDecollage wormhole start
 * \param[in] TrouDeVerAtterrissage wormhole end
 */
void Troudever (CPosition & PosPlayer, const CPosition & TrouDeVerDecollage, const CPosition & TrouDeVerAtterrissage);

#endif // TROUDEVER_H
