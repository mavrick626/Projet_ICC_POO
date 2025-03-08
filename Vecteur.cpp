#include <iostream>
#include "Vecteur.h"
#include <cmath>
#include <algorithm>

using namespace std;
typedef unsigned int uint;

// Constructor
Vecteur::Vecteur(vector<double> const& coord)
: coordonates_(coord) {}

// Setter definition
void Vecteur::set_coord(unsigned int index, double value)
{
    coordonates_[index] = value;
}

// Other methods definition
void Vecteur::add(double value)
{
    coordonates_.push_back(value);
}

void Vecteur::display() const
{
    for(double value : coordonates_) cout<<value<<" ";
    cout<<endl;
}

bool Vecteur::compare(Vecteur const& v) const
{
    bool same(false);
    size_t dim = coordonates_.size();

    if(dim == v.coordonates_.size())
    {
        same = true;

        for(size_t i(0); i<dim && same; i++)
        {
            if(abs(coordonates_[i]-v.coordonates_[i]) > 1e-10) same = false;
        }
    }

    return same;
}

// Math methods definition

Vecteur Vecteur::addition(Vecteur const& v) const
{
    size_t dimMax(max(coordonates_.size(), v.coordonates_.size()));
    size_t dimMin(min(coordonates_.size(), v.coordonates_.size()));

    Vecteur& biggerVecteur(this);
    const Vecteur& smallerVecteur(v);

    vector<double> new_coord;

    for(size_t i(0); i<dimMin; i++)
    {
        new_coord.push_back(coordonates_[i] + v.coordonates_[i]);
    }

    for(size_t i(dimMin); i<dimMax; i++)
    {
        new_coord.push_back();
    }

    return Vecteur(new_coord);
}

Vecteur Vecteur::mult(double scalar) const
{
    vector<double> new_coord;
    for(double value : coordonates_) new_coord.push_back(value*scalar);

    return Vecteur(new_coord);
}

Vecteur Vecteur::vect_prod(Vecteur const& v) const
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
        return Vecteur({0.});
    }
}

double Vecteur::norm() const
{
    return pow(norm2(), .5);
}

double Vecteur::norm2() const
{
    double sum(0.);

    for(double value : coordonates_) 
    {
        sum += pow(value, 2);
    }
    return sum;
}

Vecteur Vecteur::opposite() const
{
    return mult(-1);
}

Vecteur Vecteur::unitaire() const
{
    vector<double> new_coord;
    double norm_ = norm();

    for(double value : coordonates_) new_coord.push_back(value/norm_);
    return Vecteur(new_coord);
}
