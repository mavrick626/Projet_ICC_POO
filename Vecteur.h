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
        bool compare(Vecteur const&, unsigned int precision=1e-10) const;

    // Math methods
        Vecteur addition(Vecteur const&) const;
        Vecteur soustraction(Vecteur const&) const;

        Vecteur mult(double) const;
        double prod_scalaire(Vecteur const&) const;
        Vecteur vect_prod(Vecteur const&) const;

        double norme() const;
        double norme2() const;

        Vecteur oppose() const;
        Vecteur unitaire() const;

    private:
        std::vector<double> coordonees_;
};