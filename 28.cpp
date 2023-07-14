/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *removeKthNode(Node *head, int K)
{
    Node *f = head;
    while (K--)
    {
        f = f->next;
    }
    Node *d = head;
    if (f == NULL)
        return head->next;
    while (f->next)
    {
        f = f->next;
        d = d->next;
    }
    d->next = d->next->next;
    return head;
    // Write your code here.
}
