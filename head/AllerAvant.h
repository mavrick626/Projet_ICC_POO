#pragma once

#include "Contrainte.h"
#include "ObjetPhysique.h"

class AllerAvant : public Contrainte
{
    public :
        AllerAvant(double v, double t=0.);

        Vecteur applique_force(ObjetPhysique const&, Vecteur const& force, double t) override;
        virtual Vecteur position(ObjetPhysique const&) const override;
        virtual Vecteur vitesse(ObjetPhysique const&) const override;
        virtual void affiche(std::ostream&) const override;
        virtual void set_temps(double) override;
        
    private :
        const double v_scalaire;
        double temps;
};