#ifndef SM_INPUTSINTERFACE_H
#define SM_INPUTSINTERFACE_H

class SM_InputsInterface
{
public:
    SM_InputsInterface();

    void init();

    bool dde_test_actionneurs;
    bool dde_couleur_equipe;

    float TE_Modele;

    int Tirette;

    // Détection d'obstacles
    bool obstacle_AV;
    bool obstacle_AR;
    bool obstacleDetecte;

    float Telemetre_AV;
    float Telemetre_AR;

    // Sortie de l'asservissement
    float X_robot;
    float Y_robot;
    float angle_robot;

    bool Convergence;
    bool Convergence_old;
    bool FrontM_Convergence;
    bool Convergence_rapide;
    bool Convergence_rapide_old;
    bool FrontM_Convergence_rapide;

    // Bouchon
    bool FrontM_ConvergenceRack;
    bool ConvergenceKmar;
};

#endif // SM_INPUTSINTERFACE_H
