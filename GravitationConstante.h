#pragma once

#include <iostream>
#include "Vecteur.h"
#include "PointMateriel.h"
#include "constantes.h"

class GravitationConstante
{
    public : 
        GravitationConstante(Vecteur=Vecteur(0., 0., -9.81));
        Vecteur force(PointMateriel point, double temps=0);

    private:
        Vecteur gravitation();
};

std::ostream& operator<<(std::ostream&, GravitationConstante const&);