#include "IntegrateurEulerCromer.h"
#include "Vecteur.h"

IntegrateurEulerCromer::IntegrateurEulerCromer(double dt)
: dt(dt) {}

void IntegrateurEulerCromer::integre(ObjetMobile& obj, double t, double dt) const
{
    size_t dim(obj.get_E().dimension());
    Vecteur E(dim);
    Vecteur E_point(dim);

    E_point = obj.get_E_point() + dt*obj.evolution(t);
    E = obj.get_E() + dt*E_point;

    obj.set_E(E);
    obj.set_E_point(E_point);
}