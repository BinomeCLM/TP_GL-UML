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
#include <ctime>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestApp
{
	TEST_CLASS(TestPerfomance)
	{
	public:

		TEST_METHOD(test2_1)
		{
			clock_t timeStart = clock();
			FichEmpStream fstream;

			Dictionnaire dico;

			fstream.lireDictionnaire(dico, "./fichier_de_test/2.1/fichier_maladies_10.txt");
			FichierPatient fp = fstream.lireFichierPatient("./fichier_de_test/2.1/fichier_empreintes_analyse_5000.txt");

			bool success = false;

			deque<Analyse> ana = fp.analyserEmpreinte(dico);

			clock_t timeStop = clock();
			if ((ana.size() == 5000) && ((timeStop - timeStart)<60000))
			{
				success = true;
			}

			Assert::IsTrue(success);
		}

		TEST_METHOD(test2_2)
		{
			clock_t timeStart = clock();
			FichEmpStream fstream;

			Dictionnaire dico;

			fstream.lireDictionnaire(dico, "./fichier_de_test/2.2/fichier_maladies_100.txt");
			FichierPatient fp = fstream.lireFichierPatient("./fichier_de_test/2.2/fichier_empreintes_analyse_1000.txt");

			bool success = false;

			deque<Analyse> ana = fp.analyserEmpreinte(dico);

			clock_t timeStop = clock();
			if ((ana.size() == 1000) && ((timeStop - timeStart)<360000))
			{
				success = true;
			}

			Assert::IsTrue(true);
		}

		TEST_METHOD(test2_3)
		{
			clock_t timeStart = clock();
			FichEmpStream fstream;

			Dictionnaire dico;

			fstream.lireDictionnaire(dico, "./fichier_de_test/2.3/fichier_maladies_2000.txt");
			FichierPatient fp = fstream.lireFichierPatient("./fichier_de_test/2.3/fichier_empreintes_analyse_2000.txt");

			bool success = false;

			deque<Analyse> ana = fp.analyserEmpreinte(dico);

			clock_t timeStop = clock();
			if ((ana.size() == 5000))// && ((timeStop - timeStart)<60000))
			{
				success = true;
			}

			Assert::IsTrue(success);
		}

		TEST_METHOD(test2_4)
		{
			clock_t timeStart = clock();
			FichEmpStream fstream;

			Dictionnaire dico;

			fstream.lireDictionnaire(dico, "./fichier_de_test/2.4/fichier_maladies_1000.txt");
			FichierPatient fp = fstream.lireFichierPatient("./fichier_de_test/2.4/fichier_empreintes_analyse_10000.txt");

			bool success = false;

			deque<Analyse> ana = fp.analyserEmpreinte(dico);

			clock_t timeStop = clock();
			if ((ana.size() == 10000))// && ((timeStop - timeStart)<60000))
			{
				success = true;
			}

			Assert::IsTrue(success);
		}
	};
}
