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
    double y(obj.position().get_coord(1));

    double norme(k*(A*sin(2.*M_PI*(x/L)) - y));
    return Vecteur(norme);
}

void SuspensionSinusoidale::afficher(ostream& sortie) const
{
    sortie<<"Champ rappel sinusoidale : ";
    sortie<<"k = "<<k;
    sortie<<", A = "<<A;
    sortie<<", L = "<<L;
}