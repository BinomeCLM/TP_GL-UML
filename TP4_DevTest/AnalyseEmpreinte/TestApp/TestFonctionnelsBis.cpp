#include "stdafx.h"
#include "CppUnitTest.h"
#include "Main.h"
#include <string>
#include <iostream>
#include <map>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestApp
{
	TEST_CLASS(TestFonctionnel)
	{
	public:
		TEST_METHOD(test1_3)
		{
			Main main;
			FichEmpStream * fstream = new FichEmpStream();

			Dictionnaire dico = fstream->lireDictionnaire(dico, "./fichier_de_test/1.3/fichier_maladies_5.txt");
			FichierPatient fp = fstream->lireFichierPatient("./fichier_de_test/1.3/fichier_empreintes_analyse_1.txt");

			deque<Analyse> lesAnalyseReel = fp.analyserEmpreinte(dico);
			multimap<double, string> resultat;
			resultat.insert(pair<double, string>(100, "Maladie6"));
			resultat.insert(pair<double, string>(35, "Maladie1"));

			bool success;
			if (resultat == main.retrouverResultat(lesAnalyseReel[0],false))
			{
				success = true;
			}
			Assert::IsTrue(success);




		}
	};
}
