#include <iostream>
#include <cstdio>
#include <limits>
#include "GnuplotViewer.h"

using namespace std;

//==============================================
// Constructeur
//==============================================
GnuplotViewer::GnuplotViewer()
: gnuplotpipe(popen("gnuplot -persist", "w")) // windows : _popen, linux/mac : popen
{
    if (!gnuplotpipe)
    {
        cerr << "Erreur : impossible d'ouvrir Gnuplot.\n";
    }
    else 
    {
        set_dim();
        if(!dim) set_coord(); // appelée ssi affichage 2D
        set_titre();
        set_affichage();
        if(t_affiche != "line") set_marqueur(); // appelée ssi affichage avec marqueurs
        set_taille_marqueur();

        fprintf(gnuplotpipe,  "set title '%s' \n", titre.c_str());


        /*On aurait pu essayer de faire une méthode plus ergonomique pour ''créer la commande
        d'affichage pasà pas pour minimiser les répétitiona, mais faute de temps ça marche déjà
        bien comme ça*/ 
        if(dim)
        {
            fprintf(gnuplotpipe, "set xlabel 'x'\n");
            fprintf(gnuplotpipe, "set ylabel 'y'\n");
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
            char coord1('x');
            char coord2('y');

            if(x==1) coord1='y';
            if(x==2) coord1='z';
            if(y==0) coord2='x';
            if(y==2) coord2='z';

            fprintf(gnuplotpipe, "set xlabel '%c'\n", coord1);
            fprintf(gnuplotpipe, "set ylabel '%c'\n", coord2);

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
}

GnuplotViewer::~GnuplotViewer()
{
    /* Nettoyage de l'entrée pour que la programme ne s'arrête pas
        à cause des entrées de setup */
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
// Choix vue 2 ou 3D
void GnuplotViewer::set_dim()
{
    char entree;
    do
    {
        cout<<"Voulez-vous un graphe 3D ? (o/n)\n > ";
        cin>>entree;

        if(cin.fail()) nettoie();
    }while(entree!='o' && entree!='n');

    if(entree == 'o') dim=true;
    else dim=false;
}

// SI 2D choix des coordonnées
void GnuplotViewer::set_coord()
{
    size_t entree;
    do
    {
        cout<<"Quel est l'indice de la première coordonnee (1=x, 2=y, 3=z)?\n > ";
        cin>>entree;

        if(cin.fail()) nettoie();
    }while(entree<1 || entree>3);
    x = entree-1;

    do
    {
        cout<<"L'indice de la seconde ?\n> ";
        cin>>entree;

        if(cin.fail()) nettoie();
    }while(entree<1 || entree>3 || entree-1==x);
    y = entree-1;
}

// Choix du titre
void GnuplotViewer::set_titre()
{
    string entree;
    do
    {
        nettoie();
        cout<<"Quel est le titre du graphe ?\n> ";
        cin>>entree;
    }while(cin.fail());

    titre = entree;
}

// Choix du type de graphe
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

// SI marqueur, quel symbol
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

// Taille marqueur, ligne
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