#include <iostream>
#include "GravitationConstante.h"

using namespace std;

//==============================================
// Constructeur
//==============================================
GravitationConstante::GravitationConstante(Vecteur const& forces)
: gravitation(forces) {}

//==============================================
// Méthodes
//==============================================
Vecteur GravitationConstante::force(ObjetPhysique const& p, double t) const
{
    // p = m*g
    return p.get_masse()*gravitation;
}

void GravitationConstante::afficher(ostream& sortie) const
{
    sortie<<"Champ gravitationnel : ";
    sortie<<gravitation;
}