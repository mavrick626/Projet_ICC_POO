#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "ChampForce.h"
#include "ObjetPhysique.h"

class ChampCompose : public ChampForce
{
    public :
        void ajout_champ(std::unique_ptr<ChampForce> &&);

        virtual Vecteur force(ObjetPhysique const& obj, double t=0.) const override;
        virtual void afficher(std::ostream& sortie) const override;

    private :
        std::vector<std::unique_ptr<ChampForce>> champs;
};