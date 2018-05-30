#include "stdafx.h"
#include "CppUnitTest.h"
#include "Empreinte.h"
#include "Maladie.h"
#include "Fichier.h"
#include <string>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestApp
{
	TEST_CLASS(TestMaladie)
	{
	public:

		TEST_METHOD(AjouterEmpreinte)
		{
			string signature = "A1;string\nA2;double\nA3;double\nA4;double\nAZ51;double";
			Fichier* f = new Fichier("if", signature);
			Maladie * m = new Maladie(1, "grippe");
			string champs1 = "1;True;2.12;13;3.156;1236;Maladie1";
			string champs2 = "2;True;41;13;3.156;1236;Maladie2";
			bool b1 = m->ajouterEmpreinte(champs1,f->getSignature());
			bool b2 = m->ajouterEmpreinte(champs1, f->getSignature());
			bool b3 = m->ajouterEmpreinte(champs2, f->getSignature());

			
			deque<Empreinte> list = m->getListeEmpreinte();
			

			Assert::IsTrue(!(list.empty()),L"Pas ajouter");
			Assert::IsTrue(b1, L"b1 ajouter");
			Assert::IsTrue(!b2, L"b2 ajouter");

		}

		TEST_METHOD(GetEmpreinteById)
		{
			string signature = "A1;string\nA2;double\nA3;double\nA4;double\nAZ51;double";
			Fichier* f = new Fichier("if", signature);
			Maladie * m = new Maladie(1, "Maladie1");
			string champs1 = "1;True;2.12;13;3.156;1236;Maladie1";
			string champs2 = "2;True;9;13;3.156;1236;Maladie1";
			bool b1 = m->ajouterEmpreinte(champs1, f->getSignature());
			bool b2 = m->ajouterEmpreinte(champs2, f->getSignature());

			Empreinte e1 = m->getEmpreinteById(1);
			Empreinte e3 = m->getEmpreinteById(3);

			deque<Empreinte> list = m->getListeEmpreinte();
			Assert::AreEqual(list[0].getIdEmpreinte(), e1.getIdEmpreinte());
			Assert::AreEqual(*(new long(0)), e3.getIdEmpreinte()); //tester que id vaut 0 ----> modifier TP et 2
		}

		
	};


}
