#ifndef CONFIGURATION_H
#define CONFIGURATION_H
/*!
 * \file configuration.h
 * \brief Set of useful functions for game configuration
 * \author Aurélien Vilminot
 * \version 2.1
 * \date 07 janvier 2019
 */

#include <map>

/*!
 * \brief VerifFic verifies if the config file is readable and ready to use
 * \param[in] FicConfig path of the config file
 * \return true or false
 */
bool VerifFic (const std::string & FicConfig);

/*!
 * \brief ParamChar returns a map linking char type parameters to their string key
 * \return A map type <string, char>
 */
std::map<std::string, char> ParamChar ();

/*!
 * \brief ParamUnsigned returns a map linking unsigned type parameters to their string key
 * \return A map type <string, unsigned>
 */
std::map<std::string, unsigned> ParamUnsigned ();

#endif // CONFIGURATION_H
