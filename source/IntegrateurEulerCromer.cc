#include "IntegrateurEulerCromer.h"
#include "Vecteur.h"
#include <iostream>

using namespace std;

//==============================================
// Constructeurs
//==============================================
IntegrateurEulerCromer::IntegrateurEulerCromer(double dt)
: Integrateur(dt) {}

//==============================================
// Méthode
//==============================================
void IntegrateurEulerCromer::integre(ObjetMobile& obj, double t, double dt) const
{
    double delta(dt);
    if(delta == 0.) delta = Integrateur::dt;

    size_t dim(obj.get_E().dimension());

    // Création nouveaux vecteurs dérivé/état
    Vecteur new_E(dim);
    Vecteur new_E_point(dim);

    // Formule cf.complément mathématique
    new_E_point = obj.get_E_point() + delta*obj.evolution(t);
    new_E = obj.get_E() + delta*new_E_point;

    obj.set_E(new_E);
    obj.set_E_point(new_E_point);

}