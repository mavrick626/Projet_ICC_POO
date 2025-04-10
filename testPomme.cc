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
    /*
    IntegrateurEulerCromer intEC(dt);

    Libre l;
    PointMateriel terre("Terre", nullptr, &l, Mt, Vecteur(0,0,-Rt), Vecteur(0,0,0));
    ChampNewtonien gravite(terre);

    PointMateriel pomme("Pomme", &gravite, &l, .1, Vecteur(0,0,10), Vecteur(0,0,0));

    cout<<0*dt<<"  "<<pomme.position().get_coord(2)<<endl;
    int i(1);
    while(pomme.position().get_coord(2)>1e-9)
    {
        intEC.integre(pomme, i*dt);
        i++;
    }
    cout<<"t = "<<i*dt<<endl;
    */
   Systeme sys;

    unique_ptr<Integrateur> inte(make_unique<IntegrateurEulerCromer>(IntegrateurEulerCromer(dt)));
    unique_ptr<Libre> libre(make_unique<Libre>(Libre()));

    unique_ptr<ObjetPhysique> terre(make_unique<PointMateriel>(
        PointMateriel("Terre", nullptr, nullptr, Mt, Vecteur(0, 0, -Rt))));

    unique_ptr<ObjetPhysique> pomme(make_unique<PointMateriel>(
        PointMateriel("Pomme", nullptr, nullptr, 0.1, Vecteur(0,0,10))));
    
    unique_ptr<ChampForce> ch(make_unique<ChampNewtonien>(ChampNewtonien(*terre)));

    sys.ajout_inte(move(inte));

    sys.ajout_contrainte(move(libre));
    sys.ajout_champ(move(ch));

    sys.ajout_objet(move(terre));
    sys.ajout_objet(move(pomme));

    sys.att_cont(0, 0);

    sys.att_cont(0, 1);
    sys.att_champ(0, 1);

    cout<<sys<<endl;

    for(int i(0); i<1400; i++)
    {
        sys.evolue();
        if((i+1)%100 == 0) cout<<sys<<endl;
    }

    return 0;
}