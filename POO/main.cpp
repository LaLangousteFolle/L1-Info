#include "apc.h"
#include "tab.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

	arbre a;
	ifstream lex("lex.dic");
	string mot;
	int nb_mots_lex = 0;

	while (getline(lex, mot))
	{
		if (mot.length() > 0)
		{
			a.inserer(mot.c_str());
			nb_mots_lex++;
		}
	}
	lex.close();

	cout << "nbr de mots : " << nb_mots_lex << endl;

	int trouvés_apc = 0;
	ifstream dic("dic.txt");
	while (getline(dic, mot))
	{
		if (mot.length() > 0 && a.chercher(mot.c_str()))
			trouvés_apc++;
	}

	cout << "mots trouves : " << trouvés_apc << endl;


	tableau t;
	t.charger("lex.dic");
	clock_t fin_tab = clock();

	cout << "nbr de mots : " << t.get_nb_mots() << endl;

	int trouvés_tab = 0;
	dic.open("test.dic");
	while (getline(test, mot))
	{
		if (mot.length() > 0 && t.chercher(mot.c_str()))
			trouvés_tab++;
	}
	test.close();

	cout << "Mots trouvés : " << trouvés_tab << endl;
	return 0;
}
