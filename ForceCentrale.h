#pragma once

#include "ChampForce.h"
#include "ObjetPhysique.h"

class ForceCentrale : public ChampForce
{
    public :
        ForceCentrale(ObjetPhysique const&);
        virtual Vecteur force(ObjetPhysique const&, double t=0.) const = 0;

    protected :
        ObjetPhysique const& centre;
        Vecteur quadratique_inverse(ObjetPhysique const& autre) const;
};