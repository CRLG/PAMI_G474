/**
 * Fichier généré le : 20260421_132805
 */

#include "sm_blockly_debutant.h"
#include "CGlobale.h"


// _____________________________________
#define SM_Tache1_Generated
void SM_Tache1::step()
{
    switch (m_state)
    {
      case STATE_1 :
          if (onEntry()) {
            Application.m_asservissement.CommandeManuelle(10, 10);
          }
          gotoStateAfter(STATE_2, 1000);
          if (onExit()) {
            Application.m_asservissement.CommandeManuelle(0, 0);
          }
          break;
      case STATE_2 :
          if (onEntry()) {
            Application.m_asservissement.CommandeManuelle(0, 0);
          }
          gotoStateAfter(STATE_3, 1000);
          if (onExit()) {
            Application.m_asservissement.CommandeManuelle(0, 0);
          }
          break;
      case STATE_3 :
          if (onEntry()) {
            Application.m_modelia.m_sm_tache2.start();
          }
          gotoState(STATE_4);
          if (onExit()) { }
          break;
      case STATE_4 :
          if (onEntry()) {
            Application.m_asservissement.CommandeManuelle((-10), (-10));
          }
          gotoStateAfter(STATE_5, 1000);
          if (onExit()) {
            Application.m_asservissement.CommandeManuelle(0, 0);
          }
          break;
      case STATE_5 :
          if (onEntry()) {
            Application.m_asservissement.CommandeManuelle(0, 0);
          }
          gotoStateAfter(STATE_6, 1000);
          if (onExit()) {
            Application.m_asservissement.CommandeManuelle(0, 0);
          }
          break;
    }
}


// _____________________________________
#define SM_Tache2_Generated
void SM_Tache2::step()
{
    switch (m_state)
    {
      case STATE_1 :
          if (onEntry()) {
            Application.m_servos.CommandePositionVitesse(4, 1500, 9999);
          }
          gotoState(STATE_2);
          if (onExit()) {
          }
          break;
      case STATE_2 :
          if (onEntry()) {
          }
          gotoStateAfter(STATE_3, 1000);
          if (onExit()) { }
          break;
      case STATE_3 :
          if (onEntry()) {
            Application.m_servos.CommandePositionVitesse(4, 1000, 9999);
          }
          gotoState(STATE_4);
          if (onExit()) {
          }
          break;
      case STATE_4 :
          if (onEntry()) {
          }
          gotoStateAfter(STATE_5, 1000);
          if (onExit()) { }
          break;
      case STATE_5 :
          if (onEntry()) {
            Application.m_servos.CommandePositionVitesse(4, 2000, 5);
          }
          gotoState(STATE_6);
          if (onExit()) {
          }
          break;
    }
}


// _____________________________________
#define SM_Tache10_Generated
void SM_Tache10::step()
{
    switch (m_state)
    {
      case STATE_1 :
          if (onEntry()) {
            Application.m_servos.CommandePositionVitesse(4, 1000, 10);
          }
          gotoState(STATE_2);
          if (onExit()) {
          }
          break;
      case STATE_2 :
          if (onEntry()) {
          }
          gotoStateAfter(STATE_3, 3000);
          if (onExit()) { }
          break;
      case STATE_3 :
          if (onEntry()) {
            Application.m_servos.CommandePositionVitesse(4, 2000, 10);
          }
          gotoState(STATE_4);
          if (onExit()) {
          }
          break;
      case STATE_4 :
          if (onEntry()) {
          }
          gotoStateAfter(STATE_5, 3000);
          if (onExit()) { }
          break;
      case STATE_5 :
          if (onEntry()) {
          }
          gotoState(STATE_1);
          if (onExit()) { }
          break;
    }
}



// --------------------------------------------
// Bouchon pour chaque SM qui ne serait pas utilisée dans Blockly
#ifndef SM_Tache1_Generated
void SM_Tache1::step()
{
}
#endif // #ifndef SM_Tache1_Generated

#ifndef SM_Tache2_Generated
void SM_Tache2::step()
{
}
#endif // #ifndef SM_Tache2_Generated

#ifndef SM_Tache3_Generated
void SM_Tache3::step()
{
}
#endif // #ifndef SM_Tache3_Generated

#ifndef SM_Tache4_Generated
void SM_Tache4::step()
{
}
#endif // #ifndef SM_Tache4_Generated

#ifndef SM_Tache5_Generated
void SM_Tache5::step()
{
}
#endif // #ifndef SM_Tache5_Generated

#ifndef SM_Tache6_Generated
void SM_Tache6::step()
{
}
#endif // #ifndef SM_Tache6_Generated

#ifndef SM_Tache7_Generated
void SM_Tache7::step()
{
}
#endif // #ifndef SM_Tache7_Generated

#ifndef SM_Tache8_Generated
void SM_Tache8::step()
{
}
#endif // #ifndef SM_Tache8_Generated

#ifndef SM_Tache9_Generated
void SM_Tache9::step()
{
}
#endif // #ifndef SM_Tache9_Generated

#ifndef SM_Tache10_Generated
void SM_Tache10::step()
{
}
#endif // #ifndef SM_Tache10_Generated
