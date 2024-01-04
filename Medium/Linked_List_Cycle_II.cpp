class Solution { //Runtime: 4 ms, faster than 98.10% of C++ online submissions for Linked List Cycle II.
    ListNode *detectCycle(ListNode *head) 
    {
        ios_base::sync_with_stdio(0);
	      cin.tie(0);
        ListNode* fst_pt = head,*sl_pt=head;
        int f = 0;
        while(fst_pt && fst_pt->next)                   //Till there are nodes, keep traversing
        {
            sl_pt = sl_pt->next;
            fst_pt = fst_pt->next->next;
            if(fst_pt == sl_pt)
            {
                f = 1;
                break;
            }
        }
        if(f == 0)
          return NULL;                                 //If head reaches NULL, No cycle Exists!!! 
        while(fst_pt != head)
        {
            head = head->next;
            fst_pt = fst_pt->next;
        }
        return head;
    }
};
