class Solution { //Runtime: 7 ms, faster than 83.62% of C++ online submissions for Remove Duplicates from Sorted List II.
//Memory Usage: 11.1 MB, less than 59.49% of C++ online submissions for Remove Duplicates from Sorted List II.
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        int prev = 0;
        ListNode *h = new ListNode(), *t,*tp = h;
        while(head)
        {
            t = head;
            prev = t->val;
            head = head->next;
            while(head && head->val == prev)
                head = head->next;
            if(t->next == head)
            {
                tp->next = t;
                tp = tp->next;
            }
        }
        tp->next = NULL;
        return h->next;
    }
};