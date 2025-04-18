#pragma once

#include <iostream>
#include "Vecteur.h"

class ObjetPhysique;

class ChampForce
{
    public :
    // Destructeur
        virtual ~ChampForce() = default;
    // Méthodes
        virtual Vecteur force(ObjetPhysique const& obj, double t=0.) const = 0;
        virtual void afficher(std::ostream& sortie) const = 0;
};

/* 'inline' permet de correctement définir une fonction dans un .h
    pour ne pas avoir à créer un .cc juste pour ça */
inline std::ostream& operator<<(std::ostream& sortie, ChampForce const& ch)
{
    ch.afficher(sortie);
    return sortie;
}