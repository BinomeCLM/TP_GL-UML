/*************************************************************************
Empreinte  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( Empreinte_H )
#define Empreinte_H

//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <deque>

#include "Attribut.h"
#include "Analyse.h"
#include "Dictionnaire.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Empreinte>
//
//
//------------------------------------------------------------------------

class Empreinte 
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	// void ajouterAttribut(Attribut a);
	// Mode d'emploi :
	//
	// Contrat :
	//

	// Analyse lancerAnalyse(Fichier d);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void ajouterAttribut(Attribut a);
	deque<Attribut> getListeAttributs();
	void setNbAttributs(long nbAttr);
	//void Empreinte::getListeAttribut(Attribut a);
	long getnbAttributs();
	long getIdEmpreinte();
	//Analyse lancerAnalyse(Dictionnaire d) ;

	//------------------------------------------------- Surcharge d'opérateurs
	Empreinte & operator = (const Empreinte & unEmpreinte);
	// Mode d'emploi :
	//
	// Contrat :
	//



	//-------------------------------------------- Constructeurs - destructeur
	Empreinte(const Empreinte & unEmpreinte);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Empreinte();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Empreinte();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

private:
	long idEmpreinte;
	long nbAttributs;
	deque<Attribut> listeAttributs;
};

//-------------------------------- Autres définitions dépendantes de <Empreinte>

#endif // Empreinte_H

