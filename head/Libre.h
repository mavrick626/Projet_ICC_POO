#pragma once

#include <iostream>
#include "Contrainte.h"
#include "Vecteur.h"
#include "ObjetPhysique.h"

class Libre : public Contrainte
{
    public :
    // Aucun contrainte donc la force appliquée est simplement la somme des force extérieures
        virtual Vecteur applique_force(ObjetPhysique const& obj,  Vecteur const& force, double t=0.) override
        {
            if(obj.get_masse() != 0) return force*(1/obj.get_masse()); // a = F/m
            return force;
        }

    // Aucune contrainte donc la position et la vitesse sont les vecteurs d'états originaux
        virtual Vecteur position(ObjetPhysique const& obj) const override
        { return obj.get_E(); }

        virtual Vecteur vitesse(ObjetPhysique const& obj) const override
        { return obj.get_E_point(); }

        virtual void affiche(std::ostream& sortie) const override
        { sortie<<"contrainte libre"; }

        virtual void set_temps(double) {}
};