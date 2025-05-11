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
    //fprintf(gnuplotpipe, "set size ratio -1\n");
    //fprintf(gnuplotpipe, "set xrange [-2.2:2.2]\n");
    //fprintf(gnuplotpipe, "set yrange [-.2:2.4]\n");
    fprintf(gnuplotpipe, "set grid lt 1 lw 2 lc rgb '#b9b9b9'\n");
    // pour points
    //fprintf(gnuplotpipe, "plot '-' using 1:2:3 with points pt 7 ps 2 lc rgb variable notitle\n");
    // pour ligne 
    fprintf(gnuplotpipe, "plot '-' using 1:2:3 with line lw 2 lc rgb variable notitle\n");
    // pour ligne et points
    //fprintf(gnuplotpipe, "plot '-' using 1:2:3 with linesp pt 2 ps 1 lw 2 lc rgb variable notitle\n");
}

GnuplotViewer::~GnuplotViewer()
{
    fprintf(gnuplotpipe, "e\n");
    fflush(gnuplotpipe);
    cout<<"Graphe affiche ! Appuie sur Enter pour quitter..."<<endl;
    cin.get();

    _pclose(gnuplotpipe); // windows : _pclose, linux/mac : pclose
}

//==============================================
// Dessin
//==============================================
void GnuplotViewer::dessine(PointMateriel const& point)
{
    point.afficher_gnu(gnuplotpipe, x, y);
}

void GnuplotViewer::dessine(Systeme const& sys)
{
    sys.affiche_gnu(gnuplotpipe, x, y);
}