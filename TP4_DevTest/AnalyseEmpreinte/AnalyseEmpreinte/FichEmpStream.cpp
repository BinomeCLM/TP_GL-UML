/*************************************************************************
                           FichEmpStream  -  description
                             -------------------
    d�but                : 03/04/2018
    copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
*************************************************************************/

//---------- R�alisation de la classe <FichEmpStream> (fichier FichEmpStream.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "FichEmpStream.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type FichEmpStream::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

// M�thode non v�rifi�e
FichierPatient FichEmpStream::lireFichierPatient (string sourceFichier)
{
    FichierPatient fPatTemp;
    //On vérifie d'abord si un dictionnaire a déjà été renseigné
    if (!signatureComplete.compare(""))
    {
        cerr << "Pas de dictionnaire encore rentr�. Analyse impossible." << endl;
        return fPatTemp;
    }

	//Vérifie l’extension du fichier
    bool extensionValide = verifierExtension(sourceFichier);

    bool signatureValide = false;

    if (extensionValide)
    {
		//Verifier si il est vide
		if (verifierFichierVide(sourceFichier)) {
			//Verifier sa signature
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

	//Si c’est 3 critères sont correctes, ouvre le fichier sourceFichier
    if (signatureValide)
    {
        string laSignatureFichPat = signatureComplete.substr(0,signatureComplete.find_last_of(';')-7);
        fPatTemp.setNomFichier(sourceFichier);
        fPatTemp.setSignature(laSignatureFichPat);

        ifstream fichier;
        fichier.open((char*)sourceFichier.c_str(), ios::in);

        if (fichier.is_open())
        {
            // D'abord, il faut se rendre a la premiere empreinte
            int i;
            string ligneEmpreinte;
            for (i=0; i<(nbAttributs+3); i++) // 2 lignes au depart + nbAttributs-1 lignes + ligne vide + premi�re ligne non prise en compte
            {
                getline(fichier, ligneEmpreinte);
            }

            // Tant qu'on a pas atteint la fin du fichier, on lit la ligne
            // et on fait appel a ajouterEmpreinte d'Empreinte
            while (!fichier.eof())
            {
                getline(fichier, ligneEmpreinte);
                if (ligneEmpreinte.compare(""))
				{
					//Recuperer l’ensemble des empreintes à analyser et les stocke dans un FichierPatient.
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
}

void FichEmpStream::lireDictionnaire(Dictionnaire & dico, string sourceFichier)
//En cas d’ajout alors que le dictionnaire contient déjà des données, 
//cette méthode ajoute les maladies qui ne sont pas déjà présentes ainsi que les empreintes, 
//dont l’identifiant est différent, pour les maladies existantes.
{
	//Vérifie l’extension du fichier
    bool extensionValide = verifierExtension(sourceFichier);
    bool signatureValide = false;

    if (extensionValide)
    {
		//Verifie s’il est vide ou non
		if (verifierFichierVide(sourceFichier)) 
		{
			//Verifie sa signature
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

	//Si c’est 3 critères sont correctes, ouvre le fichier sourceFichier
    if (signatureValide)
    {
        dico.setNomFichier(sourceFichier);
        dico.setSignature(signatureComplete);
        // Tant qu'on a pas atteint la fin du fichier, on lit la ligne
        // et on fait appel a ajouterMaladie
        ifstream fichier;
        fichier.open((char*)sourceFichier.c_str(), ios::in);

        if (fichier.is_open())
        {
            int i;
            string ligneEmpreinteMaladie;
            // On recupere la premiere ligne correspondante a la signature
            for (i=0; i<(nbAttributs+4); i++) // 2 lignes au depart + nbAttributs lignes + ligne vide + premiere ligne non prise en compte
            {
                getline(fichier, ligneEmpreinteMaladie);
            }
			
            while (!fichier.eof())
            {
                getline(fichier, ligneEmpreinteMaladie);
				if (ligneEmpreinteMaladie.compare(""))
				{
					//récupére l’ensemble des maladies pour la base de connaissances et les stocke
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

} //----- Fin de Methode


bool FichEmpStream::verifierExtension (string sourceFichier)
{
    int index = sourceFichier.find_last_of('.');

    if (index != -1)
    {
        string extension = sourceFichier.substr(index,sourceFichier.length());
        if (extension.compare(".txt") == 0) // Ils sont identiques
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
        //Pas de point dans la source du fichier donc forcement mauvaise source
        return false;
    }
}


bool FichEmpStream::verifierSignature (string sourceFichier, bool dico)
{

    string signatureAverifier;
    ifstream fichier;
    fichier.open((char*)sourceFichier.c_str(), ios::in);
    long nbAttrSignaAverifier = compterAttributsSignature(sourceFichier);
    if (fichier.is_open()) // Si l'ouverture a fonctionne
    {
        int i;
        // On recupere la premiere ligne correspondante a la signature
        if (dico)
        {
            getline(fichier, signatureAverifier);
            getline(fichier, signatureAverifier);
            string signatureCompTemp = "";
            for (i=0; i<(nbAttrSignaAverifier); i++) // 2 lignes au depart + nbAttributs lignes + ligne vide
            {
                getline(fichier, signatureAverifier);

                // Les docs txt sous windows ont un \r à la fin, il faut donc le verifier et le supprimer si besoin
                if (signatureAverifier.substr(signatureAverifier.length()-1,signatureAverifier.length()).compare("\r") == 0)
                {
                    signatureCompTemp = signatureCompTemp + signatureAverifier.substr(0,signatureAverifier.length()-1);

                }
                else
                {
                    signatureCompTemp = signatureCompTemp + signatureAverifier;
                }
            }
            
			//Verifier que la signature n'est pas nulle ou vide
            if (!signatureComplete.compare(""))
            {
                if (signatureCompTemp.compare(""))
                {
                    nbAttributs = nbAttrSignaAverifier;
                    signatureComplete = signatureCompTemp; // On initialise l'attribut de la classe
                    return true;
                }
                else
                {
                    return false;
                }
            }
          
			//Verifier si il y a déjà une signature défini. Si oui on vérifie qu'elles sont identiques
            else if (signatureComplete.compare(signatureCompTemp) == 0)
            {
                // Les deux signatures sont pareils donc on peut ajouter les nouvelles donnees
                // au dictionnaire
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
            for (i=0; i<(nbAttrSignaAverifier); i++) // 2 lignes au depart + nbAttributs lignes + ligne vide
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
            // On retire le dernier attribut (disease)
            string signatureActuelle = signatureComplete.substr(0,signatureComplete.find_last_of(';'));
            signaCompTemp = signaCompTemp + "Disease";
            if (signatureActuelle.compare(signaCompTemp) == 0)
            {
                // Les deux signatures sont pareils donc on peut ajouter les nouvelles donnees
                // au dictionnaire
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

}

long FichEmpStream::compterAttributsSignature (string sourceFichier)
{
    long nbAttr = 1; // Car il y a toujours les deux premieres lignes au debut
    string chAttr = "ligne"; // Valeur par defaut pour pouvoir rentrer dans la boucle au moins une fois
    ifstream fichier;
    fichier.open((char*)sourceFichier.c_str(), ios::in);
    if (fichier.is_open()) // Si l'ouverture a fonctionne
    {
        int i;
        // On le fait 3 fois pour récupérer directement le premier attribit
        for (i=0; i<3; i++)
        {
            getline(fichier, chAttr);
        }

        // Si le premier attribut n'est pas vide, on commence à compter
        if (chAttr.compare(""))
        {
			// Tant qu'on est pas sur une ligne vide ou qu'on a pas atteint la fin du fichier
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
}

bool FichEmpStream::verifierFichierVide(string sourceFichier)
{
    ifstream fichier;
    fichier.open((char*)sourceFichier.c_str(), ios::in);
    if (fichier.is_open()) // Si l'ouverture a fonctionne
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
}

string FichEmpStream::getSignatureComplete()
{
    return signatureComplete;
}



FichEmpStream::FichEmpStream ( )
{
    signatureComplete = "";
    nbAttributs = 0;
} 


FichEmpStream::~FichEmpStream ( )
{

} 


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees
