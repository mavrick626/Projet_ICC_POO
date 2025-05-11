#include "AllerAvant.h"
#include <iostream>

using namespace std;

AllerAvant::AllerAvant(double v, double t)
: v_scalaire(v), t(t) {}

Vecteur AllerAvant::applique_force(ObjetPhysique const& obj, Vecteur const& f, double temps) 
{
    set_temps(temps);cout<<t<<endl;
    return Libre::applique_force(obj, f, temps);
}

Vecteur AllerAvant::position(ObjetPhysique const& obj) const
{
    Vecteur pos(obj.get_dim_espace_physique());

    pos.set_coord(0, v_scalaire*t);
    for(size_t i(0); i<pos.dimension(); i++)
    {
        pos.set_coord(i+1, obj.get_E().get_coord(i));
    }
    
    return pos;
}

Vecteur AllerAvant::vitesse(ObjetPhysique const& obj) const
{
    Vecteur vit(obj.get_dim_espace_physique());

    vit.set_coord(0, v_scalaire);
    for(size_t i(0); i<vit.dimension()-1; ++i)
    {
        vit.set_coord(i+1, obj.get_E_point().get_coord(i));
    }

    return vit;
}

void AllerAvant::set_temps(double temps)
{
    t = temps;
}

void AllerAvant::affiche(ostream& sortie) const
{
    sortie<<"Contrainte aller de l'avant : ";
    sortie<<"v = "<<v_scalaire;
}

