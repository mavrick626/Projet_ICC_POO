#include <iostream>
#include "PointMateriel.h"
#include "GravitationConstante.h"
#include "IntegrateurEulerCromer.h"
#include "Libre.h"

using namespace std;

int main()
{   
    double dt(.01);
    // Intégrateur
    IntegrateurEulerCromer intEC(dt);
    // Champs de force
    GravitationConstante gravite;
    // Contraintes sur l'objet
    Libre l;
    // Objet
    PointMateriel pomme(&gravite, &l, .127, Vecteur(0, 0, 1) ,Vecteur(0, 1, 2));
    cout<<pomme<<endl;
    cout<<"==========================="<<endl;

    for(int i(1); i<=10; i++)
    {
        intEC.integre(pomme, i*dt, dt);
        cout<<"t = "<<i*dt<<endl;
        cout<<pomme.get_E()<<endl;
        cout<<"==========================="<<endl;
    }

    return 0;
}