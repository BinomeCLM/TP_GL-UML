#pragma once
#include "Attribut.h"
#include "Dictionnaire.h"
#include "Empreinte.h"
#include "Maladie.h"
#include "FichEmpStream.h"
#include "Analyse.h"
class Main
{
public:
	void renseignerDictionnaire(Dictionnaire & d, FichEmpStream * fp);
	FichierPatient renseignerFichierPatient(FichEmpStream * fp);
	void afficherDetailMaladie(long idMaladie, Dictionnaire d);
	void afficherDictionnaire(Dictionnaire d);
	void afficherMeilleurCorresp(Dictionnaire d, FichierPatient fp);
	void afficherTop10(Dictionnaire d, FichierPatient fp);
	int lireEntree(int min, int max);
	multimap<double, string> retrouverResultat(Analyse a, bool meilleure);
	Main();
	~Main();
};

