#pragma once

#include <iostream>
#include "TextViewer.h"
#include "PointMateriel.h"
#include "Systeme.h"

class EnergieViewer : public TextViewer
{
    public :
    // Constructeur
        EnergieViewer(std::ostream& s) : TextViewer(s) {}
    // Méthodes
        virtual void dessine(PointMateriel const& point) override
        {
            sortie<<"Energie cin : "<<point.energie_cin()<<std::endl;
            sortie<<"Energie pot : "<<point.energie_pot()<<std::endl;
            sortie<<"Total : "<<point.energie()<<std::endl;
        }

        virtual void dessine(Systeme const& sys) override
        { sys.affiche_e(sortie); }
};