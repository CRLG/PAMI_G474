/*! \file CGlobale.cpp
    \brief Classe qui contient toute l'application
*/
#include "CGlobale.h"

//___________________________________________________________________________
/*!
   \brief Constructeur

   \param --
   \return --
*/
CGlobale::CGlobale()
{
    ModeFonctionnement = MODE_PILOTE_TERMINAL;
}

//___________________________________________________________________________
/*!
   \brief Destructeur

   \param --
   \return --
*/
CGlobale::~CGlobale() 
{

}

//___________________________________________________________________________
/*!
   \brief Point d'entrée pour l'execution de toute l'application

   \param --
   \return --
*/
void CGlobale::Run(void)
{

	// Assure que les moteurs soient au repos au démarrage
	CdeMoteur(1, 0);
	CdeMoteur(2, 0);

    // Lecture des paramètres EEPROM
    readEEPROM();

    // Attends la montée de toutes les alimentation et l'initialisation de l'écran
    // Temps nécessaire en pratique pour que l'écran tactile ai fini de démarrer
    // avant de commencer à  lui en envoyer des messages (et d'en recevoir)
   HAL_Delay(300);

   m_lcd.Init();
   m_lcd.GotoXY (20,0);
   m_lcd.Puts ("CRLG", &Font_16x26, SSD1306::SSD1306_COLOR_WHITE);
   m_lcd.GotoXY (30, 40);
   m_lcd.Puts ("PAMI", &Font_11x18, SSD1306::SSD1306_COLOR_WHITE);
   m_lcd.UpdateScreen();

   // Bandeau de LED
   m_leds_rgb.init();
   int intensity = 2;
   m_leds_rgb.setColor(1, RGBColor::RED, intensity);
   m_leds_rgb.setColor(2, RGBColor::GREEN, intensity);
   m_leds_rgb.setColor(3, RGBColor::BLUE, intensity);
   m_leds_rgb.setColor(4, RGBColor::OLIVE, intensity);
   m_leds_rgb.setColor(5, RGBColor::PURPLE, intensity);

   m_asservissement.Init();

   // Télémètre VL53
   m_telemetres.init();

    switch(ModeFonctionnement) {
    case MODE_AUTONOME : 			ModeAutonome();			break;
    case MODE_PILOTE_LABOTBOX : 	ModePiloteLaBotBox();	break;
    case MODE_PILOTE_TERMINAL : 	ModePiloteTerminal();	break;
    default : 						ModeAutonome();			break;
    }

    while(1) {
        // Ce code ne devrait jamais être atteint
    }
}


//___________________________________________________________________________
/*!
   \brief Lecture des paramètre de l'EEPROM

   \param --
   \return --
*/
void CGlobale::readEEPROM()
{
}
