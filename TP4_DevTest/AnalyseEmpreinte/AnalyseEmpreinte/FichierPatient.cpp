/*************************************************************************
                           FichierPatient  -  description
                             -------------------
    d�but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <FichierPatient> (fichier FichierPatient.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "FichierPatient.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type FichierPatient::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

deque<Analyse> FichierPatient::analyserEmpreinte (Dictionnaire d)
{
    // Est-ce qu'ici on ferait pas une deque aussi ? Pour stocker les analyses
    deque<Analyse> analyse;
    if (!listeEmpAnalyse.empty()) // V�rification si la liste des empreintes � analyser est vide ou non.
    // Est-ce qu'on la fait ici ou dans fichEmpStream. Je la laisse ici au cas ou pour l'instant
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
        cerr << "fichier des empreintes � analyse est vide." << endl;
        return analyse;
    }

}

bool FichierPatient::ajouterEmpreinte (string chEmp)
{
	
    char delimiter = ';';
	string attribut;


    unsigned int posD = 0;
	unsigned int posF = chEmp.find(delimiter,posD);
	long id  = (long)stold(chEmp.substr(posD,posF-posD));

	Empreinte * e = new Empreinte(id);

	posD = posF+1;
    cout << posF << endl;
    
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


        delete A; // C'est le pointeur qu'on delete et pas la case qu'il pointe
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
}

deque<Empreinte> FichierPatient::getListeEmpreinte()
{
    return listeEmpAnalyse;
}

//------------------------------------------------- Surcharge d'op�rateurs
/*FichierPatient & FichierPatient::operator = ( const FichierPatient & unFichierPatient )
// Algorithme :
//
{
}*/ //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/*FichierPatient::FichierPatient ( const FichierPatient & unFichierPatient )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <FichierPatient>" << endl;
#endif
}*/ //----- Fin de FichierPatient (constructeur de copie)

// Si le fichier n'est pas correcte, ce sera d�tect� d�s FichEmpStream
FichierPatient::FichierPatient(string nomFichier, string uneSignature) : Fichier::Fichier(nomFichier, uneSignature ){}

FichierPatient::FichierPatient ( )
// Algorithme :
//
{
    // Ici, on ne fait rien car avec FichEmpStream impossible de faire appel � ce constructeur par d�faut.
#ifdef MAP
    cout << "Appel au constructeur de <FichierPatient>" << endl;
#endif
} //----- Fin de FichierPatient


FichierPatient::~FichierPatient ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <FichierPatient>" << endl;
#endif
} //----- Fin de ~FichierPatient


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es
