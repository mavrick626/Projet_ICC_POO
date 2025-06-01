# Disclaimer ! 
# Notre Makefile ne ressemble pas à l'exemple du prof
# ou à son tutoriel. Nous l'avons conçu à partir d'un 
# tuto YouTube : https://www.youtube.com/watch?v=-riHEHGP2DU
# Et nous l'avons modifiés avec des commandes trouver sur 
# internet ou à l'aide de ChatGPT (qui nous a simplement aidé
# à trouver la syntaxe pour 'filter-out' par exemple)
#
# Les avantages sont qu'il ne faut pas modifier le makefile
# quand on modifie nos include, ou qu'on ajoute des classes. 
# Mais on ne peut compiler qu'une cible à la fois et TOUT
# les .cc sont compilés en .o même s'ils ne sont pas utile
#  pour la cible

# Répertoires
SRCDIR = source
INCDIR = head
BUILDDIR = build

# Chemins fichiers
EXEC = exerciceP11-spherique

SRC = $(wildcard $(SRCDIR)/*.cc)
EXCLUDE = \
		$(SRCDIR)/exerciceP12.cc \
		$(SRCDIR)/exerciceP11-route.cc \
		$(SRCDIR)/exerciceP6-testIntegrateur.cc \
		$(SRCDIR)/exerciceP11-magnetique.cc \
		$(SRCDIR)/exerciceP9-Ex3-1.cc \
		$(SRCDIR)/exerciceP9-Ex7-3.cc \
		$(SRCDIR)/exerciceP7-testPomme.cc \
		$(SRCDIR)/exerciceP7-testPointMateriel.cc \
		$(SRCDIR)/exerciceP9.cc \
		$(SRCDIR)/exerciceP4-testVecteur.cc

F_SRC = $(filter-out $(EXCLUDE), $(SRC))
OBJ = $(F_SRC:$(SRCDIR)/%.cc=$(BUILDDIR)/%.o)

# Compilateur
CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++17 -pedantic -Wall -I$(INCDIR)

# Cible
all: $(EXEC)

# Compilation fichiers sources
$(BUILDDIR)/%.o : $(SRCDIR)/%.cc 
	$(CC) -c $< -o $@ $(CXXFLAGS)

# Edition de liens, création exécutable
$(EXEC) : $(OBJ)
	$(CC) $^ -o $@

# Supression tous file.o
clean:
	rm -f $(BUILDDIR)/*.o
#	if exist $(BUILDDIR)\*.o del /Q $(BUILDDIR)\*.o

# Supressoin tous file.o + file.exe
cleanall:
	rm -f $(BUILDDIR)/*.o
	rm -f $(EXEC)
#	if exist $(BUILDDIR)\*.o del /Q $(BUILDDIR)\*.o
#	if exist $(EXEC).exe del /Q $(EXEC).exe