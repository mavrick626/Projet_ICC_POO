#include <iostream>
#include "PointMateriel.h"
#include "GravitationConstante.h"
#include "Libre.h"

using namespace std;

int main()
{
    GravitationConstante champs;
    Libre libre;

    PointMateriel p1(&champs, &libre, 10, Vecteur(1, 2, 3), Vecteur(0, .1, .2));
    PointMateriel p2(&champs, &libre, .1, Vecteur(3, 1, 10), Vecteur(.2, .2, 0));

    cout<<champs<<endl<<endl;
    cout<<p1<<endl;
    cout<<"Force : "<<champs.force(p1)<<"\n"<<endl;
    cout<<p2<<endl;
    cout<<"Force : "<<champs.force(p2)<<"\n"<<endl;

    return 0;
}