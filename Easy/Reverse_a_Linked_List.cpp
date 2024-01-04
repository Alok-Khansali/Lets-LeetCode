class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
       ios_base::sync_with_stdio(false);
	     cin.tie(NULL);
        cout.tie(NULL);
       ListNode* prev = NULL, *nxt, *cur = head;
        while(cur)                                    //                                           NODE       ->     NODE                   NODE       <-    NODE  
        {                                             //                                       ______________     ______________        ______________     ______________
            nxt = cur->next;                          // changing the links of the nodes from  |data|address|---->|data|address|   to   |data|address|<----|data|address|
            cur->next = prev;                         //                                       |____________|     |____________|        |____________|     |____________|
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};
