#include "IntegrateurRungeKutta.h"

//==============================================
// Constructeur
//==============================================
IntegrateurRungeKutta::IntegrateurRungeKutta(double dt)
: Integrateur(dt) {}

//==============================================
// Méthode intègre
//==============================================
void IntegrateurRungeKutta::integre(ObjetMobile& obj, double t) const
{
    // Calcul des 8 variable intermédiaires
    Vecteur k1(obj.get_E_point()); 
    Vecteur k1_p(obj.evolution(t));
    Vecteur k2(k1 + (dt/2)*k1_p);
    Vecteur k2_p(obj.evolution(t+(dt/2)));
    Vecteur k3(k1 + (dt/2)*k2_p);
    Vecteur k3_p(obj.evolution(t+(dt/2)));
    Vecteur k4(k1 + dt*k3_p);
    Vecteur k4_p(obj.evolution(t+dt));

    // MAJ de E et E. de l'objet
    obj.set_E(obj.get_E() + (dt/6)*(k1 + 2*k2 + 2*k3 + k4));
    obj.set_E_point(k1 + (dt/6)*(k1_p + 2*k2_p + 2*k3_p + k4_p));
}