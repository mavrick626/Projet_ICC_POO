#pragma once

#include <iostream>
#include "constantes.h"
#include "ChampForce.h"
#include "Vecteur.h"
#include "ObjetPhysique.h"

class GravitationConstante : public ChampForce
{
    public : 
    // Constructeur
        GravitationConstante(Vecteur const& gc=constantes::g);
    // Méthode
        virtual Vecteur force(ObjetPhysique const& point, double temps=0.) const override;
        virtual void afficher(std::ostream&) const override;

    private:
        const Vecteur gravitation;
};