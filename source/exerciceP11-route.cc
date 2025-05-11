#include <iostream>
#include <memory>

#include "Systeme.h"
#include "IntegrateurEulerCromer.h"
#include "GravitationConstante.h"
#include "SuspensionSinusoidale.h"
#include "ChampCompose.h"
#include "AllerAvant.h"
#include "PointMateriel.h"
#include "PositionViewer.h"

using namespace std;

int main()
{
    PositionViewer viewer(cout);

    double dt(1e-2);

    unique_ptr<IntegrateurEulerCromer> inte(make_unique<IntegrateurEulerCromer>(dt));
    unique_ptr<AllerAvant> avant(make_unique<AllerAvant>(4.));

    unique_ptr<ChampCompose> total(make_unique<ChampCompose>());
    total->ajout_champ(make_unique<GravitationConstante>());
    total->ajout_champ(make_unique<SuspensionSinusoidale>(1e6, 0.1, 1.5));

    unique_ptr<PointMateriel> p(make_unique<PointMateriel>
        ("point", 2500, 0., Vecteur({5}), Vecteur(1), nullptr, nullptr, 2));

    Systeme sys;

    sys.ajout_inte(move(inte));
    sys.ajout_champ(move(total));
    sys.ajout_contrainte(move(avant));
    sys.ajout_objet(move(p));

    sys.attribuer_champ(0, 0);
    sys.attribuer_cont(0, 0);
    
    sys.dessine_sur(viewer);
    for(int i(0); i<10; i++)
    {
        sys.evolue();
        sys.dessine_sur(viewer);
    }

    return 0;
}