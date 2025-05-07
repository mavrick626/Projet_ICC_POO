#include <iostream>
#include <string>
#include "PointMateriel.h"
#include "GravitationConstante.h"
#include "IntegrateurEulerCromer.h"
#include "Libre.h"
#include "GnuplotViewer.h"

using namespace std;

int main()
{   
    GnuplotViewer plot(1, 2);
    double dt(.01);
    // Intégrateur
    IntegrateurEulerCromer intEC(dt);
    // Champs de force
    GravitationConstante gravite;
    // Contraintes sur l'objet
    Libre l;
    // Objet
    PointMateriel pomme("pomme", .127, 0, Vecteur(0, 0, 1) ,Vecteur(0, 1, 2), &gravite, &l);

    double t(0.);
    while(pomme.position().get_coord(2) > 0)
    {
        pomme.dessine_sur(plot);
        intEC.integre(pomme, t, dt);
        t+=dt;
    }

    return 0;
}