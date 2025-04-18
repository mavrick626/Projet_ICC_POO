#pragma once

#include <iostream>
#include "SupportADessin.h"
#include "Systeme.h"
#include "PointMateriel.h"

class PositionViewer : public SupportADessin
{
    public :
        PositionViewer(std::ostream& s) : sortie(&s) {}

        virtual void dessine(PointMateriel const& point) override
        { *sortie<<point.position()<<std::endl; }
        
        virtual void dessine(Systeme const& sys) override
        { sys.affiche_pos(*sortie); }

    private :
        std::ostream* sortie;
};