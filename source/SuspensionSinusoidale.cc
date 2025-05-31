#define _USE_MATH_DEFINES
#include "SuspensionSinusoidale.h"
#include <iostream>
#include <cmath>

using namespace std;

SuspensionSinusoidale::SuspensionSinusoidale(double k, double a, double l)
: k(k), A(a), L(l) {}

Vecteur SuspensionSinusoidale::force(ObjetPhysique const& obj, double t) const
{
    double x(obj.position().get_coord(0));
    double y(obj.position().get_coord(2));

    double norme(k*(A*sin(2.*M_PI*(x/L)) - y));

    size_t dim(obj.get_dim_espace_physique());
    Vecteur f(dim);
    f.set_coord(dim-1, norme);
    return f;
}

double SuspensionSinusoidale::potentiel(ObjetPhysique const& obj) const
{
    double x(obj.position().get_coord(0));
    double y(obj.position().get_coord(2));
    return pow(k*(A*sin(2.*M_PI*(x/L)) - y), 2)/2.;
}

void SuspensionSinusoidale::afficher(ostream& sortie) const
{
    sortie<<"Champ rappel sinusoidale : ";
    sortie<<"k = "<<k;
    sortie<<", A = "<<A;
    sortie<<", L = "<<L;
}