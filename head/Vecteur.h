#pragma once

#include <iostream>
#include <vector>

class Vecteur
{
    public :
    // Constructeurs
        explicit Vecteur(unsigned int dimension);
        Vecteur(double x, double y, double z);
        Vecteur(std::vector<double> const&);

    // Getter
        double get_coord(size_t) const;
        size_t dimension() const;

    // Setter
        void set_coord(size_t, double);

    // Autres méthodes utiles
        void augmente(double);

    // Méthodes mathématiques
        double norme() const;
        double norme2() const;

        Vecteur& operator+=(Vecteur const&);
        Vecteur& operator*=(double);

    private :
        std::vector<double> coordonnees;
};

// operateur affichage
std::ostream& operator<<(std::ostream&, Vecteur const&);
// operateur de comparaison
const bool operator==(Vecteur const&, Vecteur const&);
const bool operator!=(Vecteur const&, Vecteur const&);
// operations avec le corps des scalaires
const Vecteur operator+(Vecteur, Vecteur const&);
const Vecteur operator*(double, Vecteur);
// produit scalaire et vectoriel
const double operator*(Vecteur const&, Vecteur const&);
const Vecteur operator^(Vecteur const&, Vecteur const&);
// operations complémentaires à la structure du corps
const Vecteur operator*(Vecteur, double); // commutativité
const Vecteur operator-(Vecteur); // opposé
const Vecteur operator-(Vecteur const&, Vecteur const&); // soustraction
// operateur unaire
const Vecteur operator~(Vecteur const&);