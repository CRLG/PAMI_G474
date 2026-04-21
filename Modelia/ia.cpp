// ________________________________________________
// !! ATTENTION !!
// Ce code est commun aux projets du robot réel et simulation
// Il ne doit pas y avoir de code spécifique CPU
//  ou d'appel à une classe non gérée par une couche d'abstraction
//  au risque de ne plus pouvoir tourner en simulation

#include "ia.h"
#include "CGlobale.h"
#include "ConfigSpecifiqueCoupe.h"
#include "math.h"

IA::IA()
    : IABase()
{
    m_sm_liste[m_state_machine_count++] = &m_sm_autotest;
    m_sm_liste[m_state_machine_count++] = &m_sm_tache1;
    m_sm_liste[m_state_machine_count++] = &m_sm_tache2;
    m_sm_liste[m_state_machine_count++] = &m_sm_tache3;
    m_sm_liste[m_state_machine_count++] = &m_sm_tache4;
    m_sm_liste[m_state_machine_count++] = &m_sm_tache5;
    m_sm_liste[m_state_machine_count++] = &m_sm_tache6;
    m_sm_liste[m_state_machine_count++] = &m_sm_tache7;
    m_sm_liste[m_state_machine_count++] = &m_sm_tache8;
    m_sm_liste[m_state_machine_count++] = &m_sm_tache9;
    m_sm_liste[m_state_machine_count++] = &m_sm_tache10;
}

// ________________________________________________
void IA::init()
{
    m_inputs_interface.TE_Modele = PERIODE_APPEL_MODELIA;
    m_datas_interface.init();
    m_inputs_interface.init();
    m_outputs_interface.init();
    for (int i=0; i<m_state_machine_count; i++) {
        if (m_sm_liste[i]) {
            m_sm_liste[i]->init(this);
        }
    }
    setMaxScores();

    m_sm_main.start();
}

// ________________________________________________
void IA::match_started()
{
    //Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)DECO_LED_CRLG, true);
    //m_outputs_interface.setPosition_XYTeta_sym(0, 0, M_PI/2); // pour l'année 2025 Teta=PI/2
	//Application.m_leds_rgb.setColor(4, RGBColor::BLUE, 10);
	Application.m_leds_rgb.setPattern(4, 5, 5);
}

// ________________________________________________
void IA::match_finished()
{
    //Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)DECO_LED_CRLG, false);
	Application.m_leds_rgb.setColor(4, RGBColor::GREEN, 5);
	Application.m_leds_rgb.setColor(5, RGBColor::GREEN, 5);
	m_sm_tache10.start();
}

// ________________________________________________
// Définit l'ordre d'exécution des "main missions"
// sm_xxxx.setPrioriteExecution(ordre++);
//      Active la mission xxx
//      Lui fixe une priorité d'exécution (0 étant la priorité la plus haute)
void IA::setStrategie(unsigned char strategie)
{
    int ordre = 0;
    resetAllSMPriority();
    disableAllSM(); // Désactive toutes les SM par défaut (elles seront activées une par une avec la priorité associée en fonction de la stratégie)

    //strategie = STRATEGIE_PAR_DEFAUT;
    switch (strategie) {
    // ________________________
    case STRATEGIE_01:
    default :
        m_datas_interface.choix_algo_next_mission = ALGO_PERTINENT_MISSION_CHOIX_PRIORITE;
        m_datas_interface.evit_inhibe_obstacle=false;
        Application.m_detection_obstacles.setSeuilDetectionObstacle(SEUIL_DETECTION_OBSTACLE);
        Application.m_detection_obstacles.inhibeDetection(false);
        Application.m_asservissement.CommandeVitesseMouvement(40.,2); //normalement 80 cm.s-1 et 3 rad.s-1
        Application.m_asservissement.setIndiceSportivite(0.5);
        m_datas_interface.evit_choix_strategie= SM_DatasInterface::STRATEGIE_EVITEMENT_ATTENDRE;
        m_datas_interface.evit_nombre_max_tentatives=1;

        m_sm_tache1.setPrioriteExecution(ordre++);

        break;
    }

    m_datas_interface.ChoixStrategieMatch = strategie;
}

// ________________________________________________
void IA::setMaxScores()
{
    // TODO : valeurs des scores max fixées au pif.
    // Mettre les vraies valeurs
}

// ________________________________________________
// TODO : à voir sur le long terme si la couche de recopie des donées
// externes dans m_inputs_interface.xxxx est toujours nécessaire
// ou si le modèle ne peut pas utiliser directement Application.m_xxxxx.yyyy
void IA::step()
{

	// ......
	m_inputs_interface.Tirette = HAL_GetTick() > 2000 && Application.m_detection_obstacles.isObstacleAR() && Application.m_detection_obstacles.isObstacleAV();

    stepAllStateMachines();
}

