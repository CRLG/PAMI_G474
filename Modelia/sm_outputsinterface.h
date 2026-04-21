#ifndef SM_OUTPUTSINTERFACE_H
#define SM_OUTPUTSINTERFACE_H


class SM_OutputsInterface
{
public:
    SM_OutputsInterface();

    void init();

    // Asservissement
    void CommandeMouvementXY_sym(float x, float y);                     // Consignes vers l'asserv tenant compte de la couleur
    void CommandeMouvementXY_TETA_sym(float x, float y, float teta);    // de l'équipe pour inverser les mouvements
    void setPosition_XYTeta_sym(float x, float y, float teta);

    void stopAll();

};

#endif // SM_OUTPUTSINTERFACE_H
