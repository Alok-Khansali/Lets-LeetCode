// Both are 1 pass solutions
class Solution 
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slw_pt = head, *fst_pt = head; // slow pointer and fast pointer initialised
        for (int i = 0; i < n; i++)
            fst_pt = fst_pt->next;
        if (fst_pt == NULL)
            return head->next;
        while (fst_pt->next)
        {
            fst_pt = fst_pt->next;
            slw_pt = slw_pt->next;
        }
        slw_pt->next = slw_pt->next->next;
        return head;
    }
};

// 1 loop soln with space usage
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fst_pt = head;
        ListNode *v[30];
        int sz = 0;
        while (fst_pt)
        {
            v[sz++] = fst_pt;
            fst_pt = fst_pt->next;
        }
        if (n == sz)
            return head->next;
        v[sz - n - 1]->next = v[sz - n - 1]->next->next;
        return head;
    }
};