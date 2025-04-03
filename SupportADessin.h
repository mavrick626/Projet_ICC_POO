#pragma once

#include "PointMateriel.h"
#include "Systeme.h"

class SupportADessin
{
    public:
        virtual ~SupportADessin() = default;
        // on suppose ici que les supports ne seront ni copiés ni déplacés
    
        virtual void dessine(PointMateriel const&) = 0;
        virtual void dessine(Systeme const&) = 0;
};