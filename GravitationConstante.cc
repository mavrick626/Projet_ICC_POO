#include <iostream>
#include "GravitationConstante.h"

using namespace std;

//==============================================
// Constructeur
//==============================================
GravitationConstante::GravitationConstante(Vecteur forces)
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
Vecteur GravitationConstante::force(PointMateriel const& p, double t) const
{
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
    for(size_t i(0); i<3; i++) sortie<<force.get_coord(i)<<" ";
    sortie<<"\nIntensite : "<<force.norme()<<" N";

    return sortie;
}