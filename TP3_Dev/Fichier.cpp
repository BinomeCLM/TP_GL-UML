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

void Fichier::setNomFichier(string laSourceFichier)
{
	sourceFichier = laSourceFichier;
}

void Fichier::setSignature(string uneSignature)
{
	int i = 0;
	string nom;
	string type;

	unsigned int pos1=0;
	unsigned int pos2 =0;
	unsigned int fin = uneSignature.find_last_of(';');

	while(pos1 != fin)
	{
		// On sait que double ou string ont 6 caractères chacun d'où le fait qu'après le ; on prend
		// 6 caractères à chaque fois. (pos2=pos1+6)
		pos1 = uneSignature.find(';',i);
		pos2 = pos1+6;
		nom = uneSignature.substr(i,pos1-i);//pas de +1 car on prend pas le ;
		type = uneSignature.substr(pos1+1,pos2-pos1); //pas de +1 car on prend pas le \n
		signature.push_back(make_pair(nom,type));
		i = pos2+1;
		cout << nom << " " << type << endl;
	}
}


//------------------------------------------------- Surcharge d'opérateurs
/*Fichier & Fichier::operator = ( const Fichier & unFichier )
// Algorithme :
//
{
} *///----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/*Fichier::Fichier ( const Fichier & unFichier )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Fichier>" << endl;
#endif
}*/ //----- Fin de Fichier (constructeur de copie)

Fichier::Fichier (string nomFichier, string uneSignature)
{

	nbEmpreintes = 0;
	sourceFichier = nomFichier;


	//uneSignature.erase(0,36); //on a toujours les deux première ligne du début qui font la même taille

	int i = 0;
	string nom;
	string type;

	unsigned int pos1=0;
	unsigned int pos2 =0;
	unsigned int fin = uneSignature.find_last_of(';');

	while(pos1 != fin)
	{
		// On sait que double ou string ont 6 caractères chacun d'où le fait qu'après le ; on prend
		// 6 caractères à chaque fois. (pos2=pos1+6)
		pos1 = uneSignature.find(';',i);
		pos2 = pos1+6;
		nom = uneSignature.substr(i,pos1-i);//pas de +1 car on prend pas le ;
		type = uneSignature.substr(pos1+1,pos2-pos1); //pas de +1 car on prend pas le \n
		signature.push_back(make_pair(nom,type));
		i = pos2+1;
		cout << nom << " " << type << endl;
	}
}

Fichier::Fichier ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Fichier>" << endl;
#endif
    nbEmpreintes = 0;
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
