#pragma once

#include <iostream>
#include "Vecteur.h"

class ObjetMobile 
{
    public:
        Vecteur get_E() const;
        Vecteur get_E_point() const;

        void set_E(Vecteur E);
        void set_E_point(Vecteur E_point);

        virtual Vecteur evolution(double t) const; //retourne le vecteur E''
    
    private:
        Vecteur E;
        Vecteur E_point;

};

std::ostream& operator<<(std::ostream&, ObjetMobile const&);