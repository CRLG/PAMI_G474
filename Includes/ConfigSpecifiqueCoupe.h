/*! \file ConfigSpecifiqueCoupe.h
	\brief Déclare
*/
#ifndef _CONFIG_SPECIFIQUE_COUPE 
#define _CONFIG_SPECIFIQUE_COUPE

// ________________________________________________________________________
// défini les 4 types de PAMI différents utilisés : 4 types différents : 3 PAMI écureuil + 1 PAMI Ninja
#define PAMI_TYPE_ECUREUIL_1    1
#define PAMI_TYPE_ECUREUIL_2    2
#define PAMI_TYPE_ECUREUIL_3    3
#define PAMI_TYPE_NINJA         4

// défini quel type de PAMI fait tourner le logiciel commun aux 4 types de PAMI
// permet de faire de la compilation conditionnelle #if (TYPE_PAMI == PAMI_TYPE_ECUREUIL_2) ....
#define TYPE_PAMI   (PAMI_TYPE_NINJA)  // mettre ici le type de PAMI

// ________________________________________________________________________
// A décommenter pour activer le logger de l'asservissement
// !!!! Le Logger consomme beaucoup de RAM (à désactiver si pas besoin)
//#define UTILISATION_ASSERV_LOGGER

// Consignes "tout doux" pour l'asserviseement
// utilisé dans la stratégie d'évitement et propre au robot
// TODO : peut être qu'il serait mieux de faire une méthode
// dans la classe Asservissement getCdeMinToutDoux() et getCdeMaxToutDoux()
// à ré-implémenter pour chaque robot en fonction de moteurs
#define CDE_MIN_TOUT_DOUX (-10)
#define CDE_MAX_TOUT_DOUX (10)

//! Seuil de détection d'obstacle
#define SEUIL_DETECTION_OBSTACLE  (250) // [mm]

//! Période d'appel du modèle
#define PERIODE_APPEL_MODELIA 0.02f // [sec]

// ________________________________________________________________________
//! Nombre de télémètres VL53 utilisés sur l'application
#if (TYPE_PAMI == PAMI_TYPE_NINJA)
    #define NBRE_TELEMETRES_VL53 2
#else
    #define NBRE_TELEMETRES_VL53 1
#endif

// ________________________________________________________________________
//! Durée du match
#define DUREE_MATCH 100 // [sec]  : durée totale du match

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
    STRATEGIE_PAMI_ECUREUIL_01,
    STRATEGIE_PAMI_ECUREUIL_02,
    STRATEGIE_PAMI_ECUREUIL_03,
    STRATEGIE_PAMI_ECUREUIL_04,
    // _____________________
    STRATEGIE_PAMI_NINJA_01,
    STRATEGIE_PAMI_NINJA_02,
    STRATEGIE_PAMI_NINJA_03,
    STRATEGIE_PAMI_NINJA_04,
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


