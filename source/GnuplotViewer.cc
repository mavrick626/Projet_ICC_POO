#include <iostream>
#include <cstdio>
#include <limits>
#include "GnuplotViewer.h"

using namespace std;

//==============================================
// Constructeur
//==============================================
GnuplotViewer::GnuplotViewer(size_t x, size_t y, bool trois_d, string const& n)
: gnuplotpipe(popen("gnuplot -persist", "w")), x(x), y(y), dim(trois_d), titre(n)  // windows : _popen, linux/mac : popen
{
    if (!gnuplotpipe)
    {
        cerr << "Erreur : impossible d'ouvrir Gnuplot.\n";
    }

    fprintf(gnuplotpipe,  "set title '%s' \n", titre.c_str());
    fprintf(gnuplotpipe, "set xlabel 'x'\n");
    fprintf(gnuplotpipe, "set ylabel 'y'\n");

    set_affichage();
    if(t_affiche != "line") set_marqueur();
    set_taille_marqueur();

    /*On aurait pu essayer de faire une méthode plus ergonomique pour ''créer la commande
    d'affichage pasà pas pour minimiser les répétitiona, mais faute de temps ça marche déjà
    bien comme ça*/ 
    if(trois_d)
    {
        fprintf(gnuplotpipe, "set zlabel 'z'\n");
        fprintf(gnuplotpipe, "set ticslevel 0\n"); // Pour que le plan XY soit à z=0
        fprintf(gnuplotpipe, "set view 60, 30\n"); // Angle de vue
        //fprintf(gnuplotpipe, "set view equal xyz\n");

        if(t_affiche != "line")
        {
            fprintf(gnuplotpipe, "splot '-' using 1:2:3:4 with %s pt %u  ps %f lc rgb variable notitle\n", 
                t_affiche.c_str(), t_marq, s_marq);
        }
        else
        {
            fprintf(gnuplotpipe, "splot '-' using 1:2:3:4 with %s lw %f lc rgb variable notitle\n", 
                t_affiche.c_str(), s_marq);
        }
    }
    else
    {
        fprintf(gnuplotpipe, "set grid lt 1 lw 2 lc rgb '#b9b9b9'\n");
        //fprintf(gnuplotpipe, "set size ratio -1\n");
        //fprintf(gnuplotpipe, "set xrange [-2.2:2.2]\n");
        //fprintf(gnuplotpipe, "set yrange [-.2:2.4]\n");

        if(t_affiche != "line")
        {
            fprintf(gnuplotpipe, "plot '-' using 1:2:3 with %s pt %u  ps %f lc rgb variable notitle\n", 
                t_affiche.c_str(), t_marq, s_marq);
        }
        else
        {
            fprintf(gnuplotpipe, "plot '-' using 1:2:3 with %s lw %f lc rgb variable notitle\n", 
                t_affiche.c_str(), s_marq);
        }
    }
}

GnuplotViewer::~GnuplotViewer()
{
    // Nettoyage de l'entrée pour que la programme ne s'arrête pas (cf. Destructeur)
    nettoie();

    fprintf(gnuplotpipe, "e\n");
    fflush(gnuplotpipe);
    cout<<"Graphe affiche ! Appuie sur Enter pour quitter..."<<endl;
    cin.get();

    pclose(gnuplotpipe); // windows : _pclose, linux/mac : pclose
}

//==============================================
// Dessin
//==============================================
void GnuplotViewer::dessine(ObjetPhysique const& point)
{
    point.afficher_gnu(gnuplotpipe, x, y, dim);
}

void GnuplotViewer::dessine(Systeme const& sys)
{
    sys.affiche_gnu(gnuplotpipe, x, y, dim);
}

//==============================================
// Interface utilisateur
//==============================================
void GnuplotViewer::set_affichage()
{        
    int entree;
    do
    {
        cout<<"Quel type d\'affichage voulez-vous ? Entrez le mumero correspondant"<<endl;
        cout<<"1.points, 2.line, 3.linesp \n > ";
        cin>>entree;

        if(cin.fail()) nettoie();
    }while(entree<1 || entree>3);

    if(entree==1) t_affiche = "points";
    if(entree==2) t_affiche = "line";
    if(entree==3) t_affiche = "linesp";
}

void GnuplotViewer::set_marqueur()
{
    unsigned int entree;
    do
    {
        cout<<"Quel type de marqueur voulez-vous ? Entrez le mumero correspondant\n > ";
        cin>>entree;

        if(cin.fail()) nettoie();
    }while(entree<1 || entree>13);

    t_marq = entree;
}

void GnuplotViewer::set_taille_marqueur()
{
    double entree;
    do
    {
        cout<<"Quelle taille de marqueur voulez-vous ? Entrez la taille\n >";
        cin>>entree;
    
        if(cin.fail()) nettoie();
    }while(entree<0);

    s_marq = entree;
}

void GnuplotViewer::nettoie() const
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}