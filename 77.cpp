#include <bits/stdc++.h>
class Node
{
public:
    Node *link[26];
    bool is = false;
    bool ischar(char c)
    {
        return link[c - 'a'] != NULL;
    }
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *tmp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!tmp->ischar(word[i]))
            {
                tmp->link[word[i] - 'a'] = new Node();
            }
            tmp = tmp->link[word[i] - 'a'];
        }
        tmp->is = true;
    }

    bool search(string word)
    {
        Node *tmp = root;
        bool ans = true;
        for (int i = 0; i < word.length(); i++)
        {
            tmp = tmp->link[word[i] - 'a'];
            if (!tmp->is)
                return false;
        }
        return true;
    }
};
static bool cmp(string &a, string &b)
{
    if (a.length() > b.length())
        return true;
    if (a.length() == b.length())
        return a < b;
    return false;
}
string completeString(int n, vector<string> &a)
{
    Trie t;
    for (auto it : a)
    {
        t.insert(it);
    }
    sort(a.begin(), a.end(), cmp);
    // for(auto it:a){
    //     cout<<it<<endl;
    // }
    int l = 0;
    string ans = "";
    for (auto it : a)
    {
        if (t.search(it))
            return it;
    }
    return "None";
}