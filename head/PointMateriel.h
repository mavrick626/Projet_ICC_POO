#pragma once

#include <iostream>
#include <string>
#include "ObjetPhysique.h"
#include "SupportADessin.h"

class PointMateriel : public ObjetPhysique, public virtual Dessinable
{
    public:
    // Constructeurs
        PointMateriel(std::string const&, double m, ChampForce* gc, Contrainte* cont,
            Vecteur const& p=Vecteur(0., 0., 0.), Vecteur const& v=Vecteur(0., 0., 0.), unsigned int dim_esp_ph=3);

    // Autres méthodes
        virtual Vecteur evolution(double) const override;
        virtual void afficher(std::ostream&) const override;
        virtual void dessine_sur(SupportADessin& support) override
        { support.dessine(*this); }

};