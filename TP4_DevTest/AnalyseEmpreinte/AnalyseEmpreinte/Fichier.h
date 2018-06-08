/*************************************************************************
                           Fichier  -  description
                             -------------------
    d�but                : 03/04/2018
    copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
*************************************************************************/

//---------- Interface de la classe <Fichier> (fichier Fichier.h) ----------------
#if ! defined ( FICHIER_H )
#define FICHIER_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include <deque>

#include "Maladie.h"
#include "Analyse.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Fichier>
// Classe mère de FichierPatient et Dictionnaire. C'est une classe qui généralise
// les fichiers.
//
//------------------------------------------------------------------------

class Fichier
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    deque<pair<string,string> > getSignature();
	// Mode d'emploi :
	// Retourne la signature du Fichier.
	//
	// Contrat :
	//

    void setNomFichier(string sourceFichier);
	// Mode d'emploi :
	// Définit le nom du fichier sourceFichier à partir 
	// duquel on récupére les données.
	// 
	// Contrat :
	//

    void setSignature(string signature);
	// Mode d'emploi :
	// Définit la signature du Fichier.
	//
	// Contrat :
	//

	string getNomFichier();
	// Mode d'emploi :
	// Retourne le nom du Fichier dont les données du Fichier
	// sont tirées.
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur

    Fichier(string nomFichier, string uneSignature );
	// Mode d'emploi (constructeur de copie) :
	// Constructeur de Fichier.
	// 
	// Contrat :
	//

    Fichier ( );
    // Mode d'emploi :
	// Constructeur par défaut de Fichier.
    //
    // Contrat :
    //

    virtual ~Fichier ( );
    // Mode d'emploi :
    // Destructeur par défaut de Fichier.
	//
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE



protected:
//----------------------------------------------------- Méthodes protégées
	long nbEmpreintes; // Nombre de Maldadie si le fichier est un dictionnaire. Nombre d'empreinte à analyser sinon.
    string sourceFichier; // Nom du fichier dont on tire les données.
    deque<pair<string,string> > signature; // Signature du Fichier.
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Fichier>

#endif // Main_H
