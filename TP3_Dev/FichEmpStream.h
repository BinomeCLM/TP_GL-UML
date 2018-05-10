/*************************************************************************
                           FichEmpStream  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <FichEmpStream> (fichier FichEmpStream.h) ----------------
#if ! defined ( FichEmpStream_H )
#define FichEmpStream_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>

#include "Dictionnaire.h"
#include "FichierPatient.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <FichEmpStream>
//
//
//------------------------------------------------------------------------

class FichEmpStream
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    FichierPatient lireFichierPatient (string sourceFichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Dictionnaire lireDictionnaire (string sourceFichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool verifierExtension (string sourceFichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool verifierSignature (string sourceFichier, bool dico);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void compterAttributsSignature (string sourceFichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool verifierFichierVide(string sourceFichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    FichEmpStream & operator = ( const FichEmpStream & unFichEmpStream );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    FichEmpStream ( const FichEmpStream & unFichEmpStream );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    FichEmpStream ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~FichEmpStream ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

private:
    string signatureComplete;
    long nbAttributs;
};

//-------------------------------- Autres définitions dépendantes de <FichEmpStream>

#endif // FichEmpStream_H
