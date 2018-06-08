/*************************************************************************
						Main  -  description
-------------------
début                : 03/04/2018
copyright            : 2018 par M.COREKCI, C.ETIENNE, L.GHANDOUR
*************************************************************************/

//---------- R�alisation de la classe <Main> (fichier Main.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <deque>
#include <string>
#include <time.h>
//------------------------------------------------------ Include personnel
#include "Main.h"

//----------------------------------------------------------------- PUBLIC

int main() {
	Main main;

	// Scénario
	FichEmpStream * fes = new FichEmpStream;
	Dictionnaire * dico = new Dictionnaire;
	main.renseignerDictionnaire(*dico, fes);
	bool power = true;
	while (power) {
		cout << "Que voulez-vous faire?" << endl;
		cout << " 1 - Analyser des empreintes\n 2 - Ajouter de nouvelles données au dictionnaire" << endl;
		cout << " 3 - Afficher le contenu du dictionnaire " << endl;
		cout << " 4 - Afficher les détails d'une maladie" << endl;
		cout << " 5 - Quitter le programme" << endl;
		int choix = main.lireEntree(1, 5);

		switch (choix) {
			case 1: {
				FichierPatient *fpat = new FichierPatient;
				*fpat = main.renseignerFichierPatient(fes);
				deque<Empreinte> emp = fpat->getListeEmpreinte();
				if (emp.size() == 0)
				{
				    break;
				}
				cout << "Que souhaitez-vous faire ?" << endl;
				cout << " 1 - Afficher les 10 maladies les plus probables" << endl;
				cout << " 2 - Afficher la maladie la plus probable" << endl;
				int choixAffichage = main.lireEntree(1, 2);

				if (choixAffichage == 1) 
				{
					main.afficherTop10(*dico, *fpat);
				} 
				else 
				{
					main.afficherMeilleurCorresp(*dico, *fpat);
				}
				delete fpat;
				break;
			}

			case 2: 
			{
				main.renseignerDictionnaire(*dico,fes);
				break;
			}

			case 3: 
			{
				main.afficherDictionnaire(*dico);
				break;
			}

			case 4:
			{
				cout << "Veuillez rentrer l'id de la maladie" << endl;
				deque <Maladie> mal = dico->getListeMaladie();
				int nbMaladie = mal.size();
				int id = main.lireEntree(1, nbMaladie);
				main.afficherDetailMaladie(id, *dico);
				break;
			}

			case 5:
			{
				power = false;
				break;
			}

			default:
			{
				power = false;
				break;
			}
		}
	}

    delete fes;
    delete dico;
	
	return 0;
} //----- Fin de main

void Main::renseignerDictionnaire(Dictionnaire & d, FichEmpStream * lecteur)
{
	string sourceFichierDico = "";
	cout << "Veuillez renseigner le fichier servant de base de connaissances." << endl;
	cin >> sourceFichierDico;

	lecteur->lireDictionnaire(d, sourceFichierDico);
} //----- Fin de renseignerDictionnaire

FichierPatient Main::renseignerFichierPatient(FichEmpStream * lecteur)
{
	string sourceFichierAnalyse = "";
	cout << "Veuillez renseigner le fichier contenant les empreintes à analyser." << endl;
	cin >> sourceFichierAnalyse;
	FichierPatient fPat;
	fPat = lecteur->lireFichierPatient(sourceFichierAnalyse);

	return fPat;
} //----- Fin de renseignerFichierPatient

void Main::afficherTop10(Dictionnaire d, FichierPatient fp)
{
	time_t t = clock();
	deque<Analyse> lesAnalyses = fp.analyserEmpreinte(d);
	cout << lesAnalyses.size() << endl;
	for (deque<Analyse>::iterator it=lesAnalyses.begin(); it!=lesAnalyses.end(); it++)
	{
		multimap<double,string> resultat = retrouverResultat(*it,false);
		int compteur = 1;
		cout << "Résultat de l'analyse pour l'empreinte numéro " << it->getIdEmpreinte() << endl;
		if (resultat.size() != 0)
		{
			for (multimap<double, string>::reverse_iterator it2 = resultat.rbegin(); it2 != resultat.rend(); it2++)
			{
				cout << compteur << ". " << it2->second << " : " << " proba : " << it2->first << "% de chance - " << endl;
				if (it2->first >= 70)
				{
					cout << "Très probable." << endl;
					cout << "Une analyse supplémentaire pour vérification est conseillée." << endl;
					cout << endl;
				}
				else if (it2->first >= 50)
				{
					cout << "Probable" << endl;
					cout << endl;
				}
				else
				{
					cout << "Peu probable" << endl;
					cout << endl;
				}
				compteur++;
				if (compteur == 11)
				{
					compteur--;
				}
			}
		}
		else
		{
			cout << "Aucun risque de maladie détecté à partir des informations "
			 		"contenues dans notre unité de stockage." << endl;
            cout << endl;	
		}

		t = clock() - t;
		cout << t << endl;
	}
} //----- Fin de afficherTop10

void Main::afficherMeilleurCorresp(Dictionnaire d, FichierPatient fp)
{
	deque<Analyse> lesAnalyses = fp.analyserEmpreinte(d);
	for (deque<Analyse>::iterator it = lesAnalyses.begin(); it != lesAnalyses.end(); it++)
	{
		cout << "Résultat de l'analyse pour l'empreinte numéro " << it->getIdEmpreinte() << endl;
		multimap<double, string> resultat = retrouverResultat(*it,true);
		if (resultat.size() != 0)
		{
			if (resultat.size() == 1)
			{
				cout << "Maladie avec la meilleur correspondance : " << endl;
			}
			else
			{
				cout << resultat.size() << " maladies à égalité, affichage des meilleures correspondances : " << endl;
			}
			for (multimap<double, string>::reverse_iterator it2 = resultat.rbegin(); it2 != resultat.rend(); it2++)
			{
				
				cout << it2->second << " : " << " proba : " << it2->first << "% de chance - ";

				if (it2->first >= 70) {
					cout << "Très probable." << endl;
					cout << "Une analyse supplémentaire pour vérification est conseillée." << endl;
					cout << endl;
				}
				else if (it2->first >= 50) {
					cout << "Probable" << endl;
					cout << endl;
				}
				else {
					cout << "Peu probable" << endl;
					cout << endl;
				}
			}
		}
		else
		{
			cout << "Aucun risque de maladie détecté à partir des informations "
				"contenues dans notre unité de stockage." << endl;
			cout << endl;
		}
	}
} //----- Fin de afficherMeilleurCorresp

multimap<double, string> Main::retrouverResultat(Analyse a, bool meilleur) 
{
	int compteur = 1;
	multimap<double, string> resultat = a.getCorrespondances();
	multimap<double, string> resultatMeilleur;
	double probaLimite = 0;
	if (meilleur)
	{
		if (resultat.size() > 1)
		{
			multimap<double, string>::reverse_iterator it2 = resultat.rbegin();
			probaLimite = it2->first;
		}

		for (multimap<double, string>::reverse_iterator it = resultat.rbegin(); it != resultat.rend(); it++)
		{
			if (it->first > 20)
			{
				if (compteur > 1 && it->first != probaLimite)
				{
					break;
				}

				if (it->second.compare("")) {
					resultatMeilleur.insert(pair<double, string>(it->first, it->second));
					compteur++;
				}
			}
			else {
				break;
			}
		}	
	}
	else 
	{
		if (resultat.size() > 10)
		{
			multimap<double, string>::reverse_iterator it3 = resultat.rbegin();
			advance(it3, 9);
			probaLimite = it3->first;
		}

		for (multimap<double, string>::reverse_iterator it = resultat.rbegin(); it != resultat.rend(); it++)
		{
			if (it->first > 20) 
			{
				if (compteur > 10 && it->first != probaLimite)
				{
					break;
				}

				if (it->second.compare("")) {

					resultatMeilleur.insert(pair<double, string>(it->first, it->second));
					compteur++;
				}
			}
			else {
				break;
			}
		}
	}
	return resultatMeilleur;
} //----- Fin de retrouverResultat

void Main::afficherDictionnaire(Dictionnaire d)
{
	cout << d << endl;
} //----- Fin de afficherDictionnaire

void Main::afficherDetailMaladie(long idMaladie, Dictionnaire d)
{
	Maladie maladie = d.getMaladieById(idMaladie);
	cout << maladie << endl;
} //----- Fin de afficherDetailMaladie

int Main::lireEntree(int min, int max)
{
	bool valid = false;
	int nbRentre;
	while (!valid)
	{
		cin >> nbRentre;
		if (cin.fail())
		{
			cout << "Données non valide" << endl;
			cin.clear(ios::goodbit);
			cin.ignore(100,'\n');
		}
		else {
			if (nbRentre >= min && nbRentre <= max)
			{
				valid = true;
			}
			else
			{
				cout << "Nombre saisie invalide, saisissez un nombre entre " << min << " et " << max << endl;
			}
		}
	}
	cin.clear(ios::goodbit);
	cin.ignore(100,'\n');
	return nbRentre;
} //----- Fin de lireEntree

//-------------------------------------------- Constructeurs - destructeur

Main::Main()
{} //----- Fin de Main


Main::~Main()
{} //----- Fin de ~Main

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées