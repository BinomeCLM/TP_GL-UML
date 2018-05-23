/*************************************************************************
Empreinte  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( EMPREINTE_H )
#define EMPREINTE_H

//--------------------------------------------------- Interfaces utilis�es

using namespace std;
#include <deque>
#include <map>

#include "Attribut.h"

class Dictionnaire;
class Analyse;
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

	void ajouterAttribut(Attribut * a);
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

	friend ostream &operator<<(ostream & os, Empreinte & E);



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

