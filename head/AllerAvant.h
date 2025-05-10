#pragma once

#include "Libre.h"
#include "ObjetPhysique.h"

class AllerAvant : public Libre
{
    public :
        AllerAvant(double v, double t=0.);

        Vecteur applique_force(ObjetPhysique const&, Vecteur const& force, double t) override;
        virtual Vecteur position(ObjetPhysique const&) const override;
        virtual Vecteur vitesse(ObjetPhysique const&) const override;
        virtual void affiche(std::ostream&) const override;
        
    private :
        const double v_scalaire;
        double t;
        void set_temps(double);
};