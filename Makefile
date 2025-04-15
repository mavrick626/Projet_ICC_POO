# Répertoires
SRCDIR = source
INCDIR = head
BUILDDIR = build

# Chemins fichiers
EXEC = exerciceP9
SRC = $(wildcard $(SRCDIR)/*.cc)
OBJ = $(SRC:$(SRCDIR)/%.cc=$(BUILDDIR)/%.o)

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

# Suppression tous file.o
clean:
	if exist $(BUILDDIR)\*.o del /Q $(BUILDDIR)\*.o

# Supperssoin tous file.o + file.exe
cleanall:
	if exist $(BUILDDIR)\*.o del /Q $(BUILDDIR)\*.o
	if exist $(EXEC).exe del /Q $(EXEC).exe
