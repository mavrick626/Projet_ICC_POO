#pragma once

#include "Integrateur.h"
#include "ObjetMobile.h"

class IntegrateurEulerCromer : public Integrateur
{ 
    public:
        IntegrateurEulerCromer(double dt);
        virtual void integre(ObjetMobile& obj, double t, double delta=0.) const override;
};