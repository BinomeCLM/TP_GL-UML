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
//
//
//------------------------------------------------------------------------

class Fichier
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    deque<pair<string,string> > getSignature();
    void setNomFichier(string sourceFichier);
    void setSignature(string signature);
	string getNomFichier();


//------------------------------------------------- Surcharge d'opérateurs
   // Fichier & operator = ( const Fichier & unFichier );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Fichier ( const Fichier & unFichier );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Fichier(string nomFichier, string uneSignature );

    Fichier ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Fichier ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE



protected:
//----------------------------------------------------- Méthodes protégées
	long nbEmpreintes; // Nom à changer: pour un dico, ça représente le nombre de maladie
    // et pour un FichierPatient le nombre d'empreinte à analyser.
    string sourceFichier;
    deque<pair<string,string> > signature;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Fichier>

#endif // Main_H
