#include <iostream>
#include <vector>
#include "PointMateriel.h"

using namespace std;

//==============================================
// Constructeurs
//==============================================
PointMateriel::PointMateriel(double m,  Vecteur pos,
    Vecteur v, Vecteur f)
: masse(m), etat(pos), 
    derivee_etat(v), champForces(f) {}

//==============================================
// Setter
//==============================================
void PointMateriel::set_masse(double m)
{
    masse = m;
}

void PointMateriel::set_etat(Vecteur const& pos)
{
    etat = pos;
}

void PointMateriel::set_derivee_etat(Vecteur const& v)
{
    derivee_etat = v;
}

void PointMateriel::set_champForce(Vecteur const& f)
{
    champForces = f;
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

Vecteur PointMateriel::get_champForces() const
{
    return champForces;
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

Vecteur PointMateriel::evolution(double temps) const
{
    return (1/masse)*champForces;
}

//==============================================
// Surcharge opérateurs externes
//==============================================
ostream& operator<<(ostream& sortie, PointMateriel const& p)
{
    sortie<<"Masse : "<<p.get_masse()<<" kg"<<endl;

    sortie<<"Position : ";
    Vecteur pos(p.position());
    for(size_t i(0); i<3; i++) sortie<<pos.get_coord(i)<<" ";
    
    sortie<<"\nVitesse : ";
    Vecteur v(p.vitesse());
    for(size_t i(0); i<3; i++) sortie<<v.get_coord(i)<<" ";

    sortie<<"\nForce : ";
    Vecteur f(p.get_champForces());
    for(size_t i(0); i<3; i++) sortie<<f.get_coord(i)<<" ";
    
    return sortie;
}