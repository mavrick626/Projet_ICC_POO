#include <iostream>
#include <cstdio>
#include "GnuplotViewer.h"

using namespace std;

//==============================================
// Constructeur
//==============================================
GnuplotViewer::GnuplotViewer(size_t x, size_t y, bool trois_d, string const& n)
: gnuplotpipe(_popen("gnuplot -persist", "w")), x(x), y(y), dim(trois_d), titre(n)  // windows : _popen, linux/mac : popen
{
    if (!gnuplotpipe)
    {
        cerr << "Erreur : impossible d'ouvrir Gnuplot.\n";
    }

    fprintf(gnuplotpipe,  "set title '%s' \n", titre.c_str());
    fprintf(gnuplotpipe, "set xlabel 'x'\n");
    fprintf(gnuplotpipe, "set ylabel 'y'\n");

    if(trois_d)
    {
        fprintf(gnuplotpipe, "set zlabel 'z'\n");
        fprintf(gnuplotpipe, "set ticslevel 0\n"); // Pour que le plan XY soit à z=0
        fprintf(gnuplotpipe, "set view 60, 30\n"); // Angle de vue
        //fprintf(gnuplotpipe, "set view equal xyz\n");

        fprintf(gnuplotpipe, "splot '-' using 1:2:3:4 with points pt 7 ps 1 lc rgb variable notitle\n");
    }
    else
    {
        //fprintf(gnuplotpipe, "set size ratio -1\n");
        //fprintf(gnuplotpipe, "set xrange [-2.2:2.2]\n");
        //fprintf(gnuplotpipe, "set yrange [-.2:2.4]\n");
        fprintf(gnuplotpipe, "set grid lt 1 lw 2 lc rgb '#b9b9b9'\n");
        // pour points
        fprintf(gnuplotpipe, "plot '-' using 1:2:3 with points pt 7 ps 1 lc rgb variable notitle\n");
        // pour ligne 
        //fprintf(gnuplotpipe, "plot '-' using 1:2:3 with line lw 2 lc rgb variable notitle\n");
        // pour ligne et points
        //fprintf(gnuplotpipe, "plot '-' using 1:2:3 with linesp pt 2 ps 1 lw 1.5 lc rgb variable notitle\n");
    }
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
    point.afficher_gnu(gnuplotpipe, x, y, dim);
}

void GnuplotViewer::dessine(Systeme const& sys)
{
    sys.affiche_gnu(gnuplotpipe, x, y, dim);
}