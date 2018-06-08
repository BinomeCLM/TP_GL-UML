#include "stdafx.h"
#include "CppUnitTest.h"
#include "Empreinte.h"
#include "Maladie.h"
#include "Fichier.h"
#include "FichierPatient.h"
#include "Dictionnaire.h"
#include <string>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestApp
{
	TEST_CLASS(TestFichierPatient)
	{
	public:


		TEST_METHOD(AjouterEmpreinte)
		{
			string signature = "A1;string\nA2;double\nA3;double\nA4;double\nAZ51;double\nDisease;string";

			string champs1 = "1;True;2.12;13;3.156;12.36";
			string champs2 = "1;True;2.12;13;3.156;12.36";
			string champs3 = "5;True;13;13;589;12.36";


			FichierPatient * fp = new FichierPatient("fichier", signature);
			bool b1 = fp->ajouterEmpreinte(champs1);
			bool b1bis = fp->ajouterEmpreinte(champs1);


			deque<Empreinte> list = fp->getListeEmpreinte();
			Assert::IsTrue(!(list.empty()));
			Assert::IsTrue(b1);
			Assert::IsTrue(b1bis);
		
		}




	};


}