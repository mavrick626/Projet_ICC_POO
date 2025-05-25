#pragma once

#include <iostream>
#include <string>
#include "ObjetMobile.h"
#include "Vecteur.h"
#include "Contrainte.h"
#include "ChampForce.h"

class ObjetPhysique : public ObjetMobile
{
    public :
    // Constructeur/Desrtructeur
        ObjetPhysique(std::string const& nom, double m, double q, Vecteur const& e, Vecteur const& e_point,
            ChampForce* champ, Contrainte* cont, Integrateur* inte, unsigned int dim_esp_ph);

    // Getter
        std::string get_nom() const;
        double get_masse() const;
        double get_q() const;
        unsigned int get_dim_espace_physique() const;
    // Setter
        void set_contrainte(Contrainte*);
        void set_champ(ChampForce*);
    // Méthodes
        virtual Vecteur evolution(double t) const = 0;
        Vecteur force(double t=0) const;
        Vecteur position() const;
        Vecteur vitesse() const;
        double energie() const;
        
        virtual void afficher(std::ostream&) const override;
        virtual void afficher_gnu(FILE*, size_t, size_t, bool) const = 0;
        
        double energie_cin() const;
        double energie_pot() const;
    
    protected :
        const std::string nom;
        double masse;
        double charge;
        ChampForce* champs;
        Contrainte* contraintes;
        const unsigned int dim_espace_physique;
};

std::ostream& operator<<(std::ostream&, ObjetPhysique const&);