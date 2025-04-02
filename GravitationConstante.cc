#include <iostream>
#include "GravitationConstante.h"

using namespace std;

//==============================================
// Constructeur
//==============================================
GravitationConstante::GravitationConstante(Vecteur const& forces)
: gravitation(forces) {}

//==============================================
// Getter
//==============================================
Vecteur GravitationConstante::get_champs() const
{
    return gravitation;
}

//==============================================
// Méthodes
//==============================================
Vecteur GravitationConstante::force(ObjetPhysique const& p, double t) const
{
    // p = m*g
    return p.get_masse()*gravitation;
}

//==============================================
// Surcharge opérateurs externes
//==============================================
ostream& operator<<(ostream& sortie, GravitationConstante const& champs)
{
    sortie<<"Champs de force : "<<endl;
    sortie<<"Vecteur : ";
    Vecteur force(champs.get_champs());
    sortie<<force;

    return sortie;
}