#include <IntegrateurNewmark.h>
#include <cmath>
#include <iostream>
using namespace std;

//==============================================
// Constructeur
//==============================================
IntegrateurNewmark::IntegrateurNewmark(double dt, double e)
: Integrateur(dt), epsilon(e) {}

//==============================================
// Méthode
//==============================================
void IntegrateurNewmark::integre(ObjetMobile& obj, double t) const
{
    Vecteur ancien_E(obj.get_E());
    Vecteur ancien_E_point(obj.get_E_point());

    // Initialisation des variables (cf. complément math)
    Vecteur new_E_point(ancien_E_point);
    Vecteur new_E(ancien_E);
    Vecteur s(obj.evolution(t));
    Vecteur q(new_E);

    // Boucle itérative tant que E.(n+1) n'est pas épsilon proche de q
    do
    {
        q = new_E;

        obj.set_E(new_E); obj.set_E_point(new_E_point);
        Vecteur r(obj.evolution(t+dt));

        new_E_point = ancien_E_point + (dt/2)*(r+s);
        new_E = ancien_E + dt*ancien_E_point + (pow(dt, 2)/3)*(r*(1./2.) + s);
    }while((new_E - q).norme() > epsilon);

    // MAJ de E et E. de l'objet
    obj.set_E(new_E);
    obj.set_E_point(new_E_point);
}