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
#include "Fichier.h"
#include "Maladie.h"
#include "Dictionnaire.h"
#include <deque>
#include <string>
#import <utility>
//#define _CRT_SECURE_NO_WARNINGS


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC


int main() {

	Attribut* A = new Attribut("att","double");
	Attribut* B = new Attribut("attri","double");
	double * d = new double();
	*d = 1.2;

	double * e = new double();
	*e = 2.6;
	A->setValue(d);
	B->setValue(d);
	
	if(*A == *B)
	{
		cout << "oui" << endl;
	}

	string signature = "AttributeName;AttributeType\nNoID;ID\nA1;string\nA2;double\nA3;double\nA4;double\nAZ51;double";
	Fichier* f = new Fichier("if",signature);

	for(int i =0; i < f->getSignature().size(); i++)
	{
		//cout << f->getSignature()[i].first << " " <<  f->getSignature()[i].second << endl;
	}
	//cout << f->getSignature() << endl;

	/*string * s = new string();
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
	cin >> v;*/

	return 0;
}



