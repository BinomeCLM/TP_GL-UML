/*************************************************************************
Maladie  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Maladie> (fichier Maladie.h) ----------------
#if ! defined ( MALADIE_H )
#define MALADIE_H

//--------------------------------------------------- Interfaces utilisées
#include <deque>
#include <queue>
#include "Empreinte.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Maladie>
//
//
//------------------------------------------------------------------------

class Maladie 
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat : 
	//
	bool Maladie::ajouterEmpreinte(string chEmp, dequeue<pair<string, string>> signature);
	Empreinte getEmpreinteById(long id);
	 
	//------------------------------------------------- Surcharge d'opérateurs
//	Maladie & operator = (const Maladie & unMaladie);
	// Mode d'emploi :
	//
	// Contrat :
	//


	//-------------------------------------------- Constructeurs - destructeur
	Maladie(const Maladie & unMaladie);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Maladie();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Maladie();
	// Mode d'emploi :
	//
	// Contrat :
	//

private:
	long idMaladie;
	string nomMaladie;
	long nbEmpreinte;
	deque<Empreinte> listeEmpreinte; 

	//------------------------------------------------------------------ PRIVE


protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Maladie>

#endif // MALADIE_H

