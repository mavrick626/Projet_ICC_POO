#pragma once

#include <iostream>
#include "Vecteur.h"

class ObjetPhysique;

class Contrainte
{
    public :
    // Destructeur
        virtual ~Contrainte() = default;
    // Méthodes
        virtual Vecteur applique_force(ObjetPhysique const&, Vecteur const& force, double t) = 0;
        virtual Vecteur position(ObjetPhysique const&) const = 0;
        virtual Vecteur vitesse(ObjetPhysique const&) const = 0;
        virtual void affiche(std::ostream&)const = 0;
        virtual void set_temps(double) = 0;
  
};

/* 'inline' permet de correctement définir une fonction dans un .h
    pour ne pas avoir à créer un .cc juste pour ça */
inline std::ostream& operator<<(std::ostream& sortie, Contrainte const& cont)
{
    cont.affiche(sortie);
    return sortie;
}