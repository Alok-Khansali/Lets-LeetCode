class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* slw_pt = head,*fst_pt = head;            //slow pointer and fast pointer initialised
        for(int i=0;i<n;i++)
            fst_pt = fst_pt->next;
        if(fst_pt == NULL)
             return head->next;
        while(fst_pt->next)
        {
            fst_pt = fst_pt->next;
            slw_pt = slw_pt->next;
        }
        slw_pt->next = slw_pt->next->next;
        return head;
    }
};