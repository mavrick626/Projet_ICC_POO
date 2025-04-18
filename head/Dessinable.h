#pragma once

#include "SupportADessin.h"

class Dessinable
{
    public :
        virtual ~Dessinable() = default;
        virtual void dessine_sur(SupportADessin&) = 0;
};