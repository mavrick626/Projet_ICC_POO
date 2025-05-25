#define _USE_MATH_DEFINES

#include <iostream>
#include <memory>
#include <iomanip>
#include <cmath>

#include "Systeme.h"
#include "IntegrateurRungeKutta.h"
#include "PointVectAngulaire.h"
#include "GravitationConstante.h"
#include "ContrainteSpherique.h"
#include "GnuplotViewer.h"

using namespace std;

int main()
{
    GnuplotViewer viewer(0, 1, true);
    Systeme sys;

    double dt(1e-2);
    double m(.1);
    double r(2.2);
    double theta(M_PI/3);
    double phi(0.);

    sys.ajout_inte(make_unique<IntegrateurRungeKutta>(dt));

    sys.ajout_champ(make_unique<GravitationConstante>());
    sys.ajout_contrainte(make_unique<ContrainteSpherique>(r));
    sys.ajout_objet(make_unique<PointVectAngulaire>(
        "pendule", m, 0, Vecteur({theta, phi}), Vecteur({0, 1})));

    sys.attribuer_champ(0, 0); 
    sys.attribuer_cont(0, 0);  
    sys.attribuer_inte(0, 0); 

    sys.dessine_sur(viewer);
    for(int i(0); i<6000; i++)
    {
        sys.evolue();
        sys.dessine_sur(viewer);
    }

    return 0;
}