#pragma once

#include <iostream>
#include "constantes.h"
#include "ForceCentrale.h"
#include "Vecteur.h"
#include "ObjetPhysique.h"

class ChampNewtonien : public ForceCentrale
{
    public :
    // Constructeur
        ChampNewtonien(ObjetPhysique const& c);
    // Méthodes
        virtual Vecteur force(ObjetPhysique const&, double t=.0) const override;
        virtual double potentiel(ObjetPhysique const&) const override;
        virtual void afficher(std::ostream& sortie) const override;
};
