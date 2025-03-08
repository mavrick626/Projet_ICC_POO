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
        bool compare(Vecteur const&) const;

    // Math methods
        Vecteur addition(Vecteur const&) const;
        Vecteur subtraction(Vecteur const&) const;

        Vecteur mult(double) const;
        double scalar_prod(Vecteur const&) const;
        Vecteur vect_prod(Vecteur const&) const;

        double norm() const;
        double norm2() const;

        Vecteur opposite() const;
        Vecteur unitaire() const;

    private:
        std::vector<double> coordonates_;
};