/*************************************************************************
Attribut  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Attribut> (fichier Attribut.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Attribut.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
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

} //----- Fin de Méthode

void* Attribut::getValue()
{
	return value;
}

string Attribut::getType()
{
	return type;
}


//------------------------------------------------- Surcharge d'opérateurs
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


bool Attribut::operator==(Attribut & a)
{
	#ifdef MAP
	cout << "Appel de ==" << endl;
#endif

//if ((type == "double" && *(double*)value == *(double*)unAttribut.value)
//|| (type == "string" && 0==strcmp((string*)value , *(string*)unAttribut.value)))
	
	if (getType() == "string" && (*(string*)a.getValue() == *(string*)getValue()))
	{
		cout << *(double*)a.getValue() << " " << *(double*)getValue() << endl;
		return true;
	} else if (a.getType() == "double" && (*(double*)a.getValue() ==  *(double*)getValue())) {
		cout << *(double*)a.getValue() << " " << *(double*)getValue() << endl;		
		return true;
	}
	else {
		cout << *(double*)a.getValue() << " " << *(double*)getValue() << endl;	
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
	} else if(unType == "string") {
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
	if(type == "double")
	{
		delete (double*)value;
	} else if (type == "string") {
		delete (string*)value;
	}
	
} //----- Fin de ~Attribut


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

