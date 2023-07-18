class LRUCache
{
public:
    class Node
    {
    public:
        pair<int, int> val;
        Node *next;
        Node *prev;
        Node(pair<int, int> data)
        {
            this->val = data;
            this->next = NULL;
            this->prev = NULL;
        }
    };
    unordered_map<int, Node *> mp;
    Node *head = new Node({0, 0});
    Node *tail = new Node({0, 0});
    int cap;
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (!mp.count(key))
        {
            return -1;
        }
        Node *temp = mp[key];
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        Node *k = new Node(temp->val);
        delete temp;
        k->next = head->next;
        head->next->prev = k;
        k->prev = head;
        head->next = k;
        mp[key] = k;
        return k->val.second;
    }

    void put(int key, int value)
    {
        if (mp.count(key))
        {
            Node *temp = mp[key];
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            Node *k = new Node(temp->val);
            delete temp;
            k->val.second = value;
            k->next = head->next;
            head->next->prev = k;
            k->prev = head;
            head->next = k;
            mp[key] = k;
            return;
        }
        if (mp.size() == cap)
        {
            Node *temp = tail->prev;
            mp.erase(temp->val.first);
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
        Node *k = new Node({key, value});
        k->next = head->next;
        head->next->prev = k;
        k->prev = head;
        head->next = k;
        mp[key] = k;
        return;
    }
};