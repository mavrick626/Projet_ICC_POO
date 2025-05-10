#pragma once

#include <iostream>
#include <string>
#include "ObjetPhysique.h"
#include "Contrainte.h"
#include "ChampForce.h"
#include "SupportADessin.h"
#include "Dessinable.h"

class PointMateriel : public ObjetPhysique, public virtual Dessinable
{
    public :
    // Constructeurs
        PointMateriel(std::string const&, double m, double q=0., Vecteur const& p=Vecteur(0., 0., 0.),
        Vecteur const& v=Vecteur(0., 0., 0.), ChampForce* ch=nullptr, Contrainte* cont=nullptr, unsigned int dim_esp_ph=3);
    // Méthodes
        virtual Vecteur evolution(double t) const override;
        virtual void afficher(std::ostream&) const override;
        virtual void dessine_sur(SupportADessin& support) override
        { support.dessine(*this); }

};