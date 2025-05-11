#include "AllerAvant.h"
#include <iostream>

using namespace std;

AllerAvant::AllerAvant(double v, double t)
: v_scalaire(v), temps(t) {}

Vecteur AllerAvant::applique_force(ObjetPhysique const& obj, Vecteur const& force, double t) 
{
    set_temps(t);
    if(obj.get_masse() != 0) return force*(1/obj.get_masse()); // a = F/m
    return force;
}

Vecteur AllerAvant::position(ObjetPhysique const& obj) const
{
    Vecteur pos(obj.get_dim_espace_physique());

    pos.set_coord(0, obj.get_E().get_coord(0)+temps*v_scalaire);
    for(size_t i(1); i<pos.dimension(); i++)
    {
        pos.set_coord(i, obj.get_E().get_coord(i));
    }
    
    return pos;
}

Vecteur AllerAvant::vitesse(ObjetPhysique const& obj) const
{
    Vecteur vit(obj.get_dim_espace_physique());

    vit.set_coord(0, v_scalaire);
    for(size_t i(1); i<vit.dimension(); ++i)
    {
        vit.set_coord(i, obj.get_E_point().get_coord(i));
    }

    return vit;
}

void AllerAvant::set_temps(double t)
{
    temps = t;
}

void AllerAvant::affiche(ostream& sortie) const
{
    sortie<<"Contrainte aller de l'avant : ";
    sortie<<"v = "<<v_scalaire;
}

