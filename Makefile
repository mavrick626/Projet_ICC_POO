# Répertoires
SRCDIR = source
INCDIR = head
BUILDDIR = build

# Chemins fichiers
EXEC = exerciceP9-Ex7-3

SRC = $(wildcard $(SRCDIR)/*.cc)
EXCLUDE = $(SRCDIR)/exerciceP9-Ex3-1.cc $(SRCDIR)/exerciceP9.cc $(SRCDIR)/testIntegrateur.cc $(SRCDIR)/testPointMateriel.cc $(SRCDIR)/testPomme.cc $(SRCDIR)/testVecteur.cc

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
	if exist $(BUILDDIR)\*.o del /Q $(BUILDDIR)\*.o

# Supressoin tous file.o + file.exe
cleanall:
	if exist $(BUILDDIR)\*.o del /Q $(BUILDDIR)\*.o
	if exist $(EXEC).exe del /Q $(EXEC).exe
