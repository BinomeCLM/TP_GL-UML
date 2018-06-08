
/*************************************************************************
Analyse  -  description
-------------------
d�but                : 03/04/2018
copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
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
// Role de la classe <Analyse>
//Permet de calculer et de stocker les analyse des empreintes des patitents
//
//------------------------------------------------------------------------

class Analyse
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	void calculerProbabilite (Empreinte e, Maladie m);
	// Mode d'emploi :
	//Compare les attributs de e avec les empreintes de la maladie m un à un. 
	



	void genererClassement (Dictionnaire d, Empreinte e);
	// Mode d'emploi :
	//Calcule les correspondances entre l'empreinte e donnée en paramètre 
	//et toutes les maladies du dictionnaire d pour générer un classement. 
	

	multimap<double,string> getCorrespondances();
	// Mode d'emploi :
	//Retourne correspondance

	long getIdEmpreinte();
	// Mode d'emploi :
	//Retourne idEmpreinte

	void setIdEmpreinte(long id);
	// Mode d'emploi :
	//Donne une valeur à idEmpreinte


	//-------------------------------------------- Constructeurs - destructeur
	

    Analyse(long idEmp);
	// Mode d'emploi :
	//Constructeur de Analyse

	Analyse();
	// Mode d'emploi :
	//Constructeur par défaut de Analyse

	virtual ~Analyse();
	// Mode d'emploi :
	//Destructeur de Analyse

	//------------------------------------------------------------------ PRIVE

protected:


private:
	multimap<double,string> correspondances; // Va contenir l'ensemble
	// des correspondances entre les empreintes de la maladie (repere par sa probabilte et son nom)
	long idEmpreinte; //Identifiant de l'empreinte analysee
};

//-------------------------------- Autres d�finitions d�pendantes de <Analyse>

#endif // Analyse_H

