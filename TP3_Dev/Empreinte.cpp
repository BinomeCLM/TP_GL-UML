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

/*Analyse Empreinte::lancerAnalyse(Dictionnaire d) 
{
	// On r�cup�re la liste des empreintes � analyser du Fichier Patient
	deque<Empreinte> listeEmp = d.getListeEmpreinte();

	for (deque<Empreinte>::iterator it=listeEmp.begin(); it!=listeEmp.end(); ++it)
	{
		std::cout << *it << '\n';
		Analyse a = new Analyse();

		a.genererClassement(d,e);

		return a;
	}
}*/

deque<Attribut> Empreinte::getListeAttributs() 
{
	return listeAttributs;
}

long Empreinte::getnbAttributs()
{
	return nbAttributs;
}

void Empreinte::setNbAttributs(long nbAttr)
{
	nbAttributs = nbAttr;
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

