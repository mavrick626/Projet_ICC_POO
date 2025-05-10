#pragma once

#include <ostream>

#include "Contrainte.h"
#include "constantes.h"
#include "ObjetPhysique.h"
#include "Vecteur.h"

class ContrainteSpherique : public Contrainte
{
    public :
    // Constructeur
        ContrainteSpherique(double);
    // Méthodes
        virtual Vecteur applique_force(ObjetPhysique const&, Vecteur const& force, double t) override;
        virtual Vecteur position(ObjetPhysique const&) const override;
        virtual Vecteur vitesse(ObjetPhysique const&) const override;
        virtual void affiche(std::ostream&) const override;

    private:
    // Longueur du pendule
        const double L; 
    // Vecteurs unitairs du repère cartésien associé au centre de rotation
        const Vecteur k; 
        const Vecteur d;
        const Vecteur j;

    /* Méthodes utilitaire de calcul des vecteurs du repère sphérique
       associé à l'oscillateur */
        Vecteur u_rho(ObjetPhysique const&) const;
        Vecteur u_theta(ObjetPhysique const&) const;
        Vecteur u_phi(ObjetPhysique const&) const;
    // Méthodes de calcul des accélérations angulaires
        double theta_pp(ObjetPhysique const&, Vecteur const&) const;
        double phi_pp(ObjetPhysique const&, Vecteur const&) const;
};