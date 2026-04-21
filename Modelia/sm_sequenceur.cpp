#include "sm_sequenceur.h"
#include "ia.h"

SM_Sequenceur::SM_Sequenceur()
    : m_current_mission(nullptr)
{
}

const char* SM_Sequenceur::getName()
{
    return "SM_Sequenceur";
}

const char* SM_Sequenceur::stateToName(unsigned short state)
{
    switch(state)
    {
    case RECHERCHE_SEQUENCE_OPTIMUM :       return "RECHERCHE_SEQUENCE_OPTIMUM";
    case SEQUENCE_EN_COURS :                return "SEQUENCE_EN_COURS";
    case EVITEMENT_EN_COURS :               return "EVITEMENT_EN_COURS";
    }
    return "UNKNOWN_STATE";
}


// _____________________________________
void SM_Sequenceur::step()
{
    IA::tAlgoNextPertinentMission algo_next_mission = (IA::tAlgoNextPertinentMission)internals()->choix_algo_next_mission;

    switch(m_state)
    {
    // ___________________________________
    case RECHERCHE_SEQUENCE_OPTIMUM :
        if (onEntry()) {
        }

        m_current_mission = m_ia->activeNextPertinentMainMission(algo_next_mission);
        if (m_current_mission != 0) {
            gotoState(SEQUENCE_EN_COURS);
        }

        if (onExit()) { }
        break;
    // ___________________________________
    case SEQUENCE_EN_COURS :
        if (onEntry()) {
        }

        if (inputs()->obstacleDetecte) {
            m_current_mission->interruptForEvitement();
            m_ia->m_sm_evitement.start();
            gotoState(EVITEMENT_EN_COURS);
        }
        // Si la mission en cours est achevée, passe à la suivante
        else if (m_ia->isOneMainMissionActive() == false) {
            gotoState(RECHERCHE_SEQUENCE_OPTIMUM);
        }

        // Resynchronise la machine d'état au cas où l'évitement d'obstacle soit déclenché à l'initiative d'une aurte SM
        if (m_ia->m_sm_evitement.isActive()) { gotoState(EVITEMENT_EN_COURS); }

        if (onExit()) { }
        break;
    // ___________________________________
    case EVITEMENT_EN_COURS :
        if (onEntry()) {
        }

        // Evitement terminé : retour aux missions avec possibilité de choisir le comportement au retour d'évitement
        if (!m_ia->m_sm_evitement.isActive()) {
            if (internals()->evit_comportement_retour_evitement == SM_Sequenceur::RETOUR_EVIT_REPRENDS_MISSION_INTERROMPUE) {
                if (m_current_mission && !m_current_mission->isSucces()) {
                    m_current_mission->start();
                    gotoState(SEQUENCE_EN_COURS);
                }
                else { gotoState(RECHERCHE_SEQUENCE_OPTIMUM); }
            }
            else {
                gotoState(RECHERCHE_SEQUENCE_OPTIMUM);
            }
        }

        if (onExit()) {
        }
        break;
    }
}
