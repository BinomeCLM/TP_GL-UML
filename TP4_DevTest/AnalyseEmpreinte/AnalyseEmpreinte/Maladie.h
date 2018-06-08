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
	// Crée une empreinte à partir de chEmp. 
	// Ajoute à la liste d'Empreinte de la Maladie si la maladie ne contient pas déjà 
	// une empreinte avec le même identifiant. 
	// Retourne true si l’empreinte a été ajoutée sinon false.

	Empreinte getEmpreinteById(long id);
	// Mode d'emploi :
	// Retourne l’empreinte ayant l’identifiant id. 
	// Si l’empreinte n’existe pas, retourne une Empreinte par défaut (id=0 sans attribut).
	
	string getNomMaladie();
	// Mode d'emploi :
	// Retourne nomMaladie, le nom de la Maladie.

	deque<Empreinte> getListeEmpreinte();
	// Mode d'emploi :
	// Retourne listeEmpreinte, la liste des Empreinte de la Maladie.

	bool empreinteExiste(long id);
	//Mode d'emploi :
	// Retourne true si l'Empreinte d’identifiant id existe dans la liste d’Empreinte de la maladie. 
	// Retourne false sinon.

    long getIdMaladie();
	//Mode d'emploi :
	// Retourne idMaladie, l'identifiant de la Maladie.


	//------------------------------------------------- Surcharge d'op�rateurs
    friend ostream &operator<<(ostream & os, Maladie & m);

	//-------------------------------------------- Constructeurs - destructeur

	Maladie(long id, string nom);
	//Mode d'emploi :
	// Constructeur de Maladie

	Maladie();
	// Mode d'emploi :
	// Constructeur par défaut de Maladie

	virtual ~Maladie();
	// Mode d'emploi :
	// Destructeur de Maladie

private:
    long idMaladie; // Identifiant de la Maladie.
	string nomMaladie; // Nom de la Maladie.
	long nbEmpreinte; // Nombre d'Empreinte que contient la Maladie.
	deque<Empreinte> listeEmpreinte; // Liste des Empreinte de la Maladie.

	//------------------------------------------------------------------ PRIVE


protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

};

//-------------------------------- Autres d�finitions d�pendantes de <Maladie>

#endif // MALADIE_H

