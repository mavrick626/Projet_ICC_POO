#pragma once
#include "Vecteur.h"
class ObjetMobile {


public:
Vecteur evolution(double t) const; //retourne le vecteur E''
 
private:
Vecteur E;
Vecteur E_point;

};
std :: ostream& operator<<(std::ostream&, ObjetMobiles const&);