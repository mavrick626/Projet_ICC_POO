#pragma once

#include <iostream>
#include "ObjetMobile.h"
#include "Contrainte.h"
#include "ChampForce.h"

class ObjetPhysique : public ObjetMobile
{
    public :
        ObjetPhysique(Vecteur const& e, Vecteur const& e_point, double m,
            ChampForce* champ, Contrainte* cont, unsigned int dim_esp_ph=3);
        ~ObjetPhysique();

        double get_masse() const;

        Vecteur force(double t=0) const;
        Vecteur position() const;
        Vecteur vitesse() const;

    protected :
        Contrainte* contraintes;
        ChampForce* champs;
        double masse;
        unsigned int dim_espace_physique;

};

std::ostream& operator<<(std::ostream&, ObjetPhysique const&);