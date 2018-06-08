/*************************************************************************
                           Dictionnaire -  description
                             -------------------
    d�but                : 03/04/2018
    copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
*************************************************************************/

//---------- Interface de la classe <Dictionnaire> (fichier Dictionnaire.h) ----------------
#if ! defined ( DICTIONNAIRE_H )
#define DICTIONNAIRE_H

//--------------------------------------------------- Interfaces utilisées
#include "Fichier.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Dictionnaire>
//Représente notre base de données. Stocke l'ensemble des Maladie et leurs Empreintes
//------------------------------------------------------------------------

class Dictionnaire : public Fichier
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool ajouterMaladie(string chMaladie);
	// Mode d'emploi :
	//Vérifie que ni la maladie ni que l'empreinte associée existe déjà dans le Dictionnaire.
	//Dans ce cas la Maladie est ajoutée au Dictionnaire

    deque<Maladie> getListeMaladie();
	// Mode d'emploi :
	//Retourne listeMaladie

    Maladie getMaladieById(long id);
	// Mode d'emploi :
	//Retourne la maladie qui possède l'identifiant id. 
	//Si la maladie n’existe pas dans le dictionnaire, on retourne null.

	long getNbElements();
	// Mode d'emploi :
	// Retourne nbElements

	void setSignature(string signature);
	// Mode d'emploi :
	// Definit la valeur de signature

	void setNomFichier(string sourceFich);
	//Mode d'emploi :
	// Definit la valeur de sourceFichier


//------------------------------------------------- Surcharge d'opérateurs
  
    friend ostream &operator<<(ostream &os, Dictionnaire & d);
	// Mode d'emploi :
	//Surcharge de l'opérateur <<

//-------------------------------------------- Constructeurs - destructeur

    Dictionnaire(string nomFichier, string uneSignature);
	// Mode d'emploi 
	// Constructeur par défaut de Dictionnaire

	Dictionnaire();
	// Mode d'emploi :
	// Constructeur par défaut de Dictionnaire

    virtual ~Dictionnaire ( );
    // Mode d'emploi :
    // Destructeur de Dictionnaire

//------------------------------------------------------------------ PRIVE
private :
    deque<Maladie> listeMaladie;

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Dictionnaire>

#endif // Dictionnaire_H
