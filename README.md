# Projet_ICC_POO
Boite à outils d'élément physique permettant de faire des simulations de systèmes mécaniques

1. Nous avons été jusque P12 (ajout d'intégrateur). Nous avons fait des extensions, 2 exercices simples (P9, en plus du P9 obligatoire), les trois 
simulations complexes (P11) et nous avons ajouter l'intégrateur de Newmark et de RungeKutta. Nous avons également ajouté une
méthode de calcul de l'énergie mécanique d'un objet/système (détails dans le fichier conception).

2. Nous avons une partie graphique pour suivre les objets en temps réel, exerciceP9 et P11-spherique. Nous avons aussi implémenter un GnuplotViewer
comme SupportADessin afin de tracer différentes trajectoires à la fin d'une simulation.

3. En plus des 2 heures aves les assistants, nous estimons avoir chaque passé 6 à 8 heures par semaines sur le projet. Cela
nous fait une moyenne de 8-10h/semaine.

Mode d'emploi : 
    Dans le dossier projet, vous trouverez les dossiers head/ et source/ qui contiennent tous  les .cc et les .h du projet.
    Les dossiers pomme_chute/pendule/corbeau_renard sont les dossiers pour les exercices en vue Qt_GL.
    Tous les dossier build... contiendront des .o

    Pour exécuter un exercice qui n'a pas de vue Qt_GL, il faut ouvrir le Makefile du dossier projet/, choisir quel exercice
    mettre dans EXEC et mettre les autres exercices/tests dans la liste EXCLUDE, puis taper make dans le terminal, pour exécuter
    ./nom_complet_exercice

    Avec vue Qt_GL, il faut aller dans le dossier de l'exercice, ouvrir un terminal et taper qmake, puis make. Et enfin lancer
    avec ./Qt_GL/nom_exercice. Sinon ouvrir le dossier dans QtCreator et lancer avec la flêche en bas à gauche.

    Les dossier img contient quelques plots faits avec notre GnuplotViewer. Pour modifier une exercice (changer l'intégrateur, l'affichage ...), 
    ouvrir le .cc correspondant, éventuellement changer les #include et refaire make (avec le bon nom de cible dans le EXEC du Makefile), 
    il n'y a rien a faire au niveau du Makefile à part vérfier le nom de la cible.

Organisation des fichier :

Version_Finale
    |---projet
        |---build
        |---build-corbeau_renard
        |---build-pendule
        |---build-pomme
        |---head
            |---.h
        |---source
            |---.cc
        |---img
        |---corbeau_renard
        |---pendule
        |---pomme_chute
            |---general
            |---Qt_GL