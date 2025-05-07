#include "IntegrateurRungeKutta.h"

IntegrateurRungeKutta::IntegrateurRungeKutta(double dt)
: Integrateur(dt) {}

void IntegrateurRungeKutta::integre(ObjetMobile& obj, double t, double dt) const
{
    double delta(dt);
    if(delta == 0.) delta = Integrateur::dt;

    Vecteur k1(obj.get_E_point());
    Vecteur k1_p(obj.evolution(t));
    Vecteur k2(k1 + (delta/2)*k1_p);
    Vecteur k2_p(obj.evolution(t+(delta/2)));
    Vecteur k3(k1 + (delta/2)*k2_p);
    Vecteur k3_p(obj.evolution(t+(delta/2)));
    Vecteur k4(k1 + delta*k3_p);
    Vecteur k4_p(obj.evolution(t+delta));

    obj.set_E(obj.get_E() + (delta/6)*(k1+2*k2+2*k3+k4));
    obj.set_E_point(k1 + (delta/6)*(k1_p+2*k2_p+2*k3_p+k4_p));
}