#include <iostream>
#include <iomanip>
#include "Vecteur.h"

using namespace std;

int main()
{
    cout<<setprecision(3);

    Vecteur vect1({1., 0., -.1});
    // v2 = (2.6, 3.5,  4.1)
    Vecteur vect2({2.6, 3.5, 4.1});
    Vecteur vect3;
    Vecteur x({1., 0.});

    /* Cette partie
    * (1) pourrait être écrite autrement, par exemple avec des
    *     manipulateurs (set_coord()) ;
    * (2) sera revue dans 2 semaines (constructeurs, surcharge des opérateurs).
    */
    // v1 = (1.0, 2.0, -0.1)
    vect1.set_coord(1, 2.0); // pour tester set_coord()
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

    cout<<"v1 + v2 = ";vect1.addition(vect2).display();
    cout<<"v2 + v1 = ";vect2.addition(vect1).display();
    cout<<"v1 + 0 = ";vect1.addition(Vecteur({0., 0., 0.})).display();
    cout<<"0 + v1 = ";Vecteur({0., 0., 0.}).addition(vect1).display();
    cout<<"v1 - v2 = ";vect1.subtraction(vect2).display();
    cout<<"v2 - v2 = ";vect2.subtraction(vect2).display();
    cout<<"v2 + (1 2) = ";vect2.addition(Vecteur({1, 2})).display();
    cout<<"(1 2) + v2 = ";Vecteur({1, 2}).addition(vect2).display();
    cout<<"-v1 = ";vect1.opposite().display();
    cout<<"-v2 + v1 = ";vect2.opposite().addition(vect1).display();
    cout<<"3*v1 = ";vect1.mult(3).display();
    cout<<"v1*v2 = "<<vect1.scalar_prod(vect2)<<endl;
    cout<<"v2*v1 = "<<vect2.scalar_prod(vect1)<<endl;
    try
    {
        cout<<"v1^v2 = ";
        vect1.vect_prod(vect2).display();
        cout<<"v1^x = ";
        vect1.vect_prod(x).display();
    }
    catch(const invalid_argument& err)
    {
        cerr<<"\nError : "<<err.what()<<endl;
    }
    cout<<"||v1||2 = "<<vect1.norm2()<<endl;
    cout<<"||v1|| = "<<vect1.norm()<<endl;
    cout<<"||v2||2 = "<<vect2.norm2()<<endl;
    cout<<"||v2|| = "<<vect2.norm()<<endl;

    return 0;
} 