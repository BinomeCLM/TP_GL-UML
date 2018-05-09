/*************************************************************************
Empreinte  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( Empreinte_H )
#define Empreinte_H

//--------------------------------------------------- Interfaces utilis�es

using namespace std;
#include <deque>

#include "Attribut.h"
#include "Analyse.h"
#include "Dictionnaire.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Empreinte>
//
//
//------------------------------------------------------------------------

class Empreinte
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste des param�tres );
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

	Analyse lancerAnalyse(Dictionnaire d);
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------- Surcharge d'op�rateurs
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
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

private:
	long idEmpreinte;
	long nbAttributs;
	deque<Attribut> listeAttributs;
};

//-------------------------------- Autres d�finitions d�pendantes de <Empreinte>

#endif // Empreinte_H

