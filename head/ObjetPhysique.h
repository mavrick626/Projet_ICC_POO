#pragma once

#include <iostream>
#include <string>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "Contrainte.h"
#include "ChampForce.h"

class ObjetPhysique : public ObjetMobile
{
    public :
        ObjetPhysique(std::string const& nom, Vecteur const& e, Vecteur const& e_point, double m,
            ChampForce* champ, Contrainte* cont, unsigned int dim_esp_ph=3);
        virtual ~ObjetPhysique() override;

        double get_masse() const;
        std::string get_nom() const;
        ChampForce* get_champs() const;
        
        void set_nom(std::string const&);
        void set_contrainte(Contrainte*);
        void set_champ(ChampForce*);

        Vecteur force(double t=0) const;
        Vecteur position() const;
        Vecteur vitesse() const;

    protected :
        std::string nom;
        double masse;
        ChampForce* champs;
        Contrainte* contraintes;
        unsigned int dim_espace_physique;
};

std::ostream& operator<<(std::ostream&, ObjetPhysique const&);