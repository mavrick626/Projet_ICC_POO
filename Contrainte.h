#pragma once

#include "Vecteur.h"

class ObjetPhysique;

class Contrainte
{
    public :
        virtual Vecteur applique_force(ObjetPhysique const& obj,
            Vecteur const& force, double t) const = 0;
        virtual Vecteur position(ObjetPhysique const& obj) const = 0;
        virtual Vecteur vitesse(ObjetPhysique const& obj) const = 0;
  
};