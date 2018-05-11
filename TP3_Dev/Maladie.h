/*************************************************************************
Maladie  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Maladie> (fichier Maladie.h) ----------------
#if ! defined ( MALADIE_H )
#define MALADIE_H

//--------------------------------------------------- Interfaces utilis�es
#include <deque>
#include <string>
#include "Empreinte.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Maladie>
//
//
//------------------------------------------------------------------------

class Maladie
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste des param�tres );
	// Mode d'emploi :
	//
	// Contrat :
	//
	bool ajouterEmpreinte(string chEmp, deque<pair<string, string> > signature);
	Empreinte * getEmpreinteById(long id);
	string getNomMaladie();
	deque<Empreinte> getListeEmpreinte();
	bool empreinteExiste(long id);
	//Cr�ation de cette m�thode car probl�me de segmentation avec getEmpreinteById...juste en attandant pour pouvoir tester
    //mais en soit vu qu'on a juste besoin de savoir si l'empreinte existe, on pourrait la garder au lieu de getById()


	//------------------------------------------------- Surcharge d'op�rateurs
    // Maladie & operator = (const Maladie & unMaladie);
	// Mode d'emploi :
	//
	// Contrat :
	//


	//-------------------------------------------- Constructeurs - destructeur
	//Maladie(const Maladie & unMaladie);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Maladie(long id, string nom);

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
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

};

//-------------------------------- Autres d�finitions d�pendantes de <Maladie>

#endif // MALADIE_H

