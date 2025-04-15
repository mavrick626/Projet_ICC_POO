#pragma once

#include <iostream>
#include <string>
#include "ObjetPhysique.h"
#include "SupportADessin.h"
#include "Dessinable.h"

class PointMateriel : public ObjetPhysique, public virtual Dessinable
{
    public:
    // Constructeurs
        PointMateriel(std::string const& n, ChampForce* gc, Contrainte* cont, double m=0.,
            Vecteur const& p=Vecteur(0., 0., 0.), Vecteur const& v=Vecteur(0., 0., 0.));
        virtual ~PointMateriel() override = default;

    // Autres méthodes
        virtual Vecteur evolution(double) const override;
        
        virtual void dessine_sur(SupportADessin& support) override
        { support.dessine(*this); }

};

std::ostream& operator<<(std::ostream&, PointMateriel const&);