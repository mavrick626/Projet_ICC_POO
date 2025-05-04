#pragma once

#include <iostream>
#include "ChampForce.h"
#include "Vecteur.h"
#include "ObjetPhysique.h"

class FrottementFluide : public ChampForce
{
    public :   
        FrottementFluide(double lambda) 
        : b(lambda) {}

        virtual Vecteur force(ObjetPhysique const& obj, double t=0.) const override
        { return (-b)*obj.vitesse(); }

        virtual void afficher(std::ostream& sortie) const override
        { sortie<<"Champ de frottement fluide : coef friction = ";
          sortie<<b;
        }

    private :
        double b;
};