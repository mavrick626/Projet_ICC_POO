#pragma once

#include "Integrateur.h"
#include "ObjetMobile.h"

class IntegrateurNewmark : public Integrateur
{
    public :
        IntegrateurNewmark(double dt, double epsilon=1e-9);
        virtual void integre(ObjetMobile& obj, double t) const override;

    private : 
        const double epsilon;
};