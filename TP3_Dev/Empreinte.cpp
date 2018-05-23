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

void Empreinte::ajouterAttribut(Attribut * a)
{
	nbAttributs++;
	listeAttributs.push_back(*a);
}

Analyse Empreinte::lancerAnalyse(Dictionnaire d)
{
		Analyse a;
        a.setIdEmpreinte(idEmpreinte);
        a.genererClassement(d,*this);

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

void Empreinte::setIdEmpreinte(long id)
{
    idEmpreinte = id;
}

//------------------------------------------------- Surcharge d'op�rateurs
/*Empreinte & Empreinte::operator = (const Empreinte & unEmpreinte)
// Algorithme :
//
{
} //----- Fin de operator =*/


ostream &operator<<(ostream &os, Empreinte & e)
{
	deque<Attribut> listeAttr = e.getListeAttributs();

	os << "id: " << e.getIdEmpreinte() << " -> ";
    long compteur = 0;
    long nbAttr = e.getNbAttributs();
	for (deque<Attribut>::iterator it=listeAttr.begin(); it!=listeAttr.end(); ++it)
	{
        os << *it;
        compteur++;
        if (compteur != nbAttr)
        {
            os << " / ";
        }

	}
    os << endl;
    /*long i;
    long nbAttr = e.nbAttributs;
    // ATTENTION, on a le nombre d'attributs en attribut d'Empreinte, pas besoin de .size()
	for(i = 0; i < nbAttr-1 ; i++)
	{

	}
	os << listeAttr[nbAttr-1] << endl;
	cout << "fin surcharge << Empreinte" << endl;*/

	return os;
}

  //-------------------------------------------- Constructeurs - destructeur

Empreinte::Empreinte()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Empreinte>" << endl;
#endif
	nbAttributs = 0;
} //----- Fin de Empreinte

Empreinte::Empreinte(long id)
{
	idEmpreinte = id;
	nbAttributs = 0;
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

