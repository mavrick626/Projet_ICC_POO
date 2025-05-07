#include <IntegrateurNewmark.h>
#include <cmath>

IntegrateurNewmark::IntegrateurNewmark(double dt)
: Integrateur(dt) {}

void IntegrateurNewmark::integre(ObjetMobile& obj, double t, double dt) const
{
    double delta(dt);
    if(delta == 0.) delta = Integrateur::dt;

    const double epsilon(1e-6);

    Vecteur new_E_point(obj.get_E_point());
    Vecteur new_E(obj.get_E());
    Vecteur s(obj.evolution(t));
    Vecteur q(new_E);

    do
    {
        q = new_E;
        Vecteur r(obj.evolution(t+delta));
        new_E_point = obj.get_E_point() + (delta/2)*(r+s);
        new_E = obj.get_E() + delta*obj.get_E_point() + (pow(delta, 2)/6)*(r + 2*s);
    }while((new_E - q).norme() >= epsilon);

    obj.set_E(new_E);
    obj.set_E_point(new_E_point);
}