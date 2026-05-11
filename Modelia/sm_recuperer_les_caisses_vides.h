/**
 * Built on 20260510_000835
 */

#ifndef SM_RECUPERER_LES_CAISSES_VIDES_H
#define SM_RECUPERER_LES_CAISSES_VIDES_H

#include "sm_statemachinebase.h"

class SM_recuperer_les_caisses_vides : public SM_StateMachineBase
{
public:
	SM_recuperer_les_caisses_vides();
	void step();
	const char* getName();
	const char* stateToName(unsigned short state);

	typedef enum {
	ETAT_1 = SM_StateMachineBase::SM_FIRST_STATE,

	FIN_MISSION
	}tState;
};

#endif // SM_RECUPERER_LES_CAISSES_VIDES_H
