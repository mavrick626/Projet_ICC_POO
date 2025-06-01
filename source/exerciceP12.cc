#include <iostream>
#include <iomanip>

#include "IntegrateurEulerCromer.h"
#include "IntegrateurNewmark.h"
#include "IntegrateurRungeKutta.h"
#include "Libre.h"
#include "GravitationConstante.h"
#include "PointMateriel.h"
#include "Systeme.h"
#include "GnuplotViewer.h"

using namespace std;

int main()
{
    cout<<setprecision(7);
    double dt(5e-2);
    
    //double Rt(6371e3);
    //double Mt(5.972e24);

    GnuplotViewer viewer;
    Systeme sys;

    unique_ptr<ObjetPhysique> p1(make_unique<PointMateriel>(
        "P_EC", .127, 0, Vecteur(0,0,1), Vecteur(0,1,2), 0xFF0000));
    unique_ptr<ObjetPhysique> p2(make_unique<PointMateriel>(
        "P_NM", .127, 0, Vecteur(0,0,1), Vecteur(0,1,2), 0x00FF00));
    unique_ptr<ObjetPhysique> p3(make_unique<PointMateriel>(
        "P_RK", .127, 0, Vecteur(0,0,1), Vecteur(0,1,2), 0x0000FF));

    sys.ajout_inte(make_unique<IntegrateurEulerCromer>(dt));
    sys.ajout_inte(make_unique<IntegrateurNewmark>(dt));
    sys.ajout_inte(make_unique<IntegrateurRungeKutta>(dt));

    sys.ajout_contrainte(make_unique<Libre>());
    sys.ajout_champ(make_unique<GravitationConstante>());

    sys.ajout_objet(move(p1));
    sys.ajout_objet(move(p2));
    sys.ajout_objet(move(p3));

    sys.attribuer_inte(0, 0);
    sys.attribuer_cont(0 ,0);

    for(size_t i(0); i<3; i++)
    {
        sys.attribuer_champ(0, i);
        sys.attribuer_cont(0, i);
        sys.attribuer_inte(i, i);
    }

    sys.dessine_sur(viewer);
    for(int i(0); i<20; i++)
    {
        sys.evolue();
        sys.dessine_sur(viewer);
    }

    return 0;
}