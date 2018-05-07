/*************************************************************************
                           Fichier  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Fichier> (fichier Fichier.h) ----------------
#if ! defined ( FICHIER_H )
#define FICHIER_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include <deque>

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


//------------------------------------------------- Surcharge d'opérateurs
    Fichier & operator = ( const Fichier & unFichier );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Fichier ( const Fichier & unFichier );
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
private :
    long nbEmpreintes;
    string sourceFichier;
    deque<pair<string,string> > signature;

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Fichier>

#endif // XXX_H
