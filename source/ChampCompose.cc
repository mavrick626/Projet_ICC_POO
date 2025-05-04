#include <iostream>
#include "ChampCompose.h"

using namespace std;

//==============================================
// Méthodes
//==============================================
void ChampCompose::ajout_champ(unique_ptr<ChampForce> && ch)
{
    champs.push_back(move(ch));
}

Vecteur ChampCompose::force(ObjetPhysique const& obj, double t) const
{
    Vecteur result(obj.get_E().dimension());

    for(auto const& pt_ch : champs)
    {
        result += pt_ch->force(obj, t);
    }

    return result;
}

void ChampCompose::afficher(std::ostream& sortie) const
{
    sortie<<"Champ compose : "<<std::endl;
    for(auto const& pt : champs)
    {
        pt->afficher(sortie);
        sortie<<std::endl;
    }
}