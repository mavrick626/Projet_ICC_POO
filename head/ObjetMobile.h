#pragma once

#include <iostream>
#include "Vecteur.h"

class ObjetMobile 
{
    public:
    // Constructeur
        ObjetMobile(Vecteur const& E, Vecteur const& E_point);
        virtual ~ObjetMobile() = default;
    // Getter
        Vecteur get_E() const;
        Vecteur get_E_point() const;
    // Setter
        void set_E(Vecteur const& E);
        void set_E_point(Vecteur const& E_point);
    // Autres méthodes
        virtual Vecteur evolution(double t) const = 0; //retourne le vecteur E''
    
    protected:
        Vecteur E;
        Vecteur E_point;

};

std::ostream& operator<<(std::ostream&, ObjetMobile const&);