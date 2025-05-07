#pragma once

#include "Integrateur.h"
#include "ObjetMobile.h"

class IntegrateurRungeKutta : public Integrateur
{
    public :
        IntegrateurRungeKutta(double dt);
        virtual void integre(ObjetMobile&, double t, double dt=0.) const override;
};