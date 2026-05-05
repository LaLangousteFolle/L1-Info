#include "apc.h"

int main(void)
{
    Arbre abr;

    string words[] = {"abc", "abricot", "bon", "bonjour", "vache", "viande", "violet"};
    for (string &w : words)
        abr.addWord(w.data());

    cout << "Mots dans l'arbre :" << endl;
    abr.display();

    return 0;
}
