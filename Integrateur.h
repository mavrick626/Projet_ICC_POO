#pragma once

#include "ObjetMobile.h"

class Integrateur
{
    public :
        Integrateur(double d) : dt(d) {}
        virtual void integre(ObjetMobile& obj, double t, double dt=0.) const = 0;
        double get_dt() const { return dt; }

    protected :
        const double dt;
};