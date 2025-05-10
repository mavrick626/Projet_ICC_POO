#include <iostream>
#include "ObjetMobile.h"

using namespace std;

//==============================================
// Constructeurs
//==============================================
ObjetMobile::ObjetMobile(Vecteur const& e, Vecteur const& e_point)
: E(e), E_point(e_point) {}

//==============================================
// Getter
//==============================================
Vecteur ObjetMobile::get_E() const
{
    return E;
}

Vecteur ObjetMobile::get_E_point() const
{
    return E_point;
}

//==============================================
// Setter
//==============================================
void ObjetMobile::set_E(Vecteur const& new_E) 
{
    E = new_E;
}

void ObjetMobile::set_E_point(Vecteur const& new_E_point) 
{
    E_point = new_E_point;
}

//==============================================
// Méthode d'affichage au niveau de l'objet mobile
//==============================================
void ObjetMobile::afficher(ostream& sortie) const
{
    sortie<<E<<" # parametre"<<endl;
    sortie<<E_point<<" # vitesse";
}

//==============================================
// Surcharge opérateurs d'affichage
//==============================================
ostream& operator<<(ostream& sortie, ObjetMobile const& obj)
{
    obj.afficher(sortie);
    return sortie;
}