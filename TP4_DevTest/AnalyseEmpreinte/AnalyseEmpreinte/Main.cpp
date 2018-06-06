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
#include "Analyse.h"

//#define _CRT_SECURE_NO_WARNINGS


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
/*void testAttribut();
void testMaladie();
void testFichier();
void testDico();
void testEmpreinte();
void testAffichage();
void testFichEmpStream();
void testAnalyse();*/
Dictionnaire renseignerDictionnaire(Dictionnaire & d,FichEmpStream * fp);
FichierPatient renseignerFichierPatient(FichEmpStream * fp);
void afficherDetailMaladie(long idMaladie, Dictionnaire d);
void afficherDictionnaire(Dictionnaire d);
void afficherMeilleurCorresp(Dictionnaire d, FichierPatient fp);
void afficherTop10(Dictionnaire d, FichierPatient fp);
int lireEntree(int min, int max);
multimap<double, string> retrouverResultat(Analyse a, bool meilleure);

int main() {


	// Scénario
   FichEmpStream * fes = new FichEmpStream;
	Dictionnaire * dico = new Dictionnaire;
	*dico = renseignerDictionnaire(*dico, fes);
	bool power = true;
	while (power) {
		cout << "Que voulez-vous faire?" << endl;
		cout << " 1 - Analyser des empreintes\n 2 - Ajouter de nouvelles données au dictionnaire" << endl;
		cout << " 3 - Afficher le contenu du dictionnaire " << endl;
		cout << " 4 - Afficher les détails d'une maladie" << endl;
		cout << " 5 - Quitter le programme" << endl;
		int choix = lireEntree(1, 5);

		switch (choix) {
			case 1: {
				FichierPatient *fpat = new FichierPatient;
				*fpat = renseignerFichierPatient(fes);
				deque<Empreinte> emp = fpat->getListeEmpreinte();
				if (emp.size() == 0)
				{
				    break;
				}
				cout << "Que souhaitez-vous faire ?" << endl;
				cout << " 1 - Afficher les 10 maladies les plus probables" << endl;
				cout << " 2 - Afficher la maladie la plus probable." << endl;
				int choixAffichage = lireEntree(1, 2);

				if (choixAffichage == 1) {
					afficherTop10(*dico, *fpat);
				} else {
					afficherMeilleurCorresp(*dico, *fpat);
				}
				delete fpat;
				break;
			}

			case 2: {
				renseignerDictionnaire(*dico,fes);
				break;
			}

			case 3: {
				afficherDictionnaire(*dico);
				break;
			}

			case 4:
			{
				cout << "Veuillez rentrer l'id de la maladie" << endl;
				deque <Maladie> mal = dico->getListeMaladie();
				int nbMaladie = mal.size();
				int id = lireEntree(1, nbMaladie);
				afficherDetailMaladie(id, *dico);
				break;
			}

			case 5:
			{
				power = false;
				break;
			}

			default:
			{
				power = false;
				break;
			}
		}
	}

    delete fes;
    delete dico;

	
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
	Empreinte e = m->getEmpreinteById(1);
	cout << "erreur ici 1" << endl;
	deque<Attribut> attr = e.getListeAttributs();
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

// Fonctionne pour le dico
void testFichEmpStream()
{
	FichEmpStream * fEmpSt = new FichEmpStream();
	Dictionnaire * dTest = new Dictionnaire;
	//cout << fEmpSt->verifierExtension("./dekdlekd.log") << endl;
    *dTest = fEmpSt->lireDictionnaire(*dTest, "./DataMaladie.txt");
	//cout << *dTest << endl;
	FichierPatient * fPatTest = new FichierPatient;
	*fPatTest = fEmpSt->lireFichierPatient("./DataEmp.txt");
	cout << "done" << endl;
}

// Calculer proba fonctionne
// GenererClassement aussi
void testAnalyse()
{
	Analyse * analyse = new Analyse();
	FichEmpStream * fEmpSt = new FichEmpStream();
	Dictionnaire * dTest = new Dictionnaire;
	// ON renseigne le dictionnaire
	*dTest = fEmpSt->lireDictionnaire(*dTest,"./HealthMeasurementsWithLabels.txt");
	// On renseigne le FichierPatient
	FichierPatient * fPatTest = new FichierPatient;
	*fPatTest = fEmpSt->lireFichierPatient("./HealthMeasurements.txt");

	// Test de calculerProba
	// On récupére une empreinte pour le test
	deque<Empreinte> lesEmpAanalyse = fPatTest->getListeEmpreinte();
	// On récupére une maladie pour le test
	deque<Maladie> lesMaladiesAcomparer = dTest->getListeMaladie();

	// moyen pour vérifier avant de comparer qu'il y a bien des maladies dans le dico
    // et des empreintes à analyser
	if (lesEmpAanalyse.size() > 0 && lesMaladiesAcomparer.size() > 0)
    {
        cout << lesEmpAanalyse[1] << endl;
        //cout << lesMaladiesAcomparer[1] << endl;
        //analyse->calculerProbabilite(lesEmpAanalyse[1], lesMaladiesAcomparer[1]);
        //analyse->genererClassement(*dTest,lesEmpAanalyse[1]);
        deque<Analyse> lesAnalyses = fPatTest->analyserEmpreinte(*dTest);
        for (deque<Analyse>::iterator it=lesAnalyses.begin(); it!=lesAnalyses.end(); it++)
        {
            cout << "Empreinte numéro : " << it->getIdEmpreinte() << endl;
            multimap<double,string> resultat = it->getCorrespondances();
            for (multimap<double,string>::iterator it2 = resultat.begin(); it2!=resultat.end(); it2++)
            {
                if (it2->second.compare("")) {
                    cout << it2->second << " proba : " << it2->first << " %" << endl;
                    // IL faut qu'on parle de comment on gere le
                    // cas quand la maladie n'a pas de nom
                }
            }
        }
    }
    else
    {
        cerr << "Aucune maladie renseignée dans le dico ou d'empreintes à analyser" << endl;
    }
}

Dictionnaire renseignerDictionnaire(Dictionnaire & d, FichEmpStream * lecteur)
{
	string sourceFichierDico = "";
	cout << "Veuillez renseigner le fichier servant de base de connaissances." << endl;
	cin >> sourceFichierDico;

	d = lecteur->lireDictionnaire(d, sourceFichierDico);
	return d;
}

FichierPatient renseignerFichierPatient(FichEmpStream * lecteur)
{
	string sourceFichierAnalyse = "";
	cout << "Veuillez renseigner le fichier contenant les empreintes à analyser." << endl;
	cin >> sourceFichierAnalyse;
	FichierPatient fPat;
	fPat = lecteur->lireFichierPatient(sourceFichierAnalyse);

	return fPat;
}

void afficherTop10(Dictionnaire d, FichierPatient fp)
{
	deque<Analyse> lesAnalyses = fp.analyserEmpreinte(d);
	for (deque<Analyse>::iterator it=lesAnalyses.begin(); it!=lesAnalyses.end(); it++)
	{
		multimap<double,string> resultat = retrouverResultat(*it,false);
		int compteur = 1;
		cout << "Résultat de l'analyse pour l'empreinte numéro " << it->getIdEmpreinte() << endl;
		// On fait ça pour stocker la dixième valeur et pour gérer le cas d'égalité
		if(resultat.size() != 0)
		{

			for (multimap<double, string>::reverse_iterator it2 = resultat.rbegin(); it2 != resultat.rend(); it2++)
			{
				if (it2->second.compare("")) {
					cout << compteur << ". " << it2->second << " : " << " proba : " << it2->first << "% de chance - " << endl;
					// IL faut qu'on parle de comment on gere le
					// cas quand la maladie n'a pas de nom
					if (it2->first >= 70)
					{
						cout << "Très probable." << endl;
						cout << "Une analyse supplémentaire pour vérification est conseillée." << endl;
						cout << endl;
					}
					else if (it2->first >= 50)
					{
						cout << "Probable" << endl;
						cout << endl;
					}
					else
					{
						cout << "Peu probable" << endl;
						cout << endl;
					}
					compteur++;
					if (compteur == 11)
					{

						compteur--;

					}
				}
			}
			
		}
		else
		{
			cout << "Aucun risque de maladie détecté à partir des informations "
			 		"contenues dans notre unité de stockage." << endl;
             cout << endl;
			break;
			
		}
		
	}
}

void afficherMeilleurCorresp(Dictionnaire d, FichierPatient fp)
{
	deque<Analyse> lesAnalyses = fp.analyserEmpreinte(d);
	for (deque<Analyse>::iterator it = lesAnalyses.begin(); it != lesAnalyses.end(); it++)
	{
		int compteur = 1;
		cout << "Résultat de l'analyse pour l'empreinte numéro " << it->getIdEmpreinte() << endl;
		multimap<double, string> resultat = retrouverResultat(*it,true);
		if (resultat.size() != 0)
		{
			for (multimap<double, string>::reverse_iterator it2 = resultat.rbegin(); it2 != resultat.rend(); it2++)
			{

				if (it2->second.compare("")) {
					cout << "Maladie avec la meilleur correspondance : " << endl;
					cout << it2->second << " : " << " proba : " << it2->first << "% de chance - ";

					if (it2->first >= 70) {
						cout << "Très probable." << endl;
						cout << "Une analyse supplémentaire pour vérification est conseillée." << endl;
						cout << endl;
					}
					else if (it2->first >= 50) {
						cout << "Probable" << endl;
						cout << endl;
					}
					else {
						cout << "Peu probable" << endl;
						cout << endl;
					}
				}
			}
		}
		else
		{

			cout << "Aucun risque de maladie détecté à partir des informations "
				"contenues dans notre unité de stockage." << endl;
			cout << endl;

		}
	}
	
}

multimap<double, string> retrouverResultat(Analyse a, bool meilleur) //si meilleur = true on chercher la meilleure correspondance sinon le Top10
{
	
	int compteur = 1;
	multimap<double, string> resultat = a.getCorrespondances();
	double probaLimite = 0;
	if (meilleur)
	{
		if (resultat.size() > 1)
		{
			multimap<double, string>::reverse_iterator it2 = resultat.rbegin();
			probaLimite = it2->first;
		}
	}
	else {
		if (resultat.size() > 10)
		{
			multimap<double, string>::reverse_iterator it3 = resultat.rbegin();
			advance(it3, 9);
			probaLimite = it3->first;
		}
	}

	for (multimap<double, string>::reverse_iterator it = resultat.rbegin(); it != resultat.rend(); it++)
	{
		if (it->first > 20)
		{
			if (it->first != probaLimite)
			{
				break;
			}

			if (it->second.compare("")) {

				resultat.insert(pair<double, string>(it->first, it->second));
				compteur++;
			}
		}
		else {
			break;
		}
	}

	return resultat;
}

	



void afficherDictionnaire(Dictionnaire d)
{
	cout << d << endl;
}

void afficherDetailMaladie(long idMaladie, Dictionnaire d)
{
	Maladie maladie = d.getMaladieById(idMaladie);
	cout << maladie.getEmpreinteById(7) << endl;
	cout << maladie << endl;
}


int lireEntree(int min, int max)
{
	bool valid = false;
	int nbRentre;
	while (!valid)
	{
		cin >> nbRentre;
		if (cin.fail())
		{
			cout << "Données non valide" << endl;
			cin.clear(ios::goodbit);
			cin.ignore(100,'\n');
		}
		else {
			if (nbRentre >= min && nbRentre <= max)
			{
				valid = true;
			}
			else
			{
				cout << "Nombre saisie invalide, saisissez un nombre entre " << min << " et " << max << endl;
			}
		}
	}
	cin.clear(ios::goodbit);
	cin.ignore(100,'\n');
	return nbRentre;
}