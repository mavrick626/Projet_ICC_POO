#pragma once

#include <iostream>
#include "Vecteur.h"

class ObjetPhysique;

class Contrainte
{
    public :
        virtual ~Contrainte() = default;
        virtual Vecteur applique_force(ObjetPhysique const&,
            Vecteur const& force, double t) const = 0;
        virtual Vecteur position(ObjetPhysique const&) const = 0;
        virtual Vecteur vitesse(ObjetPhysique const&) const = 0;
        virtual void affiche(std::ostream&)const = 0;
  
};