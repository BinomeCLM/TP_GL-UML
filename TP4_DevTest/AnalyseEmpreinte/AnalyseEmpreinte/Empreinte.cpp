/*************************************************************************
					   Empreinte  -  description
                             -------------------
    début                : 03/04/2018
    copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
*************************************************************************/

//---------- Réalisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------

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
} //----- Fin de ajouterAttribut

Analyse Empreinte::lancerAnalyse(Dictionnaire d)
{
		Analyse a;
        a.setIdEmpreinte(idEmpreinte);
        a.genererClassement(d,*this);

        return a;
} //----- Fin de lancerAnalyse

deque<Attribut> Empreinte::getListeAttributs()
{
	return listeAttributs;
} //----- Fin de getListeAttributs

long Empreinte::getNbAttributs()
{
	return nbAttributs;
} //----- Fin de getNbAttributs

void Empreinte::setNbAttributs(long nbAttr)
{
	nbAttributs = nbAttr;
} //----- Fin de setNbAttributs

long Empreinte::getIdEmpreinte()
{
	return idEmpreinte;
} //----- Fin de getIdEmpreinte

void Empreinte::setIdEmpreinte(long id)
{
    idEmpreinte = id;
} //----- Fin de setIdEmpreinte

//------------------------------------------------- Surcharge d'operateurs

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

	return os;
} //----- Fin de operator<<

//-------------------------------------------- Constructeurs - destructeur

Empreinte::Empreinte()
{
	nbAttributs = 0;
} //----- Fin de Empreinte

Empreinte::Empreinte(long id)
{
	idEmpreinte = id;
	nbAttributs = 0;
} //----- Fin de Empreinte

Empreinte::~Empreinte()
{} //----- Fin de ~Empreinte


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes protégées

