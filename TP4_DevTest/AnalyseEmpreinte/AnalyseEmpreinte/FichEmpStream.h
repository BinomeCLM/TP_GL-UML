/*************************************************************************
                           FichEmpStream  -  description
                             -------------------
    d�but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <FichEmpStream> (fichier FichEmpStream.h) ----------------
#if ! defined ( FICHEMPSTREAM_H )
#define FICHEMPSTREAM_H

//--------------------------------------------------- Interfaces utilis�es
using namespace std;
#include <string>

#include "Dictionnaire.h"
#include "FichierPatient.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <FichEmpStream>
//
//
//------------------------------------------------------------------------

class FichEmpStream
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste des param�tres );
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

    long compterAttributsSignature (string sourceFichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool verifierFichierVide(string sourceFichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    string getSignatureComplete();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'op�rateurs
    //FichEmpStream & operator = ( const FichEmpStream & unFichEmpStream );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //FichEmpStream ( const FichEmpStream & unFichEmpStream );
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
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s

private:
    string signatureComplete;
    long nbAttributs;
};

//-------------------------------- Autres d�finitions d�pendantes de <FichEmpStream>

#endif // FichEmpStream_H
