/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

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
        for (int i = 0; i < word.length(); i++)
        {
            if (!tmp->ischar(word[i]))
            {
                return false;
            }
            tmp = tmp->link[word[i] - 'a'];
        }
        return tmp->is;
    }

    bool startsWith(string prefix)
    {
        Node *tmp = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!tmp->ischar(prefix[i]))
            {
                return false;
            }
            tmp = tmp->link[prefix[i] - 'a'];
        }
        return true;
    }
};
