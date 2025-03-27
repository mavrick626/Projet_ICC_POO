#include <iostream>
#include <vector>
#include "PointMateriel.h"
#include "GravitationConstante.h"

using namespace std;

//==============================================
// Constructeurs
//==============================================
PointMateriel::PointMateriel(GravitationConstante* gc, double m,
    Vecteur const& pos, Vecteur const& v)
: masse(m), etat(pos), 
    derivee_etat(v), champForces(gc) {}

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

void PointMateriel::set_champForce(GravitationConstante* const f)
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

GravitationConstante* PointMateriel::get_champForces() const
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
    return (1/masse)*(*champForces).get_champs();
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
    
    return sortie;
}