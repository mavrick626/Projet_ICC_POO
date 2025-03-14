#include <iostream>
#include <vector>
#include "PointMateriel.h"

using namespace std;

//==============================================
// Constructeurs
//==============================================
PointMateriel::PointMateriel()
: PointMateriel(0., Vecteur(0., 0., 0.) ,Vecteur(0., 0., 0.), Vecteur(0., 0., 0.)) {}

PointMateriel::PointMateriel(double m,  Vecteur pos,
    Vecteur v, Vecteur f)
: masse(m), etat(pos), 
    derivee_etat(v), ChampForces(f) {}

//==============================================
// Setter
//==============================================
void PointMateriel::set_etat(Vecteur const& pos)
{
    etat = pos;
}

void PointMateriel::set_derivee_etat(Vecteur const& v)
{
    derivee_etat = v;
}

//==============================================
// Getter
//==============================================
double PointMateriel::get_masse() const
{
    return masse;
}

Vecteur PointMateriel::get_etat() const
{
    return etat;
}

Vecteur PointMateriel::get_derivee_etat() const
{
    return derivee_etat;
}

//==============================================
// Autres méthodes
//==============================================
Vecteur PointMateriel::position() const
{
    return etat;
}

Vecteur PointMateriel::vitesse() const
{
    return derivee_etat;
}

Vecteur PointMateriel::evolution(double temps)
{
    return (1/masse)*ChampForces;
}

//==============================================
// Surcharge opérateurs externes
//==============================================
ostream& operator<<(ostream& sortie, PointMateriel const& p)
{
    sortie<<"Masse : "<<p.get_masse()<<"Kg"<<endl;
    sortie<<"Position : ";
    for(size_t i(0); i<3; i++) sortie<<p.position().get_coord(i)<<" ";
    sortie<<"\nVitesse : ";
    for(size_t i(0); i<3; i++) sortie<<p.vitesse().get_coord(i)<<" ";
    
    return sortie;
}