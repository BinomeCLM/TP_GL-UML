/*************************************************************************
Empreinte  -  description
-------------------
début                : 03/04/2018
copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
*************************************************************************/

//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ----------------
#if ! defined ( EMPREINTE_H )
#define EMPREINTE_H

//--------------------------------------------------- Interfaces utilis�es

using namespace std;
#include <deque>
#include <map>

#include "Attribut.h"

class Dictionnaire;
class Analyse;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Empreinte>
// Stocke et gère les Empreintes des patients à analyser et celles des Maladies.
// Une Empreinte est composée d'Attribut se basant sur une signature précise.
//------------------------------------------------------------------------

class Empreinte
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	void ajouterAttribut(Attribut * a);
	// Mode d'emploi :
	// Ajoute un attribut (valeur pointée par a) à la liste d’Attribut de l’empreinte.
	
	deque<Attribut> getListeAttributs();
	// Mode d'emploi :
	// Retourne listeAttributs, la liste des Attribut de l'Empreinte.


	void setNbAttributs(long nbAttr);
	// Mode d'emploi :
	// Definit la valeur de nbAttributs, le nombre d'Attribut que contient 
	// l'Empreinte.


	long getNbAttributs();
	// Mode d'emploi :
	// Retourne nbAttributs, le nombre d'Attribut de l'Empreinte.

	long getIdEmpreinte();
	// Mode d'emploi :
	// Retourne IdEmpreinte, l'identifiant de l'Empreinte.

	void setIdEmpreinte(long id);
	// Mode d'emploi :
	// Definit la valeur de IdEmpreinte, l'identifiant de l'Empreinte.

	Analyse lancerAnalyse(Dictionnaire d);
	// Mode d'emploi :
	// Lance une analyse pour l'Empreinte en comparant celle-ci avec
	// l'ensemble des Maladie du Dictionnaire d.
	// Cette Analyse est ensuite retournée.


	//------------------------------------------------- Surcharge d'op�rateur
	friend ostream &operator<<(ostream & os, Empreinte & E);
	// Mode d'emploi :
	// Surcharge de l'operator << qui permet d'afficher une Empreinte
	// avec son identifiant et l'ensemble de ses Attribut.


	//-------------------------------------------- Constructeurs - destructeur

	Empreinte(long id);
	// Mode d'emploi :
	// Constructeur d'Empreinte


	Empreinte();
	// Mode d'emploi :
	// Constructeur par défaut d'Empreinte

	virtual ~Empreinte();
	// Mode d'emploi :
	// Destructeur d'Empreinte

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

private:
	long idEmpreinte; // identifiant de l'Empreinte
	long nbAttributs; // Nombre d'Attribut de l'Empreinte
	deque<Attribut> listeAttributs; // Liste d'Attribut de l'Empreinte.
};

//-------------------------------- Autres définitions dépendantes de <Empreinte>

#endif // Empreinte_H

