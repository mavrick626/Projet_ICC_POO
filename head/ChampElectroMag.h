#pragma once

#include <iostream>
#include "ChampForce.h"
#include "Vecteur.h"
#include "ObjetPhysique.h"

class ChampElectroMag : public ChampForce
{
    public :
        ChampElectroMag(Vecteur const& elec, Vecteur const& mag)
        : E(elec), B(mag) {}
        virtual Vecteur force(ObjetPhysique const& obj, double t=0.) const override
        {
            return obj.get_q()*(E + (obj.vitesse()^B));
        }
        virtual void afficher(std::ostream& sortie) const override
        { sortie<<"Champ electromagnétique constant : ";
          sortie<<"E = "<<E<<", ";
          sortie<<"B = "<<B; 
        }

    private :
        const Vecteur E;
        const Vecteur B;
};