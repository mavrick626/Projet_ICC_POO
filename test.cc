#include <iostream>
#include <iomanip>
#include "Vecteur.h"
#include <vector>

using namespace std;

int main()
{
    cout<<setprecision(5);

    Vecteur vect1(1., 0., -.1);
    // v2 = (2.6, 3.5,  4.1)
    Vecteur vect2(2.6, 3.5, 4.1);
    Vecteur vect3(5);

    Vecteur x(1., 0., 0.);
    Vecteur y(0., 1., 0.);
    Vecteur z(0., 0., 1.);

    /* Cette partie
    * (1) pourrait être écrite autrement, par exemple avec des
    *     manipulateurs (set_coord()) ;
    * (2) sera revue dans 2 semaines (constructeurs, surcharge des opérateurs).
    */
    // v1 = (1.0, 2.0, -0.1)
    vect1.set_coord(1, 2.0); // pour tester set_coord()
    vect3 = vect1;

    cout << "Vecteur 1 : ";
    cout<<vect1<<endl;
    cout << endl;

    cout << "Vecteur 2 : ";
    cout<<vect2<<endl;
    cout << endl;

    cout << "Le vecteur 1 est ";
    if (vect1 == vect2) {
        cout << "egal au";
    } else {
        cout << "different du";
    }
    cout << " vecteur 2," << endl << "et est ";
    if (vect1 != vect3) {
        cout << "different du";
    } else {
        cout << "egal au";
    }
    cout << " vecteur 3." << endl;

    cout<<"v1 + v2 = "<<vect1+vect2<<endl;
    cout<<"v2 + v1 = "<<vect2+vect1<<endl;
    //cout<<"v1 + 0 = "<<vect1+Vecteur({0., 0., 0.})<<endl;
    //cout<<"0 + v1 = "<<Vecteur({0., 0., 0.})+vect1<<endl;
    cout<<"v1 - v2 = "<<vect1-vect2<<endl;
    cout<<"v2 - v2 = "<<vect2-vect2<<endl;
    //cout<<"v2 + (1 2) = "<<vect2+Vecteur({1, 2})<<endl;
    //cout<<"(1 2) + v2 = "<<Vecteur({1, 2})+vect2<<endl;
    cout<<"-v1 = "<<-vect1<<endl;
    cout<<"-v2 + v1 = "<<-vect2+vect1<<endl;
    cout<<"3*v1 = "<<3*vect1<<endl;
    cout<<"v1*3 = "<<vect1*3<<endl;
    cout<<"v1*v2 = "<<vect1*vect2<<endl;
    cout<<"v2*v1 = "<<vect2*vect1<<endl;
    try
    {
        cout<<"x^y = "<<(x^y)<<endl;
        cout<<"y^z = "<<(y^z)<<endl;
        cout<<"z^x = "<<(z^x)<<endl;
        cout<<"x^z = "<<(x^z)<<endl;
        cout<<"z^y = "<<(z^y)<<endl;
        cout<<"y^x = "<<(y^x)<<endl;
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