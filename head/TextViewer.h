#pragma once

#include <iostream>
#include "SupportADessin.h"
#include "PointMateriel.h"
#include "Systeme.h"

class TextViewer : public SupportADessin
{
    public :
    // Constructeur
        TextViewer(std::ostream& s) : sortie(s) {}
    // Méthodes
        virtual void dessine(PointMateriel const& point) override
        { sortie<<point<<std::endl; }

        virtual void dessine(Systeme const& sys) override
        { sortie<<sys<<std::endl; }

    protected :
        std::ostream& sortie;
};