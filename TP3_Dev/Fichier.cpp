/*************************************************************************
                           Fichier  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Fichier> (fichier Fichier.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <utility>

//------------------------------------------------------ Include personnel
#include "Fichier.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Fichier::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

deque<pair<string,string> > Fichier::getSignature()
{
	return signature;
}


//------------------------------------------------- Surcharge d'opérateurs
Fichier & Fichier::operator = ( const Fichier & unFichier )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Fichier::Fichier ( const Fichier & unFichier )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Fichier>" << endl;
#endif
} //----- Fin de Fichier (constructeur de copie)

Fichier::Fichier (string nomFichier, string uneSignature )
{
	nbEmpreintes = 0;
	sourceFichier = nomFichier;
	uneSignature.erase(0,36); //on a toujours les deux première ligne du début qui font la même taille
	int i = 0;
	string nom;
	string type;
	int pos1;
	int pos2;
	while(pos2 <uneSignature.length())
	{
		

		pos1 = uneSignature.find(';',i);
		pos2 = uneSignature.find('\n',i);
		nom = uneSignature.substr(i,pos1-i);//pas de +1 car on prend pas le ;
		type = uneSignature.substr(pos1+1,pos2-pos1-1); //pas de +1 car on prend pas le \n
		signature.push_back(make_pair(nom,type));
		i = pos2+1;


	}
}


Fichier::Fichier ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Fichier>" << endl;
#endif
} //----- Fin de Fichier


Fichier::~Fichier ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Fichier>" << endl;
#endif
} //----- Fin de ~Fichier


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
