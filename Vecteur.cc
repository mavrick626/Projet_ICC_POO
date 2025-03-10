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
: coordonates_(coord) {}

//==============================================
// Setter definition
//==============================================
void Vecteur::set_coord(unsigned int index, double value)
{
    coordonates_[index] = value;
}

//==============================================
// Other methods definition
//==============================================
void Vecteur::add(double value)
{
    coordonates_.push_back(value);
}

void Vecteur::display() const
{
    for(double value : coordonates_) cout<<value<<" ";
    cout<<endl;
}

bool Vecteur::compare(Vecteur const& v, double precision) const
{
    bool same(false);
    size_t dim = coordonates_.size();

    if(dim == v.coordonates_.size())
    {
        same = true;

        for(size_t i(0); i<dim && same; i++)
        {
            if(abs(coordonates_[i]-v.coordonates_[i]) > precision) same = false;
        }
    }

    return same;
}

//==============================================
// Math methods definition
//==============================================
Vecteur Vecteur::addition(Vecteur const& v) const
{
    size_t dim(coordonates_.size());
    size_t v_dim(v.coordonates_.size());
    size_t dimMax(max(dim, v_dim));

    vector<double> new_coord;

    for(size_t i(0); i<dimMax; i++)
    {
        // plongement naturel de Rm dans Rn en ajoutant des 0 ∀ m<i≤n
        if(i < dim)
        {
            new_coord.push_back(coordonates_[i]);
        }
        else
        {
            new_coord.push_back(0.);
        }

        if(i < v_dim)
        {
            new_coord[i] += v.coordonates_[i];
        }
        else
        {
            new_coord[i] += 0.;
        }
    }

    return Vecteur(new_coord);
}

Vecteur Vecteur::subtraction(Vecteur const& v) const
{
    // u - v = u + (-v)
    return addition(v.opposite());
}

Vecteur Vecteur::mult(double scalar) const
{
    vector<double> new_coord(coordonates_);
    for(double& value : new_coord) value *= scalar; // ui = a*ui, ∀i

    return Vecteur(new_coord);
}

double Vecteur::dot_prod(Vecteur const& v) const
{
    size_t dimMin(min(coordonates_.size(), v.coordonates_.size()));
    double result(0.);

    for(size_t i(0); i<dimMin; i++) result += coordonates_[i]*v.coordonates_[i];

    return result;
}

Vecteur Vecteur::cross_prod(Vecteur const& v) const
{
    if(coordonates_.size() == 3 && v.coordonates_.size() == 3)
    {
        vector<double> new_coord(3, 0.);

        new_coord[0] = coordonates_[1]*v.coordonates_[2] - coordonates_[2]*v.coordonates_[1];
        new_coord[1] = coordonates_[2]*v.coordonates_[0] - coordonates_[0]*v.coordonates_[2];
        new_coord[2] = coordonates_[0]*v.coordonates_[1] - coordonates_[1]*v.coordonates_[0];

        return Vecteur(new_coord);
    }
    else
    {
        throw invalid_argument("Les vecteurs doivent etre en 3 dimensions !");
    }
}

double Vecteur::norm() const
{
    return pow(norm2(), .5);
}

double Vecteur::norm2() const
{
    double sum(0.);
    for(double value : coordonates_) sum += pow(value, 2);

    return sum;
}

Vecteur Vecteur::opposite() const
{
    return mult(-1);
}

Vecteur Vecteur::unit() const
{
    vector<double> new_coord(coordonates_);
    double norm_ = norm();
    for(double& value : new_coord) value /= norm_;

    return Vecteur(new_coord);
}
