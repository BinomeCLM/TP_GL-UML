/*************************************************************************
                           FichierPatient  -  description
                             -------------------
    début                : 03/04/2018
    copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
*************************************************************************/

//---------- Réalisation de la classe <FichierPatient> (fichier FichierPatient.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "FichierPatient.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


deque<Analyse> FichierPatient::analyserEmpreinte (Dictionnaire d)
{
    deque<Analyse> analyse;
    if (!listeEmpAnalyse.empty()) 
    {
        for (std::deque<Empreinte>::iterator it=listeEmpAnalyse.begin(); it!=listeEmpAnalyse.end(); ++it)
        {
            Analyse a;
            a.setIdEmpreinte(it->getIdEmpreinte());
            a = it->lancerAnalyse(d);
            analyse.push_back(a);
        }
        return analyse;
    }
    else
    {
        cerr << "fichier des empreintes a analyse est vide." << endl;
        return analyse;
    }
} //----- Fin de analyserEmpreinte

bool FichierPatient::ajouterEmpreinte (string chEmp)
{
    char delimiter = ';';
	string attribut;

    unsigned int posD = 0;
	unsigned int posF = chEmp.find(delimiter,posD);
	long id  = (long)stold(chEmp.substr(posD,posF-posD));

	Empreinte * e = new Empreinte(id);

	posD = posF+1;
    
    int i = 0;
    unsigned int fin = chEmp.find_last_of(';');
    while(posF != fin)
    {
        posF = chEmp.find(delimiter,posD);
        attribut  = chEmp.substr(posD,posF-posD);
        void* val;
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

        nbEmpreintes++;
        e->ajouterAttribut(A);

        posD = posF+1;

        i++;

        delete A; 
    }
    posF = chEmp.find('\\',posD);
    attribut  = chEmp.substr(posD,posF-posD);

    void* val2;
    Attribut* A = new Attribut(signature[i].first,signature[i].second);


    if(A->getType() == "double")
    {
        val2 = new double(stod(attribut));
        A->setValue(val2);
        delete (double*)val2;
    }
    else if(A->getType() == "string")
    {
        val2 =  new string(attribut);
        A->setValue(val2);
        delete (string*)val2;
    }

    nbEmpreintes++;
    e->ajouterAttribut(A);

    listeEmpAnalyse.push_back(*e);

    delete A;
    delete e;
	
    return true;
} //----- Fin de ajouterEmpreinte

deque<Empreinte> FichierPatient::getListeEmpreinte()
{
    return listeEmpAnalyse;
} //----- Fin de getListeEmpreinte

//-------------------------------------------- Constructeurs - destructeur

FichierPatient::FichierPatient(string nomFichier, string uneSignature) : Fichier::Fichier(nomFichier, uneSignature )
{} //----- Fin de FichierPatient

FichierPatient::FichierPatient ( ) : Fichier::Fichier()
{} //----- Fin de FichierPatient

FichierPatient::~FichierPatient ( )
{} //----- Fin de ~FichierPatient

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
