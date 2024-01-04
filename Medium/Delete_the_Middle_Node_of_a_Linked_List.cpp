class Solution
{
    // Runtime: 1943 ms, faster than 51.49% of C++ online submissions for Delete the Middle Node of a Linked List.
    // Memory Usage: 294.5 MB, less than 95.17% of C++ online submissions for Delete the Middle Node of a Linked List.
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        ios_base::sync_with_stdio(0);
        if (head->next == NULL)
            return NULL;
        if (head->next->next == NULL)
        {
            head->next = NULL;
            return head;
        }
        ListNode *sl = head, *fst = head;
        while (fst != NULL && fst->next != NULL)
        {
            sl = sl->next;
            fst = fst->next->next;
        }
        *sl = *sl->next;
        return head;
    }
};