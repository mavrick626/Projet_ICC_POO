#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "SupportADessin.h"
#include "Dessinable.h"
#include "Integrateur.h"
#include "ChampForce.h"
#include "Contrainte.h"
#include "ObjetPhysique.h"

class Systeme : public Dessinable
{
    public :
    // Constructeurs
        Systeme();
        Systeme(Systeme const&) = delete; // interdiction de copier le système
    
    // Méthodes ajout éléments
        void ajout_inte(std::unique_ptr<Integrateur> &&);
        void ajout_champ(std::unique_ptr<ChampForce> &&);
        void ajout_contrainte(std::unique_ptr<Contrainte> &&);
        void ajout_objet(std::unique_ptr<ObjetPhysique> &&);
    // Méthodes attributation
        void attribuer_cont(size_t, size_t);
        void attribuer_champ(size_t, size_t);

        void evolue();
        std::ostream& affiche(std::ostream&) const;
        virtual void dessine_sur(SupportADessin& support) override
        { support.dessine(*this); }

    private :
        std::unique_ptr<Integrateur> integrateur;
        std::vector<std::unique_ptr<ChampForce>> champs;
        std::vector<std::unique_ptr<Contrainte>> contraintes;
        std::vector<std::unique_ptr<ObjetPhysique>> objets;
        double temps;

};

std::ostream& operator<<(std::ostream&, Systeme const&);