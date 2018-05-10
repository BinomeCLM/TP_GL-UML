/*************************************************************************
                           FichEmpStream  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <FichEmpStream> (fichier FichEmpStream.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "FichEmpStream.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type FichEmpStream::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

// Méthode non vérifiée
FichierPatient FichEmpStream::lireFichierPatient (string sourceFichier)
{
    // Première vérif pour voir si un dictionnaire est déja renseignée sinon erreur
    if (!signatureComplete.compare(""))
    {
        cerr << "Pas de dictionnaire encore rentré. Analyse impossible." << endl;
        return nullptr;
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
        cerr << "Extension rentrée ne correspond pas à '.txt' ou fichier vide" << endl;
    }

    if (signatureValide)
    {
        FichierPatient fPatTemp = new FichierPatient(sourceFichier, signatureComplete.substr(0,signatureComplete.find_last_of(';')));

        ifstream fichier;
        fichier.open((char*)sourceFichier.c_str(), ios::in);

        if (fichier.is_open())
        {
            // D'abord, il faut se rendre à la première empreinte !
            int i;
            string ligneEmpreinte;
            for (i=0; i<(nbAttributs+3); i++) // 2 lignes au départ + nbAttributs-1 lignes + ligne vide + première ligne non prise en compte
            {
                getline(fichier, ligneEmpreinte);
            }

            // Tant qu'on a pas atteint la fin du fichier, on lit la ligne
            // et on fait appel a ajouterEmpreinte d'Empreinte
            while (!fichier.eof())
            {
                getline(fichier, ligneEmpreinte);
                // Est-ce qu'on ajoute des verifications pour voir si la ligne n'est pas vide ?
                fPatTemp.ajouterEmpreinte(ligneEmpreinte);
            }

            fichier.close();

            return fPatTemp;
        }
        else
        {
            cerr << "Le fichier est valide mais son ouverture a échoué." << endl;
            return nullptr;
        }
    }
    else
    {
        cerr << "La signature ne correspond pas à celle du dictionnaire déjà stockée." << endl;
        return nullptr;
    }
}

// Méthode non vérifiée
Dictionnaire FichEmpStream::lireDictionnaire(string sourceFichier)
{
    bool extensionValide = verifierExtension(sourceFichier);
    bool signatureValide = false;

    if (extensionValide && verifierFichierVide(sourceFichier))
    {
        signatureValide = verifierSignature(sourceFichier);
    }
    else
    {
        cerr << "Extension rentrée ne correspond pas à '.txt'" << endl;
    }

    if (signatureValide)
    {
        Dictionnaire dTemp = new Dictionnaire(sourceFichier, signatureComplete);
        // Tant qu'on a pas atteint la fin du fichier, on lit la ligne
        // et on fait appel a ajouterMaladie
        ifstream fichier;
        fichier.open((char*)sourceFichier.c_str(), ios::in);

        if (fichier.is_open())
        {
            int i;
            string ligneEmpreinteMaladie;
            // On récupére la première ligne correspondante à la signature
            for (i=0; i<(nbAttributs+4); i++) // 2 lignes au départ + nbAttributs lignes + ligne vide + première ligne non prise en compte
            {
                getline(fichier, ligneEmpreinteMaladie);
            }

            while (!fichier.eof())
            {
                getline(fichier, ligneEmpreinteMaladie);
                dTemp.ajouterMaladie(ligneEmpreinteMaladie);
            }

            fichier.close();
        }
        else
        {
            cerr << "Le fichier est valide mais son ouverture a échoué." << endl;
        }
    }
    else
    {
        cerr << "La signature ne correspond pas à celle du dictionnaire déjà stockée." << endl;
    }

} //----- Fin de Méthode

// Méthode vérifiée, elle fonctionne
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
        // Pas de point dans la source du fichier donc forcément mauvaise source
        return false;
    }
}

// Méthode vérifiée, elle fonctionne
bool FichEmpStream::verifierSignature (string sourceFichier, bool dico)
{
    // But: récupérer la signature du fichier entiérement qui est la première ligne
    // du fichier maladie dictionnaire donné en parmètre
    string signatureAverifier;
    ifstream fichier;
    fichier.open((char*)sourceFichier.c_str(), ios::in);
    if (fichier.is_open()) // Si l'ouverture a fonctionne
    {
        int i;
        // On récupére la première ligne correspondante à la signature
        if (dico)
        {
            for (i=0; i<(nbAttributs+4); i++) // 2 lignes au départ + nbAttributs lignes + ligne vide
            {
                getline(fichier, signatureAverifier);
            }
            // Premiere verification : est-ce que la signature est null et est-ce que la signature du
            // nouveau doc n'est pas vide ? Si oui, première execution donc on
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
            // Deuxieme verif : si deja une signature, c'est qu'on veut ajouter de nouvelles données
            // donc on les compare
            else if (signatureComplete.compare(signatureAverifier) == 0)
            {
                // Les deux signatures sont pareils donc on peut ajouter les nouvelles données
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
            for (i=0; i<(nbAttributs+3); i++) // 2 lignes au départ + nbAttributs lignes + ligne vide
            {
                getline(fichier, signatureAverifier);
            }
            // On retire le dernier attribut (disease) pour
            string signatureActuelle = signatureComplete.substr(0,signatureComplete.find_last_of(';'));
            if (signatureActuelle.compare(signatureAverifier) == 0)
            {
                // Les deux signatures sont pareils donc on peut ajouter les nouvelles données
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

// Méthode permettant de compter le nombre d'attributs de la
// signature la première fois
// Méthode vérifiée, elle fonctionne
void FichEmpStream::compterAttributsSignature (string sourceFichier)
{
    long nbAttr = -2; // Car il y a toujours les deux premières lignes au début
    string chAttr = "ligne"; // Valeur par défaut pour pouvoir rentrer dans la boucle au moins une fois
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

// Méthode vérifiée, elle fonctionne
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
//------------------------------------------------- Surcharge d'opérateurs
FichEmpStream & FichEmpStream::operator = ( const FichEmpStream & unFichEmpStream )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
FichEmpStream::FichEmpStream ( const FichEmpStream & unFichEmpStream )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <FichEmpStream>" << endl;
#endif
} //----- Fin de FichEmpStream (constructeur de copie)


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

//----------------------------------------------------- Méthodes protégées
