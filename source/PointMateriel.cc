#include <iostream>
#include "PointMateriel.h"

using namespace std;

//==============================================
// Constructeurs
//==============================================
PointMateriel::PointMateriel(string const& n, double m,ChampForce* gc, Contrainte* cont,
    Vecteur const& p, Vecteur const& v, unsigned int dim_esp_ph)
: ObjetPhysique(n, m, p, v, gc, cont, dim_esp_ph) {}

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