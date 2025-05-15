#include <iostream>
#include <memory>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

#include "PositionViewer.h"
#include "GnuplotViewer.h"
#include "Systeme.h"
#include "IntegrateurNewmark.h"
#include "ChampNewtonien.h"
#include "Libre.h"
#include "PointMateriel.h"

using namespace std;

int main()
{
    GnuplotViewer plot(0, 1);
    Systeme sys;

// Données du problème
    double UA(149.6e9); // Unité astronomique
    double Ms(1.989e30); // Masse solaire
    
    double Rt(1*UA); // rayon orbite Terre
    double Rm(1.52*UA); // rayon orbite Mars

    double annee(365.*24.*3600.); // 1 an en seconde
    double Vt(2*M_PI * (Rt/annee)); // v rotation Terre
    double v(Vt*pow((2*Rm)/(Rm+Rt), .5)); //v0 du satellite

    double t(0.); 
    double tf(1.414*annee); // Durée orbite satellite
    double dt(24*3600.); // pas de temps (1semaine en secondes)

// Initialisation du Système
    unique_ptr<ObjetPhysique> soleil(make_unique<PointMateriel>("Soleil", Ms));
    unique_ptr<ObjetPhysique> sat(make_unique<PointMateriel>
        ("Satellite", 1e3, 0, Vecteur(UA, 0, 0), Vecteur(0, v, 0)));

    /*!! Attention !! pour Newmark si dt est trop grand (~14jours),
    il faut réduire l'épsilon du seuil de convergence pour ne pas partir
    dans une boucle infinie. val de base 1e-6, sinon 1e-3 */ 
    sys.ajout_inte(make_unique<IntegrateurNewmark>(dt));

    sys.ajout_contrainte(make_unique<Libre>());
    sys.ajout_champ(make_unique<ChampNewtonien>(*soleil));
    sys.ajout_champ(make_unique<ChampNewtonien>(*sat));

    sys.ajout_objet(move(soleil));
    sys.ajout_objet(move(sat));

    sys.attribuer_inte(0, 0);
    sys.attribuer_inte(0, 1);
    sys.attribuer_champ(0, 1);
    sys.attribuer_champ(1, 0);
    sys.attribuer_cont(0, 1);
    sys.attribuer_cont(0, 0);

// Run de la simulation
    sys.dessine_sur(plot);
    while(t<tf)
    {
        sys.evolue();
        sys.dessine_sur(plot);
        t+= dt;
    }

    return 0;
}