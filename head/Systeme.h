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
        Systeme(double t=0.);
        Systeme(Systeme const&) = delete; // interdiction de copier le système
    // Méthodes d'ajout d'éléments
        void ajout_inte(std::unique_ptr<Integrateur> &&);
        void ajout_champ(std::unique_ptr<ChampForce> &&);
        void ajout_contrainte(std::unique_ptr<Contrainte> &&);
        void ajout_objet(std::unique_ptr<ObjetPhysique> &&);
    // Méthodes d'attributation
        void attribuer_cont(size_t, size_t);
        void attribuer_champ(size_t, size_t);
        void attribuer_inte(size_t, size_t);
    // Autres méthodes
        void evolue();
        double calcul_e_sys() const;

        void affiche(std::ostream&) const;
        void affiche_pos(std::ostream&) const;
        void affiche_e(std::ostream&) const;
        void affiche_gnu(FILE*, size_t, size_t) const;
        virtual void dessine_sur(SupportADessin& support) override
        { support.dessine(*this); }

    private :
        std::vector<std::unique_ptr<Integrateur>> integrateurs;
        std::vector<std::unique_ptr<ChampForce>> champs;
        std::vector<std::unique_ptr<Contrainte>> contraintes;
        std::vector<std::unique_ptr<ObjetPhysique>> objets;
        double temps;

};

std::ostream& operator<<(std::ostream&, Systeme const&);