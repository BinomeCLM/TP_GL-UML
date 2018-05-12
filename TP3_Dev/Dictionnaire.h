/*************************************************************************
                           Dictionnaire -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
//
//
//------------------------------------------------------------------------

class Dictionnaire : public Fichier
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    bool ajouterMaladie(string chMaladie);

    deque<Maladie> getListeMaladie();

    long getNbElements();


//------------------------------------------------- Surcharge d'opérateurs
   // Dictionnaire & operator = ( const Dictionnaire & unDictionnaire );
    // Mode d'emploi :
    //
    // Contrat :
    //
    friend ostream &operator<<(ostream &os, Dictionnaire & d);

//-------------------------------------------- Constructeurs - destructeur
   // Dictionnaire ( const Dictionnaire & unDictionnaire );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //



    Dictionnaire ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Dictionnaire(string nomFichier, string uneSignature);

    virtual ~Dictionnaire ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE
private :
    deque<Maladie> listeMaladie;

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Dictionnaire>

#endif // Dictionnaire_H
