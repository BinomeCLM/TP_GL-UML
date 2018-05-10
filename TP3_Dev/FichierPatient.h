/*************************************************************************
                           FichierPatient  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <FichierPatient> (fichier FichierPatient.h) ----------------
#if ! defined ( FichierPatient_H )
#define FichierPatient_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>

#include "Empreinte.h"
#include "Analyse.h"
#include "Dictionnaire.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <FichierPatient>
//
//
//------------------------------------------------------------------------

class FichierPatient : public Fichier
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Analyse* analyserEmpreinte (Dictionnaire d);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool ajouterEmpreinte (string empLigne);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    FichierPatient & operator = ( const FichierPatient & unFichierPatient );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    FichierPatient ( const FichierPatient & unFichierPatient );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    FichierPatient(string nomFichier, string uneSignature);

    FichierPatient ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~FichierPatient ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

private:
    deque<Empreinte> listeEmpAnalyse;

};

//-------------------------------- Autres définitions dépendantes de <FichierPatient>

#endif // FichierPatient_H
