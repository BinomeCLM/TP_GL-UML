/*************************************************************************
                           FichierPatient  -  description
                             -------------------
    d�but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <FichierPatient> (fichier FichierPatient.h) ----------------
#if ! defined ( FichierPatient_H )
#define FichierPatient_H

//--------------------------------------------------- Interfaces utilis�es
using namespace std;
#include <string>
#include <deque>


#include "Dictionnaire.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <FichierPatient>
//
//
//------------------------------------------------------------------------

class FichierPatient : public Fichier
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste des param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    deque<Analyse> analyserEmpreinte (Dictionnaire d);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool ajouterEmpreinte (string empLigne);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'op�rateurs
    //FichierPatient & operator = ( const FichierPatient & unFichierPatient );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //FichierPatient ( const FichierPatient & unFichierPatient );
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
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s

private:
    deque<Empreinte> listeEmpAnalyse;

};

//-------------------------------- Autres d�finitions d�pendantes de <FichierPatient>

#endif // FichierPatient_H
