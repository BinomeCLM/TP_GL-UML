#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <ctime>
#include <sstream>

using namespace std;

string intToString(int i) {
     ostringstream oss;
     oss << i;
     return oss.str();
}

int main()
{
    cout << "Quel fichier voulez-vous creer?" << endl;
    cout << "   1 -> Creer un fichier maladie" <<endl;
    cout << "   2 -> Creer un fichier empreinte a analyser" << endl;
    int typeFichier;
    cin >> typeFichier;
    cin.clear(ios::goodbit);
    cin.ignore(100,'\n');

    if (typeFichier==2)
    {
        cout << "Combien d'empreintes souhaitez-vous ajouter?" << endl;
    }
    else
    {
        cout << "Combien de maladies souhaitez-vous ajouter?" << endl;
    }
    string nbEmpreintes;
    cin >> nbEmpreintes;
    if (cin.fail())
    {
        cin.clear(ios::goodbit);
        cin.ignore(100,'\n');
        return 0;
    }
    cin.clear(ios::goodbit);
    cin.ignore(100,'\n');

    string nomFichier;
    if (typeFichier==2)
    {
        nomFichier = "fichier_empreintes_analyse_" + nbEmpreintes +".txt";
    }
    else
    {
        nomFichier = "fichier_maladies_" + nbEmpreintes +".txt";
    }

    ofstream fichier(nomFichier.c_str(), ios::out | ios::trunc);
    //déclaration du flux et ouverture du fichier ou création de celui-ci

    if(fichier)  // si l'ouverture a réussi
    {
        fichier << "AttributeName;AttributeType" << endl;
        fichier << "NoID;ID" << endl;
        cout << "Combien d'attributs dans la signature ?" << endl;
        int nbAttributs = 0;
        cin >> nbAttributs;
        cin.clear(ios::goodbit);
        cin.ignore(100,'\n');

        int i;
        map<string,string> signature;
        string id;
        for (i=0; i<nbAttributs; i++)
        {
            id = intToString(i);
            if (i%2==0)
            {
                string nvelElmt = "A" + id +";string";
                signature.insert(pair<string,string>(string("A"+id),string("string")));
                fichier << nvelElmt << endl;
            }
            else
            {
                string nvelElmt = "A" + id +";double";
                signature.insert(pair<string,string>(string("A"+id),string("double")));
                fichier << nvelElmt << endl;
            }
        }
        if (typeFichier==1)
        {
            fichier << "Disease;string" << endl;
        }
        fichier << endl;
        fichier << "NoID;";

        string dernierAttr = "A" + id;
        for (std::map<string,string>::iterator it=signature.begin(); it!=signature.end(); ++it)
        {
            if (dernierAttr.compare((it->first))==0)
            {
                if (typeFichier==1)
                {
                    fichier << it->first << ";" << "Disease" << endl;
                }
                else
                {
                    fichier << it->first << endl;
                }
            }
            else
            {
                fichier << it->first << ";";
            }
        }
        cout << "Voulez-vous des doublons (1:true 2:false)?" << endl;
        int doublon;
        cin >> doublon;
        cin.clear(ios::goodbit);
        cin.ignore(100,'\n');
        int nbMaxDoublon;
        if (doublon == 1)
        {
            cout << "Quel nombre max d'empreintes differentes souhaitez-vous?" << endl;

            cin >> nbMaxDoublon;
            cin.clear(ios::goodbit);
            cin.ignore(100,'\n');
        }
        string attrString[10] = {"red","hot","cold","blue","none","true","false", "medium","safe","danger"};
        double attrDouble[10] = {1234, 23, 45.5, 20.7, 10, 11, 7, 23445, 0.55, 9};
        int idEmp = 1;
        int j;
        srand(time(NULL));
        int nbEmp = atoi(nbEmpreintes.c_str());
        for (i=0; i<nbEmp; i++)
        {
            if (typeFichier==2 && doublon==1)
            {
                idEmp = rand()%nbMaxDoublon;
            }
            fichier << idEmp << ";";
            for (j=1; j<nbAttributs+1; j++)
            {
                int nbAlea = rand()%10;
                if (j%2 == 0)
                {
                    fichier <<  attrString[nbAlea];
                }
                else
                {
                    fichier << attrDouble[nbAlea];
                }
                if (j!=(nbAttributs))
                {
                    fichier << ";";
                }
            }
            if (typeFichier==1 && doublon==2)
            {
                string idMala = intToString(i);
                string nomMaladie = "Maladie" + idMala;
                fichier << ";" << nomMaladie;
            }
            else if (typeFichier==1 && doublon==1)
            {
                string idMala = intToString(rand()%nbMaxDoublon);
                string nomMaladie = "Maladie" + idMala;
                fichier << ";" << nomMaladie;
            }

            fichier << endl;
            idEmp++;
        }
        fichier.close();  // on referme le fichier
    }
    else
    {
        cerr << "problème ouverture fichier" << endl;
    }

    return 0;
}

