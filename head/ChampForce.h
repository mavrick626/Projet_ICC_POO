#pragma once

#include <iostream>
#include "Vecteur.h"

class ObjetPhysique;

class ChampForce
{
    public :
        virtual ~ChampForce() = default;
        virtual Vecteur force(ObjetPhysique const& obj, double t=0.) const = 0;
};