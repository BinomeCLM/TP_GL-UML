/*************************************************************************
Attribut  -  description
-------------------
d�but                : 03/04/2018
copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
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
	
		*(double*)value = *(double*)uneValeur;
	}
	else if (type == "string") {
		*(string*)value = *(string*)uneValeur;
	}
	

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
Attribut& Attribut::operator=(const Attribut & unAttribut)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel à l'opérateur d'assignement de <Attribut>" << endl;
#endif
	nom = unAttribut.nom;
	type = unAttribut.type;
	if (type == "double")
	{
		value = new double(*(double*)(unAttribut.value));
	}
	else if (type == "string")
	{
		void * s = unAttribut.value;
		value = new string(*(string*)s);
	}

	return *this;
} //----- Fin de operator =*/



ostream &operator<<(ostream & os, Attribut & A)
{
	if(A.getType() == "double")
	{
		os << *(double*)A.getValue();

	} else if (A.getType() == "string")
	{
		os << *(string*)A.getValue();
	}
	return os;
}



bool Attribut::operator==(Attribut & a)
{
	#ifdef MAP
	cout << "Appel de ==" << endl;
#endif



	if (getType() == "string" && (*(string*)a.getValue() == *(string*)getValue()))
	{
		return true;
	}
	else if (a.getType() == "double" && (*(double*)a.getValue() ==  *(double*)getValue()))
    {
		return true;
	}
	else
	{
		return false;
	}
}



  //-------------------------------------------- Constructeurs - destructeur
Attribut::Attribut(const Attribut & unAttribut)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Attribut>" << endl;
#endif
	nom = unAttribut.nom;
	type = unAttribut.type;
    if (type == "double")
    {
        value = new double(*(double*)(unAttribut.value));
    }
    else if(type == "string")
    {
        value = new string(*(string*)(unAttribut.value));
    }

} //----- Fin de Attribut (constructeur de copie)

Attribut::Attribut(string unNom, string unType)
{
#ifdef MAP
	cout << "Appel au constructeur de  <Attribut>" << endl;
#endif
	nom = unNom;
	type = unType;
	if (unType == "double")
	{
		value = new double;
	}
	else if(unType == "string")
    {
		value = new string;
	}

}

Attribut::Attribut()
// Algorithme :
//
{

} //----- Fin de Attribut


Attribut::~Attribut()
// Algorithme :
//
{

	if(type == "double")
	{
		delete (double*)value;
	}
	else if (type == "string")
    {
		delete (string*)value;
	}

} //----- Fin de ~Attribut


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

