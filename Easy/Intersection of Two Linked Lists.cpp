class Solution { //58 ms, faster than 30.98% of C++ online submissions for Intersection of Two Linked Lists.
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        unordered_set<ListNode*> s;
        while(headA)
        {
            s.insert(headA);
            headA=headA->next;
        }
         while(headB)
         {
             if(s.find(headB) != s.end())
                 return headB;
             headB = headB->next;
         }
        return NULL;
    }
};
