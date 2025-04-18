#pragma once

#include <cstdio>
#include "SupportADessin.h"
#include "PointMateriel.h"
#include "Systeme.h"

class GnuplotViewer : public SupportADessin
{
    public:
        GnuplotViewer(size_t, size_t);
        ~GnuplotViewer();

        virtual void dessine(PointMateriel const&) override;
        virtual void dessine(Systeme const&) override;

    private :
        FILE* gnuplotpipe;
        size_t x;
        size_t y;
};