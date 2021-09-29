class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        
	    ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int x=0;
        for(ListNode* t = head ;t!=NULL; t= t->next,x++){}
        int q = x / k , r = x % k;
        vector<ListNode*> s(k);
        for(int i=0;i<k;i++,r--)
        {
            int j = (r>0) ? q+1 : q;
            ListNode* ep = NULL;          //end_point
            s[i] = head;
            while(j--)
            {
                ep = head;
                head = head->next;
            }
            if(ep)
                ep->next = NULL;
        }
        return s;    
    }
};
