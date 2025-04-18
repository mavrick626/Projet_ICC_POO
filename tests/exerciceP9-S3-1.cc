#include <iostream>
#include <memory>
#include <string>
#include <cmath>

#include "TextViewer.h"
#include "Systeme.h"
#include "IntegrateurEulerCromer.h"
#include "GravitationConstante.h"
#include "Libre.h"
#include "PointMateriel.h"

using namespace std;

int main()
{
    TextViewer console(cout);
    Systeme sys;

    double dt(1e-3);

    double h(20.);
    double d(10.);
    double v(3*pow(10*(d*d+h*h)/(2*h),.5));
    double a(3.1415 * 45/180);
    double t(0.);
    double tf(pow(d*d+h*h, .5)/v);

    unique_ptr<Integrateur> inte(make_unique<IntegrateurEulerCromer>
        (IntegrateurEulerCromer(dt)));

    unique_ptr<ChampForce> gravite(make_unique<GravitationConstante>
        (GravitationConstante()));
    unique_ptr<Contrainte> libre(make_unique<Libre>(Libre()));

    unique_ptr<ObjetPhysique> fromage(make_unique<PointMateriel>
    (PointMateriel("fromage", 5, nullptr, nullptr, Vecteur(0, 0, h), Vecteur(3))));
    unique_ptr<ObjetPhysique> pierre(make_unique<PointMateriel>
    (PointMateriel("pierre", 1, nullptr, nullptr, Vecteur(-d, 0, 0), Vecteur(v*cos(a), 0, v*sin(a)))));

    sys.ajout_inte(move(inte));
    sys.ajout_champ(move(gravite));
    sys.ajout_contrainte(move(libre));
    sys.ajout_objet(move(fromage));
    sys.ajout_objet(move(pierre));

    sys.attribuer_champ(0, 0);
    sys.attribuer_champ(0, 1);

    sys.attribuer_cont(0, 0);
    sys.attribuer_cont(0, 1);

    console.dessine(sys);
    while(t < tf)
    {
        sys.evolue();
        t+=dt;
    }
    console.dessine(sys);

    return 0;
}