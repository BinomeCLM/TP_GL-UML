/*************************************************************************
Maladie  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Maladie> (fichier Maladie.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string> 

//------------------------------------------------------ Include personnel
#include "Maladie.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Maladie::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool Maladie::ajouterEmpreinte(string chEmp, deque<pair<string,string> > signature ) {
	bool ajoutee;
	/*
	std::string s = "scott>=tiger";
	std::string delimiter = ">=";
	std::string token = s.substr(0, s.find(delimiter));
	*/
	string delimiter = ";";
	Empreinte* e = new Empreinte();
	while (!signature.empty())
	{

		//string monType = signature.front();
		/*switch (c) //C'est quoi c ?
		{
		case 'A':
			capa++;
			break;
		case 'a':
			lettera++;
			break;
		default:
			nota++;
		}*/
		//e->id = stol(chEmp.substr(0, chEmp.find(delimiter)));
	}



	return ajoutee;
}
Empreinte Maladie::getEmpreinteById(long id) {
	Empreinte e;

	return e;
}

string Maladie::getNomMaladie() {
	return nomMaladie;
}
deque<Empreinte> Maladie::getListeEmpreinte() {
	return listeEmpreinte;
}



//------------------------------------------------- Surcharge d'opérateurs
/*Maladie & Maladie::operator = (const Maladie & unMaladie)
// Algorithme :
//
{
} //----- Fin de operator =
*/

  //-------------------------------------------- Constructeurs - destructeur
Maladie::Maladie(const Maladie & unMaladie)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Maladie>" << endl;
#endif
} //----- Fin de Maladie (constructeur de copie)


Maladie::Maladie()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Maladie>" << endl;
#endif
} //----- Fin de Maladie


Maladie::~Maladie()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Maladie>" << endl;
#endif
} //----- Fin de ~Maladie


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

