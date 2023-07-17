/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        vector<int> d;
        ListNode *l3 = new ListNode(0);

        int c = 0;
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 != NULL && l2 != NULL)
            {
                int x = l1->val + l2->val;
                if (c == 1)
                {
                    x++;
                    c = 0;
                }
                if (x >= 10)
                {
                    x -= 10;
                    c = 1;
                }
                d.push_back(x);
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1 != NULL)
            {
                int x = l1->val;
                if (c == 1)
                {
                    x++;
                    c = 0;
                }
                if (x >= 10)
                {
                    x -= 10;
                    c = 1;
                }
                d.push_back(x);
                l1 = l1->next;
            }
            else if (l2 != NULL)
            {
                int x = l2->val;
                if (c == 1)
                {
                    x++;
                    c = 0;
                }
                if (x >= 10)
                {
                    x -= 10;
                    c = 1;
                }
                d.push_back(x);
                l2 = l2->next;
            }
        }
        if (c == 1)
            d.push_back(1);
        for (int i = 1; i <= d.size(); i++)
        {
            cout << d[d.size() - i];
            ListNode *k = new ListNode(d[d.size() - i]);
            if (i != 1)
                k->next = l3;
            l3 = k;
        }
        return l3;
    }
};