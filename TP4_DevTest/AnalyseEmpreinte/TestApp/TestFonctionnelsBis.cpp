#include "stdafx.h"
#include "CppUnitTest.h"
#include "FichierPatient.h"
#include "FichEmpStream.h"
#include "Dictionnaire.h"
#include "Analyse.h"
#include "FichEmpStream.h"
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
			FichEmpStream * fstream = new FichEmpStream();

			Dictionnaire dico = fstream->lireDictionnaire(dico, "./fichier_de_test/1.3/fichier_maladies_5.txt");
			FichierPatient fp = fstream->lireFichierPatient("./fichier_de_test/1.3/fichier_empreintes_analyse_1.txt");

			deque<Analyse> lesAnalyseReel;
			
			resultat = fp.analyserEmpreinte(dico);

			Assert::AreEqual(analyseAttendu, resultat);




		}
}
