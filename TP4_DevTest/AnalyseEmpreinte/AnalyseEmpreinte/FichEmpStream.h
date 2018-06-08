/*************************************************************************
                           FichEmpStream  -  description
                             -------------------
    d�but                : 03/04/2018
    copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
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
//Permet de lire les fichiers données par l'utilisateur
//et gerer leur contenu
//------------------------------------------------------------------------

class FichEmpStream
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    FichierPatient lireFichierPatient (string sourceFichier);
    // Mode d'emploi :
    //Ouvre et lit le fichier de nom sourceFichier. Les données sont stockées dans un FichierPatient
	//Ce FichierPatient est retourné.

    void lireDictionnaire (Dictionnaire & dico, string sourceFichier);
    // Mode d'emploi :
    //Ouvre et lit le fichier de nom sourceFichier. Les données sont stockées dans un Dictionnaire
	//Ce Dictionnaire est retourné.

    bool verifierExtension (string sourceFichier);
    // Mode d'emploi :
    //Vérifie l’extension de sourceFichier. 
	//Retourne true s’il s’agit d’un extension ‘.txt’ (celle choisie dans notre cas) sinon false.


    bool verifierSignature (string sourceFichier, bool dico);
    // Mode d'emploi :
    //Lit et récupère la signature du fichier sourceFichier et l’a compare 
	//avec la signature renseignée lors du premier chargement de fichier. 
	//Retourne true si elles sont égales, sinon false. Dans le cas où il s’agit du premier chargement on retourne forcément true. 
	//Le boolean dico permet de savoir si le fichier à analyser est un dictionnaire ou un fichier patient.

    long compterAttributsSignature (string sourceFichier);
    // Mode d'emploi :
    //Compte le nombre d’attributs de la signature du fichier sourceFichier. 

    bool verifierFichierVide(string sourceFichier);
    // Mode d'emploi :
    //Analyse si le fichier sourceFichier est vide. Si c’est le cas on retourne false, sinon on retourne true

    string getSignatureComplete();
    // Mode d'emploi :
    //Retourne signatureComplete

//-------------------------------------------- Constructeurs - destructeu

    FichEmpStream ( );
    // Mode d'emploi :
    //Constructeur de FichEmpSteam

    virtual ~FichEmpStream ( );
    // Mode d'emploi :
    //Destructeur de FichEmpStream

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
