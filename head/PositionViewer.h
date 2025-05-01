#pragma once

#include <iostream>
#include "TextViewer.h"

class PositionViewer : public TextViewer
{
    public :
        PositionViewer(std::ostream& s) : TextViewer(s) {}

        virtual void dessine(PointMateriel const& point) override
        { sortie<<point.position()<<std::endl; }
        
        virtual void dessine(Systeme const& sys) override
        { sys.affiche_pos(sortie); }
};