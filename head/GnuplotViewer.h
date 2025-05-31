#pragma once

#include <cstdio>
#include <string>
#include "SupportADessin.h"
#include "ObjetPhysique.h"
#include "Systeme.h"

class GnuplotViewer : public SupportADessin
{
    public :
    // Constructeur/Déstructeur
        GnuplotViewer(size_t, size_t, bool trois_d=false, std::string const& n=std::string("Trajectoire"));
        ~GnuplotViewer();
    // Méthodes
        virtual void dessine(ObjetPhysique const&) override;
        virtual void dessine(Systeme const&) override;

    private :
        FILE* gnuplotpipe;
        size_t x;
        size_t y;
        bool dim;
        std::string titre;
};