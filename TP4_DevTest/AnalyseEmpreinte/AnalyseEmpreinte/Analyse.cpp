/*************************************************************************
                       Analyse -  description
                             -------------------
    début                : 03/04/2018
    copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
*************************************************************************/

//---------- Realisation de la classe <Analyse> (fichier Analyse.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Analyse.h"
#include "Dictionnaire.h"
#include "Empreinte.h"
#include <utility>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

void Analyse::genererClassement(Dictionnaire d, Empreinte e)
{
	deque<Maladie> listeMaladies = d.getListeMaladie();

	for (deque<Maladie>::iterator it=listeMaladies.begin(); it!=listeMaladies.end(); ++it)
	{
		calculerProbabilite(e,*it);
	}
} //----- Fin de genererClassement

void Analyse::calculerProbabilite(Empreinte e, Maladie m)
{
	deque<Empreinte> listeEmp = m.getListeEmpreinte();

	long nbAttrEmp = e.getNbAttributs();

	deque<Attribut> listeAttr = e.getListeAttributs();

	double max = 0;

	for (deque<Empreinte>::iterator it=listeEmp.begin(); it!=listeEmp.end(); ++it)
	{
		// On initialise un compteur pour compter le nombre d'attributs correspondant
		long compteur = 0;

		deque<Attribut> listeAttrEmpMaladie = it->getListeAttributs();
		for (int i=0; i<nbAttrEmp; i++)
        {
			if (listeAttr[i] == listeAttrEmpMaladie[i])
			{
				compteur ++;
			}
		}

		if (compteur > max)
        {
            max = compteur;
        }

	}

    correspondances.insert(pair<double,string>(((max/nbAttrEmp)*100),m.getNomMaladie()));
} //----- Fin de calculerProbabilite

multimap<double,string> Analyse::getCorrespondances()
{
    return correspondances;
} //----- Fin de getCorrespondances

long Analyse::getIdEmpreinte()
{
    return idEmpreinte;
} //----- Fin de getIdEmpreinte

void Analyse::setIdEmpreinte(long id)
{
    idEmpreinte = id;
} //----- Fin de setIdEmpreinte

//-------------------------------------------- Constructeurs - destructeur

Analyse::Analyse(long id)
{
    idEmpreinte = id;
} //----- Fin de Analyse

Analyse::Analyse()
{} //----- Fin de Analyse

Analyse::~Analyse()
{} //----- Fin de ~Analyse


