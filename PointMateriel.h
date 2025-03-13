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
        void set_position(Vecteur const&);
        void set_vitesse(Vecteur const&);
    // Getter
        Vecteur get_position() const; 
        Vecteur get_vitesse() const;
    // Autres méthodes
        Vecteur position() const;
        Vecteur vitesse() const;
        double evolution(double);

    private:
        double masse;
        Vecteur etat;
        Vecteur derivee_etat;
        Vecteur ChampForces;
};