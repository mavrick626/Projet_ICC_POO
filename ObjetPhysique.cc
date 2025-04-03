#include <iostream>
#include "ObjetPhysique.h"

using namespace std;

//==============================================
// Constructeur
//==============================================
ObjetPhysique::ObjetPhysique(Vecteur const& e, Vecteur const& e_point, double m, 
    ChampForce* champ, Contrainte* cont, unsigned int dim_esp_ph)
: ObjetMobile(e, e_point), masse(m),
    champs(champ), contraintes(cont), dim_espace_physique(dim_esp_ph) {}

//==============================================
// Déstructeur
//==============================================
ObjetPhysique::~ObjetPhysique()
{
    // Supression des pointeurs
    delete champs;
    delete contraintes;
}

//==============================================
// Getter
//==============================================
double ObjetPhysique::get_masse() const
{
    return masse;
}

//==============================================
// Méthodes
//==============================================
Vecteur ObjetPhysique::force(double t) const
{
    return (*champs).force(*this);
}

Vecteur ObjetPhysique::position() const
{
    return (*contraintes).position(*this);
}

Vecteur ObjetPhysique::vitesse() const
{
    return (*contraintes).vitesse(*this);
}

//==============================================
// Surhcarge opérateurs externes
//==============================================
ostream& operator<<(ostream& sortie, ObjetPhysique const& obj)
{
    sortie<<"Masse : "<<obj.get_masse()<<endl;
    sortie<<"Etat : "<<obj.get_E()<<endl;
    sortie<<"Derivee etat : "<<obj.get_E_point();

    return sortie;
}