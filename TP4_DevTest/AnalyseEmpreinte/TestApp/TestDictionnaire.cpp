#include "stdafx.h"
#include "CppUnitTest.h"
#include "Empreinte.h"
#include "Maladie.h"
#include "Fichier.h"
#include "Dictionnaire.h"
#include <string>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestApp
{
	TEST_CLASS(TestDictionnaire)
	{
	public:


		TEST_METHOD(AjouterMaladie)
		{
			string signature = "A1;string\nA2;double\nA3;double\nA4;double\nAZ51;double\nDisease;string";

			string champs1 = "1;True;2.12;13;3.156;12.36;Maladie1";
			string champs2 = "1;True;2.12;13;3.156;12.36;";
			string champs3 = "5;True;13;13;589;12.36;Maladie1";


			Dictionnaire * d = new Dictionnaire("fichier", signature);
			bool b1 = d->ajouterMaladie(champs1);
			bool b1bis = d->ajouterMaladie(champs1);
			bool b2 = d->ajouterMaladie(champs2);
			bool b3 = d->ajouterMaladie(champs3);


			deque<Maladie> list = d->getListeMaladie();
			Assert::IsTrue(!(list.empty()), L"Pas ajouter");
			Assert::IsTrue(b1, L"b1 ajouter");
			Assert::IsTrue(!b1bis, L"b1bis ajouter");
			Assert::IsTrue(b2, L"b2 pas ajouter");
			Assert::IsTrue(b3, L"b3 pas ajouter");
		}

		TEST_METHOD(GetMaladieById)
		{
			string signature = "A1;string\nA2;double\nA3;double\nA4;double\nAZ51;double\nDisease;string";

			string champs1 = "1;True;2.12;13;3.156;12.36;Maladie1";
			string champs2 = "5;True;13;13;589;12.36;Maladie2";


			Dictionnaire * d = new Dictionnaire("fichier", signature);
			d->ajouterMaladie(champs1);;
			d->ajouterMaladie(champs2);

			Maladie m1 = d->getMaladieById(1);
			Maladie m3 = d->getMaladieById(3);

			deque<Maladie> list = d->getListeMaladie();
			Assert::AreEqual(list[0].getIdMaladie(), m1.getIdMaladie());
			Assert::AreEqual(*(new long(0)), m3.getIdMaladie());//?
		}



	};


}