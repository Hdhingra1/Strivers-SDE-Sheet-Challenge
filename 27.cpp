#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    // Write your code here.
    Node<int> *ans = new Node<int>(0);
    Node<int> *temp = ans;
    while (first && second)
    {
        Node<int> *T = new Node<int>(0);
        if (first->data <= second->data)
        {
            T->data = first->data;
            first = first->next;
        }
        else
        {
            T->data = second->data;
            second = second->next;
        }
        ans->next = T;
        ans = T;
    }
    while (first)
    {
        Node<int> *T = new Node<int>(0);
        T->data = first->data;
        first = first->next;
        ans->next = T;
        ans = T;
    }
    while (second)
    {
        Node<int> *T = new Node<int>(0);
        T->data = second->data;
        second = second->next;
        ans->next = T;
        ans = T;
    }
    return temp->next;
}
