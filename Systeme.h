#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <initializer_list>

#include "Dessinable.h"
#include "Integrateur.h"
#include "ChampForce.h"
#include "Contrainte.h"
#include "ObjetPhysique.h"

class Systeme 
{
    public :
    // Constructeurs
        Systeme();
    /*    Systeme(std::unique_ptr<Integrateur> && , 
            std::initializer_list<std::unique_ptr<ChampForce> &&>,
            std::initializer_list<std::unique_ptr<Contrainte> &&>, 
            std::initializer_list<std::unique_ptr<ObjetPhysique> &&>, 
            double t=0.);*/
    
    // Méthodes modif du système
        void ajout_inte(std::unique_ptr<Integrateur> &&);
        void ajout_champ(std::unique_ptr<ChampForce> &&);
        void ajout_contrainte(std::unique_ptr<Contrainte> &&);
        void ajout_objet(std::unique_ptr<ObjetPhysique> &&);

        void att_cont(size_t, size_t);
        void att_champ(size_t, size_t);

        void evolue();

        std::ostream& affiche(std::ostream&) const;

    private :
        std::unique_ptr<Integrateur> integrateur;
        std::vector<std::unique_ptr<ChampForce>> champs;
        std::vector<std::unique_ptr<Contrainte>> contraintes;
        std::vector<std::unique_ptr<ObjetPhysique>> objets;
        double temps;

};

std::ostream& operator<<(std::ostream&, Systeme const&);