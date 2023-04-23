class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *lst = new ListNode(0), *head2 = lst, *curr = head, *trav = head, *prev;
        lst->next = head;
        while (trav != NULL && trav->val < x)
            trav = trav->next, lst = lst->next;

        if (trav == NULL)
            return head;

        prev = trav, curr = trav, trav = trav->next;

        while (trav)
            if (trav->val < x)
            {
                curr->next = curr->next->next;
                trav->next = lst->next, lst->next = trav;
                lst = trav, trav = curr->next;
            }
            else
                trav = trav->next, curr = curr->next;
        return head2->next;
    }
};