#pragma once

#include "ForceCentrale.h"
#include "constantes.h"

class ChampNewtonien : public ForceCentrale
{
    public :
        ChampNewtonien(ObjetPhysique const& c)
        : ForceCentrale(c) {}

        virtual Vecteur force(ObjetPhysique const& obj, double t=.0) const override
        {
            // Création d'un vecteur nul dans la dimension de l'objet
            Vecteur f(obj.get_E().dimension());
            
            // Calcul du numérateur et multiplication avec le vecteur quadratique inverse
            double num(constantes::G*centre.get_masse()*obj.get_masse());
            f = num*quadratique_inverse(obj);

            return f;
        }
};
