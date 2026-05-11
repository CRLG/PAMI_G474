/**
* Built on 20260510_000835
*/

#include "sm_recuperer_les_caisses_vides.h"
#include "CGlobale.h"

SM_recuperer_les_caisses_vides::SM_recuperer_les_caisses_vides()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_recuperer_les_caisses_vides::getName()
{
	return "SM_recuperer_les_caisses_vides";
}

const char* SM_recuperer_les_caisses_vides::stateToName(unsigned short state)
{
	switch(state)
	{
		case ETAT_1 :	return "ETAT_1";

		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_recuperer_les_caisses_vides::step()
{
	switch (m_state)
	{
			
// _____________________________________

  case ETAT_1 :
  	if (onEntry()) {
  	  //Actions en entrée de l état
  	}
  	//Transitions vers les autres états
  	if (onExit()) {
  	  //TODO : pouvoir intégrer des actions en sortie d état
  	}
  	break;

// ___________________________
case FIN_MISSION :
		m_succes = true;
		m_score = m_max_score;
		stop();
		break;


	}
}
