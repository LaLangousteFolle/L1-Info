class noeud;

class arbre
{
	noeud * racine;
public:
	arbre();
	~arbre();
	void inserer(const char * mot);
	bool chercher(const char * mot);
};

class noeud
{
	friend class arbre;
	char info;
	noeud * fils;
	noeud * frere;
public:
	noeud();
	~noeud();
};
