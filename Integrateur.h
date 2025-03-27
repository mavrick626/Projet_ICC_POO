#pragma once

#include "ObjetMobile.h"

class Integrateur
{
    public :
        virtual void integre(ObjetMobile& obj, double t, double dt) const = 0;
};