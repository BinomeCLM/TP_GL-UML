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

// Méthode à revoir
bool Dictionnaire::ajouterMaladie(string chMaladie)
{
	bool existeM = false; //maladie existe ?
	string nom = chMaladie.substr(chMaladie.find_last_of(';')+1,chMaladie.length()-2);
	// Est-ce qu'on est sur que le nom de la maladie sera tjr en dernier ?
	// Par exemple, si dan la signature le nom de la maladie est au milieu
	// il faudrait parcourir la signature, repéré l'index de l'attribut "disease"
	// et à partir de cet index, récupérer le nom de la maladie
	cout << nom << endl;

	for (deque<Maladie>::iterator it=listeMaladie.begin(); it!=listeMaladie.end(); ++it)
	{
		cout << "hey" << endl;
		if((*it).getNomMaladie() == nom)
		{
		    // Tu n'utilises jamais ce booleen par la suite donc je ne comprends pas son utilité
		    // J'aurai plutot mis existeEmpreinte avec si l'empreinte existe deja (prochaine boucle for),
		    // tu mets sa valeur à true et ensuite tu break; Si l'empreinte existe alors tu ne l'ajoutes pas
		    // sinon tu l'ajoutes et augmente le compteur.
			existeM = true;
			// Si la maladie existe, on regarde si l'empreinte existe dans sa liste
			int posD = 0;
			int posF = chMaladie.find(';',posD);
			// id de l'empreinte est unique donc on compare directement avec celle la
			// Deux empreintes ne peuvent pas avoir le meme id et des valeurs différentes pour les 2 attributs ?
			long id  = (long)stold(chMaladie.substr(posD,posF-posD));
			for (deque<Empreinte>::iterator it2=it->getListeEmpreinte().begin(); it2!=it->getListeEmpreinte().end(); ++it2)
			{
				if((*it2).getIdEmpreinte() == id)
				{
					return false;
					// A quoi sert le break vu que tu return false ?
					break;
				}
			}
			(*it).ajouterEmpreinte(chMaladie,signature);
			return true;
			// A quoi sert le break vu que tu return true ?
			break;
		}
	}
	// Partie à faire seulement si l'empreinte n'existe deja pas dans la maladie
	// ou si la maladie n'existe pas, or la avec ton code tu ne prends pas
	// en compte tout les cas
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
