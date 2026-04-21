#ifndef IA_H
#define IA_H

#include "iabase.h"
#include "sm_autotest.h"

#include "sm_debuginterface.h"
#include "sm_blockly_debutant.h"

class IA : public IABase
{
public:
    IA();

    // States machines
    SM_Autotest                         m_sm_autotest;
    // SM blockly
    SM_Tache1                           m_sm_tache1;
    SM_Tache2                           m_sm_tache2;
    SM_Tache3                           m_sm_tache3;
    SM_Tache4                           m_sm_tache4;
    SM_Tache5                           m_sm_tache5;
    SM_Tache6                           m_sm_tache6;
    SM_Tache7                           m_sm_tache7;
    SM_Tache8                           m_sm_tache8;
    SM_Tache9                           m_sm_tache9;
    SM_Tache10                          m_sm_tache10;

    void step();
    void init();
    void match_started();
    void match_finished();

    void setStrategie(unsigned char strategie);
    void setMaxScores();
};

#endif // IA_H
