#pragma once

#include <iostream>
#include "PointMateriel.h"

class PointVectAngulaire : public PointMateriel
{
    public :
    // Constructeur
        PointVectAngulaire(std::string const&, double m, double q=0., Vecteur const& p=Vecteur(0., 0., 0.), 
        Vecteur const& v=Vecteur(0., 0., 0.), ChampForce* ch=nullptr, Contrainte* cont=nullptr, unsigned int dim_esp_ph=3);
    // Setter modifié
        virtual void set_E(Vecteur const&) override;
        
    private :
        void renormaliser();
};