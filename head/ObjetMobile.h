#pragma once

#include <iostream>
#include "Vecteur.h"
#include "Integrateur.h"

class ObjetMobile 
{
    public :
    // Constructeur/Destructeur
        ObjetMobile(Vecteur const& E, Vecteur const& E_point, Integrateur*);
        virtual ~ObjetMobile() = default;
    // Getter
        Vecteur get_E() const;
        Vecteur get_E_point() const;
    // Setter
        void set_E(Vecteur const& E);
        void set_E_point(Vecteur const& E_point);
        void set_integrateur(Integrateur*);
    // Autres méthodes
        virtual Vecteur evolution(double t) const = 0; //retourne le vecteur E''
        void integre(double); // Lance l'intégration à traver l'intégrateur associé à l'objet
        virtual void afficher(std::ostream&) const;
    
    protected :
        Vecteur E;
        Vecteur E_point;
        Integrateur* integrateur;

};

std::ostream& operator<<(std::ostream&, ObjetMobile const&);