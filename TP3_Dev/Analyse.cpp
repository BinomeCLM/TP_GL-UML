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
void Analyse::genererClassement(Fichier d, Empreinte e)
{
	deque<Maladie> listeMaladies = d.getListeMaladie();

    // Pour chaque maladie du dictionnaire, on calcule la proba associ�e
    // avec l'empreinte � analyser
	for (std::deque<Maladie>::iterator it=listeMaladies.begin(); it!=listeMaladies.end(); ++it)
	{
		std::cout << *it << '\n';
		calculerProbabilit�(e,*it);
	}
}

// M�thode non v�rifi�e --> Test unitaire � r�alis�
void Analyse::calculerProbabilit�(Empreinte e, Maladie m)
{
	// On r�cup�re les empreintes ou l'empreinte de la maladie
	deque<Empreinte> listeEmp = m.getListeEmpreinte();

	// On r�cup�re dans une var le nombre d'attributs pour faire la moyenne
	long nbAttrEmp = e.getNbAttribut();

	//On r�cup�re une seule fois la liste des attributs de l'empreinte qu'on analyse
	deque<Attribut> listeAttr = e.getListeAttributs();

	// Pour chq empreinte, on calcule la probabilit� associ�e
	for (deque<Empreinte>::iterator it=listeEmp.begin(); it!=listeEmp.end(); ++it)
	{
		std::cout << *it << '\n';

		// On init un compteur pour compter le nbre d'attributs correspondant
		long compteur = 0;

		// On compare les attributs des deux empreintes

		// On r�cup�re la liste des attributs de l'empreinte de la maladie
		deque<Attribut> listeAttrEmpMaladie = *it.getListeAttributs();
		for (int i=0; i<nbAttribtus; i++)
        {
			if (listeAttr[i] == listeAttrEmpMaladie[i])
			{
				compteur ++;
			}
		}

		correspondances.insert(pair<double,string>((compteur/nbAttributs),m.nomMaladie) );
		// On ajoute a la multimap en mettant le nom de la maladie et la proba en cl�
	}
}

//------------------------------------------------- Surcharge d'op�rateurs
/*Analyse & Analyse::operator = (const Analyse & unAnalyse)
// Algorithme :
//
{
} //----- Fin de operator = */


  //-------------------------------------------- Constructeurs - destructeur
Analyse::Analyse(const Analyse & unAnalyse)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Analyse>" << endl;
#endif
} //----- Fin de Analyse (constructeur de copie)

Analyse::Analyse(Long id)
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

