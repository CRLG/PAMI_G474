/*! \file CServomoteursBase.h
    \brief Classe qui contient la gestion des roues motrices gauche et droite
*/

#ifndef _SERVOMOTEURS_H_
#define _SERVOMOTEURS_H_

#include "CServomoteursBase.h"

// -----------------------------
//! Classe de gestion des options d'exécution passees en ligne de commande
class CServomoteurs : public CServomoteursBase
{
public :
    CServomoteurs();

    /*virtual*/ void CommandeServo(unsigned char numServo, unsigned short position_usec) override;
};

#endif  // _SERVOMOTEURS_H_
