#include "Systeme.h"
#include <iostream>
#include <memory>
#include <initializer_list>

using namespace std;

//==============================================
// Constructeur
//==============================================
Systeme::Systeme()
: integrateur(nullptr), temps(0.) {}

//==============================================
// Méthodes
//==============================================
void Systeme::ajout_inte(unique_ptr<Integrateur> && inte)
{
    integrateur = move(inte);
}

void Systeme::ajout_champ(unique_ptr<ChampForce> && champ)
{
    champs.push_back(move(champ));
}

void Systeme::ajout_contrainte(unique_ptr<Contrainte> && cont)
{
    contraintes.push_back(move(cont));
}

void Systeme::ajout_objet(unique_ptr<ObjetPhysique> && obj)
{
    objets.push_back(move(obj));
}

void Systeme::att_cont(size_t i, size_t j)
{
    if(i<contraintes.size() && j<objets.size())
    {
        (*objets[j]).set_contrainte(&(*contraintes[i]));
    }
}

void Systeme::att_champ(size_t i, size_t j)
{
    if(i<contraintes.size() && j<objets.size())
    {
        (*objets[j]).set_champ(&(*champs[i]));
    }
}

void Systeme::evolue()
{
    for(auto& pt_obj : objets)
    {
        if(pt_obj->get_champs() != nullptr) integrateur->integre((*pt_obj), temps);
    }

    temps += integrateur->get_dt();
}   

ostream& Systeme::affiche(ostream& sortie) const
{
    sortie<<"Systeme a t = "<<temps<<" : "<<endl;
    for(size_t i(0); i<objets.size(); i++)
    {
        sortie<<"Objet no "<<i+1<<" : "<<endl;
        sortie<<*objets[i]<<endl;
    }
    sortie<<"///////////////////////////////////////////////////"<<endl;

    return sortie;
}

//==============================================
// Surcharge opérateur
//==============================================
ostream& operator<<(ostream& sortie, Systeme const& sys)
{
    return sys.affiche(sortie);
}