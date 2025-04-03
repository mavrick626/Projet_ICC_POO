#pragma once

#include <iostream>
#include "SupportADessin.h"
#include "PointMateriel.h"

class TextViewer : public SupportADessin
{
    public :
        virtual void dessine(PointMateriel const& point) override
        { std::cout<<point<<std::endl; }

    private :
        std::ostream& sortie;
};