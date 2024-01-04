class Solution {  //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Middle of the Linked List.
                  //Memory Usage: 7 MB, less than 69.33% of C++ online submissions for Middle of the Linked List.
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode *fst_pt = head;
        while(fst_pt && fst_pt->next)
        {
            fst_pt = fst_pt->next->next;
            head = head->next;
        }
        return head;
    }
};