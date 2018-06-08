/*************************************************************************
Attribut  -  description
-------------------
début                : 03/04/2018
copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
*************************************************************************/

//---------- Interface de la classe <Attribut> (fichier Attribut.h) ----------------
#if ! defined ( ATTRIBUT_H )
#define ATTRIBUT_H

//--------------------------------------------------- Interfaces utilis�es
using namespace std;
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Attribut>
// Attribut est un élément élémentaire d'une empreinte. Celui-ci correspond
// à une unique donnée d'une empreinte d'un patient. 
//
//------------------------------------------------------------------------

class Attribut
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	void setValue(void* uneValeur);
	// Mode d'emploi : 
	// Affecte la valeur uneValeur à l'attribut.
	//
	// Contrat :
	//

	void* getValue();
	// Mode d'emploi :
	// Retourne la valeur de l'attribut.
	//
	// Contrat :
	//

	string getType();
	// Mode d'emploi :
	// Retourne une string indiquant le type de l'attribut.
	//
	// Contrat :
	//

	string getNom();
	// Mode d'emploi :
	// Retourne une string indiquant le nom de l'attribut.
	//
	// Contrat :
	//


	//------------------------------------------------- Surcharge d'op�rateurs
	Attribut & operator = (const Attribut & unAttribut);
	// Mode d'emploi :
	// Surcharge de l'operator = permettant d'affecter les différents paramètres
	// de unAttribut à un autre Attribut.
	//
	// Contrat :
	//

	bool operator==(Attribut & a);

	friend ostream &operator<<(ostream & os, Attribut & A);


	//-------------------------------------------- Constructeurs - destructeur
	Attribut(const Attribut & unAttribut);
	// Mode d'emploi (constructeur de copie) :
	// Constructeur de copie d'Attribut.
	//
	// Contrat :
	//

	Attribut(string unNom, string unType);
	// Mode d'emploi (constructeur de copie) :
	// Constructeur d'Attribut.
	//
	// Contrat :
	//

	Attribut();
	// Mode d'emploi :
	// Constructeur par défaut d'Attribut.
	//
	// Contrat :
	//

	virtual ~Attribut();
	// Mode d'emploi :
	// Destructeur d'Attribut.s
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE
private:
	string nom; // Nom de l'Attribut (il est unique, il sert d'identifiant)
	string type; // Type de l'Attribut
	void* value; // Valeur de l'Attribut dont le pointeur sera défini une fois le type renseigné

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

};

//-------------------------------- Autres d�finitions d�pendantes de <Attribut>

#endif // ATTRIBUT_H

