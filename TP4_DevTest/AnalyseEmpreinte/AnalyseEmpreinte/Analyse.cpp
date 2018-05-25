/*************************************************************************
Analyse  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
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

// M�thode non v�rifi�e --> Test unitaire � faire
// une fois calculerProbabilit� valid�e
void Analyse::genererClassement(Dictionnaire d, Empreinte e)
{
	//////////////////Rajouter set id
	deque<Maladie> listeMaladies = d.getListeMaladie();

    // Pour chaque maladie du dictionnaire, on calcule la proba associ�e
    // avec l'empreinte � analyser
	for (deque<Maladie>::iterator it=listeMaladies.begin(); it!=listeMaladies.end(); ++it)
	{
		calculerProbabilite(e,*it);
	}
}

// M�thode non v�rifi�e --> Test unitaire � r�alis�
void Analyse::calculerProbabilite(Empreinte e, Maladie m)
{
	// On r�cup�re les empreintes ou l'empreinte de la maladie
	deque<Empreinte> listeEmp = m.getListeEmpreinte();

	// On r�cup�re dans une var le nombre d'attributs pour faire la moyenne
	long nbAttrEmp = e.getNbAttributs();

	//On r�cup�re une seule fois la liste des attributs de l'empreinte qu'on analyse
	deque<Attribut> listeAttr = e.getListeAttributs();

	double max = 0;

	// Pour chq empreinte, on calcule la probabilit� associ�e
	for (deque<Empreinte>::iterator it=listeEmp.begin(); it!=listeEmp.end(); ++it)
	{
		// On init un compteur pour compter le nbre d'attributs correspondant
		long compteur = 0;

		// On compare les attributs des deux empreintes

		// On r�cup�re la liste des attributs de l'empreinte de la maladie
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
		// On ajoute a la multimap en mettant le nom de la maladie et la proba en cl�
	}
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
//------------------------------------------------- Surcharge d'op�rateurs
/*Analyse & Analyse::operator = (const Analyse & unAnalyse)
// Algorithme :
//
{
} //----- Fin de operator = */


  //-------------------------------------------- Constructeurs - destructeur
/*Analyse::Analyse(const Analyse & unAnalyse)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Analyse>" << endl;
#endif
} *///----- Fin de Analyse (constructeur de copie)

Analyse::Analyse(long id)
{
    idEmpreinte = id;
}

Analyse::Analyse()
// Algorithme :
//
{

#ifdef MAP
	cout << "Appel au constructeur de <Analyse>" << endl;
#endif
} //----- Fin de Analyse


Analyse::~Analyse()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Analyse>" << endl;
#endif
} //----- Fin de ~Analyse


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

