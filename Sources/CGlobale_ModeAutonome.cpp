/*! \file CGlobale_ModeAutonome.cpp
    \brief Classe qui contient toute l'application pour le mode de fonctionnement autonome
*/
#include "CGlobale.h"
#include <stdio.h>
#include "ConfigSpecifiqueCoupe.h"



//___________________________________________________________________________
/*!
   \brief Point d'entrée pour l'execution de toute l'application

   \param --
   \return --
*/
void CGlobale::ModeAutonome(void)
{
	m_modelia.init();
	m_modelia.setStrategie(STRATEGIE_01);

    while(1) {
        if (tick) {
            tick = 0;
            SequenceurModeAutonome();
        }
    }
}

//___________________________________________________________________________
/*!
   \brief Sequenceur de taches en mode autonome

   \param --
   \return --
*/
void CGlobale::SequenceurModeAutonome(void)
{
    static unsigned int cpt1msec = 0;
    static unsigned int cpt5msec = 0;
    static unsigned int cpt10msec = 0;
    static unsigned int cpt20msec = 0;
    static unsigned int cpt34msec = 0;
    static unsigned int cpt50msec = 0;
    static unsigned int cpt100msec = 0;
    static unsigned int cpt200msec = 0;
    static unsigned int cpt500msec = 0;
    static unsigned int cpt1sec = 0;

    // ______________________________
    cpt1msec++;
    if (cpt1msec >= TEMPO_1msec) {
        cpt1msec = 0;
        m_codeurs.Traitement();
    }
    // ______________________________
    cpt5msec++;
    if (cpt5msec >= TEMPO_5msec) {
        cpt5msec = 0;

        m_asservissement.CalculsMouvementsRobots();
    }
    // ______________________________
    cpt10msec++;
    if (cpt10msec >= TEMPO_10msec) {
        cpt10msec = 0;
    }

    // ______________________________
    cpt20msec++;
    if (cpt20msec >= TEMPO_20msec) {
        cpt20msec = 0;

        toggleLedBuiltin();
        HAL_GPIO_TogglePin(Led1_GPIO_Port, Led1_Pin);

        // Execute un pas de calcul du modele
        m_modelia.step();

        m_servos.periodicCall();
    }

    // ______________________________
    cpt34msec++;
    if (cpt34msec >= TEMPO_34msec) {
        cpt34msec = 0;

        m_telemetres.periodicTask();

        unsigned long color_rgb = m_detection_obstacles.isObstacleAV()?RGBColor::RED: RGBColor::OFF_BLACK;
        m_leds_rgb.setColor(0, color_rgb, 10);

        color_rgb = m_detection_obstacles.isObstacleAR()?RGBColor::RED: RGBColor::OFF_BLACK;
        m_leds_rgb.setColor(1, color_rgb, 10);
    }

    // ______________________________
    cpt50msec++;
    if (cpt50msec >= TEMPO_50msec) {
        cpt50msec = 0;

        m_leds_rgb.periodicTask();
    }

    // ______________________________
    cpt100msec++;
    if (cpt100msec >= TEMPO_100msec) {
        cpt100msec = 0;
    }

    // ______________________________
    cpt200msec++;
    if (cpt200msec >= TEMPO_200msec) {
        cpt200msec = 0;
        HAL_GPIO_TogglePin(Led2_GPIO_Port, Led2_Pin);
    }
    // ______________________________
    cpt500msec++;
    if (cpt500msec >= TEMPO_500msec) {
        cpt500msec = 0;
    }
    // ______________________________
    cpt1sec++;
    if (cpt1sec >= TEMPO_1sec) {
        cpt1sec = 0;
    }

}
