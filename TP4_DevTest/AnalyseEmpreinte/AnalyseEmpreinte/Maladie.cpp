/*************************************************************************
Maladie  -  description
-------------------
d�but                : 03/04/2018
copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
*************************************************************************/

//---------- R�alisation de la classe <Maladie> (fichier Maladie.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Maladie.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
bool Maladie::ajouterEmpreinte(string chEmp, deque<pair<string,string> > signature ) {

	bool ajoutee;

	char delimiter = ';'; //les attributs sont séparés par un ';'
	string attribut;

	int posD = 0; //début de l'attribut
	int posF = chEmp.find(delimiter,posD); //fin de l'attribut
	long id  = (long)stold(chEmp.substr(posD,posF-posD)); //premier attribut = id
    Empreinte* e = new Empreinte();
    if(!empreinteExiste(id)) //si la maladie ne possède pas déjà cette empreinte
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

			//selon le type on défini la valeur de l'attribut
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
}

Empreinte Maladie::getEmpreinteById(long id) {
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
}

bool Maladie::empreinteExiste(long id) {

	deque<Empreinte>::iterator it;

	for (it=listeEmpreinte.begin(); it!=listeEmpreinte.end(); ++it)
	{
		if(id == (*it).getIdEmpreinte())
		{
			return true;
		}
	}

	return false;
}

string Maladie::getNomMaladie() {
	return nomMaladie;
}

deque<Empreinte> Maladie::getListeEmpreinte() {
	return listeEmpreinte;
}

long Maladie::getIdMaladie()
{
    return idMaladie;
}

ostream &operator<<(ostream &os, Maladie & m)
{
    deque<Empreinte> listeEmpMaladie = m.getListeEmpreinte();
    long nbEmp = m.nbEmpreinte;
    os << "idMaladie: " << m.idMaladie << "; Nombre d'Empreintes : " << nbEmp << endl;

    for (deque<Empreinte>::iterator it=listeEmpMaladie.begin(); it!=listeEmpMaladie.end(); ++it)
    {
        os << *it << endl;
    }
    return os;
}


Maladie::Maladie()
{

} 

Maladie::Maladie(long id, string nom)
{
	idMaladie = id;
	nomMaladie = nom;
	nbEmpreinte = 0; 
}


Maladie::~Maladie()
{
} 


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

