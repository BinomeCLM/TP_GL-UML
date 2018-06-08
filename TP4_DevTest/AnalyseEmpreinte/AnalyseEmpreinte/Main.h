/*************************************************************************
                           Main  -  description
                             -------------------
    début                : 03/04/2018
    copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
*************************************************************************/

//---------- Interface de la classe <Main> (fichier Main.h) ----------------
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
// Main permettant d'appliquer le scénario de l'application. Elle propose tous 
// les services que notre application offre : affichage du top 10 des risques ou du risque de 
// maladie possible, ajouter des données au Dictionnaire, afficher les détails d'une Maladie ou
// l'ensemble des maladies du Dictionnaire.
//------------------------------------------------------------------------

class Main
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	void renseignerDictionnaire(Dictionnaire & d, FichEmpStream * fp);
	// Mode d'emploi :
	// Renseigne des données dans le Dictionnaire d. 
	// Demande à l’utilisateur la source du fichier contenant les données. 
	// fp est le lecteur qui va permettre de lire le fichier et ses données.

	FichierPatient renseignerFichierPatient(FichEmpStream * fp);
	// Mode d'emploi :
	// Renseigne des empreintes à analyser. 
	// Demande à l’utilisateur la source du fichier contenant les données. 
	// fp est le lecteur qui va permettre de lire le fichier et ses données. 
	// Retourne un FichierPatient avec les données à l’intérieur si le fichier 
	// est valide sinon retourne un FichierPatient vide.

	void afficherDetailMaladie(long idMaladie, Dictionnaire d);
	// Mode d'emploi :
	// Affiche la maladie dont l’identifiant dans le dictionnaire d est id.  

	

	void afficherDictionnaire(Dictionnaire d);
	// Mode d'emploi :
	// Affiche toutes les maladies et leurs empreintes contenues dans le Dictionnaire d.
	

	void afficherMeilleurCorresp(Dictionnaire d, FichierPatient fp);
	// Mode d'emploi :
	// Affiche le risque de maladie le plus probable pour chaque empreinte du FichierPatient fp. 
	// Cette analyse est faite par rapport au Dictionnaire d. Si des maladies sont à égalités, 
	// alors elles sont aussi affichées.

	void afficherTop10(Dictionnaire d, FichierPatient fp);
	//Mode d'emploi :
	// Affiche le top 10 des risques de maladie les plus probables pour chaque empreinte du FichierPatient fp. 
	// Cette analyse est faite par rapport au Dictionnaire d. 
	// Si des maladies sont à égalités au niveau de la dizième position, alors elles sont aussi affichées.

	int lireEntree(int min, int max);
	// Récupére un numéro rentré par l'utilisateur et permet de vérifier qu'il 
	// est dans l'intervalle [min,max]. Redemande la saisie tant que celui-ci n'est pas valide.
	// Une fois valide, retourne le numéro rentré.

	multimap<double, string> retrouverResultat(Analyse a, bool meilleure);
	// Mode d'emploi
	// Retourne une multimap contenant les résultats de l’Analyse a à afficher.
	// meilleure est un bool indiquant si on souhaite retrouver le meilleur
	// résultat ou les 10 meilleurs. Dans les deux cas, prend en compte les égalités.
	//
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
