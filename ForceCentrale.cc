#include "ForceCentrale.h"

//==============================================
// Constructeur
//==============================================
ForceCentrale::ForceCentrale(ObjetPhysique* pt_obj)
: centre(pt_obj) {}

//==============================================
// Méthode
//==============================================
Vecteur ForceCentrale::quadratique_inverse(ObjetPhysique const& autre) const
{
    Vecteur pos1(centre->position());
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