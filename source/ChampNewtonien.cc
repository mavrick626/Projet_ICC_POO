#include <iostream>
#include "ChampNewtonien.h"

using namespace std;

//==============================================
// Constructeur
//==============================================
ChampNewtonien::ChampNewtonien(ObjetPhysique const& obj)
: ForceCentrale(obj) {}

//==============================================
// Méthodes
//==============================================
Vecteur ChampNewtonien::force(ObjetPhysique const& obj, double t) const
{
    // Création d'un vecteur nul dans la dimension de l'objet
    Vecteur f(obj.get_E().dimension());

    double num(constantes::G*centre.get_masse()*obj.get_masse()); // G*M*m
    f = num*quadratique_inverse(obj); // F = G*M*m/R²

    return f;
}

double ChampNewtonien::potentiel(ObjetPhysique const& obj) const
{
    return (constantes::G)*obj.get_masse()*centre.get_masse()/(obj.position()-centre.position()).norme();
}

// override de l'affiche
void ChampNewtonien::afficher(ostream& sortie) const
{
    sortie<<"Champ newtonien, ";
    ForceCentrale::afficher(sortie);
}