#pragma once

#include <iostream>
#include "Vecteur.h"
#include "PointMateriel.h"
#include "Constantes.h"

class GravitationConstante
{
    public : 
    // Constructeur
        GravitationConstante(Vecteur=constantes::g);
    // Getter
        Vecteur get_champs() const;
    // Méthode
        Vecteur force(PointMateriel const& point, double temps=0.) const;

    private:
        Vecteur gravitation;
};

std::ostream& operator<<(std::ostream&, GravitationConstante const&);