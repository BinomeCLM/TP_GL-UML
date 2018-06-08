/*************************************************************************
						Maladie  -  description
-------------------
début                : 03/04/2018
copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
*************************************************************************/

//---------- R�alisation de la classe <Maladie> (fichier Maladie.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Maladie.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool Maladie::ajouterEmpreinte(string chEmp, deque<pair<string,string> > signature ) 
{
	bool ajoutee;

	char delimiter = ';';
	string attribut;

	int posD = 0;
	int posF = chEmp.find(delimiter,posD);
	long id  = (long)stold(chEmp.substr(posD,posF-posD)); 
    Empreinte* e = new Empreinte();
    if(!empreinteExiste(id))
	{
	    e->setIdEmpreinte(id);
		posD = posF+1;

		int fin = chEmp.find_last_of(delimiter);
		int i = 0;

		while(posF != fin)
		{
			void* val;
			posF = chEmp.find(delimiter,posD);
			attribut  = chEmp.substr(posD,posF-posD);

			Attribut* A = new Attribut(signature[i].first,signature[i].second);

			if(A->getType() == "double")
			{
				val = new double(stod(attribut));
				A->setValue(val);
				delete (double*)val;

			}
			else if(A->getType() == "string")
			{
				val =  new string(attribut);
				A->setValue(val);
				delete (string*)val;
			}

			e->ajouterAttribut(A);
			delete A;

			posD = posF+1;

			i++;
		}
		ajoutee = true;
		listeEmpreinte.push_back(*e);
		nbEmpreinte++;
	}
	else
    {
		ajoutee = false;
	}

	delete e;

	return ajoutee;
} //----- Fin de ajouterEmpreinte

Empreinte Maladie::getEmpreinteById(long id) 
{
	Empreinte e;

	deque<Empreinte>::iterator it;

	for (it=listeEmpreinte.begin(); it!=listeEmpreinte.end(); ++it)
	{
		if(id == (*it).getIdEmpreinte())
		{
			return *it;
		}
	}

	return e;
} //----- Fin de getEmpreinteById

bool Maladie::empreinteExiste(long id) 
{

	deque<Empreinte>::iterator it;

	for (it=listeEmpreinte.begin(); it!=listeEmpreinte.end(); ++it)
	{
		if(id == (*it).getIdEmpreinte())
		{
			return true;
		}
	}

	return false;
} //----- Fin de empreinteExiste

string Maladie::getNomMaladie() 
{
	return nomMaladie;
} //----- Fin de getNomMaladie

deque<Empreinte> Maladie::getListeEmpreinte()
{
	return listeEmpreinte;
} //----- Fin de getListeEmpreinte

long Maladie::getIdMaladie()
{
    return idMaladie;
} //----- Fin de getIdMaladie

//------------------------------------------------- Surcharge d'operateurs

ostream &operator<<(ostream &os, Maladie & m)
{
    deque<Empreinte> listeEmpMaladie = m.getListeEmpreinte();
    long nbEmp = m.nbEmpreinte;
	os << "idMaladie: " << m.idMaladie << "; Nom Maladie : " << m.nomMaladie << "; Nombre d'Empreintes : " << nbEmp << endl;

    for (deque<Empreinte>::iterator it=listeEmpMaladie.begin(); it!=listeEmpMaladie.end(); ++it)
    {
        os << *it << endl;
    }
    return os;
} //----- Fin de operator<<

//-------------------------------------------- Constructeurs - destructeur

Maladie::Maladie()
{} //----- Fin de Maladie 

Maladie::Maladie(long id, string nom)
{
	idMaladie = id;
	nomMaladie = nom;
	nbEmpreinte = 0; 
} //----- Fin de Maladie


Maladie::~Maladie()
{} //----- Fin de ~Maladie 


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

