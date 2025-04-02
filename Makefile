CC = g++
CXXFLAGS = -std=c++17 -pedantic -Wall

EXEC = testPomme
SRC = $(wildcard *.cc)
OBJ = $(SRC:.cc=.o)

all: $(EXEC)

%.o : %.cc %.h
	$(CC) -c $< -o $@

$(EXEC) : $(OBJ)
	$(CC) $^ -o $@

# remove all file.o
clean:
	del /Q *.o

# remove all file.o + file.exe
cleanall:
	del /Q *.o, *.exe
