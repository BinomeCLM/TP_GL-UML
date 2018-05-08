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
void testAttribut();
void testMaladie();
void testFichier();
void testDico();
int main() {

	//testAttribut();
	//testMaladie();
	testFichier();
	//testDico();
	

	return 0;
}

void testAttribut()
{
	Attribut* A = new Attribut("att","double");
	Attribut* B = new Attribut("attri","double");
	double * d = new double(1.2);
	

	double * e = new double(2.6);
	
	A->setValue(d);
	B->setValue(e);
	cout << "ici" << endl;
	if(*A == *B)
	{
		cout << "oui" << endl;
	}

	delete A;
	delete B;
	delete d;
	delete e;
	
	

}

void testDico()
{

	string signature = "AttributeName;AttributeType\nNoID;ID\nA1;string\nA2;double\nA3;double\nA4;double\nAZ51;double";
	Fichier* f = new Fichier("if",signature);
	long *id  = new long(1);
	Maladie * m = new Maladie(*id,"grippe");
	string champs1 = "1;True;2.12;13;3.156;1236;Maladie1";
	string champs2 = "1;True;2.12;13;3.156;1236;Maladie2";


	Dictionnaire * d = new Dictionnaire("if",signature);
	cout << d->ajouterMaladie(champs1) << endl;


	 delete f;
	 delete id;
	 delete d;
	 delete m;

}

void testMaladie()
{
	string signature = "AttributeName;AttributeType\nNoID;ID\nA1;string\nA2;double\nA3;double\nA4;double\nAZ51;double";
	Fichier* f = new Fichier("if",signature);
	long *id  = new long(1);
	Maladie * m = new Maladie(*id,"grippe");
	string champs1 = "1;True;2.12;13;3.156;1236;Maladie1";
	string champs2 = "1;True;2.12;13;3.156;1236;Maladie2";

	//cout << f->getSignature()[0].first << f->getSignature()[0].second << endl;

	cout << m->ajouterEmpreinte(champs1,f->getSignature()) << endl;
	cout << m->ajouterEmpreinte(champs1,f->getSignature()) << endl;
	//m->getEmpreinteById(*id);

	 delete f;
	 delete id;
	 delete m; //Sinon erreur object was not allocated

}

void testFichier()
{
	string signature = "AttributeName;AttributeType\nNoID;ID\nA1;string\nA2;double\nA3;double\nA4;double\nAZ51;double";
	Fichier* f = new Fichier("if",signature);
	for(int i =0; i< f->getSignature().size(); i++)
	{
		cout << f->getSignature()[i].first << f->getSignature()[i].second << endl;
	}

	delete f;
}



