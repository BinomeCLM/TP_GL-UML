#include "stdafx.h"
#include "CppUnitTest.h"
#include "FichierPatient.h"
#include "Dictionnaire.h"
#include <string>
#include <iostream>
#include <map>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestApp
{
	TEST_CLASS(TestAnalyse)
	{
	public:
		TEST_METHOD(CalculerProbabilite)
		{
			string signature = "A1;double\nA2;string\nA3;string\nA4;double\nAZ51;string\n";

			string champs1 = "1;12;True;rouge;39;ventre";
			string champs2 = "12;14;False;rouge;39;ventre;Maladie";
			string champs3 = "13;12;True;rouge;39;t�te;Maladie";


			FichierPatient * fp = new FichierPatient("fichier", signature);
			
			fp->ajouterEmpreinte(champs1);
			deque<Empreinte> listFP = fp->getListeEmpreinte();

			Maladie * m1= new Maladie(1, "grippe");
			m1->ajouterEmpreinte(champs2, fp->getSignature());

			Maladie * m2 = new Maladie(2, "rhume");
			m2->ajouterEmpreinte(champs2,fp->getSignature());
			m2->ajouterEmpreinte(champs3,fp->getSignature());

			Analyse * analyse1 = new Analyse(1);
			analyse1->calculerProbabilite(listFP[0], *m1);
		

			Analyse * analyse2 = new Analyse(1);
			analyse2->calculerProbabilite(listFP[0], *m2);

			multimap<double, string> res1 = analyse1->getCorrespondances();
			multimap<double, string> res2 = analyse2->getCorrespondances();

			Assert::AreEqual(pair<double, string>(60.0, "grippe").first, (*(res1.find(60) )).first,L"1");
			Assert::AreEqual(pair<double, string>(60.0, "grippe").second, (*(res1.find(60))).second, L"2");
			Assert::AreEqual(pair<double, string>(80.0, "rhume").first, (*(res2.find(80))).first, L"3");
			Assert::AreEqual(pair<double, string>(80.0, "rhume").second, (*(res2.find(80))).second, L"4");
	

		}

		TEST_METHOD(GenererClassement)
		{

			string signature = "A1;string\nA2;double\nA3;double\nA4;double\nAZ51;double\nDisease;string";

			string champs1 = "1;True;2.12;13;3.156;12.36;Maladie1";
			string champs2 = "5;True;13;13;589;12.36;Maladie2";
			string champs3 = "12;False;14;0;14;7;Maladie3";
			string champs4 = "8;True;4;7;8;7;Maladie1";
			string champsEmp = "7;True;2.12;13;3.15;7";

			Dictionnaire * d = new Dictionnaire("fichier", signature);
			d->ajouterMaladie(champs1);
			d->ajouterMaladie(champs2);
			d->ajouterMaladie(champs3);
			d->ajouterMaladie(champs4);

			FichierPatient * fp = new FichierPatient("fichier", signature);
			fp->ajouterEmpreinte(champsEmp);
			deque<Empreinte> listFP = fp->getListeEmpreinte();
			Empreinte e = listFP[0];

			Analyse * analyse = new Analyse(7);
			analyse->genererClassement(*d, e);

			multimap<double, string> calcul;
			calcul.insert(pair<double, string>(60, "Maladie1"));
			calcul.insert(pair<double, string>(40, "Maladie2"));
			calcul.insert(pair<double, string>(20, "Maladie3"));

			multimap<double, string> res = analyse->getCorrespondances();

			Assert::IsTrue(res == calcul);



		}
	};
}
