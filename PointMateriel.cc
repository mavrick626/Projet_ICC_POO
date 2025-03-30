#include <iostream>
#include "PointMateriel.h"

using namespace std;

//==============================================
// Constructeurs
//==============================================
PointMateriel::PointMateriel(ChampsForce* gc, Contrainte* cont, double m,
    Vecteur const& p, Vecteur const& v)
: ObjetPhysique(p, v, m, gc, cont) {}

//==============================================
// Autres méthodes
//==============================================
Vecteur PointMateriel::evolution(double temps) const
{
    return (*champs).force(*this)*(1/masse);
}

//==============================================
// Surcharge opérateurs externes
//==============================================
ostream& operator<<(ostream& sortie, PointMateriel const& p)
{
    sortie<<"Masse : "<<p.get_masse()<<" kg"<<endl;
    sortie<<"Position : "<<p.get_E()<<endl;
    sortie<<"Vitesse : "<<p.get_E_point();
    
    return sortie;
}