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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int t = k;
        ListNode *up = head;
        for (int i = 0; i < k; i++)
        {
            if (up == nullptr)
                return head;
            up = up->next;
        }
        up = head;
        ListNode *prev = NULL;
        ListNode *nxt;
        while (t-- && head)
        {
            nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        ListNode *kio = prev;

        while (head)
        {
            ListNode *jk = head;

            prev = NULL;
            t = k;
            for (int i = 0; i < k; i++)
            {
                if (jk == nullptr)
                {
                    up->next = head;
                    return kio;
                }
                jk = jk->next;
            }
            jk = head;
            while (t-- && head)
            {
                nxt = head->next;
                head->next = prev;
                prev = head;
                head = nxt;
            }
            up->next = prev;
            // cout<<up->data<<" "<<jk->data<<" "<<prev->data;
            up = jk;
        }
        return kio; //
    }
};