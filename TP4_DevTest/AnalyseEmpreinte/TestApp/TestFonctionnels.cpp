#include "stdafx.h"
#include "CppUnitTest.h"
#include "FichierPatient.h"
#include "FichEmpStream.h"
#include "Dictionnaire.h"
#include "main.cpp"
#include "Analyse.h"
#include <string>
#include <iostream>
#include <map>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestApp
{
	TEST_CLASS(TestFonctionnel)
	{
	public:
		TEST_METHOD(test1_1)
		{
			bool reussi = false;
			cout << "Un fichier “.txt” contenant une empreinte valide et un dictionnaire valide permettant d’obtenir 10 risques. " << endl;
			cout << " Un affichage par ordre décroissant des probabilités des 10 risques principaux détectés pour cette empreinte.x" << endl;
			FichEmpStream *lecteur = new FichEmpStream;
			FichierPatient fp = lecteur->lireFichierPatient("./fichier_de_test/test1_1_f.txt");
			Dictionnaire d;
			d = lecteur->lireDictionnaire(d, "./fichier_de_test/test1_1_d.txt");

			deque<Analyse> lesAnalysesReel = fp.analyserEmpreinte(d);

			for (deque<Analyse>::iterator it = lesAnalysesReel.begin(); it != lesAnalysesReel.end(); it++) {
				multimap<double, string> corresp = retrouverResultat(*it,false):
			}

			Assert::IsTrue(reussi);

		}
		TEST_METHOD(test1_2)
		{
			bool reussi = false;
			cout << "Un fichier “.txt” contenant plusieurs empreintes valides et un dictionnaire valide permettant d’obtenir 10 risques pour chaque empreinte. "<<endl;
			cout << "\n>> Un affichage par ordre décroissant des probabilités des 10 risques principaux détectés pour chaque empreinte.\n" << endl;
			FichEmpStream *lecteur = new FichEmpStream;
			FichierPatient fp = lecteur->lireFichierPatient("./fichier_de_test/test1_2_f.txt");
			Dictionnaire d;
			d = lecteur->lireDictionnaire(d, "./fichier_de_test/test1_2_d.txt");

			deque<Analyse> lesAnalysesReel = fp.analyserEmpreinte(d);
			deque<Analyse> lesAnalysesTheorique = fp.analyserEmpreinte(d);
			multimap<double, string> correspondancesTheorique;


			//ajout a la main les corresp theorique
			for (int i = 0; i < 10; i++) {
				correspondancesTheorique.insert(pair<double, string>(1.0, "maladie"));
			}
			//idEmpreinteTheorique
			long idEmpreinteTheorique = 1;
			
			//creation de analyseTheorique et mettre a jour
			Analyse analyseTheorique;
			analyseTheorique.setIdEmpreinte(idEmpreinteTheorique);
			analyseTheorique.setCorrespondances(correspondancesTheorique);

			//ajout de analyseTheorique a lesAnalysesTheorique
			lesAnalysesTheorique.push_back(analyseTheorique);

			if (lesAnalysesTheorique == lesAnalysesReel)
				reussi = true;

			Assert::IsTrue(reussi);

		}
		TEST_METHOD(UnEmpMoins10Risque)
		{
			bool reussi = false;
			string desc = "Un fichier “.txt” contenant une empreinte valide et un dictionnaire valide permettant d’obtenir au moins un risque mais moins de 10 risques. ";
			desc += "\n>> Un affichage par ordre décroissant des probabilités des risques détectés pour cette empreinte (nombre de risque entre 0 et 10).\n";
			cout << desc << endl;
			FichEmpStream *lecteur = new FichEmpStream;
			FichierPatient fp = lecteur->lireFichierPatient("UnEmpMoins10Risque2.txt");
			Dictionnaire *d = new Dictionnaire;
			*d = lecteur->lireDictionnaire(*d, "UnEmpMoins10Risque.txt");

			deque<Analyse> lesAnalyses = fp.analyserEmpreinte(*d);
			for (deque<Analyse>::iterator it = lesAnalyses.begin(); it != lesAnalyses.end(); it++)
			{
				multimap<double, string> resultat = it->getCorrespondances();
				int compteur = 0;
				// On fait ça pour stocker la dixième valeur et pour gérer le cas d'égalité
				double proba10;
				if (resultat.size() > 10)
				{
					multimap<double, string>::reverse_iterator it3 = resultat.rbegin();
					advance(it3, 9);
					proba10 = it3->first;
				}
				else {
					reussi = false;
				}

				for (multimap<double, string>::reverse_iterator it2 = resultat.rbegin(); it2 != resultat.rend(); it2++)
				{
					if (it2->first > 20)
					{
						compteur++;
						if (compteur >= 10)
						{
							reussi = false;
							break;
						}
						else if (compteur<10) {
							reussi = true;
						}
					}
					else
					{
						reussi = false;
						//cout << "Aucun risque de maladie détecté à partir des informations contenues dans notre unité de stockage." << endl;
					}
				}
			}
			Assert::IsTrue(reussi);

		}
		TEST_METHOD(PlusieursEmpMoins10Risque)
		{
			bool reussi = false;
			string desc = "Un fichier “.txt” contenant plusieurs empreintes valides et un dictionnaire valide permettant d’obtenir moins de 10 risques pour chaque empreinte. ";
			desc += "\n>> Un affichage par ordre décroissant de probabilité des risques détectés pour chaque empreinte(nombre de risque entre 0 et 10), pour chaque empreinte.\n";
			cout << desc << endl;
			FichEmpStream *lecteur = new FichEmpStream;
			FichierPatient fp = lecteur->lireFichierPatient("PlusieursEmpMoins10Risque2.txt");
			Dictionnaire *d = new Dictionnaire;
			*d = lecteur->lireDictionnaire(*d, "PlusieursEmpMoins10Risque.txt");

			deque<Analyse> lesAnalyses = fp.analyserEmpreinte(*d);
			for (deque<Analyse>::iterator it = lesAnalyses.begin(); it != lesAnalyses.end(); it++)
			{
				multimap<double, string> resultat = it->getCorrespondances();
				int compteur = 0;
				// On fait ça pour stocker la dixième valeur et pour gérer le cas d'égalité
				double proba10;
				if (resultat.size() > 10)
				{
					multimap<double, string>::reverse_iterator it3 = resultat.rbegin();
					advance(it3, 9);
					proba10 = it3->first;
				}

				for (multimap<double, string>::reverse_iterator it2 = resultat.rbegin(); it2 != resultat.rend(); it2++)
				{
					if (it2->first > 20)
					{
						compteur++;
						if (compteur >= 10)
						{
							reussi = false;
							Assert::IsTrue(reussi);// on fait ça si on passe pour une empreinte c est faux...
							break;
						}
						else if (compteur<10) {
							reussi = true;
						}
					}
					else
					{
						reussi = false;
						//cout << "Aucun risque de maladie détecté à partir des informations contenues dans notre unité de stockage." << endl;
					}
				}
			}
			Assert::IsTrue(reussi);
		}
		TEST_METHOD(UnEmpNonRisque)
		{
			bool reussi = false;
			string desc = "Un fichier “.txt” contenant une empreinte valide et un dictionnaire valide permettant d’obtenir 0 risque de maladie correspondant à l’empreinte. ";
			desc += "\n>> Aucun risque n’est affiché, seulement la phrase d’indication : « Aucun risque de maladie détecté à partir des informations contenues dans notre unité de stockage »\n";
			cout << desc << endl;
			FichEmpStream *lecteur = new FichEmpStream;
			FichierPatient fp = lecteur->lireFichierPatient("UnEmpNonRisque2.txt");
			Dictionnaire *d = new Dictionnaire;
			*d = lecteur->lireDictionnaire(*d, "UnEmpNonRisque.txt");

			deque<Analyse> lesAnalyses = fp.analyserEmpreinte(*d);
			for (deque<Analyse>::iterator it = lesAnalyses.begin(); it != lesAnalyses.end(); it++)
			{
				multimap<double, string> resultat = it->getCorrespondances();
				int compteur = 0;
				// On fait ça pour stocker la dixième valeur et pour gérer le cas d'égalité
				double proba10;
				if (resultat.size() > 10)
				{
					multimap<double, string>::reverse_iterator it3 = resultat.rbegin();
					advance(it3, 9);
					proba10 = it3->first;
				}

				for (multimap<double, string>::reverse_iterator it2 = resultat.rbegin(); it2 != resultat.rend(); it2++)
				{
					if (it2->first > 20)
					{

						reussi = false;
						break;
					}
					else
					{
						reussi = true;
						break;
						//cout << "Aucun risque de maladie détecté à partir des informations contenues dans notre unité de stockage." << endl;
					}
				}
			}
			Assert::IsTrue(reussi);
		}
		TEST_METHOD(UnEmpPlusDe10Risque)
		{
			bool reussi = false;
			string desc = "Un fichier “.txt” contenant une empreinte valide et un dictionnaire valide permettant d’obtenir une égalité et par conséquent, plus de 10 risques de maladie correspondant à l’empreinte. ";
			desc += "\n>> Un affichage par ordre décroissant de probabilité de plus de 10 risques.\n";
			cout << desc << endl;
			FichEmpStream *lecteur = new FichEmpStream;
			FichierPatient fp = lecteur->lireFichierPatient("UnEmpPlusDe10Risque2.txt");
			Dictionnaire *d = new Dictionnaire;
			*d = lecteur->lireDictionnaire(*d, "UnEmpPlusDe10Risque.txt");

			deque<Analyse> lesAnalyses = fp.analyserEmpreinte(*d);
			for (deque<Analyse>::iterator it = lesAnalyses.begin(); it != lesAnalyses.end(); it++)
			{
				multimap<double, string> resultat = it->getCorrespondances();
				int compteur = 0;
				// On fait ça pour stocker la dixième valeur et pour gérer le cas d'égalité
				double proba10;
				if (resultat.size() > 10)
				{
					multimap<double, string>::reverse_iterator it3 = resultat.rbegin();
					advance(it3, 9);
					proba10 = it3->first;
				}
				else {
					reussi = false;
				}

				for (multimap<double, string>::reverse_iterator it2 = resultat.rbegin(); it2 != resultat.rend(); it2++)
				{
					if (it2->first > 20)
					{
						compteur++;
						if (compteur >= 10)
						{
							reussi = true;
							Assert::IsTrue(reussi);// on fait ça si on passe pour une empreinte c est faux...
						}
						else if (compteur<10) {
							reussi = false;
						}
					}
					else
					{
						reussi = false;
						break;
						//cout << "Aucun risque de maladie détecté à partir des informations contenues dans notre unité de stockage." << endl;
					}
				}
			}
			Assert::IsTrue(reussi);

		}
	};
}
