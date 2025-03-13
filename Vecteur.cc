#include <iostream>
#include <cmath>
#include <algorithm>
#include <exception>
#include "Vecteur.h"

using namespace std;

//==============================================
// Constructor
//==============================================
Vecteur::Vecteur(vector<double> const& coord)
: coordonees_(coord) {}

//==============================================
// Setter definition
//==============================================
void Vecteur::set_coord(unsigned int index, double value)
{
    coordonees_[index] = value;
}

//==============================================
// Other methods definition
//==============================================
void Vecteur::add(double value)
{
    coordonees_.push_back(value);
}

void Vecteur::display() const
{
    for(double value : coordonees_) cout<<value<<" ";
    cout<<endl;
}

bool Vecteur::compare(Vecteur const& v, double precision) const
{
    bool same(false);
    size_t dim = coordonees_.size();

    if(dim == v.coordonees_.size())
    {
        same = true;

        for(size_t i(0); i<dim && same; i++)
        {
            if(abs(coordonees_[i]-v.coordonees_[i]) > precision) same = false;
        }
    }

    return same;
}

//==============================================
// Math methods definition
//==============================================
Vecteur Vecteur::addition(Vecteur const& v) const
{
    size_t dim(coordonees_.size());
    size_t v_dim(v.coordonees_.size());
    size_t dimMax(max(dim, v_dim));

    vector<double> new_coord;

    for(size_t i(0); i<dimMax; i++)
    {
        // plongement naturel de Rm dans Rn en ajoutant des 0 ∀ m<i≤n
        if(i < dim)
        {
            new_coord.push_back(coordonees_[i]);
        }
        else
        {
            new_coord.push_back(0.);
        }

        if(i < v_dim)
        {
            new_coord[i] += v.coordonees_[i];
        }
        else
        {
            new_coord[i] += 0.;
        }
    }

    return Vecteur(new_coord);
}

Vecteur Vecteur::soustraction(Vecteur const& v) const
{
    // u - v = u + (-v)
    return addition(v.oppose());
}

Vecteur Vecteur::mult(double scalaire) const
{
    vector<double> new_coord(coordonees_);
    for(double& value : new_coord) value *= scalaire; // ui = a*ui, ∀i

    return Vecteur(new_coord);
}

<<<<<<< HEAD:Vecteur.cpp
double Vecteur::prod_scalaire(Vecteur const& v) const
=======
double Vecteur::dot_prod(Vecteur const& v) const
>>>>>>> 7efc4d8f6c67b5261275fd49325eafb7d651c3ab:Vecteur.cc
{
    size_t dimMin(min(coordonees_.size(), v.coordonees_.size()));
    double result(0.);

    for(size_t i(0); i<dimMin; i++) result += coordonees_[i]*v.coordonees_[i];

    return result;
}

Vecteur Vecteur::cross_prod(Vecteur const& v) const
{
    if(coordonees_.size() == 3 && v.coordonees_.size() == 3)
    {
        vector<double> new_coord(3, 0.);

        new_coord[0] = coordonees_[1]*v.coordonees_[2] - coordonees_[2]*v.coordonees_[1];
        new_coord[1] = coordonees_[2]*v.coordonees_[0] - coordonees_[0]*v.coordonees_[2];
        new_coord[2] = coordonees_[0]*v.coordonees_[1] - coordonees_[1]*v.coordonees_[0];

        return Vecteur(new_coord);
    }
    else
    {
        throw invalid_argument("Les vecteurs doivent etre en 3 dimensions !");
    }
}

double Vecteur::norme() const
{
    return pow(norme2(), .5);
}

double Vecteur::norme2() const
{
    double sum(0.);
    for(double value : coordonees_) sum += pow(value, 2);

    return sum;
}

Vecteur Vecteur::oppose() const
{
    return mult(-1);
}

Vecteur Vecteur::unit() const
{
    vector<double> new_coord(coordonees_);
    double norme_ = norme();
    for(double& value : new_coord) value /= norme_;

    return Vecteur(new_coord);
}
