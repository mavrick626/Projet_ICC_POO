#include "Systeme.h"
#include <iostream>
#include <cstdio>
#include <memory>

using namespace std;

//==============================================
// Constructeur
//==============================================
Systeme::Systeme()
: integrateur(nullptr), temps(0.) {}

//==============================================
// Méthodes ajout éléments
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

//==============================================
// Méthodes attribution champ/contrainte
//==============================================
void Systeme::attribuer_cont(size_t i, size_t j)
{
    if(i<contraintes.size() && j<objets.size())
    {
        (*objets[j]).set_contrainte(&(*contraintes[i]));
    }
}

void Systeme::attribuer_champ(size_t i, size_t j)
{
    if(i<contraintes.size() && j<objets.size())
    {
        (*objets[j]).set_champ(&(*champs[i]));
    }
}

//==============================================
// Méthodes
//==============================================
void Systeme::evolue()
{
    for(auto& pt_obj : objets)
    {
        if(pt_obj->get_champs() != nullptr) integrateur->integre((*pt_obj), temps);
    }

    temps += integrateur->get_dt();
}   

void Systeme::affiche(ostream& sortie) const
{
    sortie<<"Systeme a t = "<<temps<<" : "<<endl;
    for(size_t i(0); i<objets.size(); i++)
    {
        sortie<<"Objet no "<<i+1<<" : "<<endl;
        sortie<<*objets[i]<<endl<<endl;
    }
    sortie<<endl;

    for(size_t i(0); i<champs.size(); i++)
    {
        sortie<<"Champ no "<<i+1<<" : ";
        sortie<<*champs[i]<<endl;
    }
    sortie<<endl;

    for(size_t i(0); i<contraintes.size(); i++)
    {
        sortie<<"Contrainte no "<<i+1<<" : ";
        sortie<<*contraintes[i]<<endl;
    }
    sortie<<endl;

    sortie<<"-------------------------------------------"<<endl;
}

void Systeme::affiche_pos(ostream& sortie) const
{
    sortie<<"Positions a t = "<<temps<<" : "<<endl;
    for(size_t i(0); i<objets.size(); i++)
    {
        sortie<<objets[i]->get_nom()<<" : ";
        sortie<<objets[i]->position()<<endl;
    }
    sortie<<"-------------------------------------------"<<endl;
}

void Systeme::affiche_gnu(FILE* f) const
{
    for(auto const& obj : objets)
    {
        Vecteur const& pos(obj->position());
        fprintf(f, "%f %f\n", pos.get_coord(0), pos.get_coord(2));
    }
}
//==============================================
// Surcharge opérateur
//==============================================
ostream& operator<<(ostream& sortie, Systeme const& sys)
{
    sys.affiche(sortie);
    return sortie;
}