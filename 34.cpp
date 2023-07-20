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
    void reverse(ListNode *&head)
    {
        if (head == NULL)
            return;
        ListNode *prev = NULL;
        ListNode *ne;
        while (head)
        {
            ne = head->next;
            head->next = prev;
            prev = head;
            head = ne;
        }
        head = prev;
        // cout<<head->val;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (!fast)
        {
            slow->next;
        }
        reverse(slow);
        // cout<<slow->val;
        while (slow)
        {
            if (slow->val != head->val)
            {
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};