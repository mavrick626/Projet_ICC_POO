#include <iostream>
#include "PointMateriel.h"
#include "Libre.h"
#include "ChampNewtonien.h"
#include "IntegrateurEulerCromer.h"
#include "Systeme.h"

using namespace std;

int main()
{
    double dt(1e-3);
    
    double Rt(6371e3);
    double Mt(5.972e24);
    
    IntegrateurEulerCromer intEC(dt);

    Libre l;
    PointMateriel terre("Terre", Mt, nullptr, &l, Vecteur(0,0,-Rt), Vecteur(0,0,0));
    ChampNewtonien gravite(terre);

    PointMateriel pomme("Pomme", .1, &gravite, &l, Vecteur(0,0,10), Vecteur(0,0,0));

    cout<<0*dt<<"  "<<pomme.position().get_coord(2)<<endl;
    int i(1);
    while(pomme.position().get_coord(2)>1e-9)
    {
        intEC.integre(pomme, i*dt);
        i++;
    }
    cout<<"t = "<<i*dt<<endl;

    return 0;
}