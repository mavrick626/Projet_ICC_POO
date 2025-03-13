#pragma once
#include <iostream>
#include "Vecteur.h"

class PointMateriel{
    public:
    // Constructeurs
        PointMateriel();
        PointMateriel();
    void set_position(Vecteur);
    void set_vitesse(Vecteur);
    Vecteur get_position() const; 
    Vecteur get_vitesse() const;
    Vecteur position() const;
    Vecteur vitesse() const;
    double evolution(double temps);




    private:
    Vecteur etat;
    Vecteur derivee_etat;
    double masse;
    Vecteur ChampForces;


};