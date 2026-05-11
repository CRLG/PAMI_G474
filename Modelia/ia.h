#ifndef IA_H
#define IA_H

#include "iabase.h"
#include "sm_autotest.h"

#include "sm_debuginterface.h"
#include "sm_blockly_debutant.h"
#include "sm_vider_les_frigos.h"
#include "sm_remplir_les_frigos.h"
#include "sm_recuperer_les_caisses_vides.h"

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
    SM_TachePostMatch                   m_sm_tache_post_match;
    SM_TacheAvantMatch                  m_sm_tache_avant_match;

    // PAMI Ninja
    SM_recuperer_les_caisses_vides      m_sm_recuperer_les_caisses_vides;
    SM_vider_les_frigos                 m_sm_vider_les_frigos;
    SM_remplir_les_frigos               m_sm_remplir_les_frigos;

    void step();
    void init();
    void match_started();
    void match_finished();

    void setStrategie(unsigned char strategie);
    void setMaxScores();
};

#endif // IA_H
