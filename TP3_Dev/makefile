COMP=g++
EDL=g++
LIBS=
RM=rm
CLEAN=raz
EXEC=analyseEmpreinte
CXXFLAGS=-W -Wall -D MAP -ansi -pedantic -std=c++11
EDLFLAGS=
RMFLAGS = -f
OBJ=Main.o Dictionnaire.o Fichier.o FichierPatient.o Maladie.o Empreinte.o  Attribut.o Analyse.o

#Création de l’éxécutable Test
$(EXEC) : $(OBJ)
	echo  "EDL de $(EXEC)"
	$(EDL) -o $(EXEC) $(OBJ)

#Création de Main.o
main.o : Main.cpp Main.h Attribut.h Dictionnaire.h Empreinte.h Maladie.h FichierPatient.h FichEmpStream.h
	echo "Comp de Main"
	$(COMP) -c $< $(CXXFLAGS)

#Création de FichEmpStream.o
FichEmpStream.o : FichEmpStream.cpp FichEmpStream.h Dictionnaire.h FichierPatient.h
	echo "Comp de FichEmpStream"
	$(COMP) -c $< $(CXXFLAGS)

#Création de Dictionnaire.o
Dictionnaire.o : Dictionnaire.cpp Dictionnaire.h Fichier.h
	echo "Comp de Dictionnaire"
	$(COMP) -c $< $(CXXFLAGS)

#Création de FichierPatient.o
FichierPatient.o : FichierPatient.cpp FichierPatient.h Fichier.h 
	echo "Comp de FichierPatient"
	$(COMP) -c $< $(CXXFLAGS)

#Création de Fichier.o
Fichier.o : Fichier.cpp Fichier.h Analyse.h Maladie.h
	echo "Comp de Fichier"
	$(COMP) -c $< $(CXXFLAGS)

#Création de Maladie.o
Maladie.o : Maladie.cpp Maladie.h Empreinte.h
	echo "Comp de Maladie"
	$(COMP) -c $< $(CXXFLAGS)


#Création de Empreinte.o
Empreinte.o : Empreinte.cpp Empreinte.h Attribut.h
	echo "Compilation de Empreinte"
	$(COMP) -c $< $(CXXFLAGS)

#Création de Attribut.o
Attribut.o : Attribut.cpp Attribut.h
	echo "Compilation de Attribut"
	$(COMP) -c $< $(CXXFLAGS)

#Création de Analyse.o
Analyse.o : Analyse.cpp Analyse.h
	echo "Compilation de Analyse"
	$(COMP) -c $< $(CXXFLAGS)


.PHONY: $(CLEAN) mrproper

$(CLEAN):
	$(RM) $(RMFLAGS) $(EXEC) $(OBJ) corc

mrproper: clean
	$(RM) $(RMFLAGS) $(EXEC)
