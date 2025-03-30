#pragma once

#include "Vecteur.h"
#include "ObjetPhysique.h"
#include "Contrainte.h"

class Libre : public Contrainte
{
    public :
        virtual Vecteur applique_force(ObjetPhysique const& obj,  Vecteur const& force, double t) const override
        {
            if(obj.get_masse() != 0) return force*(1/obj.get_masse());
            return force;
        }

        virtual Vecteur position(ObjetPhysique const& obj) const override
        { return obj.get_E(); }

        virtual Vecteur vitesse(ObjetPhysique const& obj) const override
        { return obj.get_E_point(); }
};