/*************************************************************************
Main  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <Main> (fichier Main.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <deque>
#include <string>

//------------------------------------------------------ Include personnel
#include "Main.h"
#include "Attribut.h"
#include "Dictionnaire.h"
#include "Empreinte.h"
#include "Maladie.h"
#include "FichEmpStream.h"

//#define _CRT_SECURE_NO_WARNINGS


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
void testAttribut();
void testMaladie();
void testFichier();
void testDico();
void testEmpreinte();
void testAffichage();
void testFichEmpStream();
int main() {

	//testAttribut();
	//testEmpreinte();
	//testMaladie();
	//testFichier();
	//testDico();
    //testAffichage();
	testFichEmpStream();

	return 0;
}

// Test du constructeur, methode validee
void testAttribut()
{
	Attribut* A = new Attribut("att","double");
	Attribut* B = new Attribut("attri","string");

	double * d = new double(1.2);
	string * e = new string("lol");

	A->setValue(d);
	B->setValue(e);
	cout << "ici" << endl;

	if(*A == *B)
	{
		cout << "oui" << endl;
	}
	else
	{
		cout << "non" << endl;
	}
	cout << *(double*) A->getValue() << endl;
	cout << *(string*) B->getValue() << endl;
	delete A;
	delete B;
	delete d;
	delete e;
}

// Test du constructeur Empreinte + AjouterAttributs, methode validee
void testEmpreinte()
{
	Empreinte * emp = new Empreinte(2);
	Empreinte* emp2 = new Empreinte(1);

	Attribut* A = new Attribut("att","double");
	Attribut* B = new Attribut("attri","string");

	double * d = new double(2.5);
	string * e = new string("coucou");

	A->setValue(d);
	B->setValue(e);

	// Test méthode ajouterAttribut
	cout << "ici" << endl;
	emp->ajouterAttribut(A);
	emp->ajouterAttribut(B);

	cout << emp->getNbAttributs() << endl;
	deque<Attribut> listeAttr = emp->getListeAttributs();

	for (deque<Attribut>::iterator it=listeAttr.begin(); it!=listeAttr.end(); it++)
	{
		if (it->getType() == "double")
		{
			cout << "debug" << endl;
			cout << it->getNom() << endl;
			cout << *((double*)it->getValue()) << endl;
		}
		else
		{
			cout << it->getNom() << endl;
			cout << *(string*) it->getValue() << endl;
		}

	}


	delete emp;
	delete emp2;
	delete A;
	delete B;
	delete d;
	delete e;
}

// ajouterMaladie validée, getListeMaladie validée, << pour maladie marche
void testDico()
{

	string signature = "AttributeName;AttributeType\nNoID;ID\nA1;string\nA2;double\nA3;double\nA4;double\nAZ51;double\nDisease;string";

	long *id  = new long(1);
	//Maladie * m = new Maladie(*id,"grippe");
	string champs1 = "1;True;2.12;13;3.156;12.36;Maladie1";
	string champs2 = "1;True;2.12;13;3.156;12.36;Maladie2";


	Dictionnaire * d = new Dictionnaire("if",signature);
	cout << d->ajouterMaladie(champs2) << endl;
	deque<Maladie> lesMaladies = d->getListeMaladie();
    for (deque<Maladie>::iterator it=lesMaladies.begin(); it!=lesMaladies.end(); ++it)
    {
        cout << *it << endl;
    }
    for (deque<Maladie>::iterator it=lesMaladies.begin(); it!=lesMaladies.end(); ++it)
    {
        cout << *it << endl;
    }

	delete id;
	delete d;

}

// ajouterMaladie et empreinteExiste fonctionne mais pas getEMpreinteById
void testMaladie()
{
	string signature = "AttributeName;AttributeType\nNoID;ID\nA1;string\nA2;double\nA3;double\nA4;double\nAZ51;double";
	Fichier* f = new Fichier("if",signature);
	long *id  = new long(1);
	Maladie * m = new Maladie(*id,"grippe");
	string champs1 = "1;True;2.12;13;3.156;1236;Maladie1";
	string champs2 = "2;True;2.12;13;3.156;1236;Maladie2";

	cout << m->ajouterEmpreinte(champs1,f->getSignature()) << endl;
	cout << m->ajouterEmpreinte(champs2,f->getSignature()) << endl;

	deque<Empreinte> listeEmp = m->getListeEmpreinte();
	//cout << f->getSignature()[0].first << f->getSignature()[0].second << endl;
	for (deque<Empreinte>::iterator it2=listeEmp.begin(); it2!=listeEmp.end(); it2++)
	{
		deque<Attribut> listeAttr = it2->getListeAttributs();

		for (deque<Attribut>::iterator it=listeAttr.begin(); it!=listeAttr.end(); it++)
		{
			if (it->getType() == "double")
			{
				cout << it->getNom() << endl;
				cout << *((double*)it->getValue()) << endl;
			}
			else
			{
				cout << it->getNom() << endl;
				cout << *(string*) it->getValue() << endl;
			}

		}
	}
	cout << "Test getEmpreinteById" << endl;
	cout << m->empreinteExiste(1) << endl; // Méthode marche
	Empreinte * e = m->getEmpreinteById(1);
	cout << "erreur ici 1" << endl;
	deque<Attribut> attr = e->getListeAttributs();
	cout << "erreur ici 2" << endl;
	for (deque<Attribut>::iterator it=attr.begin(); it!=attr.end(); it++)
	{
		if (it->getType() == "double")
		{
			cout << it->getNom() << endl;
			cout << *((double*)it->getValue()) << endl;
		}
		else
		{
			cout << it->getNom() << endl;
			cout << *(string*) it->getValue() << endl;
		}

	}

	delete e;
	delete f;
	delete id;
	delete m; //Sinon erreur object was not allocated

}

// COnstructeur de Fichier fonctionne
void testFichier()
{
	string signature = "AttributeName;AttributeType\nNoID;ID\nA1;string\nA2;double\nA3;double\nA4;double\nAZ51;double";
	Fichier* f = new Fichier("if",signature);
	deque<pair<string,string>> signatureFich = f->getSignature();
	for(unsigned int i =0; i< signatureFich.size(); i++)
	{
		cout << signatureFich[i].first << signatureFich[i].second << endl;
	}

	delete f;
}

// Surcharge Dictionnaire, Maladie, Empreinte et Attributs fonctionnent
void testAffichage()
{
    string signature = "AttributeName;AttributeType\nNoID;ID\nA1;string\nA2;double\nA3;double\nA4;double\nAZ51;double\nDisease;string";
    Dictionnaire* d = new Dictionnaire("if",signature);
    Maladie * m = new Maladie(1,"grippe");
    string champs1 = "1;True;2.12;13;3.156;1236;Maladie1";
    string champs2 = "2;True;2.12;13;3.156;12.36;Maladie2";

    cout << m->ajouterEmpreinte(champs1,d->getSignature()) << endl;
    cout << m->ajouterEmpreinte(champs2,d->getSignature()) << endl;
	cout << d->ajouterMaladie(champs1) << endl;
    cout << *m << endl;
    cout << *d << endl;

    /*Empreinte * e = new Empreinte(1);
    Attribut* A = new Attribut("att","double");
    Attribut* B = new Attribut("attri","string");

    double * valD = new double(2.5);
    string * valS = new string("coucou");

    A->setValue(valD);
    B->setValue(valS);

    cout << "ici" << endl;
    e->ajouterAttribut(A);
    e->ajouterAttribut(B);

    cout << "test surcharge affichage" << endl;
    cout << *e << endl;*/

    delete d;
    delete m;
    //delete e;
    //delete A;
    //delete B;
}

void testFichEmpStream()
{
	FichEmpStream * fEmpSt = new FichEmpStream();
	cout << fEmpSt->verifierExtension("./dekdlekd.log");
	fEmpSt->lireDictionnaire("./HealthMeasurementsWithLabels.txt");
}