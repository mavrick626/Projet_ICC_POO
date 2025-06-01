#include <iostream>
#include <memory>

#include "Systeme.h"
#include "IntegrateurNewmark.h"
#include "GravitationConstante.h"
#include "SuspensionSinusoidale.h"
#include "ChampCompose.h"
#include "AllerAvant.h"
#include "PointMateriel.h"
#include "GnuplotViewer.h"

using namespace std;

int main()
{
    GnuplotViewer viewer(0, 2, false, "route sinusoidale");

    double dt(1e-2);

    unique_ptr<ChampCompose> total(make_unique<ChampCompose>());
    total->ajout_champ(make_unique<GravitationConstante>());
    total->ajout_champ(make_unique<SuspensionSinusoidale>(1e6, 0.1, 1.5));
    unique_ptr<PointMateriel> p(make_unique<PointMateriel>
        ("camion", 2500., 0., Vecteur(2), Vecteur(2), 0x0000DD, nullptr, nullptr, nullptr, 3));

    Systeme sys;

    sys.ajout_inte(make_unique<IntegrateurNewmark>(dt));
    sys.ajout_champ(move(total));
    sys.ajout_contrainte(make_unique<AllerAvant>(4.));
    sys.ajout_objet(move(p));

    sys.attribuer_champ(0, 0);
    sys.attribuer_cont(0, 0);
    sys.attribuer_inte(0, 0);
    
    sys.dessine_sur(viewer);
    for(int i(0); i<399; i++)
    {
        sys.evolue();
        sys.dessine_sur(viewer);
    }

    return 0;
}