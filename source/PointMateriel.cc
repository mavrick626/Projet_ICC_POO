#include <iostream>
#include "PointMateriel.h"

using namespace std;

//==============================================
// Constructeurs
//==============================================
PointMateriel::PointMateriel(string const& n, double m, double q, Vecteur const& p,
    Vecteur const& v, int c, ChampForce* ch, Contrainte* cont, Integrateur* inte, unsigned int dim_esp_ph)
: ObjetPhysique(n, m, q, p, v, ch, cont, inte, dim_esp_ph) 
{ if(c==-1) couleur = auto_couleur();
  else couleur = c ;}

//==============================================
// Méthodes
//==============================================
/* Méthode qui retourne l'accélération selon l'équation du mouvement
pour un point massie (a = F/M, calculée à travers la contrainte)*/
Vecteur PointMateriel::evolution(double t) const
{
    if(contraintes != nullptr) return contraintes->applique_force(*this, force(t), t);
    return Vecteur(E.dimension());
}

// override de l'affichage (semblable à celui d'un ObjetPhysique)
void PointMateriel::afficher(ostream& sortie) const
{
    ObjetPhysique::afficher(sortie);
}

void PointMateriel::afficher_gnu(FILE* f, size_t x, size_t y, bool trois_d) const
{
    Vecteur pos(position());

    if(trois_d)
    { fprintf(f, "%f %f %f %d\n", pos.get_coord(0), pos.get_coord(1), pos.get_coord(2), couleur); }
    else
    { fprintf(f, "%f %f %d\n", pos.get_coord(x), pos.get_coord(y), couleur); }
}

int PointMateriel::auto_couleur()
{
    if(nom=="Soleil") return 0xFF8000; // orange
    if(nom=="Satellite") return 0x990099; // violet
    if(nom=="Terre") return 0x0000CC; // bleu
    if(nom=="Mars") return 0xCC0000; // rouge
    if(nom=="Pomme") return 0xFF0000; // rouge
    if(nom=="Pierre") return 0x606060;

    return 0x000000; // noir par défaut
}