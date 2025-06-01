#include <iostream>
#include <memory>
#include <string>
#include <cmath>

#include "GnuplotViewer.h"
#include "Systeme.h"
#include "IntegrateurNewmark.h"
#include "GravitationConstante.h"
#include "Libre.h"
#include "PointMateriel.h"

using namespace std;

int main()
{
    GnuplotViewer plot;
    Systeme sys;

    double dt(5e-2);

    double h(20.); // hauteur initiale pomme
    double d(50.); // distance entre pierre et arbre
    double v(pow(9.82*(d*d+h*h)/(2*h),.5)); // V0 pierre
    double a(atan(h/d)); // angle de lance

    double t(0.); // t0
    double tf(pow(d*d+h*h, .5)/v); //t vol

    unique_ptr<Integrateur> inte(make_unique<IntegrateurNewmark>(dt));

    unique_ptr<ChampForce> gravite(make_unique<GravitationConstante>());
    unique_ptr<Contrainte> libre(make_unique<Libre>());

    unique_ptr<ObjetPhysique> fromage(make_unique<PointMateriel>
    ("Fromage", 5, 0, Vecteur(d, 0, h), Vecteur(3), 0x999999));
    unique_ptr<ObjetPhysique> pierre(make_unique<PointMateriel>
    ("Pierre", 1, 0, Vecteur(0, 0, 0), Vecteur(v*cos(a), 0, v*sin(a)), 0xFF0000));

    sys.ajout_inte(move(inte));
    sys.ajout_champ(move(gravite));
    sys.ajout_contrainte(move(libre));
    sys.ajout_objet(move(fromage));
    sys.ajout_objet(move(pierre));

    sys.attribuer_champ(0, 0);
    sys.attribuer_champ(0, 1);

    sys.attribuer_cont(0, 0);
    sys.attribuer_cont(0, 1);

    sys.attribuer_inte(0, 0);
    sys.attribuer_inte(0, 1);

    while(t < tf)
    {
        sys.dessine_sur(plot);
        sys.evolue();
        t+=dt;
    }

    return 0;
}