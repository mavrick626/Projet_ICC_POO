#include <iostream>
#include "PointMateriel.h"

using namespace std;

//==============================================
// Constructeurs
//==============================================
PointMateriel::PointMateriel(string const& n, double m, double q, Vecteur const& p,
    Vecteur const& v, ChampForce* gc, Contrainte* cont, unsigned int dim_esp_ph)
: ObjetPhysique(n, m, q, p, v, gc, cont, dim_esp_ph) {}

//==============================================
// Autres méthodes
//==============================================
Vecteur PointMateriel::evolution(double temps) const
{
    return champs->force(*this) * (1/masse); // a = F/m
}

void PointMateriel::afficher(ostream& sortie) const
{
    ObjetPhysique::afficher(sortie);
}