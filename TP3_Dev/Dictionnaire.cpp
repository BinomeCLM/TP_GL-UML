/*************************************************************************
                           Dictionnaire  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Dictionnaire> (fichier Dictionnaire.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Dictionnaire.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Dictionnaire::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool Dictionnaire::ajouterMaladie(string chMaladie)
{
	bool existeM = false;; //maladie existe ?
	string nom = chMaladie.substr(chMaladie.find_last_of(';')+1,chMaladie.length()-2);
	cout << nom << endl;
	
	for (deque<Maladie>::iterator it=listeMaladie.begin(); it!=listeMaladie.end(); ++it)
	{
		cout << "hey" << endl;
		if((*it).getNomMaladie() == nom)
		{
			existeM = true;
			int posD = 0;
			int posF = chMaladie.find(';',posD);
			long id  = (long)stold(chMaladie.substr(posD,posF-posD));
			for (deque<Empreinte>::iterator it2=it->getListeEmpreinte().begin(); it2!=it->getListeEmpreinte().end(); ++it2)
			{
				if((*it2).getIdEmpreinte() == id)
				{
					return false;
					break;
				}
			}
			(*it).ajouterEmpreinte(chMaladie,signature);
			return true;
			break;
		}
	}
	nbEmpreintes++;
	Maladie * m = new Maladie(nbEmpreintes,nom);
	m->ajouterEmpreinte(chMaladie,signature);
	listeMaladie.push_back(*m);

	return true;


}


//------------------------------------------------- Surcharge d'opérateurs
/*Dictionnaire & Dictionnaire::operator = ( const Dictionnaire & unDictionnaire )
// Algorithme :
//
{
} //----- Fin de operator = */


//-------------------------------------------- Constructeurs - destructeur
/*Dictionnaire::Dictionnaire ( const Dictionnaire & unDictionnaire )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Dictionnaire>" << endl;
#endif
} //----- Fin de Dictionnaire (constructeur de copie) */


Dictionnaire::Dictionnaire ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Dictionnaire>" << endl;
#endif
} //----- Fin de Dictionnaire

Dictionnaire::Dictionnaire(string nomFichier, string uneSignature) : Fichier::Fichier(nomFichier, uneSignature ){}


Dictionnaire::~Dictionnaire ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Dictionnaire>" << endl;
#endif
} //----- Fin de ~Dictionnaire


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
