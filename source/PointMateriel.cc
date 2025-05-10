#include <iostream>
#include "PointMateriel.h"

using namespace std;

//==============================================
// Constructeurs
//==============================================
PointMateriel::PointMateriel(string const& n, double m, double q, Vecteur const& p,
    Vecteur const& v, ChampForce* ch, Contrainte* cont, unsigned int dim_esp_ph)
: ObjetPhysique(n, m, q, p, v, ch, cont, dim_esp_ph) {}

//==============================================
// Méthodes
//==============================================
/* Méthode qui retourne l'accélération selon l'équation du mouvement
pour un point massie (a = F/M, calculée à travers la contrainte)*/
Vecteur PointMateriel::evolution(double temps) const
{
    return contraintes->applique_force(*this, force(temps), temps);
}

// override de l'affichage (semblable à celui d'un ObjetPhysique)
void PointMateriel::afficher(ostream& sortie) const
{
    ObjetPhysique::afficher(sortie);
}