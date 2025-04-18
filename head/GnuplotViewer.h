#pragma once

#include <cstdio>
#include "SupportADessin.h"
#include "PointMateriel.h"
#include "Systeme.h"

class GnuplotViewer : public SupportADessin
{
    public:
        GnuplotViewer();
        ~GnuplotViewer();

        virtual void dessine(PointMateriel const&) override;
        virtual void dessine(Systeme const&) override;

        void print() const;

    private :
        FILE* gnuplotpipe;
};