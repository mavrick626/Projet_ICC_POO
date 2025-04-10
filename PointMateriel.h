#pragma once

#include <iostream>
#include <string>
#include "ObjetPhysique.h"

class PointMateriel : public ObjetPhysique
{
    public:
    // Constructeurs
        PointMateriel(std::string const& n, ChampForce* gc, Contrainte* cont, double m=0.,
            Vecteur const& p=Vecteur(0., 0., 0.), Vecteur const& v=Vecteur(0., 0., 0.));

    // Autres méthodes
        virtual Vecteur evolution(double) const override;

};

std::ostream& operator<<(std::ostream&, PointMateriel const&);