
/*************************************************************************
Analyse  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Analyse> (fichier Analyse.h) ----------------
#if ! defined ( ANALYSE_H )
#define ANALYSE_H

//--------------------------------------------------- Interfaces utilis�es
using namespace std;
#include <map>
#include <deque>
#include <string>

class Dictionnaire;
class Empreinte;
class Maladie;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Analyse>
//
//
//------------------------------------------------------------------------

class Analyse
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	void calculerProbabilite (Empreinte e, Maladie m);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void genererClassement (Dictionnaire d, Empreinte e);
	// Mode d'emploi :
	//
	// Contrat :
	//

	multimap<double,string> getCorrespondances();
	long getIdEmpreinte();
	void setIdEmpreinte(long id);

	//------------------------------------------------- Surcharge d'op�rateurs
//	Analyse & operator = (const Analyse & unAnalyse);
	// Mode d'emploi :
	//
	// Contrat :
	//


	//-------------------------------------------- Constructeurs - destructeur
	//Analyse(const Analyse & unAnalyse);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

    Analyse(long idEmp);
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
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

private:
	multimap<double,string> correspondances; // Va contenir l'ensemble
	// des correspondances entre les empreintes de la maladie (rep�r�e par son iD
    // dans la map du dico et la proba associ�e qui est la cl�)
	long idEmpreinte;
};

//-------------------------------- Autres d�finitions d�pendantes de <Analyse>

#endif // Analyse_H

