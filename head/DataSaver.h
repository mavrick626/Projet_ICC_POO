#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "SupportADessin.h"
#include "PointMateriel.h"
#include "Systeme.h"

class DataSaver : public SupportADessin
{
    public :
        DataSaver(PointMateriel const&);
        virtual void dessine(PointMateriel const&);
        virtual void dessine(Systeme const& sys) {}

    private :
        PointMateriel const& objet;
        std::ofstream sortie;
        
        std::string nom_fichier() const;
};