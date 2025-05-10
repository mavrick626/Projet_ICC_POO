#pragma once

#include <iostream>
#include "ChampForce.h"
#include "ObjetPhysique.h"

class SuspensionSinusoidale : public ChampForce
{
    public :
        SuspensionSinusoidale(double, double, double);
        virtual Vecteur force(ObjetPhysique const&, double t) const override;
        virtual void afficher(std::ostream&) const override;

    private :
        const double k;
        const double A;
        const double L;
};