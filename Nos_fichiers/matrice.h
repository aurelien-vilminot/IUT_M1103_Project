#ifndef MATRICE_H
#define MATRICE_H

/*!
 * \file matrice.h
 * \brief Set of useful functions for the game's map initialization and display.
 * \author Christophe Ruiz
 * \author Aurélien Vilminot
 * \version 1.0
 * \date 08 janvier 2019
 */

#include "../Correc_Prof/type.h"
#include "configuration.h"

/*! \brief ClearScreen Clears the screen
 */
void ClearScreen ();

/*!
 * \brief Couleur initializes color
 * \param[in] coul color's code for Unix terminals
 */
void Couleur (const std::string & coul);

/*!
 * \brief InitMat initializes position of every elements of the matrix
 * \param[out] Mat matrix used for game's map
 * \param[in] NbLine number of lines in the matrix
 * \param[in] NbColumn number of columns in the matrix
 * \param[in] PosPlayer1 player one position
 * \param[in] PosPlayer2 player two position
 * \param[in] VictoireP1 true when player P1 wins
 * \param[in] TrouDeVerDecollage wormhole first position
 * \param[in] TrouDeVerAtterrissage wormhole second position
 * \param[in] DebutMur wall begin position
 * \param[in] FinMur wall end position
 * \param[in] EmplacementBoost boost bonus position
 * \param[in] EmplacementBoostImposer directional boost bonus position
 * \param[in] PosDoubleTour doubleplay bonus position
 */
void InitMat (CMat & Mat, const unsigned NbLine, const unsigned NbColumn, const CPosition & PosPlayer1, const CPosition & PosPlayer2, const bool & VictoireP1, const CPosition & TrouDeVerDecollage, const CPosition & TrouDeVerAtterrissage, const CPosition & DebutMur, const CPosition & FinMur, const CPosition & EmplacementBoost, const CPosition & EmplacementBoostImposer, const CPosition & PosDoubleTour);

/*!
 * \brief ShowMatrix displays game's map
 * \param[in] Mat matrix used for game's map
 * \param[in] IndiceBoost boost power, number of case skipped
 * \param[in] IndiceBoostImposer boost power , number of case skipped
 * \param[in] DirectionBoostImposer boost bonus direction
 * \param[in] Mode gamemode chosen
 * \param[in] TourActuel actual game round
 * \param[in] NbManches number of rounds allowed in game
 * \param[in] NbVic_P1 number of victories for player one
 * \param[in] NbVic_P2 number of victories for player two
 */
void ShowMatrix (const CMat & Mat, const unsigned & IndiceBoost, const unsigned & IndiceBoostImposer, const unsigned DirectionBoostImposer, const bool & Mode, const unsigned & TourActuel, const unsigned & NbManches, const unsigned & NbVic_P1, const unsigned & NbVic_P2);


const char KTokenPlayer1 = ParamChar() ["TokenP1"];//!< player one's token

const char KTokenPlayer2 = ParamChar() ["TokenP2"] ;//!< player two's token

const char KTokenTrouDeVerDecollage = 'o';//!< wormhole's token

const char KTokenTrouDeVerAtterrissage = 'o';//!< wormhole's token

const char KTokenMur = 'X';//!< wall's token

const char KTokenBoost = 'B';//!< boost bonus' token

const char KTokenBoostImposer = 'I';//!< directional boost's token

const char KTokenBoostImposerUp = '^';//!< upper direction boost's token

const char KTokenBoostImposerDown = 'v';//!< down direction boost's token

const char KTokenBoostImposerRight = '>';//!< right direction boost's token

const char KTokenBoostImposerLeft = '<';//!< left direction boost's token

const char KTokenDoubleTour = 'x';//!< doubleplay bonus's token



const std::string KReset   ("0"); //!< resets Unix terminal's color value

const std::string KNoir    ("30"); //!< black color for Unix terminal

const std::string KRouge   ("31"); //!< red color for Unix terminal

const std::string KVert    ("32"); //!< green color for Unix terminal

const std::string KJaune   ("33"); //!< yellow color for Unix terminal

const std::string KBleu    ("34"); //!< blue color for Unix terminal

const std::string KMagenta ("35"); //!< magenta color for Unix terminal

const std::string KCyan    ("36"); //!< cyan color for Unix terminal


#endif // MATRICE_H
