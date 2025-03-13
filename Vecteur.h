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
        Vecteur soustraction(Vecteur const&) const;

        Vecteur mult(double) const;
<<<<<<< HEAD
        double prod_scalaire(Vecteur const&) const;
        Vecteur vect_prod(Vecteur const&) const;
=======
        double dot_prod(Vecteur const&) const;
        Vecteur cross_prod(Vecteur const&) const;
>>>>>>> 7efc4d8f6c67b5261275fd49325eafb7d651c3ab

        double norme() const;
        double norme2() const;

<<<<<<< HEAD
        Vecteur oppose() const;
        Vecteur unitaire() const;
=======
        Vecteur opposite() const;
        Vecteur unit() const;
>>>>>>> 7efc4d8f6c67b5261275fd49325eafb7d651c3ab

    private:
        std::vector<double> coordonees_;
};