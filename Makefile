# compilateur
cc = g++
# options de compilation (utilisé en cc -c)
CXXFLAGS = -Wall -ansi -pedantic -Wextra -g -O2
# options de l'edition des liens (utilisé en cc -o) (les bibliothèques utilisées)
LDFLAGS = -lm
# liste des fichiers sources
SRC = $(wildcard *.cpp)
# liste des fichiers objets
OBJ = $(SRC:.cpp=.o)
# l'executable
EXE = exe
# Les regles:

all: $(EXE)

%.o : %.cpp
	$(cc) -c $< $(CXXFLAGS)

$(EXE) : $(OBJ)
	$(cc) -o $(EXE) $(OBJ) $(LDFLAGS)
