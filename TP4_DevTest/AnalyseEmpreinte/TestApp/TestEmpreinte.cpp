#include "stdafx.h"
#include "CppUnitTest.h"
#include "Empreinte.h"
#include "Attribut.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestApp
{		
	TEST_CLASS(TestEmpreinte)
	{
	public:
		
		TEST_METHOD(AjouterAttribut)
		{
			Empreinte * emp = new Empreinte(1);
			Attribut* A = new Attribut("att", "double");
			Attribut* B = new Attribut("attri", "string");

			double * d = new double(1.2);
			string * e = new string("rougeur");

			A->setValue(d);
			B->setValue(e);

			emp->ajouterAttribut(A);
			emp->ajouterAttribut(B);

			string dbl = "double";
			string str = "string";

			deque<Attribut> list = emp->getListeAttributs();

			Assert::IsTrue(!list.empty(), L"L'attribut n'a pas �t� ajout�");
			Assert::AreEqual(*d, *(double*)list[0].getValue(), L"Valeur de A fausse");
			Assert::AreEqual(dbl, list[0].getType(),L"Le type de A est faux");
			Assert::AreEqual(*e, *(string*)list[1].getValue(),L"La valeur de B est fausse");
			Assert::AreEqual(str, list[1].getType(),L"Le type est faux");

			

			
		}

	};
}