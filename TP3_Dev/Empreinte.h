/*************************************************************************
Empreinte  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( EMPREINTE_H )
#define EMPREINTE_H

//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <deque>
#include <map>

#include "Attribut.h"
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

	void ajouterAttribut(Attribut a);
	// Mode d'emploi :
	//
	// Contrat :
	//

	deque<Attribut> getListeAttributs();
	// Mode d'emploi :
	//
	// Contrat :
	//

	void setNbAttributs(long nbAttr);
	// Mode d'emploi :
	//
	// Contrat :
	//

	long getNbAttributs();
	// Mode d'emploi :
	//
	// Contrat :
	//

	long getIdEmpreinte();
	// Mode d'emploi :
	//
	// Contrat :
	//

	void setIdEmpreinte(long id);
	// Mode d'emploi :
	//
	// Contrat :
	//

    // A revoir !!!
	multimap<double,string> lancerAnalyse(Dictionnaire d);
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------- Surcharge d'opérateurs
	//Empreinte & operator = (const Empreinte & unEmpreinte);
	// Mode d'emploi :
	//
	// Contrat :
	//



	//-------------------------------------------- Constructeurs - destructeur
	//Empreinte(const Empreinte & unEmpreinte);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Empreinte(long id);


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

