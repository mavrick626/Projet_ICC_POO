#pragma once

#include <iostream>
#include <string>
#include "Integrateur.h"
#include "ObjetPhysique.h"
#include "Contrainte.h"
#include "ChampForce.h"

class PointMateriel : public ObjetPhysique
{
    public :
    // Constructeurs
        PointMateriel(std::string const&, double m, double q=0., Vecteur const& p=Vecteur(3),
            Vecteur const& v=Vecteur(3), ChampForce* ch=nullptr, Contrainte* cont=nullptr,
            Integrateur* inte=nullptr, unsigned int dim_esp_ph=3);
    // Méthodes
        virtual Vecteur evolution(double t) const override;
        virtual void afficher(std::ostream&) const override;
        virtual void afficher_gnu(FILE*, size_t, size_t, bool) const override;

    private : 
        int couleur() const;
};