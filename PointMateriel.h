#pragma once

#include <iostream>
#include "ObjetPhysique.h"

class PointMateriel : public ObjetPhysique
{
    public:
    // Constructeurs
        PointMateriel(ChampsForce* gc, Contrainte* cont, double m=0.,
            Vecteur const& p=Vecteur(0., 0., 0.), Vecteur const& v=Vecteur(0., 0., 0.));

    // Autres méthodes
        virtual Vecteur evolution(double) const override;

};

std::ostream& operator<<(std::ostream&, PointMateriel const&);