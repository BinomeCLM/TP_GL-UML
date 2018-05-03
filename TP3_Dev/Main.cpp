/*************************************************************************
Main  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Main> (fichier Main.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Main.h"
#include "Attribut.h"
#include <string>
//#define _CRT_SECURE_NO_WARNINGS


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

int main(int  argc, char* argv[]) {

	
	string * s = new string();
	*s = "hello";
	double * d = new double();
	*d = 1.2;

	Attribut* A = new Attribut("symp", "double");
	A->setValue(d);
	Attribut* B = new Attribut("symp", "double");
	B->setValue(d);
	
	cout << *(double*)A->getValue() << " " << *(double*)B->getValue() << endl;

	if (A->estEgal(*B))
	{
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	delete A;
	delete B;
	
	
	
	int v;
	cin >> v;

	return 0;
}
