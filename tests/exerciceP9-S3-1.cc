#include <iostream>
#include <memory>
#include <string>
#include <cmath>

#include "PositionViewer.h"
#include "GnuplotViewer.h"
#include "Systeme.h"
#include "IntegrateurEulerCromer.h"
#include "GravitationConstante.h"
#include "Libre.h"
#include "PointMateriel.h"

using namespace std;

int main()
{
    PositionViewer console(cout);
    GnuplotViewer plot;
    Systeme sys;

    double dt(1e-1);

    double h(20.);
    double d(50.);
    double v(pow(9.82*(d*d+h*h)/(2*h),.5));
    double tg(h/d);
    double t(0.);
    double tf(pow(d*d+h*h, .5)/v);

    unique_ptr<Integrateur> inte(make_unique<IntegrateurEulerCromer>
        (IntegrateurEulerCromer(dt)));

    unique_ptr<ChampForce> gravite(make_unique<GravitationConstante>
        (GravitationConstante()));
    unique_ptr<Contrainte> libre(make_unique<Libre>(Libre()));

    unique_ptr<ObjetPhysique> fromage(make_unique<PointMateriel>
    (PointMateriel("fromage", 5, Vecteur(d, 0, h))));
    unique_ptr<ObjetPhysique> pierre(make_unique<PointMateriel>
    (PointMateriel("pierre", 1, Vecteur(0, 0, 0), Vecteur(v*cos(atan(tg)), 0, v*sin(atan(tg))))));

    sys.ajout_inte(move(inte));
    sys.ajout_champ(move(gravite));
    sys.ajout_contrainte(move(libre));
    sys.ajout_objet(move(fromage));
    sys.ajout_objet(move(pierre));

    sys.attribuer_champ(0, 0);
    sys.attribuer_champ(0, 1);

    sys.attribuer_cont(0, 0);
    sys.attribuer_cont(0, 1);

    while(t < tf)
    {
        sys.dessine_sur(console);
        sys.dessine_sur(plot);
        sys.evolue();
        t+=dt;
    }

    plot.print();

    return 0;
}