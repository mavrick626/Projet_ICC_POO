# Répertoires
SRCDIR = source
INCDIR = head
BUILDDIR = build

# Chemins fichiers
EXEC = exerciceP11-route

SRC = $(wildcard $(SRCDIR)/*.cc)
EXCLUDE = \
		$(SRCDIR)/exerciceP12.cc \
		$(SRCDIR)/exerciceP11-spherique.cc\
		$(SRCDIR)/exerciceP11-magnetique.cc \
		$(SRCDIR)/exerciceP9-Ex3-1.cc \
		$(SRCDIR)/exerciceP9.cc \
		$(SRCDIR)/exerciceP9-Ex7-3.cc \
		$(SRCDIR)/exerciceP7-testPomme.cc\
		$(SRCDIR)/exerciceP7-testPointMateriel.cc \
		$(SRCDIR)/exerciceP6-testIntegrateur.cc\
		$(SRCDIR)/exerciceP4-testVecteur.cc

F_SRC = $(filter-out $(EXCLUDE), $(SRC))
OBJ = $(F_SRC:$(SRCDIR)/%.cc=$(BUILDDIR)/%.o)

# Compilateur
CC = g++
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
#	 rm -f $(BUILDDIR)/*.o
	if exist $(BUILDDIR)\*.o del /Q $(BUILDDIR)\*.o

# Supressoin tous file.o + file.exe
cleanall:
#	 rm -f $(BUILDDIR)/*.o
#	 rm -f $(EXEC)
	if exist $(BUILDDIR)\*.o del /Q $(BUILDDIR)\*.o
	if exist $(EXEC).exe del /Q $(EXEC).exe
