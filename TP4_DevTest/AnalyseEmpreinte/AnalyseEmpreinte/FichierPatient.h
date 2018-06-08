/*************************************************************************
                           FichierPatient  -  description
                             -------------------
    d�but                : 03/04/2018
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
// R�le de la classe <FichierPatient>
//Stock et gère les empreintes données par l'utilisatuer pour être analysées
//par notre application
//------------------------------------------------------------------------

class FichierPatient : public Fichier
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques

    deque<Analyse> analyserEmpreinte (Dictionnaire d);
    // Mode d'emploi :
    //Pour chaque empreinte de cette classe, appelle la méthode lancerAnalyse. 
	//Chacune des analyses effectuées est regroupées dans une deque stockant des Analyse que l’on retourne.

    bool ajouterEmpreinte (string empLigne);
    // Mode d'emploi :
    //Ajoute l’empreinte e à la liste des empreintes du FichierPatient.

    deque<Empreinte> getListeEmpreinte();
	// Mode d'emploi :
	//Retourne listeEmpAnalyse

//-------------------------------------------- Constructeurs - destructeur
    FichierPatient(string nomFichier, string uneSignature);
	// Mode d'emploi
	// Constructeur de FichierPatient

    FichierPatient ( );
    // Mode d'emploi :
    //Constructeur par défaut

    virtual ~FichierPatient ( );
    // Mode d'emploi :
    //Destructeur par défaut

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s

private:
    deque<Empreinte> listeEmpAnalyse;

};

//-------------------------------- Autres d�finitions d�pendantes de <FichierPatient>

#endif // FichierPatient_H
