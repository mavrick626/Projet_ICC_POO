#pragma once

#include "Vecteur.h"

class ObjetPhysique;

class ChampsForce
{
    public :
        virtual Vecteur force(ObjetPhysique const& obj, double t=0.) const = 0;
};