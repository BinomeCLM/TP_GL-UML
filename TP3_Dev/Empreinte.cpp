/*************************************************************************
Empreinte  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>


//------------------------------------------------------ Include personnel
#include "Empreinte.h"
#include "Dictionnaire.h"
#include "Analyse.h"



//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type Empreinte::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

void Empreinte::ajouterAttribut(Attribut a)
{
	listeAttributs.push_back(a);

}

Analyse Empreinte::lancerAnalyse(Dictionnaire d)
{
		Analyse * a = new Analyse(idEmpreinte);

        a->genererClassement(d,*this);

        return *a;
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

//------------------------------------------------- Surcharge d'op�rateurs
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

  //----------------------------------------------------- M�thodes prot�g�es

