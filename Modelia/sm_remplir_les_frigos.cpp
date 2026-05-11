/**
* Built on 20260510_000824
*/

#include "sm_remplir_les_frigos.h"
#include "CGlobale.h"

SM_remplir_les_frigos::SM_remplir_les_frigos()
{
	m_main_mission_type = true;
	m_max_score = 0;
}

const char* SM_remplir_les_frigos::getName()
{
	return "SM_remplir_les_frigos";
}

const char* SM_remplir_les_frigos::stateToName(unsigned short state)
{
	switch(state)
	{
		case ETAT_1 :	return "ETAT_1";

		case FIN_MISSION :	return "FIN_MISSION";
	}
	return "UNKNOWN_STATE";
}

// _____________________________________
void SM_remplir_les_frigos::step()
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
