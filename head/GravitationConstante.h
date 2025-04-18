#pragma once

#include <iostream>
#include "Vecteur.h"
#include "ChampForce.h"
#include "Constantes.h"
#include "ObjetPhysique.h"

class GravitationConstante : public ChampForce
{
    public : 
    // Constructeur
        GravitationConstante(Vecteur const& gc=constantes::g);
    // Getter
        Vecteur get_champs() const;
    // Méthode
        virtual Vecteur force(ObjetPhysique const& point, double temps=0.) const override;
        virtual void afficher(std::ostream&) const override;

    private:
        Vecteur gravitation;
};