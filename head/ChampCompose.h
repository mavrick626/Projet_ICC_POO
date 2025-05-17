#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "ChampForce.h"
#include "ObjetPhysique.h"

class ChampCompose : public ChampForce
{
    public :
    // Ajouter un champ à la composition
        void ajout_champ(std::unique_ptr<ChampForce> &&);
    // Autres méthodes
        virtual Vecteur force(ObjetPhysique const& obj, double t=0.) const override;
        virtual double potentiel(ObjetPhysique const&) const override;
        virtual void afficher(std::ostream& sortie) const override;

    private :
        std::vector<std::unique_ptr<ChampForce>> champs;
};