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
bool Dictionnaire::ajouterMaladie(string chEmpMaladie)
{
	string nom = chEmpMaladie.substr(chEmpMaladie.find_last_of(';')+1);
	cout << nom << endl;

	for (deque<Maladie>::iterator it=listeMaladie.begin(); it!=listeMaladie.end(); ++it)
	{
		if((*it).getNomMaladie() == nom)
		{
		    // Tu n'utilises jamais ce booleen par la suite donc je ne comprends pas son utilité
		    // J'aurai plutot mis existeEmpreinte avec si l'empreinte existe deja (prochaine boucle for),
		    // tu mets sa valeur à true et ensuite tu break; Si l'empreinte existe alors tu ne l'ajoutes pas
		    // sinon tu l'ajoutes et augmente le compteur.
			bool existeEmp = false;
			// Si la maladie existe, on regarde si l'empreinte existe dans sa liste
			int posD = 0;
			int posF = chEmpMaladie.find(';',posD);
			// id de l'empreinte est unique donc on compare directement avec celle la
			long id  = (long)stold(chEmpMaladie.substr(posD,posF-posD));
			deque<Empreinte> listeEmp = it->getListeEmpreinte();
			for (deque<Empreinte>::iterator it2=listeEmp.begin(); it2!=listeEmp.end(); ++it2)
			{
				if((*it2).getIdEmpreinte() == id)
				{
					existeEmp = true;
				}
			}
			if (!existeEmp)
            {
                it->ajouterEmpreinte(chEmpMaladie,signature);
                nbEmpreintes++;
                return true;
            }
            else
            {
                return false;
            }
		}
	}
	nbEmpreintes++;
	Maladie * m = new Maladie(nbEmpreintes,nom);
	m->ajouterEmpreinte(chEmpMaladie,signature);
	listeMaladie.push_back(*m);
	return true;
}

deque<Maladie> Dictionnaire::getListeMaladie()
{
    return listeMaladie;
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
