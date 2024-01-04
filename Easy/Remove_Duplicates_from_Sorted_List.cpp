class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        cout.tie(NULL);
        if(head == NULL)
            return head;
        ListNode* trav=head;
        while(trav->next)
            if(trav->val == trav->next->val)
                trav->next=trav->next->next;
            else
             trav=trav->next;
        return head;
    }
};
