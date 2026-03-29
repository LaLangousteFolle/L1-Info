#include "apc.h"
#include <cstring>
#include <iostream>

noeud::noeud()
{
	info = '\0';
	fils = nullptr;
	frere = nullptr;
}

noeud::~noeud()
{
	if (fils != nullptr)
		delete fils;
	if (frere != nullptr)
		delete frere;
}

arbre::arbre()
{
	racine = new noeud();
}

arbre::~arbre()
{
	delete racine;
}

void arbre::inserer(const char * mot)
{
	noeud * courant = racine;
	int i = 0;

	while (mot[i] != '\0')
	{
		if (courant->fils == nullptr)
		{
			courant->fils = new noeud();
			courant->fils->info = mot[i];
			courant = courant->fils;
		}
		else
		{
			noeud * precedent = nullptr;
			noeud * frere_courant = courant->fils;

			while (frere_courant != nullptr && frere_courant->info < mot[i])
			{
				precedent = frere_courant;
				frere_courant = frere_courant->frere;
			}

			if (frere_courant != nullptr && frere_courant->info == mot[i])
			{
				courant = frere_courant;
			}
			else
			{
				noeud * nouveau = new noeud();
				nouveau->info = mot[i];
				nouveau->frere = frere_courant;
				if (precedent == nullptr)
					courant->fils = nouveau;
				else
					precedent->frere = nouveau;
				courant = nouveau;
			}
		}
		i++;
	}

	noeud * fin = new noeud();
	fin->info = '\0';

	if (courant->fils == nullptr)
	{
		courant->fils = fin;
	}
	else
	{
		noeud * precedent = nullptr;
		noeud * frere_courant = courant->fils;
		while (frere_courant != nullptr)
		{
			precedent = frere_courant;
			frere_courant = frere_courant->frere;
		}
		precedent->frere = fin;
	}
}

bool arbre::chercher(const char * mot)
{
	noeud * courant = racine;
	int i = 0;

	while (mot[i] != '\0')
	{
		noeud * frere_courant = courant->fils;
		bool trouve = false;

		while (frere_courant != nullptr)
		{
			if (frere_courant->info == mot[i])
			{
				courant = frere_courant;
				trouve = true;
				break;
			}
			frere_courant = frere_courant->frere;
		}

		if (!trouve)
			return false;

		i++;
	}

	noeud * frere_courant = courant->fils;
	while (frere_courant != nullptr)
	{
		if (frere_courant->info == '\0')
			return true;
		frere_courant = frere_courant->frere;
	}

	return false;
}
