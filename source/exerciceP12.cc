#include <iostream>
#include <iomanip>

#include "IntegrateurEulerCromer.h"
#include "IntegrateurNewmark.h"
#include "IntegrateurRungeKutta.h"
#include "Libre.h"
#include "ChampNewtonien.h"
#include "PointMateriel.h"
#include "Systeme.h"
#include "PositionViewer.h"

using namespace std;

int main()
{
    cout<<setprecision(7);
    double dt(1e-3);
    
    double Rt(6371e3);
    double Mt(5.972e24);

    PositionViewer viewer(cout);
    Systeme sys;

    unique_ptr<ObjetPhysique> terre(make_unique<PointMateriel>(
        "Terre", Mt, 0, Vecteur(0,0,-Rt), Vecteur(0,0,0)));
    unique_ptr<ObjetPhysique> p1(make_unique<PointMateriel>(
        "P_EC", .1, 0, Vecteur(0,0,10), Vecteur(0,0,0)));
    unique_ptr<ObjetPhysique> p2(make_unique<PointMateriel>(
        "P_NM", .1, 0, Vecteur(0,0,10), Vecteur(0,0,0)));
    unique_ptr<ObjetPhysique> p3(make_unique<PointMateriel>(
        "P_RK", .1, 0, Vecteur(0,0,10), Vecteur(0,0,0)));

    sys.ajout_inte(make_unique<IntegrateurEulerCromer>(dt));
    sys.ajout_inte(make_unique<IntegrateurNewmark>(dt));
    sys.ajout_inte(make_unique<IntegrateurRungeKutta>(dt));

    sys.ajout_contrainte(make_unique<Libre>());
    sys.ajout_champ(make_unique<ChampNewtonien>(*terre));

    sys.ajout_objet(move(terre));
    sys.ajout_objet(move(p1));
    sys.ajout_objet(move(p2));
    sys.ajout_objet(move(p3));

    sys.attribuer_inte(0, 0);
    sys.attribuer_cont(0 ,0);

    for(size_t i(0); i<3; i++)
    {
        sys.attribuer_champ(0, i+1);
        sys.attribuer_cont(0, i+1);
        sys.attribuer_inte(i, i+1);
    }

    sys.dessine_sur(viewer);
    for(int i(0); i<11; i++)
    {
        sys.evolue();
        sys.dessine_sur(viewer);
    }

    return 0;
}