class tableau
{
	char ** tab;
	char * buf;
	int nb_mots;
	int taille_buf;

	void tri_rapide(int debut, int fin);

public:
	tableau();
	~tableau();
	void charger(const char * nom_fichier);
	bool chercher(const char * mot);
	int get_nb_mots();
	int get_taille_buf();
};
