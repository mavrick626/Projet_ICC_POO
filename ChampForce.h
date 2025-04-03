#pragma once

#include "Vecteur.h"

class ObjetPhysique;

class ChampForce
{
    public :
        virtual Vecteur force(ObjetPhysique const& obj, double t=0.) const = 0;
};