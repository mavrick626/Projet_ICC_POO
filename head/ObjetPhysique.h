#pragma once

#include <iostream>
#include <string>
#include "Vecteur.h"
#include "ObjetMobile.h"
#include "Contrainte.h"
#include "ChampForce.h"
#include "SupportADessin.h"
#include "Dessinable.h"

class ObjetPhysique : public ObjetMobile
{
    public :
    // Constructeur/Desrtructeur
        ObjetPhysique(std::string const& nom, double m, Vecteur const& e, Vecteur const& e_point,
            ChampForce* champ, Contrainte* cont, unsigned int dim_esp_ph);
    // Getter
        double get_masse() const;
        std::string get_nom() const;
        ChampForce* get_champs() const;
    // Setter
        void set_contrainte(Contrainte*);
        void set_champ(ChampForce*);
    // Méthodes
        virtual Vecteur evolution(double t) const = 0;
        Vecteur force(double t=0) const;
        Vecteur position() const;
        Vecteur vitesse() const;
        
        virtual void afficher(std::ostream&) const override;

    protected :
        const std::string nom;
        double masse;
        ChampForce* champs;
        Contrainte* contraintes;
        const unsigned int dim_espace_physique;
};

std::ostream& operator<<(std::ostream&, ObjetPhysique const&);