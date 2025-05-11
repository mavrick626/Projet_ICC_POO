#include <iostream>
#include <memory>
#include <string>

#include "Systeme.h"
#include "IntegrateurEulerCromer.h"
#include "ChampElectroMag.h"
#include "FrottementFluide.h"
#include "ChampCompose.h"
#include "Libre.h"
#include "PointMateriel.h"
#include "GnuplotViewer.h"

using namespace std;

int main()
{
    double dt(1e-3);
    double coef(1.33e-5);
    double masse(1.5e-4);
    double q(2e-6);

    GnuplotViewer viewer(0, 1);
    Systeme sys;

    unique_ptr<ChampCompose> ch_tot(make_unique<ChampCompose>());
    ch_tot->ajout_champ(make_unique<ChampElectroMag>(Vecteur(3), Vecteur(0, 0, 0.5)));
    ch_tot->ajout_champ(make_unique<FrottementFluide>(coef));

    sys.ajout_inte(make_unique<IntegrateurEulerCromer>(dt));

    sys.ajout_contrainte(make_unique<Libre>());
    sys.ajout_champ(move(ch_tot));

    sys.ajout_objet(make_unique<PointMateriel> ("particule", masse, q, Vecteur(3) ,Vecteur(0.3, 0, 0)));
    sys.attribuer_cont(0, 0);
    sys.attribuer_champ(0, 0);
    sys.attribuer_inte(0, 0);

    for(int i(0); i<1000; i++)
    {
        sys.evolue();
        sys.dessine_sur(viewer);
    }

    return 0;
}