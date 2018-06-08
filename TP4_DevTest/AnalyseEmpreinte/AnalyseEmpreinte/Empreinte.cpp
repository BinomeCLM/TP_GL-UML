/*************************************************************************
Empreinte  -  description
-------------------
d�but                : 03/04/2018
copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
*************************************************************************/

//---------- R�alisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>


//------------------------------------------------------ Include personnel
#include "Empreinte.h"
#include "Dictionnaire.h"
#include "Analyse.h"



//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques
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

ostream &operator<<(ostream &os, Empreinte & e)
{
	deque<Attribut> listeAttr = e.getListeAttributs();

	os << "id: " << e.getIdEmpreinte() << " -> ";
    long compteur = 0;
    long nbAttr = e.getNbAttributs();
	//On affiche tous les attributs 
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

	return os;
}

  //-------------------------------------------- Constructeurs - destructeur

Empreinte::Empreinte()
// Algorithme :
//
{
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

} //----- Fin de ~Empreinte


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

