#pragma once

class PointMateriel;
class Systeme;

class SupportADessin
{
    public :
    // Destructeur
        virtual ~SupportADessin() = default;
        // on suppose ici que les supports ne seront ni copiés ni déplacés
        SupportADessin() = default;
        SupportADessin(const SupportADessin&) = delete;
        SupportADessin(SupportADessin &&) = delete;
    // Méthodes
        virtual void dessine(PointMateriel const&) = 0;
        virtual void dessine(Systeme const&) = 0;
};