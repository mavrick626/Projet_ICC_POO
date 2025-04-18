#pragma once

#include <iostream>
#include "ChampForce.h"
#include "Vecteur.h"
#include "ObjetPhysique.h"

class ForceCentrale : public ChampForce
{
    public :
    // Constructeur
        ForceCentrale(ObjetPhysique const&);
    // Méthodes
        virtual Vecteur force(ObjetPhysique const&, double t=0.) const = 0;
        virtual void afficher(std::ostream&) const override;

    protected :
        const ObjetPhysique& centre;
        Vecteur quadratique_inverse(ObjetPhysique const& autre) const; // pas public prc pas besoin à l'extérieur
};