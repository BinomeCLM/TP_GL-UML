/*************************************************************************
Attribut  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <Attribut> (fichier Attribut.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Attribut.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
void Attribut::setValue(void* uneValeur)
// Algorithme :
//
{
	if (type == "double")
	{
		//value = new double ();
		*(double*)value = *(double*)uneValeur;
	}
	else if (type == "string") {
		//value = new string();
		*(string*)value = *(string*)uneValeur;
	}
	//delete [] uneValeur;

} //----- Fin de M�thode

void* Attribut::getValue()
{
	return value;
}

string Attribut::getType()
{
	return type;
}

string Attribut::getNom()
{
    return nom;
}


//------------------------------------------------- Surcharge d'op�rateurs
/*Attribut & Attribut::operator = (const Attribut & unAttribut)
// Algorithme :
//
{
} //----- Fin de operator =*/

/*bool Attribut::estEgal(Attribut & a)
{
	if (a.getType() == "string" && *(string*)a.getValue() == *(string*)value)
	{
		return true;
	}
	else if (a.getType() == "double" && *(double*)a.getValue() == *(double*)value) {
		return true;
	}
	else {
		return false;
	}


}*/

ostream &operator<<(ostream & os, Attribut & A)
{
	if(A.getType() == "double")
	{
		os << *(double*)A.getValue();

	} else if (A.getType() == "string")
	{
		os << *(string*)A.getValue();
	}
    // Soit on met else tout seul soit on laisse comme ça et on met un else avec un msg d'erreur
	return os;
}



bool Attribut::operator==(Attribut & a)
{
	#ifdef MAP
	cout << "Appel de ==" << endl;
#endif

//if ((type == "double" && *(double*)value == *(double*)unAttribut.value)
//|| (type == "string" && 0==strcmp((string*)value , *(string*)unAttribut.value)))

	if (getType() == "string" && (*(string*)a.getValue() == *(string*)getValue()))
	{
		cout << *(string*)a.getValue() << " " << *(string*)getValue() << endl;
		return true;
	}
	else if (a.getType() == "double" && (*(double*)a.getValue() ==  *(double*)getValue()))
    {
		cout << *(double*)a.getValue() << " " << *(double*)getValue() << endl;
		return true;
	}
	// A revoir
	else
	{
	    cerr << "Les deux attributs n'ont pas le même type." << endl;
		return false;
	}
}



  //-------------------------------------------- Constructeurs - destructeur
/*Attribut::Attribut(const Attribut & unAttribut)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Attribut>" << endl;
#endif
} //----- Fin de Attribut (constructeur de copie)*/

Attribut::Attribut(string unNom, string unType)
{
#ifdef MAP
	cout << "Appel au constructeur de  <Attribut>" << endl;
#endif
	nom = unNom;
	type = unType;
	if (unType == "double")
	{
		value = new double();
	}
	else if(unType == "string")
    {
		value = new string();
	}

}

Attribut::Attribut()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Attribut>" << endl;
#endif
} //----- Fin de Attribut


Attribut::~Attribut()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Attribut>" << endl;
#endif
	/*if(type == "double")
	{
		delete (double*)value;
	}
	else if (type == "string")
    {
		delete (string*)value;
	}
*/
} //----- Fin de ~Attribut


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

