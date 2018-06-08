/*************************************************************************
Analyse  -  description
-------------------
d�but                : 03/04/2018
copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
*************************************************************************/

//---------- R�alisation de la classe <Analyse> (fichier Analyse.cpp) ------------

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
// type Analyse::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


void Analyse::genererClassement(Dictionnaire d, Empreinte e)
{
	deque<Maladie> listeMaladies = d.getListeMaladie();

    // Pour chaque maladie du dictionnaire, on calcule la proba associee
    // avec l'empreinte a analyser
	for (deque<Maladie>::iterator it=listeMaladies.begin(); it!=listeMaladies.end(); ++it)
	{
		calculerProbabilite(e,*it);
	}
}

void Analyse::calculerProbabilite(Empreinte e, Maladie m)
// Algorithme :
//Soit ‘a’ le nombre d’attributs identiques et ‘n’ le nombre d’attributs total.
//La probabilité calculée est égale à : (a / n)*100.
{
	// On recupere les empreintes ou l'empreinte de la maladie
	deque<Empreinte> listeEmp = m.getListeEmpreinte();

	// On recupere dans une var le nombre d'attributs pour faire la moyenne
	long nbAttrEmp = e.getNbAttributs();

	//On recupere une seule fois la liste des attributs de l'empreinte qu'on analyse
	deque<Attribut> listeAttr = e.getListeAttributs();

	double max = 0;

	// Pour chaque empreinte, on calcule la probabilite associee
	for (deque<Empreinte>::iterator it=listeEmp.begin(); it!=listeEmp.end(); ++it)
	{
		// On initie un compteur pour compter le nbre d'attributs correspondant
		long compteur = 0;


		// On recupere la liste des attributs de l'empreinte de la maladie
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
	// On ajoute a la multimap en mettant le nom de la maladie et la proba en cle
    correspondances.insert(pair<double,string>(((max/nbAttrEmp)*100),m.getNomMaladie()));
}

multimap<double,string> Analyse::getCorrespondances()
{
    return correspondances;
}

long Analyse::getIdEmpreinte()
{
    return idEmpreinte;
}

void Analyse::setIdEmpreinte(long id)
{
    idEmpreinte = id;
}



//-------------------------------------------- Constructeurs - destructeur


Analyse::Analyse(long id)
{
    idEmpreinte = id;
}

Analyse::Analyse()
{

}


Analyse::~Analyse()
{

}


