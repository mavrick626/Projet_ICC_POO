#define _USE_MATH_DEFINES
#include "ContrainteSpherique.h"
#include <cmath>

using namespace std;

//==============================================
// Constructeur
//==============================================
ContrainteSpherique::ContrainteSpherique(double l)
:L(l), k(~constantes::g), d(Vecteur(1, 0, 0)), j(d^k) {}

//==============================================
// Méthodes
//==============================================
Vecteur ContrainteSpherique::applique_force(ObjetPhysique const& obj, Vecteur const& f, double t) const
{
    return Vecteur({theta_pp(obj, f), phi_pp(obj, f)});
}

Vecteur ContrainteSpherique::position(ObjetPhysique const& obj) const
{
    double theta(obj.get_E().get_coord(0));
    double phi(obj.get_E().get_coord(1));

    return L*((cos(theta)-1)*k + sin(theta)*cos(phi)*d + sin(theta)*sin(phi)*j);
}

Vecteur ContrainteSpherique::vitesse(ObjetPhysique const& obj) const
{
    double theta(obj.get_E().get_coord(0));
    double phi(obj.get_E().get_coord(1));
    double theta_p(obj.get_E_point().get_coord(0));
    double phi_p(obj.get_E_point().get_coord(1));

    return L*(-theta_p*sin(theta)*k 
        + (theta_p*cos(theta)*cos(phi)-phi_p*sin(theta)*sin(phi))*d 
        + (theta_p*cos(theta)*sin(phi)+phi_p*sin(theta)*cos(phi))*j);
}

void ContrainteSpherique::affiche(ostream& sortie) const
{
    sortie<<"Contrainte spherique : L = "<<L<<endl;
}

//==============================================
// Méthodes utilitaires
//==============================================
Vecteur ContrainteSpherique::u_rho(ObjetPhysique const& obj) const
{
    double theta(obj.get_E().get_coord(0));
    double phi(obj.get_E().get_coord(1));

    return sin(theta)*cos(phi)*d + sin(theta)*sin(phi)*j + cos(theta)*k;
}

Vecteur ContrainteSpherique::u_theta(ObjetPhysique const& obj) const
{
    double theta(obj.get_E().get_coord(0));
    double phi(obj.get_E().get_coord(1));

    return cos(theta)*cos(phi)*d + cos(theta)*sin(phi)*j - sin(theta)*k;
}

Vecteur ContrainteSpherique::u_phi(ObjetPhysique const& obj) const
{
    double phi(obj.get_E().get_coord(1));

    return -sin(phi)*d + cos(phi)*j;
}

double ContrainteSpherique::theta_pp(ObjetPhysique const& obj, Vecteur const& f) const
{
    double theta(obj.get_E().get_coord(0));
    double phi_p(obj.get_E_point().get_coord(1));

    return (f*u_theta(obj))/(L*obj.get_masse()) + sin(theta)*cos(theta)*pow(phi_p, 2);
}

double ContrainteSpherique::phi_pp(ObjetPhysique const& obj, Vecteur const& f) const
{
    double theta(obj.get_E().get_coord(0));
    double theta_p(obj.get_E_point().get_coord(0));
    double phi_p(obj.get_E_point().get_coord(1));

    if(theta==0 || theta==M_PI) return 0.;
    return (f*u_phi(obj))/(L*sin(theta)*obj.get_masse()) - 2*theta_p*phi_p/tan(theta);
}