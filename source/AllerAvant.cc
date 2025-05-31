#include "AllerAvant.h"
#include <iostream>

using namespace std;

//==============================================
// Constructeur
//==============================================
AllerAvant::AllerAvant(double v, double t)
: v_scalaire(v), temps(t) {}

//==============================================
// Méthodes calcul force, position, vitesse
//==============================================
Vecteur AllerAvant::applique_force(ObjetPhysique const& obj, Vecteur const& force, double t) 
{
    set_temps(t);
    Vecteur f_prime({force.get_coord(0), force.get_coord(2)});
    if(obj.get_masse() != 0) return f_prime*(1/obj.get_masse()); // a = F/m
    return force;
}

/* La position et la vitesse sont des vecteurs dans l'espace physique réel du l'objet(R3). 
La première coordonnée est la position (v*t) et la vitesse de la contrainte. Les autres
sont simplement les coordonnées des vecteurs E, E_p sur les autres degrés de libretés. */
Vecteur AllerAvant::position(ObjetPhysique const& obj) const
{
    Vecteur pos(obj.get_dim_espace_physique());

    pos.set_coord(0, temps*v_scalaire);
    for(size_t i(0); i<pos.dimension()-1; i++)
    {
        if(i<obj.get_E().dimension()) pos.set_coord(i+1, obj.get_E().get_coord(i));
        else pos.set_coord(i, 0.); // on remplit avec des 0 s'il y a trop peu de degré de liberté
    }

    return pos;
}

Vecteur AllerAvant::vitesse(ObjetPhysique const& obj) const
{
    Vecteur vit(obj.get_dim_espace_physique());

    vit.set_coord(0, v_scalaire);
    for(size_t i(0); i<vit.dimension()-1; ++i)
    {
        if(i<obj.get_E().dimension()) vit.set_coord(i+1, obj.get_E_point().get_coord(i));
        else vit.set_coord(i, 0.);
    }

    return vit;
}

// MAJ du temps de la contrainte
void AllerAvant::set_temps(double t)
{
    temps = t;
}

void AllerAvant::affiche(ostream& sortie) const
{
    sortie<<"Contrainte aller de l'avant : ";
    sortie<<"v = "<<v_scalaire;
}

