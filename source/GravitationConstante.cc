#include <iostream>
#include "GravitationConstante.h"

using namespace std;

//==============================================
// Constructeur
//==============================================
GravitationConstante::GravitationConstante(Vecteur const& forces)
: gravitation(forces) {}

//==============================================
// Méthodes, force retourne le vecteur force p=mg
//==============================================
Vecteur GravitationConstante::force(ObjetPhysique const& p, double t) const
{
    return p.get_masse()*gravitation;
}

// Override de l'affichage
void GravitationConstante::afficher(ostream& sortie) const
{
    sortie<<"Champ gravitationnel : ";
    sortie<<gravitation;
}