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
void PointMateriel::set_position(Vecteur const& pos)
{
    etat = pos;
}

void PointMateriel::set_vitesse(Vecteur const& v)
{
    derivee_etat = v;
}

//==============================================
// Getter
//==============================================
Vecteur PointMateriel::get_position() const
{
    return etat;
}

Vecteur PointMateriel::get_vitesse() const
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

double PointMateriel::evolution(double temps)
{
    return temps;
}