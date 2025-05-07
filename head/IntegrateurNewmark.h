#pragma once

#include "Integrateur.h"
#include "ObjetMobile.h"

class IntegrateurNewmark : public Integrateur
{
    public :
        IntegrateurNewmark(double dt);
        virtual void integre(ObjetMobile& obj, double t, double dt=0.) const override;
};