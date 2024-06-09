class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int f, int b, ListNode *list2)
    {
        int st = 1;
        ListNode *a = list1, *sl = list1;
        while (st != f)
        {
            a = a->next;
            sl = sl->next;
            st++;
        }
        ListNode *d = sl;
        while (st <= b)
        {
            a = a->next;
            sl = sl->next;
            st++;
        }
        d->next = list2;
        sl = list2;
        while (sl->next != NULL)
            sl = sl->next;
        sl->next = a->next;
        return list1;
    }
};