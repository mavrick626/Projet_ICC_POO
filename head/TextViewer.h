#pragma once

#include <iostream>
#include "SupportADessin.h"
#include "PointMateriel.h"
#include "Systeme.h"

class TextViewer : public SupportADessin
{
    public :
        TextViewer(std::ostream& s) : sortie(&s) {}
        ~TextViewer() {delete sortie;}

        virtual void dessine(PointMateriel const& point) override
        { *sortie<<point<<std::endl; }

        virtual void dessine(Systeme const& sys) override
        { *sortie<<sys<<std::endl; }

    private :
        std::ostream* sortie;
};