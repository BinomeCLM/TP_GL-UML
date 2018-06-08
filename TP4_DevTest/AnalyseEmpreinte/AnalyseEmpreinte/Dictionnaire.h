/*************************************************************************
                           Dictionnaire -  description
                             -------------------
    début                : 03/04/2018
    copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
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
// Représente notre base de données pour faire les analyses. Stocke l'ensemble
// des Maladie et leurs Empreinte. Classe fille de Fichier.
//------------------------------------------------------------------------

class Dictionnaire : public Fichier
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool ajouterMaladie(string chMaladie);
	// Mode d'emploi :
	// ajoute une maladie repéré par chMaladie dans le Dictionnaire. Si le nom
	// de cette maladie existe déjà et posséde une empreinte avec le même identifiant
	// que celle qu'on souhaite ajoutée alors elle n'est pas ajoutée (retourne false). 
	// Sinon retourne true.

    deque<Maladie> getListeMaladie();
	// Mode d'emploi :
	// Retourne listeMaladie, la liste des Maladie de notre dictionnaire 
	// et leurs empreintes correspondantes.

    Maladie getMaladieById(long id);
	// Mode d'emploi :
	// Retourne la maladie qui possède l'identifiant id ainsi que l'ensemble de ses empreintes. 
	// Si la maladie n’existe pas dans le dictionnaire, une Maladie vide (sans empreinte, sans identifiant
	// et sans nom) est retournée.

	long getNbElements();
	// Mode d'emploi :
	// Retourne nbElements, le nombre de maladies que contient le Dictionnaire.

	void setSignature(string signature);
	// Mode d'emploi :
	// Definit la valeur de la signature de la maladie, renseignée par le paramètre signature.

	void setNomFichier(string sourceFich);
	//Mode d'emploi :
	// Definit la valeur de sourceFichier, représentant le nom du fichier dont la
	// base de connaissance tire ses valeurs. En cas d'ajout supplémentaire de données, 
	// le nom du nouveau fichier est ajoutée au précédent (séparé par un '/').


//------------------------------------------------- Surcharge d'opérateurs
  
    friend ostream &operator<<(ostream &os, Dictionnaire & d);
	// Mode d'emploi :
	// Surcharge de l'opérateur << qui permet d'afficher l'ensemble du Dictionnaire.

//-------------------------------------------- Constructeurs - destructeur

    Dictionnaire(string nomFichier, string uneSignature);
	// Mode d'emploi 
	// Constructeur de Dictionnaire

	Dictionnaire();
	// Mode d'emploi :
	// Constructeur par défaut de Dictionnaire

    virtual ~Dictionnaire ( );
    // Mode d'emploi :
    // Destructeur de Dictionnaire

//------------------------------------------------------------------ PRIVE
private :
    deque<Maladie> listeMaladie; // La liste des Maladie du Dictionnaire

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Dictionnaire>

#endif // Dictionnaire_H
