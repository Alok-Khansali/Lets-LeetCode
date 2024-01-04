class Solution {                                           //TWO POINTER ALGORITHM
public:
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* fast_pt = head,*slow_pt = head, *temp;
        while(k-- > 1)                                     //Getting the kth node from beginning
        {
            fast_pt = fast_pt->next;
        }
        temp = fast_pt;                                    //Storing the kth node from beginning
        while(fast_pt->next != NULL)                       //Getting the kth node from the end
        {
            fast_pt = fast_pt->next;
            slow_pt = slow_pt->next;                       //Storing the kth node in the slow pointer
        }
        swap(temp->val,slow_pt->val);                      //Swapping the values of both the nodes 
        return head;
    }
};
