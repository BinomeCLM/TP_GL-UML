/*************************************************************************
                           Main  -  description
                             -------------------
    d�but                : 03/04/2018
    copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Main.h) ----------------
#if ! defined ( Main_H )
#define Main_H

//--------------------------------------------------- Interfaces utilisées
#include "Attribut.h"
#include "Dictionnaire.h"
#include "Empreinte.h"
#include "Maladie.h"
#include "FichEmpStream.h"
#include "Analyse.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Main>
//Main permettant de gérer le scénario et les différents services de notre
//application
//------------------------------------------------------------------------

class Main
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	void renseignerDictionnaire(Dictionnaire & d, FichEmpStream * fp);
	// Mode d'emploi :
	// Renseigne des données dans le Dictionnaire d. 
	//Demande à l’utilisateur la source du fichier contenant les données. 
	//fp est le lecteur qui va permettre de lire le fichier et ses données.

	FichierPatient renseignerFichierPatient(FichEmpStream * fp);
	// Mode d'emploi :
	// Renseigne des empreintes à analyser. 
	//Demande à l’utilisateur la source du fichier contenant les données. 
	//fp est le lecteur qui va permettre de lire le fichier et ses données. 
	//Retourne un FichierPatient avec les données à l’intérieur si le fichier est valide sinon retourne un FichierPatient vide.

	void afficherDetailMaladie(long idMaladie, Dictionnaire d);
	// Mode d'emploi :
	// Affiche la maladie dont l’identifiant dans le dictionnaire d est id.  

	

	void afficherDictionnaire(Dictionnaire d);
	// Mode d'emploi :
	// Affiche toutes les maladies et leurs empreintes contenues dans le Dictionnaire d.
	

	void afficherMeilleurCorresp(Dictionnaire d, FichierPatient fp);
	// Mode d'emploi :
	//Affiche le risque de maladie le plus probable pour chaque empreinte du FichierPatient fp. 
	//Cette analyse est faite par rapport au Dictionnaire d. Si des maladies sont à égalité, alors elles sont aussi affichées.

	void afficherTop10(Dictionnaire d, FichierPatient fp);
	//Mode d'emploi :
	//Affiche le top 10 des risques de maladie les plus probables pour chaque empreinte du FichierPatient fp. 
	//Cette analyse est faite par rapport au Dictionnaire d. 
	//Si des maladies sont à égalité au niveau de la dizième position, alors elles sont aussi affichées.

	int lireEntree(int min, int max);
	//Demande à l'utilisatuer de rentrer un numéro entre min et max

	multimap<double, string> retrouverResultat(Analyse a, bool meilleure);
	// Mode d'emploi
	// Retourne une multimap contenant les résultats de l’Analyse à afficher

	//-------------------------------------------- Constructeurs - destructeur

	Main();
	// Mode d'emploi :
	// Constructeur par défaut de Main

	virtual ~Main();
	// Mode d'emploi :
	// Destructeur de Main

};

//-------------------------------- Autres définitions dépendantes de <Main>

#endif // Main_H
