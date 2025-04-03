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

class Systeme : public Dessinable
{
    public :
        Systeme();
        Systeme(Integrateur const& integrateur, std::initializer_list<ChampForce> const&,
            std::initializer_list<Contrainte> const&, std::initializer_list<ObjetPhysique> const&, double t=0.);

        void ajout_champ(ChampForce const&);
        void ajout_contrainte(Contrainte const&);
        void ajour_objet(ObjetPhysique const&);

    private :
        std::unique_ptr<Integrateur> integrateur;
        std::vector<std::unique_ptr<ChampForce>> champs;
        std::vector<std::unique_ptr<Contrainte>> contraintes;
        std::vector<std::unique_ptr<ObjetPhysique>> objets;
        double temps;

};

std::ofstream& operator<<(std::ostream&, Systeme const&);