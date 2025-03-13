#pragma once

#include <iostream>
#include <vector>

class Vecteur
{
    public:
    // Constructeurs
        Vecteur(unsigned int dimension);
        Vecteur(double, double, double);
        Vecteur(std::vector<double> const&);

    // Getter
    double get_coord(unsigned int) const;
    size_t dimension() const;

    // Setter
        void set_coord(unsigned int, double);

    // Autres méthodes utiles
        void augmente(double);

    // Méthodes mathématiques
        double norm() const;
        double norm2() const;

    private:
        std::vector<double> coordonnees_;
};

// operateur affichage
std::ostream& operator<<(std::ostream&, Vecteur const&);
// operateur de comparaison
const bool operator==(Vecteur const&, Vecteur const&);
const bool operator!=(Vecteur const&, Vecteur const&);
// operations qui permettent de définir un corps
const Vecteur operator+(Vecteur const&, Vecteur const&);
const Vecteur operator*(double, Vecteur const&);
// produit scalaire et vectoriel
const double operator*(Vecteur const&, Vecteur const&);
const Vecteur operator^(Vecteur const&, Vecteur const&);
// operations complémentaires à la structure du corps
const Vecteur operator*(Vecteur const&, double); // commutativité
const Vecteur operator-(Vecteur const&); // opposé
const Vecteur operator-(Vecteur const&, Vecteur const&); // soustraction
// operateur unaire
const Vecteur operator~(Vecteur const&);