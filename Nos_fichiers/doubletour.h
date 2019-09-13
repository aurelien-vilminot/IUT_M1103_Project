#ifndef DOUBLETOUR_H
#define DOUBLETOUR_H
/*!
 * \file doubletour.h
 * \brief Set of useful functions for in-game doubleplay bonus
 * \author Aurélien Vilminot
 * \version 1.6
 * \date 02 janvier 2019
 */

#include "../Correc_Prof/type.h"

/*!
 * \brief GenereDoubleTour generates doubleplay bonus
 * \param[in] P1 player one position
 * \param[in] P2 player two position
 * \param[in] TrouDeVerDecollage wormhole's first door position
 * \param[in] TrouDeVerAtterrissage wormhole's second door position
 * \param[in] DebutMur wall first position
 * \param[in] FinMur wall second position
 * \param[in] EmplacementBoost boost bonus position
 * \param[in] EmplacementBoostImposer directional boost imposer
 * \param[out] PosDoubleTour doubleplay bonus position
 */

void GenereDoubleTour (const CPosition & P1, const CPosition & P2, const CPosition & TrouDeVerDecollage, const CPosition & TrouDeVerAtterrissage, const CPosition & DebutMur, const CPosition & FinMur,
                       const CPosition & EmplacementBoost, const CPosition & EmplacementBoostImposer, CPosition & PosDoubleTour);
/*! \brief DoubleTour
 *  \param[in] PosPlayer player position
 *  \param[in] PosDoubleTour doubleplay bonus position
 *  \param[out] Joueur selects wich player plays next
 */
void DoubleTour(bool & Joueur, const CPosition & PosPlayer, const CPosition & PosDoubleTour);

#endif // DOUBLETOUR_H
