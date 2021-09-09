class Solution {
public:
    bool hasCycle(ListNode *head)    //floyd's algo  two pointer algorithm
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        cout.tie(NULL);
        ListNode* slw = head,*fst = head;
        while(fst && fst->next)
        {
            slw = slw->next, fst = fst ->next ->next;
            if (slw == fst)
                return true;
        }
        return false;     
    }
};
