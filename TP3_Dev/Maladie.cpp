/*************************************************************************
Maladie  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
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
// type Maladie::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

bool Maladie::ajouterEmpreinte(string chEmp, deque<pair<string,string> > signature ) {
	bool ajoutee;


	/*std::string s = "scott>=tiger";
	std::string delimiter = ">=";
	std::string token = s.substr(0, s.find(delimiter));

	string delimiter = ";";
	Empreinte* e = new Empreinte();
	while (!signature.empty())
	{

		//string monType = signature.front();
		switch (c) //C'est quoi c ?
		{
		case 'A':
			capa++;
			break;
		case 'a':
			lettera++;
			break;
		default:
			nota++;
		}
		//e->id = stol(chEmp.substr(0, chEmp.find(delimiter)));
	}*/



	char delimiter = ';';
	string attribut;
	void* val;

	int posD = 0;
	int posF = chEmp.find(delimiter,posD);
	long id  = (long)stold(chEmp.substr(posD,posF-posD)); // Vu que posD vaut 0 je ne vois pas l'utilit� de faire posF-posD

	if(!empreinteExiste(id))
	{
		Empreinte* e = new Empreinte(id);
		posD = posF+1;

		int fin = chEmp.find_last_of(delimiter);
		int i = 0;

		while(posF != fin)
		{
			posF = chEmp.find(delimiter,posD);
			attribut  = chEmp.substr(posD,posF-posD);
			Attribut* A = new Attribut(signature[i].first,signature[i].second);

			if(A->getType() == "double")
			{
				val = new double(stod(attribut));
				A->setValue(val);
			}
			else if(A->getType() == "string")
			{
				val =  new string(attribut);
				A->setValue(val);
			}

			nbEmpreinte++;
			e->ajouterAttribut(*A);

			posD = posF+1;

			i++;

			delete A;
		}
		ajoutee = true;
		listeEmpreinte.push_back(*e);
		nbEmpreinte++; // Tu avais oubli� d'incr�menter le nombre d'empreinte
		delete e;
	}
	else
    {
		ajoutee = false;
	}

	return ajoutee;
}

// Est-ce qu'on a besoin de getEmpreinteById et empreinteExiste ?
// retourner un pointeur ? Pourquoi pas une r�f�rence ?
// Parce-que sinon la case que pointe e va �tre d�truite � la fin de
// la m�thode, non ?
Empreinte* Maladie::getEmpreinteById(long id) {
	Empreinte* e = nullptr;

	deque<Empreinte>::iterator it;

	for (it=listeEmpreinte.begin(); it!=listeEmpreinte.end(); ++it)
	{
		if(id == (*it).getIdEmpreinte())
		{
			*e = *it;
			cout << "ici " << endl;
			break;
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
			// Pourquoi un break apr�s avoir retourner ??
			break;
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



//------------------------------------------------- Surcharge d'op�rateurs
/*Maladie & Maladie::operator = (const Maladie & unMaladie)
// Algorithme :
//
{
} //----- Fin de operator =
*/

  //-------------------------------------------- Constructeurs - destructeur
Maladie::Maladie(const Maladie & unMaladie)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Maladie>" << endl;
#endif
} //----- Fin de Maladie (constructeur de copie)


Maladie::Maladie()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Maladie>" << endl;
#endif
} //----- Fin de Maladie

Maladie::Maladie(long id, string nom)
{
	idMaladie = id;
	nomMaladie = nom;
	nbEmpreinte = 0; // j'ai rajout� �a dans le constructeur
}


Maladie::~Maladie()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Maladie>" << endl;
#endif
} //----- Fin de ~Maladie


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

