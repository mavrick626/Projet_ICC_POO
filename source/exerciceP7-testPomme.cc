#include <iostream>
#include "PointMateriel.h"
#include "Libre.h"
#include "ChampNewtonien.h"
#include "IntegrateurRungeKutta.h"
#include <iomanip>

using namespace std;

int main()
{
    cout<<setprecision(7);
    double dt(1e-3);
    
    double Rt(6371e3);
    double Mt(5.972e24);
    
    IntegrateurRungeKutta intEC(dt);

    Libre l;
    PointMateriel terre("Terre", Mt, 0, Vecteur(0,0,-Rt), Vecteur(0,0,0), -1, nullptr, &l);
    ChampNewtonien gravite(terre);

    PointMateriel pomme("Pomme", .1, 0, Vecteur(0,0,10), Vecteur(0,0,0), -1, &gravite, &l);

    cout<<0*dt<<"  "<<pomme.position().get_coord(2)<<endl;
    for(int i(0); i<100; i++)
    {
        pomme.energie();
        intEC.integre(pomme, i*dt);
        cout<<(i+1)*dt<<"  "<<pomme.position().get_coord(2)<<endl;
    }

    return 0;
}