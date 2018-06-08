/*************************************************************************
					   Dictionnaire  -  description
                             -------------------
    début                : 03/04/2018
    copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
*************************************************************************/

//---------- Réalisation de la classe <Dictionnaire> (fichier Dictionnaire.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <utility>

//------------------------------------------------------ Include personnel
#include "Dictionnaire.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool Dictionnaire::ajouterMaladie(string chEmpMaladie)
{
	string nom = chEmpMaladie.substr(chEmpMaladie.find_last_of(';')+1);
	for (deque<Maladie>::iterator it=listeMaladie.begin(); it!=listeMaladie.end(); ++it)
	{
		string nomMaladie = (*it).getNomMaladie();
		if(!(nomMaladie.compare(nom)))
		{
		  
			bool existeEmp = false;
			int posD = 0;
			int posF = chEmpMaladie.find(';',posD);
			long id  = (long)stold(chEmpMaladie.substr(posD,posF-posD));
			deque<Empreinte> listeEmp = it->getListeEmpreinte();
			
			for (deque<Empreinte>::iterator it2=listeEmp.begin(); it2!=listeEmp.end(); ++it2)
			{
				// Si la maladie existe déjà, on regarde si l’identifiant de l’empreinte 
				// donnée pour cette maladie est déjà répertoriée. 
				if((*it2).getIdEmpreinte() == id)
				{
					existeEmp = true;
				}
			}
			// Si ce n’est pas le cas, on ajoute cette empreinte à la liste des empreintes de la maladie.
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
	
	delete m;
	
	return true;
} //----- Fin de ajouterMaladie

deque<Maladie> Dictionnaire::getListeMaladie()
{
    return listeMaladie;
} //----- Fin de getListeMaladie

long Dictionnaire::getNbElements()
{
	return nbEmpreintes;
} //----- Fin de etNbElements


void Dictionnaire::setSignature(string uneSignature)
{
	int i = 0;
	string nom;
	string type;

	unsigned int pos1=0;
	unsigned int pos2 =0;
	unsigned int fin = uneSignature.find_last_of(';');

	while(pos1 != fin)
	{
		// On sait que 'double' ou 'string' ont 6 caractères chacun d'où le fait qu'après le ; on prend
		// 6 caractères à chaque fois pour rcupérer le type. (pos2=pos1+6)
		pos1 = uneSignature.find(';',i);
		pos2 = pos1+6;
		nom = uneSignature.substr(i,pos1-i);
		type = uneSignature.substr(pos1+1,pos2-pos1);
		signature.push_back(make_pair(nom,type));
		i = pos2+1;
	}
	
	signature.pop_back();
} //----- Fin de setSignature

void Dictionnaire::setNomFichier(string sourceFich)
{
	if (sourceFich.compare(""))
	{
		sourceFichier = sourceFichier + " / " + sourceFich;
	}
	else
	{
		sourceFichier = sourceFich;
	}
} //----- Fin de setNomFichier

Maladie Dictionnaire::getMaladieById(long id)
{
	Maladie m;
	deque<Maladie>::iterator it;

	for (it=listeMaladie.begin(); it!=listeMaladie.end(); it++)
	{
		if(id == (*it).getIdMaladie())
		{
			return *it;
		}
	}
	return m;
} //----- Fin de getMaladieById

//------------------------------------------------- Surcharge d'operateurs

ostream &operator<<(ostream &os, Dictionnaire & d)
{
	deque<Maladie> listeMaladie = d.getListeMaladie();
    os << "Affichage des " << d.getNbElements() << " maladies du dictionnaire " << endl;

    for (deque<Maladie>::iterator it=d.listeMaladie.begin(); it!=d.listeMaladie.end(); ++it)
    {
        os << *it << endl;
    }

    return os;
} //----- Fin de operator<<

//-------------------------------------------- Constructeurs - destructeur

Dictionnaire::Dictionnaire ( ) : Fichier::Fichier()
{} //----- Fin de Dictionnaire

Dictionnaire::Dictionnaire(string nomFichier, string uneSignature) : Fichier::Fichier(nomFichier, uneSignature )
{
	signature.pop_back();
} //----- Fin de Dictionnaire


Dictionnaire::~Dictionnaire ( )
{} //----- Fin de Dictionnaire

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
