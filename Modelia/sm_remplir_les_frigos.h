/**
 * Built on 20260510_000824
 */

#ifndef SM_REMPLIR_LES_FRIGOS_H
#define SM_REMPLIR_LES_FRIGOS_H

#include "sm_statemachinebase.h"

class SM_remplir_les_frigos : public SM_StateMachineBase
{
public:
	SM_remplir_les_frigos();
	void step();
	const char* getName();
	const char* stateToName(unsigned short state);

	typedef enum {
	ETAT_1 = SM_StateMachineBase::SM_FIRST_STATE,

	FIN_MISSION
	}tState;
};

#endif // SM_REMPLIR_LES_FRIGOS_H
