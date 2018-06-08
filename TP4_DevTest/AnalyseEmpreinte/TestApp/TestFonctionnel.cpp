#include "stdafx.h"
#include "CppUnitTest.h"
#include "Empreinte.h"
#include "Maladie.h"
#include "Fichier.h"
#include "FichierPatient.h"
#include "Dictionnaire.h"
#include "Main.h"
#include "Analyse.h"
#include "FichEmpStream.h"
#include <string>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestApp
{
	TEST_CLASS(TestFonctionnel)
	{
	public:

		TEST_METHOD(test1_1)
		{
			bool reussi = true;
			cout << "Un fichier “.txt” contenant une empreinte valide et un dictionnaire valide permettant d’obtenir 10 risques. " << endl;
			cout << " Un affichage par ordre décroissant des probabilités des 10 risques principaux détectés pour cette empreinte.x" << endl;
			FichEmpStream lecteur;
			Dictionnaire d;
			lecteur.lireDictionnaire(d, "./fichier_de_test/1.1/fichier_maladies.txt");
			FichierPatient fp = lecteur.lireFichierPatient("./fichier_de_test/1.1/fichier_empreintes_analyse_1.txt");

			Main m;

			deque<Analyse> lesAnalysesReel = fp.analyserEmpreinte(d);
			multimap<double, string> correspAttendue;
			correspAttendue.insert(pair<double, string>(100, "Maladie4"));
			correspAttendue.insert(pair<double, string>(100, "Maladie0"));
			correspAttendue.insert(pair<double, string>(80, "Maladie2"));
			correspAttendue.insert(pair<double, string>(50, "Maladie14"));
			correspAttendue.insert(pair<double, string>(40, "Maladie60"));
			correspAttendue.insert(pair<double, string>(40, "Maladie52"));
			correspAttendue.insert(pair<double, string>(40, "Maladie50"));
			correspAttendue.insert(pair<double, string>(40, "Maladie42"));
			correspAttendue.insert(pair<double, string>(40, "Maladie40"));
			correspAttendue.insert(pair<double, string>(40, "Maladie16"));

			for (deque<Analyse>::iterator it = lesAnalysesReel.begin(); it != lesAnalysesReel.end(); it++)
			{
				multimap<double, string> correspReel = m.retrouverResultat(*it, false);
				if (correspReel != correspAttendue)
				{
					reussi = false;
				}
			}

			Assert::IsTrue(reussi, L"Pas de correspondance entre les risques a afficher");

		}
		TEST_METHOD(test1_2)
		{
			Main main;
			FichEmpStream lecteur;
			Dictionnaire dico;
			lecteur.lireDictionnaire(dico, "./fichier_de_test/1.2/fichier_maladies.txt");
			FichierPatient fp = lecteur.lireFichierPatient("./fichier_de_test/1.2/fichier_empreintes_analyse_2.txt");

			deque<Analyse> lesAnalyseReel = fp.analyserEmpreinte(dico);
			multimap<double, string> correspAttendue;
			correspAttendue.insert(pair<double, string>(40, "Maladie16"));
			correspAttendue.insert(pair<double, string>(40, "Maladie14"));
			correspAttendue.insert(pair<double, string>(80, "Maladie2"));
			correspAttendue.insert(pair<double, string>(100, "Maladie42"));
			correspAttendue.insert(pair<double, string>(100, "Maladie40"));
			correspAttendue.insert(pair<double, string>(100, "Maladie27"));
			correspAttendue.insert(pair<double, string>(100, "Maladie26"));
			correspAttendue.insert(pair<double, string>(100, "Maladie23"));
			correspAttendue.insert(pair<double, string>(100, "Maladie4"));
			correspAttendue.insert(pair<double, string>(100, "Maladie0"));
			

			multimap<double, string> correspAttendue2;
			correspAttendue2.insert(pair<double, string>(30, "Maladie2"));
			correspAttendue2.insert(pair<double, string>(40, "Maladie60"));
			correspAttendue2.insert(pair<double, string>(40, "Maladie52"));
			correspAttendue2.insert(pair<double, string>(40, "Maladie50"));
			correspAttendue2.insert(pair<double, string>(100, "Maladie21"));
			correspAttendue2.insert(pair<double, string>(100, "Maladie20"));
			correspAttendue2.insert(pair<double, string>(100, "Maladie19"));
			correspAttendue2.insert(pair<double, string>(100, "Maladie18"));
			correspAttendue2.insert(pair<double, string>(100, "Maladie17"));
			correspAttendue2.insert(pair<double, string>(100, "Maladie8"));
			
			deque<multimap<double, string>> lesAnalyseTheorique;
			lesAnalyseTheorique.push_back(correspAttendue);
			lesAnalyseTheorique.push_back(correspAttendue2);
			bool success = true;

			multimap<double, string> resultatReel;
			int i = 0;
			for (deque<Analyse>::iterator it = lesAnalyseReel.begin(); it != lesAnalyseReel.end(); ++it)
			{
				resultatReel = main.retrouverResultat(*it, false);
				if (lesAnalyseTheorique[i] != resultatReel)
				{
					success = false;
					break;
				}
				i++;
			}


			Assert::IsTrue(success);

		}

		TEST_METHOD(test1_3)
		{
			Main main;
			FichEmpStream fstream;

			Dictionnaire dico;
			//*dico = fstream->lireDictionnaire(*dico, "DataMaladie.txt");
			fstream.lireDictionnaire(dico, "./fichier_de_test/1.3/fichier_maladies_5.txt");

			FichierPatient fp;
			//*fp = fstream->lireFichierPatient("DataEmp.txt");
			fp = fstream.lireFichierPatient("./fichier_de_test/1.3/fichier_empreintes_analyse_1.txt");

			deque<Analyse> lesAnalyseReel = fp.analyserEmpreinte(dico);
			multimap<double, string> resultat;
			resultat.insert(pair<double, string>(35, "Maladie1"));
			resultat.insert(pair<double, string>(100, "Maladie5"));
			bool success = false;

			multimap<double, string> resultatReel;
			for (deque<Analyse>::iterator it = lesAnalyseReel.begin(); it != lesAnalyseReel.end(); ++it)
			{
				
				resultatReel = main.retrouverResultat(*it, false);
			}

			if (resultat == resultatReel)
			{
				success = true;
			}

			
			Assert::IsTrue(success);




		}

		TEST_METHOD(test1_4)
		{

			Main main;
			FichEmpStream fstream;

			Dictionnaire dico;
			//*dico = fstream->lireDictionnaire(*dico, "DataMaladie.txt");
			fstream.lireDictionnaire(dico, "./fichier_de_test/1.4/fichier_maladies_5.txt");

			FichierPatient fp;
			//*fp = fstream->lireFichierPatient("DataEmp.txt");
			fp = fstream.lireFichierPatient("./fichier_de_test/1.4/fichier_empreintes_analyse_3.txt");

			deque<Analyse> lesAnalyseReel = fp.analyserEmpreinte(dico);
			multimap<double, string> resultat1;
			resultat1.insert(pair<double, string>(85, "Maladie0"));
			resultat1.insert(pair<double, string>(90, "Maladie7"));

			multimap<double, string> resultat2;
			resultat2.insert(pair<double, string>(95, "Maladie6"));
			
			multimap<double, string> resultat3;
			resultat3.insert(pair<double, string>(90, "Maladie5"));

			deque<multimap<double, string>> lesAnalyseTheorique;
			lesAnalyseTheorique.push_back(resultat1);
			lesAnalyseTheorique.push_back(resultat2);
			lesAnalyseTheorique.push_back(resultat3);
			bool success = true;

			multimap<double, string> resultatReel;
			int i = 0;
			for (deque<Analyse>::iterator it = lesAnalyseReel.begin(); it != lesAnalyseReel.end(); ++it)
			{
				resultatReel = main.retrouverResultat(*it, false);
				if (lesAnalyseTheorique[i] != resultatReel)
				{
					success = false;
					break;
				}
				i++;
			}


			Assert::IsTrue(success);
		}

		TEST_METHOD(test1_5)
		{
			Main main;
			FichEmpStream fstream;

			Dictionnaire dico;
			//*dico = fstream->lireDictionnaire(*dico, "DataMaladie.txt");
			fstream.lireDictionnaire(dico, "./fichier_de_test/1.5/fichier_maladies_20.txt");

			FichierPatient fp;
			//*fp = fstream->lireFichierPatient("DataEmp.txt");
			fp = fstream.lireFichierPatient("./fichier_de_test/1.5/fichier_empreintes_analyse_1.txt");

			deque<Analyse> lesAnalyseReel = fp.analyserEmpreinte(dico);
			multimap<double, string> resultat;
			bool success = false;

			multimap<double, string> resultatReel;
			for (deque<Analyse>::iterator it = lesAnalyseReel.begin(); it != lesAnalyseReel.end(); ++it)
			{

				resultatReel = main.retrouverResultat(*it, false);
			}

			if (resultat == resultatReel)
			{
				success = true;
			}


			Assert::IsTrue(success);
		}

		TEST_METHOD(test1_6)
		{
			Main main;
			FichEmpStream fstream;

			Dictionnaire dico;
			//*dico = fstream->lireDictionnaire(*dico, "DataMaladie.txt");
			fstream.lireDictionnaire(dico, "./fichier_de_test/1.6/fichier_maladies_20.txt");

			FichierPatient fp;
			//*fp = fstream->lireFichierPatient("DataEmp.txt");
			fp = fstream.lireFichierPatient("./fichier_de_test/1.6/fichier_empreintes_analyse_1.txt");

			deque<Analyse> lesAnalyseReel = fp.analyserEmpreinte(dico);
			multimap<double, string> resultat;
			resultat.insert(pair<double, string>(50, "Maladie23"));
			resultat.insert(pair<double, string>(50, "Maladie22"));
			resultat.insert(pair<double, string>(50, "Maladie21"));
			resultat.insert(pair<double, string>(50, "Maladie19"));
			resultat.insert(pair<double, string>(50, "Maladie5"));
			resultat.insert(pair<double, string>(50, "Maladie4"));
			resultat.insert(pair<double, string>(50, "Maladie3"));
			resultat.insert(pair<double, string>(50, "Maladie2"));
			resultat.insert(pair<double, string>(100, "Maladie24"));
			resultat.insert(pair<double, string>(100, "Maladie1"));
			resultat.insert(pair<double, string>(100, "Maladie0"));
			bool success = false;

			multimap<double, string> resultatReel;
			for (deque<Analyse>::iterator it = lesAnalyseReel.begin(); it != lesAnalyseReel.end(); ++it)
			{

				resultatReel = main.retrouverResultat(*it, false);
			}

			if (resultat == resultatReel)
			{
				success = true;
			}


			Assert::IsTrue(success);

		}

		TEST_METHOD(test1_7)
		{
			Main main;
			FichEmpStream fstream;

			Dictionnaire dico;
			//*dico = fstream->lireDictionnaire(*dico, "DataMaladie.txt");
			fstream.lireDictionnaire(dico, "./fichier_de_test/1.7/fichier_maladies_20.txt");

			Maladie * mAttendue = new Maladie(7, "Maladie6");
			mAttendue->ajouterEmpreinte("59;blue;10;red;11;medium;0.55;blue;45.5;blue;11;medium;7;medium;23445;cold;20.7;hot;7;hot;20.7",dico.getSignature());
			Maladie * mReel = new Maladie;
			*mReel = dico.getMaladieById(7);

			deque<Empreinte> listEmpAttendu = mAttendue->getListeEmpreinte();
			deque<Empreinte> listEmpReel = mReel->getListeEmpreinte();


			Assert::AreEqual(mAttendue->getIdMaladie(), mReel->getIdMaladie());
			Assert::AreEqual(listEmpAttendu.size(), listEmpReel.size());
			
		}

		TEST_METHOD(test1_8)
		{
			Main main;
			FichEmpStream fstream;

			Dictionnaire dico;
			//*dico = fstream->lireDictionnaire(*dico, "DataMaladie.txt");
			fstream.lireDictionnaire(dico, "./fichier_de_test/1.8/fichier_maladies_20.txt");

			Maladie * mAttendue = new Maladie(1, "Maladie1");
			mAttendue->ajouterEmpreinte("1;danger;9;true;9;false;7;false;10;true;20.7;red;1234;cold;0.55;blue;23445;true;23;danger;23445", dico.getSignature());
			mAttendue->ajouterEmpreinte("6;cold;11;cold;7;red;11;danger;11;false;7;blue;1234;hot;20.7;hot;10;none;23;red;23", dico.getSignature());
			mAttendue->ajouterEmpreinte("7;true;7;false;1234;false;7;false;9;none;45.5;safe;10;none;11;hot;45.5;safe;45.5;cold;20.7", dico.getSignature());
			mAttendue->ajouterEmpreinte("8;red;20.7;blue;20.7;medium;20.7;cold;10;danger;20.7;none;23;red;23445;red;10;medium;10;blue;45.5", dico.getSignature());
			mAttendue->ajouterEmpreinte("9;false;9;true;11;hot;11;medium;11;red;10;blue;9;none;0.55;false;7;true;23;medium;0.55", dico.getSignature());
			mAttendue->ajouterEmpreinte("15;true;9;medium;45.5;false;7;hot;23;cold;11;safe;20.7;hot;23;hot;45.5;hot;11;medium;45.5;", dico.getSignature());
			


			Maladie * mReel = new Maladie;
			*mReel = dico.getMaladieById(1);

			deque<Empreinte> listEmpAttendu = mAttendue->getListeEmpreinte();
			deque<Empreinte> listEmpReel = mReel->getListeEmpreinte();


			Assert::AreEqual(mAttendue->getIdMaladie(), mReel->getIdMaladie());
			Assert::AreEqual(listEmpAttendu.size(), listEmpReel.size());
		}

		TEST_METHOD(test1_9)
		{
			Main main;
			FichEmpStream fstream;

			Dictionnaire dico;
			//*dico = fstream->lireDictionnaire(*dico, "DataMaladie.txt");
			fstream.lireDictionnaire(dico, "./fichier_de_test/1.9/fichier_maladies_5.txt");

			Maladie * mAttendue = new Maladie(0,"");



			Maladie * mReel = new Maladie;
			*mReel = dico.getMaladieById(41);

			deque<Empreinte> listEmpAttendu = mAttendue->getListeEmpreinte();
			deque<Empreinte> listEmpReel = mReel->getListeEmpreinte();


			Assert::AreEqual(mAttendue->getIdMaladie(), mReel->getIdMaladie());
			Assert::AreEqual(listEmpAttendu.size(), listEmpReel.size());
		}

		TEST_METHOD(test1_11)
		{
			Main main;
			FichEmpStream fstream;

			Dictionnaire dico;
			//*dico = fstream->lireDictionnaire(*dico, "DataMaladie.txt");
			fstream.lireDictionnaire(dico, "./fichier_de_test/1.11/fichier_maladies_20.txt");

			FichierPatient fp;
			//*fp = fstream->lireFichierPatient("DataEmp.txt");
			fp = fstream.lireFichierPatient("./fichier_de_test/1.11/fichier_empreintes_analyse_1.txt");

			deque<Analyse> lesAnalyseReel = fp.analyserEmpreinte(dico);
			multimap<double, string> resultat;
			resultat.insert(pair<double, string>(92, "Maladie18"));
			bool success = false;

			multimap<double, string> resultatReel;
			for (deque<Analyse>::iterator it = lesAnalyseReel.begin(); it != lesAnalyseReel.end(); ++it)
			{

				resultatReel = main.retrouverResultat(*it, true);
			}

			if (resultat == resultatReel)
			{
				success = true;
			}


			Assert::IsTrue(success);
		}

		TEST_METHOD(test1_12)
		{
			Main main;
			FichEmpStream fstream;

			Dictionnaire dico;
			//*dico = fstream->lireDictionnaire(*dico, "DataMaladie.txt");
			fstream.lireDictionnaire(dico, "./fichier_de_test/1.12/fichier_maladies_30.txt");

			FichierPatient fp;
			//*fp = fstream->lireFichierPatient("DataEmp.txt");
			fp = fstream.lireFichierPatient("./fichier_de_test/1.12/fichier_empreintes_analyse_1.txt");

			deque<Analyse> lesAnalyseReel = fp.analyserEmpreinte(dico);
			multimap<double, string> resultat;
			resultat.insert(pair<double, string>(100, "Maladie6"));
			resultat.insert(pair<double, string>(100, "Maladie5"));
			bool success = false;

			multimap<double, string> resultatReel;
			for (deque<Analyse>::iterator it = lesAnalyseReel.begin(); it != lesAnalyseReel.end(); ++it)
			{

				resultatReel = main.retrouverResultat(*it, true);
			}

			if (resultat == resultatReel)
			{
				success = true;
			}


			Assert::IsTrue(success);
		}

		TEST_METHOD(test1_13)
		{
			Main main;
			FichEmpStream fstream;

			Dictionnaire dico;
			fstream.lireDictionnaire(dico, "./fichier_de_test/1.13/fichier_maladies_2.txt");
			FichierPatient fp;
			fp = fstream.lireFichierPatient("./fichier_de_test/1.13/fichier_empreintes_analyse_1.txt");

			deque<Analyse> lesAnalyseReel = fp.analyserEmpreinte(dico);
			multimap<double, string> resultat;
			bool success = false;

			multimap<double, string> resultatReel;
			int nbMaladie;
			for (deque<Analyse>::iterator it = lesAnalyseReel.begin(); it != lesAnalyseReel.end(); ++it)
			{

				resultatReel = main.retrouverResultat(*it, true);
				nbMaladie = it->getCorrespondances().size();
			}

			if (resultat == resultatReel)
			{
				success = true;
			}

			
			Assert::IsTrue(success);
			Assert::AreEqual(2, nbMaladie);

		}

		TEST_METHOD(test1_18)
		{
			bool reussi = false;
			cout << "Un dictionnaire non valide en entrée (extension différente de celle attendue). " << endl;
			cout << "Retourne une erreur précisant que l’extension du dictionnaire rentrée est invalide. " << endl;
			FichEmpStream lecteur;
			Dictionnaire d;
			deque<Maladie> avant = d.getListeMaladie();

			lecteur.lireDictionnaire(d, "./fichier_de_test/1.18/fichier_maladies.json");
			deque<Maladie> apres = d.getListeMaladie();
			if (avant.size() == apres.size()) {
				Assert::IsTrue(true);
			}
			else {
				Assert::IsTrue(false);
			}
		}
		TEST_METHOD(test1_19)
		{
			bool reussi = false;
			cout << "Un fichier d’empreinte à analyser non valide (extension différente de celle attendue) et un dictionnaire valide en entrée. " << endl;
			cout << "Retourne une erreur précisant que l’extension du fichier censé contenir le ou les empreintes est invalide. " << endl;
			FichEmpStream lecteur;
			Dictionnaire d;
			lecteur.lireDictionnaire(d, "./ft/1.19/fichier_maladies.txt");
			FichierPatient fp;
			deque<Empreinte> avant = fp.getListeEmpreinte();

			fp = lecteur.lireFichierPatient("./ft/1.19/fichier_empreintes.json");

			deque<Empreinte> apres = fp.getListeEmpreinte();

			if (avant.size() == apres.size()) {
				Assert::IsTrue(true);
			}
			else {
				Assert::IsTrue(false);
			}
		}

		TEST_METHOD(test1_20)
		{
			bool reussi = false;
			cout << "Un fichier “.txt” non valide (fichier vide) et un dictionnaire valide. " << endl;
			cout << "Message d’erreur affiché : « Aucune empreinte à analyser dans le fichier donné. » " << endl;
			FichEmpStream lecteur;
			Dictionnaire d;
			lecteur.lireDictionnaire(d, "./ft/1.20/fichier_maladies_10.txt");
			FichierPatient fp;
			fp = lecteur.lireFichierPatient("./ft/1.20/fichier_empreintes_analyse_0.txt");

			deque<Empreinte> empreintes = fp.getListeEmpreinte();

			if (empreintes.size() == 0) 
			{
				Assert::IsTrue(true);
			}
			else {
				Assert::IsTrue(false);
			}
		}

		

	};

	
}
