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

//#define _CRT_SECURE_NO_WARNINGS


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
void testAttribut();
void testMaladie();
void testFichier();
void testDico();
void testEmpreinte();
void testAffichage();
int main() {

	//testAttribut();
    //testEmpreinte();
	//testMaladie();
	//testFichier();
	//testDico();
	testAffichage();


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

	
    cout << *A << endl;
    cout << *B << endl;
	delete A;
	delete B;
	delete d;
	delete e;
}

void testAffichage()
{
	Empreinte * E = new Empreinte(4);
	Attribut* A = new Attribut("att","double");
	Attribut* B = new Attribut("attri","string");

	double * d = new double(1.2);
	string * e = new string("lol");

	A->setValue(d);
	B->setValue(e);

	cout << *A << endl;
    cout << *B << endl;

	E->ajouterAttribut(*A);
	E->ajouterAttribut(*B);
	cout << "heyOp" << endl;
	deque<Attribut> listeAttr = E->getListeAttributs();

	cout << "id:"<<E->getIdEmpreinte()<<"/";

	/*for (deque<Attribut>::iterator it=listeAttr.begin(); it!=listeAttr.end()-1; ++it)
	{
		cout << "for avant "<< endl;
		os << *it << "/";
		cout << "for apres "<< endl;
	}*/

	for(int i = 0; i < (listeAttr.size())-1 ; i++)
	{
		//cout << "for avant "<< endl;
		cout << listeAttr[i] << "/";
		//cout << "for apres "<< endl;
	}
	//cout << "hey";

	//os << listeAttr[0] << endl;
	cout << listeAttr[listeAttr.size()] << endl;
	//delete A;
	//delete B;
	//delete d;
	//delete e;
	//delete E;

	
}

// Test du constructeur, methode validee
void testEmpreinte()
{
    Empreinte * emp = new Empreinte(2);
    Empreinte* emp2 = new Empreinte(1);

    Attribut* A = new Attribut("att","double");
    Attribut* B = new Attribut("attri","string");

    //double * d = new double(2.5);
    string * e = new string("coucou");

    //A->setValue(d);
    B->setValue(e);

    // Test méthode ajouterAttribut
    cout << "ici" << endl;
    //emp->ajouterAttribut(*A);
    emp->ajouterAttribut(*B);

    cout << emp->getNbAttributs() << endl;
    deque<Attribut> listeAttr = emp->getListeAttributs();
    int i;
    for (deque<Attribut>::iterator it=listeAttr.begin(); it!=listeAttr.end(); ++it)
    {
        if (it->getType() == "double")
        {
            cout << "debug" << endl;
            cout << it->getNom() << endl;
            cout << *(double*)it->getValue() << endl;
        }
        else
        {
            void* value = nullptr;
            *(string*) value = *(string*) it->getValue();
            //cout << *value << endl;
            cout << it->getNom() << endl;
            cout << *(string*) it->getValue() << endl;
        }

    }
    delete emp;
    delete emp2;
    delete A;
    delete B;
    //delete d;
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



