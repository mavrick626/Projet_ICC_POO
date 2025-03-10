#pragma once
#include <vector>

class Vecteur
{
    public:
    // Constructor
        Vecteur() = default;
        Vecteur(std::vector<double> const&);

    // Setter
        void set_coord(unsigned int, double);

    // Other methods
        void add(double);
        void display() const;
        bool compare(Vecteur const&, double precision=1e-10) const;

    // Math methods
        Vecteur addition(Vecteur const&) const;
        Vecteur subtraction(Vecteur const&) const;

        Vecteur mult(double) const;
        double dot_prod(Vecteur const&) const;
        Vecteur cross_prod(Vecteur const&) const;

        double norm() const;
        double norm2() const;

        Vecteur opposite() const;
        Vecteur unit() const;

    private:
        std::vector<double> coordonates_;
};