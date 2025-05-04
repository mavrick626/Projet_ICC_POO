#include <iostream>
#include <memory>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

#include "PositionViewer.h"
#include "GnuplotViewer.h"
#include "Systeme.h"
#include "IntegrateurEulerCromer.h"
#include "ChampNewtonien.h"
#include "Libre.h"
#include "PointMateriel.h"

using namespace std;

int main()
{
    GnuplotViewer plot(0, 1);
    Systeme sys;

    double UA(149.6e9); // Unité astronomique
    double Ms(1.989e30); // Masse solaire
    
    double Rt(1*UA); // rayon orbite Terre
    double Rm(1.52*UA); // rayon orbite Mars

    double annee(365*24*3600); // 1 an en seconde
    double Vt(2*M_PI*Rt/annee); // v rotation Terre
    double v(Vt*pow((2*Rm)/(Rm+Rt), 0.5)); //v0 du satellite

    double t(0.); 
    double tf(1.414*annee); // Durée orbite satellite

    double dt(7*24*3600); // pas de temps (1semaine en secondes)

    unique_ptr<Integrateur> inte(make_unique<IntegrateurEulerCromer>(dt));
    
    unique_ptr<ObjetPhysique> soleil(make_unique<PointMateriel>("Soleil", Ms));
    unique_ptr<ObjetPhysique> sat(make_unique<PointMateriel>("Satellite", 1e3, 0, Vecteur(UA, 0, 0), Vecteur(0, v, 0)));

    unique_ptr<Contrainte> libre(make_unique<Libre>());
    unique_ptr<ChampForce> gravite(make_unique<ChampNewtonien>(*soleil));
    unique_ptr<ChampForce> ch_s(make_unique<ChampNewtonien>(*sat));

    sys.ajout_inte(move(inte));

    sys.ajout_champ(move(gravite));
    sys.ajout_champ(move(ch_s));
    sys.ajout_contrainte(move(libre));

    sys.ajout_objet(move(soleil));
    sys.ajout_objet(move(sat));

    sys.attribuer_champ(0, 1);
    sys.attribuer_champ(1, 0);
    sys.attribuer_cont(0, 1);
    sys.attribuer_cont(0, 0);

    sys.dessine_sur(plot);
    while(t<tf)
    {
        sys.evolue();
        sys.dessine_sur(plot);
        t+=dt;
    }

    return 0;
}