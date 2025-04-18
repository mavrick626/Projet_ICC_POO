#include <iostream>
#include <cstdio>
#include "GnuplotViewer.h"

using namespace std;

//==============================================
// Constructeur
//==============================================
GnuplotViewer::GnuplotViewer(size_t x, size_t y)
: gnuplotpipe(_popen("gnuplot -persist", "w")), x(x), y(y)  // windows : _popen, linux/mac : popen
{
    if (!gnuplotpipe)
    {
        cerr << "Erreur : impossible d'ouvrir Gnuplot.\n";
    }

    fprintf(gnuplotpipe, "set title 'Trajectoire'\n");
    fprintf(gnuplotpipe, "set xlabel 'x'\n");
    fprintf(gnuplotpipe, "set ylabel 'y'\n");
    fprintf(gnuplotpipe, "plot '-' with points pt 7 ps 1title 'position'\n");  
}

GnuplotViewer::~GnuplotViewer()
{
    fprintf(gnuplotpipe, "e\n");
    fflush(gnuplotpipe);
    cout<<"Graphe affiche ! Appuie sur Enter pour quitter..."<<endl;
    cin.get();

    _pclose(gnuplotpipe);
}

//==============================================
// Dessin
//==============================================
void GnuplotViewer::dessine(PointMateriel const& point)
{
    Vecteur const& pos = point.position();
    fprintf(gnuplotpipe, "%f %f\n", pos.get_coord(0), pos.get_coord(1));
}

void GnuplotViewer::dessine(Systeme const& sys)
{
    sys.affiche_gnu(gnuplotpipe, x, y);
}