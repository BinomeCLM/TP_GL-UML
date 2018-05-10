
/*************************************************************************
Analyse  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Analyse> (fichier Analyse.h) ----------------
#if ! defined ( Analyse_H )
#define Analyse_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <map>
#include <deque>
#include <string>

#include "Empreinte.h"
#include "Fichier.h"
#include "Maladie.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Analyse>
//
//
//------------------------------------------------------------------------

class Analyse
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	Analyse calculerProbabilité (Empreinte e, Maladie, m);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void genererClassement (Fichier d, Empreinte e);
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------- Surcharge d'opérateurs
	Analyse & operator = (const Analyse & unAnalyse);
	// Mode d'emploi :
	//
	// Contrat :
	//


	//-------------------------------------------- Constructeurs - destructeur
	Analyse(const Analyse & unAnalyse);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

    Analyse(Long idEmp);
	// Mode d'emploi :
	//
	// Contrat :
	//

	Analyse();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Analyse();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

private:
	multimap<double,string> correspondances; // Va contenir l'ensemble
	// des correspondances entre les empreintes de la maladie (repérée par son iD
    // dans la map du dico et la proba associée qui est la clé)
	long idEmpreinte;
};

//-------------------------------- Autres définitions dépendantes de <Analyse>

#endif // Analyse_H

