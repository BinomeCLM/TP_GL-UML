/*************************************************************************
                           FichierPatient  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <FichierPatient> (fichier FichierPatient.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "FichierPatient.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type FichierPatient::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

Analyse* FichierPatient::analyserEmpreinte (Dictionnaire d)
{
    // Est-ce qu'ici on ferait pas une deque aussi ? Pour stocker les analyses
    deque<Analyse> analyse;
    if (!listeEmpAnalyse.empty()) // Vérification si la liste des empreintes à analyser est vide ou non.
    // Est-ce qu'on la fait ici ou dans fichEmpStream. Je la laisse ici au cas ou pour l'instant
    {
        for (std::deque<Empreinte>::iterator it=listeEmpAnalyse.begin(); it!=listeEmpAnalyse.end(); ++it)
        {
            Analyse a = new Analyse(*it.getIdEmpreinte());
            a = *it.lancerAnalyse(d);
            analyse.push_back(a);
        }
    }
    else
    {
        cerr << "fichier des empreintes à analyse est vide." << endl;
    }

}

bool FichierPatient::ajouterEmpreinte (string chEmp)
{
    char delimiter = ';';
	string attribut;
	void* val;

	int posD = 0;
	int posF = chEmp.find(delimiter,posD);
	long id  = (long)stold(chEmp.substr(posD,posF-posD));

	Empreinte e = new Empreinte(id);

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
        e.ajouterAttribut(*A);

        posD = posF+1;

        i++;

        delete A; // C'est le pointeur qu'on delete et pas la case qu'il pointe
    }

    listeEmpAnalyse.push_back(e);
}

//------------------------------------------------- Surcharge d'opérateurs
/*FichierPatient & FichierPatient::operator = ( const FichierPatient & unFichierPatient )
// Algorithme :
//
{
}*/ //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
FichierPatient::FichierPatient ( const FichierPatient & unFichierPatient )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <FichierPatient>" << endl;
#endif
} //----- Fin de FichierPatient (constructeur de copie)

// Si le fichier n'est pas correcte, ce sera détecté dès FichEmpStream
FichierPatient::FichierPatient(string nomFichier, string uneSignature) : Fichier::Fichier(nomFichier, uneSignature ){}

FichierPatient::FichierPatient ( )
// Algorithme :
//
{
    // Ici, on ne fait rien car avec FichEmpStream impossible de faire appel à ce constructeur par défaut.
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

//----------------------------------------------------- Méthodes protégées
