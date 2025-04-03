#pragma once

#include <iostream>
#include "ChampForce.h"
#include "Constantes.h"
#include "ObjetPhysique.h"

class GravitationConstante : public ChampsForce
{
    public : 
    // Constructeur
        GravitationConstante(Vecteur const& gc=constantes::g);
    // Getter
        Vecteur get_champs() const;
    // Méthode
        virtual Vecteur force(ObjetPhysique const& point, double temps=0.) const override;

    private:
        Vecteur gravitation;
};

std::ostream& operator<<(std::ostream&, GravitationConstante const&);