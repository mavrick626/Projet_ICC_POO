#pragma once

#include <ostream>

#include "Contrainte.h"
#include "constantes.h"
#include "ObjetPhysique.h"
#include "Vecteur.h"

class ContrainteSpherique : public Contrainte
{
    public :
        ContrainteSpherique(double);

        virtual Vecteur applique_force(ObjetPhysique const&, Vecteur const& force, double t) const override;
        virtual Vecteur position(ObjetPhysique const&) const override;
        virtual Vecteur vitesse(ObjetPhysique const&) const override;
        virtual void affiche(std::ostream&) const override;

    private:
        const double L;
        const Vecteur k;
        const Vecteur d;
        const Vecteur j;

        Vecteur u_rho(ObjetPhysique const&) const;
        Vecteur u_theta(ObjetPhysique const&) const;
        Vecteur u_phi(ObjetPhysique const&) const;

        double theta_pp(ObjetPhysique const&, Vecteur const&) const;
        double phi_pp(ObjetPhysique const&, Vecteur const&) const;
};