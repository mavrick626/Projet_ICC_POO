#include "Systeme.h"
#include <iostream>
#include <cstdio>
#include <memory>

using namespace std;

//==============================================
// Constructeur
//==============================================
Systeme::Systeme(double t)
: integrateur(nullptr), temps(t) { if(t<0) temps=0.;}

//==============================================
// Méthodes d'ajout des différentes types d'éléments
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
// Méthodes attribution du champ/contrainte i à l'objet j
//==============================================
void Systeme::attribuer_cont(size_t i, size_t j)
{
    if(i<contraintes.size() && j<objets.size())
    {
        (*objets[j]).set_contrainte(contraintes[i].get());
    }
}

void Systeme::attribuer_champ(size_t i, size_t j)
{
    if(i<contraintes.size() && j<objets.size())
    {
        (*objets[j]).set_champ(champs[i].get());
    }
}

//==============================================
// Evolution, fais évoluer tous les objets du système
//==============================================
void Systeme::evolue()
{
    if(integrateur != nullptr)
    {
        temps += integrateur->get_dt();
        for(auto& pt_obj : objets)
        {
            if(pt_obj->get_champs() != nullptr) integrateur->integre((*pt_obj), temps);
        }
    }
    else cerr<<"Le systeme n'a pas d'integrateur,  evolution impossible !"<<endl;
}   

//==============================================
// Différents formats d'affichage (Text, Position, Gnuplot)
//==============================================
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

void Systeme::affiche_gnu(FILE* f, size_t x, size_t y) const
{
    for(auto const& obj : objets)
    {
        Vecteur const& pos(obj->position());
        fprintf(f, "%f %f\n", pos.get_coord(x), pos.get_coord(y));
    }
}

//==============================================
// Surcharge de l'opérateur d'affichage
//==============================================
ostream& operator<<(ostream& sortie, Systeme const& sys)
{
    sys.affiche(sortie);
    return sortie;
}