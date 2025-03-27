#pragma once

#include "Integrateur.h"

class IntegrateurEulerCromer : public Integrateur
{ 
    public:
        IntegrateurEulerCromer(double dt);
        virtual void integre(ObjetMobile& obj, double t, double dt) const override;

    private:
        const double dt;
};