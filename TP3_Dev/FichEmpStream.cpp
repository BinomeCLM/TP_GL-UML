/*************************************************************************
                           FichEmpStream  -  description
                             -------------------
    d�but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <FichEmpStream> (fichier FichEmpStream.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "FichEmpStream.h"

//------------------------------------------------------------- Constantes

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
    // Premi�re v�rif pour voir si un dictionnaire est d�ja renseign�e sinon erreur
    if (!signatureComplete.compare(""))
    {
        cerr << "Pas de dictionnaire encore rentr�. Analyse impossible." << endl;

    }

    bool extensionValide = verifierExtension(sourceFichier);
    bool signatureValide = false;

    // Si l'extension est valide et que le fichier n'est pas vide
    if (extensionValide && verifierFichierVide(sourceFichier))
    {
        signatureValide = verifierSignature(sourceFichier, false);
    }
    else
    {
        cerr << "Extension rentr�e ne correspond pas � '.txt' ou fichier vide" << endl;
    }

    if (signatureValide)
    {
        FichierPatient * fPatTemp = new FichierPatient(sourceFichier, signatureComplete.substr(0,signatureComplete.find_last_of(';')));

        ifstream fichier;
        fichier.open((char*)sourceFichier.c_str(), ios::in);

        if (fichier.is_open())
        {
            // D'abord, il faut se rendre � la premi�re empreinte !
            int i;
            string ligneEmpreinte;
            for (i=0; i<(nbAttributs+3); i++) // 2 lignes au d�part + nbAttributs-1 lignes + ligne vide + premi�re ligne non prise en compte
            {
                getline(fichier, ligneEmpreinte);
            }

            // Tant qu'on a pas atteint la fin du fichier, on lit la ligne
            // et on fait appel a ajouterEmpreinte d'Empreinte
            while (!fichier.eof())
            {
                getline(fichier, ligneEmpreinte);
                // Est-ce qu'on ajoute des verifications pour voir si la ligne n'est pas vide ?
                fPatTemp->ajouterEmpreinte(ligneEmpreinte);
            }

            fichier.close();

            return *fPatTemp;
        }
        else
        {
            cerr << "Le fichier est valide mais son ouverture a �chou�." << endl;

        }
    }
    else
    {
        cerr << "La signature ne correspond pas � celle du dictionnaire d�j� stock�e." << endl;

    }
}

// M�thode non v�rifi�e
Dictionnaire FichEmpStream::lireDictionnaire(string sourceFichier)
{
    bool extensionValide = verifierExtension(sourceFichier);
    bool signatureValide = false;

    if (extensionValide && verifierFichierVide(sourceFichier))
    {
        signatureValide = verifierSignature(sourceFichier, true);
    }
    else
    {
        cerr << "Extension rentr�e ne correspond pas � '.txt'" << endl;
    }

    if (signatureValide)
    {
        Dictionnaire * dTemp = new Dictionnaire(sourceFichier, signatureComplete);
        // Tant qu'on a pas atteint la fin du fichier, on lit la ligne
        // et on fait appel a ajouterMaladie
        ifstream fichier;
        fichier.open((char*)sourceFichier.c_str(), ios::in);

        if (fichier.is_open())
        {
            int i;
            string ligneEmpreinteMaladie;
            // On r�cup�re la premi�re ligne correspondante � la signature
            for (i=0; i<(nbAttributs+4); i++) // 2 lignes au d�part + nbAttributs lignes + ligne vide + premi�re ligne non prise en compte
            {
                getline(fichier, ligneEmpreinteMaladie);
            }

            while (!fichier.eof())
            {
                getline(fichier, ligneEmpreinteMaladie);
                dTemp->ajouterMaladie(ligneEmpreinteMaladie);
            }

            fichier.close();

            return *dTemp;
        }
        else
        {
            cerr << "Le fichier est valide mais son ouverture a �chou�." << endl;

        }
    }
    else
    {
        cerr << "La signature ne correspond pas � celle du dictionnaire d�j� stock�e." << endl;


    }

} //----- Fin de M�thode

// M�thode v�rifi�e, elle fonctionne
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
        // Pas de point dans la source du fichier donc forc�ment mauvaise source
        return false;
    }
}

// M�thode v�rifi�e, elle fonctionne
bool FichEmpStream::verifierSignature (string sourceFichier, bool dico)
{
    // But: r�cup�rer la signature du fichier enti�rement qui est la premi�re ligne
    // du fichier maladie dictionnaire donn� en parm�tre
    string signatureAverifier;
    ifstream fichier;
    fichier.open((char*)sourceFichier.c_str(), ios::in);
    if (fichier.is_open()) // Si l'ouverture a fonctionne
    {
        int i;
        // On r�cup�re la premi�re ligne correspondante � la signature
        if (dico)
        {
            for (i=0; i<(nbAttributs+4); i++) // 2 lignes au d�part + nbAttributs lignes + ligne vide
            {
                getline(fichier, signatureAverifier);
            }
            // Premiere verification : est-ce que la signature est null et est-ce que la signature du
            // nouveau doc n'est pas vide ? Si oui, premi�re execution donc on
            // ajoute forcement
            if (!signatureComplete.compare(""))
            {
                if (signatureAverifier.compare(""))
                {
                    compterAttributsSignature(sourceFichier);
                    signatureComplete = signatureAverifier; // On initialise l'attribut de la classe
                    return true;
                }
                else
                {
                    return false;
                }
            }
            // Deuxieme verif : si deja une signature, c'est qu'on veut ajouter de nouvelles donn�es
            // donc on les compare
            else if (signatureComplete.compare(signatureAverifier) == 0)
            {
                // Les deux signatures sont pareils donc on peut ajouter les nouvelles donn�es
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
            for (i=0; i<(nbAttributs+3); i++) // 2 lignes au d�part + nbAttributs lignes + ligne vide
            {
                getline(fichier, signatureAverifier);
            }
            // On retire le dernier attribut (disease) pour
            string signatureActuelle = signatureComplete.substr(0,signatureComplete.find_last_of(';'));
            if (signatureActuelle.compare(signatureAverifier) == 0)
            {
                // Les deux signatures sont pareils donc on peut ajouter les nouvelles donn�es
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
    }

}

// M�thode permettant de compter le nombre d'attributs de la
// signature la premi�re fois
// M�thode v�rifi�e, elle fonctionne
void FichEmpStream::compterAttributsSignature (string sourceFichier)
{
    long nbAttr = -2; // Car il y a toujours les deux premi�res lignes au d�but
    string chAttr = "ligne"; // Valeur par d�faut pour pouvoir rentrer dans la boucle au moins une fois
    ifstream fichier;
    fichier.open((char*)sourceFichier.c_str(), ios::in);
    if (fichier.is_open()) // Si l'ouverture a fonctionne
    {
        while (chAttr.compare("") && !fichier.eof()) // Tant qu'on est pas sur une ligne vide ou qu'on a pas atteint la fin du fichier
        {
            getline(fichier, chAttr);
            nbAttr++;
        }

        nbAttributs = nbAttr-1; // On enleve la ligne vide du compteur

        fichier.close();
    }
    else
    {
        cerr << "erreur lors de l'ouverture du fichier" << endl;
    }
}

// M�thode v�rifi�e, elle fonctionne
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
//------------------------------------------------- Surcharge d'op�rateurs
/*FichEmpStream & FichEmpStream::operator = ( const FichEmpStream & unFichEmpStream )
// Algorithme :
//
{
} *///----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/*FichEmpStream::FichEmpStream ( const FichEmpStream & unFichEmpStream )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <FichEmpStream>" << endl;
#endif
}*/ //----- Fin de FichEmpStream (constructeur de copie)


FichEmpStream::FichEmpStream ( )
// Algorithme :
//
{
    signatureComplete = "";
    nbAttributs = 0;
#ifdef MAP
    cout << "Appel au constructeur de <FichEmpStream>" << endl;
#endif
} //----- Fin de FichEmpStream


FichEmpStream::~FichEmpStream ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <FichEmpStream>" << endl;
#endif
} //----- Fin de ~FichEmpStream


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es
