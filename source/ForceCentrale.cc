#include <iostream>
#include "ForceCentrale.h"

using namespace std;

//==============================================
// Constructeur
//==============================================
ForceCentrale::ForceCentrale(ObjetPhysique const& ref_obj)
: centre(ref_obj) {}

//==============================================
// Méthode
//==============================================
void ForceCentrale::afficher(ostream& sortie) const
{
    sortie<<"centre : "<<centre.position()<<", massse : "<<centre.get_masse();
}

Vecteur ForceCentrale::quadratique_inverse(ObjetPhysique const& autre) const
{
    Vecteur pos1(centre.position());
    Vecteur pos2(autre.position());
    Vecteur quadra_inv(pos1.dimension());

    Vecteur diff(pos1-pos2);
    double distance(diff.norme2());

    // Test de la différence de position des objets
    if(distance > 1e-18)
    {
        quadra_inv = ~diff; // Calcul du vecteur unitaire (préserve direction/sens)
        quadra_inv *= 1/distance; // Mutiplication à la norme voulue
    }

    return quadra_inv;
}