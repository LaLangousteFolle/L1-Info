#include "tab.h"
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
tableau::tableau()
{
	tab = nullptr;
	buf = nullptr;
	nb_mots = 0;
	taille_buf = 0;
}

tableau::~tableau()
{
	if (tab != nullptr)
		delete[] tab;
	if (buf != nullptr)
		delete[] buf;
}

void tableau::charger(const char * nom_fichier)
{
	ifstream fichier(nom_fichier);
	string mot;
	int taille_totale = 0;
	nb_mots = 0;

	while (getline(fichier, mot))
	{
		if (mot.length() > 0)
		{
			taille_totale += mot.length() + 1;
			nb_mots++;
		}
	}

	taille_buf = taille_totale;
	buf = new char[taille_buf];
	tab = new char*[nb_mots];

	fichier.clear();
	fichier.seekg(0);

	int pos = 0;
	int index = 0;
	while (getline(fichier, mot))
	{
		if (mot.length() > 0)
		{
			tab[index] = &buf[pos];
			strcpy(&buf[pos], mot.c_str());
			pos += mot.length() + 1;
			index++;
		}
	}

	fichier.close();

	tri_rapide(0, nb_mots - 1);
}

void tableau::tri_rapide(int debut, int fin)
{
	if (debut >= fin)
		return;

	int pivot_idx = debut;
	char * pivot = tab[pivot_idx];
	int i = debut + 1;
	int j = fin;

	while (i <= j)
	{
		while (i <= j && strcmp(tab[i], pivot) <= 0)
			i++;
		while (i <= j && strcmp(tab[j], pivot) > 0)
			j--;
		if (i < j)
		{
			char * temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
		}
	}

	char * temp = tab[pivot_idx];
	tab[pivot_idx] = tab[j];
	tab[j] = temp;

	tri_rapide(debut, j - 1);
	tri_rapide(j + 1, fin);
}

bool tableau::chercher(const char * mot)
{
	int debut = 0;
	int fin = nb_mots - 1;

	while (debut <= fin)
	{
		int milieu = (debut + fin) / 2;
		int cmp = strcmp(mot, tab[milieu]);

		if (cmp == 0)
			return true;
		else if (cmp < 0)
			fin = milieu - 1;
		else
			debut = milieu + 1;
	}

	return false;
}

int tableau::get_nb_mots()
{
	return nb_mots;
}

int tableau::get_taille_buf()
{
	return taille_buf;
}
