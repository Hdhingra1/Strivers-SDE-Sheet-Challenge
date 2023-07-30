#include <bits/stdc++.h>
class Node
{
public:
    Node *link[26];
    int tw = 0;
    int pw = 0;
    bool is(char c)
    {
        return link[c - 'a'] != NULL;
    }
    void put(char c, Node *k)
    {
        link[c - 'a'] = k;
    }
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        // Write your code here.
        root = new Node();
    }

    void insert(string &word)
    {
        Node *tmp = root;
        for (auto it : word)
        {
            if (!tmp->is(it))
            {
                tmp->put(it, new Node());
            }
            tmp->pw++;
            tmp = tmp->link[it - 'a'];
        }
        tmp->pw++;
        tmp->tw++;
    }

    int countWordsEqualTo(string &word)
    {
        Node *tmp = root;
        for (auto it : word)
        {
            if (!tmp->is(it))
            {
                return 0;
            }
            tmp = tmp->link[it - 'a'];
        }
        return tmp->tw;
    }

    int countWordsStartingWith(string &word)
    {
        Node *tmp = root;
        for (auto it : word)
        {
            if (!tmp->is(it))
            {
                return 0;
            }
            tmp = tmp->link[it - 'a'];
        }
        return tmp->pw;
    }

    void erase(string &word)
    {
        Node *tmp = root;
        for (auto it : word)
        {
            tmp->pw--;
            tmp = tmp->link[it - 'a'];
        }
        tmp->pw--;
        tmp->tw--;
    }
};
