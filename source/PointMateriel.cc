#include <iostream>
#include "PointMateriel.h"

using namespace std;

//==============================================
// Constructeurs
//==============================================
PointMateriel::PointMateriel(string const& n,ChampForce* gc, Contrainte* cont, double m,
    Vecteur const& p, Vecteur const& v)
: ObjetPhysique(n, p, v, m, gc, cont) {}

//==============================================
// Autres méthodes
//==============================================
Vecteur PointMateriel::evolution(double temps) const
{
    return champs->force(*this) * (1/masse);
}

//==============================================
// Surcharge opérateurs externes
//==============================================
ostream& operator<<(ostream& sortie, PointMateriel const& p)
{
    sortie<<p.get_nom()<<endl;
    sortie<<p;
    
    return sortie;
}