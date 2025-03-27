#pragma once

#include <iostream>
#include "Vecteur.h"
#include "GravitationConstante.h"

class PointMateriel{
    public:
    // Constructeurs
        PointMateriel(GravitationConstante* gc, double m=0.,
            Vecteur const& p=Vecteur(0., 0., 0.), Vecteur const& v=Vecteur(0., 0., 0.));
    // Setter
        void set_masse(double);
        void set_etat(Vecteur const&);
        void set_derivee_etat(Vecteur const&);
        void set_champForce(GravitationConstante* const);
    // Getter
        double get_masse() const;
        Vecteur get_etat() const; 
        Vecteur get_derivee_etat() const;
        GravitationConstante* get_champForces() const;
    // Autres méthodes
        Vecteur position() const;
        Vecteur vitesse() const;
        Vecteur evolution(double) const;

    private:
        double masse;
        Vecteur etat;
        Vecteur derivee_etat;
        GravitationConstante* champForces;
};

std::ostream& operator<<(std::ostream&, PointMateriel const&);