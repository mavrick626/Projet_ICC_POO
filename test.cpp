#include <iostream>
#include <iomanip>
#include "Vecteur.h"

using namespace std;

int main()
{
    cout<<setprecision(3);

    Vecteur vect1;
    Vecteur vect2;
    Vecteur vect3;

    Vecteur x({1. ,0., 0.});
    Vecteur y({0., 1., 0.});

    /* Cette partie
    * (1) pourrait être écrite autrement, par exemple avec des
    *     manipulateurs (set_coord()) ;
    * (2) sera revue dans 2 semaines (constructeurs, surcharge des opérateurs).
    */
    // v1 = (1.0, 2.0, -0.1)
    vect1.add(1.0); vect1.add(0.0); vect1.add(3.);
    vect1.set_coord(1, 2.0); // pour tester set_coord()

    // v2 = (2.6, 3.5,  4.1)
    vect2.add(12.); vect2.add(5.);

    vect3 = vect1;

    cout << "Vecteur 1 : ";
    vect1.display();
    cout << endl;

    cout << "Vecteur 2 : ";
    vect2.display();
    cout << endl;

    cout << "Le vecteur 1 est ";
    if (vect1.compare(vect2)) {
        cout << "egal au";
    } else {
        cout << "different du";
    }
    cout << " vecteur 2," << endl << "et est ";
    if (! vect1.compare(vect3)) {
        cout << "different du";
    } else {
        cout << "egal au";
    }
    cout << " vecteur 3." << endl;

    cout<<"2*v1 = ";vect1.mult(2).display();
    cout<<"-v1 = ";vect1.opposite().display();
    cout<<"u1 = ";vect1.unitaire().display();

    cout<<"norm v2 = "<<vect2.norm()<<endl;
    cout<<"X ^ Y = ";x.vect_prod(y).display();

    cout<<"x + y = ";x.addition(y).display();
    cout<<"x - y = ";x.subtraction(y).display();

    cout<<"V1.V2 = "<<vect1.scalar_prod(vect2)<<endl;

    return 0;
} 