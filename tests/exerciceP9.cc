#include <iostream>

#include "IntegrateurEulerCromer.h"
#include "Libre.h"
#include "ChampNewtonien.h"
#include "PointMateriel.h"
#include "Systeme.h"
#include "PositionViewer.h"

using namespace std;

int main()
{
    double dt(1e-3);
    
    double Rt(6371e3);
    double Mt(5.972e24);

    PositionViewer viewer(cout);
    Systeme sys;

    unique_ptr<Integrateur> inte(make_unique<IntegrateurEulerCromer>(IntegrateurEulerCromer(dt)));
    unique_ptr<Libre> libre(make_unique<Libre>(Libre()));

    unique_ptr<ObjetPhysique> terre(make_unique<PointMateriel>(
        PointMateriel("Terre", Mt, Vecteur(0, 0, -Rt))));

    unique_ptr<ObjetPhysique> pomme(make_unique<PointMateriel>(
        PointMateriel("Pomme", 0.1, Vecteur(0,0,10))));
    
    unique_ptr<ChampForce> ch_t(make_unique<ChampNewtonien>(ChampNewtonien(*terre)));
    unique_ptr<ChampForce> ch_p(make_unique<ChampNewtonien>(ChampNewtonien(*pomme)));

    sys.ajout_inte(move(inte));

    sys.ajout_contrainte(move(libre));
    sys.ajout_champ(move(ch_t));
    sys.ajout_champ(move(ch_p));

    sys.ajout_objet(move(terre));
    sys.ajout_objet(move(pomme));

    sys.attribuer_cont(0, 0); // contrainte 0 à obj 0
    sys.attribuer_champ(1, 0); // champ 1 à obj 0

    sys.attribuer_cont(0, 1);
    sys.attribuer_champ(0, 1);

    sys.dessine_sur(viewer);
    for(int i(0); i<1426; i++)
    {
        sys.evolue();
    }
    sys.dessine_sur(viewer);

    return 0;
}