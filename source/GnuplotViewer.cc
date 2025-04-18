#include <iostream>
#include "GnuplotViewer.h"

using namespace std;

//==============================================
// Constructeur
//==============================================
GnuplotViewer::GnuplotViewer() : gnuplotpipe(_popen("gnuplot -persist", "w")) // windows : _popen, linux/mac : popen
{
    if (!gnuplotpipe)
    {
        cerr << "Erreur : impossible d'ouvrir Gnuplot.\n";
    }

    fprintf(gnuplotpipe, "set title 'Coordonnees'\n");
    fprintf(gnuplotpipe, "set xlabel 'x'\n");
    fprintf(gnuplotpipe, "set ylabel 'y'\n");
    fprintf(gnuplotpipe, "plot '-' with points pointtype 1 pointsize 0.8 title 'position'\n");  
}

GnuplotViewer::~GnuplotViewer()
{
    _pclose(gnuplotpipe);
}

//==============================================
// Dessin
//==============================================
void GnuplotViewer::dessine(PointMateriel const& point)
{
    Vecteur const& pos = point.position();
    fprintf(gnuplotpipe, "%f %f\n", pos.get_coord(0), pos.get_coord(2));
}

void GnuplotViewer::dessine(Systeme const& sys)
{
    sys.affiche_gnu(gnuplotpipe);
}

void GnuplotViewer::print() const
{
    fprintf(gnuplotpipe, "e\n");
    fflush(gnuplotpipe);

    cout<<"Graphe affiche !"<<endl;
}