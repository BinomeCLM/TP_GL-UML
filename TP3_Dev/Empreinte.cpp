/*************************************************************************
Empreinte  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>


//------------------------------------------------------ Include personnel
#include "Empreinte.h"



//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Empreinte::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Empreinte::ajouterAttribut(Attribut a)
{
	listeAttributs.push_back(a);

}

Analyse Empreinte::lancerAnalyse(Dictionnaire d)
{
		Analyse a = new Analyse();

		a.genererClassement(d,this);

		return a;
}

deque<Attribut> Empreinte::getListeAttributs()
{
	return listeAttributs;
}

long Empreinte::getNbAttributs()
{
	return nbAttributs;
}

void Empreinte::setNbAttributs(long nbAttr)
{
	nbAttributs = nbAttr;
}

long Empreinte::getIdEmpreinte()
{
	return idEmpreinte;
}

//------------------------------------------------- Surcharge d'opérateurs
/*Empreinte & Empreinte::operator = (const Empreinte & unEmpreinte)
// Algorithme :
//
{
} //----- Fin de operator =*/


  //-------------------------------------------- Constructeurs - destructeur

Empreinte::Empreinte()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Empreinte>" << endl;
#endif
} //----- Fin de Empreinte

Empreinte::Empreinte(long id)
{
		idEmpreinte = id;
}

Empreinte::~Empreinte()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Empreinte>" << endl;
#endif
} //----- Fin de ~Empreinte


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

