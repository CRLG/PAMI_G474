/*! \file RessoucesHardware.cpp
    \brief Déclare les ressources hardware du MBED utilisées par le reste du logiciel
*/
#include "console_interactive_menu.h"
#include "RessourcesHardware.h"
#include "stdio.h"
#include "CGlobale.h"

CMenuApp::CMenuApp()
{
    enable_echo(false);
    DECLARE_START_PAGE(CMenuApp::page1);
}

// ______________________________________________
void CMenuApp::send_to_console(char msg[])
{
    printf("%s", msg);
}

// ============================================================================
//                             LES MENUS
// ============================================================================
void CMenuApp::page1()
{
    DECLARE_PAGE("Menu Page 1", CMenuApp::page1);
    DECLARE_OPTION('a', "Commande moteurs", CMenuApp::page_cde_moteurs);
    DECLARE_OPTION('z', "Commande servo", CMenuApp::page_servos);
    DECLARE_OPTION('e', "Capteurs", CMenuApp::page_capteurs);
    DECLARE_OPTION('r', "I2C", CMenuApp::page_i2c);
    DECLARE_OPTION('t', "Asservissement", CMenuApp::page_asservissement);
}


// ===========================================================
//                  MOTEURS
// ===========================================================

void CMenuApp::page_cde_moteurs()
{
    DECLARE_PAGE("COMMANDE MOTEURS", CMenuApp::page_cde_moteurs);

    DECLARE_ACTION('a', "Arrêt moteurs", CMenuApp::arret_moteurs);

    DECLARE_ACTION('z', "Gauche -10%", CMenuApp::cde_mot_G_M1);
    DECLARE_ACTION('e', "Gauche -25%", CMenuApp::cde_mot_G_M2);
    DECLARE_ACTION('r', "Gauche -50%", CMenuApp::cde_mot_G_M3);
    DECLARE_ACTION('Z', "Gauche +10%", CMenuApp::cde_mot_G_P1);
    DECLARE_ACTION('E', "Gauche +25%", CMenuApp::cde_mot_G_P2);
    DECLARE_ACTION('R', "Gauche +50%", CMenuApp::cde_mot_G_P3);

    DECLARE_ACTION('q', "Droit -10%", CMenuApp::cde_mot_D_M1);
    DECLARE_ACTION('s', "Droit -25%", CMenuApp::cde_mot_D_M2);
    DECLARE_ACTION('d', "Droit -50%", CMenuApp::cde_mot_D_M3);
    DECLARE_ACTION('Q', "Droit +10%", CMenuApp::cde_mot_D_P1);
    DECLARE_ACTION('S', "Droit +25%", CMenuApp::cde_mot_D_P2);
    DECLARE_ACTION('D', "Droit +50%", CMenuApp::cde_mot_D_P3);

    DECLARE_ACTION('w', "Mot3 -10%", CMenuApp::cde_mot_M3_M1);
    DECLARE_ACTION('x', "Mot3 -25%", CMenuApp::cde_mot_M3_M2);
    DECLARE_ACTION('c', "Mot3 -50%", CMenuApp::cde_mot_M3_M3);
    DECLARE_ACTION('W', "Mot3 +10%", CMenuApp::cde_mot_M3_P1);
    DECLARE_ACTION('X', "Mot3 +10%", CMenuApp::cde_mot_M3_P2);
    DECLARE_ACTION('C', "Mot3 +10%", CMenuApp::cde_mot_M3_P3);
}

bool CMenuApp::arret_moteurs()  { CdeMoteur(1, 0); CdeMoteur(2, 0); CdeMoteur(3,0); return true;}

bool CMenuApp::cde_mot_G_M1()   { Application.m_roues.AdapteCommandeMoteur_G(-10); return true; }
bool CMenuApp::cde_mot_G_M2()   { Application.m_roues.AdapteCommandeMoteur_G(-25); return true; }
bool CMenuApp::cde_mot_G_M3()   { Application.m_roues.AdapteCommandeMoteur_G(-50); return true; }
bool CMenuApp::cde_mot_G_P1()   { Application.m_roues.AdapteCommandeMoteur_G(10); return true; }
bool CMenuApp::cde_mot_G_P2()   { Application.m_roues.AdapteCommandeMoteur_G(25); return true; }
bool CMenuApp::cde_mot_G_P3()   { Application.m_roues.AdapteCommandeMoteur_G(50); return true; }

bool CMenuApp::cde_mot_D_M1()   { Application.m_roues.AdapteCommandeMoteur_D(-10); return true; }
bool CMenuApp::cde_mot_D_M2()   { Application.m_roues.AdapteCommandeMoteur_D(-25); return true; }
bool CMenuApp::cde_mot_D_M3()   { Application.m_roues.AdapteCommandeMoteur_D(-50); return true; }
bool CMenuApp::cde_mot_D_P1()   { Application.m_roues.AdapteCommandeMoteur_D(10); return true; }
bool CMenuApp::cde_mot_D_P2()   { Application.m_roues.AdapteCommandeMoteur_D(25); return true; }
bool CMenuApp::cde_mot_D_P3()   { Application.m_roues.AdapteCommandeMoteur_D(50); return true; }

bool CMenuApp::cde_mot_M3_M1()   { CdeMoteur(3, -10); return true; }
bool CMenuApp::cde_mot_M3_M2()   { CdeMoteur(3, -25); return true; }
bool CMenuApp::cde_mot_M3_M3()   { CdeMoteur(3, -50); return true; }
bool CMenuApp::cde_mot_M3_P1()   { CdeMoteur(3, 10); return true; }
bool CMenuApp::cde_mot_M3_P2()   { CdeMoteur(3, 25); return true; }
bool CMenuApp::cde_mot_M3_P3()   { CdeMoteur(3, 50); return true; }






void CMenuApp::page_capteurs()
{
    DECLARE_PAGE("Capteurs", CMenuApp::page_capteurs);
    DECLARE_OPTION('0', "Retour en page d'accueil", CMenuApp::page1);
    DECLARE_ACTION('a', "Etat des codeurs", CMenuApp::read_codeurs);
    DECLARE_ACTION('z', "Etat des entrees analogiques", CMenuApp::read_analog_inputs);
    DECLARE_ACTION('t', "Distance télémètre", CMenuApp::read_telemetre);
}


// ===========================================================
//                  SERVO MOTEURS
// ===========================================================

void CMenuApp::page_servos()
{
    DECLARE_PAGE("SERVO MOTEURS", CMenuApp::page_servos);
    DECLARE_OPTION('0', "Retour en page d'accueil", CMenuApp::page1);
    DECLARE_ACTION('a', "Servo1 : 1200", CMenuApp::page_servo1_1200);
    DECLARE_ACTION('z', "Servo1 : 1500", CMenuApp::page_servo1_1500);
    DECLARE_ACTION('e', "Servo1 : 1700", CMenuApp::page_servo1_1700);
    DECLARE_ACTION('r', "Servo1 : 2000", CMenuApp::page_servo1_2000);

    DECLARE_ACTION('y', "Servo2 : 1200", CMenuApp::page_servo2_1200);
    DECLARE_ACTION('u', "Servo2 : 1500", CMenuApp::page_servo2_1500);
    DECLARE_ACTION('i', "Servo2 : 1700", CMenuApp::page_servo2_1700);
    DECLARE_ACTION('o', "Servo2 : 2000", CMenuApp::page_servo2_2000);

    DECLARE_ACTION('q', "Servo3 : 1200", CMenuApp::page_servo3_1200);
    DECLARE_ACTION('s', "Servo3 : 1500", CMenuApp::page_servo3_1500);
    DECLARE_ACTION('d', "Servo3 : 1700", CMenuApp::page_servo3_1700);
    DECLARE_ACTION('f', "Servo3 : 2000", CMenuApp::page_servo3_2000);

    DECLARE_ACTION('h', "Servo4 : 1200", CMenuApp::page_servo4_1200);
    DECLARE_ACTION('j', "Servo4 : 1500", CMenuApp::page_servo4_1500);
    DECLARE_ACTION('k', "Servo4 : 1700", CMenuApp::page_servo4_1700);
    DECLARE_ACTION('l', "Servo4 : 2000", CMenuApp::page_servo4_2000);

}

// ===========================================================
//                  SERVO MOTEURS
// ===========================================================
bool CMenuApp::page_servo1_1200() { Application.test_Servo1 = 1200; return true; }
bool CMenuApp::page_servo1_1500() { Application.test_Servo1 = 1500; return true; }
bool CMenuApp::page_servo1_1700() { Application.test_Servo1 = 1700; return true; }
bool CMenuApp::page_servo1_2000() { Application.test_Servo1 = 2000; return true; }
bool CMenuApp::page_servo2_1200() { Application.test_Servo2 = 1200; return true; }
bool CMenuApp::page_servo2_1500() { Application.test_Servo2 = 1500; return true; }
bool CMenuApp::page_servo2_1700() { Application.test_Servo2 = 1700; return true; }
bool CMenuApp::page_servo2_2000() { Application.test_Servo2 = 2000; return true; }
bool CMenuApp::page_servo3_1200() { Application.test_Servo3 = 1200; return true; }
bool CMenuApp::page_servo3_1500() { Application.test_Servo3 = 1500; return true; }
bool CMenuApp::page_servo3_1700() { Application.test_Servo3 = 1700; return true; }
bool CMenuApp::page_servo3_2000() { Application.test_Servo3 = 2000; return true; }
bool CMenuApp::page_servo4_1200() { Application.test_Servo4 = 1200; return true; }
bool CMenuApp::page_servo4_1500() { Application.test_Servo4 = 1500; return true; }
bool CMenuApp::page_servo4_1700() { Application.test_Servo4 = 1700; return true; }
bool CMenuApp::page_servo4_2000() { Application.test_Servo4 = 2000; return true; }







void CMenuApp::page_asservissement () {
    DECLARE_PAGE("ASSERVISSEMENT", CMenuApp::page_asservissement);
    DECLARE_OPTION('0', "Retour en page d'accueil", CMenuApp::page1);
    DECLARE_ACTION('x', "STOP", CMenuApp::asser_stop);
    DECLARE_ACTION('c', "RESET ASSERVISSEMENT", CMenuApp::asser_resetPos);
    DECLARE_ACTION('a', "+10 cm", CMenuApp::asser_avant10);
    DECLARE_ACTION('z', "+20 cm", CMenuApp::asser_avant20);
    DECLARE_ACTION('e', "+30 cm", CMenuApp::asser_avant30);
    DECLARE_ACTION('r', "+50 cm", CMenuApp::asser_avant50);
    DECLARE_ACTION('t', "+100 cm", CMenuApp::asser_avant100);

    DECLARE_ACTION('A', "-10 cm", CMenuApp::asser_arriere10);
    DECLARE_ACTION('Z', "-20 cm", CMenuApp::asser_arriere20);
    DECLARE_ACTION('E', "-30 cm", CMenuApp::asser_arriere30);
    DECLARE_ACTION('R', "-50 cm", CMenuApp::asser_arriere50);
    DECLARE_ACTION('T', "-100 cm", CMenuApp::asser_arriere100);

    DECLARE_ACTION('u', "Afficher x/y", CMenuApp::get_xy_asser);

    DECLARE_OPTION('l', "Data Logger", CMenuApp::page_asserv_data_logger);
}


void CMenuApp::page_set_param_1()
{
    DECLARE_PAGE("Forçage paramètre Param1", CMenuApp::page_set_param_1)
            DECLARE_ACTION('r', "Lecture du paramètre", CMenuApp::action_read_param1)
            DECLARE_OPTION('q', "Retour en page principale", CMenuApp::page1)
            DECLARE_ACTION_DOUBLE("Entrez une valeur pour Param1", CMenuApp::action_set_param1)
}

void CMenuApp::page_set_param_2()
{
    DECLARE_PAGE("Forçage paramètre Param2", CMenuApp::page_set_param_2)
            DECLARE_ACTION('r', "Lecture du paramètre", CMenuApp::action_read_param2)
            DECLARE_OPTION('q', "Retour en page principale", CMenuApp::page_set_param_1)
            DECLARE_ACTION_INT("Entrez une valeur pour Param2", CMenuApp::action_set_param2)
}


// ============================================================================
//                             LES ACTIONS
// ============================================================================
bool CMenuApp::action_set_param1(double val)
{
    _printf("Changement de la valeur du paramètre Param1: %f\n\r", val);
    m_param1 = val;
    return true;
}

bool CMenuApp::action_read_param1()
{
    _printf("Valeur du Param1: %f\n\r", m_param1);
    return true;
}

bool CMenuApp::action_set_param2(int val)
{
    _printf("Changement de la valeur du paramètre Param2: %d\n\r", val);
    m_param2 = val;
    return true;
}

bool CMenuApp::action_read_param2()
{
    _printf("Valeur du Param2: %d\n\r", m_param2);
    return true;
}

bool CMenuApp::action_read_params()
{
    _printf("Valeur du Param1: %f\n\r", m_param1);
    _printf("Valeur du Param2: %d\n\r", m_param2);
    return true;
}







// ===========================================================
//                  CAPTEURS
// ===========================================================

bool CMenuApp::read_codeurs()
{
    _printf("Codeur1: %d / Codeur2: %d\n\r", getCodeur(1), getCodeur(2));
    return true;
}

bool CMenuApp::read_analog_inputs()
{
    _printf("Eana1=%.3fV(%d) / Eana2=%.3fV(%d) / Eana3=%.3fV(%d) / Eana4=%.3fV(%d)\n\r",
            readAnalogVolt(1), readAnalog(1),
            readAnalogVolt(2), readAnalog(2),
            readAnalogVolt(3), readAnalog(3),
            readAnalogVolt(4), readAnalog(4));
    return true;
}


bool CMenuApp::read_telemetre()
{
    return true;
}

// ===========================================================
//                  ASSERVISSEMENT
// ===========================================================
bool CMenuApp::asser_stop ()
{
    Application.m_asservissement.CommandeManuelle(0, 0);
	return true;
}

bool CMenuApp::asser_resetPos()
{
    return true;
}

bool CMenuApp::asser_avant10 ()
{
	Application.m_asservissement.CommandeMouvementDistanceAngle(10, 0);
    return true;
}

bool CMenuApp::asser_avant20 ()
{
	Application.m_asservissement.CommandeMouvementDistanceAngle(20, 0);
    return true;
}

bool CMenuApp::asser_avant30 ()
{
	Application.m_asservissement.CommandeMouvementDistanceAngle(30, 0);
    return true;
}

bool CMenuApp::asser_avant50 ()
{
	Application.m_asservissement.CommandeMouvementDistanceAngle(30, 0);
    return true;
}

bool CMenuApp::asser_avant100 ()
{
	Application.m_asservissement.CommandeMouvementDistanceAngle(100, 0);
    return true;
}

bool CMenuApp::asser_arriere10 ()
{
	Application.m_asservissement.CommandeMouvementDistanceAngle(-10, 0);
	return true;
}

bool CMenuApp::asser_arriere20 ()
{
	Application.m_asservissement.CommandeMouvementDistanceAngle(-20, 0);
	return true;
}

bool CMenuApp::asser_arriere30 ()
{
	Application.m_asservissement.CommandeMouvementDistanceAngle(-30, 0);
	return true;
}


bool CMenuApp::asser_arriere50 ()
{
	Application.m_asservissement.CommandeMouvementDistanceAngle(-50, 0);
    return true;
}

bool CMenuApp::asser_arriere100 ()
{
	Application.m_asservissement.CommandeMouvementDistanceAngle(-100, 0);
    return true;
}

bool CMenuApp::get_xy_asser ()
{
    return true;
}

// =============================================================================
//                   DATA LOGGER POUR ASSERV
// =============================================================================
void CMenuApp::page_asserv_data_logger()
{
    DECLARE_PAGE("Data Logger", CMenuApp::page_asserv_data_logger);
    DECLARE_ACTION('s', "Start logger", CMenuApp::start_logger);
    DECLARE_ACTION('t', "Stop logger", CMenuApp::stop_logger);
    DECLARE_ACTION('e', "Statut du logger", CMenuApp::statut_logger);
    DECLARE_ACTION('p', "Print logger", CMenuApp::print_logger);
    DECLARE_ACTION('w', "Synchro logger OFF", CMenuApp::synchro_logger_off);
    DECLARE_ACTION('x', "Synchro logger ON", CMenuApp::synchro_logger_on);
    DECLARE_ACTION('b', "Rollback logger OFF", CMenuApp::rollback_logger_off);
    DECLARE_ACTION('n', "Rollback logger ON", CMenuApp::rollback_logger_on);
}

bool CMenuApp::start_logger()       { Application.m_asservissement.m_data_logger.start(); return true; }
bool CMenuApp::stop_logger()        { Application.m_asservissement.m_data_logger.stop(); return true; }
bool CMenuApp::print_logger()       { Application.m_asservissement.m_data_logger.print(); return true; }
bool CMenuApp::synchro_logger_off() { Application.m_asservissement.m_automatic_start_logger = false; return true; }
bool CMenuApp::synchro_logger_on()  { Application.m_asservissement.m_automatic_start_logger = true; return true; }
bool CMenuApp::rollback_logger_off(){ Application.m_asservissement.m_data_logger.m_rollback_until_convergence = false; return true; }
bool CMenuApp::rollback_logger_on() { Application.m_asservissement.m_data_logger.m_rollback_until_convergence = true; return true; }
bool CMenuApp::statut_logger()
{
    if (Application.m_asservissement.m_data_logger.m_started)   _printf("Enregistrement en cours...\n\r");
    else                                                        _printf("Enregistrement arrêté\n\r");

    return true;
}




// =============================================================================
//                          I2C
// =============================================================================
void CMenuApp::page_i2c()
{
    DECLARE_PAGE("I2C", CMenuApp::page_i2c);
    DECLARE_ACTION('s', "Scan I2C", CMenuApp::i2c_action_scan);
}

bool CMenuApp::i2c_action_scan()
{
    uint8_t data;
    _printf("SCAN I2C\n\r");

    // 1. présentation du scan sous une forme linéaire des calculateurs présents
    for (unsigned int addr=0; addr<0xFF; addr++)
    {
        if (HAL_I2C_Master_Transmit(&I2C_HDL_ELECTROBOT, addr, &data, 1, I2C_DEFAULT_TIMEOUT) == HAL_OK) {
            printf(" Echo on 0x%x\n\r", addr);
        }
    }

    // 1. présentation du scan sous une forme de tableau
    _printf("\n\r      ");
    for (unsigned int i=0; i<16; i++) _printf("%x   ", i);
    for (unsigned int addr=0; addr<=0xFF; addr++)
    {
        if ((addr%16) == 0) printf("\n\r0x%02x", addr);
        if (HAL_I2C_Master_Transmit(&I2C_HDL_ELECTROBOT, addr, &data, 1, I2C_DEFAULT_TIMEOUT) == HAL_OK) {
            _printf("  OK", addr);
        }
        else {
            _printf("  --", addr);
        }
    }
    _printf("\n\r");

    return true;
}
