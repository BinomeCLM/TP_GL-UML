/*************************************************************************
					   FichEmpStream  -  description
                             -------------------
    début                : 03/04/2018
    copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
*************************************************************************/

//---------- Réalisation de la classe <FichEmpStream> (fichier FichEmpStream.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "FichEmpStream.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

FichierPatient FichEmpStream::lireFichierPatient (string sourceFichier)
{
    FichierPatient fPatTemp;
    if (!signatureComplete.compare(""))
    {
        cerr << "Pas de dictionnaire encore rentré. Analyse impossible." << endl;
        return fPatTemp;
    }

    bool extensionValide = verifierExtension(sourceFichier);

    bool signatureValide = false;

    if (extensionValide)
    {
		if (verifierFichierVide(sourceFichier)) 
		{
			signatureValide = verifierSignature(sourceFichier, false);
		}
		else
		{
			cerr << "Le fichier est vide" << endl;
			return fPatTemp;
		}
    }
    else
    {
        cerr << "Extension rentree ne correspond pas a '.txt'" << endl;
        return fPatTemp;
    }

    if (signatureValide)
    {
		// Pour un FichierPatient, on ne prend pas en compte 'Disease' qui est le dernier élément de la signature.
        string laSignatureFichPat = signatureComplete.substr(0,signatureComplete.find_last_of(';')-7);
        fPatTemp.setNomFichier(sourceFichier);
        fPatTemp.setSignature(laSignatureFichPat);

        ifstream fichier;
        fichier.open((char*)sourceFichier.c_str(), ios::in);

        if (fichier.is_open())
        {
            // D'abord, on se rend à la première ligne d'empreinte
			// (2 lignes au depart + nbAttributs-1 lignes + ligne vide + première ligne) non prises en compte
            int i;
            string ligneEmpreinte;
            for (i=0; i<(nbAttributs+3); i++) 
            {
                getline(fichier, ligneEmpreinte);
            }

            while (!fichier.eof())
            {
                getline(fichier, ligneEmpreinte);
                if (ligneEmpreinte.compare(""))
				{
                    fPatTemp.ajouterEmpreinte(ligneEmpreinte);
                }
            }

            fichier.close();

            return fPatTemp;
        }
        else
        {
            cerr << "Le fichier est valide mais son ouverture a echoue." << endl;
            return fPatTemp;
        }
    }
    else
    {
        cerr << "La signature ne correspond pas a celle du dictionnaire deja stockee." << endl;
        return fPatTemp;
    }
} //----- Fin de lireFichierPatient

void FichEmpStream::lireDictionnaire(Dictionnaire & dico, string sourceFichier)
{
    bool extensionValide = verifierExtension(sourceFichier);
    bool signatureValide = false;

    if (extensionValide)
    {
		if (verifierFichierVide(sourceFichier)) 
		{
			signatureValide = verifierSignature(sourceFichier, true);
		}
		else
		{
			cerr << "Le fichier est vide" << endl;
		}
    }
    else
    {
        cerr << "Extension rentree ne correspond pas a '.txt'" << endl;
    }

    if (signatureValide)
    {
        dico.setNomFichier(sourceFichier);
        dico.setSignature(signatureComplete);
        ifstream fichier;
        fichier.open((char*)sourceFichier.c_str(), ios::in);

        if (fichier.is_open())
        {
            int i;
            string ligneEmpreinteMaladie;
            // On  place à la premiere ligne correspondante à une maladie
			// (2 lignes au depart + nbAttributs lignes + ligne vide + premiere ligne) non prise en compte
            for (i=0; i<(nbAttributs+4); i++) 
            {
                getline(fichier, ligneEmpreinteMaladie);
            }
			
            while (!fichier.eof())
            {
                getline(fichier, ligneEmpreinteMaladie);
				if (ligneEmpreinteMaladie.compare(""))
				{
                    dico.ajouterMaladie(ligneEmpreinteMaladie);
                }
            }
            fichier.close();
        }
        else
        {
            cerr << "Le fichier est valide mais son ouverture a echoue." << endl;
        }
    }
    else
    {
        cerr << "La signature ne correspond pas a celle du dictionnaire deja stockee." << endl;
    }
} //----- Fin de lireDictionnaire


bool FichEmpStream::verifierExtension (string sourceFichier)
{
    int index = sourceFichier.find_last_of('.');

    if (index != -1)
    {
        string extension = sourceFichier.substr(index,sourceFichier.length());
        if (extension.compare(".txt") == 0) 
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
} //----- Fin de verifierExtension


bool FichEmpStream::verifierSignature (string sourceFichier, bool dico)
{
    string signatureAverifier;
    ifstream fichier;
    fichier.open((char*)sourceFichier.c_str(), ios::in);
    long nbAttrSignaAverifier = compterAttributsSignature(sourceFichier);
    if (fichier.is_open())
    {
        int i;
        if (dico)
        {
            getline(fichier, signatureAverifier);
            getline(fichier, signatureAverifier);
            string signatureCompTemp = "";
            for (i=0; i<(nbAttrSignaAverifier); i++)
            {
                getline(fichier, signatureAverifier);

                // Les docs '.txt' sous windows peuvent contenir un \r en fin de ligne, il faut donc le verifier et ne pas le prendre en compte si présent.
                if (signatureAverifier.substr(signatureAverifier.length()-1,signatureAverifier.length()).compare("\r") == 0)
                {
                    signatureCompTemp = signatureCompTemp + signatureAverifier.substr(0,signatureAverifier.length()-1);
                }
                else
                {
                    signatureCompTemp = signatureCompTemp + signatureAverifier;
                }
            }
            
            if (!signatureComplete.compare(""))
            {
                if (signatureCompTemp.compare(""))
                {
					// On initialise les attributs de la classe car c'est le premier Dictionnaire ajouté
                    nbAttributs = nbAttrSignaAverifier;
                    signatureComplete = signatureCompTemp; 
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if (signatureComplete.compare(signatureCompTemp) == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            getline(fichier, signatureAverifier);
            getline(fichier, signatureAverifier);
            string signaCompTemp = "";
            for (i=0; i<(nbAttrSignaAverifier); i++)
            {
                getline(fichier, signatureAverifier);
                if (signatureAverifier.substr(signatureAverifier.length()-1,signatureAverifier.length()).compare("\r") == 0)
                {
                    signaCompTemp = signaCompTemp + signatureAverifier.substr(0,signatureAverifier.length()-1);
                }
                else
                {
                    signaCompTemp = signaCompTemp + signatureAverifier;
                }
            }
            string signatureActuelle = signatureComplete.substr(0,signatureComplete.find_last_of(';'));
            signaCompTemp = signaCompTemp + "Disease";
            if (signatureActuelle.compare(signaCompTemp) == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        cerr << "erreur lors de l'ouverture du fichier" << endl;
        return false;
    }
} //----- Fin de verifierSignature

long FichEmpStream::compterAttributsSignature (string sourceFichier)
{
    long nbAttr = 1; 
    string chAttr = "ligne"; // Valeur par defaut pour pouvoir rentrer dans la boucle au moins une fois
    ifstream fichier;
    fichier.open((char*)sourceFichier.c_str(), ios::in);
    if (fichier.is_open()) 
    {
        int i;
        // On le fait 3 fois pour se placer directement sur le premier attribut
        for (i=0; i<3; i++)
        {
            getline(fichier, chAttr);
        }

        // Si le premier attribut n'est pas vide, on commence à compter
        if (chAttr.compare(""))
        {
            while (chAttr.compare("") && chAttr.substr(0,4).compare("NoID") && !fichier.eof()) 
            {
                getline(fichier, chAttr);
                nbAttr++;
            }
        }
        fichier.close();
        return nbAttr-1; // On enleve la ligne vide du compteur
    }
    else
    {
        cerr << "erreur lors de l'ouverture du fichier" << endl;
        return 0;
    }
} //----- Fin de compterAttributsSignature

bool FichEmpStream::verifierFichierVide(string sourceFichier)
{
    ifstream fichier;
    fichier.open((char*)sourceFichier.c_str(), ios::in);
    if (fichier.is_open()) 
    {
        fichier.seekg (0, fichier.end);
        int length = fichier.tellg();
        fichier.close();
        if (length == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        cerr << "erreur lors de l'ouverture du fichier" << endl;
        return false;
    }
} //----- Fin de verifierFichierVide

string FichEmpStream::getSignatureComplete()
{
    return signatureComplete;
} //----- Fin de getSignatureComplete

//-------------------------------------------- Constructeurs - destructeur

FichEmpStream::FichEmpStream ( )
{
    signatureComplete = "";
    nbAttributs = 0;
} //----- Fin de FichEmpStream


FichEmpStream::~FichEmpStream ( )
{} //----- Fin de ~FichEmpStream

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees
