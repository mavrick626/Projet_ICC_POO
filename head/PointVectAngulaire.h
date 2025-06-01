#pragma once

#include <iostream>
#include "PointMateriel.h"

class PointVectAngulaire : public PointMateriel
{
    public :
    // Constructeur
        PointVectAngulaire(std::string const&, double m, double q=0., Vecteur const& p=Vecteur(0., 0., 0.), 
            Vecteur const& v=Vecteur(0., 0., 0.), int c=0x000000, ChampForce* ch=nullptr, Contrainte* cont=nullptr,
            Integrateur* inte=nullptr, unsigned int dim_esp_ph=3);
    // Setter modifié
        void set_E(Vecteur const&);
        
    private :
        void renormaliser();
};