#include <iostream>
#include "ObjetPhysique.h"

using namespace std;

//==============================================
// Constructeur
//==============================================
ObjetPhysique::ObjetPhysique(string const& n,  double m, Vecteur const& e, Vecteur const& e_point,
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

void ObjetPhysique::afficher(ostream& sortie) const
{
    sortie<<nom<<endl;
    ObjetMobile::afficher(sortie); sortie<<endl;
    sortie<<position()<<" # position physique"<<endl;
    sortie<<vitesse()<<" # vitesse physique"<<endl;
    sortie<<masse<<" # masse"<<endl;
    sortie<<"contrainte : "<<*contraintes;
}

//==============================================
// Surhcarge opérateurs externes
//==============================================
ostream& operator<<(ostream& sortie, ObjetPhysique const& obj)
{
    obj.afficher(sortie);
    return sortie;
}