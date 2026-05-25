class Solution {
public:

    ListNode* rec(ListNode* head, int& n)
    {
        // base case
        if (!head)
        {
            return NULL;
        }

        // recurse till end
        head->next = rec(head->next, n);

        // coming back from recursion
        n--;

        // remove nth node
        if (n == 0)
        {
            return head->next;
        }

        return head;
    }

    ListNode* removeNthFromEnd(
        ListNode* head,
        int n)
    {
        return rec(head, n);
    }
};