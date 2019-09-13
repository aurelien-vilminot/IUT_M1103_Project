#ifndef MUR_H
#define MUR_H

/*!
 * \file mur.h
 * \brief Set of functions to create the wall in game
 * \author Christophe Ruiz
 * \version 1.2
 * \date 27 décembre 2018
 */

#include "../Correc_Prof/type.h"

/*!
 * \brief GenereMur generates wall position
 * \param[in] P1 player one position
 * \param[in] P2 player two position
 * \param[in] TrouDeVerDecollage wormhole start position
 * \param[in] TrouDeVerAtterrissage wormhole arrival position
 * \param[in, out] DebutMur wall start
 * \param[in, out] FinMur wall end
 */
void GenereMur (const CPosition & P1, const CPosition & P2, const CPosition & TrouDeVerDecollage, const CPosition & TrouDeVerAtterrissage, CPosition & DebutMur, CPosition & FinMur);

/*!
 * \brief Mur makes the wall functionnal
 * \param[out] PosPlayer players position
 * \param[in] Deplacement players move
 * \param[in] DebutMur wall start
 * \param[in] FinMur wall end
 */
void Mur (CPosition & PosPlayer, const char & Deplacement, const CPosition & DebutMur, const CPosition & FinMur);

#endif // MUR_H
