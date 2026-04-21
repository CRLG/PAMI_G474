/*! \file ConfigSpecifiqueCoupe.h
	\brief Déclare
*/
#ifndef _CONFIG_SPECIFIQUE_COUPE 
#define _CONFIG_SPECIFIQUE_COUPE


// Consignes "tout doux" pour l'asserviseement
// utilisé dans la stratégie d'évitement et propre au robot
// TODO : peut être qu'il serait mieux de faire une méthode
// dans la classe Asservissement getCdeMinToutDoux() et getCdeMaxToutDoux()
// à ré-implémenter pour chaque robot en fonction de moteurs
#define CDE_MIN_TOUT_DOUX (-10)
#define CDE_MAX_TOUT_DOUX (10)

//! Seuil de détection d'obstacle
#define SEUIL_DETECTION_OBSTACLE  (100) // [mm]

//! Période d'appel du modèle
#define PERIODE_APPEL_MODELIA 0.02f // [sec]

//! Durée du match
#define DUREE_MATCH 100 // [sec]
#define DEBUT_MATCH 1 // [sec]

typedef enum {
    JAUNE=0,
    BLEU
}tCouleurEquipes;

// Affectation des numéros de stratégie
typedef enum {
    STRATEGIE_PAR_DEFAUT= 0,
    STRATEGIE_HOMOLO1,
    STRATEGIE_HOMOLO2,
    STRATEGIE_01,
    STRATEGIE_02,
    STRATEGIE_03,
    STRATEGIE_04,
    STRATEGIE_05,
    STRATEGIE_06,
    // _____________________
    STRATEGIE_TEST_01 = 30,
    STRATEGIE_TEST_02,
    STRATEGIE_TEST_03,
    STRATEGIE_TEST_04,
    STRATEGIE_TEST_05,
    STRATEGIE_TEST_06,
    STRATEGIE_TEST_07
}eATTRIBUTION_STRATEGIES;



#endif // _CONFIG_SPECIFIQUE_COUPE


