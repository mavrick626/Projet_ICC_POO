#include <iostream>
#include <cmath>
#include <algorithm>
#include <exception>
#include "Vecteur.h"

using namespace std;

//==============================================
// Constructeurs
//==============================================
Vecteur::Vecteur(unsigned int dimension)
: coordonnees_(vector<double> (dimension, 0.)) {}

Vecteur::Vecteur(double x, double y, double z)
: coordonnees_({x, y, z}) {}

Vecteur::Vecteur(vector<double> const& coord)
: coordonnees_(coord) {}

//==============================================
// getter définition
//==============================================
double Vecteur::get_coord(unsigned int index) const
{
    return coordonnees_[index];
}

size_t Vecteur::dimension() const
{
    return coordonnees_.size();
}

//==============================================
// Setter définition
//==============================================
void Vecteur::set_coord(unsigned int index, double composante)
{
    coordonnees_[index] = composante;
}

//==============================================
// Autre méthode
//==============================================
void Vecteur::augmente(double composante)
{
    coordonnees_.push_back(composante);
}

//==============================================
// Math méthodes
//==============================================
double Vecteur::norme() const
{
    return pow(norme2(), .5);
}

double Vecteur::norme2() const
{
    double somme(0.);
    for(double composante : coordonnees_) somme += pow(composante, 2);

    return somme;
}

Vecteur& Vecteur::operator+=(Vecteur const& v)
{
    size_t u_dim(coordonnees_.size());
    size_t v_dim(v.coordonnees_.size());

    if(u_dim < v_dim) coordonnees_.resize(v_dim, 0.);
    for(size_t i(0); i<v_dim; i++) coordonnees_[i] += v.coordonnees_[i];

    return *this;
}

Vecteur& Vecteur::operator*=(double scalaire)
{
    for(size_t i(0); i<coordonnees_.size(); i++) coordonnees_[i]*=scalaire;

    return *this;
}

//==============================================
// Surcharge externe des opérateurs
//==============================================
// Opérateur d'affichage
ostream& operator<<(ostream& sortie, Vecteur const& v)
{
    size_t dim(v.dimension());

    sortie<<"(";
    for(size_t i(0); i<dim; i++)
    {
        sortie<<v.get_coord(i);
        if(i<dim-1) sortie<<", ";
    }
    sortie<<")";

    return sortie;
}
// Opérateurs de comparaison
const bool operator==(Vecteur const& u, Vecteur const& v)
{
    bool semblable(false);
    size_t u_dim(u.dimension());

    if(u_dim == v.dimension())
    {
        semblable = true;
        for(size_t i(0); i<u_dim && semblable; i++)
        {
            if(abs(u.get_coord(i)-v.get_coord(i)) > 1e-10) semblable = false;
        }
    }
    return semblable;
}

const bool operator!=(Vecteur const& u, Vecteur const& v)
{
    return !(u==v);
}
// Opérations de l'espace vectoriel Rn, adition interne
const Vecteur operator+(Vecteur u, Vecteur const& v)
{
    u += v;
    return u;
}
// Multiplication externe par un scalaire
const Vecteur operator*(double scalaire, Vecteur u)
{   
    return u*=scalaire;
}
// Opérateur produit scalaire
const double operator*(Vecteur const& u, Vecteur const& v)
{
    // si les vecteurs sont de dimensions différentes, les termes de m à n sont nulles (m<n)
    size_t dimMin(min(u.dimension(), v.dimension()));
    double result(0.);

    for(size_t i(0); i<dimMin; i++) result += u.get_coord(i)*v.get_coord(i);

    return result;
}
// Opérateur produit vectoriel
const Vecteur operator^(Vecteur const& u, Vecteur const& v)
{
    if(u.dimension() == 3 && v.dimension() == 3)
    {
        vector<double> nouvelles_coord(3, 0.);

        nouvelles_coord[0] = u.get_coord(1)*v.get_coord(2) - u.get_coord(2)*v.get_coord(1);
        nouvelles_coord[1] = u.get_coord(2)*v.get_coord(0) - u.get_coord(0)*v.get_coord(2);
        nouvelles_coord[2] = u.get_coord(0)*v.get_coord(1) - u.get_coord(1)*v.get_coord(0);

        return Vecteur(nouvelles_coord);
    }
    else
    {
        throw invalid_argument("Les vecteurs doivent etre en 3 dimensions !");
    }
}

// Opérateur inverse
const Vecteur operator-(Vecteur u)
{
    return u*=(-1);
}
// Opérateur soustraction, addition de l'opposé
const Vecteur operator-(Vecteur const& u, Vecteur const& v)
{
    // u - v = u + (-v)
    return u+(-v);
}
// Commutativité de la multiplication par un scalaire
const Vecteur operator*(Vecteur u, double scalaire)
{
    return u*=scalaire;
}
// Vecteur unaire
const Vecteur operator~(Vecteur const& u)
{
    double norme_(u.norme());
    size_t dim_(u.dimension());
    vector<double> nouvelles_coord;

    for(size_t i(0); i<dim_; i++) 
    {
        nouvelles_coord.push_back(u.get_coord(i)/norme_);
    }
    return Vecteur(nouvelles_coord); 
}