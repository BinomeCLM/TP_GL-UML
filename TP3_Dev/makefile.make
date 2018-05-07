COMP=g++
EDL=g++
LIBS=
RM=rm
CLEAN=raz
EXEC=analyse
CXXFLAGS=-W -Wall -ansi -pedantic -std=c++11
EDLFLAGS=
RMFLAGS = -f
OBJ=Main.o Dictionnaire.o Fichier.o Maladie.o Analyse.o Empreinte.o  Attribut.o
#Options.o Element.o InformationLog.o Top10.o Graphe.o

#Création de l’éxécutable Test
$(EXEC) : $(OBJ)
	echo  "EDL de $(EXEC)"
	$(EDL) -o $(EXEC) $(OBJ)

#Création de Main.o
main.o : Main.cpp Main.h Attribut.h
	echo "Comp de Main"
	$(COMP) -c $< $(CXXFLAGS)

#Création de Dictionnaire.o
Dictionnaire.o : Dictionnaire.cpp Dictionnaire.h Maladie.h Fichier.h
	echo "Comp de Dictionnaire"
	$(COMP) -c $< $(CXXFLAGS)

#Création de Fichier.o
Fichier.o : Fichier.cpp Fichier.h Attribut.h
	echo "Comp de Fichier"
	$(COMP) -c $< $(CXXFLAGS)

#Création de Maladie.o
Maladie.o : Maladie.cpp Maladie.h Empreinte.h
	echo "Comp de Maladie"
	$(COMP) -c $< $(CXXFLAGS)

#Création de Analyse.o	
Analyse.o : Analyse.cpp Analyse.h Empreinte.h
	echo "Compilation de Analyse"
	$(COMP) -c $< $(CXXFLAGS)
	

#Création de Empreinte.o
Empreinte.o : Empreinte.cpp Empreinte.h Attribut.h Dictionnaire.h
	echo "Compilation de Empreinte"
	$(COMP) -c $< $(CXXFLAGS)

#Création de Attribut.o
Attribut.o : Attribut.cpp Attribut.h
	echo "Compilation de Attribut"
	$(COMP) -c $< $(CXXFLAGS)


.PHONY: $(CLEAN) mrproper

$(CLEAN):
	$(RM) $(RMFLAGS) $(EXEC) $(OBJ) corc

mrproper: clean
	$(RM) $(RMFLAGS) $(EXEC)