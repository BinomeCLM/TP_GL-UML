/*************************************************************************
Maladie  -  description
-------------------
d�but                : 03/04/2018
copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
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
//Stock et gère les Maladies du Dictionnaires
//------------------------------------------------------------------------

class Maladie
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	bool ajouterEmpreinte(string chEmp, deque<pair<string, string> > signature);
	// Mode d'emploi :
	//Crée une empreinte à partir de chEmp. 
	//Ajoute à la liste d'empreintes de la maladie si la maladie ne contient pas une empreinte avec le même identifiant. 
	//Retourne true si l’empreinte a été ajoutée sinon false.

	Empreinte getEmpreinteById(long id);
	// Mode d'emploi :
	// Retourne l’empreinte ayant l’identifiant id. 
	//Si l’empreinte n’existe pas, retourne une Empreinte par défaut (id=0 sans attribut).
	
	string getNomMaladie();
	// Mode d'emploi :
	//Retourne nomMaladie

	deque<Empreinte> getListeEmpreinte();
	// Mode d'emploi :
	//Retourne listeEmpreinte

	bool empreinteExiste(long id);
	//Mode d'emploi :
	//Retourne True si l’empreinte d’identifiant id existe dans la liste d’empreintes de la maladie. 
	//Retourne False sinon.

    long getIdMaladie();
	//Mode d'emploi :
	//Retourne idMaladie


	//------------------------------------------------- Surcharge d'op�rateurs
    friend ostream &operator<<(ostream & os, Maladie & m);

	//-------------------------------------------- Constructeurs - destructeur

	Maladie(long id, string nom);
	//Mode d'emploi :
	//constructeur de Maladie

	Maladie();
	// Mode d'emploi :
	//Constructeur par défaut de Maladie

	virtual ~Maladie();
	// Mode d'emploi :
	//Destructeur de Maladie

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

