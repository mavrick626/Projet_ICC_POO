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
// Retourne le vecteur de norme 1/r² pointant vers l'objet central du champ
Vecteur ForceCentrale::quadratique_inverse(ObjetPhysique const& autre) const
{
    // Récupération des positions du centre et de l'objet
    Vecteur pos1(centre.position());
    Vecteur pos2(autre.position());
    Vecteur quadra_inv(autre.get_E().dimension());

    // Calcul de la distance r entre les 2 objets
    Vecteur diff(pos1-pos2);
    double distance(diff.norme2());

    // Test de la différence de position des objets
    if(distance > 1e-18)
    {
        quadra_inv = ~diff; // Calcul du vecteur unitaire (préserve direction/sens)
        quadra_inv *= (1/distance); // Mutiplication à la norme voulue
    }

    return quadra_inv;
}

// Override affichage
void ForceCentrale::afficher(ostream& sortie) const
{
    sortie<<"centre : "<<centre.position()<<", massse : "<<centre.get_masse();
}