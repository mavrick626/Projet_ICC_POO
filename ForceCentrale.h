#pragma once

#include "ChampsForce.h"
#include "ObjetPhysique.h"

class ForceCentrale : public ChampsForce
{
    public :
        ForceCentrale(ObjetPhysique* pt_obj);
        virtual Vecteur force(ObjetPhysique const& obj, double t=0.) const = 0;

    protected :
        ObjetPhysique* centre;
        Vecteur quadratique_inverse(ObjetPhysique const& autre) const;
};