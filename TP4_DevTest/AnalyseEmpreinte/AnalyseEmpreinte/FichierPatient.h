/*************************************************************************
                           FichierPatient  -  description
                             -------------------
    début                : 03/04/2018
    copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
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
// Rôle de la classe <FichierPatient>
// Stocke et gère les empreintes à analyser renseignées par l'utilisateur.
//
//------------------------------------------------------------------------

class FichierPatient : public Fichier
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques

    deque<Analyse> analyserEmpreinte (Dictionnaire d);
    // Mode d'emploi :
    // Analyse l'ensemble des Empreinte du FichierPatient en 
	// comparant les correspondances avec le Dictionnaire d.
	// Retourne une qeque<Analyse> représentant les résultats pour
	// chaque Empreinte du FichierPatient.

    bool ajouterEmpreinte (string empLigne);
    // Mode d'emploi :
    // Ajoute l’empreinte e à la liste des Empreinte du FichierPatient.
	// Retourne true en cas d'ajout, false sinon.

    deque<Empreinte> getListeEmpreinte();
	// Mode d'emploi :
	// Retourne listeEmpAnalyse, la liste des Empreinte à analyser
	// de FichierPatient.

//-------------------------------------------- Constructeurs - destructeur
    FichierPatient(string nomFichier, string uneSignature);
	// Mode d'emploi
	// Constructeur de FichierPatient

    FichierPatient ( );
    // Mode d'emploi :
    //Constructeur par défaut de FichierPatient.

    virtual ~FichierPatient ( );
    // Mode d'emploi :
    // Destructeur par défaut de FichierPatient.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s

private:
    deque<Empreinte> listeEmpAnalyse; // Liste des Empreinte à analyser.

};

//-------------------------------- Autres d�finitions d�pendantes de <FichierPatient>

#endif // FichierPatient_H
