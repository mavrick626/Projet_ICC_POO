#include <iostream>
#include "ObjetPhysique.h"

using namespace std;

//==============================================
// Constructeur
//==============================================
ObjetPhysique::ObjetPhysique(string const& n,  double m, double q, Vecteur const& e, Vecteur const& e_point,
    ChampForce* champ, Contrainte* cont, Integrateur* inte, unsigned int dim_esp_ph)
: ObjetMobile(e, e_point, inte), nom(n), masse(m), charge(q),
    champs(champ), contraintes(cont), dim_espace_physique(dim_esp_ph) {}

//==============================================
// Getter
//==============================================
string ObjetPhysique::get_nom() const
{
    return nom;
}

double ObjetPhysique::get_masse() const
{
    return masse;
}

double ObjetPhysique::get_q() const
{
    return charge;
}

unsigned int ObjetPhysique::get_dim_espace_physique() const
{
    return dim_espace_physique;
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
// Calcul de la force générée par le champ
Vecteur ObjetPhysique::force(double t) const
{
    if(champs != nullptr) return champs->force(*this);
    return Vecteur(E.dimension());
}

// Calcul des vecteurs position/vitesse physique selon la contrainte
Vecteur ObjetPhysique::position() const
{
    return contraintes->position(*this);
}

Vecteur ObjetPhysique::vitesse() const
{
    return contraintes->vitesse(*this);
}

// override de l'affichage
void ObjetPhysique::afficher(ostream& sortie) const
{
    sortie<<nom<<endl;
    ObjetMobile::afficher(sortie); sortie<<endl;
    if(contraintes != nullptr)
    {
        sortie<<position()<<" # position physique"<<endl;
        sortie<<vitesse()<<" # vitesse physique"<<endl;
    }
    sortie<<masse<<" # masse"<<endl;
    sortie<<charge<<" # charge elec"<<endl;
    if(contraintes != nullptr) sortie<<"contrainte : "<<*contraintes;
}

//==============================================
// Surhcarge opérateurs externes d'affichage
//==============================================
ostream& operator<<(ostream& sortie, ObjetPhysique const& obj)
{
    obj.afficher(sortie);
    return sortie;
}