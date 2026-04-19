/*! \file CTelemetres.cpp
    \brief Classe qui contient les méthodes pour le dialogue avec la capteur ultrason SRF08
*/
#include "RessourcesHardware.h"
#include "CTelemetres.h"
#include "ConfigSpecifiqueCoupe.h"
#include "CGlobale.h"

//___________________________________________________________________________
/*!
   \brief Constructeur

   \param --
   \return --
*/
CTelemetres::CTelemetres()
: m_vl53(&I2C_HDL_ELECTROBOT)
{

}

//___________________________________________________________________________
/*!
   \brief Destructeur

   \param --
   \return --
*/
CTelemetres::~CTelemetres() 
{

}


//___________________________________________________________________________
float CTelemetres::getDistanceAVG()
{
    return m_dist_filt[IDX_VL53_AV];
}

float CTelemetres::getDistanceAVD()
{
    return m_dist_filt[IDX_VL53_AV];
}

float CTelemetres::getDistanceARG()
{
    return m_dist_filt[IDX_VL53_AR];
}

float CTelemetres::getDistanceARD()
{
    return m_dist_filt[IDX_VL53_AR];
}

float CTelemetres::getDistanceARGCentre()
{
    return m_dist_filt[IDX_VL53_AR];
}

float CTelemetres::getDistanceARDCentre()
{
    return m_dist_filt[IDX_VL53_AR];
}

//___________________________________________________________________________
/*!
   \brief Initialisation des capteurs

   \param --
   \return --
*/
bool CTelemetres::init(void)
{
	   m_vl53.init();
	   return true;
}

//___________________________________________________________________________
void CTelemetres::periodicTask(void)
{
    m_vl53.read();
    // Filtrage moyenne glissante
    for (int i=0; i<VL53_COUNT; i++) {
    	unsigned short current_dist = m_vl53.get_last_distance(i);
    	m_dist_filt[i] = MoyenneGlissante_uint16(current_dist, m_buff_moy_dist_vl53[i], BUFF_SIZE_MOYENNE);
    }
}


//___________________________________________________________________________
/*!
   \brief Filrtage des donnees brutes des capteurs ultrason

   \param currentVal la valeur du dernier échantillon pour le calcul de la moyenne
   \param buf_oldSamples le buffer contenant les derniers échantillons de mesures
   \param samplesNumbers le nombre de point pour la moyenne glissante
   \return la valeur moeyennée
*/
unsigned short CTelemetres::MoyenneGlissante_uint16(unsigned short currentVal, unsigned short *buf_oldSamples, unsigned int samplesNumbers)
{
	unsigned short moy=currentVal;
    int i=0;  // Attention : doit être un "int" et non un "unsigned int" à cause du test de fin dans le "for"

    // Traite tous les échantillons sauf le 1er (index 0 du tableau) qui est un cas particulier
    for (i=(samplesNumbers-2); i>0; i--) {
        moy = moy + buf_oldSamples[i];
        buf_oldSamples[i] = buf_oldSamples[i-1];
    }

    // Cas particulier pour la 1ère case du tableau où la nouvelle valeur ne provient pas de l'index précédent du tableau mais du nouvel échantillon
    moy = moy + buf_oldSamples[0];
    buf_oldSamples[0] = currentVal;

    moy = moy / samplesNumbers;

    return(moy);
}
