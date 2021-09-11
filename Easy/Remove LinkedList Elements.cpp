class Solution {      
public:
    ListNode* removeElements(ListNode* head, int val) {
        ios_base::sync_with_stdio(false);
	      cin.tie(NULL);
        cout.tie(NULL);
        if(!head)
            return head;
        ListNode* prev, *trav = head;                       //traversal node
        while(trav) 
        {   
            if(trav->val == val)
                if(trav == head)
                    head = trav->next, trav = head;
                else
                  trav = trav->next, prev->next = trav;
            else
                prev = trav , trav = trav->next;
        }
        return head;
    }
};
