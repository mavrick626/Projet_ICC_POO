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
        GnuplotViewer();
        ~GnuplotViewer();
    // Méthodes dessin
        virtual void dessine(ObjetPhysique const&) override;
        virtual void dessine(Systeme const&) override;
    // interface utilisateur
        void set_dim();
        void set_coord();
        void set_titre();
        void set_affichage();
        void set_marqueur();
        void set_taille_marqueur();

    private :
        FILE* gnuplotpipe; // canal de com vers gnuplot
        // données pour affichage 2 ou 3D
        size_t x;
        size_t y;
        bool dim;
        // settings du plot
        std::string titre;
        std::string t_affiche;
        unsigned int t_marq;
        double s_marq;
        // fonction auxiliaire pour nettoyer cin
        void nettoie() const;
};