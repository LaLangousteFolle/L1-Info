#include "apc.h"

int main(void)
{
    // Q1
    Arbre abr;
    string words[] = {"abc", "abricot", "bon", "bonjour", "vache", "viande", "violet"};
    for (string &w : words)
        abr.addWord(w.data());

    // Q5
    abr.display();

    // Q6
    cout << "abc " << abr.search("abc") << endl; //1
    cout << "ab  " << abr.search("ab") << endl; // 0
    cout << "bon " << abr.search("bon") << endl; // 1
    cout << "xyz " << abr.search("xyz") << endl; // 0

    // Q8
    cout << "total  " << abr.totalWords() << endl; //7

    // Q9
    cout << "longueur max " << abr.longestWord() << endl; //7

    // Q7
    abr.deleteWord("bon");
    abr.display();
    cout << "bon " << abr.search("bon") << endl; // 0
    cout << "bonjour " << abr.search("bonjour") << endl; // 1
    cout << "total " << abr.totalWords() << endl; // 6

    // Q10
    abr.saveToFile("sauvegarde.txt");

    // Q2
    Arbre abr2("sauvegarde.txt");
    abr2.display();
    cout << "total  " << abr2.totalWords() << endl; //6

    // Q4
    Arbre abr3(abr2);
    abr3.deleteWord("abc");
    cout << "abr3 total " << abr3.totalWords() << endl; //5
    cout << "abr2 total " << abr2.totalWords() << endl; // 6

    // Q11
    abr.getSuggestions("ab");
    abr.getSuggestions("vi");
    abr.getSuggestions("b");
    abr.getSuggestions("zz");

    return 0;
}
