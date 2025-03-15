#include <iostream>
#include "PointMateriel.h"
#include "GravitationConstante.h"

using namespace std;

int main()
{
    GravitationConstante champs;

    PointMateriel p1(10, Vecteur(1, 2, 3), Vecteur(0, .1, .2));
    PointMateriel p2(2, Vecteur(3, 1, 10), Vecteur(.2, .2, 0));

    p1.set_champForce(champs.force(p1));
    p2.set_champForce(champs.force(p2));

    cout<<champs<<endl<<endl;
    cout<<p1<<endl<<endl;
    cout<<p2<<endl;

    return 0;
}