/*************************************************************************
                           Fichier  -  description
                             -------------------
    d�but                : 03/04/2018
    copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
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


string Fichier::getNomFichier()
{
	return sourceFichier;
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


Fichier::Fichier (string nomFichier, string uneSignature)
{

	nbEmpreintes = 0;
	sourceFichier = nomFichier;

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
	}
}

Fichier::Fichier ( )
// Algorithme :
//
{
    nbEmpreintes = 0;
	sourceFichier = "";
} //----- Fin de Fichier

Fichier::~Fichier ( )
// Algorithme :
//
{

} //----- Fin de ~Fichier


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
