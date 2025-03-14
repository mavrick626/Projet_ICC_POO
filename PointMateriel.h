#pragma once

#include <iostream>
#include <vector>
#include "Vecteur.h"

class PointMateriel{
    public:
    // Constructeurs
        PointMateriel();
        PointMateriel(double, Vecteur, Vecteur, Vecteur);
    // Setter
        void set_etat(Vecteur const&);
        void set_derivee_etat(Vecteur const&);
    // Getter
        double get_masse() const;
        Vecteur get_etat() const; 
        Vecteur get_derivee_etat() const;
    // Autres méthodes
        Vecteur position() const;
        Vecteur vitesse() const;
        Vecteur evolution(double);

    private:
        double masse;
        Vecteur etat;
        Vecteur derivee_etat;
        Vecteur ChampForces;
};

std::ostream& operator<<(std::ostream&, PointMateriel const&);