#pragma once

#include <iostream>
#include "Vecteur.h"
#include "Constantes.h"

// Proto class temporaire
class PointMateriel;

class GravitationConstante
{
    public : 
    // Constructeur
        GravitationConstante(Vecteur const& gc=constantes::g);
    // Getter
        Vecteur get_champs() const;
    // Méthode
        Vecteur force(PointMateriel* const point, double temps=0.) const;

    private:
        Vecteur gravitation;
};

std::ostream& operator<<(std::ostream&, GravitationConstante const&);