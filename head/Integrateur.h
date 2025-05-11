#pragma once

class ObjetMobile;

class Integrateur
{
    public :
    // Constructeur/Destructeur
        Integrateur(double d) : dt(d) {}
        virtual ~Integrateur() = default;
    // Méthodes
        virtual void integre(ObjetMobile& obj, double t) const = 0;
        double get_dt() const { return dt; }

    protected :
        const double dt;
};