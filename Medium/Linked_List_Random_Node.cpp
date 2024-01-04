class Solution {
public:
    ListNode* h;
    Solution(ListNode* head) 
    {
        h = head;
    }
    int getRandom() 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        ListNode *trav = h;
        int p = 1, ans;
        while(trav)
        {          
            if(rand() % p == 0)
                ans = trav->val;
            trav = trav->next;
            p++;
        }
        return ans;
    }
};
