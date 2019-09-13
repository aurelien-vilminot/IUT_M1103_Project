 #ifndef BOOST_H
#define BOOST_H
/*!
 * \file boost.h
 * \brief Set of useful functions for the in-game boost bonus.
 * \author Christophe Ruiz
 * \author Aurélien Vilminot
 * \version 1.4
 * \date 30 décembre 2018
 */

#include "../Correc_Prof/type.h"

/*!
 * \brief GenereBoost, generates boost bonus position
 * \param[in] P1 player one position
 * \param[in] P2 player two position
 * \param[in] TrouDeVerDecollage wormhole's first door position
 * \param[in] TrouDeVerAtterrissage wormhole's second door position
 * \param[in] DebutMur wall begin position
 * \param[in] FinMur wall end position
 * \param[out] EmplacementBoost boost bonus position
 * \param[out] IndiceBoost boost power, number of case skipped
 */
void GenereBoost (const CPosition & P1, const CPosition & P2, const CPosition & TrouDeVerDecollage, const CPosition & TrouDeVerAtterrissage, const CPosition & DebutMur, const CPosition & FinMur, CPosition & EmplacementBoost, unsigned & IndiceBoost);

/*!
 * \brief GenereBoostImposer, generates directionnal boost bonus position
 * \param[in] P1 player one position
 * \param[in] P2 player two position
 * \param[in] TrouDeVerDecollage wormhole's first door position
 * \param[in] TrouDeVerAtterrissage wormhole's second door position
 * \param[in] DebutMur wall begin position
 * \param[in] FinMur wall end position
 * \param[in] EmplacementBoost boost bonus position
 * \param[out] DirectionBoostImposer boost bonus direction
 * \param[out] IndiceBoostImposer boost power, number of case skipped
 * \param[out] EmplacementBoostImposer directional boost position
 */
void GenereBoostImposer (const CPosition & P1, const CPosition & P2, const CPosition & TrouDeVerDecollage, const CPosition & TrouDeVerAtterrissage, const CPosition & DebutMur, const CPosition & FinMur, const CPosition & EmplacementBoost, unsigned & DirectionBoostImposer, unsigned & IndiceBoostImposer, CPosition & EmplacementBoostImposer);

/*!
 * \brief Boost generates boost bonus
 * \param[in, out] PosPlayer player position
 * \param[in] Deplacement player last move direction
 * \param[in] EmplacementBoost boost bonus position
 * \param[in] IndiceBoost boost bonus power, number of case skipped
 * \param[in] TrouDeVerDecollage wormhole's first door position
 * \param[in] TrouDeVerAtterrissage wormhole's second door position
 * \param[in] DebutMur wall begin position
 * \param[in] FinMur wall end position
 * \param[in] EmplacementBoostImposer directional boost position
 * \param[in] IndiceBoostImposer boost power, number of case skipped
 * \param[in] DirectionBoostImposer boost bonus direction
 */
void Boost(CPosition & PosPlayer, const char & Deplacement, const CPosition & EmplacementBoost, const unsigned & IndiceBoost, const CPosition & TrouDeVerDecollage,
           const CPosition & TrouDeVerAtterrissage, const CPosition & DebutMur, const CPosition & FinMur, const CPosition & EmplacementBoostImposer, const unsigned & IndiceBoostImposer,
           const unsigned & DirectionBoostImposer);

/*!
 * \brief BoostImposer generates directional boost bonus
 * \param[in, out] PosPlayer player position
 * \param[in] Deplacement player last move direction
 * \param[in] EmplacementBoost boost bonus position
 * \param[in] IndiceBoost boost bonus power, number of case skipped
 * \param[in] TrouDeVerDecollage wormhole's first door position
 * \param[in] TrouDeVerAtterrissage wormhole's second door position
 * \param[in] DebutMur wall begin position
 * \param[in] FinMur wall end position
 * \param[in] EmplacementBoostImposer directional boost position
 * \param[in] IndiceBoostImposer boost power, number of case skipped
 * \param[in] DirectionBoostImposer boost bonus direction
 */
void BoostImposer(CPosition & PosPlayer, const char & Deplacement, const CPosition & EmplacementBoost, const unsigned & IndiceBoost, const CPosition & TrouDeVerDecollage,
                  const CPosition & TrouDeVerAtterrissage, const CPosition & DebutMur, const CPosition & FinMur, const CPosition & EmplacementBoostImposer, const unsigned & IndiceBoostImposer,
                  const unsigned & DirectionBoostImposer);

#endif // BOOST_H
