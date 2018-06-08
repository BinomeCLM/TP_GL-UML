/*************************************************************************
Empreinte  -  description
-------------------
d�but                : 03/04/2018
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
// R�le de la classe <Empreinte>
//Stock et gère les Empreintes des patients et celles des Maladies.
//------------------------------------------------------------------------

class Empreinte
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	void ajouterAttribut(Attribut * a);
	// Mode d'emploi :
	//Ajoute un attribut a à la liste d’attributs de l’empreinte.
	
	deque<Attribut> getListeAttributs();
	// Mode d'emploi :
	//Retourne listeAttributs


	void setNbAttributs(long nbAttr);
	// Mode d'emploi :
	//Defini la valeure de nbAttributs


	long getNbAttributs();
	// Mode d'emploi :
	//Retourne nbAttributs

	long getIdEmpreinte();
	// Mode d'emploi :
	//Retourne IdEmpreinte

	void setIdEmpreinte(long id);
	// Mode d'emploi :
	//defini la valeur de IdEmpreinte


	Analyse lancerAnalyse(Dictionnaire d);
	// Mode d'emploi :
	//Appelle la méthode ‘genererClassement’ de la classe Analyse pour l’empreinte par rapport au dictionnaire d. 
	//Cette analyse est ensuite retournée.


	//------------------------------------------------- Surcharge d'op�rateur
	friend ostream &operator<<(ostream & os, Empreinte & E);



	//-------------------------------------------- Constructeurs - destructeur

	Empreinte(long id);
	// Mode d'emploi :
	//Constructeur d'Empreinte


	Empreinte();
	// Mode d'emploi :
	//Constructeur par défaut d'Empreinte

	virtual ~Empreinte();
	// Mode d'emploi :
	//Destructeur d'Empreinte

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

private:
	long idEmpreinte;
	long nbAttributs;
	deque<Attribut> listeAttributs;
};

//-------------------------------- Autres d�finitions d�pendantes de <Empreinte>

#endif // Empreinte_H

