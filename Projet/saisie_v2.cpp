#include <ncurses.h>
#include <fstream>
#include <string>
#include <vector>
#include "apc.h"

using namespace std;

struct Cellule
{
    char val;
    Cellule *suiv;
    Cellule *prec;
};

void lst_inserer(Cellule *&tete, Cellule *&queue, Cellule *pos, char c)
{
    Cellule *n = new Cellule;
    n->val = c;
    n->suiv = pos;
    n->prec = pos ? pos->prec : queue;
    if (n->prec)
        n->prec->suiv = n;
    else
        tete = n;
    if (pos)
        pos->prec = n;
    else
        queue = n;
}

void lst_supprimer(Cellule *&tete, Cellule *&queue, Cellule *pos)
{
    if (!pos)
        return;
    if (pos->prec)
        pos->prec->suiv = pos->suiv;
    else
        tete = pos->suiv;
    if (pos->suiv)
        pos->suiv->prec = pos->prec;
    else
        queue = pos->prec;
    delete pos;
}

void lst_free(Cellule *&tete, Cellule *&queue)
{
    Cellule *c = tete;
    while (c)
    {
        Cellule *next = c->suiv;
        delete c;
        c = next;
    }
    tete = nullptr;
    queue = nullptr;
}

string getCurrentWord(Cellule *curseur, Cellule *queue)
{
    vector<char> chars;
    Cellule *c = curseur ? curseur->prec : queue;
    while (c && c->val != ' ')
    {
        chars.push_back(c->val);
        c = c->prec;
    }
    string word;
    for (int i = (int)chars.size() - 1; i >= 0; i--)
        word += chars[i];
    return word;
}

void deleteCurrentWord(Cellule *&tete, Cellule *&queue, Cellule *curseur)
{
    Cellule *c = curseur ? curseur->prec : queue;
    while (c && c->val != ' ')
    {
        Cellule *prev = c->prec;
        lst_supprimer(tete, queue, c);
        c = prev;
    }
}

int main()
{
    Arbre arbre("dic-moyen-trie.txt");

    Cellule *tete = nullptr;
    Cellule *queue = nullptr;
    Cellule *curseur = nullptr;

    int K = 5;

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(1);

    int deb = 1;
    mvprintw(0, 0, "Saisie (TAB=suggestions, ESC=fin+sauvegarder):");

    while (true)
    {
        move(deb, 0);
        clrtoeol();
        for (Cellule *c = tete; c; c = c->suiv)
            addch(c->val);

        int curX = 0;
        for (Cellule *c = tete; c != curseur; c = c->suiv)
            curX++;
        move(deb, curX);
        refresh();

        int ch = getch();

        if (ch == 27)
            break;

        else if (ch == '\t')
        {
            string prefix = getCurrentWord(curseur, queue);
            if (prefix.empty())
                continue;

            vector<string> sugg = arbre.getSuggestions(prefix);
            int total = (int)sugg.size();
            int page = 0;

            while (true)
            {
                for (int i = 0; i < K + 3; i++)
                {
                    move(deb + 2 + i, 0);
                    clrtoeol();
                }

                int start = page * K;
                if (start >= total)
                {
                    page = 0;
                    start = 0;
                }

                if (total == 0)
                    mvprintw(deb + 2, 0, "(aucune suggestion - mot inconnu)");
                else
                {
                    mvprintw(deb + 2, 0, "Suggestions \"%s\" (page %d/%d):",
                             prefix.c_str(), page + 1, (total + K - 1) / K);
                    for (int i = 0; i < K && start + i < total; i++)
                        mvprintw(deb + 3 + i, 0, "%d: %s", i, sugg[start + i].c_str());
                }
                move(deb, curX);
                refresh();

                int sel = getch();

                if (sel == '\t')
                {
                    page++;
                    continue;
                }
                if (sel >= '0' && sel <= '9' && total > 0)
                {
                    int idx = start + (sel - '0');
                    if (idx < total)
                    {
                        deleteCurrentWord(tete, queue, curseur);
                        for (char c : sugg[idx])
                            lst_inserer(tete, queue, curseur, c);
                    }
                }
                break;
            }

            for (int i = 0; i < K + 3; i++)
            {
                move(deb + 2 + i, 0);
                clrtoeol();
            }
        }

        else if (ch == ' ')
        {
            string word = getCurrentWord(curseur, queue);
            if (!word.empty() && !arbre.search(word.c_str()))
                arbre.addWord(word.c_str());
            lst_inserer(tete, queue, curseur, ' ');
        }

        else if (ch == KEY_LEFT)
        {
            if (curseur == tete)
                ;
            else if (curseur == nullptr)
                curseur = queue;
            else
                curseur = curseur->prec;
        }

        else if (ch == KEY_RIGHT)
        {
            if (curseur != nullptr)
                curseur = curseur->suiv;
        }

        else if (ch == KEY_BACKSPACE || ch == 127 || ch == 8)
        {
            Cellule *todel = curseur ? curseur->prec : queue;
            if (todel)
                lst_supprimer(tete, queue, todel);
        }

        else if (ch >= 32 && ch <= 126)
            lst_inserer(tete, queue, curseur, (char)ch);
    }

    endwin();

    cout << "Nom du fichier de sauvegarde : ";
    string filename;
    cin >> filename;
    ofstream F(filename);
    for (Cellule *c = tete; c; c = c->suiv)
        F << c->val;
    F.close();
    cout << "Sauvegarde dans " << filename << endl;

    lst_free(tete, queue);
    return 0;
}
