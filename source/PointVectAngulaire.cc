#define _USE_MATH_DEFINES
#include <cmath>
#include "PointVectAngulaire.h"

using namespace std;

//==============================================
// Constructeur
//==============================================
PointVectAngulaire::PointVectAngulaire(string const& n, double m, double q, Vecteur const& p, 
Vecteur const& v, ChampForce* ch, Contrainte* cont, unsigned int dim_esp_ph)
: PointMateriel(n ,m, q, p, v, ch, cont, dim_esp_ph) { renormaliser(); }

//==============================================
// Méthodes
//==============================================
void PointVectAngulaire::set_E(Vecteur const& e)
{
    ObjetMobile::set_E(e);
    renormaliser();
}

// normalise le vecteur d'état avec des valeurs dans l'intervalle [-2pi, 2pi]
void PointVectAngulaire::renormaliser()
{
    for(size_t i(0); i<E.dimension(); i++) 
    {
        double new_coord(fmod(E.get_coord(i), 2*M_PI));
        E.set_coord(i, new_coord);
    }
}