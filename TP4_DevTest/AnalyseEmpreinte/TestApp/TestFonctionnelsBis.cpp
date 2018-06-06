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

			Dictionnaire dico = fstream->lireDictionnaire("Data");
			FichierPatient fp = fstream->lireFichierPatient("Data");

			deque<Analyse> analyseAttendu;
			deque<Analyse> resultat;
			resultat = fp.analyserEmpreinte();

			Assert::AreEqual(analyseAttendu, resultat);




		}
}
