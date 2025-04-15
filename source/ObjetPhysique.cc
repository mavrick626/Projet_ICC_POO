#include <iostream>
#include "ObjetPhysique.h"

using namespace std;

//==============================================
// Constructeur
//==============================================
ObjetPhysique::ObjetPhysique(string const& n, Vecteur const& e, Vecteur const& e_point, double m, 
    ChampForce* champ, Contrainte* cont, unsigned int dim_esp_ph)
: ObjetMobile(e, e_point), nom(n), masse(m),
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

string ObjetPhysique::get_nom() const
{
    return nom;
}

ChampForce* ObjetPhysique::get_champs() const
{
    return champs;
}

//==============================================
// Setter
//==============================================
void ObjetPhysique::set_nom(string const& n)
{
    nom = n;
}

void ObjetPhysique::set_contrainte(Contrainte* pt_cont)
{
    contraintes = pt_cont;
}

void ObjetPhysique::set_champ(ChampForce* pt_champ)
{
    champs = pt_champ;
}

//==============================================
// Méthodes
//==============================================
Vecteur ObjetPhysique::force(double t) const
{
    return champs->force(*this);
}

Vecteur ObjetPhysique::position() const
{
    return contraintes->position(*this);
}

Vecteur ObjetPhysique::vitesse() const
{
    return contraintes->vitesse(*this);
}

//==============================================
// Surhcarge opérateurs externes
//==============================================
ostream& operator<<(ostream& sortie, ObjetPhysique const& obj)
{
    sortie<<obj.get_nom()<<endl;
    sortie<<obj.get_E()<<" # parametre"<<endl;
    sortie<<obj.get_E_point()<<" # vitesse"<<endl;
    sortie<<obj.position()<<" # position physique"<<endl;
    sortie<<obj.vitesse()<<" # vitesse physique"<<endl;
    sortie<<obj.get_masse()<<" # masse"<<endl;

    return sortie;
}