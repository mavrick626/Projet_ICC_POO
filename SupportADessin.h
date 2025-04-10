#pragma once

#include "PointMateriel.h"

class SupportADessin
{
    public:
        virtual ~SupportADessin() = default;
        // on suppose ici que les supports ne seront ni copiés ni déplacés
    
        virtual void dessine(PointMateriel const&) = 0;
};