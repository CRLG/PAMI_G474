/*! \file CGlobale_ModePiloteTerminal.cpp
    \brief Classe qui contient toute l'application pour le mode de fonctionnement pilote via Anaconbot
*/
#include "CGlobale.h"
#include "stdio.h"

//___________________________________________________________________________
/*!
   \brief Gestion du mode piloté via Anaconbot

   \param --
   \return --
*/
void CGlobale::ModePiloteTerminal(void)
{
    while(1) {
        if (tick) {
            tick = 0;
            SequenceurModePiloteTerminal();
        }
    }
}

// _____________________________________________________________
void CGlobale::ReceiveRS232_ModePiloteTerminal(void)
{
    char rxData;
    //rxData = _rs232_pc_rx.getc();
}


//___________________________________________________________________________
/*!
   \brief Sequenceur de taches en mode autonome

   \param --
   \return --
*/
void CGlobale::SequenceurModePiloteTerminal(void)
{
    static unsigned int cpt1msec = 0;
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
    cpt10msec++;
    if (cpt10msec >= TEMPO_10msec) {
        cpt10msec = 0;
        unsigned char rxdata[2], txdata[2]= {0xF0, 0x69};
        //HAL_SPI_TransmitReceive(&hspi2, txdata, rxdata, 2, 100);
    }

    // ______________________________
    cpt20msec++;
    if (cpt20msec >= TEMPO_20msec) {
        cpt20msec = 0;
/*
        HAL_GPIO_WritePin(Mot1_Sens1_GPIO_Port, Mot1_Sens1_Pin, (GPIO_PinState)test_Mot1_Sens1);
        HAL_GPIO_WritePin(Mot1_Sens2_GPIO_Port, Mot1_Sens2_Pin, (GPIO_PinState)test_Mot1_Sens2);
        HAL_GPIO_WritePin(Mot2_Sens1_GPIO_Port, Mot2_Sens1_Pin, (GPIO_PinState)test_Mot2_Sens1);
        HAL_GPIO_WritePin(Mot2_Sens2_GPIO_Port, Mot2_Sens2_Pin, (GPIO_PinState)test_Mot2_Sens2);
        HAL_GPIO_WritePin(Mot3_Sens1_GPIO_Port, Mot3_Sens1_Pin, (GPIO_PinState)test_Mot3_Sens1);
        HAL_GPIO_WritePin(Mot3_Sens2_GPIO_Port, Mot3_Sens2_Pin, (GPIO_PinState)test_Mot3_Sens2);
*/
        //HAL_GPIO_WritePin(Led1_GPIO_Port, Led1_Pin, (GPIO_PinState)test_Led1);
        //HAL_GPIO_WritePin(Led2_GPIO_Port, Led2_Pin, (GPIO_PinState)test_Led2);
        HAL_GPIO_WritePin(Cde_Mosfet_GPIO_Port, Cde_Mosfet_Pin, (GPIO_PinState)test_CdeMosfet);

        //HAL_GPIO_WritePin(Stor1_GPIO_Port, Stor1_Pin, (GPIO_PinState)test_Stor1);
        //HAL_GPIO_WritePin(Stor2_GPIO_Port, Stor2_Pin, (GPIO_PinState)test_Stor2);

        test_Etor3 = HAL_GPIO_ReadPin(Etor3_GPIO_Port, Etor3_Pin);

        test_Eana1 = readAnalogVolt(1);
        test_Eana2 = readAnalogVolt(2);
        test_Eana3 = readAnalogVolt(3);
        test_Eana4 = readAnalogVolt(4);

        test_codeurs[0]= m_codeurs.m_CumulCodeurPosition1;
        test_codeurs[1]= m_codeurs.m_CumulCodeurPosition2;

        CdeServo(1, test_Servo1);
        CdeServo(2, test_Servo2);
        CdeServo(3, test_Servo3);
        CdeServo(4, test_Servo4);
    }

    // ______________________________
    cpt34msec++;
    if (cpt34msec >= TEMPO_34msec) {
        cpt34msec = 0;

        m_telemetres.periodicTask();
        test_telemetres[0] = m_telemetres.getDistanceAVD();
        test_telemetres[1] = m_telemetres.getDistanceARD();
        m_leds_rgb.setColor(0, RGBColor::RED, test_telemetres[0]/100);
        m_leds_rgb.setColor(1, RGBColor::BLUE, test_telemetres[1]/100);
    }

    // ______________________________
    cpt50msec++;
    if (cpt50msec >= TEMPO_50msec) {
        cpt50msec = 0;
        toggleLedBuiltin();
        //printf("%d\n\r", HAL_GetTick());
        HAL_GPIO_TogglePin(Led1_GPIO_Port, Led1_Pin);

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
    }
    // ______________________________
    cpt500msec++;
    if (cpt500msec >= TEMPO_500msec) {
        cpt500msec = 0;
        HAL_GPIO_TogglePin(Led2_GPIO_Port, Led2_Pin);
    }
    // ______________________________
    cpt1sec++;
    if (cpt1sec >= TEMPO_1sec) {
        cpt1sec = 0;
    }

}
